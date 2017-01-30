#include "def.h"
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(!present("needle"))
    move_object(clone_object(PATH+"Wep/needle"),this_object());
  if(arg) return;
  set_name("doctor");
  set_alt_name("dr");
  set_alias("schreber");
  set_short("Dr. Schreber");
  set_long(
"Dr. Schreber is a frail, twisted old man, who retains\n"+
"only his memories as a scientist and only that due to\n"+
"his servitude to the rulers of this city.  Now, he\n"+
"believes that he might have a chance to overthrow his\n"+
"masters.\n"
);
  set_gender("male");
  set_race("human");
  set_level(10);
  set_wc(14);
  set_ac(8);
  set_hp(150);
  set_al(-100);
  add_money(450);
  set_chat_chance(5);
  load_chat("Dr. Schreber says: I call them...strangers...\n");
  load_chat("Dr. Schreber says: Murdoch...is...our only hope.\n");
  load_chat("Dr. Schreber says: We...all of us...are their experiment.\n");
  load_chat("Dr. Schreber says: They...mix and match...memories...with my help.\n");
  load_chat("Dr. Schreber says: They fear...moisture...and sunlight.\n"+
            "                   A phobia, if you will.\n");
  set_a_chat_chance(6);
  load_a_chat("Dr. Schreber tries to stick you with a needle.");
}
