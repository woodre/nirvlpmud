#include "../include/ansi.h"
void
long()
{
    write(RED+"\
A thick red deposit of scales coats your body from your\n\
neck, down your chest, around your torso, and to your\n\
lower extremities.  A dark red aura enshrouds it.\n"+NORM);
}

int
do_special(object User)
{
    string Merv;
    if(0 == random(6))
    {
      if(0 == random(6))
        Merv = "Your scaly skin hardens in defense.\n";
      else if(0 == random(5))
        Merv = "The dragonskin deflects part of the blow.\n";
      else if(0 == random(4))
        Merv = "Just as the blow makes contact with your skin, it ripples\n"+
               "and ruptures.  Scales deflect the onslaught.\n";
      else if(0 == random(3))
        Merv = "The blow is softened by your dragonskin.\n";
      else
        Merv = "Your dragonskin solidifies, hardening against the strike.\n";
      tell_object(User, Merv);
      return random(4);
    }
}
      
void extra_look()
{
    if(this_player() == environment())
      write("You are armored in " + BOLD + BLK + "DragonSkin" + NORM + ".\n");
    else write((string)environment()->query_name() + " is armored in " + BOLD + BLK + "DragonSkin" + NORM + ".\n");
}


id(str) { return str == "dragon skin" || str == "dragonscale" ||
          str == "armour" || str == "armour of dark red dragonscale"
          || str == "verte_dragon_skin" || str == "skin" || str == "scales"
        || str == "dragonskin";
}

drop() { return 1; }

get()
{
    return 1;
}
