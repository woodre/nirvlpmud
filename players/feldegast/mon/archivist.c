#include "defs.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(OBJ_PATH+"notebook.c"),this_object());
  add_money(random(200));
  set_name("archivist");
  set_alt_name("scribe");
  set_short("Archivist");
  set_long(
"The archivist is a man in his later years, with a light dusting of\n"+
"snowy hair on his head and a pair of wire glasses perched lightly upon\n"+
"his nose.  He sits upon a bench, carefully translating a dusty old\n"+
"book.  He doesn't appear to have noticed you yet.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(12);
  set_wc(16);
  set_ac(8);
  set_hp(180);
  set_al(800);
  set_chat_chance(3);
  load_chat("Archivist says: Hmm...Yes...Fascinating.\n");
  load_chat("Archivist carefully turns a page.\n");
  load_chat("Archivist says, without looking up: Oh, there you are, Pelin.\n"+
            "  Have your men had any luck finding the soulstone?\n");
  load_chat("Archivist hums to himself.\n");
  set_a_chat_chance(3);
  load_a_chat("Archivist says: Ack!\n");
  load_a_chat("Archivist says: Help!  Help!\n");
}
