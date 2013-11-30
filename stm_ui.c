/*
 * STM-GTK - Stereomood Gtk
 * Copyright (C) 2013 Darcy Brás da Silva
 *
 * stm_ui.c is part of STM-GTK.
 *
 * STM-GTK is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * STM-GTK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with STM-GTK.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "stm_ui.h"


static GtkWidget *main_window;
static GtkWidget *txt_entry_search;
static GtkWidget *btn_search;
static GtkWidget *btn_download;
static GtkWidget *btn_toggle_play;

static GtkWidget *main_grid;
static GtkWidget *top_grid;
static GtkWidgte *middle_grid;
static GtkWidget *bottom_grid;

static GtkWidget *playlist_treeview;
static GtkListStore treeview_store;
static GtkCellRenderer *cell;
static GtkTreeViewColumn *column;

static GtkWidget *list;
static GtkListStore *store;

/* creates all widgets with base definitions*/
static int stm_ui_init()
{
	return 1;
}
