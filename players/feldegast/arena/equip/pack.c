#include "def.h"
#include "/players/feldegast/defines.h"

inherit "obj/treasure";


reset(arg) {
  if(arg) return;
  set_id("pack");
  set_alias("backpack");
  set_short("A backpack");
  set_long(
"This is a standard military backpack made out of some\n"+
"tough, waterproofed material.\n"
  );
  set_weight(1);
  set_value(50);
  if(!present("mail")) {
    object mail;
    mail=clone_object(PATH+"mail");
    move_object(mail,this_object());
  }
}
can_put_and_get() { return 1; }
