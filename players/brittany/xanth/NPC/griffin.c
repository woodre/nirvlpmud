#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("griffin");
set_alias("snake");
set_alt_name("animal");
set_race("creature");
set_short("A large Griffin");
set_long("	A snake-like reptile, it has a long thick tail and long thin\n"+
"It has narrow double-jointed leg, large footed, and wickedly\n"+
"clawed.  Its narrow head is beaked, with pale blue eyes.  Large\n"+
"wings fold against its sides that are purple and leathery.  It\n"+
"does not have any hair nor feathers, but has scaled areas.\n");

set_level(5);
   set_hp(75);
   set_wc(9);
   set_ac(5);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());

set_chat_chance(5);
load_chat("The griffin slivers towards you.\n");
load_chat("The griffin rattles its long tail.\n");
  
   gold = clone_object("obj/money");
gold->set_money(200);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("players/brittany/amber/OBJ/horn.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
"The griffin squeals loudly then dies.\n");
   return 0; }