#include <gtk/gtk.h>
#include <glib/gstdio.h>

int randomNumberLessThan(int n);
void initialising(GtkButton *buttonInit,int i,int j);
int hasAnyoneWon(int a[3][3]);
void setAllButtonsToBlank();
void computerMove();

static GtkButton *move_and_win;

//checkEmpty is to store whether the button has been clicked or not
//playerPosition is to store player 1 & player 2 position

static GtkButton *button[3][3]={{NULL,NULL,NULL},{NULL,NULL,NULL},{NULL,NULL,NULL}};
static int flag=0, gameNotOver=1, initialise=0, statusFlag=0, checkEmpty[3][3]={{0,0,0},{0,0,0},{0,0,0}};
static int countMovement=0;
static int playerPosition[3][3]={{0,0,0},{0,0,0},{0,0,0}};

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

print_11 (GtkWidget *button11)
{

    // runs if in initialising mode
  if(initialise!=0)
  {
      initialising(button11,0,0);
      return 0;
  }

  if(checkEmpty[0][0]) return 0; // checks if position has been clicked
  if(gameNotOver)
  {
    // runs when the button is clicked during an odd move
    if(++countMovement%2)
    {
      playerPosition[0][0]=1;
      gtk_button_set_label(button11, "X");
      checkEmpty[0][0]=1;
      switch(hasAnyoneWon(playerPosition))
      {
        case 0: if(countMovement==9)
                {
                  printf("DRAW");
                  
                  gameNotOver=0; return 0;
                } break;
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\nIt's Player 2's turn");
      
    }
    // runs when the button is clicked during an even move
    else
    {
      playerPosition[0][0]=2;
      gtk_button_set_label(button11, "O");
      switch(hasAnyoneWon(playerPosition))
      {
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\nIt's Player 1's turn");
    }
    checkEmpty[0][0]=1;
  }
  return 0;

}

print_12 (GtkWidget *button12)
{

     // runs if in initialising mode
  if(initialise!=0)
  {
      initialising(button12,0,1);
      return 0;
  }

  if(checkEmpty[0][1]) return 0;
  if(gameNotOver)
  {
    // runs when the button is clicked during an odd move
    if(++countMovement%2)
    {
      playerPosition[0][1]=1;
      gtk_button_set_label(button12, "X");
      checkEmpty[0][1]=1;
      switch(hasAnyoneWon(playerPosition))
      {
        case 0: if(countMovement==9)
                {
                  printf("\nDRAW");
                  
                  gameNotOver=0; return 0;
                } break;
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\nIt's Player 2's turn");
      
    }
    // runs when the button is clicked during an even move
    else
    {
      playerPosition[0][1]=2;
      gtk_button_set_label(button12, "O");
      switch(hasAnyoneWon(playerPosition))
      {
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\nIt's Player 1's turn");
    }
    checkEmpty[0][1]=1;
  }
  return 0;

}

print_13 (GtkWidget *button13)
{
     // runs if in initialising mode
  if(initialise!=0)
  {
      initialising(button13,0,2);
      return 0;
  }

  if(checkEmpty[0][2]) return 0;
  if(gameNotOver)
  {
    // runs when the button is clicked during an odd move
    if(++countMovement%2)
    {
      playerPosition[0][2]=1;
      gtk_button_set_label(button13, "X");
      checkEmpty[0][2]=1;
      switch(hasAnyoneWon(playerPosition))
      {
        case 0: if(countMovement==9)
                {
                  printf("\nDRAW");
                  
                  gameNotOver=0; return 0;
                } break;
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\nIt's Player 2's turn");
      
    }
    // runs when the button is clicked during an even move
    else
    {
      playerPosition[0][2]=2;
      gtk_button_set_label(button13, "O");
      switch(hasAnyoneWon(playerPosition))
      {
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\nIt's Player 1's turn");
    }
    checkEmpty[0][2]=1;
  }
  return 0;

}

print_21 (GtkWidget *button21)
{
     // runs if in initialising mode
  if(initialise!=0)
  {
      initialising(button21,1,0);
      return 0;
  }

  if(checkEmpty[1][0]) return 0;
  if(gameNotOver)
  {
    // runs when the button is clicked during an odd move
    if(++countMovement%2)
    {
      playerPosition[1][0]=1;
      gtk_button_set_label(button21, "X");
      checkEmpty[1][0]=1;
      switch(hasAnyoneWon(playerPosition))
      {
        case 0: if(countMovement==9)
                {
                  printf("\nDRAW");
                  
                  gameNotOver=0; return 0;
                } break;
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\nIt's Player 2's turn");
      
    }
    // runs when the button is clicked during an even move
    else
    {
      playerPosition[1][0]=2;
      gtk_button_set_label(button21, "O");
      switch(hasAnyoneWon(playerPosition))
      {
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\nIt's Player 1's turn");
    }
    checkEmpty[1][0]=1;
  }
  return 0;

}

print_22 (GtkWidget *button22)
{
    //  runs if in initialising mode
  if(initialise!=0)
  {
      initialising(button22,1,1);
      return 0;
  }

  if(checkEmpty[1][1]) return 0;
  if(gameNotOver)
  {
    // runs when the button is clicked during an odd move
    if(++countMovement%2)
    {
      playerPosition[1][1]=1;
      gtk_button_set_label(button22, "X");
      checkEmpty[1][1]=1;
      switch(hasAnyoneWon(playerPosition))
      {
        case 0: if(countMovement==9)
                {
                  printf("\nDRAW");
                  
                  gameNotOver=0; return 0;
                } break;
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\nIt's Player 2's turn");
      
    }
    // runs when the button is clicked during an even move
    else
    {
      playerPosition[1][1]=2;
      gtk_button_set_label(button22, "O");
      switch(hasAnyoneWon(playerPosition))
      {
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\n\nIt's Player 1's turn");
    }
    checkEmpty[1][1]=1;
  }
  return 0;

}

print_23 (GtkWidget *button23)
{
     // runs if in initialising mode
  if(initialise!=0)
  {
      initialising(button23,1,2);
      return 0;
  }

  if(checkEmpty[1][2]) return 0;
  if(gameNotOver)
  {
    // runs when the button is clicked during an odd move
    if(++countMovement%2)
    {
      playerPosition[1][2]=1;
      gtk_button_set_label(button23, "X");
      checkEmpty[1][2]=1;
      switch(hasAnyoneWon(playerPosition))
      {
        case 0: if(countMovement==9)
                {
                  printf("\nDRAW");
                  
                  gameNotOver=0; return 0;
                } break;
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\nIt's Player 2's turn");
      
    }
    // runs when the button is clicked during an even move
    else
    {
      playerPosition[1][2]=2;
      gtk_button_set_label(button23, "O");
      switch(hasAnyoneWon(playerPosition))
      {
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\nIt's Player 1's turn");
    }
    checkEmpty[1][2]=1;
  }
  return 0;
}

print_31 (GtkWidget *button31)
{
   // runs if in initialising mode
  if(initialise!=0)
  {
      initialising(button31,2,0);
      return 0;
  }

  if(checkEmpty[2][0]) return 0;
  if(gameNotOver)
  {
    // runs when the button is clicked during an odd move
    if(++countMovement%2)
    {
      playerPosition[2][0]=1;
      gtk_button_set_label(button31, "X");
      checkEmpty[2][0]=1;
      switch(hasAnyoneWon(playerPosition))
      {
        case 0: if(countMovement==9)
                {
                  printf("\nDRAW");
                  
                  gameNotOver=0; return 0;
                } break;
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\nIt's Player 2's turn");
      
    }
    // runs when the button is clicked during an even move
    else
    {
      playerPosition[2][0]=2;
      gtk_button_set_label(button31, "O");
      switch(hasAnyoneWon(playerPosition))
      {
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\nIt's Player 1's turn");
    }
    checkEmpty[2][0]=1;
  }
  return 0;

}

print_32 (GtkWidget *button32)
{

   // runs if in initialising mode
  if(initialise!=0)
  {
      initialising(button32,2,1);
      return 0;
  }

  if(checkEmpty[2][1]) return 0;
  if(gameNotOver)
  {
    // runs when the button is clicked during an odd move
    if(++countMovement%2)
    {
      playerPosition[2][1]=1;
      gtk_button_set_label(button32, "X");
      checkEmpty[2][1]=1;
      switch(hasAnyoneWon(playerPosition))
      {
        case 0: if(countMovement==9)
                {
                  printf("\nDRAW");
                  
                  gameNotOver=0; return 0;
                } break;
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\nIt's Player 2's turn");
      
    }
    // runs when the button is clicked during an even move
    else
    {
      playerPosition[2][1]=2;
      gtk_button_set_label(button32, "O");
      switch(hasAnyoneWon(playerPosition))
      {
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\nIt's Player 1's turn");
    }
    checkEmpty[2][1]=1;
  }
  return 0;
}

print_33 (GtkWidget *button33)
{
     // runs if in initialising mode
  if(initialise!=0)
  {
      initialising(button33,2,2);
      return 0;
  }

  if(checkEmpty[2][2]) return 0;
  if(gameNotOver)
  {
    // runs when the button is clicked during an odd move
    if(++countMovement%2)
    {
      playerPosition[2][2]=1;
      gtk_button_set_label(button33, "X");
      checkEmpty[2][2]=1;
      switch(hasAnyoneWon(playerPosition))
      {
        case 0: if(countMovement==9)
                {
                  printf("\nDRAW");
                  
                  gameNotOver=0; return 0;
                } break;
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\nIt's Player 2's turn");
      
    }
    // runs when the button is clicked during an even move
    else
    {
      playerPosition[2][2]=2;
      gtk_button_set_label(button33, "O");
      switch(hasAnyoneWon(playerPosition))
      {
        case 1: printf("\nPlayer 1 has won!");
                gameNotOver=0; return 0;
        case 2: printf("\nPlayer 2 has won!");
                gameNotOver=0; return 0;
      }
      printf("\nIt's Player 1's turn");
    }
    checkEmpty[2][2]=1;
  }
  return 0;

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

  // button = gtk_builder_get_object (builder, "move_and_win");
  // g_signal_connect_swapped (button, "clicked", G_CALLBACK (print_status), window);

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

// function for checking if whether any row, column or diagonal is completely filled by either 0, 1 or 2 and returns either 0, 1 or 2
int hasAnyoneWon(int a[3][3])
{
  int oneWon=0; int twoWon=0; int i,j;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      if(a[i][j]==1) oneWon++;
      if(a[i][j]==2) twoWon++;
    }
    if(oneWon==3) return 1;
    if(twoWon==3) return 2;
    oneWon=0; twoWon=0;
  }

  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      if(a[j][i]==1) oneWon++;
      if(a[j][i]==2) twoWon++;
    }
    if(oneWon==3) return 1;
    if(twoWon==3) return 2;
    oneWon=0; twoWon=0;
  }

  for(i=0;i<3;i++)
  {
    if(a[i][i]==1) oneWon++;
    if(a[i][i]==2) twoWon++;
  }
  if(oneWon==3) return 1;
  if(twoWon==3) return 2;
  oneWon=0; twoWon=0;

  for(i=0,j=2;i<3;i++,j--)
  {
    if(a[i][j]==1) oneWon++;
    if(a[i][j]==2) twoWon++;
  }
  if(oneWon==3) return 1;
  if(twoWon==3) return 2;
  return 0;
}

void initialising(GtkButton *buttonInit,int i,int j)
{
    if(button[i][j]!=NULL) return;
    button[i][j]=buttonInit;
    gtk_button_set_label(button[i][j], "OK");
    if(++initialise==10)
    {
      initialise=0;
      printf("It's Player 1's turn");
      setAllButtonsToBlank();
    }
}

void setAllButtonsToBlank()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            gtk_button_set_label(button[i][j], " ");
        }
    }
}
