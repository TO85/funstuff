#pragma once

#include <QtCore/qglobal.h>

#if defined(FSCORE_LIBRARY)
#  define FSCORE_EXPORT Q_DECL_EXPORT
#else
#  define FSCORE_EXPORT Q_DECL_IMPORT
#endif
