// Copyright (c) 2022 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=33a684b03178472bdf93e70043304cce8bc32d05$
//

#ifndef CEF_INCLUDE_CAPI_TEST_CEF_TRANSLATOR_TEST_CAPI_H_
#define CEF_INCLUDE_CAPI_TEST_CEF_TRANSLATOR_TEST_CAPI_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED) && !defined(WRAPPING_CEF_SHARED) && \
    !defined(UNIT_TEST)
#error This file can be included for unit tests only
#endif

#include "include/capi/cef_base_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _cef_translator_test_ref_ptr_client_child_t;
struct _cef_translator_test_ref_ptr_client_t;
struct _cef_translator_test_ref_ptr_library_child_t;
struct _cef_translator_test_ref_ptr_library_t;
struct _cef_translator_test_scoped_client_child_t;
struct _cef_translator_test_scoped_client_t;
struct _cef_translator_test_scoped_library_child_t;
struct _cef_translator_test_scoped_library_t;

///
// Structure for testing all of the possible data transfer types.
///
typedef struct _cef_translator_test_t {
  ///
  // Base structure.
  ///
  cef_base_ref_counted_t base;

  // PRIMITIVE VALUES

  ///
  // Return a void value.
  ///
  void(CEF_CALLBACK* get_void)(struct _cef_translator_test_t* self);

  ///
  // Return a bool value.
  ///
  int(CEF_CALLBACK* get_bool)(struct _cef_translator_test_t* self);

  ///
  // Return an int value.
  ///
  int(CEF_CALLBACK* get_int)(struct _cef_translator_test_t* self);

  ///
  // Return a double value.
  ///
  double(CEF_CALLBACK* get_double)(struct _cef_translator_test_t* self);

  ///
  // Return a long value.
  ///
  long(CEF_CALLBACK* get_long)(struct _cef_translator_test_t* self);

  ///
  // Return a size_t value.
  ///
  size_t(CEF_CALLBACK* get_sizet)(struct _cef_translator_test_t* self);

  ///
  // Set a void value.
  ///
  int(CEF_CALLBACK* set_void)(struct _cef_translator_test_t* self);

  ///
  // Set a bool value.
  ///
  int(CEF_CALLBACK* set_bool)(struct _cef_translator_test_t* self, int val);

  ///
  // Set an int value.
  ///
  int(CEF_CALLBACK* set_int)(struct _cef_translator_test_t* self, int val);

  ///
  // Set a double value.
  ///
  int(CEF_CALLBACK* set_double)(struct _cef_translator_test_t* self,
                                double val);

  ///
  // Set a long value.
  ///
  int(CEF_CALLBACK* set_long)(struct _cef_translator_test_t* self, long val);

  ///
  // Set a size_t value.
  ///
  int(CEF_CALLBACK* set_sizet)(struct _cef_translator_test_t* self, size_t val);

  ///
  // Set a int list value.
  ///
  int(CEF_CALLBACK* set_int_list)(struct _cef_translator_test_t* self,
                                  size_t valCount,
                                  int const* val);

  ///
  // Return an int list value by out-param.
  ///
  int(CEF_CALLBACK* get_int_list_by_ref)(struct _cef_translator_test_t* self,
                                         size_t* valCount,
                                         int* val);

  ///
  // Return the number of points that will be output above.
  ///
  size_t(CEF_CALLBACK* get_int_list_size)(struct _cef_translator_test_t* self);

  // STRING VALUES

  ///
  // Return a string value.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_string)(
      struct _cef_translator_test_t* self);

  ///
  // Set a string value.
  ///
  int(CEF_CALLBACK* set_string)(struct _cef_translator_test_t* self,
                                const cef_string_t* val);

  ///
  // Return a string value by out-param.
  ///
  void(CEF_CALLBACK* get_string_by_ref)(struct _cef_translator_test_t* self,
                                        cef_string_t* val);

  ///
  // Set a string list value.
  ///
  int(CEF_CALLBACK* set_string_list)(struct _cef_translator_test_t* self,
                                     cef_string_list_t val);

  ///
  // Return a string list value by out-param.
  ///
  int(CEF_CALLBACK* get_string_list_by_ref)(struct _cef_translator_test_t* self,
                                            cef_string_list_t val);

  ///
  // Set a string map value.
  ///
  int(CEF_CALLBACK* set_string_map)(struct _cef_translator_test_t* self,
                                    cef_string_map_t val);

  ///
  // Return a string map value by out-param.
  ///
  int(CEF_CALLBACK* get_string_map_by_ref)(struct _cef_translator_test_t* self,
                                           cef_string_map_t val);

  ///
  // Set a string multimap value.
  ///
  int(CEF_CALLBACK* set_string_multimap)(struct _cef_translator_test_t* self,
                                         cef_string_multimap_t val);

  ///
  // Return a string multimap value by out-param.
  ///
  int(CEF_CALLBACK* get_string_multimap_by_ref)(
      struct _cef_translator_test_t* self,
      cef_string_multimap_t val);

  // STRUCT VALUES

  ///
  // Return a point value.
  ///
  cef_point_t(CEF_CALLBACK* get_point)(struct _cef_translator_test_t* self);

  ///
  // Set a point value.
  ///
  int(CEF_CALLBACK* set_point)(struct _cef_translator_test_t* self,
                               const cef_point_t* val);

  ///
  // Return a point value by out-param.
  ///
  void(CEF_CALLBACK* get_point_by_ref)(struct _cef_translator_test_t* self,
                                       cef_point_t* val);

  ///
  // Set a point list vlaue.
  ///
  int(CEF_CALLBACK* set_point_list)(struct _cef_translator_test_t* self,
                                    size_t valCount,
                                    cef_point_t const* val);

  ///
  // Return a point list value by out-param.
  ///
  int(CEF_CALLBACK* get_point_list_by_ref)(struct _cef_translator_test_t* self,
                                           size_t* valCount,
                                           cef_point_t* val);

  ///
  // Return the number of points that will be output above.
  ///
  size_t(CEF_CALLBACK* get_point_list_size)(
      struct _cef_translator_test_t* self);

  // LIBRARY-SIDE REFPTR VALUES

  ///
  // Return an new library-side object.
  ///
  struct _cef_translator_test_ref_ptr_library_t*(
      CEF_CALLBACK* get_ref_ptr_library)(struct _cef_translator_test_t* self,
                                         int val);

  ///
  // Set an object. Returns the value from
  // cef_translator_test_ref_ptr_library_t::get_value(). This tests input and
  // execution of a library-side object type.
  ///
  int(CEF_CALLBACK* set_ref_ptr_library)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_ref_ptr_library_t* val);

  ///
  // Set an object. Returns the object passed in. This tests input and output of
  // a library-side object type.
  ///
  struct _cef_translator_test_ref_ptr_library_t*(
      CEF_CALLBACK* set_ref_ptr_library_and_return)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_ref_ptr_library_t* val);

  ///
  // Set a child object. Returns the value from
  // cef_translator_test_ref_ptr_library_t::get_value(). This tests input of a
  // library- side child object type and execution as the parent type.
  ///
  int(CEF_CALLBACK* set_child_ref_ptr_library)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_ref_ptr_library_child_t* val);

  ///
  // Set a child object. Returns the object as the parent type. This tests input
  // of a library-side child object type and return as the parent type.
  ///
  struct _cef_translator_test_ref_ptr_library_t*(
      CEF_CALLBACK* set_child_ref_ptr_library_and_return_parent)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_ref_ptr_library_child_t* val);

  ///
  // Set an object list vlaue.
  ///
  int(CEF_CALLBACK* set_ref_ptr_library_list)(
      struct _cef_translator_test_t* self,
      size_t valCount,
      struct _cef_translator_test_ref_ptr_library_t* const* val,
      int val1,
      int val2);

  ///
  // Return an object list value by out-param.
  ///
  int(CEF_CALLBACK* get_ref_ptr_library_list_by_ref)(
      struct _cef_translator_test_t* self,
      size_t* valCount,
      struct _cef_translator_test_ref_ptr_library_t** val,
      int val1,
      int val2);

  ///
  // Return the number of object that will be output above.
  ///
  size_t(CEF_CALLBACK* get_ref_ptr_library_list_size)(
      struct _cef_translator_test_t* self);

  // CLIENT-SIDE REFPTR VALUES

  ///
  // Set an object. Returns the value from
  // cef_translator_test_ref_ptr_client_t::get_value(). This tests input and
  // execution of a client-side object type.
  ///
  int(CEF_CALLBACK* set_ref_ptr_client)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_ref_ptr_client_t* val);

  ///
  // Set an object. Returns the handler passed in. This tests input and output
  // of a client-side object type.
  ///
  struct _cef_translator_test_ref_ptr_client_t*(
      CEF_CALLBACK* set_ref_ptr_client_and_return)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_ref_ptr_client_t* val);

  ///
  // Set a child object. Returns the value from
  // cef_translator_test_ref_ptr_client_t::get_value(). This tests input of a
  // client- side child object type and execution as the parent type.
  ///
  int(CEF_CALLBACK* set_child_ref_ptr_client)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_ref_ptr_client_child_t* val);

  ///
  // Set a child object. Returns the object as the parent type. This tests input
  // of a client-side child object type and return as the parent type.
  ///
  struct _cef_translator_test_ref_ptr_client_t*(
      CEF_CALLBACK* set_child_ref_ptr_client_and_return_parent)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_ref_ptr_client_child_t* val);

  ///
  // Set an object list vlaue.
  ///
  int(CEF_CALLBACK* set_ref_ptr_client_list)(
      struct _cef_translator_test_t* self,
      size_t valCount,
      struct _cef_translator_test_ref_ptr_client_t* const* val,
      int val1,
      int val2);

  ///
  // Return an object list value by out-param.
  ///
  int(CEF_CALLBACK* get_ref_ptr_client_list_by_ref)(
      struct _cef_translator_test_t* self,
      size_t* valCount,
      struct _cef_translator_test_ref_ptr_client_t** val,
      struct _cef_translator_test_ref_ptr_client_t* val1,
      struct _cef_translator_test_ref_ptr_client_t* val2);

  ///
  // Return the number of object that will be output above.
  ///
  size_t(CEF_CALLBACK* get_ref_ptr_client_list_size)(
      struct _cef_translator_test_t* self);

  // LIBRARY-SIDE OWNPTR VALUES

  ///
  // Return an new library-side object.
  ///
  struct _cef_translator_test_scoped_library_t*(
      CEF_CALLBACK* get_own_ptr_library)(struct _cef_translator_test_t* self,
                                         int val);

  ///
  // Set an object. Returns the value from
  // cef_translator_test_scoped_library_t::get_value(). This tests input and
  // execution of a library-side object type.
  ///
  int(CEF_CALLBACK* set_own_ptr_library)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_scoped_library_t* val);

  ///
  // Set an object. Returns the object passed in. This tests input and output of
  // a library-side object type.
  ///
  struct _cef_translator_test_scoped_library_t*(
      CEF_CALLBACK* set_own_ptr_library_and_return)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_scoped_library_t* val);

  ///
  // Set a child object. Returns the value from
  // cef_translator_test_scoped_library_t::get_value(). This tests input of a
  // library- side child object type and execution as the parent type.
  ///
  int(CEF_CALLBACK* set_child_own_ptr_library)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_scoped_library_child_t* val);

  ///
  // Set a child object. Returns the object as the parent type. This tests input
  // of a library-side child object type and return as the parent type.
  ///
  struct _cef_translator_test_scoped_library_t*(
      CEF_CALLBACK* set_child_own_ptr_library_and_return_parent)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_scoped_library_child_t* val);

  // CLIENT-SIDE OWNPTR VALUES

  ///
  // Set an object. Returns the value from
  // cef_translator_test_scoped_client_t::get_value(). This tests input and
  // execution of a client-side object type.
  ///
  int(CEF_CALLBACK* set_own_ptr_client)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_scoped_client_t* val);

  ///
  // Set an object. Returns the handler passed in. This tests input and output
  // of a client-side object type.
  ///
  struct _cef_translator_test_scoped_client_t*(
      CEF_CALLBACK* set_own_ptr_client_and_return)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_scoped_client_t* val);

  ///
  // Set a child object. Returns the value from
  // cef_translator_test_scoped_client_t::get_value(). This tests input of a
  // client- side child object type and execution as the parent type.
  ///
  int(CEF_CALLBACK* set_child_own_ptr_client)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_scoped_client_child_t* val);

  ///
  // Set a child object. Returns the object as the parent type. This tests input
  // of a client-side child object type and return as the parent type.
  ///
  struct _cef_translator_test_scoped_client_t*(
      CEF_CALLBACK* set_child_own_ptr_client_and_return_parent)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_scoped_client_child_t* val);

  // LIBRARY-SIDE RAWPTR VALUES

  ///
  // Set an object. Returns the value from
  // cef_translator_test_scoped_library_t::get_value(). This tests input and
  // execution of a library-side object type.
  ///
  int(CEF_CALLBACK* set_raw_ptr_library)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_scoped_library_t* val);

  ///
  // Set a child object. Returns the value from
  // cef_translator_test_scoped_library_t::get_value(). This tests input of a
  // library- side child object type and execution as the parent type.
  ///
  int(CEF_CALLBACK* set_child_raw_ptr_library)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_scoped_library_child_t* val);

  ///
  // Set an object list vlaue.
  ///
  int(CEF_CALLBACK* set_raw_ptr_library_list)(
      struct _cef_translator_test_t* self,
      size_t valCount,
      struct _cef_translator_test_scoped_library_t* const* val,
      int val1,
      int val2);

  // CLIENT-SIDE RAWPTR VALUES

  ///
  // Set an object. Returns the value from
  // cef_translator_test_scoped_client_t::get_value(). This tests input and
  // execution of a client-side object type.
  ///
  int(CEF_CALLBACK* set_raw_ptr_client)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_scoped_client_t* val);

  ///
  // Set a child object. Returns the value from
  // cef_translator_test_scoped_client_t::get_value(). This tests input of a
  // client- side child object type and execution as the parent type.
  ///
  int(CEF_CALLBACK* set_child_raw_ptr_client)(
      struct _cef_translator_test_t* self,
      struct _cef_translator_test_scoped_client_child_t* val);

  ///
  // Set an object list vlaue.
  ///
  int(CEF_CALLBACK* set_raw_ptr_client_list)(
      struct _cef_translator_test_t* self,
      size_t valCount,
      struct _cef_translator_test_scoped_client_t* const* val,
      int val1,
      int val2);
} cef_translator_test_t;

