// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: uifontfile_format.proto
// Protobuf C++ Version: 5.27.3

#include "uifontfile_format.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;

inline constexpr CUIFontFilePackagePB_CUIEncryptedFontFilePB::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        encrypted_contents_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()) {}

template <typename>
PROTOBUF_CONSTEXPR CUIFontFilePackagePB_CUIEncryptedFontFilePB::CUIFontFilePackagePB_CUIEncryptedFontFilePB(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct CUIFontFilePackagePB_CUIEncryptedFontFilePBDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CUIFontFilePackagePB_CUIEncryptedFontFilePBDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~CUIFontFilePackagePB_CUIEncryptedFontFilePBDefaultTypeInternal() {}
  union {
    CUIFontFilePackagePB_CUIEncryptedFontFilePB _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CUIFontFilePackagePB_CUIEncryptedFontFilePBDefaultTypeInternal _CUIFontFilePackagePB_CUIEncryptedFontFilePB_default_instance_;

inline constexpr CUIFontFilePB::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        font_file_name_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        opentype_font_data_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()) {}

template <typename>
PROTOBUF_CONSTEXPR CUIFontFilePB::CUIFontFilePB(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct CUIFontFilePBDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CUIFontFilePBDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~CUIFontFilePBDefaultTypeInternal() {}
  union {
    CUIFontFilePB _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CUIFontFilePBDefaultTypeInternal _CUIFontFilePB_default_instance_;

inline constexpr CUIFontFilePackagePB::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        encrypted_font_files_{},
        package_version_{0u} {}

template <typename>
PROTOBUF_CONSTEXPR CUIFontFilePackagePB::CUIFontFilePackagePB(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct CUIFontFilePackagePBDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CUIFontFilePackagePBDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~CUIFontFilePackagePBDefaultTypeInternal() {}
  union {
    CUIFontFilePackagePB _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CUIFontFilePackagePBDefaultTypeInternal _CUIFontFilePackagePB_default_instance_;
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_uifontfile_5fformat_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_uifontfile_5fformat_2eproto = nullptr;
const ::uint32_t
    TableStruct_uifontfile_5fformat_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        PROTOBUF_FIELD_OFFSET(::CUIFontFilePB, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::CUIFontFilePB, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::CUIFontFilePB, _impl_.font_file_name_),
        PROTOBUF_FIELD_OFFSET(::CUIFontFilePB, _impl_.opentype_font_data_),
        0,
        1,
        PROTOBUF_FIELD_OFFSET(::CUIFontFilePackagePB_CUIEncryptedFontFilePB, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::CUIFontFilePackagePB_CUIEncryptedFontFilePB, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::CUIFontFilePackagePB_CUIEncryptedFontFilePB, _impl_.encrypted_contents_),
        0,
        PROTOBUF_FIELD_OFFSET(::CUIFontFilePackagePB, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::CUIFontFilePackagePB, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::CUIFontFilePackagePB, _impl_.package_version_),
        PROTOBUF_FIELD_OFFSET(::CUIFontFilePackagePB, _impl_.encrypted_font_files_),
        0,
        ~0u,
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, 10, -1, sizeof(::CUIFontFilePB)},
        {12, 21, -1, sizeof(::CUIFontFilePackagePB_CUIEncryptedFontFilePB)},
        {22, 32, -1, sizeof(::CUIFontFilePackagePB)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::_CUIFontFilePB_default_instance_._instance,
    &::_CUIFontFilePackagePB_CUIEncryptedFontFilePB_default_instance_._instance,
    &::_CUIFontFilePackagePB_default_instance_._instance,
};
const char descriptor_table_protodef_uifontfile_5fformat_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\027uifontfile_format.proto\"C\n\rCUIFontFile"
    "PB\022\026\n\016font_file_name\030\001 \001(\t\022\032\n\022opentype_f"
    "ont_data\030\002 \001(\014\"\261\001\n\024CUIFontFilePackagePB\022"
    "\027\n\017package_version\030\001 \002(\r\022J\n\024encrypted_fo"
    "nt_files\030\002 \003(\0132,.CUIFontFilePackagePB.CU"
    "IEncryptedFontFilePB\0324\n\026CUIEncryptedFont"
    "FilePB\022\032\n\022encrypted_contents\030\001 \001(\014"
};
static ::absl::once_flag descriptor_table_uifontfile_5fformat_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_uifontfile_5fformat_2eproto = {
    false,
    false,
    274,
    descriptor_table_protodef_uifontfile_5fformat_2eproto,
    "uifontfile_format.proto",
    &descriptor_table_uifontfile_5fformat_2eproto_once,
    nullptr,
    0,
    3,
    schemas,
    file_default_instances,
    TableStruct_uifontfile_5fformat_2eproto::offsets,
    file_level_enum_descriptors_uifontfile_5fformat_2eproto,
    file_level_service_descriptors_uifontfile_5fformat_2eproto,
};
// ===================================================================

class CUIFontFilePB::_Internal {
 public:
  using HasBits =
      decltype(std::declval<CUIFontFilePB>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
      8 * PROTOBUF_FIELD_OFFSET(CUIFontFilePB, _impl_._has_bits_);
};

CUIFontFilePB::CUIFontFilePB(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:CUIFontFilePB)
}
inline PROTOBUF_NDEBUG_INLINE CUIFontFilePB::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::CUIFontFilePB& from_msg)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        font_file_name_(arena, from.font_file_name_),
        opentype_font_data_(arena, from.opentype_font_data_) {}

CUIFontFilePB::CUIFontFilePB(
    ::google::protobuf::Arena* arena,
    const CUIFontFilePB& from)
    : ::google::protobuf::Message(arena) {
  CUIFontFilePB* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);

  // @@protoc_insertion_point(copy_constructor:CUIFontFilePB)
}
inline PROTOBUF_NDEBUG_INLINE CUIFontFilePB::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        font_file_name_(arena),
        opentype_font_data_(arena) {}

inline void CUIFontFilePB::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
CUIFontFilePB::~CUIFontFilePB() {
  // @@protoc_insertion_point(destructor:CUIFontFilePB)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void CUIFontFilePB::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.font_file_name_.Destroy();
  _impl_.opentype_font_data_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
CUIFontFilePB::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              &_table_.header,
              nullptr,  // OnDemandRegisterArenaDtor
              nullptr,  // IsInitialized
              PROTOBUF_FIELD_OFFSET(CUIFontFilePB, _impl_._cached_size_),
              false,
          },
          &CUIFontFilePB::MergeImpl,
          &CUIFontFilePB::kDescriptorMethods,
          &descriptor_table_uifontfile_5fformat_2eproto,
          nullptr,  // tracker
      };
  ::google::protobuf::internal::PrefetchToLocalCache(&_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_data_.tc_table);
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 0, 36, 2> CUIFontFilePB::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(CUIFontFilePB, _impl_._has_bits_),
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_CUIFontFilePB_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::CUIFontFilePB>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // optional bytes opentype_font_data = 2;
    {::_pbi::TcParser::FastBS1,
     {18, 1, 0, PROTOBUF_FIELD_OFFSET(CUIFontFilePB, _impl_.opentype_font_data_)}},
    // optional string font_file_name = 1;
    {::_pbi::TcParser::FastSS1,
     {10, 0, 0, PROTOBUF_FIELD_OFFSET(CUIFontFilePB, _impl_.font_file_name_)}},
  }}, {{
    65535, 65535
  }}, {{
    // optional string font_file_name = 1;
    {PROTOBUF_FIELD_OFFSET(CUIFontFilePB, _impl_.font_file_name_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kRawString | ::_fl::kRepAString)},
    // optional bytes opentype_font_data = 2;
    {PROTOBUF_FIELD_OFFSET(CUIFontFilePB, _impl_.opentype_font_data_), _Internal::kHasBitsOffset + 1, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kBytes | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\15\16\0\0\0\0\0\0"
    "CUIFontFilePB"
    "font_file_name"
  }},
};

