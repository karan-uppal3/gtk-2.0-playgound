#include <gtk/gtk.h>

static void open_dialog ( GtkWidget *widget , gpointer data )
{
    GtkWidget *dialog , *label;

    dialog = gtk_dialog_new_with_buttons("Dialog",GTK_WINDOW(data),GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL , GTK_RESPONSE_CANCEL, NULL);

    label = gtk_label_new("You clicked this button");
    
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->vbox),label,0,0,0);

    gtk_widget_show_all(dialog);

    gint response = gtk_dialog_run(GTK_DIALOG(dialog));

    if ( response == GTK_RESPONSE_OK )
        gtk_main_quit();
    else
        g_print("The cancel is pressed");

    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[])
{
    gtk_init(&argc,&argv);
    
    GtkWidget *window , *button;
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
 
    button = gtk_button_new_with_label("Click me");

    g_signal_connect(button,"clicked",G_CALLBACK(open_dialog),window);

    gtk_container_set_border_width(GTK_CONTAINER(window),100);
    gtk_container_add(GTK_CONTAINER(window),button);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}