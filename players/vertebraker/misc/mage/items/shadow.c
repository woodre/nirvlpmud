#include "/players/vertebraker/ansi.h"

int loaded;

status
id(string str)
{
    return str == "verte_dark_thing" || str == "shadow" ||
           str == "black shadow";
}

void
init()
{
    if(!loaded && environment())
    {
      loaded = 1;
      set_light(-1);
      call_out("dissipate", 600);
    }
}

string
short()
{
    return (BOLD + BLK + "A black shadow" + NORM + "\
 has rolled over the area");
}

status
get()
{
    return 0;
}

void
dissipate()
{
    object e, x;

    if(!(e = environment()))
    {
      destruct(this_object());
      return;
    }

    tell_room(e, BOLD + BLK + "\
The black shadow" + NORM + " vanishes.\n");
    set_light(1);
    destruct(this_object());
}

void
long()
{
    return write(BOLD + BLK + "A dark, tendrilous shadow...\n" + NORM);
}