PROTOBUF_NOINLINE void CUIFontFilePB::Clear() {
// @@protoc_insertion_point(message_clear_start:CUIFontFilePB)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _impl_.font_file_name_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      _impl_.opentype_font_data_.ClearNonDefaultToEmpty();
    }
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

::uint8_t* CUIFontFilePB::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:CUIFontFilePB)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // optional string font_file_name = 1;
  if (cached_has_bits & 0x00000001u) {
    const std::string& _s = this->_internal_font_file_name();
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(_s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormat::SERIALIZE,
                                "CUIFontFilePB.font_file_name");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  // optional bytes opentype_font_data = 2;
  if (cached_has_bits & 0x00000002u) {
    const std::string& _s = this->_internal_opentype_font_data();
    target = stream->WriteBytesMaybeAliased(2, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CUIFontFilePB)
  return target;
}

::size_t CUIFontFilePB::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CUIFontFilePB)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::_pbi::Prefetch5LinesFrom7Lines(reinterpret_cast<const void*>(this));
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // optional string font_file_name = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                      this->_internal_font_file_name());
    }

    // optional bytes opentype_font_data = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 + ::google::protobuf::internal::WireFormatLite::BytesSize(
                                      this->_internal_opentype_font_data());
    }

  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void CUIFontFilePB::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<CUIFontFilePB*>(&to_msg);
  auto& from = static_cast<const CUIFontFilePB&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:CUIFontFilePB)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _this->_internal_set_font_file_name(from._internal_font_file_name());
    }
    if (cached_has_bits & 0x00000002u) {
      _this->_internal_set_opentype_font_data(from._internal_opentype_font_data());
    }
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void CUIFontFilePB::CopyFrom(const CUIFontFilePB& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CUIFontFilePB)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void CUIFontFilePB::InternalSwap(CUIFontFilePB* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.font_file_name_, &other->_impl_.font_file_name_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.opentype_font_data_, &other->_impl_.opentype_font_data_, arena);
}

