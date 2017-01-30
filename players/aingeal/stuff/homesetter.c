#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "/obj/treasure";

reset(arg)
{
	if(arg) return;
	set_id("homesetter");
	set_alias("homesetter");
	set_short("Homesetter");
	set_long("This is Aingeal's login setter.\n");
	set_weight(0);
	set_value(0);
}

drop()
{
	write("You may not drop your homesetter.\n");
	return 1;
}

init()
{
  ::init();
  add_action("homesetter","homesetter");
}


homesetter(str)
{
  if(!str)
  {
    write("Where do you want to login?\n");
    return 1;
  }
  if(str=="church") this_player()->set_home("/room/church.c"); }
  if(str=="home") this_player()->set_home("/players/aingeal/workroom.c"); }
	write("Your login has been set to " + str + ".\n");
	return 1;
}
