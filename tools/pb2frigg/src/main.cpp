#include <cassert>
#include <iostream>
#include <sstream>

#include <google/protobuf/descriptor.h>
#include <google/protobuf/compiler/plugin.h>
#include <google/protobuf/compiler/code_generator.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/printer.h>

namespace pb = google::protobuf;

// --------------------------------------------------------
// scalar specific functions
// --------------------------------------------------------

void printScalarInitialize(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	if(field->is_optional() || field->is_required()) {
		printer.Print("m_$name${0}, p_$name${false}",
				"name", field->name());
	}else if(field->is_repeated()) {
		printer.Print("m_$name${allocator}",
				"name", field->name());
	}else{
		assert(!"Unexpected field configuration");
	}
}

void printScalarAccessors(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	const char *out_type;
	switch(field->type()) {
	case pb::FieldDescriptor::TYPE_INT32:
		out_type = "int32_t"; break;
	case pb::FieldDescriptor::TYPE_UINT32:
		out_type = "uint32_t"; break;
	case pb::FieldDescriptor::TYPE_INT64:
		out_type = "int64_t"; break;
	case pb::FieldDescriptor::TYPE_UINT64:
		out_type = "uint64_t"; break;
	case pb::FieldDescriptor::TYPE_ENUM:
		out_type = "int64_t"; break;
	default:
		assert(!"Unexpected scalar type");
	}

	if(field->is_optional() || field->is_required()) {
		printer.Print("inline $out_type$ $name$() const {\n"
				"  return m_$name$;\n"
				"}\n",
				"name", field->name(), "out_type", out_type);
		printer.Print("inline void set_$name$($out_type$ value) {\n"
				"  m_$name$ = value;\n"
				"  p_$name$ = true;\n"
				"}\n",
				"name", field->name(), "out_type", out_type);
	}else if(field->is_repeated()) {
		printer.Print("inline void add_$name$($out_type$ value) {\n"
				"  m_$name$.push(value);\n"
				"}\n",
				"name", field->name(), "out_type", out_type);
		printer.Print("inline size_t $name$_size() const {\n"
				"  return m_$name$.size();\n"
				"}\n",
				"name", field->name());
		printer.Print("inline $out_type$ $name$(size_t i) const {\n"
				"  return m_$name$[i];\n"
				"}\n",
				"name", field->name(), "out_type", out_type);
	}else{
		assert(!"Unexpected field configuration");
	}
}

void printScalarSize(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	if(field->is_optional() || field->is_required()) {
		printer.Print("if(p_$name$) {\n"
				"  cachedSize_ += pb2frigg::varintSize($number$ << 3);\n"
				"  cachedSize_ += pb2frigg::varintSize(m_$name$);\n"
				"}\n",
				"number", std::to_string(field->number()), "name", field->name());
	}else if(field->is_repeated()) {
		printer.Print("cachedSize_ += m_$name$.size()"
					" * pb2frigg::varintSize($number$ << 3);\n"
				"for(size_t i = 0; i < m_$name$.size(); i++)\n"
				"  cachedSize_ += pb2frigg::varintSize(m_$name$[i]);\n",
				"number", std::to_string(field->number()), "name", field->name());
	}else{
		assert(!"Unexpected field configuration");
	}
}

void printScalarSerialize(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	const char *emit_function;
	switch(field->type()) {
	case pb::FieldDescriptor::TYPE_INT32:
		emit_function = "pb2frigg::emitInt32"; break;
	case pb::FieldDescriptor::TYPE_UINT32:
		emit_function = "pb2frigg::emitUInt32"; break;
	case pb::FieldDescriptor::TYPE_INT64:
		emit_function = "pb2frigg::emitInt64"; break;
	case pb::FieldDescriptor::TYPE_UINT64:
		emit_function = "pb2frigg::emitUInt64"; break;
	case pb::FieldDescriptor::TYPE_ENUM:
		emit_function = "pb2frigg::emitInt64"; break;
	default:
		assert(!"Unexpected scalar type");
	}

	if(field->is_optional() || field->is_required()) {
		printer.Print("if(p_$name$)\n"
				"  $emit_function$(writer, $number$, m_$name$);\n",
				"emit_function", emit_function, "number", std::to_string(field->number()),
				"name", field->name());
	}else if(field->is_repeated()) {
		printer.Print("for(size_t i = 0; i < m_$name$.size(); i++)\n", "name", field->name());
		printer.Indent();
		printer.Print("$emit_function$(writer, $number$, m_$name$[i]);\n",
				"emit_function", emit_function, "number", std::to_string(field->number()),
				"name", field->name());
		printer.Outdent();
	}else{
		assert(!"Unexpected field configuration");
	}
}

