#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("urhandrek");
set_alt_name("templar_trainer");
set_alias("trainer");
set_race("human");
set_short("Urhandrek the Trainer ");
set_long(
"  This man is dressed in a simple brown robe, a sword is\n"+
"belted to his hip.  He has jet black hair, and a well-\n"+
"trimmed beard. His hawk-like nose and sharply accentuated\n"+
"eyebrows give him a predatory look. If you are a knight,\n"+
"you can 'advance' your guild levels, and 'train' your weapon\n"+
"skills with this man.\n");

set_level(20);
set_hp(225);
set_al(800);
set_wc(35);
set_ac(14);
set_aggressive(0);
gold = clone_object("obj/money");
gold->set_money(500);
move_object(gold,this_object());
}

