#include <iostream>
#include <windows.h>
#include <allegro5/allegro.h>


using namespace std;

unsigned short r = 0, g = 0, b = 0;
bool directionR = true, directionG = true, directionB = true;
unsigned short option = 1;

void Red()
{
    if(directionR == true)
        {
            r++;
            cout << "r: " << r << " g: " << g << " b: " << b << " Case: " << option << endl;
        }
        else
        {
            r--;
            cout << "r: " << r << " g: " << g << " b: " << b << " Case: " << option << endl;
        }

        if(r == 255 || r == 0)
        {
            directionR = !directionR;
            option++;
        }

}

void Green()
{
    if(directionG == true)
        {
            g++;
            cout << "r: " << r << " g: " << g << " b: " << b << " Case: " << option << endl;
        }
        else
        {
            g--;
            cout << "r: " << r << " g: " << g << " b: " << b << " Case: " << option << endl;
        }

        if(g == 255 || g == 0)
        {
            directionG = !directionG;
            option++;
        }

}

void Blue()
{
    if(directionB == true)
        {
            b++;
            cout << "r: " << r << " g: " << g << " b: " << b << " Case: " << option << endl;
        }
        else
        {
            b--;
            cout << "r: " << r << " g: " << g << " b: " << b << " Case: " << option << endl;
        }

        if(b == 255 || b == 0)
        {
            directionB = !directionB;
            option++;
        }

}


int main()
{
    al_init();
    al_install_keyboard();
    ALLEGRO_KEYBOARD_STATE keyboard;
    ALLEGRO_DISPLAY *window = al_create_display( 800, 640);
    al_set_window_title( window,"Color spectrum");

    //---
    unsigned short counter = 0;
    //---


    while( !al_key_down(&keyboard, ALLEGRO_KEY_ESCAPE)) //koniec programu gdy wciœniemy klawisz Escape
   {
    //----------
    if(counter % 20 == 0)
        {

        counter = 0;

        switch(option)
        {
            case 1:
                {
                    //Red();   // 0
                    //Green(); // 0
                    Blue();  // 1
                    break;
                }
            case 2:
                {
                    Red();   // 1
                    //Green(); // 0
                    //Blue();  // 1
                    break;
                }
            case 3:
                {
                    //Red();   // 1
                    //Green(); // 0
                    Blue();  // 0
                    break;
                }
            case 4:
                {
                    //Red();   // 1
                    Green(); // 1
                    //Blue();  // 0
                    break;
                }
            case 5:
                {
                    Red();   // 0
                    //Green(); // 1
                    //Blue();  // 0
                    break;
                }
            case 6:
                {
                    //Red();   // 0
                    //Green(); // 1
                    Blue();  // 1
                    break;
                }
            case 7:
                {
                    Red();   // 1
                    //Green(); // 1
                    //Blue();  // 1
                    break;
                }
            default:
                {

                    option = 1;
                }
        }

    //----------
            al_get_keyboard_state(&keyboard);
            al_clear_to_color(al_map_rgb( r, g, b));
        }
        al_flip_display();

        Sleep( 1 );
        counter++;
    }

    al_destroy_display(window);

    return 0;
}
