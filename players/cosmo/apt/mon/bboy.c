#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold, bub;
  ::reset(arg);
  if(arg) return;

set_name(HIY+"Bubble Boy"+NORM);
set_alias("bubble boy");
set_alt_name("boy");
set_race("human");
set_short("The Bubble Boy");
set_long(
  "  The Bubble Boy is a small child about 12 years of age.\n"+
  "His immunity system failed when he was a baby and since\n"+
  "that time he has been confined to live in this bubble,\n"+
  "with his own private oxygen.  You feel saddened by this\n"+
  "until you realize what a rude little brat this kid actually\n"+
  "is.\n");

set_level(12);
  set_hp(200);
  set_al(-100);
  set_wc(14);
  set_ac(9);
  set_heal(3,20);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The boy whines: Get the hell out of here. I didn't invite you.\n");
set_a_chat_chance(15);
  load_a_chat("The boy boasts: You can't hurt me.  My bubble will protect me.\n");

set_chance(10);
set_spell_dam(30);
set_spell_mess1(
  "\nThe Bubble Boy suddenly begins to "+RED+"glow"+NORM+".\n");
set_spell_mess2(
  "\nThe boy's eyes turn a "+RED+"sinister"+NORM+" color and the\n"+
  "bubble suddenly "+RED+"engulfs"+NORM+" you.\n");

bub = clone_object("/players/cosmo/apt/armor/bubble");
move_object(bub,this_object());
gold = clone_object("obj/money");
gold->set_money(50+random(100));
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
    "The Bubble Boy coughs and gasps, 'I ... need ... air ....'.\n");
return 0; }

