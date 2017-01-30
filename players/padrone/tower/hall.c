/*
 * hall.c
 */
 
#include "/obj/door.h"

inherit "room/room";
 
object the_dragon;
status dragon_can_come;
object obj_1, obj_2;  /* For the doors */

void make_dragon();
 
void
reset(status arg)
{
  room::reset(arg);
  if (arg)
    return;
  dragon_can_come = 1;
  if (!present("door"))
  {
    obj_1 = clone_object("obj/door");
    obj_1->set_dir("north");
    obj_1->set_door_room("/players/padrone/tower/hall");
    obj_1->set_type("moderate-security");
    obj_1->set_code("treasurydoor");
    obj_1->set_door_long("This is a stout wooden door, several inches thick.\n"+
                         "There is a small note nailed to it:\n"+
                         "    'Don't go in here. The guards have gone crazy again.'\n");
    obj_1->set_locked(1);
    obj_1->set_closed(1);
    obj_1->set_can_lock(1);

    obj_2 = clone_object("obj/door");
    obj_2->set_dir("south");
    obj_2->set_door_room("/players/padrone/tower/rambo_room");
    obj_2->set_type("moderate-security");
    obj_2->set_code("treasurydoor");
    obj_2->set_door_long("This is a stout wooden door, several inches thick.\n"+
                          "There is a small note nailed to it:\n"+
                          "    'Don't go in here. The guards have gone crazy again.'\n");
    obj_2->set_door(obj_2);
    obj_2->set_door(obj_1);
    move_object(obj_1, this_object());
    move_object(obj_2, "/players/padrone/tower/rambo_room");
    obj_1->set_both_status();
  }
  if (!the_dragon)
    dragon_can_come = 1;
  short_desc = "The tower hall";
  long_desc = "You are in the hall of Padrone's private tower.\n"+
              "This is a big and spacious hall, so the interior of the tower must\n"+
              "have been expanded using magic. Several doors lead to other rooms.\n"+
              "A small ladder leads up to Padrone's private workroom,\n"+
              "and a stone stairway leads down into the tower.\n"+
              "There is a small note on the door leading north.\n";
  items = ({
    "note", "The small note on the north door says:\n"+
            "    'Don't go in here. The guards have gone crazy again.'",
  });
  dest_dir = ({
    "/players/padrone/tower/rambo_room", "north",
    "/players/padrone/tower/bedroom", "south",
    "/players/padrone/tower/lab", "lab",
    "/players/padrone/tower/poolroom", "west",
    "/players/padrone/tower/tower4", "down",
    "/players/padrone/workroom", "up"
  });
}

void
init()
{
  room::init();
  add_action("up_check", "up");
}

status
up_check()
{
  if (the_dragon && present(the_dragon, this_object())
      && ((string)this_player()->query_name() != "Padrone"))
  {
    write("You cannot pass the dragon.\n");
    say(this_player()->query_name()+
        " tries to climb the ladder, but the dragon bars the way.\n");
    return 1;
  }
  else if (dragon_can_come &&
          ((string)this_player()->query_name() != "Padrone"))
  {
    write("As you try to climb the ladder, an alarm sounds!\n");
    say("As " + this_player()->query_name() +
        " tries to climb the ladder, an alarm sounds!\n");
    write("A giant stainless steel dragon shows up to investigate!\n");
    say("A giant stainless steel dragon shows up to investigate!\n");
    make_dragon();
    return 1;
  }
  else
    return 0;
}

void
make_dragon()
{
  the_dragon = clone_object("/players/padrone/tower/npc/t_dragon");
  move_object(the_dragon, this_object());
  dragon_can_come = 0;
}
