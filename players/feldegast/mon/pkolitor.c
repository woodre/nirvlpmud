#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("p'kolitor");
  set_alt_name("kolitor");
  set_alias("elder");
  set_short("P'kolitor the Village Elder");
  set_long(
"P'kolitor is an ancient p'kalian, his skin having lost its luster\n"+
"and become brown and spotted.  His eye stalks are shriveled and\n"+
"his hands shake feebly.  He wears a bright blue vest with a felt\n"+
"sun on it over a white cotton robe.\n"
  );
  set_gender("male");
  set_race("p'kalian");
  set_level(10);
  set_wc(14);
  set_ac(8);
  set_hp(150);
  set_al(600);
  set_chat_chance();
  load_chat("P'kolitor meditates.\n");
  load_chat("P'kolitor snorts softly and then shakes himself.\n");
  move_object(clone_object(OBJ_PATH+"scroll-fable.c"),this_object());
  add_talk("well", "P'kolitor says: I am the keeper of the well key to the well.\n");
  add_talk("key", "P'kolitor says: I believe I gave the key to the well to P'salin.\n");
  add_talk("history", "P'kolitor says: This mural records the history of our people.\n");
  add_talk("p'chilik", "P'kolitor says: Such a good boy.\n");
  add_talk("p'salin", "P'kolitor says: He runs the apothecary.  Plays a mean game of t'sltnik.\n");
  add_talk("p'lila", "P'kolitor says: Ah, if I were only a few decades younger...\n");
  add_talk("tully", "P'kolitor says: He does not sell much.  I'm not sure why he is here.\n");
  add_talk("village", "P'kolitor says: We have lived here for many years.\n");
}
