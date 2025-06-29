// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "txt/platform.h"

#if defined(SK_FONTMGR_ANDROID_AVAILABLE)
#include "third_party/skia/include/ports/SkFontMgr_android.h"
#include "third_party/skia/include/ports/SkFontScanner_FreeType.h"
#endif

#if defined(SK_FONTMGR_FREETYPE_EMPTY_AVAILABLE)
#include "third_party/skia/include/ports/SkFontMgr_empty.h"
#endif

namespace txt {

std::vector<std::string> GetDefaultFontFamilies() {
  return {"sans-serif"};
}

sk_sp<SkFontMgr> GetDefaultFontManager(uint32_t font_initialization_data) {
#if defined(SK_FONTMGR_ANDROID_AVAILABLE)
  static sk_sp<SkFontMgr> mgr =
      SkFontMgr_New_Android(nullptr, SkFontScanner_Make_FreeType());
#elif defined(SK_FONTMGR_FREETYPE_EMPTY_AVAILABLE)
  static sk_sp<SkFontMgr> mgr = SkFontMgr_New_Custom_Empty();
#else
  static sk_sp<SkFontMgr> mgr = SkFontMgr::RefEmpty();
#endif
  return mgr;
}

}  // namespace txt
