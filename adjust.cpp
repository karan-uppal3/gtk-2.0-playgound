#include <gtk/gtk.h>

static void value_changed(GtkWidget *scale , gpointer data )
{
    g_print("%f\n",gtk_range_get_value(GTK_RANGE(scale)));
}

int main(int argc, char *argv[])
{
    gtk_init(&argc,&argv);
    
    GtkWidget *window , *scale;
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
 
    GtkObject* adjustment = gtk_adjustment_new(0,0,10,1,1,NULL);
    scale = gtk_hscale_new(GTK_ADJUSTMENT(adjustment));

    gtk_scale_set_value_pos(GTK_SCALE(scale),GTK_POS_BOTTOM);
    
    gtk_scale_set_digits(GTK_SCALE(scale),3);
    
    gtk_scale_set_draw_value(GTK_SCALE(scale),false); //true to see value

    g_signal_connect(scale,"value-changed",G_CALLBACK(value_changed),NULL);

    gtk_container_add(GTK_CONTAINER(window), scale);
 
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}