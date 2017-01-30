#include "../defs.h"

inherit TEACHER;

void reset(int arg) {
  ::reset(arg);
  if(arg)return;
  set_name("aubec");
  set_alias("master");
  set_short("Master Aubec");
  set_long(
"Master Aubec is a tall, stern looking sorcerer with a fierce scowl\n\
that follows him wherever he goes.  His eyes are intense, probing,\n\
and you feel a sudden urge to confess all of your sins.  Aubec, some-\n\
times called 'the Harsh' is the instructor of apprentices at The Misty\n\
Tower.  You can 'ask' him for more information.\n"
  );
  set_level(30);
  set_hp(500);
  set_wc(50);
  set_ac(30);
  set_chat_chance(4);
  load_chat("Aubec says: Yes, what do you want?\n");
  add_spell("bauble","bauble",500,5);
  add_spell("light","light",5000,10);
  add_spell("magic missile","magic_missile",5000,40);
  add_spell("shock","shock",15000,40);
}