::google::protobuf::Metadata CUIFontFilePB::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class CUIFontFilePackagePB_CUIEncryptedFontFilePB::_Internal {
 public:
  using HasBits =
      decltype(std::declval<CUIFontFilePackagePB_CUIEncryptedFontFilePB>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
      8 * PROTOBUF_FIELD_OFFSET(CUIFontFilePackagePB_CUIEncryptedFontFilePB, _impl_._has_bits_);
};

CUIFontFilePackagePB_CUIEncryptedFontFilePB::CUIFontFilePackagePB_CUIEncryptedFontFilePB(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
}
inline PROTOBUF_NDEBUG_INLINE CUIFontFilePackagePB_CUIEncryptedFontFilePB::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::CUIFontFilePackagePB_CUIEncryptedFontFilePB& from_msg)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        encrypted_contents_(arena, from.encrypted_contents_) {}

CUIFontFilePackagePB_CUIEncryptedFontFilePB::CUIFontFilePackagePB_CUIEncryptedFontFilePB(
    ::google::protobuf::Arena* arena,
    const CUIFontFilePackagePB_CUIEncryptedFontFilePB& from)
    : ::google::protobuf::Message(arena) {
  CUIFontFilePackagePB_CUIEncryptedFontFilePB* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);

  // @@protoc_insertion_point(copy_constructor:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
}
inline PROTOBUF_NDEBUG_INLINE CUIFontFilePackagePB_CUIEncryptedFontFilePB::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        encrypted_contents_(arena) {}

