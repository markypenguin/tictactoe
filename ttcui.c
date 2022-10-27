#include <gtk/gtk.h>
#include <glib/gstdio.h>

static void
print_start (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Start\n");
}

print_reset (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Reset\n");
}

print_single (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Single\n");
}

print_multi (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Multi\n");
}

static void
print_11 (GtkWidget *button11)
{
  printf("button 11 click click");
  gtk_button_set_label(button11, "X");
  g_print ("Button 11 pressed \n");
}

static void
quit_cb (GtkWindow *window)
{
  gtk_window_close (window);
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  /* Construct a GtkBuilder instance and load our UI description */
  GtkBuilder *builder = gtk_builder_new ();
  gtk_builder_add_from_file (builder, "C:\\Users\\NINO\\Desktop\\School\\test\\build\\testvers7.ui", NULL);

  /* Connect signal handlers to the constructed widgets. */
  GObject *window = gtk_builder_get_object (builder, "window");
  gtk_window_set_application (GTK_WINDOW (window), app);

  GObject *button = gtk_builder_get_object (builder, "startButton");
  g_signal_connect (button, "clicked", G_CALLBACK (print_start), NULL);

  button = gtk_builder_get_object (builder, "resetButton");
  g_signal_connect (button, "clicked", G_CALLBACK (print_reset), NULL);

  button = gtk_builder_get_object (builder, "singleButton");
  g_signal_connect (button, "clicked", G_CALLBACK (print_single), NULL);

  button = gtk_builder_get_object (builder, "multiButton");
  g_signal_connect (button, "clicked", G_CALLBACK (print_multi), NULL);

  button = gtk_builder_get_object (builder, "button11");
  g_signal_connect (button, "clicked", G_CALLBACK (print_11), NULL);

  button = gtk_builder_get_object (builder, "exitButton");
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (quit_cb), window);

  gtk_widget_show (GTK_WIDGET (window));

  /* We do not need the builder any more */
  g_object_unref (builder);
}

int main (int   argc,
      char *argv[])
{
#ifdef GTK_SRCDIR
  g_chdir (GTK_SRCDIR);
#endif

  GtkApplication *app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

  int status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
