/* As of right now this is a drop on a Huge fucking mob so it is a really hard to get Bag of holding t
   doesn't save */

inherit "obj/armor";
inherit "obj/container.c";
#include "/players/jareel/define.h"

  reset(arg) {
    ::reset(arg); 
    if (arg) return;
    set_name("cloak");
    set_short(HIK+"Demon Cloak of Holding"+NORM+" ["+HIK+"Demon Forged"+NORM+"]"+NORM);
    set_long(
      "Demon Cloaks are forged from the flesh of a void demon in the rare\n"+
	  "demonic soul fire of an Ember Sembraki Demon. Forging bags is an ancient\n"+
      "practice that turns chaotic flesh into a protective shell that will allow\n"+
      "you can store items in the cloaks dark void.\n"+
      "");
    set_ac(1);
	set_res(1);
    set_type("cloak");
    set_weight(1);
    set_value(50000);
    set_max_weight(1000); /* Major Drop on a Big Mob Item is Soul Bound to a Player that 
	                        is the plan anyway Soul Bound will be (250) if its No save 
							will be (1000) */
	
}
query_save_flag() { return 1; } /*Is NOSAVE Until I get direction on Soulbinding items*/