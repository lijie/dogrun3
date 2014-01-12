// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: uiconfig.proto

#ifndef PROTOBUF_uiconfig_2eproto__INCLUDED
#define PROTOBUF_uiconfig_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace dogrun2 {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_uiconfig_2eproto();
void protobuf_AssignDesc_uiconfig_2eproto();
void protobuf_ShutdownFile_uiconfig_2eproto();

class UIElementFont;
class UIElementIcon;
class UIItemConf;
class UIItemConfArray;

enum kItemType {
  kItemTrain = 0,
  kItemPlay = 1
};
bool kItemType_IsValid(int value);
const kItemType kItemType_MIN = kItemTrain;
const kItemType kItemType_MAX = kItemPlay;
const int kItemType_ARRAYSIZE = kItemType_MAX + 1;

const ::google::protobuf::EnumDescriptor* kItemType_descriptor();
inline const ::std::string& kItemType_Name(kItemType value) {
  return ::google::protobuf::internal::NameOfEnum(
    kItemType_descriptor(), value);
}
inline bool kItemType_Parse(
    const ::std::string& name, kItemType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<kItemType>(
    kItemType_descriptor(), name, value);
}
// ===================================================================

class UIElementFont : public ::google::protobuf::Message {
 public:
  UIElementFont();
  virtual ~UIElementFont();

  UIElementFont(const UIElementFont& from);

  inline UIElementFont& operator=(const UIElementFont& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const UIElementFont& default_instance();

  void Swap(UIElementFont* other);

  // implements Message ----------------------------------------------

  UIElementFont* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const UIElementFont& from);
  void MergeFrom(const UIElementFont& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string desc = 1;
  inline bool has_desc() const;
  inline void clear_desc();
  static const int kDescFieldNumber = 1;
  inline const ::std::string& desc() const;
  inline void set_desc(const ::std::string& value);
  inline void set_desc(const char* value);
  inline void set_desc(const char* value, size_t size);
  inline ::std::string* mutable_desc();
  inline ::std::string* release_desc();
  inline void set_allocated_desc(::std::string* desc);

  // required string font = 2;
  inline bool has_font() const;
  inline void clear_font();
  static const int kFontFieldNumber = 2;
  inline const ::std::string& font() const;
  inline void set_font(const ::std::string& value);
  inline void set_font(const char* value);
  inline void set_font(const char* value, size_t size);
  inline ::std::string* mutable_font();
  inline ::std::string* release_font();
  inline void set_allocated_font(::std::string* font);

  // required int32 pos_x = 3;
  inline bool has_pos_x() const;
  inline void clear_pos_x();
  static const int kPosXFieldNumber = 3;
  inline ::google::protobuf::int32 pos_x() const;
  inline void set_pos_x(::google::protobuf::int32 value);

  // required int32 pos_y = 4;
  inline bool has_pos_y() const;
  inline void clear_pos_y();
  static const int kPosYFieldNumber = 4;
  inline ::google::protobuf::int32 pos_y() const;
  inline void set_pos_y(::google::protobuf::int32 value);

  // required int32 font_size = 5;
  inline bool has_font_size() const;
  inline void clear_font_size();
  static const int kFontSizeFieldNumber = 5;
  inline ::google::protobuf::int32 font_size() const;
  inline void set_font_size(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:dogrun2.UIElementFont)
 private:
  inline void set_has_desc();
  inline void clear_has_desc();
  inline void set_has_font();
  inline void clear_has_font();
  inline void set_has_pos_x();
  inline void clear_has_pos_x();
  inline void set_has_pos_y();
  inline void clear_has_pos_y();
  inline void set_has_font_size();
  inline void clear_has_font_size();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* desc_;
  ::std::string* font_;
  ::google::protobuf::int32 pos_x_;
  ::google::protobuf::int32 pos_y_;
  ::google::protobuf::int32 font_size_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];

  friend void  protobuf_AddDesc_uiconfig_2eproto();
  friend void protobuf_AssignDesc_uiconfig_2eproto();
  friend void protobuf_ShutdownFile_uiconfig_2eproto();

