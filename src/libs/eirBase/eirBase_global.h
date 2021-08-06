#pragma once

#include <QtCore/qglobal.h>

#if defined(EIRBASE_LIBRARY)
#  define EIRBASE_EXPORT Q_DECL_EXPORT
#else
#  define EIRBASE_EXPORT Q_DECL_IMPORT
#endif
