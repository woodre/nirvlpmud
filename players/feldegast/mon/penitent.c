#include "defs.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("penitent");
  set_alt_name("idiot");
  set_short("A penitent");
  set_long(
    "The penitent stands in the middle of the plaza wearing\n"+
    "nothing but his breaches.  His back is scarred with long\n"+
    "bloody scars that go up and down his back.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(9);
  set_wc(13);
  set_ac(7);
  set_hp(135);
  set_al(50);
  set_chat_chance(5);
  load_chat("The penitent flagellates himself.\n");
  load_chat("The penitent mumbles a prayer.\n");
  load_chat("The penitent whimpers.\n");
  move_object(clone_object(WEP_PATH+"flog.c"),this_object());
}