void printScalarParse(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	const char *fetch_function, *wire_constant;
	switch(field->type()) {
	case pb::FieldDescriptor::TYPE_INT32:
		fetch_function = "fetchInt32";
		wire_constant = "pb2frigg::wireVarint";
		break;
	case pb::FieldDescriptor::TYPE_UINT32:
		fetch_function = "fetchUInt32";
		wire_constant = "pb2frigg::wireVarint";
		break;
	case pb::FieldDescriptor::TYPE_INT64:
		fetch_function = "fetchInt64";
		wire_constant = "pb2frigg::wireVarint";
		break;
	case pb::FieldDescriptor::TYPE_UINT64:
		fetch_function = "fetchUInt64";
		wire_constant = "pb2frigg::wireVarint";
		break;
	case pb::FieldDescriptor::TYPE_ENUM:
		fetch_function = "fetchInt64";
		wire_constant = "pb2frigg::wireVarint";
		break;
	default:
		assert(!"Unexpected scalar type");
	}

	if(field->is_optional() || field->is_required()) {
		printer.Print("case $number$:\n"
				"  FRG_ASSERT(header.wire == $wire_constant$);\n",
				"wire_constant", wire_constant,
				"number", std::to_string(field->number()));
		printer.Print("  m_$name$ = $fetch_function$(reader);\n"
				"  p_$name$ = true;\n"
				"  break;\n",
				"name", field->name(), "fetch_function", fetch_function);
	}else if(field->is_repeated()) {
		printer.Print("case $number$:\n", "number", std::to_string(field->number()));
		printer.Indent();
		printer.Print("FRG_ASSERT(header.wire == $wire_constant$);\n"
				"m_$name$.push($fetch_function$(reader));\n"
				"break;\n",
				"wire_constant", wire_constant, "fetch_function", fetch_function,
				"name", field->name());
		printer.Outdent();
	}else{
		assert(!"Unexpected field configuration");
	}
}

void printScalarMember(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	const char *out_type;
	switch(field->type()) {
	case pb::FieldDescriptor::TYPE_INT32:
		out_type = "int32_t"; break;
	case pb::FieldDescriptor::TYPE_UINT32:
		out_type = "uint32_t"; break;
	case pb::FieldDescriptor::TYPE_INT64:
		out_type = "int64_t"; break;
	case pb::FieldDescriptor::TYPE_UINT64:
		out_type = "uint64_t"; break;
	case pb::FieldDescriptor::TYPE_ENUM:
		out_type = "int64_t"; break;
	default:
		assert(!"Unexpected scalar type");
	}

	if(field->is_optional() || field->is_required()) {
		printer.Print("$out_type$ m_$name$;\n"
				"bool p_$name$;\n",
				"out_type", out_type, "name", field->name());
	}else if(field->is_repeated()) {
		printer.Print("frg::vector<$out_type$, Allocator> m_$name$;\n",
				"out_type", out_type, "name", field->name());
	}else{
		assert(!"Unexpected field configuration");
	}
}

// --------------------------------------------------------
// string specific functions
// --------------------------------------------------------

void printStringInitialize(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	if(field->is_optional() || field->is_required()) {
		printer.Print("m_$name${allocator}, p_$name${false}",
				"name", field->name());
	}else{
		assert(!"Unexpected field configuration");
	}
}

