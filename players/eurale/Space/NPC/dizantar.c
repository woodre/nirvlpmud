#include "/players/eurale/Space/DEFS.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("slu'em");
set_race("humanoid");
set_short("Slu'em, the dizantar bounty hunter");
set_long(
  "This tall, armored dizantar humanoid spends most of his time\n"+
  "hunting and killing zodars.  He is wearing what appears to be\n"+
  "some sort of silvery, heavy plate mail of special construction\n"+
  "with smooth, tightly fitting joints.  The rest of the armor is\n"+
  "covered with spikes and razor-sharp edges.  No part of the body\n"+
  "is left visible.  Even the eye slits show only black.  Despite\n"+
  "the weight of the armor, Slu'em moves quickly, silently and with\n"+
  "great agility.  There is no recorded account of what a dizantar's\n"+
  "body looks like.  When the armor is opened, all that is ever\n"+
  "found is a smoking black pile of ashes.\n");

set_level(20);
  set_hp(550);
  set_al(-400);
  if(!present("kunjukdan")) {
  move_object(clone_object("players/eurale/Space/OBJ/kunjukdan"),TO); }
  init_command("wield kunjukdan");
  set_wc(30);
  set_ac(15);
  set_heal(random(30),5);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The armor glows as if luminescent.\n");
  load_chat("With unnerving speed, Slu'em circles you...\n");
  load_chat("The wicked polearm glints in the light.\n");
set_a_chat_chance(15);
  load_a_chat("Slu'em JABS you in the stomach with the kunjukdan handle.\n");
  load_a_chat("You nearly BLACK OUT from the blow to your chin.\n");
  load_a_chat("SWOOOSH!!!  The kunjukdan just misses...\n");

gold = clone_object("obj/money");
gold->set_money(2000 + random(1000));
move_object(gold,this_object());
}

id(str) { return str == "slu'em" || str == "slu" || str == "dizantar"
	|| str == "bounty hunter" || str == "hunter"; }

monster_died() {
  tell_room(environment(this_object()),
  "As Slu'em hits the floor, you smell burning flesh!\n");
return 0; }
