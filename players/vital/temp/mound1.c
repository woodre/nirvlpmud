/*
 *      File:                   mound1.c
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 05/13/2004
 *      Notes:
 *      Change History: 06/05/04, 27/09/05 - Rewrote long description [Vital]
 */
#include <ansi.h>

inherit "room/room";    /* inherits room obj */

int             i;

reset(arg)
{
  ::reset(arg);
  if (!present("ulatha"))
  {
    for (i = 1; i < 2; i++)
    {
      move_object(clone_object("/players/hogath/area/mobs/newbie/ulatha"),
        this_object());
      move_object(clone_object("/players/hogath/area/mobs/newbie/fluffy"),
        this_object());
    }
  }     /* monster call */
  if (arg)
    return;
  set_light(1);
  set_short("Living Room");
  set_long("\
  This is the living room. Unlike the doorway, it has wood panel\n\
walls. Inside is a comfortable chair and a long couch. They sit\n\
infront of a large fireplace that runs the length of the south\n\
wall.\n");
/*   short_desc = "Living Room"; /* room short description */
/*   long_desc = */
/*     "     This is the living room.  Unlike the doorway, it has wooden\n" + */
/*     "paneled walls.  Inside a comfortable chair and couch can be seen\n" + */
/*     "in front of a large fireplace runs the length of the south wall.\n" + */
/*     "Within the room you notice a happy gnome with a panting dog at his\n" + */
/*     "feet.\n"; */
  /* long description of room */

  dest_dir =
  ({
    "/players/hogath/area/newbie/mounddr.c", "north", /* exits from room */
    "/players/hogath/area/newbie/mound2.c", "west",
    "/players/hogath/area/newbie/mound3.c", "east",
  });
  items =
  ({
    "chair", "A very comfortable chair.  It looks a little worn though",
    "floor", "A hard wooden floor with a throw rug on it",
    "wall", "Finely made wooden paneling distinguishes this wall",
    "rug", "A finely woven rug with a colorful pattern on it",
    "couch", "A lengthy couch, it looks quite comfy",
    "fireplace", "This soot covered fireplace looks as though it has \n" +
    "seen much use in the recent winter",
    "walls", "The walls are all paneled with some sort of oak wood",
    "doorway", "You see a small room leading out to the north",
    "living room", "It looks like a very relaxing room",
    "room", "A good place to relax and sleep away the afternoon",
  });     /* stuff to look at */
}

init()
{
  ::init();
  add_action("search_me", "search");  /* adds search option to room */
  add_action("cmd_smell", "smell"); /* adds smell command */
  add_action("cmd_listen", "listen"); /* add listen command */
}

cmd_smell(str)
{       /* smell function */
  switch (str)
  {
    case "chair":
      if (present("ulatha"))
      {
        write("Ulatha wouldn't want you to sniff his chair while he is in it.\n");
        break;
      }
      else
      {
        write("Sweat and Body odor come from the chair.\n");
        break;
      }
    case "rug":
    case "floor":
      write("It smells dirty.");
      break;
    case "fireplace":
      write("Burnt wood and soot assail your nostrils.\n");
      break;
    case "couch":
      write("It smells dusty.\n");
      break;
    case "doorway":
      write("Cool air streams through the doorway.\n");
      break;
    case "room":
    case "living room":
    case "wall":
    case "walls":
    default:
      if (!str)
      {
        write("It smells of cinnamon.\n");
        break;
      }
      else
      {
        write("You don't detect any smell from " + str + ".\n");
        break;
      }
  }
  return 1;
}

cmd_listen(str)
{       /* listen function */
  switch (str)
  {
    case "fireplace":
      write("A fire crackles.\n");
      break;
    case "doorway":
      write("Whistling wind can be heard.\n");
      break;
    case "living room":
    case "room":
    default:
      if (!str)
      {
        write("A crackling fire can be heard throughout the room.\n");
        break;
      }
      else
      {
        write("You don't detect any sound from the " + str + ".\n");
        break;
      }
  }
  return 1;
}

search_me(str)
{       /* search function */
  if (!str)
  {
    notify_fail("What are you trying to search?\n");
    return 0;
  }
  write("You furiously search the " + str + " but find nothing.\n");
  return 1;
}
