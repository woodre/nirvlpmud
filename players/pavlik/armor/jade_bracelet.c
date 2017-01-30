inherit "/obj/armor";
#include "/players/pavlik/closed/colors.h"
#define tp this_player()

/*
 * This item can only be worn be female players.
 * from: ~/monsters/ilstkarn/banshee
 */

reset() {
 set_name("Jade Bracelet");
 set_alias("bracelet");
 set_short("a Jade Bracelet");
 set_long(
 "A fine chain of jade links.  The rounded pieces of jade are linked\n"+
 "together with thin strands of finely woven gold.  The bracelet is\n"+
 "very beautiful and also very delicate.\n");
 set_type("misc");
 set_ac(1);
 set_weight(1);
 set_value(3500);
 set_save_flag(1);
 chance_break();
}

init() {
  ::init();
  add_action("check_wear","wear");
}

/*
 * Chance_Break:
 * Because this item is so delicate it may break apart in combat.
 */
chance_break() {
  if(!worn_by) {
    return 1;
  }
  if(!worn_by->query_attack()) {
    return 1;
  }
  if(random(10) != 4) {
    return 1;
  }
  tell_object(worn_by,
  "Your opponent lands a blow on your Jade Bracelet and the delicate\n"+
  "piece of jewerly breaks!\n");
  tell_object(worn_by,
  "The Jade Bracelet shatters into a thousand pieces!\n");
  drop(1);
  destruct(this_object());
  return 1;
}

check_wear(str) {

  if(!id(str)) {
    return 0;
  }

  if(tp->query_gender() != "female") {
    write("Your wrist is too thick for this delicate bracelet.\n");
    return 1;
  }

  if(worn) {
    write("You already wear it!\n");
    return 1;
  }

  ::wear(str);

  if(worn) {
    write("You clasp the delicate bracelet around your wrist.\n");
    this_player()->raise_magic_aptitude(1);
    this_player()->raise_strength(-1);
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
    worn_by->raise_magic_aptitude(-1);
    worn_by->raise_strength(1);
    worn_by = 0;
    worn = 0;
    return 1;
}

drop(silently) {
  if(worn) {
    call_other(worn_by, "stop_wearing", name);
    this_player()->raise_magic_aptitude(-1);
    this_player()->raise_strength(1);
  }
  worn = 0;
  worn_by = 0;
  if(!silently)
    tell_object(environment(this_object()),"You drop your worn armor.\n"
);
  return 0;
}

