inherit "/obj/monster.c";
#include "/obj/ansi.h"
#define tpn this_player()->query_name()

object bra;
reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Super Model");
  set_race("human");
  set_alias("model");
  set_short(BOLD+RED+"A Sexy Model"+NORM);
  set_long(
    " This is a sexy runway model, hired by Victoria's Secret.\n"+
    "She seems a bit twitchy and has a bit of a sore nose from\n"+
    "all the cocaine she must be doing. Runway models are evil\n"+
    "creatures who would stop at nothing to be #1. Beware!'n"+
    " \n"+
    " Measurements: 30C-26-34\n");
    
  bra = clone_object("/players/tallos/victoria/objects/ipexbrablue.c");
  move_object(bra, this_object());
  command("wear bra", this_object());
  
  add_money(2500+random(1000));
  set_level(18+random(3));
  set_hp(450+random(350));
  set_al(-1000);
  set_ac(20+random(6));
  set_wc(32+random(5));
  set_aggressive(0);
  set_chat_chance(10);
  load_chat("The sexy model says, \"Don't you wish your girlfriend was hot like me?\"\n");
  load_chat("The sexy model does her little turn on the catwalk.\n");
  add_spell("Claws",
  "The "+RED+"#MN#"+HIR+" bites and claws at you with vicious drug fueled RAGE!!!"+NORM+"\n",
  "The "+RED+"#MN#"+HIR+" begins to bite and scratch with cocaine drivin energy."+NORM+"\n",
  25,40,"other|physical");
}
