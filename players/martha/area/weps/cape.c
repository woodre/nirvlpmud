#include "/players/martha/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("cape");
   set_alias("armor");
   set_short("Licorice Cape");
   set_long(
      "This dark black licorice cape looks like a tasty\n"+
      "treat, but you should try wearing it.\n");
   
   set_ac(0);
   set_type("cloak");  
   set_weight(0);
   set_value(67);
}

init()
{
  add_action("wear_cape", "wear");
}

wear_cape(str)
{
  if (str == "cape" && this_player()->query_exp() > 6000)
  {
    notify_fail("You are too experienced to wear this.\n");
    return 0;
  }
  write("Woot!\n");
  ::wear(str);
  return 1;
}

