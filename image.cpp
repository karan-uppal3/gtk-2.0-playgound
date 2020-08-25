#include <gtk/gtk.h>

int main ( int argc , char* argv[] )
{
    gtk_init (&argc , &argv );    // initialising the gtk

    GtkWidget *window , *image;  //declare the needed variables
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);    //create the window

    g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit), NULL);  //if X is clicked then exit from the program

    image = gtk_image_new_from_file("/home/karan/Downloads/IMG-20200517-WA0002.jpg");

    gtk_container_add(GTK_CONTAINER(window),image);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
