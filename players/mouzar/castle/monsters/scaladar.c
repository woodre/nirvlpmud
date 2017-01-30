#include "/players/feldegast/closed/ansi.h"
inherit "obj/monster.c";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("scaladar");
set_short("Scaladar");
set_long("This automaton, scorpion-like monster is a cold, methodical killer.\n" +
        "It was made then released with orders to kill anything it come in\n" +
        "with.\n");
set_al(0);
set_level(14);
set_wc(18);
set_ac(11);
set_hp(210);
set_aggressive(1);
set_dead_ob(this_object());
}
 
monster_died(ob) {
  object corpse, part;
  corpse=present("corpse",environment());
  write("Your final blow rips open the automaton's body revealing the parts inside.\n");
  part=clone_object("/obj/treasure.c");
  part->set_id("gear");
  part->set_short(HIY+"Golden gear"+NORM);
  part->set_long("This is a small golden gear.\n");
  part->set_weight(1);
  part->set_value(300);
  move_object(part,corpse);
  part=clone_object("/obj/treasure.c");
  part->set_id("axle");
  part->set_short(HIY+"Golden axle"+NORM);
  part->set_long("This a small golden axle.\n");
  part->set_weight(1);
  part->set_value(300);
  move_object(part,corpse);
  part=clone_object("/obj/treasure.c");
  part->set_id("spring");
  part->set_short(HIY+"Golden spring"+NORM);
  part->set_long("This is a small golden spring.\n");
  part->set_weight(1);
  part->set_value(200);
  move_object(part,corpse);
}
