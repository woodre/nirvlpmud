inherit "obj/armor";
#include <ansi.h>

reset(arg)
{
  if(arg) return;
  set_name("ears");
  set_alias("bunny ears");
  set_short(HIY+"Easter "+HIG+"Bunny "+HIC+"Ears"+NORM);
  set_long("A pair of "+HIM+"pink "+NORM+"and "+HIB+"blue "+NORM+"bunny ears.\n"+
    "Maybe you can wiggle them.\n");
  set_type("other");
  set_ac(0);
  set_weight(1);
  set_value(0);
}

void init()
{
  ::init();
  add_action("cmd_wiggle", "wiggle");
}

int cmd_wiggle(string str)
{
    if(!str)
  {
    notify_fail("Wiggle what?\n");
    return 0;
  }
    if(str != "ears")
  {
    notify_fail("You can only \"wiggle\" the \"ears\".\n");
    return 0;
  }

  write(HIB+"You wiggle your bunny ears!\n"+NORM);
  say(HIM+(string)this_player()->query_name()+" wiggles their bunny ears!\n"+NORM);

  return 1;
}
