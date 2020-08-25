#include <gtk/gtk.h>
#include <iostream>

static void button_clicked(GtkWidget* widget, gpointer data)
{
    g_print("lol\n");
}
int main(int argc,char*argv[])
{
    gtk_init(&argc,&argv);
    
    GtkWidget *window, *button;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    button = gtk_button_new_with_label("Click to exit");

    g_signal_connect (window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);

    g_signal_connect (button,"button_press_event",G_CALLBACK(gtk_main_quit),NULL);

    gtk_widget_set_size_request(window,300,300);

    gtk_window_set_title(GTK_WINDOW(window),"Hello world");

    gtk_container_add(GTK_CONTAINER(window),button);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}