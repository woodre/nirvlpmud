#include "/players/mythos/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("cryeo");
  set_alias("knife");
  set_short("Steel Knife");
  set_long("A dark steel blade.  Magical runes are \n"+
          "etched along its length.\n");
  set_class(20);
  set_weight(1);
  set_value(50);
  set_hit_func(this_object());
}

query_save_flag() { return 1;}

weapon_hit(attacker){
  if(random(3) == 0) {
    write("The blade flashes!\n");
    move_object(clone_object("/players/mythos/closed/guild/forest/mon/worm.c"),attacker);
    this_player()->heal_self(-3-random(10));
    return -5; }
   return;
}

init() {
 ::init();
/* Rumplemintz - removing, don't need it in init as well as weapon_hit
 if(random(3) == 0) {
    write("The blade flashes!\n");
    move_object(clone_object("/players/mythos/closed/guild/forest/mon/worm.c"),
    this_player());
    move_object(clone_object("/players/mythos/closed/guild/forest/mon/worm.c"),
    this_player());
    move_object(clone_object("/players/mythos/closed/guild/forest/mon/worm.c"),
    this_player());
    move_object(clone_object("/players/mythos/closed/guild/forest/mon/worm.c"),
    this_player());
    this_player()->heal_self(-3-random(10));
    }
*/
}