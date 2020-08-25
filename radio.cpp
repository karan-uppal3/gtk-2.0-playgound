#include <gtk/gtk.h>
#include <cstring>

static void toggled_func ( GtkWidget *widget , gpointer data )
{
    g_print("The %s button is set to active",(char*)data);
}

int main ( int argc , char* argv[] )
{
    gtk_init (&argc , &argv );    // initialising the gtk

    GtkWidget *window , *radio , *radio2 , *vbox;  //declare the needed variables
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);    //create the window

    g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit), NULL);  //if X is clicked then exit from the program

    vbox = gtk_vbox_new(0,0);

    radio = gtk_radio_button_new_with_label(NULL,"Label 1");
    gtk_box_pack_start(GTK_BOX(vbox),radio,0,0,0);
    g_signal_connect(radio,"toggled",G_CALLBACK(toggled_func),(gpointer)"1");

    radio2 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio)),"Label 2");
    gtk_box_pack_start(GTK_BOX(vbox),radio2,0,0,0);
    g_signal_connect(radio2,"toggled",G_CALLBACK(toggled_func),(gpointer)"2");

    radio2 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio)),"Label 3");
    gtk_box_pack_start(GTK_BOX(vbox),radio2,0,0,0);
    g_signal_connect(radio2,"toggled",G_CALLBACK(toggled_func),(gpointer)"3");

    radio2 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio)),"Label 4");
    gtk_box_pack_start(GTK_BOX(vbox),radio2,0,0,0);
    g_signal_connect(radio2,"toggled",G_CALLBACK(toggled_func),(gpointer)"4");


    gtk_container_add(GTK_CONTAINER(window),vbox);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

