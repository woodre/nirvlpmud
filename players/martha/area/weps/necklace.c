#include "/players/martha/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("necklace");
   set_alias("plum");
   set_alias("armor");
   set_short("A Plum Necklace");
   set_long(
      "This necklace has an enormous plum pendant hanging from it.\n"+
      "You think it might help you in battle.\n");
   
   set_ac(0);
   set_type("amulet");  
   set_weight(0);
   set_value(70);
}

init()
{
  add_action("wear_necklace", "wear");
}

wear_necklace(str)
{
  if (str == "necklace" && this_player()->query_exp() > 6000)
  {
    notify_fail("You are too experienced to wear this.\n");
    return 0;
  }
  write("Woot!\n");
  ::wear(str);
  return 1;
}