  void InitAsDefaultInstance();
  static UIElementFont* default_instance_;
};
// -------------------------------------------------------------------

class UIElementIcon : public ::google::protobuf::Message {
 public:
  UIElementIcon();
  virtual ~UIElementIcon();

  UIElementIcon(const UIElementIcon& from);

  inline UIElementIcon& operator=(const UIElementIcon& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const UIElementIcon& default_instance();

  void Swap(UIElementIcon* other);

  // implements Message ----------------------------------------------

  UIElementIcon* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const UIElementIcon& from);
  void MergeFrom(const UIElementIcon& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string icon = 1;
  inline bool has_icon() const;
  inline void clear_icon();
  static const int kIconFieldNumber = 1;
  inline const ::std::string& icon() const;
  inline void set_icon(const ::std::string& value);
  inline void set_icon(const char* value);
  inline void set_icon(const char* value, size_t size);
  inline ::std::string* mutable_icon();
  inline ::std::string* release_icon();
  inline void set_allocated_icon(::std::string* icon);

  // required int32 pos_x = 2;
  inline bool has_pos_x() const;
  inline void clear_pos_x();
  static const int kPosXFieldNumber = 2;
  inline ::google::protobuf::int32 pos_x() const;
  inline void set_pos_x(::google::protobuf::int32 value);

  // required int32 pos_y = 3;
  inline bool has_pos_y() const;
  inline void clear_pos_y();
  static const int kPosYFieldNumber = 3;
  inline ::google::protobuf::int32 pos_y() const;
  inline void set_pos_y(::google::protobuf::int32 value);

  // required int32 scale = 4;
  inline bool has_scale() const;
  inline void clear_scale();
  static const int kScaleFieldNumber = 4;
  inline ::google::protobuf::int32 scale() const;
  inline void set_scale(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:dogrun2.UIElementIcon)
 private:
  inline void set_has_icon();
  inline void clear_has_icon();
  inline void set_has_pos_x();
  inline void clear_has_pos_x();
  inline void set_has_pos_y();
  inline void clear_has_pos_y();
  inline void set_has_scale();
  inline void clear_has_scale();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* icon_;
  ::google::protobuf::int32 pos_x_;
  ::google::protobuf::int32 pos_y_;
  ::google::protobuf::int32 scale_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_uiconfig_2eproto();
  friend void protobuf_AssignDesc_uiconfig_2eproto();
  friend void protobuf_ShutdownFile_uiconfig_2eproto();

  void InitAsDefaultInstance();
  static UIElementIcon* default_instance_;
};
// -------------------------------------------------------------------

class UIItemConf : public ::google::protobuf::Message {
 public:
  UIItemConf();
  virtual ~UIItemConf();

  UIItemConf(const UIItemConf& from);

