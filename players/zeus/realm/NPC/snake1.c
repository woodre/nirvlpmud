inherit "/obj/monster";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("snake");
  set_short("A snake");
  set_race("snake");
  set_long(
"This is a green forest snake.  It's body is a patchwork of many different\n"+
"shades of green and is actually very beautiful.  It has a very thick body,\n"+
"and appears to be extremely agile.  It's black eyes look very perceptive.\n"+
"It's mouth is closed, however it looks as though it could open quite wide\n"+
"if needed.\n");
  set_level(16);
  set_ac(4+random(4));
  set_wc(20+random(5));
  set_hp(200);
  set_al(-55);
  set_aggressive(1);
  set_chat_chance(4);
  set_a_chat_chance(5);
  load_chat("The snake slithers around the room.\n");
  load_chat("The snake coils up and watches you.\n");
  load_chat("The snake watches you closely.\n");
  load_chat("The snake quickly glances into the forest.\n");
  load_chat("The snake hisses at you.\n");
  load_chat("The snake flicks it's tongue into the air.\n");
  load_chat("The snake sits perfectly still.\n");
  load_a_chat("The snake bites your leg!\n");
  load_a_chat("The snake snaps at you!\n");
  load_a_chat("The snake hits you with a crushing blow!\n");
  set_chance(5);
  set_spell_dam(25);
  set_spell_mess1("The snake bites your ankle!\n");
  set_spell_mess2("The snake bites your ankle!\n");
  set_dead_ob(TO);
}  }

monster_died(){
 write("You skin the green snake.\n");
  MO(CO("/players/zeus/realm/OBJ/snakeskin.c"), environment(TO));
return 1; }
