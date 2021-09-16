#pragma once

#include <QtCore/qglobal.h>

#if defined(FSUTIL_LIBRARY)
#  define FSUTIL_EXPORT Q_DECL_EXPORT
#else
#  define FSUTIL_EXPORT Q_DECL_IMPORT
#endif
