#include "defs.h"

inherit "/obj/armor.c";

void reset(int arg) {
  if(arg) return;
  set_name("helm");
  set_alias("helmet");
  set_short(HIY+"Golden"+BLK+" helm"+NORM);
  set_long(
    "This is a mighty steel helm with strong cheek and nose guards\n"+
    "that almost completely protect the face.  It has fancy gold\n"+
    "trimming and its rim is studded with blue and red gems.\n"
  );
  set_weight(4);
  set_ac(2);
  set_type("helmet");
  set_value(4000);
}

do_special(owner) {
  if(!random(6)) {
    if(!random(3) && this_player()) {
      tell_object(owner,TPN+" rings your helm like a gong.\n");
    }
    owner->add_hit_point(-6);
  }
  if(!random(10)) {
    tell_object(owner,"The blow glances off of your helm.\n");
    return 1;
  }

}

