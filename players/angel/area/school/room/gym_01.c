/*                                                                              *
 *      File:             /players/angel/area/school/room/gym_01.c              *
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

#include <ansi.h>

inherit "room/room";
int x;

reset(arg)
{
  ::reset(arg);
  if( !present("teacher", this_object()) )
    move_object(clone_object("/players/angel/area/school/npc/gym_teacher_01.c"), this_object());  
  if( !present("student", this_object()) )
  {
    for(x=0; x<5; x++)
    {
    move_object(clone_object("/players/angel/area/school/npc/gym_student_01.c"), this_object());
    }
}
  if(arg) return;
  set_light(1);
  short_desc = "gym";
  long_desc =
"   Students play sports for PE such as hockey, basketball, volleyball\n\
and handball. Students also perform plays in the gym. They have Friday\n\
Night Lives where people have sleep-over's in the gym. The gym also\n\
servers as a cafeteria.\n";

  items =
  ({
    "basketball goals",
    "They features a 44 inch fan shaped backboard made of durable eco composite\n\
material, telescoping lift system that adjusts the height of your rim\n\
and more",
    "floor",
    "You see a hard wood floor, it is very shiny",
    "gym",
    "The gym has shiny hardwood floors. The lunch tables pop up and are along\n\
the wall. There is a stage at the front and a storage room for the equipment",
    "friday night lives",
    "When the students sleep over and play games. Help to keep them off the streets",
    "tables",
    "They are stored along the wall till lunch time",
    "stage",
    "A typical school stage",
    "storage room",
    "A dark room where the equipment is keep",
    "equipment",
    "Balls, bats, gloves, racquet's, and the like",
  });
  dest_dir =
  ({
    "/players/angel/area/school/room/school_hall_04.c", "southeast",
  });
}