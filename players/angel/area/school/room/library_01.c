/*                                                                              *
 *      File:             /players/angel/area/school/room/library_01.c          *
 *      Function:         room                                                  *
 *      Author(s):        Angel@Nirvana                                         *
 *      Copyright:        Copyright (c) 2006 Angel (Josh Hatfield)              *
 *                                All Rights Reserved.                          *
 *      Source:           11/15/06                                              *
 *      Notes:                                                                  *
 *                                                                              *
 *                                                                              *
 *      Change History:                                                         *
 */

inherit "room/room";
int x;

reset(arg)
{
  ::reset(arg);
  if( !present("library student", this_object()) )
    move_object(clone_object("/players/angel/area/school/npc/library_student_01.c"), this_object());
  if( !present("library", this_object()) )
  {
    for(x=0; x<4; x++)
    {
    move_object(clone_object("/players/angel/area/school/npc/library_student_02.c"), this_object());
    }
}
  if(arg) return;
  set_light(1);
  short_desc = "Library";
  long_desc =
"  Westview School has a large and well stocked library of books,\n\
magazines, filmstrips, videos, computer resources and other material.\n\
Students can use the facility during the lunch hour, before classes\n\
in the morning, at times assigned by subject teachers and in study\n\
periods. The library is open from 8:15am until 3:45.\n";

  items =
  ({
    "library",
    "This Library is very large and open.\n\
You feel very comfortable in this room",
    "computer resources",
    "This is the information lab of computers where students can access\n\
electronic encyclopedias",
    "books",
    "Books, magazines, audio-visual resources, equipment and computer\n\
programs all can be identified using the automated program",
    "magazines",
    "Stacks of magazines are organized by title here",
    "avdio-visual resources",
    "TV's, VCR's, Power point machines, and much more equipment can be\n\
found here",
    "equipment",
    "There are many different devices the Librarian uses",
    "computer programs",
    "Educational software to help the students in learning",
    "program",
    "Programs are different types of educational softwear on a cd",
    "resources",
    "A source of information",
    "film strips",
    "They are old educational movies",
    "videos",
    "They are many Educational movies",
  });
  dest_dir =
  ({
    "/players/angel/area/school/room/school_hall_02", "south",
  });
}