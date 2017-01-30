#include "/players/martha/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("shoes");
   set_alias("armor");
   set_short("Granny Shoes");
   set_long(
      "These shoes look like something your gramma would wear!\n"+
      "Maybe you should try them on?\n");
   
   set_ac(0);
   set_type("boots");  
   set_weight(0);
   set_value(58);
}

init()
{
  add_action("wear_shoes", "wear");
}

wear_shoes(str)
{
  if (str == "shoes" && this_player()->query_exp() > 6000)
  {
    notify_fail("You are too experienced to wear these.\n");
    return 0;
  }
  write("Woot!\n");
  ::wear(str);
  return 1;
}
