/*
Held by brigand9.c
*/
#include "defs.h"

inherit "/obj/armor.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("shield");
  set_alias("starshield");
  set_short(HIW+"Star"+HIM+"shield"+NORM);
  set_long(
    "This shield has the weight and shape of a heavy curved shield,\n"+
    "but it appears to be made out of a piece of the sky as seen\n"+
    "from the countryside on a hot summer night.\n"
  );
  set_weight(3);
  set_ac(2);
  set_type("shield");
  set_value(1000);
  /* added by Illarion May 05 */
  set_params("other|fire",0,15,0);
}
