#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "West School";
  long_desc =
"  "+HIB+"West School"+NORM+".\n\
  This is the playground area for West School.  Kids play here on a\n\
regular basis.  To the north is the entrance to the school, however\n\
it is under major construction.  The administration is remodeling the\n\
100+ year olds school.  According to posted signs, the building is\n\
being remodeled and asbestos is being removed.\n";

  items =
  ({
	"playground",
	"A large open space with climbing toys for the students to have fun",
	"school",
	"A place where children are educated",
	"building",
	"It's a large two story brick structure",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/emain_05",  "road",
  });
  move_object(clone_object("/players/angel/area/school/npc/playground_student_01.c"), this_object());
  move_object(clone_object("/players/angel/area/school/npc/playground_student_01.c"), this_object());
  move_object(clone_object("/players/angel/area/school/npc/playground_student_01.c"), this_object());
  move_object(clone_object("/players/angel/area/school/npc/playground_student_01.c"), this_object());
  move_object(clone_object("/players/angel/area/school/npc/playground_student_01.c"), this_object());
}