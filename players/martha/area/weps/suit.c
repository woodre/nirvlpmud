#include "/players/martha/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("suit");
   set_alias("armor");
   set_short("Candy Suit");
   set_long(
      "This candy suit may protect you in battle.\n");
   
   set_ac(2);
   set_type("armor");  
   set_weight(1);
   set_value(100);
}

init()
{
  add_action("wear_suit", "wear");
}

wear_suit(str)
{
  if (str == "suit" && this_player()->query_exp() > 6000)
  {
    notify_fail("You are too experienced to wear this.\n");
    return 0;
  }
  write("Woot!\n");
  ::wear(str);
  return 1;
}
