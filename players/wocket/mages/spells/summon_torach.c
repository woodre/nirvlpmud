#define MAGEPATH "/players/feldegast/mages/"
#define TORACH "/players/feldegast/mages/mon/torach"
#include "/players/feldegast/defines.h"

inherit "/players/wocket/mages/obj/page.c";

reset(arg) {
  if(arg) return;
  spell="summon torach";
  spell_short=YEL+"Summon Torach"+NORM;
  spell_desc=
"Cost:  20 sp\n\
  Little is known of Torach the Acquirer, except that he was born\n\
of some long-dead race and has walked the hills and valleys of a\n\
dozen worlds, for well over a millenium.  Also, that he is a trader,\n\
and will come to deal with whoever calls him.\n";
  time=8;
  size=2;
  spcost=20;
  hpcost=0;
  type="summon";
}
check_spell(object mage, string str) {
  if(present("torach",environment(mage))) {
    tell_object(mage,"He is already here!\n");
    return 0;
  }
  if(environment(mage)->realm()=="NT") {
    tell_object(mage,"Torach will not come to this place.\n");
    return 0;
  }
  return 1;
}

cast_spell(object mage, string str) {
  tell_object(mage,"Torach has answered your call.\n");
  tell_room(environment(mage),"Torach the Acquirer arrives, dusts off his clothes, and gets\n"+
                              "ready to do some trading.\n");
  if(environment(TORACH))
    tell_room(environment(TORACH),"Torach picks up his things and leaves.\n");
  call_other(TORACH,"id");
  move_object(TORACH,environment(mage));
}
