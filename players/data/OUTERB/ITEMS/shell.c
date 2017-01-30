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
  set_id("shell");
  set_short(HIW+"a piece of shell"+NORM);
  set_long(
 "This is a piece of shell from a fallen gripper. Its\n"+
 "hard yet durable making it excelent for use in making\n"+
 "weapons or armor. It could be 'bartered' to the right person.\n");
  
  set_weight(1);
  set_value(50);
}

init() {
  add_action("barter","barter");
}

barter(str) {
  if(id(str)) {
    if(present("figure",environment(this_player()))) {
      write("The figure takes the shell from you.\n"+
			"The Figure hisses: Whaaat sshhhhaabyyyyy quality!\n");  
      this_player()->add_money(200+random(50));
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
    }
  }
  notify_fail("Barter what?\n");
}