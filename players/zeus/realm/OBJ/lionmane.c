inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_id("lions mane");
  set_alias("mane");
  set_short("A lions mane");
  set_long(
"This is the beautiful mane of a mighty lion.  The hair is long and soft,\n"+
"and at the end in which it was hacked off of the lion, dried blood\n"+
"and chunks of flesh remain.  This valuble item can be 'barter'ed for.\n");
  set_weight(1);
  set_value(100+random(3000));
}
