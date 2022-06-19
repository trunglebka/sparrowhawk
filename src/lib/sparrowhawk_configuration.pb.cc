// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sparrowhawk_configuration.proto

#include "sparrowhawk_configuration.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace speech {
namespace sparrowhawk {
class SparrowhawkConfigurationDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<SparrowhawkConfiguration> _instance;
} _SparrowhawkConfiguration_default_instance_;
}  // namespace sparrowhawk
}  // namespace speech
static void InitDefaultsscc_info_SparrowhawkConfiguration_sparrowhawk_5fconfiguration_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::speech::sparrowhawk::_SparrowhawkConfiguration_default_instance_;
    new (ptr) ::speech::sparrowhawk::SparrowhawkConfiguration();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_SparrowhawkConfiguration_sparrowhawk_5fconfiguration_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_SparrowhawkConfiguration_sparrowhawk_5fconfiguration_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_sparrowhawk_5fconfiguration_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_sparrowhawk_5fconfiguration_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_sparrowhawk_5fconfiguration_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_sparrowhawk_5fconfiguration_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::speech::sparrowhawk::SparrowhawkConfiguration, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::speech::sparrowhawk::SparrowhawkConfiguration, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::speech::sparrowhawk::SparrowhawkConfiguration, tokenizer_grammar_),
  PROTOBUF_FIELD_OFFSET(::speech::sparrowhawk::SparrowhawkConfiguration, verbalizer_grammar_),
  PROTOBUF_FIELD_OFFSET(::speech::sparrowhawk::SparrowhawkConfiguration, sentence_boundary_regexp_),
  PROTOBUF_FIELD_OFFSET(::speech::sparrowhawk::SparrowhawkConfiguration, sentence_boundary_exceptions_file_),
  PROTOBUF_FIELD_OFFSET(::speech::sparrowhawk::SparrowhawkConfiguration, serialization_spec_),
  0,
  1,
  2,
  3,
  4,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 10, sizeof(::speech::sparrowhawk::SparrowhawkConfiguration)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::speech::sparrowhawk::_SparrowhawkConfiguration_default_instance_),
};

const char descriptor_table_protodef_sparrowhawk_5fconfiguration_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\037sparrowhawk_configuration.proto\022\022speec"
  "h.sparrowhawk\"\272\001\n\030SparrowhawkConfigurati"
  "on\022\031\n\021tokenizer_grammar\030\001 \001(\t\022\032\n\022verbali"
  "zer_grammar\030\002 \001(\t\022 \n\030sentence_boundary_r"
  "egexp\030\003 \001(\t\022)\n!sentence_boundary_excepti"
  "ons_file\030\004 \001(\t\022\032\n\022serialization_spec\030\005 \001"
  "(\t"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_sparrowhawk_5fconfiguration_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_sparrowhawk_5fconfiguration_2eproto_sccs[1] = {
  &scc_info_SparrowhawkConfiguration_sparrowhawk_5fconfiguration_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_sparrowhawk_5fconfiguration_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_sparrowhawk_5fconfiguration_2eproto = {
  false, false, descriptor_table_protodef_sparrowhawk_5fconfiguration_2eproto, "sparrowhawk_configuration.proto", 242,
  &descriptor_table_sparrowhawk_5fconfiguration_2eproto_once, descriptor_table_sparrowhawk_5fconfiguration_2eproto_sccs, descriptor_table_sparrowhawk_5fconfiguration_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_sparrowhawk_5fconfiguration_2eproto::offsets,
  file_level_metadata_sparrowhawk_5fconfiguration_2eproto, 1, file_level_enum_descriptors_sparrowhawk_5fconfiguration_2eproto, file_level_service_descriptors_sparrowhawk_5fconfiguration_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_sparrowhawk_5fconfiguration_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_sparrowhawk_5fconfiguration_2eproto)), true);
