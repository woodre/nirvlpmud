#include "/players/martha/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("shield");
   set_alias("armor");
   set_short("Licorice Shield");
   set_long(
      "This dark black licorice shield looks good enough\n"+
      "to nibble, but it will help you in battle.\n");
   
   set_ac(0);
   set_type("shield");  
   set_weight(0);
   set_value(73);
}

init()
{
  add_action("wear_shield", "wear");
}

wear_shield(str)
{
  if (str == "shield" && this_player()->query_exp() > 6000)
  {
    notify_fail("You are too experienced to wear this.\n");
    return 0;
  }
  write("Woot!\n");
  ::wear(str);
  return 1;
}
