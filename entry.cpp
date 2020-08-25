#include <gtk/gtk.h>

static void button_clicked (GtkWidget *widget,gpointer data)
{
    g_print("%s\n",gtk_entry_get_text(GTK_ENTRY(data)));
    //gtk_entry_set_text(GTK_ENTRY(data),"Text printed");
    gtk_editable_select_region(GTK_EDITABLE(data),0,-1);
    gtk_editable_copy_clipboard(GTK_EDITABLE(data));
}

int main ( int argc , char* argv[] )
{
    gtk_init (&argc , &argv );    // initialising the gtk

    GtkWidget *window , *entry, *button, *hbox;  //declare the needed variables
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);    //create the window

    g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit), NULL);  //if X is clicked then exit from the program

    entry = gtk_entry_new();

    button = gtk_button_new_with_mnemonic("_Write text");

    g_signal_connect(button,"clicked",G_CALLBACK(button_clicked),entry);

    g_signal_connect(entry,"activate",G_CALLBACK(button_clicked),entry);

    hbox = gtk_hbox_new(0,0);

    gtk_box_pack_start(GTK_BOX(hbox),entry,0,0,0);
    gtk_box_pack_start(GTK_BOX(hbox),button,0,0,0);

    gtk_container_add(GTK_CONTAINER(window),hbox);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}