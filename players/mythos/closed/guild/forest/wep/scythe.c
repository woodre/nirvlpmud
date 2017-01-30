/* this is on a /players/braxana/horlach/mon/min_death.c  */
#define TR tell_room(environment(this_player())
#include "/players/mythos/closed/ansi.h"

inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("reaper");
  set_alias("scythe");
  set_short("Reaper of Nightmares");
  set_long(" The Long dark stained wood of the handle of this wicked scythe is\n"+
             "curved and wrought with the runes of chaos.  The blade itself has \n"+
             "a cold feel and the same black steel shine as the molten metal of \n"+
             "the hooves that Nightmares posess.  The serpentine haft bears the \n"+
             "marks of battles from time immemorial.\n"+
             "The very stuff of dreams fuels its power.\n");
  set_class(19);
  set_weight(5);
  set_value(15000);
  set_hit_func(this_object());
}

query_save_flag() { return 0; }
query_dwep() { return 1; }

weapon_hit(attacker){
if(random(3) == 0) {
  if(this_player()->query_attrib("wil") > random(70) && check(attacker)) {
    if(attacker->query_hp() > 10) attacker->heal_self(-5-random(10));
    else attacker->heal_self(-random(10));
      TR,"The Scythe blazes with a "+HIR+"light"+NORM+" as it slices into the enemy!\n");
      write("The Scythe vibrates in glee...\n");
  }
  if(random(2)) TR,"The Scythe cuts deeply into "+attacker->short()+"\n");
  else
  TR,attacker->query_name()+" screams as the Scythe cuts into the soul.\n");
return 7;
}
   return;
}

check(attacker) {
  if(attacker->id("nightmare") || attacker->id("dopplganger") || 
     attacker->id("dream") || attacker->id("dreams") || attacker->id("dopp"))
     return 1;
  else return 0; 
}