void printStringAccessors(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	if(field->is_optional() || field->is_required()) {
		printer.Print("inline const frg::string<Allocator> &$name$() const {\n"
				"  return m_$name$;\n"
				"}\n",
				"name", field->name());
		printer.Print("inline void set_$name$(frg::string<Allocator> value) {\n"
				"  m_$name$ = std::move(value);\n"
				"  p_$name$ = true;\n"
				"}\n",
				"name", field->name());
	}else{
		assert(!"Unexpected field configuration");
	}
}

void printStringSize(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	if(field->is_optional() || field->is_required()) {
		printer.Print("if(p_$name$) {\n"
				"  cachedSize_ += pb2frigg::varintSize($number$ << 3);\n"
				"  size_t $name$_length = m_$name$.size();\n"
				"  cachedSize_ += pb2frigg::varintSize($name$_length);\n"
				"  cachedSize_ += $name$_length;\n"
				"}\n",
				"number", std::to_string(field->number()), "name", field->name());
	}else{
		assert(!"Unexpected field configuration");
	}
}

void printStringSerialize(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	if(field->is_optional() || field->is_required()) {
		printer.Print("if(p_$name$)\n"
					"  pb2frigg::emitString(writer, $number$,"
							" m_$name$.data(), m_$name$.size());\n",
				"number", std::to_string(field->number()), "name", field->name());
	}else{
		assert(!"Unexpected field configuration");
	}
}

void printStringParse(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	if(field->is_optional() || field->is_required()) {
		printer.Print("case $number$: {\n", "number", std::to_string(field->number()));
		printer.Indent();
		printer.Print("FRG_ASSERT(header.wire == pb2frigg::wireDelimited);\n"
				"size_t $name$_length = peekVarint(reader);\n"
				"m_$name$.resize($name$_length);\n"
				"reader.peek(m_$name$.data(), $name$_length);\n"
				"p_$name$ = true;\n",
				"name", field->name());
		printer.Outdent();
		printer.Print("} break;\n");
	}else{
		assert(!"Unexpected field configuration");
	}
}

void printStringMember(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	if(field->is_optional() || field->is_required()) {
		printer.Print("frg::string<Allocator> m_$name$;\n"
				"bool p_$name$;\n",
				"name", field->name());
	}else{
		assert(!"Unexpected field configuration");
	}
}

// --------------------------------------------------------
// embedded message specific functions
// --------------------------------------------------------

void printEmbeddedInitialize(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	if(field->is_optional()) {
		printer.Print("m_$name${allocator}, p_$name${false}",
				"name", field->name());
	}else if(field->is_repeated()) {
		printer.Print("m_$name${allocator}",
				"name", field->name());
	}else{
		assert(!"Unexpected field configuration");
	}
}

void printEmbeddedAccessors(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	const pb::Descriptor *descriptor = field->message_type();
	std::string qualified, part;
	std::istringstream stream(descriptor->full_name());
	while(std::getline(stream, part, '.'))
		qualified += "::" + part;

	if(field->is_optional()) {
		printer.Print("inline const $msg_type$<Allocator> &$name$() const {\n"
				"  return m_$name$;\n"
				"}\n",
				"name", field->name(), "msg_type", qualified);
		printer.Print("inline $msg_type$<Allocator> &mutable_$name$() {\n"
				"  p_$name$ = true;\n"
				"  return m_$name$;\n"
				"}\n",
				"name", field->name(), "msg_type", qualified);
	}else if(field->is_repeated()) {
		printer.Print("inline void add_$name$($msg_type$<Allocator> message) {\n"
				"  m_$name$.push(std::move(message));\n"
				"}\n",
				"name", field->name(), "msg_type", qualified);
		printer.Print("inline size_t $name$_size() const {\n"
				"  return m_$name$.size();\n"
				"}\n",
				"name", field->name());
		printer.Print("inline const $msg_type$<Allocator> &$name$(size_t i) const {\n"
				"  return m_$name$[i];\n"
				"}\n",
				"name", field->name(), "msg_type", qualified);
	}else{
		assert(!"Unexpected field configuration");
	}
}

