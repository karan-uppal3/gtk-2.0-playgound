#include <gtk/gtk.h>

static void value_changed ( GtkWidget*widget , gpointer data )
{
    g_print("%f\n",gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(widget)));
}

int main(int argc, char *argv[])
{
    gtk_init(&argc,&argv);
    
    GtkWidget *window , *spin;
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
 
    GtkObject* adjustment = gtk_adjustment_new(0,0,10,1,1,NULL);
    
    spin = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment),1,2);

    g_signal_connect(spin,"value-changed",G_CALLBACK(value_changed),NULL);

    gtk_container_add(GTK_CONTAINER(window), spin);
 
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}