/* ***********************************************
 * hide.c
 *
 * Creator - Data
 * 
 * Date of File Completion - 8/25/09
 * 
 *
 * **********************************************/
#include <ansi.h>
#include "/sys/lib.h"
inherit "obj/treasure";

reset(arg) {
  if(arg) 
  return;
  set_id("hide");
  set_short(RED+"Heart Hound Hide"+NORM);
  set_long(
 "This is a piece of heart hound hide. Its hair resembling that of a\n"+
 "deer's. This hide is somewhat valuable to the right person and may\n"+
 "be 'bartered'.\n"
  );
  set_weight(1);
  set_value(50);
}

init() {
  add_action("barter","barter");
}

barter(str) {
  if(id(str)) {
    if(present("figure",environment(this_player()))) {
      write("The Figure hisses: Thhhhaannkssss I nnneeedded thaaaat.\n");
      this_player()->add_money(300+random(100));
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
    }
  }
  notify_fail("What do you wish to barter?\n");
}