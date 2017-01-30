#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("clyde");
  set_short("Clyde the Talking Sword");
  set_long(
"Clyde is a common, working class sword with few aspirations.\n");
  set_class(16);
  set_value(5);
  set_weight(1);
  set_type("sword");
  set_hit_func(this_object());
  set_heart_beat(1);
}
int weapon_hit(object ob)
{
  if(!random(6))
  {
    switch(random(5))
    {
      case 0: write("Clyde says: HEY!  Watch where you swing me!\n");
              break;
       case 1: write("Clyde says: You got a nick in me!  YOU BASTARD!\n");
               break;
       case 2: write("Clyde says: Weapon for sale!  Will accept any offer!\n");
               break;
        case 3: write("Clyde says: Oh, and suddenly we think we're Zorro!  I don't THINK SO!\n");
                break;
         case 4: write("Clyde says: I'm a sword, not a club, you IDIOT!\n");
                 break;
          case 5: write("Clyde says: Parry!  Riposte!  Avant!  That's what you're SUPPOSED to do!\n");
                 break;
    }
    return -random(8);
  }
  if(!random(50))
  {
    write("Clyde escapes your grasp.\n");
    command("drop clyde",this_player());
  }
}
void heart_beat()
{
  if(environment() && environment()->is_player())
  {
    if(!random(60))
    {
      tell_object(environment(),"Clyde says: Would it kill you to polish me every now and then?\n");
    }
  }
  else
  {
    if(!random(20)) tell_room(environment(),"Clyde says: HEY!  Somebody pick me up!\n");
  }
}
int wield(string str)
{
  if(::wield(str))
  {
  write("Clyde says: Hey!  Don't get too friendly!\n");
    return 1;
  }
}
