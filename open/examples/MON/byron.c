#include "/players/feldegast/defines.h"

inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/feldegast/wep/j_rapier.c"));
  move_object(clone_object("/players/feldegast/equip/shield.c"));
  init_command("wear shield");
  init_command("wield rapier");
  set_name("duke byron");
  set_alt_name("byron");
  set_alias("duke");
  set_short("Duke Byron");
  set_long(
"Duke Byron is a handsome man in his early twenties dressed\n"+
"in the most fashionable clothes money can buy.  Despite\n"+
"his courtly appearance, you notice a cunning gleam in his\n"+
"eyes and an unnatural grace that belie his effete manner.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(20);
  set_wc(30);
  set_ac(17);
  set_hp(500);
  set_al(500);
  add_money(4000);  
  set_a_chat_chance(10);
  load_a_chat("Duke Byron yells: En guarde!\n");
  load_a_chat("Duke Byron's blade misses you by a heartbeat.\n");
  load_a_chat("Duke Byron thrusts with his jewelled blade.\n");
   load_a_chat("Duke Byron dazzles you with his fencing skills.\n");
  set_chance(5);
  set_spell_mess1(
"\n\tDuke Byron thrusts his blade into his opponent's gut\n"+
"\t\tspilling "+RED+"blood"+NORM+"freely.\n\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"\n\tDuke Byron thrusts his blade into your gut\n"+
"\t\tspilling "+RED+"blood"+NORM+"freely.\n\n"
  ); /* 1ST PERSON */
  set_spell_dam(25);
}
