#include <gtk/gtk.h>

static void check_state ( GtkWidget *widget , gpointer data )
{
    if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget) ))
    {
        g_print("The toggle button activated");
    }
    else
    {
        g_print("The toggle button is unactivated");
    }
    
}

int main ( int argc , char* argv[] )
{
    gtk_init (&argc , &argv );    // initialising the gtk

    GtkWidget *window , *toggle , *vbox;  //declare the needed variables
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);    //create the window

    g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit), NULL);  //if X is clicked then exit from the program

    vbox = gtk_vbox_new(0,0);

    toggle = gtk_toggle_button_new_with_mnemonic("_Toggle 1");
    gtk_box_pack_start(GTK_BOX(vbox),toggle,0,0,0);
    g_signal_connect(toggle,"toggled",G_CALLBACK(check_state),NULL);

    toggle = gtk_toggle_button_new_with_mnemonic("T_oggle 2");
    gtk_box_pack_start(GTK_BOX(vbox),toggle,0,0,0);
    g_signal_connect(toggle,"toggled",G_CALLBACK(check_state),NULL);

    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle),true);

    gtk_container_add(GTK_CONTAINER(window),vbox);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
