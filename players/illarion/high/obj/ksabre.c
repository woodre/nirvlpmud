/* weapon for high/mon/killian.c */
#include "/players/illarion/dfns.h"
inherit "/players/illarion/high/obj/imm_sword";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("sabre");
  set_alt_name("sword");
  set_short("A ancient cavalry sabre");
  set_long(
"A deceptively old and klunky weapon, this sword has served in many a\n"+
"military campaign, in the hands of an officer.  The blade is curved,\n"+
"one-edged, and has a blunt point, but is razor-sharp.  A large cupped\n"+
"handguard protects the worn hilt.\n");
  set_class(17);
  set_weight(4);
  set_value(1200);
  set_hit_func(this_object());
}
weapon_hit() {
  if(random(4)) return 0;
  if(wielded_by->query_name() == "Simon Killian" ||
      wielded_by->query_attrib("str") > random(50)) {
    tell_object(wielded_by,"You put your back into your swing.\n");
    return 3+random(3);
  }
}