  inline UIItemConf& operator=(const UIItemConf& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const UIItemConf& default_instance();

  void Swap(UIItemConf* other);

  // implements Message ----------------------------------------------

  UIItemConf* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const UIItemConf& from);
  void MergeFrom(const UIItemConf& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .dogrun2.UIElementFont title = 1;
  inline bool has_title() const;
  inline void clear_title();
  static const int kTitleFieldNumber = 1;
  inline const ::dogrun2::UIElementFont& title() const;
  inline ::dogrun2::UIElementFont* mutable_title();
  inline ::dogrun2::UIElementFont* release_title();
  inline void set_allocated_title(::dogrun2::UIElementFont* title);

  // required .dogrun2.UIElementFont speed = 2;
  inline bool has_speed() const;
  inline void clear_speed();
  static const int kSpeedFieldNumber = 2;
  inline const ::dogrun2::UIElementFont& speed() const;
  inline ::dogrun2::UIElementFont* mutable_speed();
  inline ::dogrun2::UIElementFont* release_speed();
  inline void set_allocated_speed(::dogrun2::UIElementFont* speed);

  // required .dogrun2.UIElementFont exp = 3;
  inline bool has_exp() const;
  inline void clear_exp();
  static const int kExpFieldNumber = 3;
  inline const ::dogrun2::UIElementFont& exp() const;
  inline ::dogrun2::UIElementFont* mutable_exp();
  inline ::dogrun2::UIElementFont* release_exp();
  inline void set_allocated_exp(::dogrun2::UIElementFont* exp);

  // required .dogrun2.UIElementIcon icon = 4;
  inline bool has_icon() const;
  inline void clear_icon();
  static const int kIconFieldNumber = 4;
  inline const ::dogrun2::UIElementIcon& icon() const;
  inline ::dogrun2::UIElementIcon* mutable_icon();
  inline ::dogrun2::UIElementIcon* release_icon();
  inline void set_allocated_icon(::dogrun2::UIElementIcon* icon);

  // required .dogrun2.UIElementFont icon_num = 5;
  inline bool has_icon_num() const;
  inline void clear_icon_num();
  static const int kIconNumFieldNumber = 5;
  inline const ::dogrun2::UIElementFont& icon_num() const;
  inline ::dogrun2::UIElementFont* mutable_icon_num();
  inline ::dogrun2::UIElementFont* release_icon_num();
  inline void set_allocated_icon_num(::dogrun2::UIElementFont* icon_num);

  // @@protoc_insertion_point(class_scope:dogrun2.UIItemConf)
 private:
  inline void set_has_title();
  inline void clear_has_title();
  inline void set_has_speed();
  inline void clear_has_speed();
  inline void set_has_exp();
  inline void clear_has_exp();
  inline void set_has_icon();
  inline void clear_has_icon();
  inline void set_has_icon_num();
  inline void clear_has_icon_num();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::dogrun2::UIElementFont* title_;
  ::dogrun2::UIElementFont* speed_;
  ::dogrun2::UIElementFont* exp_;
  ::dogrun2::UIElementIcon* icon_;
  ::dogrun2::UIElementFont* icon_num_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];

  friend void  protobuf_AddDesc_uiconfig_2eproto();
  friend void protobuf_AssignDesc_uiconfig_2eproto();
  friend void protobuf_ShutdownFile_uiconfig_2eproto();

  void InitAsDefaultInstance();
  static UIItemConf* default_instance_;
};
// -------------------------------------------------------------------

class UIItemConfArray : public ::google::protobuf::Message {
 public:
  UIItemConfArray();
  virtual ~UIItemConfArray();

  UIItemConfArray(const UIItemConfArray& from);

