inherit "/obj/generic_heal.c";
#include <ansi.h>

/********************************
 4(6 soak/stuff) = 24 total tox
 4(31 + random(40)) = 200 avg heal
   24/200 = .12 = 22 coins/pt healed
   22(124) = 2728 + 2/3(22(40)) = 587
   2728 + 587 = 3315 coins for this heal
   Rounding up to 3350 in shop
*********************************/



void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("Gu");
  add_alias("packet");
  add_alias("gel");
  set_short(BOLD+GRN+"Gu Energy Gel"+NORM);
  set_long(
   "A small packet filled with a lime flavored energy gel.\n"+
   "It doesn't look very appetizing but it is supposed to provide\n"+
   "a quick burst of energy if you 'squeeze' it!\n");
  set_type("shots");
  set_type_single("shot");
  set_msg("You tear open the packet and squirt the gel into your mouth. Ick!\n");
  set_msg2(" tears open a small packet and squirts the gel into their mouth.\n");
  set_empty_msg("");
  add_cmd("squeeze");
  set_heal(31+random(40),31+random(40));
  set_charges(4);
  set_msg_precharges(BOLD+BLK+"["+NORM+BOLD);
  set_msg_postcharges(BLK+"]"+NORM);
  set_soak(3);
  set_stuff(3);
  set_value(200+random(200));
  set_msg_soaked(HIY+"You couldn't possibly eat any more of this junk!\n"+NORM);
  set_msg_stuffed(HIY+"You couldn't possibly eat any more of this junk!\n"+NORM);
}



query_save_flag(){  return 1;  }