void printEmbeddedSize(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	if(field->is_optional()) {
		printer.Print("if(p_$name$) {\n"
				"  cachedSize_ += pb2frigg::varintSize($number$ << 3);\n"
				"  size_t $name$_length = m_$name$.ByteSize();\n"
				"  cachedSize_ += pb2frigg::varintSize($name$_length);\n"
				"  cachedSize_ += $name$_length;\n"
				"}\n",
				"number", std::to_string(field->number()), "name", field->name());
	}else if(field->is_repeated()) {
		printer.Print("cachedSize_ += m_$name$.size()"
					" * pb2frigg::varintSize($number$ << 3);\n"
				"for(size_t i = 0; i < m_$name$.size(); i++) {\n"
				"  size_t $name$_length = m_$name$[i].ByteSize();\n"
				"  cachedSize_ += pb2frigg::varintSize($name$_length);\n"
				"  cachedSize_ += $name$_length;\n"
				"}\n",
				"number", std::to_string(field->number()), "name", field->name());
	}else{
		assert(!"Unexpected field configuration");
	}
}

void printEmbeddedSerialize(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	if(field->is_optional()) {
		printer.Print("if(p_$name$) {\n"
				"  pokeHeader(writer, pb2frigg::Header{$number$,"
					" pb2frigg::wireDelimited});\n"
				"  pokeVarint(writer, m_$name$.GetCachedSize());\n"
				"  m_$name$.SerializeWithCachedSizesToArray((uint8_t *)array"
						" + writer.offset(), m_$name$.GetCachedSize());\n"
				"  writer.advance(m_$name$.GetCachedSize());\n"
				"}\n",
				"number", std::to_string(field->number()), "name", field->name());
	}else if(field->is_repeated()) {
		printer.Print("for(size_t i = 0; i < m_$name$.size(); i++) {\n"
				"  pokeHeader(writer, pb2frigg::Header{$number$,"
					" pb2frigg::wireDelimited});\n"
				"  pokeVarint(writer, m_$name$[i].GetCachedSize());\n"
				"  m_$name$[i].SerializeWithCachedSizesToArray((uint8_t *)array"
						" + writer.offset(), m_$name$[i].GetCachedSize());\n"
				"  writer.advance(m_$name$[i].GetCachedSize());\n"
				"}\n",
				"number", std::to_string(field->number()), "name", field->name());
	}else{
		assert(!"Unexpected field configuration");
	}
}

void printEmbeddedParse(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	const pb::Descriptor *descriptor = field->message_type();
	std::string qualified, part;
	std::istringstream stream(descriptor->full_name());
	while(std::getline(stream, part, '.'))
		qualified += "::" + part;

	if(field->is_optional()) {
		printer.Print("case $number$: {\n", "number", std::to_string(field->number()));
		printer.Indent();
		printer.Print("FRG_ASSERT(header.wire == pb2frigg::wireDelimited);\n"
				"size_t $name$_length = peekVarint(reader);\n"
				"m_$name$.ParseFromArray((uint8_t *)array + reader.offset(), $name$_length);\n"
				"reader.advance($name$_length);\n"
				"p_$name$ = true;\n",
				"msg_type", qualified, "name", field->name());
		printer.Outdent();
		printer.Print("} break;\n");
	}else if(field->is_repeated()) {
		printer.Print("case $number$: {\n", "number", std::to_string(field->number()));
		printer.Indent();
		printer.Print("FRG_ASSERT(header.wire == pb2frigg::wireDelimited);\n"
				"size_t $name$_length = peekVarint(reader);\n"
				"$msg_type$<Allocator> element(*allocator_);\n"
				"element.ParseFromArray((uint8_t *)array + reader.offset(), $name$_length);\n"
				"m_$name$.push(std::move(element));\n"
				"reader.advance($name$_length);\n",
				"msg_type", qualified, "name", field->name());
		printer.Outdent();
		printer.Print("} break;\n");
	}else{
		assert(!"Unexpected field configuration");
	}
}

