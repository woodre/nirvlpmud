#include "/players/eurale/closed/ansi.h"
inherit "obj/monster";
#define TPRN this_player()->query_real_name()
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("sedjak");
set_alias("merchant");
set_short(HIB+"Sedjak, the arcane merchant"+NORM);
set_long(
  "Sedjak is one of the rare arcane merchants that are often found\n"+
  "wherever there is potential trade in magical items.  He is a tall,\n"+
  "lanky, blue giant with an elongated face and thin fingers.  Each\n"+
  "finger on his hands has one more joint than is common in most\n"+
  "humanoid life forms.  He wears a clean, blue robe with gold lines\n"+
  "encircling the ends of his long sleeves.  He will often barter for\n"+
  "the items one has to get rid of.\n");

set_race("creature");
set_level(18);
set_hp(450);
set_al(0);
set_heal(5,7);
set_aggressive(0);
set_dead_ob(this_object());

set_wc(45);
set_ac(15);

set_chat_chance(5);
  load_chat("Sedjak whispers, 'Got anything you'd like to barter for?'\n");
set_a_chat_chance(4);
  load_a_chat("'I'm going to tell all my friends', cries Sedjak\n");

gold = clone_object("obj/money");
gold->set_money(random(700)+360);
move_object(gold,this_object());
}

monster_died() {
  write_file("/players/eurale/NPC/LOG/sedjak",ctime(time())+
    "  Sedjak killed by "+capitalize(TPRN)+".\n");
return 0; }
