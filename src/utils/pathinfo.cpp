// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2017-2019 Alejandro Sirgo Rica & Contributors

#include "pathinfo.h"

#include <QApplication>
#include <QDir>
#include <QFileInfo>

const QString PathInfo::whiteIconPath()
{
    return QStringLiteral(":/img/material/white/");
}

const QString PathInfo::blackIconPath()
{
    return QStringLiteral(":/img/material/black/");
}

QStringList PathInfo::translationsPaths()
{
    QString binaryPath =
      QFileInfo(qApp->applicationDirPath()).absoluteFilePath();
    QString trPath = QDir::toNativeSeparators(binaryPath + "/translations");
#if defined(Q_OS_UNIX)
    // Relocatable installs (e.g. AppImage) keep the binary in <prefix>/bin and
    // the translations in <prefix>/share/flameshot/translations.
    QString relocatableTrPath = QDir::toNativeSeparators(
      QDir::cleanPath(binaryPath + "/../share/flameshot/translations"));
    return QStringList()
           << QStringLiteral(APP_PREFIX) + "/share/flameshot/translations"
           << relocatableTrPath << trPath
           << QStringLiteral("/usr/share/flameshot/translations")
           << QStringLiteral("/usr/local/share/flameshot/translations");
#endif
    return QStringList() << trPath;
}