void printEmbeddedMember(pb::io::Printer &printer, const pb::FieldDescriptor *field) {
	const pb::Descriptor *descriptor = field->message_type();
	std::string qualified, part;
	std::istringstream stream(descriptor->full_name());
	while(std::getline(stream, part, '.'))
		qualified += "::" + part;

	if(field->is_optional()) {
		printer.Print("$msg_type$<Allocator> m_$name$;\n"
				"bool p_$name$;\n",
				"msg_type", qualified, "name", field->name());
	}else if(field->is_repeated()) {
		printer.Print("frg::vector<$msg_type$<Allocator>, Allocator> m_$name$;\n",
				"msg_type", qualified, "name", field->name());
	}else{
		assert(!"Unexpected field configuration");
	}
}

// --------------------------------------------------------
// container generation functions
// --------------------------------------------------------

void generateEnum(pb::io::Printer &printer, const pb::EnumDescriptor *enumeration) {
	printer.Print("struct $name$ {\n", "name", enumeration->name());
	printer.Indent();
	printer.Print("enum {\n");
	printer.Indent();

	for(int i = 0; i < enumeration->value_count(); i++) {
		const pb::EnumValueDescriptor *value = enumeration->value(i);
		printer.Print("$name$ = $number$", "name", value->name(),
				"number", std::to_string(value->number()));

		if(i + 1 < enumeration->value_count())
			printer.Print(",");
		printer.Print("\n");
	}

	printer.Outdent();
	printer.Print("};\n");
	printer.Outdent();
	printer.Print("};\n");
}

