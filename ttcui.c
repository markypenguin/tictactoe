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

int turn = 1;

static void
print_11 (GtkWidget *button11)
{
  if(turn==1) {
    printf("button 11 click click");
    gtk_button_set_label(button11, "X");
    g_print ("Buttons 11 pressed \n");
    turn = 0;
  }
  else {
    printf("button 11 click click");
    gtk_button_set_label(button11, "O");
    g_print ("Button 11 pressed \n");
    turn = 1;
  }
}

print_12 (GtkWidget *button12)
{
  if(turn==1) {
    printf("button 12 click click");
    gtk_button_set_label(button12, "X");
    g_print ("Buttons 12 pressed \n");
    turn = 0;
  }
  else {
    printf("button 12 click click");
    gtk_button_set_label(button12, "O");
    g_print ("Button 12 pressed \n");
    turn = 1;
  }
}

print_13 (GtkWidget *button13)
{
  if(turn==1) {
    printf("button 13 click click");
    gtk_button_set_label(button13, "X");
    g_print ("Buttons 13 pressed \n");
    turn = 0;
  }
  else {
    printf("button 13 click click");
    gtk_button_set_label(button13, "O");
    g_print ("Button 13 pressed \n");
    turn = 1;
  }
}

print_21 (GtkWidget *button21)
{
  if(turn==1) {
    printf("button 21 click click");
    gtk_button_set_label(button21, "X");
    g_print ("Buttons 21 pressed \n");
    turn = 0;
  }
  else {
    printf("button 21 click click");
    gtk_button_set_label(button21, "O");
    g_print ("Button 21 pressed \n");
    turn = 1;
  }
}

print_22 (GtkWidget *button22)
{
  if(turn==1) {
    printf("button 22 click click");
    gtk_button_set_label(button22, "X");
    g_print ("Buttons 22 pressed \n");
    turn = 0;
  }
  else {
    printf("button 22 click click");
    gtk_button_set_label(button22, "O");
    g_print ("Button 22 pressed \n");
    turn = 1;
  }
}

print_23 (GtkWidget *button23)
{
  if(turn==1) {
    printf("button 23 click click");
    gtk_button_set_label(button23, "X");
    g_print ("Buttons 23 pressed \n");
    turn = 0;
  }
  else {
    printf("button 23 click click");
    gtk_button_set_label(button23, "O");
    g_print ("Button 23 pressed \n");
    turn = 1;
  }
}

print_31 (GtkWidget *button31)
{
  if(turn==1) {
    printf("button 31 click click");
    gtk_button_set_label(button31, "X");
    g_print ("Buttons 31 pressed \n");
    turn = 0;
  }
  else {
    printf("button 31 click click");
    gtk_button_set_label(button31, "O");
    g_print ("Button 31 pressed \n");
    turn = 1;
  }
}

print_32 (GtkWidget *button32)
{
  if(turn==1) {
    printf("button 32 click click");
    gtk_button_set_label(button32, "X");
    g_print ("Buttons 32 pressed \n");
    turn = 0;
  }
  else {
    printf("button 32 click click");
    gtk_button_set_label(button32, "O");
    g_print ("Button 32 pressed \n");
    turn = 1;
  }
}

print_33 (GtkWidget *button33)
{
  if(turn==1) {
    printf("button 33 click click");
    gtk_button_set_label(button33, "X");
    g_print ("Buttons 22 pressed \n");
    turn = 0;
  }
  else {
    printf("button 33 click click");
    gtk_button_set_label(button33, "O");
    g_print ("Button 33 pressed \n");
    turn = 1;
  }
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
  gtk_builder_add_from_file (builder, "C:\\CSC1103 - Programming Meth\\project_gtk\\tictactoe-main\\testMark.glade", NULL);

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

  //ADDED CODE HERE
  button = gtk_builder_get_object (builder, "button12");
  g_signal_connect (button, "clicked", G_CALLBACK (print_12), NULL);

  button = gtk_builder_get_object (builder, "button13");
  g_signal_connect (button, "clicked", G_CALLBACK (print_13), NULL);

  button = gtk_builder_get_object (builder, "button21");
  g_signal_connect (button, "clicked", G_CALLBACK (print_21), NULL);

  button = gtk_builder_get_object (builder, "button22");
  g_signal_connect (button, "clicked", G_CALLBACK (print_22), NULL);

  button = gtk_builder_get_object (builder, "button23");
  g_signal_connect (button, "clicked", G_CALLBACK (print_23), NULL);

  button = gtk_builder_get_object (builder, "button31");
  g_signal_connect (button, "clicked", G_CALLBACK (print_31), NULL);

  button = gtk_builder_get_object (builder, "button32");
  g_signal_connect (button, "clicked", G_CALLBACK (print_32), NULL);

  button = gtk_builder_get_object (builder, "button33");
  g_signal_connect (button, "clicked", G_CALLBACK (print_33), NULL);

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
