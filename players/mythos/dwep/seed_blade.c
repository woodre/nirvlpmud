#include "/players/mythos/closed/ansi.h"
int idset;
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("goldenblade");
  set_alias("blade");
  set_short("Goldenblade");
  set_long("A glittering blade of Gold.  The edges are serragated and sharp.\n"+
           "Born from the GoldenSeed, it can be returned to the seed if the\n"+
           "proper robe is wrapped about it.\n");
  set_class(18);
  set_weight(2);
  set_value(1500);
  set_hit_func(this_object());
}

set_idset(n) { idset = n; }
query_idset() { return idset; }
query_save_flag() { return 0; }
query_dwep() { return 1; }

weapon_hit(attacker){
string msg;
  switch(random(8)) {
    case 0: msg = "The "+YEL+"GoldenBlade"+NORM+" slices into the enemy!\n"; break;
    case 1: msg = "Light gleams off the Blade as it slashes into the enemy!\n"; break;
    case 2: msg = "A whistling is heard as the shimmering blade cuts through the air.\n"; break;
    case 3: msg = "The atmosphere is drentched in "+RED+"BLOOD"+NORM+" as the target is cut!\n"; break;
    case 4: msg = attacker->query_name()+" squeals in "+BOLD+"PAIN"+NORM+"!\n"; break;
    case 5: msg = BOLD+"DEATH HAS COME!"+NORM+"\n"; break;
    case 6: msg = "Rays of light are broken into a multitude\n"+
                  "of colors as the blade slices through them.\n"; break;
    case 7: msg = this_player()->query_name()+" screams a Battle Cry and leaps into the fray!\n"; break;
  }
  tell_room(environment(this_player()),msg);
if(random(3) == 0) return 7;   
   return;
}
