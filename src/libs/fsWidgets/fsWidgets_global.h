#pragma once

#include <QtCore/qglobal.h>

#if defined(FSWIDGETS_LIBRARY)
#  define FSWIDGETS_EXPORT Q_DECL_EXPORT
#else
#  define FSWIDGETS_EXPORT Q_DECL_IMPORT
#endif
