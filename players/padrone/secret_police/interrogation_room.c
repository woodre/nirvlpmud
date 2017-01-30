/*
 * interrogation_room.c - Redone by Rumplemintz
 */

inherit "room/room";

void
reset(status arg)
{
  object obj_1, obj_2, pol1, pol2;

  room::reset(arg);

  if (!present("door"))
  {
    obj_1 = clone_object("/obj/door");
    obj_1->set_dir("west");
    obj_1->set_door_room("players/padrone/secret_police/interrogation_room");
    obj_1->set_type("cell");
    obj_1->set_code("celldoor");
    obj_1->set_door_long("This is a thick and solid door with iron hinges.\n");
    obj_1->set_locked(1);
    obj_1->set_closed(1);
    obj_1->set_can_lock(1);

    obj_2 = clone_object("/obj/door");
    obj_2->set_dir("east");
    obj_2->set_door_room("players/padrone/secret_police/cell");
    obj_2->set_type("cell");
    obj_2->set_code("celldoor");
    obj_2->set_door_long("This is a thick and solid door with iron hinges.\n");

    obj_1->set_door(obj_2);
    obj_2->set_door(obj_1);

    move_object(obj_1, this_object());
    move_object(obj_2, "/players/padrone/secret_police/cell");

    obj_1->set_both_status();
  }
  if (!pol1)
  {
    pol1 = clone_object("/players/padrone/secret_police/npc/policeman");
    pol1->setup_mob(1);
    move_object(pol1, this_object());
  }
  if (!pol2)
  {
    pol2 = clone_object("/players/padrone/secret_police/npc/sergeant");
    move_object(pol2, this_object());
  }

  if (arg)
    return;

  short_desc = "The Secret Police interrogation room";
  long_desc = "You are in the Secret Police interrogation room,\n"+
              "a small ugly room without any windows.\n";
  dest_dir = ({
    "/players/padrone/secret_police/cell", "west",
    "/players/padrone/secret_police/hall", "east",
  });
}
