#include <iostream>
#include <vector>
#include <X11/Xlib.h>
#include <SDL2/SDL.h>
#include <unistd.h> // for usleep(t) microseconds 
using namespace std;


vector<int> getCursor(){

    vector<int> coordinates;

    Display *display = XOpenDisplay(NULL);

    // error handling
    if(display == NULL){
        cerr << "Unable to open display." << endl;
        return {0,0};
    }

    Window root = DefaultRootWindow(display);
    XEvent event;

    // current position
    XQueryPointer(display, root, &event.xbutton.root,
                    &event.xbutton.window, &event.xbutton.x_root,
                    &event.xbutton.y_root, &event.xbutton.x,
                    &event.xbutton.y, &event.xbutton.state);

    XCloseDisplay(display);

    coordinates.push_back(event.xbutton.x);
    coordinates.push_back(event.xbutton.y);

    return coordinates;
}


int main(){
    while(true){
        vector<int> Pos = getCursor();
        // Display the cursor position on the console
        cout << "Cursor Position: x = " << Pos[0] << "\ty = " << Pos[1] << '\r' << flush;
    }

    return 0;
}
