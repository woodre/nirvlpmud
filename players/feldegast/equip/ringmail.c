#include "defs.h"

inherit "/obj/armor.c";

void reset(int arg) {
  if(arg) return;
  set_name("mail");
  set_alias("ring mail");
  set_short("A suit of ring mail");
  set_long(
    "This is a suit of armor consisting of interlocking steel rings.\n"+
    "It offers greater flexibility than some other types of armor, but\n"+
    "can be quite noisy.\n"
  );
  set_ac(3);
  set_type("armor");
  set_weight(3);
  set_value(600);
}
