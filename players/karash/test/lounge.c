/*
 *      File:                 /players/star/lounge/lounge.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               12/31/2005
 *      Notes:
 *      Change History:
 */

#include <ansi.h>

inherit "/room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "The Wizards' Lounge";
  long_desc =
  "   This is the wizards' lounge.  The walls are decorated with posters\n"+
  "about motivation and success, as well as the obligatory bulletin board\n"+
  "posted with flyers about regulations and equal opportunity.  There is\n"+
  "a refrigerator in one corner with a water cooler next to it.  A coffee\n"+
  "maker sits on the counter that runs the length of one wall.  A soda\n"+
  "machine hums quietly in another corner.  The large table in the center\n"+
  "of the room is surrounded by mis-matched chairs and covered with a\n"+
  "cheesy table cloth.\n";

  items =
  ({
    "walls",
    "The walls are white, but look like they haven't been painted in some\n"+
    "time",
    "posters",
    "The posters have all kinds of cheesy motivational phrases on them",
    "The bulletin board contains the notices everyone should read, but few\n"+
    "ever do",
    "refrigerator",
    "This is quite an old-looking refrigerator",
    "counter",
    "The counter is chipped formica, and is scattered with empty\n"+
    "containers, napkins, paper plates, and other useful lounge-type things",
    "table",
    "The table is large, and a bit wobbly",
    "chairs",
    "The chairs are all different, and most of them have tears in the\n"+
    "cushions",
    "cloth",
    "The table cloth has some kind of faded apple pattern on it",
    "table cloth",
    "The table cloth has some kind of faded apple pattern on it",
  });

  if(!present("soda machine"))
    move_object(clone_object("/players/star/lounge/machine.c"),this_object());
  if(!present("coffee maker"))
    move_object(clone_object("/players/star/lounge/c_maker.c"),this_object());
  if(!present("water cooler"))
    move_object(clone_object("/players/star/lounge/cooler.c"),this_object());
}

void init()
{
  ::init();
  add_action("open", "open");
}

int open(string str)
  {
  if(!str)
  {
    notify_fail("Open what?\n");
    return 0;
  }
  if(str != "refrigerator")
  {
    notify_fail("You can only \"open\" the \"refrigerator\".\n");
    return 0;
  }

  write("You open the refrigerator and the nasty smell just about knocks you\n"+
    "out before you can get it closed again.  Like most lounge\n"+
    "refrigerators, no one apparently ever cleans this one.\n");
  say((string)this_player()->query_name()+" opens the refrigerator, gags, and closes it quickly.\n");

  return 1;
}
