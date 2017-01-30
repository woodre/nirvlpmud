#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if( !present("volunteer", this_object()) )
    move_object(clone_object("/players/angel/area/school/npc/volunteer_01.c"), this_object()); 
  if(arg) return;
  set_light(1);
  short_desc = "School Entrance";
  long_desc =
"  Huge glass doors open into Northview elementary school. This\n\
is the entrance area to the school and it has a wonderful view of\n\
the area. A sign shows that the Nurse's office is to north and the\n\
main office northwest. To the west is long long hallway that looks\n\
to be 100 yards long.\n";

  items =
  ({
    "glass doors",
    "These doors are huge and they extend to the top of the building",
    "glass",
    "The glass seems clear enough to walk through",
    "doors",
    "The doors swing open with ease. They are made of glass and have\n\
a silver metal trim",
    "sign",
    "This sign hangs from the ceiling. It is made of a hard plastic and\n\
it is illuminated",
    "building",
    "A large brick structure",
    "school",
    "It is a large brick building, with a glass entrance",
    "view",
    "As you look out the Giant glass doors you see a beautiful view of\n\
the lake",
    "offices",
    "From this room there are two office doors that can be seen to the\n\
north and northwest",
    "hallway",
    "This is a very long corridor at least 100 yards",
    "entrance",
    "This room is full of light from the sun light that comes right\n\
in through the glass wall. The tile floor shines bright form the\n\
clear wax coating on the floor. The interior wall are made bricks,\n\
which are painted red and white. The school mascot is painted on\n\
the wall. It is a mural of a Mississenwa Indian.",
  });
  dest_dir =
  ({
	"/players/angel/area/school/room/nurse_office_01",  "north",
    "/players/angel/area/town/room/7thnh",            "south",
    "/players/angel/area/school/room/school_hall_01",   "west",
    "/players/angel/area/school/room/main_office_01",   "northwest",
/*  "/players/angel/area/school/room/airport",          "heli", */
  });
}
/*
init() {
  ::init();
    add_action("south"); add_verb("south");
} 

south() {
    if (call_other(this_player(), "query_level", 0) < 20) {
        write("A strong magic force stops you.\n");
        say(call_other(this_player(), "query_name", 0) +
            " tries to go through the field, but fails.\n");
        return 1;
    }
    write("You wriggle through the force field...\n");
    call_other(this_player(), "move_player", "fly#/players/angel/area/town/room/7thnh.c");
    return 1;
}
*/