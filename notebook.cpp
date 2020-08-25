#include <gtk/gtk.h>
#include <string>

int main(int argc, char *argv[])
{
    gtk_init(&argc,&argv);
    
    GtkWidget *window, *notebook , *label , *label2;
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
 
    notebook = gtk_notebook_new();
    gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook),GTK_POS_BOTTOM);

    for ( int i = 0 ; i < 5 ; i++ )
    {
        std::string s = "This is just a text of the notebook\nIn this example you can learn it\nThis is page ";

        s += static_cast<char>(49+i);

        label = gtk_label_new(s.c_str());

        s = "Page ";
        s += static_cast<char>(49+i);

        label2 = gtk_label_new(s.c_str());

        gtk_notebook_append_page(GTK_NOTEBOOK(notebook),label,label2);
    }

    gtk_container_add(GTK_CONTAINER(window), notebook);
 
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}