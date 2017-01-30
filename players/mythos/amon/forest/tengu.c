#include "/players/mythos/closed/ansi.h"
inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("tengu");
  set_race("spirit");
  set_short("Tengu");
  set_long("One of the great spirit warriors- this winged man is an opponent\n"+
           "to be wary of.  His face is that of a beaked like that of a bird's\n"+
           " and his wings on his back are folded neatly beneath a cloak.\n");
  set_hp(800);
  set_level(25);
  set_al(350);
  move_object(clone_object("/players/mythos/aarmor/forest/cloak.c"),this_object());
  init_command("wear cloak");
  set_wc(50);
  set_ac(17);
  set_aggressive(0);
  set_chat_chance(3);
  set_a_chat_chance(15);
  load_chat("The Tengu smiles at you.\n");
  load_chat("The Tengu paces.\n");
  load_a_chat("Tengu strikes out quickly!\n");
  set_chance(30);
  set_spell_dam(40);
  set_spell_mess1("The Tengu strikes out quickly and smashes his foe!\n");
  set_spell_mess2("The Tengu strikes out swiftly and smashes you!\n");
  set_mult(2);
  set_mult_chance(50);
  set_mult_dam1(10);
  set_mult_dam2(80);
  gold=clone_object("obj/money");
  gold->set_money(random(2000)+1000);
  move_object(gold,this_object());
}

#include "/players/mythos/amon/hb_ag.h"
