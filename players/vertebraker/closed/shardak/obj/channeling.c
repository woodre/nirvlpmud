#include "/players/vertebraker/ansi.h"

#define Suckage (10 + random(20))

object apt223;
int beats;

status
id(string str)
{
    return (str == "dRkChnL" || str == "unholy blackness" ||
            str == "blackness");
}

void
load_target(object a)
{
    apt223 = a;
}

string
short()
{
    return BOLD + BLK + "// UnHoly Blackness //" + NORM;
}

void
long()
{
    write(short() + "\n");
}

void
reset(status arg)
{
    if(arg) return;
    set_heart_beat(1);
}

void
heart_beat()
{
    int z;
    object e, a;

    if(root()) { set_heart_beat(0); return; }
    if(!apt223 || !(e = environment()) ||
       !present(apt223, e))
    {
      set_heart_beat(0);
      if(e)
        tell_room(e, "\
The " + BOLD + BLK + "blackness" + NORM + " disappears.\n");
      destruct(this_object());
      return;
    }

    if((beats ++) > 20)
    {
      tell_room(e, "\
The " + BOLD + BLK + "blackness" + NORM + " disappears.\n");
      destruct(this_object());
      return;
    }
      

    if(0 == random(7))
      tell_room(e, "\
The " + BOLD + BLK + "blackness" + NORM + " pulses " + BOLD
      + BLK + "softly" + NORM + ".\n");
    
    a = first_inventory(e);

    if(!random(4))
    while(a)
    {
      if((object)a->query_attack() == apt223 &&
         !a->query_ghost())
      {
        if((status)a->query_npc())
        {
          a->heal_self(-Suckage);
          apt223->add_hit_point(Suckage);
          if(0 == random(3))
            tell_object(apt223, BOLD + BLK + "\
Dark energy" + NORM + " floods through your veins.\n");
          if(0 == random(3))
            tell_room(e, (string)apt223->query_name() + " \
appears to be healthier.\n", ({ apt223 }));
        }
        else
        {
          z = (int)a->query_hp();
          a->hit_player(Suckage, "other|evil");
          if(((int)a->query_hp() - z) >= 1)
          {
            apt223->add_hit_point(Suckage);
            if(0 == random(3))
              tell_object(apt223, BOLD + BLK + "\
Dark energy" + NORM + " floods through your veins.\n");
            if(0 == random(3))
              tell_object(a, BOLD + BLK + "\
Life force" + NORM + " is sucked away from you...\n");
            if(0 == random(3))
              tell_room(e, (string)apt223->query_name() + " \
appears to be healthier.\n", ({ apt223 }));
          }
        }
      }
      a = next_inventory(a);
    }

}
