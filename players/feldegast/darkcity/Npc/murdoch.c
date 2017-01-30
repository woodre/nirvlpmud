#include "/players/feldegast/defines.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("john murdoch");
  set_alt_name("john");
  set_alias("murdoch");
  set_short("John Murdoch");
  set_long(
    "John Murdoch is a handsome man in his twenties who has\n"+
    "a slightly wild, hunted look to him.  He is a man with\n"+
    "no memory of his past, but possessed of a terrible\n"+
    "power to bend reality to his will.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(20);
  set_wc(30);
  set_ac(17);
  set_hp(500);
  set_al(800);
  add_money(4900+random(8)*25);
  set_chat_chance(5);
  load_chat("John Murdoch asks: Who am I?\n");
  load_chat("John Murdoch asks: How do you get to Shell Beach?\n");
  load_chat("John Murdoch asks: When was the last time you remember seeing the sun?\n");
  load_chat("John Murdoch says: I'm innocent!\n");
  load_chat("John Murdoch says: They're after me.\n");
  set_a_chat_chance(6);
  load_a_chat("John Murdoch warps reality around you.\n");
  set_chance(15);
  set_spell_mess1(
"The air "+HIM+"warps"+NORM+" around John Murdoch.\n\n"+
"His foe flies through the air and lands in a heap.\n\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"The air "+HIM+"warps"+NORM+" around John Murdoch.\n\n"+
"You are struck by a force of unimaginable power,\n"+
"sending you flying through the air.\n"
  ); /* 1ST PERSON */
  set_spell_dam(40);
}
