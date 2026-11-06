// SPDX-FileCopyrightText: Copyright 2026 Eden Emulator Project
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QString>

namespace QtCommon::Mod {

QStringList GetModFolders(const QString& root, const QString& fallbackName);

// Extracts into its own temp subfolder so several archives can be pending at once.
const QString ExtractMod(const QString& path, int slot = 0);

} // namespace QtCommon::Mod
