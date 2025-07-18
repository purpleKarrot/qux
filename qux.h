// Copyright 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
// This work is free. You can redistribute it and/or modify it under the
// terms of the Do What The Fuck You Want To Public License, Version 2,
// as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.

#pragma once

#if defined(__ELF__) || defined(__MACH__) || defined(__WASM__)
#  define QUX_IMPORT __attribute__((visibility("default")))
#  define QUX_EXPORT __attribute__((visibility("default")))
#else  // assume PE/COFF
#  define QUX_IMPORT __declspec(dllimport)
#  define QUX_EXPORT __declspec(dllexport)
#endif

#if defined(qux_STATIC)
#  define QUX_API
#elif  defined(qux_EXPORTS)
#  define QUX_API QUX_EXPORT
#else
#  define QUX_API QUX_IMPORT
#endif

QUX_API char* qux(char const* x, char const* y);
QUX_API void qux_free(char* str);
