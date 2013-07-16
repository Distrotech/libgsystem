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

gboolean gs_file_enumerator_iterate (GFileEnumerator  *direnum,
                                     GFileInfo       **out_info,
                                     GFile           **out_child,
                                     GCancellable     *cancellable,
                                     GError          **error);

GInputStream *gs_file_read_noatime (GFile         *file,
                                    GCancellable  *cancellable,
                                    GError       **error);
GMappedFile *gs_file_map_noatime (GFile         *file,
                                  GCancellable  *cancellable,
                                  GError       **error);

#if GLIB_CHECK_VERSION(2,34,0)
GBytes *gs_file_map_readonly (GFile         *file,
                              GCancellable  *cancellable,
                              GError       **error);
#endif

gboolean gs_file_sync_data (GFile          *file,
                            GCancellable   *cancellable,
                            GError        **error);

gboolean gs_file_create (GFile          *file,
                         int             mode,
                         GOutputStream **out_stream,
                         GCancellable   *cancellable,
                         GError        **error);

gboolean gs_file_linkcopy (GFile          *src,
                           GFile          *dest,
                           GFileCopyFlags  flags,
                           GCancellable   *cancellable,
                           GError        **error);

gboolean gs_file_linkcopy_sync_data (GFile          *src,
                                     GFile          *dest,
                                     GFileCopyFlags  flags,
                                     GCancellable   *cancellable,
                                     GError        **error);

gboolean gs_file_rename (GFile          *from,
                         GFile          *to,
                         GCancellable   *cancellable,
                         GError        **error);

gboolean gs_file_unlink (GFile          *path,
                         GCancellable   *cancellable,
                         GError        **error);

gboolean gs_file_chown (GFile          *path,
                        guint32         owner,
                        guint32         group,
                        GCancellable   *cancellable,
                        GError        **error);

gboolean gs_file_chmod (GFile          *path,
                        guint           mode,
                        GCancellable   *cancellable,
                        GError        **error);

gboolean gs_file_ensure_directory (GFile          *dir,
                                   gboolean        with_parents,
                                   GCancellable   *cancellable,
                                   GError        **error);

gboolean gs_file_ensure_directory_mode (GFile          *dir,
                                        guint           mode,
                                        GCancellable   *cancellable,
                                        GError        **error);

gchar *gs_file_load_contents_utf8 (GFile         *file,
                                   GCancellable  *cancellable,
                                   GError       **error);

gchar *gs_file_get_relpath (GFile *one,
                            GFile *two);

GFile * gs_file_realpath (GFile *file);

G_END_DECLS

#endif
