#include "/players/jamila/define.h"

inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/jamila/docks/mobs/hat.c"));
  init_command("wear helmet");
  set_name("tourist");
  set_alt_name("man");
  set_alias("tourist");
  set_short("A Tourist");
  set_long(
"This man is definately a tourist.  He is wearing shorts,\n"+
"sandals and a polo shirt with a hat that no one from\n"+
"the docks would be caught dead in.  \n"
  );
  set_gender("male");
  set_race("human");
  set_level(17);
  set_wc(24);
  set_ac(13);
  set_hp(300+random(50));
  add_money(900+random(200)); 
  set_al(300);
  set_chat_chance(6);  
  set_a_chat_chance(10);
  load_chat("The tourist looks around at everything.\n");
  load_chat("The tourist points at something cool and runs over to get a closer look.\n");
  load_a_chat("The tourist runs around wildly.\n");
   set_chance(4);
  set_spell_mess1(
"\n\tIn a mad panic the tourist runs right smack\n"+
"\t\tinto his opponent.\n\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"\n\tIn a mad panic the tourist runs right smack\n"+
"\t\tinto you causing your head to burn.\n\n"
  ); /* 1ST PERSON */
  set_spell_dam(10);
}
monster_died() {
object gold;
tell_room(environment(this_object()),
  "A full purse falls from the tourists hands and\n"+
  "spills open releasing coins everywhere.\n");
  gold = clone_object("obj/money");
  gold->set_money(1100+random(500));
  move_object(gold,environment(this_object()));
return 1; }