///
// Create the test object.
///
CEF_EXPORT cef_translator_test_t* cef_translator_test_create(void);

///
// Library-side test object for RefPtr.
///
typedef struct _cef_translator_test_ref_ptr_library_t {
  ///
  // Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  // Return a value.
  ///
  int(CEF_CALLBACK* get_value)(
      struct _cef_translator_test_ref_ptr_library_t* self);

  ///
  // Set a value.
  ///
  void(CEF_CALLBACK* set_value)(
      struct _cef_translator_test_ref_ptr_library_t* self,
      int value);
} cef_translator_test_ref_ptr_library_t;

///
// Create the test object.
///
CEF_EXPORT cef_translator_test_ref_ptr_library_t*
cef_translator_test_ref_ptr_library_create(int value);

///
// Library-side child test object for RefPtr.
///
typedef struct _cef_translator_test_ref_ptr_library_child_t {
  ///
  // Base structure.
  ///
  cef_translator_test_ref_ptr_library_t base;

  ///
  // Return a value.
  ///
  int(CEF_CALLBACK* get_other_value)(
      struct _cef_translator_test_ref_ptr_library_child_t* self);

  ///
  // Set a value.
  ///
  void(CEF_CALLBACK* set_other_value)(
      struct _cef_translator_test_ref_ptr_library_child_t* self,
      int value);
} cef_translator_test_ref_ptr_library_child_t;