namespace speech {
namespace sparrowhawk {

// ===================================================================

class SparrowhawkConfiguration::_Internal {
 public:
  using HasBits = decltype(std::declval<SparrowhawkConfiguration>()._has_bits_);
  static void set_has_tokenizer_grammar(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_verbalizer_grammar(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_sentence_boundary_regexp(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_sentence_boundary_exceptions_file(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_serialization_spec(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
};

SparrowhawkConfiguration::SparrowhawkConfiguration(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:speech.sparrowhawk.SparrowhawkConfiguration)
}
SparrowhawkConfiguration::SparrowhawkConfiguration(const SparrowhawkConfiguration& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  tokenizer_grammar_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_tokenizer_grammar()) {
    tokenizer_grammar_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_tokenizer_grammar(), 
      GetArena());
  }
  verbalizer_grammar_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_verbalizer_grammar()) {
    verbalizer_grammar_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_verbalizer_grammar(), 
      GetArena());
  }
  sentence_boundary_regexp_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_sentence_boundary_regexp()) {
    sentence_boundary_regexp_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_sentence_boundary_regexp(), 
      GetArena());
  }
  sentence_boundary_exceptions_file_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_sentence_boundary_exceptions_file()) {
    sentence_boundary_exceptions_file_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_sentence_boundary_exceptions_file(), 
      GetArena());
  }
  serialization_spec_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_serialization_spec()) {
    serialization_spec_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_serialization_spec(), 
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:speech.sparrowhawk.SparrowhawkConfiguration)
}

void SparrowhawkConfiguration::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_SparrowhawkConfiguration_sparrowhawk_5fconfiguration_2eproto.base);
  tokenizer_grammar_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  verbalizer_grammar_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  sentence_boundary_regexp_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  sentence_boundary_exceptions_file_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  serialization_spec_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

SparrowhawkConfiguration::~SparrowhawkConfiguration() {
  // @@protoc_insertion_point(destructor:speech.sparrowhawk.SparrowhawkConfiguration)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void SparrowhawkConfiguration::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  tokenizer_grammar_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  verbalizer_grammar_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  sentence_boundary_regexp_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  sentence_boundary_exceptions_file_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  serialization_spec_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void SparrowhawkConfiguration::ArenaDtor(void* object) {
  SparrowhawkConfiguration* _this = reinterpret_cast< SparrowhawkConfiguration* >(object);
  (void)_this;
}
void SparrowhawkConfiguration::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void SparrowhawkConfiguration::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const SparrowhawkConfiguration& SparrowhawkConfiguration::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_SparrowhawkConfiguration_sparrowhawk_5fconfiguration_2eproto.base);
  return *internal_default_instance();
}


