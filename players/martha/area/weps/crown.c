#include "/players/martha/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("crown");
   set_alias("armor");
   set_short("Lollipop Crown");
   set_long(
      "This crown is adorned with lollipops.\n"+
      "Maybe you should try it on?\n");
   
   set_ac(0);
   set_type("helmet");  
   set_weight(0);
   set_value(70);
}

init()
{
  add_action("wear_crown", "wear");
}

wear_crown(str)
{
  if (str == "crown" && this_player()->query_exp() > 6000)
  {
    notify_fail("You are too experienced to wear this.\n");
    return 0;
  }
  write("Woot!\n");
  ::wear(str);
  return 1;
}
