inherit "/obj/armor";
#include "/players/pavlik/closed/colors.h"
#define tp this_player()

/*
 * These powerful slippers can only be worn only by female players.
 * This armor raises the players magical aptitude by 3 points
 * while worn.  This item is UNIQUE and can only 1 can exist at
 * any time.
 *
 * from: ~/monsters/ilstkarn/banshee (a 10000 hp monster)
 */
/* APPROVED BY SNOW 5/28/98 */

reset() {
 set_name("Crystal Slippers");
 set_alias("slippers");
 set_short("a pair of Crystal Slippers");
 set_long(
 "A pair of crystal slippers.\n");
 set_type("boots");
 set_ac(1);
 set_weight(1);
 set_value(1000);
 set_save_flag(1);
}

init() {
  ::init();
  add_action("check_wear","wear");
}

check_wear(str) {

  if(!id(str)) {
    return 0;
  }

  if(tp->query_gender() != "female") {
    write("Who do you think you are, Denis Rodman?\n");
    write("Go find yourself a nice pair of boots instead.\n");
    return 1;
  }

  if(worn) {
    write("You already wear it!\n");
    return 1;
  }

  ::wear(str);

  if(worn) {
    write("You slip your toes into the sparkling crystal slippers.\n");
    write("A powerful sense of awareness overcomes you!\n");
    this_player()->raise_magic_aptitude(3);

  }

  return 1;
}

remove(str) {
    if (!id(str))
        return 0;
    if (!worn) {
        return 0;
    }
    call_other(worn_by, "stop_wearing",name);
    worn_by->raise_magic_aptitude(-3);
    worn_by = 0;
    worn = 0;
    return 1;
}

drop(silently) {
  if(worn) {
    call_other(worn_by, "stop_wearing", name);
    this_player()->raise_magic_aptitude(-3);
  }
  worn = 0;
  worn_by = 0;
  if(!silently)
    tell_object(environment(this_object()),"You drop your worn armor.\n"
);
  return 0;
}

