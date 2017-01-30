#include "/players/martha/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("gloves");
   set_alias("armor");
   set_short("Candy Stained Gloves");
   set_long(
      "These gloves have gumdrop stains all over them, but they\n"+
      "look like they might help you in battle.\n");
   
   set_ac(0);
   set_type("ring");  
   set_weight(0);
   set_value(65);
}

init()
{
  add_action("wear_gloves", "wear");
}

wear_gloves(str)
{
  if (str == "gloves" && this_player()->query_exp() > 6000)
  {
    notify_fail("You are too experienced to wear these.\n");
    return 0;
  }
  write("Woot!\n");
  ::wear(str);
  return 1;
}
