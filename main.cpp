#include <iostream>
#include <vector>
#include <X11/Xlib.h>
#include <unistd.h> // for usleep(t) microseconds
using namespace std;


int main(){
    Display *display = XOpenDisplay(NULL);

    if(display == NULL){
        cerr << "Unable to open display." << endl;
        return 1;
    }

    Window root = DefaultRootWindow(display);

    XEvent event;
    while(true){
        XQueryPointer(display, root, &event.xbutton.root,
                      &event.xbutton.window, &event.xbutton.x_root,
                      &event.xbutton.y_root, &event.xbutton.x,
                      &event.xbutton.y, &event.xbutton.state);
        
        // Display cursor pos
        cout << "Cursor Position: \n" << "x = " << event.xbutton.x
             << "\ty = " << event.xbutton.y << '\r' << flush;

        usleep(1000000); // sleep 100 ms to avoid excessive update
    };

    XCloseDisplay(display);

    return 0;
}