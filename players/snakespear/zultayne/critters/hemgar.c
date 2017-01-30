#include "/players/snakespear/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg) {
 object gold;
   ::reset(arg);
   if(arg) return;


set_name("gargoyle");
set_short(GRY+"Hematite "+NORM+"Gargoyle");
set_alias("hematite");
set_race( "spirit");
set_long(
  "  A very tall gargoyle that almost shines in the light.  The surface of\n"+
  "the gargoyle's skin is a very silvery black.  His large wings are spread\n"+
  "wide and he peers about the room.  The gargoyle looks very tough and\n"+
  "ready to defend his home from anyone, no matter the size of the foe.\n");
set_level(17);
set_ac(14);
set_al(-100+random(100));
set_wc(24);
set_hp(450+random(50));
set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(5);
  load_chat("Gargoyle growls: Prepare to feel my wrath, young warrior!\n");
  load_chat("Gargoyle grunts loudly and charges in your direction.\n");
  load_chat("Gargoyle exclaims: I will protect my stonghold with my life!\n");
  load_chat("The Hematite Gargoyle prepares to attack and kill !!\n");
   
set_chance(15);
set_spell_dam(30);

set_spell_mess1(
  "Hematite turns and attacks smacks you with his leathery wings!\n");
set_spell_mess2(
  "Hematite turns and attacks smacks you with his leathery wings!\n");

gold = clone_object("obj/money");
gold->set_money(650);
move_object(gold,this_object());
 }

monster_died() {
  move_object(clone_object("/players/snakespear/zultayne/treasure/hematite.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
      "\n\t\tThe Gargoyle crumbles in defeat ! ! \n");
return 0; }