void generateMessage(pb::io::Printer &printer, const pb::Descriptor *descriptor) {
	// generate a containing class for each message
	printer.Print("template<typename Allocator>\n"
			"class $name$ {\n"
			"public:\n", "name", descriptor->name());
	printer.Indent();

	for(int i = 0; i < descriptor->enum_type_count(); i++) {
		printer.Print("\n");
		generateEnum(printer, descriptor->enum_type(i));
	}

	// generate the default constructor
	printer.Print("\n");
	printer.Print("$name$(Allocator &allocator)\n"
			": allocator_{&allocator}, cachedSize_{0}",
			"name", descriptor->name());

	for(int i = 0; i < descriptor->field_count(); i++) {
		const pb::FieldDescriptor *field = descriptor->field(i);

		printer.Print(",\n"
				"  ");

		switch(field->type()) {
		case pb::FieldDescriptor::TYPE_INT32:
		case pb::FieldDescriptor::TYPE_UINT32:
		case pb::FieldDescriptor::TYPE_INT64:
		case pb::FieldDescriptor::TYPE_UINT64:
		case pb::FieldDescriptor::TYPE_ENUM:
			printScalarInitialize(printer, field);
			break;
		case pb::FieldDescriptor::TYPE_STRING:
		case pb::FieldDescriptor::TYPE_BYTES:
			printStringInitialize(printer, field);
			break;
		case pb::FieldDescriptor::TYPE_MESSAGE:
			printEmbeddedInitialize(printer, field);
			break;
		default:
			assert(!"Unexpected field type");
		}
	}

	printer.Print(" { }\n");

	// generate the accessor functions
	for(int i = 0; i < descriptor->field_count(); i++) {
		const pb::FieldDescriptor *field = descriptor->field(i);

		printer.Print("\n");

		switch(field->type()) {
		case pb::FieldDescriptor::TYPE_INT32:
		case pb::FieldDescriptor::TYPE_UINT32:
		case pb::FieldDescriptor::TYPE_INT64:
		case pb::FieldDescriptor::TYPE_UINT64:
		case pb::FieldDescriptor::TYPE_ENUM:
			printScalarAccessors(printer, field);
			break;
		case pb::FieldDescriptor::TYPE_STRING:
		case pb::FieldDescriptor::TYPE_BYTES:
			printStringAccessors(printer, field);
			break;
		case pb::FieldDescriptor::TYPE_MESSAGE:
			printEmbeddedAccessors(printer, field);
			break;
		default:
			assert(!"Unexpected field type");
		}
	}

	// generate the size computation function
	printer.Print("\n"
			"size_t ByteSize() {\n");
	printer.Indent();
	printer.Print("cachedSize_ = 0;\n");

	for(int i = 0; i < descriptor->field_count(); i++) {
		const pb::FieldDescriptor *field = descriptor->field(i);

		switch(field->type()) {
		case pb::FieldDescriptor::TYPE_INT32:
		case pb::FieldDescriptor::TYPE_UINT32:
		case pb::FieldDescriptor::TYPE_INT64:
		case pb::FieldDescriptor::TYPE_UINT64:
		case pb::FieldDescriptor::TYPE_ENUM:
			printScalarSize(printer, field);
			break;
		case pb::FieldDescriptor::TYPE_STRING:
		case pb::FieldDescriptor::TYPE_BYTES:
			printStringSize(printer, field);
			break;
		case pb::FieldDescriptor::TYPE_MESSAGE:
			printEmbeddedSize(printer, field);
			break;
		default:
			assert(!"Unexpected field type");
		}
	}

	printer.Print("return cachedSize_;\n");
	printer.Outdent();
	printer.Print("}\n"
			"size_t GetCachedSize() {\n"
			"  return cachedSize_;\n"
			"}\n");

	// generate the serialization function
	printer.Print("\n"
			"void SerializeWithCachedSizesToArray(void *array, size_t length) {\n");
	printer.Indent();
	printer.Print("pb2frigg::BufferWriter writer((uint8_t *)array, length);\n");

	for(int i = 0; i < descriptor->field_count(); i++) {
		const pb::FieldDescriptor *field = descriptor->field(i);

		switch(field->type()) {
		case pb::FieldDescriptor::TYPE_INT32:
		case pb::FieldDescriptor::TYPE_UINT32:
		case pb::FieldDescriptor::TYPE_INT64:
		case pb::FieldDescriptor::TYPE_UINT64:
		case pb::FieldDescriptor::TYPE_ENUM:
			printScalarSerialize(printer, field);
			break;
		case pb::FieldDescriptor::TYPE_STRING:
		case pb::FieldDescriptor::TYPE_BYTES:
			printStringSerialize(printer, field);
			break;
		case pb::FieldDescriptor::TYPE_MESSAGE:
			printEmbeddedSerialize(printer, field);
			break;
		default:
			assert(!"Unexpected field type");
		}
	}

	printer.Print("FRG_ASSERT(writer.offset() == length);\n");
	printer.Outdent();
	printer.Print("}\n"
			"void SerializeToString(frg::string<Allocator> *string) {\n"
			"  string->resize(ByteSize());\n"
			"  SerializeWithCachedSizesToArray(string->data(), string->size());\n"
			"}\n");


	// generate the deserialization function
	printer.Print("\n"
			"void ParseFromArray(const void *buffer, size_t buffer_size) {\n");
	printer.Indent();
	printer.Print("const uint8_t *array = static_cast<const uint8_t *>(buffer);\n"
			"pb2frigg::BufferReader reader(array, buffer_size);\n"
			"while(!reader.atEnd()) {\n");
	printer.Indent();
	printer.Print("auto header = fetchHeader(reader);\n"
			"switch(header.field) {\n");

	for(int i = 0; i < descriptor->field_count(); i++) {
		const pb::FieldDescriptor *field = descriptor->field(i);

		switch(field->type()) {
		case pb::FieldDescriptor::TYPE_INT32:
		case pb::FieldDescriptor::TYPE_UINT32:
		case pb::FieldDescriptor::TYPE_INT64:
		case pb::FieldDescriptor::TYPE_UINT64:
		case pb::FieldDescriptor::TYPE_ENUM:
			printScalarParse(printer, field);
			break;
		case pb::FieldDescriptor::TYPE_STRING:
		case pb::FieldDescriptor::TYPE_BYTES:
			printStringParse(printer, field);
			break;
		case pb::FieldDescriptor::TYPE_MESSAGE:
			printEmbeddedParse(printer, field);
			break;
		default:
			assert(!"Unexpected field type");
		}
	}

	printer.Print("default:\n");
	printer.Indent();
	printer.Print("FRG_ASSERT(!\"Unexpected field number\");\n");
	printer.Outdent();
	printer.Print("}\n");
	printer.Outdent();
	printer.Print("}\n");
	printer.Outdent();
	printer.Print("}\n");

	// generate the fields that hold the actual data
	printer.Print("\n");
	printer.Outdent();
	printer.Print("private:\n");
	printer.Indent();
	printer.Print("Allocator *allocator_;\n");
	printer.Print("size_t cachedSize_;\n");

	for(int i = 0; i < descriptor->field_count(); i++) {
		const pb::FieldDescriptor *field = descriptor->field(i);

		switch(field->type()) {
		case pb::FieldDescriptor::TYPE_INT32:
		case pb::FieldDescriptor::TYPE_UINT32:
		case pb::FieldDescriptor::TYPE_INT64:
		case pb::FieldDescriptor::TYPE_UINT64:
		case pb::FieldDescriptor::TYPE_ENUM:
			printScalarMember(printer, field);
			break;
		case pb::FieldDescriptor::TYPE_STRING:
		case pb::FieldDescriptor::TYPE_BYTES:
			printStringMember(printer, field);
			break;
		case pb::FieldDescriptor::TYPE_MESSAGE:
			printEmbeddedMember(printer, field);
			break;
		default:
			assert(!"Unexpected field type");
		}
	}

	// generate a method that reads a message
	// close the containing class
	printer.Outdent();
	printer.Print("};\n");
}