inline void CUIFontFilePackagePB_CUIEncryptedFontFilePB::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
CUIFontFilePackagePB_CUIEncryptedFontFilePB::~CUIFontFilePackagePB_CUIEncryptedFontFilePB() {
  // @@protoc_insertion_point(destructor:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void CUIFontFilePackagePB_CUIEncryptedFontFilePB::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.encrypted_contents_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
CUIFontFilePackagePB_CUIEncryptedFontFilePB::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              &_table_.header,
              nullptr,  // OnDemandRegisterArenaDtor
              nullptr,  // IsInitialized
              PROTOBUF_FIELD_OFFSET(CUIFontFilePackagePB_CUIEncryptedFontFilePB, _impl_._cached_size_),
              false,
          },
          &CUIFontFilePackagePB_CUIEncryptedFontFilePB::MergeImpl,
          &CUIFontFilePackagePB_CUIEncryptedFontFilePB::kDescriptorMethods,
          &descriptor_table_uifontfile_5fformat_2eproto,
          nullptr,  // tracker
      };
  ::google::protobuf::internal::PrefetchToLocalCache(&_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_data_.tc_table);
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 0, 2> CUIFontFilePackagePB_CUIEncryptedFontFilePB::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(CUIFontFilePackagePB_CUIEncryptedFontFilePB, _impl_._has_bits_),
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_CUIFontFilePackagePB_CUIEncryptedFontFilePB_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::CUIFontFilePackagePB_CUIEncryptedFontFilePB>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // optional bytes encrypted_contents = 1;
    {::_pbi::TcParser::FastBS1,
     {10, 0, 0, PROTOBUF_FIELD_OFFSET(CUIFontFilePackagePB_CUIEncryptedFontFilePB, _impl_.encrypted_contents_)}},
  }}, {{
    65535, 65535
  }}, {{
    // optional bytes encrypted_contents = 1;
    {PROTOBUF_FIELD_OFFSET(CUIFontFilePackagePB_CUIEncryptedFontFilePB, _impl_.encrypted_contents_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kBytes | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
  }},
};

PROTOBUF_NOINLINE void CUIFontFilePackagePB_CUIEncryptedFontFilePB::Clear() {
// @@protoc_insertion_point(message_clear_start:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    _impl_.encrypted_contents_.ClearNonDefaultToEmpty();
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

::uint8_t* CUIFontFilePackagePB_CUIEncryptedFontFilePB::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // optional bytes encrypted_contents = 1;
  if (cached_has_bits & 0x00000001u) {
    const std::string& _s = this->_internal_encrypted_contents();
    target = stream->WriteBytesMaybeAliased(1, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
  return target;
}

::size_t CUIFontFilePackagePB_CUIEncryptedFontFilePB::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional bytes encrypted_contents = 1;
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::BytesSize(
                                    this->_internal_encrypted_contents());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void CUIFontFilePackagePB_CUIEncryptedFontFilePB::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<CUIFontFilePackagePB_CUIEncryptedFontFilePB*>(&to_msg);
  auto& from = static_cast<const CUIFontFilePackagePB_CUIEncryptedFontFilePB&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    _this->_internal_set_encrypted_contents(from._internal_encrypted_contents());
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void CUIFontFilePackagePB_CUIEncryptedFontFilePB::CopyFrom(const CUIFontFilePackagePB_CUIEncryptedFontFilePB& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void CUIFontFilePackagePB_CUIEncryptedFontFilePB::InternalSwap(CUIFontFilePackagePB_CUIEncryptedFontFilePB* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.encrypted_contents_, &other->_impl_.encrypted_contents_, arena);
}

::google::protobuf::Metadata CUIFontFilePackagePB_CUIEncryptedFontFilePB::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class CUIFontFilePackagePB::_Internal {
 public:
  using HasBits =
      decltype(std::declval<CUIFontFilePackagePB>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
      8 * PROTOBUF_FIELD_OFFSET(CUIFontFilePackagePB, _impl_._has_bits_);
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x00000001) ^ 0x00000001) != 0;
  }
};

CUIFontFilePackagePB::CUIFontFilePackagePB(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:CUIFontFilePackagePB)
}
inline PROTOBUF_NDEBUG_INLINE CUIFontFilePackagePB::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::CUIFontFilePackagePB& from_msg)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        encrypted_font_files_{visibility, arena, from.encrypted_font_files_} {}

CUIFontFilePackagePB::CUIFontFilePackagePB(
    ::google::protobuf::Arena* arena,
    const CUIFontFilePackagePB& from)
    : ::google::protobuf::Message(arena) {
  CUIFontFilePackagePB* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);
  _impl_.package_version_ = from._impl_.package_version_;

  // @@protoc_insertion_point(copy_constructor:CUIFontFilePackagePB)
}
inline PROTOBUF_NDEBUG_INLINE CUIFontFilePackagePB::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        encrypted_font_files_{visibility, arena} {}