void SparrowhawkConfiguration::Clear() {
// @@protoc_insertion_point(message_clear_start:speech.sparrowhawk.SparrowhawkConfiguration)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      tokenizer_grammar_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      verbalizer_grammar_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000004u) {
      sentence_boundary_regexp_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000008u) {
      sentence_boundary_exceptions_file_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000010u) {
      serialization_spec_.ClearNonDefaultToEmpty();
    }
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* SparrowhawkConfiguration::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional string tokenizer_grammar = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_tokenizer_grammar();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "speech.sparrowhawk.SparrowhawkConfiguration.tokenizer_grammar");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string verbalizer_grammar = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_verbalizer_grammar();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "speech.sparrowhawk.SparrowhawkConfiguration.verbalizer_grammar");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string sentence_boundary_regexp = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_sentence_boundary_regexp();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "speech.sparrowhawk.SparrowhawkConfiguration.sentence_boundary_regexp");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string sentence_boundary_exceptions_file = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          auto str = _internal_mutable_sentence_boundary_exceptions_file();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "speech.sparrowhawk.SparrowhawkConfiguration.sentence_boundary_exceptions_file");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string serialization_spec = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          auto str = _internal_mutable_serialization_spec();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "speech.sparrowhawk.SparrowhawkConfiguration.serialization_spec");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* SparrowhawkConfiguration::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:speech.sparrowhawk.SparrowhawkConfiguration)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string tokenizer_grammar = 1;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_tokenizer_grammar().data(), static_cast<int>(this->_internal_tokenizer_grammar().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "speech.sparrowhawk.SparrowhawkConfiguration.tokenizer_grammar");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_tokenizer_grammar(), target);
  }

  // optional string verbalizer_grammar = 2;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_verbalizer_grammar().data(), static_cast<int>(this->_internal_verbalizer_grammar().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "speech.sparrowhawk.SparrowhawkConfiguration.verbalizer_grammar");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_verbalizer_grammar(), target);
  }

  // optional string sentence_boundary_regexp = 3;
  if (cached_has_bits & 0x00000004u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_sentence_boundary_regexp().data(), static_cast<int>(this->_internal_sentence_boundary_regexp().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "speech.sparrowhawk.SparrowhawkConfiguration.sentence_boundary_regexp");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_sentence_boundary_regexp(), target);
  }

  // optional string sentence_boundary_exceptions_file = 4;
  if (cached_has_bits & 0x00000008u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_sentence_boundary_exceptions_file().data(), static_cast<int>(this->_internal_sentence_boundary_exceptions_file().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "speech.sparrowhawk.SparrowhawkConfiguration.sentence_boundary_exceptions_file");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_sentence_boundary_exceptions_file(), target);
  }

  // optional string serialization_spec = 5;
  if (cached_has_bits & 0x00000010u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_serialization_spec().data(), static_cast<int>(this->_internal_serialization_spec().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "speech.sparrowhawk.SparrowhawkConfiguration.serialization_spec");
    target = stream->WriteStringMaybeAliased(
        5, this->_internal_serialization_spec(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:speech.sparrowhawk.SparrowhawkConfiguration)
  return target;
}

size_t SparrowhawkConfiguration::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:speech.sparrowhawk.SparrowhawkConfiguration)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    // optional string tokenizer_grammar = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_tokenizer_grammar());
    }

    // optional string verbalizer_grammar = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_verbalizer_grammar());
    }

    // optional string sentence_boundary_regexp = 3;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_sentence_boundary_regexp());
    }

    // optional string sentence_boundary_exceptions_file = 4;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_sentence_boundary_exceptions_file());
    }

    // optional string serialization_spec = 5;
    if (cached_has_bits & 0x00000010u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_serialization_spec());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void SparrowhawkConfiguration::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:speech.sparrowhawk.SparrowhawkConfiguration)
  GOOGLE_DCHECK_NE(&from, this);
  const SparrowhawkConfiguration* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<SparrowhawkConfiguration>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:speech.sparrowhawk.SparrowhawkConfiguration)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:speech.sparrowhawk.SparrowhawkConfiguration)
    MergeFrom(*source);
  }
}

void SparrowhawkConfiguration::MergeFrom(const SparrowhawkConfiguration& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:speech.sparrowhawk.SparrowhawkConfiguration)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_tokenizer_grammar(from._internal_tokenizer_grammar());
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_set_verbalizer_grammar(from._internal_verbalizer_grammar());
    }
    if (cached_has_bits & 0x00000004u) {
      _internal_set_sentence_boundary_regexp(from._internal_sentence_boundary_regexp());
    }
    if (cached_has_bits & 0x00000008u) {
      _internal_set_sentence_boundary_exceptions_file(from._internal_sentence_boundary_exceptions_file());
    }
    if (cached_has_bits & 0x00000010u) {
      _internal_set_serialization_spec(from._internal_serialization_spec());
    }
  }
}

void SparrowhawkConfiguration::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:speech.sparrowhawk.SparrowhawkConfiguration)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SparrowhawkConfiguration::CopyFrom(const SparrowhawkConfiguration& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:speech.sparrowhawk.SparrowhawkConfiguration)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SparrowhawkConfiguration::IsInitialized() const {
  return true;
}

void SparrowhawkConfiguration::InternalSwap(SparrowhawkConfiguration* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  tokenizer_grammar_.Swap(&other->tokenizer_grammar_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  verbalizer_grammar_.Swap(&other->verbalizer_grammar_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  sentence_boundary_regexp_.Swap(&other->sentence_boundary_regexp_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  sentence_boundary_exceptions_file_.Swap(&other->sentence_boundary_exceptions_file_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  serialization_spec_.Swap(&other->serialization_spec_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata SparrowhawkConfiguration::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace sparrowhawk
}  // namespace speech
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::speech::sparrowhawk::SparrowhawkConfiguration* Arena::CreateMaybeMessage< ::speech::sparrowhawk::SparrowhawkConfiguration >(Arena* arena) {
  return Arena::CreateMessageInternal< ::speech::sparrowhawk::SparrowhawkConfiguration >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