  inline UIItemConfArray& operator=(const UIItemConfArray& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const UIItemConfArray& default_instance();

  void Swap(UIItemConfArray* other);

  // implements Message ----------------------------------------------

  UIItemConfArray* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const UIItemConfArray& from);
  void MergeFrom(const UIItemConfArray& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .dogrun2.UIItemConf conf = 1;
  inline int conf_size() const;
  inline void clear_conf();
  static const int kConfFieldNumber = 1;
  inline const ::dogrun2::UIItemConf& conf(int index) const;
  inline ::dogrun2::UIItemConf* mutable_conf(int index);
  inline ::dogrun2::UIItemConf* add_conf();
  inline const ::google::protobuf::RepeatedPtrField< ::dogrun2::UIItemConf >&
      conf() const;
  inline ::google::protobuf::RepeatedPtrField< ::dogrun2::UIItemConf >*
      mutable_conf();

  // @@protoc_insertion_point(class_scope:dogrun2.UIItemConfArray)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::dogrun2::UIItemConf > conf_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_uiconfig_2eproto();
  friend void protobuf_AssignDesc_uiconfig_2eproto();
  friend void protobuf_ShutdownFile_uiconfig_2eproto();

  void InitAsDefaultInstance();
  static UIItemConfArray* default_instance_;
};
// ===================================================================


// ===================================================================

// UIElementFont

// required string desc = 1;
inline bool UIElementFont::has_desc() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void UIElementFont::set_has_desc() {
  _has_bits_[0] |= 0x00000001u;
}
inline void UIElementFont::clear_has_desc() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void UIElementFont::clear_desc() {
  if (desc_ != &::google::protobuf::internal::kEmptyString) {
    desc_->clear();
  }
  clear_has_desc();
}
inline const ::std::string& UIElementFont::desc() const {
  return *desc_;
}
inline void UIElementFont::set_desc(const ::std::string& value) {
  set_has_desc();
  if (desc_ == &::google::protobuf::internal::kEmptyString) {
    desc_ = new ::std::string;
  }
  desc_->assign(value);
}
inline void UIElementFont::set_desc(const char* value) {
  set_has_desc();
  if (desc_ == &::google::protobuf::internal::kEmptyString) {
    desc_ = new ::std::string;
  }
  desc_->assign(value);
}
inline void UIElementFont::set_desc(const char* value, size_t size) {
  set_has_desc();
  if (desc_ == &::google::protobuf::internal::kEmptyString) {
    desc_ = new ::std::string;
  }
  desc_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* UIElementFont::mutable_desc() {
  set_has_desc();
  if (desc_ == &::google::protobuf::internal::kEmptyString) {
    desc_ = new ::std::string;
  }
  return desc_;
}
inline ::std::string* UIElementFont::release_desc() {
  clear_has_desc();
  if (desc_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = desc_;
    desc_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void UIElementFont::set_allocated_desc(::std::string* desc) {
  if (desc_ != &::google::protobuf::internal::kEmptyString) {
    delete desc_;
  }
  if (desc) {
    set_has_desc();
    desc_ = desc;
  } else {
    clear_has_desc();
    desc_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required string font = 2;
inline bool UIElementFont::has_font() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void UIElementFont::set_has_font() {
  _has_bits_[0] |= 0x00000002u;
}
inline void UIElementFont::clear_has_font() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void UIElementFont::clear_font() {
  if (font_ != &::google::protobuf::internal::kEmptyString) {
    font_->clear();
  }
  clear_has_font();
}
inline const ::std::string& UIElementFont::font() const {
  return *font_;
}
inline void UIElementFont::set_font(const ::std::string& value) {
  set_has_font();
  if (font_ == &::google::protobuf::internal::kEmptyString) {
    font_ = new ::std::string;
  }
  font_->assign(value);
}
inline void UIElementFont::set_font(const char* value) {
  set_has_font();
  if (font_ == &::google::protobuf::internal::kEmptyString) {
    font_ = new ::std::string;
  }
  font_->assign(value);
}
inline void UIElementFont::set_font(const char* value, size_t size) {
  set_has_font();
  if (font_ == &::google::protobuf::internal::kEmptyString) {
    font_ = new ::std::string;
  }
  font_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* UIElementFont::mutable_font() {
  set_has_font();
  if (font_ == &::google::protobuf::internal::kEmptyString) {
    font_ = new ::std::string;
  }
  return font_;
}
inline ::std::string* UIElementFont::release_font() {
  clear_has_font();
  if (font_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = font_;
    font_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void UIElementFont::set_allocated_font(::std::string* font) {
  if (font_ != &::google::protobuf::internal::kEmptyString) {
    delete font_;
  }
  if (font) {
    set_has_font();
    font_ = font;
  } else {
    clear_has_font();
    font_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required int32 pos_x = 3;
inline bool UIElementFont::has_pos_x() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void UIElementFont::set_has_pos_x() {
  _has_bits_[0] |= 0x00000004u;
}
inline void UIElementFont::clear_has_pos_x() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void UIElementFont::clear_pos_x() {
  pos_x_ = 0;
  clear_has_pos_x();
}
inline ::google::protobuf::int32 UIElementFont::pos_x() const {
  return pos_x_;
}
inline void UIElementFont::set_pos_x(::google::protobuf::int32 value) {
  set_has_pos_x();
  pos_x_ = value;
}

// required int32 pos_y = 4;
inline bool UIElementFont::has_pos_y() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void UIElementFont::set_has_pos_y() {
  _has_bits_[0] |= 0x00000008u;
}
inline void UIElementFont::clear_has_pos_y() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void UIElementFont::clear_pos_y() {
  pos_y_ = 0;
  clear_has_pos_y();
}
inline ::google::protobuf::int32 UIElementFont::pos_y() const {
  return pos_y_;
}
inline void UIElementFont::set_pos_y(::google::protobuf::int32 value) {
  set_has_pos_y();
  pos_y_ = value;
}

// required int32 font_size = 5;
inline bool UIElementFont::has_font_size() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void UIElementFont::set_has_font_size() {
  _has_bits_[0] |= 0x00000010u;
}
inline void UIElementFont::clear_has_font_size() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void UIElementFont::clear_font_size() {
  font_size_ = 0;
  clear_has_font_size();
}
inline ::google::protobuf::int32 UIElementFont::font_size() const {
  return font_size_;
}
inline void UIElementFont::set_font_size(::google::protobuf::int32 value) {
  set_has_font_size();
  font_size_ = value;
}

// -------------------------------------------------------------------

// UIElementIcon

// required string icon = 1;
inline bool UIElementIcon::has_icon() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void UIElementIcon::set_has_icon() {
  _has_bits_[0] |= 0x00000001u;
}
inline void UIElementIcon::clear_has_icon() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void UIElementIcon::clear_icon() {
  if (icon_ != &::google::protobuf::internal::kEmptyString) {
    icon_->clear();
  }
  clear_has_icon();
}
inline const ::std::string& UIElementIcon::icon() const {
  return *icon_;
}
inline void UIElementIcon::set_icon(const ::std::string& value) {
  set_has_icon();
  if (icon_ == &::google::protobuf::internal::kEmptyString) {
    icon_ = new ::std::string;
  }
  icon_->assign(value);
}
inline void UIElementIcon::set_icon(const char* value) {
  set_has_icon();
  if (icon_ == &::google::protobuf::internal::kEmptyString) {
    icon_ = new ::std::string;
  }
  icon_->assign(value);
}
inline void UIElementIcon::set_icon(const char* value, size_t size) {
  set_has_icon();
  if (icon_ == &::google::protobuf::internal::kEmptyString) {
    icon_ = new ::std::string;
  }
  icon_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* UIElementIcon::mutable_icon() {
  set_has_icon();
  if (icon_ == &::google::protobuf::internal::kEmptyString) {
    icon_ = new ::std::string;
  }
  return icon_;
}
inline ::std::string* UIElementIcon::release_icon() {
  clear_has_icon();
  if (icon_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = icon_;
    icon_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void UIElementIcon::set_allocated_icon(::std::string* icon) {
  if (icon_ != &::google::protobuf::internal::kEmptyString) {
    delete icon_;
  }
  if (icon) {
    set_has_icon();
    icon_ = icon;
  } else {
    clear_has_icon();
    icon_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required int32 pos_x = 2;
inline bool UIElementIcon::has_pos_x() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void UIElementIcon::set_has_pos_x() {
  _has_bits_[0] |= 0x00000002u;
}
inline void UIElementIcon::clear_has_pos_x() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void UIElementIcon::clear_pos_x() {
  pos_x_ = 0;
  clear_has_pos_x();
}
inline ::google::protobuf::int32 UIElementIcon::pos_x() const {
  return pos_x_;
}
inline void UIElementIcon::set_pos_x(::google::protobuf::int32 value) {
  set_has_pos_x();
  pos_x_ = value;
}

// required int32 pos_y = 3;
inline bool UIElementIcon::has_pos_y() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void UIElementIcon::set_has_pos_y() {
  _has_bits_[0] |= 0x00000004u;
}
inline void UIElementIcon::clear_has_pos_y() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void UIElementIcon::clear_pos_y() {
  pos_y_ = 0;
  clear_has_pos_y();
}
inline ::google::protobuf::int32 UIElementIcon::pos_y() const {
  return pos_y_;
}
inline void UIElementIcon::set_pos_y(::google::protobuf::int32 value) {
  set_has_pos_y();
  pos_y_ = value;
}

// required int32 scale = 4;
inline bool UIElementIcon::has_scale() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void UIElementIcon::set_has_scale() {
  _has_bits_[0] |= 0x00000008u;
}
inline void UIElementIcon::clear_has_scale() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void UIElementIcon::clear_scale() {
  scale_ = 0;
  clear_has_scale();
}
inline ::google::protobuf::int32 UIElementIcon::scale() const {
  return scale_;
}
inline void UIElementIcon::set_scale(::google::protobuf::int32 value) {
  set_has_scale();
  scale_ = value;
}

// -------------------------------------------------------------------

// UIItemConf

// required .dogrun2.UIElementFont title = 1;
inline bool UIItemConf::has_title() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void UIItemConf::set_has_title() {
  _has_bits_[0] |= 0x00000001u;
}
inline void UIItemConf::clear_has_title() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void UIItemConf::clear_title() {
  if (title_ != NULL) title_->::dogrun2::UIElementFont::Clear();
  clear_has_title();
}
inline const ::dogrun2::UIElementFont& UIItemConf::title() const {
  return title_ != NULL ? *title_ : *default_instance_->title_;
}
inline ::dogrun2::UIElementFont* UIItemConf::mutable_title() {
  set_has_title();
  if (title_ == NULL) title_ = new ::dogrun2::UIElementFont;
  return title_;
}
inline ::dogrun2::UIElementFont* UIItemConf::release_title() {
  clear_has_title();
  ::dogrun2::UIElementFont* temp = title_;
  title_ = NULL;
  return temp;
}
inline void UIItemConf::set_allocated_title(::dogrun2::UIElementFont* title) {
  delete title_;
  title_ = title;
  if (title) {
    set_has_title();
  } else {
    clear_has_title();
  }
}

// required .dogrun2.UIElementFont speed = 2;
inline bool UIItemConf::has_speed() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void UIItemConf::set_has_speed() {
  _has_bits_[0] |= 0x00000002u;
}
inline void UIItemConf::clear_has_speed() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void UIItemConf::clear_speed() {
  if (speed_ != NULL) speed_->::dogrun2::UIElementFont::Clear();
  clear_has_speed();
}
inline const ::dogrun2::UIElementFont& UIItemConf::speed() const {
  return speed_ != NULL ? *speed_ : *default_instance_->speed_;
}
inline ::dogrun2::UIElementFont* UIItemConf::mutable_speed() {
  set_has_speed();
  if (speed_ == NULL) speed_ = new ::dogrun2::UIElementFont;
  return speed_;
}
inline ::dogrun2::UIElementFont* UIItemConf::release_speed() {
  clear_has_speed();
  ::dogrun2::UIElementFont* temp = speed_;
  speed_ = NULL;
  return temp;
}
inline void UIItemConf::set_allocated_speed(::dogrun2::UIElementFont* speed) {
  delete speed_;
  speed_ = speed;
  if (speed) {
    set_has_speed();
  } else {
    clear_has_speed();
  }
}

// required .dogrun2.UIElementFont exp = 3;
inline bool UIItemConf::has_exp() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void UIItemConf::set_has_exp() {
  _has_bits_[0] |= 0x00000004u;
}
inline void UIItemConf::clear_has_exp() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void UIItemConf::clear_exp() {
  if (exp_ != NULL) exp_->::dogrun2::UIElementFont::Clear();
  clear_has_exp();
}
inline const ::dogrun2::UIElementFont& UIItemConf::exp() const {
  return exp_ != NULL ? *exp_ : *default_instance_->exp_;
}
inline ::dogrun2::UIElementFont* UIItemConf::mutable_exp() {
  set_has_exp();
  if (exp_ == NULL) exp_ = new ::dogrun2::UIElementFont;
  return exp_;
}
inline ::dogrun2::UIElementFont* UIItemConf::release_exp() {
  clear_has_exp();
  ::dogrun2::UIElementFont* temp = exp_;
  exp_ = NULL;
  return temp;
}
inline void UIItemConf::set_allocated_exp(::dogrun2::UIElementFont* exp) {
  delete exp_;
  exp_ = exp;
  if (exp) {
    set_has_exp();
  } else {
    clear_has_exp();
  }
}

// required .dogrun2.UIElementIcon icon = 4;
inline bool UIItemConf::has_icon() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void UIItemConf::set_has_icon() {
  _has_bits_[0] |= 0x00000008u;
}
inline void UIItemConf::clear_has_icon() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void UIItemConf::clear_icon() {
  if (icon_ != NULL) icon_->::dogrun2::UIElementIcon::Clear();
  clear_has_icon();
}
inline const ::dogrun2::UIElementIcon& UIItemConf::icon() const {
  return icon_ != NULL ? *icon_ : *default_instance_->icon_;
}
inline ::dogrun2::UIElementIcon* UIItemConf::mutable_icon() {
  set_has_icon();
  if (icon_ == NULL) icon_ = new ::dogrun2::UIElementIcon;
  return icon_;
}
inline ::dogrun2::UIElementIcon* UIItemConf::release_icon() {
  clear_has_icon();
  ::dogrun2::UIElementIcon* temp = icon_;
  icon_ = NULL;
  return temp;
}
inline void UIItemConf::set_allocated_icon(::dogrun2::UIElementIcon* icon) {
  delete icon_;
  icon_ = icon;
  if (icon) {
    set_has_icon();
  } else {
    clear_has_icon();
  }
}

// required .dogrun2.UIElementFont icon_num = 5;
inline bool UIItemConf::has_icon_num() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void UIItemConf::set_has_icon_num() {
  _has_bits_[0] |= 0x00000010u;
}
inline void UIItemConf::clear_has_icon_num() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void UIItemConf::clear_icon_num() {
  if (icon_num_ != NULL) icon_num_->::dogrun2::UIElementFont::Clear();
  clear_has_icon_num();
}
inline const ::dogrun2::UIElementFont& UIItemConf::icon_num() const {
  return icon_num_ != NULL ? *icon_num_ : *default_instance_->icon_num_;
}
inline ::dogrun2::UIElementFont* UIItemConf::mutable_icon_num() {
  set_has_icon_num();
  if (icon_num_ == NULL) icon_num_ = new ::dogrun2::UIElementFont;
  return icon_num_;
}
inline ::dogrun2::UIElementFont* UIItemConf::release_icon_num() {
  clear_has_icon_num();
  ::dogrun2::UIElementFont* temp = icon_num_;
  icon_num_ = NULL;
  return temp;
}
inline void UIItemConf::set_allocated_icon_num(::dogrun2::UIElementFont* icon_num) {
  delete icon_num_;
  icon_num_ = icon_num;
  if (icon_num) {
    set_has_icon_num();
  } else {
    clear_has_icon_num();
  }
}

// -------------------------------------------------------------------

// UIItemConfArray

// repeated .dogrun2.UIItemConf conf = 1;
inline int UIItemConfArray::conf_size() const {
  return conf_.size();
}
inline void UIItemConfArray::clear_conf() {
  conf_.Clear();
}
inline const ::dogrun2::UIItemConf& UIItemConfArray::conf(int index) const {
  return conf_.Get(index);
}
inline ::dogrun2::UIItemConf* UIItemConfArray::mutable_conf(int index) {
  return conf_.Mutable(index);
}
inline ::dogrun2::UIItemConf* UIItemConfArray::add_conf() {
  return conf_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::dogrun2::UIItemConf >&
UIItemConfArray::conf() const {
  return conf_;
}
inline ::google::protobuf::RepeatedPtrField< ::dogrun2::UIItemConf >*
UIItemConfArray::mutable_conf() {
  return &conf_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace dogrun2

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::dogrun2::kItemType>() {
  return ::dogrun2::kItemType_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_uiconfig_2eproto__INCLUDED