///
// Create the test object.
///
CEF_EXPORT cef_translator_test_ref_ptr_library_child_t*
cef_translator_test_ref_ptr_library_child_create(int value, int other_value);

///
// Another library-side child test object for RefPtr.
///
typedef struct _cef_translator_test_ref_ptr_library_child_child_t {
  ///
  // Base structure.
  ///
  cef_translator_test_ref_ptr_library_child_t base;

  ///
  // Return a value.
  ///
  int(CEF_CALLBACK* get_other_other_value)(
      struct _cef_translator_test_ref_ptr_library_child_child_t* self);

  ///
  // Set a value.
  ///
  void(CEF_CALLBACK* set_other_other_value)(
      struct _cef_translator_test_ref_ptr_library_child_child_t* self,
      int value);
} cef_translator_test_ref_ptr_library_child_child_t;

///
// Create the test object.
///
CEF_EXPORT cef_translator_test_ref_ptr_library_child_child_t*
cef_translator_test_ref_ptr_library_child_child_create(int value,
                                                       int other_value,
                                                       int other_other_value);

///
// Client-side test object for RefPtr.
///
typedef struct _cef_translator_test_ref_ptr_client_t {
  ///
  // Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  // Return a value.
  ///
  int(CEF_CALLBACK* get_value)(
      struct _cef_translator_test_ref_ptr_client_t* self);
} cef_translator_test_ref_ptr_client_t;

