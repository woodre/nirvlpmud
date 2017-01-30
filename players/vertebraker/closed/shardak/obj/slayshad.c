#include "/players/vertebraker/ansi.h"

object shadowee;

void
load_shadow(object ob)
{
    shadowee = ob;
    shadow(shadowee, 1);
}

void
unload_shadow()
{
    if(objectp(shadowee))
      shadow(shadowee,0);
}

status
get() 
{ 
    if(shadowee)
    {
      shadowee->get();
      if(shadowee)
        write((string)shadowee->short() + " is cursed!\n");
    }
    return 0;
}

string
short()
{
    string sh;

    return (shadowee && (sh=(string)shadowee->short()) ?
            (sh + " " + BOLD + "(CurSed)" + NORM) :
            "");
}
