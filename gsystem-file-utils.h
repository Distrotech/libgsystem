/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*-
 *
 * Copyright (C) 2012 Colin Walters <walters@verbum.org>.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GSYSTEM_FILE_UTILS_H__
#define __GSYSTEM_FILE_UTILS_H__

#include <gio/gio.h>

G_BEGIN_DECLS

const char *gs_file_get_path_cached (GFile *file);

const char *gs_file_get_basename_cached (GFile *file);

GInputStream *gs_file_read_noatime (GFile         *path,
                                    GCancellable  *cancellable,
                                    GError       **error);
GMappedFile *gs_file_map_noatime (GFile         *path,
                                  GCancellable  *cancellable,
                                  GError       **error);

gboolean gs_file_rename (GFile          *src,
                         GFile          *dest,
                         GCancellable   *cancellable,
                         GError        **error);

gboolean gs_file_unlink (GFile          *path,
                         GCancellable   *cancellable,
                         GError        **error);

gboolean gs_file_ensure_directory (GFile          *dir,
                                   gboolean        with_parents,
                                   GCancellable   *cancellable,
                                   GError        **error);

gchar *gs_file_load_contents_utf8 (GFile         *file,
                                   GCancellable  *cancellable,
                                   GError       **error);


G_END_DECLS

#endif