///
// Client-side child test object for RefPtr.
///
typedef struct _cef_translator_test_ref_ptr_client_child_t {
  ///
  // Base structure.
  ///
  cef_translator_test_ref_ptr_client_t base;

  ///
  // Return a value.
  ///
  int(CEF_CALLBACK* get_other_value)(
      struct _cef_translator_test_ref_ptr_client_child_t* self);
} cef_translator_test_ref_ptr_client_child_t;

///
// Library-side test object for OwnPtr/RawPtr.
///
typedef struct _cef_translator_test_scoped_library_t {
  ///
  // Base structure.
  ///
  cef_base_scoped_t base;

  ///
  // Return a value.
  ///
  int(CEF_CALLBACK* get_value)(
      struct _cef_translator_test_scoped_library_t* self);

  ///
  // Set a value.
  ///
  void(CEF_CALLBACK* set_value)(
      struct _cef_translator_test_scoped_library_t* self,
      int value);
} cef_translator_test_scoped_library_t;

///
// Create the test object.
///
CEF_EXPORT cef_translator_test_scoped_library_t*
cef_translator_test_scoped_library_create(int value);

///
// Library-side child test object for OwnPtr/RawPtr.
///
typedef struct _cef_translator_test_scoped_library_child_t {
  ///
  // Base structure.
  ///
  cef_translator_test_scoped_library_t base;

  ///
  // Return a value.
  ///
  int(CEF_CALLBACK* get_other_value)(
      struct _cef_translator_test_scoped_library_child_t* self);

  ///
  // Set a value.
  ///
  void(CEF_CALLBACK* set_other_value)(
      struct _cef_translator_test_scoped_library_child_t* self,
      int value);
} cef_translator_test_scoped_library_child_t;

