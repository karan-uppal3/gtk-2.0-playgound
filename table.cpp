#include <gtk/gtk.h>

static void button_clicked (GtkWidget *widget,gpointer data)
{
    gtk_label_set_text(GTK_LABEL(data),"you clicked the button");
}

int main ( int argc , char* argv[] )
{
    gtk_init (&argc , &argv );    // initialising the gtk

    GtkWidget *window , *table , *label , *button;  //declare the needed variables
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);    //create the window

    g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit), NULL);  //if X is clicked then exit from the program

    table = gtk_table_new(2,2,0);

    button = gtk_button_new_with_mnemonic("_Button");

    label = gtk_label_new("Hello world");

    gtk_table_attach(GTK_TABLE(table),label,0,1,0,1,GTK_FILL,GTK_FILL,0,0);

    gtk_table_attach(GTK_TABLE(table),button,1,2,0,1,GTK_FILL,GTK_FILL,0,0);


    button = gtk_button_new_with_mnemonic("B_utton 2");

    label = gtk_label_new("Hello world 2");

    gtk_table_attach(GTK_TABLE(table),label,0,1,1,2,GTK_FILL,GTK_FILL,0,0);

    gtk_table_attach(GTK_TABLE(table),button,1,2,1,2,GTK_FILL,GTK_FILL,0,0);

    gtk_container_add(GTK_CONTAINER(window),table);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}