class FriggGenerator : public pb::compiler::CodeGenerator {
public:
	virtual bool Generate(const pb::FileDescriptor *file, const std::string &parameter,
			pb::compiler::GeneratorContext *context, std::string *error) const;
};

bool FriggGenerator::Generate(const pb::FileDescriptor *file, const std::string &parameter,
			pb::compiler::GeneratorContext *context, std::string *error) const {
	std::string path = file->name();
	size_t file_dot = path.rfind('.');
	if(file_dot != std::string::npos)
		path.erase(path.begin() + file_dot, path.end());
	path += ".frigg_pb.hpp";

	pb::io::ZeroCopyOutputStream *output = context->Open(path);
	{ // limit the lifetime of printer
		pb::io::Printer printer(output, '$');

		printer.Print("// This file is auto-generated from $file$\n",
				"file", file->name());
		printer.Print("// Do not try to edit it manually!\n");

		printer.Print("#include <utility>\n"); // For std::move.
		printer.Print("#include <frg/string.hpp>\n");
		printer.Print("#include <frg/string.hpp>\n");
		printer.Print("#include <frg/vector.hpp>\n");
		printer.Print("#include <pb2frigg-internals.hpp>\n");

		// print the namespace opening braces
		int num_namespaces = 0;
		std::string pkg_full, pkg_part;
		std::istringstream pkg_stream(file->package());
		printer.Print("\n");
		while(std::getline(pkg_stream, pkg_part, '.')) {
			printer.Print("namespace $pkg_part$ {\n", "pkg_part", pkg_part);
			pkg_full += (num_namespaces == 0 ? "" : "::") + pkg_part;
			num_namespaces++;
		}

		// Generate message forward declarations.
		for(int i = 0; i < file->message_type_count(); i++) {
			printer.Print("\n");
			printer.Print("template<typename Allocator>\n"
					"class $msg_type$;\n",
					"msg_type", file->message_type(i)->name());
		}

		// generate all enums
		for(int i = 0; i < file->enum_type_count(); i++) {
			printer.Print("\n");
			generateEnum(printer, file->enum_type(i));
		}

		// generate all messages
		for(int i = 0; i < file->message_type_count(); i++) {
			printer.Print("\n");
			generateMessage(printer, file->message_type(i));
		}

		// print the closing braces for the namespace
		printer.Print("\n");
		for(int i = 0; i < num_namespaces; i++)
			printer.Print("} ");
		if(num_namespaces > 0)
			printer.Print("// namespace $pkg_full$\n", "pkg_full", pkg_full);
	} // printer is destructed here
	delete output;

	return true;
}

int main(int argc, char* argv[]) {
	FriggGenerator generator;
	return pb::compiler::PluginMain(argc, argv, &generator);
}
