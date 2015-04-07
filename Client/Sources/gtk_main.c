/*
** gtk_main.c for Gtk_Main_C_ in /home/boulat_m/rendu/Projets_sem2/myIRC/GIT/myIRC/Client
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Mon Apr  6 19:03:05 2015 Mickael BOULAT
** Last update Tue Apr  7 16:18:32 2015 Mickael BOULAT
*/

# include "client.h"

typedef struct	s_display
{
  GtkBuilder	*_builder;
  GObject	*_window;
  GObject	*_button;
}		t_display;

void	init_window(t_display *d)
{
  
  d->_builder = gtk_builder_new();
  gtk_builder_add_from_file (d->_builder, "builder3.ui", NULL);

  d->_window = gtk_builder_get_object(d->_builder, "window"); 
  d->_button = gtk_builder_get_object(d->_builder, "button"); 
  g_signal_connect(d->_button, "clicked", G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect(d->_window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
  
}

int	display(int *argc, char ***argv)
{
  t_display	d;

  gtk_init(argc, argv);
  init_window(&d);
  //gtk_widget_show_all(d._window);
  gtk_main();
 return (EXIT_SUCCESS);
}
