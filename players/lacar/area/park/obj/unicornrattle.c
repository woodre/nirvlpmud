/*
*      File:             /players/lacar/area/park/obj/unicornrattle.c
*      Function:         obj
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2006 Lacar (Carla J Merrill)
*                                All Rights Reserved
*      Source:    	
*      Notes:            area
*      Change History:
*/
inherit "/obj/treasure";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("unicorn rattle");
set_alias("rattle");
set_short("Unicorn Rattle");
set_long("This is a rattle made from a unicorn's horn. It makes\n\
a sound when shaken. The color seems to be fading.\n");
set_value(30);
}

void init()
{
  ::init();
  add_action("shake", "shake");
}

int shake(string str)
  {
  if(!str)
  {
    notify_fail("Shake what?\n");
    return 0;
  }
  if(str != "rattle")
  {
    notify_fail("You can only \"shake\" the \"rattle\".\n");
    return 0;
  }
write("You shake the rattle.\n");
say((string)this_player()->query_name()+"shakes rattle.\n");

  return 1;
}
