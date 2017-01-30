/*
 *      File:                 /players/star/rooms/playground.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Notes:
 *      Change History:
 */

#include <ansi.h>
int X;

inherit "/room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "The Overlook's Playground";
  long_desc =
  "   The area inside the playground fence is covered in wood chips.  In\n"+
  "one corner is a tall slide, and on the valley side of the fence there\n"+
  "is a large swing set.  There is a large pipe for crawling through in\n"+
  "the center of the playground.  The doll house is a perfect replica of\n"+
  "the hotel and is hinged so that it can be opened.  Beyond the fence on\n"+
  "the south side of the play area the ground drops off quickly and the\n"+
  "view of the valley below is amazing.\n";

  items =
  ({
    "fence",
    "The chain-link fence surrounding the playground is about four feet\n"+
    "high",
    "chips",
    "The wood chips on the ground are thick enough to soften a child's fall",
    "slide",
    "This is a plain metal slide.  It looks like it needs to be painted,\n"+
    "but you could still play on it if you wanted to",
    "swing set",
    "The swings have been removed from the metal frame for the winter",
    "set",
    "The swings have been removed from the metal frame for the winter",
    "pipe",
    "The large concrete pipe is half buried in the ground, but the openings\n"+
    "are more than large enough to crawl through",
    "house",
    "The large doll house looks just like the hotel and has a latch on one\n"+
    "side and hinges on the other",
    "doll house",
    "The large doll house looks just like the hotel and has a latch on one\n"+
    "side and hinges on the other",
    "view",
    "You can see for miles from up here",
    "valley",
    "The valley is deep and the autumn leaves are brightly colored",
    "leaves",
    "The leaves are shades of "+HIR+"red, "+HIY+"yellow, "+NORM+"and "+YEL+"orange"+NORM,
  });
  dest_dir =
  ({
    "/players/star/rooms/topiary2.c",     "north",
    "/players/star/rooms/pipe.c",         "pipe",
  });
}

void init()
{
  ::init();
  add_action("cmd_play","play");
  add_action("cmd_open","open");
}

int cmd_play(string str)
{
  if(!str)
  {
    notify_fail("Play on what?\n");
    return 0;
  }
  if(str != "slide" && str!= "on slide")
  {
    notify_fail("You can only \"play\" on the \"slide\".\n");
    return 0;
  }

  X = random(10);
  if(X > 8) {
    write("You climb up the slide and start down, but fall off and bump your\n"+
    "nose.  OUCH!\n");

    say((string)this_player()->query_name()+" starts down the slide but falls off and bumps their nose.\n");
      this_player()->add_hp(-3);
  return 1;
  }

  write("You climb the ladder and slide down.  WHEE!\n");
  say((string)this_player()->query_name()+" climbs the ladder and goes down the slide, saying \"WHEE!\"\n");
return 1;
}

int cmd_open(string str)
{
  if(!str)
  {
    notify_fail("Open what?\n");
    return 0;
  }
  if(str != "house" && str != "doll house")
  {
    notify_fail("You can only \"open\" the \"house\".\n");
    return 0;
  }

  write("You open the doll house and notice that all the furniture has been\n"+
    "removed for the winter.  Since there is nothing to play with, you\n"+
    "close it up again.\n");
  say((string)this_player()->query_name()+" opens the doll house, looks inside, and closes it again.\n");

  return 1;
}
