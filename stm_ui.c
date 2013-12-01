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
#include <gtk/gtk.h>

static GtkWidget *main_window;
static GtkWidget *txt_entry_search;
static GtkWidget *btn_search;
static GtkWidget *btn_download;
static GtkWidget *btn_toggle_play;

static GtkWidget *main_grid;
static GtkWidget *top_grid;
static GtkWidget *middle_grid;
static GtkWidget *bottom_grid;

static GtkWidget *playlist_treeview;
static GtkWidget *playlist_list;


/* creates all base widgets */
static int stm_ui_init()
{
	main_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

	/* create the grids that hold the control widgets */
	main_grid   = gtk_grid_new();
	top_grid    = gtk_grid_new();
	middle_grid = gtk_grid_new();
	bottom_grid = gtk_grid_new();
	
	txt_entry_search = gtk_entry_new();
	btn_search       = gtk_button_new();
	btn_download     = gtk_button_new();
	btn_toggle_play  = gtk_button_new();

	/* necessary evil. lets check if everything was created */
	if(!main_window) return -1;

	if(!main_grid)   return -2;
	if(!top_grid)    return -3;
	if(!middle_grid) return -4;
	if(!bottom_grid) return -5;

	if(!txt_entry_search) return -6;
	if(!btn_search)       return -7;
	if(!btn_download)     return -8;
	if(!btn_toggle_play)  return -9;

	return 1;

}/* end stm_ui_init() */

static void config_main_window(void)
{
	gtk_window_set_default_size( GTK_WINDOW( main_window ), 
				     STM_MW_WIDTH, STM_MW_HEIGHT );
	
	gtk_window_set_position( GTK_WINDOW( main_window ),
				 GTK_WIN_POS_CENTER );
	
	gtk_window_set_title( GTK_WINDOW( main_window ),
			      STM_MW_TITLE);
}/*end config_main_window */

static void config_layout_grids(void)
{
	gtk_widget_set_hexpand( GTK_WIDGET( top_grid ), TRUE );
	gtk_widget_set_vexpand( GTK_WIDGET( top_grid ), FALSE);
	
	gtk_widget_set_hexpand( GTK_WIDGET( middle_grid ), TRUE);
	gtk_widget_set_vexpand( GTK_WIDGET( middle_grid ), TRUE);
	
	gtk_widget_set_hexpand( GTK_WIDGET( bottom_grid ), FALSE);
	gtk_widget_set_vexpand( GTK_WIDGET( bottom_grid ), FALSE);
}/* end config_layout_grids */

static void config_txt_entry_search(void)
{
	gtk_widget_set_hexpand( GTK_WIDGET( txt_entry_search ), TRUE);
	gtk_widget_set_vexpand( GTK_WIDGET( txt_entry_search ), FALSE);
	
	gtk_widget_set_tooltip_markup( txt_entry_search,
				       STM_TXT_ENTRY_SEARCH_TOOLTIP_STR);
}/*end config_txt_entry_search */

static void config_btn_search(void)
{
	gtk_button_set_label( GTK_BUTTON( btn_search ), STM_BTN_SEARCH_STR);
	
	gtk_widget_set_hexpand( GTK_WIDGET( btn_search ), TRUE);
	gtk_widget_set_vexpand( GTK_WIDGET( btn_search ), FALSE);
	
	/* any default signal handler should be defined here */
	/*###################################################*/
}/*end config_btn_search */

static void config_playlist_treeview(void)
{
	gtk_widget_set_hexpand( GTK_WIDGET( playlist_treeview ), TRUE);
	gtk_widget_set_vexpand( GTK_WIDGET( playlist_treeview ), TRUE);

	/* any default signal handler should be defined here */
	/*###################################################*/	
}/*end config_playlist_treeview */

static void config_btn_download(void)
{
	gtk_button_set_label( GTK_BUTTON( btn_download), STM_BTN_DOWNLOAD_STR);
	
	gtk_widget_set_hexpand( GTK_WIDGET( btn_download ), TRUE);
	gtk_widget_set_vexpand( GTK_WIDGET( btn_download ), FALSE);
	
	/* any default signal handler should be defined here */
	/*###################################################*/
}/*end config_btn_download */

static void config_btn_toggle_play(void)
{
	gtk_button_set_label( GTK_BUTTON( btn_toggle_play), 
			      STM_BTN_TOGGLE_PLAY_STR_0);
	
	gtk_widget_set_hexpand( GTK_WIDGET( btn_toggle_play ), TRUE);
	gtk_widget_set_vexpand( GTK_WIDGET( btn_toggle_play ), FALSE);
	
	
	/* since this feature will only be available in future versions 
	 * don't let the user interact with the button.
	 */
	gtk_widget_set_sensitive( GTK_WIDGET( btn_toggle_play ), FALSE);
	
	/* in any case, let the user know the feature is not implemented */
	gtk_widget_set_tooltip_markup( GTK_WIDGET( btn_toggle_play ),
				       STM_NOTIMPLEMENTED_TOOLTIP_STR);
	/* any default signal handler should be defined here */
	/*###################################################*/
}/*end config_btn_toggle_play */

static void assemble_ui(void)
{
	/* add the main grid to the root window */
	gtk_container_add( GTK_CONTAINER( main_window ),
			   GTK_WIDGET( main_grid ));
	
	/* add the sub-grids into the main_grid 
	 * prototype: 
	 * gtk_grid_attach ( GTK_GRID( the_grid ),
	 *                   GTK_WIDGET( the_widget),
	 *                   0,  //left
	 *                   0,  //top
	 *                   1,  //width
	 *                   1); //height
	 */
	
	gtk_grid_attach( GTK_GRID( main_grid ), 
			 GTK_WIDGET( top_grid ), 0, 0, 1, 1);
	
	gtk_grid_attach( GTK_GRID( main_grid ), 
			 GTK_WIDGET( middle_grid ), 0, 1, 1, 1);
	
	gtk_grid_attach( GTK_GRID( main_grid ), 
			 GTK_WIDGET( bottom_grid ), 0, 2, 1, 1);
	
	/* add control widgets to the respective positions */
	
	/* top_grid control widgets */
	gtk_grid_attach( GTK_GRID( top_grid ),
			 GTK_WIDGET( txt_entry_search ), 0, 0, 1, 1);
	
	gtk_grid_attach( GTK_GRID( top_grid ), 
			 GTK_WIDGET( btn_search ), 1, 0, 1, 1);
	
	/* middle_grid  control widgets */
	gtk_grid_attach( GTK_GRID( middle_grid ), 
			 GTK_WIDGET( playlist_treeview ), 0, 0, 1, 1);
	
	/* bottom_grid control widgets */
	gtk_grid_attach( GTK_GRID( bottom_grid ), 
			 GTK_WIDGET( btn_download ), 0, 0, 1, 1);
	
	gtk_grid_attach( GTK_GRID( bottom_grid ),
			 GTK_WIDGET( btn_toggle_play ), 1, 0, 1, 1);

}/*end assemble_ui */ 


/*debuging purposes*/
int fakemain(int argc, char **argv)
{
	gtk_init(&argc, &argv);
	
	stm_ui_init();

	config_main_window();
	config_layout_grids();

	config_txt_entry_search();
	config_btn_search();
	
	config_playlist_treeview();
	
	config_btn_download();
	config_btn_toggle_play();
	
	assemble_ui();
	
	gtk_widget_show_all(main_window);

	gtk_main();
	return 0;
}
