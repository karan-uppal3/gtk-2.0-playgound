// Didn't work

#include <gtk/gtk.h>
#include <cstring>
 
static float percent = 0.0;
 
static gboolean inc_progress(gpointer data)
{
        percent += 0.05;
        if(percent > 1.0)
                percent = 0.0;
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(data), percent);
        char c[3];
        sprintf(c, "%d%%", static_cast<int>(percent*100));
        gtk_progress_bar_set_text(GTK_PROGRESS_BAR(data), c);
}
 
int main(int argc, char* argv[])
{
        gtk_init(&argc, &argv);
        // Didn't work

#include <gtk/gtk.h>
#include <cstring>
 
static float percent = 0.0;
 
static gboolean inc_progress(gpointer data)
{
        percent += 0.05;
        if(percent > 1.0)
                percent = 0.0;
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(data), percent);
        char c[3];
        sprintf(c, "%d%%", static_cast<int>(percent*100));
        gtk_progress_bar_set_text(GTK_PROGRESS_BAR(data), c);
}
 
int main(int argc, char* argv[])
{
        gtk_init(&argc, &argv);
        GtkWidget *window, *progress;
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
 
        progress = gtk_progress_bar_new();
 
//      gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress), "50%");
 
//      gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(progress), GTK_PROGRESS_TOP_TO_BOTTOM);
 
        g_timeout_add(200, inc_progress, progress);     // 300 ms
 
        gtk_container_add(GTK_CONTAINER(window), progress);
 
        gtk_widget_show_all(window);
        gtk_main();
        return 0;
}
        progress = gtk_progress_bar_new();
 
//      gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress), "50%");
 
//      gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(progress), GTK_PROGRESS_TOP_TO_BOTTOM);
 
        g_timeout_add(200, inc_progress, progress);     // 300 ms
 
        gtk_container_add(GTK_CONTAINER(window), progress);
 
        gtk_widget_show_all(window);
        gtk_main();
        return 0;
}