inline void CUIFontFilePackagePB::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.package_version_ = {};
}
CUIFontFilePackagePB::~CUIFontFilePackagePB() {
  // @@protoc_insertion_point(destructor:CUIFontFilePackagePB)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void CUIFontFilePackagePB::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
CUIFontFilePackagePB::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              &_table_.header,
              nullptr,  // OnDemandRegisterArenaDtor
              CUIFontFilePackagePB::IsInitializedImpl,
              PROTOBUF_FIELD_OFFSET(CUIFontFilePackagePB, _impl_._cached_size_),
              false,
          },
          &CUIFontFilePackagePB::MergeImpl,
          &CUIFontFilePackagePB::kDescriptorMethods,
          &descriptor_table_uifontfile_5fformat_2eproto,
          nullptr,  // tracker
      };
  ::google::protobuf::internal::PrefetchToLocalCache(&_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_data_.tc_table);
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 1, 0, 2> CUIFontFilePackagePB::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(CUIFontFilePackagePB, _impl_._has_bits_),
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_CUIFontFilePackagePB_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::CUIFontFilePackagePB>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // repeated .CUIFontFilePackagePB.CUIEncryptedFontFilePB encrypted_font_files = 2;
    {::_pbi::TcParser::FastMtR1,
     {18, 63, 0, PROTOBUF_FIELD_OFFSET(CUIFontFilePackagePB, _impl_.encrypted_font_files_)}},
    // required uint32 package_version = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(CUIFontFilePackagePB, _impl_.package_version_), 0>(),
     {8, 0, 0, PROTOBUF_FIELD_OFFSET(CUIFontFilePackagePB, _impl_.package_version_)}},
  }}, {{
    65535, 65535
  }}, {{
    // required uint32 package_version = 1;
    {PROTOBUF_FIELD_OFFSET(CUIFontFilePackagePB, _impl_.package_version_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kUInt32)},
    // repeated .CUIFontFilePackagePB.CUIEncryptedFontFilePB encrypted_font_files = 2;
    {PROTOBUF_FIELD_OFFSET(CUIFontFilePackagePB, _impl_.encrypted_font_files_), -1, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
  }}, {{
    {::_pbi::TcParser::GetTable<::CUIFontFilePackagePB_CUIEncryptedFontFilePB>()},
  }}, {{
  }},
};

PROTOBUF_NOINLINE void CUIFontFilePackagePB::Clear() {
// @@protoc_insertion_point(message_clear_start:CUIFontFilePackagePB)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.encrypted_font_files_.Clear();
  _impl_.package_version_ = 0u;
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

::uint8_t* CUIFontFilePackagePB::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:CUIFontFilePackagePB)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // required uint32 package_version = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(
        1, this->_internal_package_version(), target);
  }

  // repeated .CUIFontFilePackagePB.CUIEncryptedFontFilePB encrypted_font_files = 2;
  for (unsigned i = 0, n = static_cast<unsigned>(
                           this->_internal_encrypted_font_files_size());
       i < n; i++) {
    const auto& repfield = this->_internal_encrypted_font_files().Get(i);
    target =
        ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
            2, repfield, repfield.GetCachedSize(),
            target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CUIFontFilePackagePB)
  return target;
}

::size_t CUIFontFilePackagePB::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CUIFontFilePackagePB)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::_pbi::Prefetch5LinesFrom7Lines(reinterpret_cast<const void*>(this));
  // repeated .CUIFontFilePackagePB.CUIEncryptedFontFilePB encrypted_font_files = 2;
  total_size += 1UL * this->_internal_encrypted_font_files_size();
  for (const auto& msg : this->_internal_encrypted_font_files()) {
    total_size += ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
  }
  // required uint32 package_version = 1;
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(
        this->_internal_package_version());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void CUIFontFilePackagePB::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<CUIFontFilePackagePB*>(&to_msg);
  auto& from = static_cast<const CUIFontFilePackagePB&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:CUIFontFilePackagePB)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_encrypted_font_files()->MergeFrom(
      from._internal_encrypted_font_files());
  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    _this->_impl_.package_version_ = from._impl_.package_version_;
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void CUIFontFilePackagePB::CopyFrom(const CUIFontFilePackagePB& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CUIFontFilePackagePB)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool CUIFontFilePackagePB::IsInitializedImpl(
    const MessageLite& msg) {
  auto& this_ = static_cast<const CUIFontFilePackagePB&>(msg);
  if (_Internal::MissingRequiredFields(this_._impl_._has_bits_)) {
    return false;
  }
  return true;
}

void CUIFontFilePackagePB::InternalSwap(CUIFontFilePackagePB* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  _impl_.encrypted_font_files_.InternalSwap(&other->_impl_.encrypted_font_files_);
        swap(_impl_.package_version_, other->_impl_.package_version_);
}

::google::protobuf::Metadata CUIFontFilePackagePB::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ PROTOBUF_UNUSED =
        (::_pbi::AddDescriptors(&descriptor_table_uifontfile_5fformat_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