///
// Create the test object.
///
CEF_EXPORT cef_translator_test_scoped_library_child_t*
cef_translator_test_scoped_library_child_create(int value, int other_value);

///
// Another library-side child test object for OwnPtr/RawPtr.
///
typedef struct _cef_translator_test_scoped_library_child_child_t {
  ///
  // Base structure.
  ///
  cef_translator_test_scoped_library_child_t base;

  ///
  // Return a value.
  ///
  int(CEF_CALLBACK* get_other_other_value)(
      struct _cef_translator_test_scoped_library_child_child_t* self);

  ///
  // Set a value.
  ///
  void(CEF_CALLBACK* set_other_other_value)(
      struct _cef_translator_test_scoped_library_child_child_t* self,
      int value);
} cef_translator_test_scoped_library_child_child_t;

///
// Create the test object.
///
CEF_EXPORT cef_translator_test_scoped_library_child_child_t*
cef_translator_test_scoped_library_child_child_create(int value,
                                                      int other_value,
                                                      int other_other_value);

///
// Client-side test object for OwnPtr/RawPtr.
///
typedef struct _cef_translator_test_scoped_client_t {
  ///
  // Base structure.
  ///
  cef_base_scoped_t base;

  ///
  // Return a value.
  ///
  int(CEF_CALLBACK* get_value)(
      struct _cef_translator_test_scoped_client_t* self);
} cef_translator_test_scoped_client_t;

///
// Client-side child test object for OwnPtr/RawPtr.
///
typedef struct _cef_translator_test_scoped_client_child_t {
  ///
  // Base structure.
  ///
  cef_translator_test_scoped_client_t base;

  ///
  // Return a value.
  ///
  int(CEF_CALLBACK* get_other_value)(
      struct _cef_translator_test_scoped_client_child_t* self);
} cef_translator_test_scoped_client_child_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_TEST_CEF_TRANSLATOR_TEST_CAPI_H_
