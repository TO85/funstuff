#pragma once

#include <QtCore/qglobal.h>

#if defined(FSGUI_LIBRARY)
#  define FSGUI_EXPORT Q_DECL_EXPORT
#else
#  define FSGUI_EXPORT Q_DECL_IMPORT
#endif
