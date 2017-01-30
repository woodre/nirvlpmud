#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("father");
set_alias("man");
set_alt_name("amys_father");
set_race("unknown");
set_short("An old man");
set_long(
  "A wrinkled old man with leathery skin.  It seems like he\n"+
  "has worked out in the sun for most of his life and it has\n"+
  "taken it's toll on him.  A sadness seems to drag him down\n"+
  "you wonder what he could be missing\n" );

set_level(20);
set_hp(700+random(600));
set_al(1000);
set_wc(40);
set_ac(20);
set_heal(5,10);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The man says 'Where could she have gone?' \n");
set_chat_chance(15);
  load_chat("The man weeps quietly.\n");
set_chat_chance(15);
  load_chat("The man says 'I told her not to go into the swamp.' \n");
set_chat_chance(15); 
  load_chat("The man asks 'Could you find her for me?' \n");
set_a_chat_chance(15);
  load_a_chat("The man screams 'I won't die till she is safe!' \n");

set_chance(10);
set_spell_dam(random(40));

set_spell_mess1(
  "The man slams a solid forearm into your head and you "+BOLD+""+RED+"BLEED"+NORM+". \n");
set_spell_mess2(
  "The man slams his forearm into his opponents head and makes them bleed. \n");

gold = clone_object("obj/money");
gold->set_money(4000+ random(3000));
move_object(gold,this_object());
}

