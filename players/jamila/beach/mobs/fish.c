#include "/players/jamila/define.h"

inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  set_dead_ob(this_object());
  if(arg) return;
  set_name("small fish");
  set_alt_name("fish");
  set_alias("fish");
  set_short("A Small Fish");
  set_long(
"This is a small fish that has no fear as it swims around between\n"+
"your legs.  It tempts you to try to catch it.\n"
  );
  set_gender("unknown");
  set_race("fish");
  set_level(4);
  set_wc(8+random(2));
  set_ac(4+random(2));
  set_hp(55+random(15));
  set_al(100);
  set_chat_chance(6); 
  set_a_chat_chance(10);
  load_chat("The fish swims around your legs happily.\n");
  load_a_chat("The fish darts between your legs.\n");
  set_chance(7);
  set_spell_mess1(
"\n\tThe small fish rakes its scales across it's opponent's skin\n"+
"\t\tmaking a small cut in their flesh.\n\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"\n\tThe small fish rakes its scales across your skin making \n"+
"\t\ta small cut in your flesh.\n\n"
  ); /* 1ST PERSON */
  set_spell_dam(3);
}
monster_died() {
object gold;
tell_room(environment(this_object()),
  "The fish dies and you notice that while fighting you\n"+
  "slit open its stomach and coins fell out.  This fish\n"+
  "should have been more careful about what it ate.\n");
  gold = clone_object("obj/money");
  gold->set_money(100+random(50));
  move_object(gold,environment(this_object()));
return 1; }