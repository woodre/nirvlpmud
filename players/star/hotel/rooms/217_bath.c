/*
 *      File:                 /players/star/hotel/rooms/217_bath.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               03/16/2006
 *      Notes:
 *      Change History:
 */

#include <ansi.h>
#include </players/star/defs.h>

inherit "/room/room";

/* Global Variables */
status open;

reset(arg)
{
  ::reset(arg);
  open = 0; /* This should happen every reset */
  if(arg) return;
  set_light(1);
  short_desc = "217's Bathroom";
  long_desc =
    "   The tiles, sink, and toilet in this bathroom are absolutely\n"+
    "gleaming.  The Overlook must employ a first rate housekeeping staff.\n"+
    "But in this room they missed something.  The bathmat is still in front\n"+
    "of the tub, and it is wet.  It sounds like something is dripping from\n"+
    "behind the shower curtain as well.\n";

  items =
  ({
    "tiles",
    "The tiles are light blue, and sparkling clean",
    "sink",
    "The sink is white, and so clean it almost hurts your eyes to look at",
    "toilet",
    "The toilet is white and shining clean",
    "bathmat",
    "The bathmat is blue, crumpled, wet, and should have been removed after\n"+
    "the last guest checked out",
    "tub",
    "The tub is white, and though the outside is clean there is something\n"+
    "odd about it.  There seems to be a shadow behind the shower curtain",
    "curtain",
    "The shower curtain is blue, and is moving slightly in and out.  It\n"+
    "looks like there is a shadowy form reclining in the tub behind it.\n"+
    "Maybe you should pull the curtain back and look",
    "shower curtain",
    "The shower curtain is blue, and is moving slightly in and out.  It\n"+
    "looks like there is a shadowy form reclining in the tub behind it.\n"+
    "Maybe you should pull the curtain back and look",
  });
  dest_dir =
  ({
    HOTEL+"rooms/217.c",     "out",
  });
}

void init()
{
  ::init();
  add_action("cmd_pull", "pull");
}

int cmd_pull(string str)
{
  if(!str)
  {
    notify_fail("Pull what?\n");
    return 0;
  }
  if(str != "curtain" && str != "shower curtain")
  {
    notify_fail("You can only \"pull\" the \"curtain\".\n");
    return 0;
  }

  if (!open)
  {
    object ob;

    write("You pull back the shower curtain and see a corpse floating in the\n"+
      "water.  It stands up, sloshing the water over the edges of the tub, and\n"+
      "reaches out its hands toward your neck.\n");
    say((string)this_player()->query_name()+" pulls back the shower curtain and a corpse gets out of the\n"+
      "tub and attacks them!\n");
    ob = clone_object(HOTEL+"npcs/corpse.c");
    move_object(ob, this_object());
    this_player()->attacked_by(ob);
    open = 1;
    return 1;
  }

  if (open)
  {
    write("You open the shower curtain and see nothing.  The tub looks a little\n"+
      "damp, which is certainly odd, but the shadow you thought you saw must\n"+
      "have been a trick of the light.\n");
    say((string)this_player()->query_name()+" opens the shower curtain to reveal an empty tub.\n");
    return 1;
  }
}
