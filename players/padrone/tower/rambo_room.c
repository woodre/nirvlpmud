/*
 * rambo_room.c
 * New rambo_room with the 3 rambo's in it
 */

inherit "room/room";

object rambo1, rambo2, rambo3, rkey;

void throw_out_players();

void
reset(status arg)
{
  room::reset(arg);
  if (!rambo1)
  {
    rambo1 = clone_object("/players/padrone/tower/npc/rambo.c");
    rambo1->set_movie(1);
    move_object(rambo1, this_object());
  }
  if (!rambo2)
  {
    rambo2 = clone_object("/players/padrone/tower/npc/rambo");
    rambo2->set_movie(2);
    move_object(rambo2, this_object());
  }
  if (!rambo3)
  {
    rambo3 = clone_object("/players/padrone/tower/npc/rambo");
    rambo3->set_movie(3);
    rkey = clone_object("/obj/key");
    rkey->set_type("maximum-security");
    rkey->set_code("vaultdoor");
    move_object(rkey, rambo3);
    move_object(rambo3, this_object());
  }
  if (arg)
    return;
  throw_out_players();
  short_desc = "Rambo room in the treasury";
  long_desc = "This is the Castle's treasury.\n"+
              "Over the years, many of the riches of the world have been collected here.\n"+
              "In his youth, the Wizard travelled the world and collected numerous fantastic\n"+
              "and valuable items, and since he retired from his adventuring and settled down\n"+
              "in this comfortable castle, consultation fees and royalties have contributed\n"+
              "even more to his fortune.\n"+
              "The treasure is stored in the vault, north of this room.\n";
  dest_dir = ({
    "/players/padrone/tower/treasury", "north",
    "/players/padrone/tower/hall", "south",
  });
}

void
throw_out_players()
{
  object obj, this_obj;
  obj = first_inventory(this_object());
  while (obj)
  {
    this_obj = obj;
    obj = next_inventory(obj);
    if (living(this_obj) && !this_obj->query_npc())
    {
      tell_object(this_obj, "Suddenly, you have a feeling of disorientation.\n");
      this_obj->move_player("out#/players/padrone/tower/hall");
    }
  }
}

void
init()
{
  room::init();
  add_action("rambo_block", "north");
}

status
rambo_block()
{
  if(rambo1 && present(rambo1, this_object()))
  {
    write("Rambo I bars the way.\n");
    return 1;
  }
  if (rambo2 && present(rambo2, this_object()))
  {
    write("Rambo II bars the way.\n");
    return 1;
  }
  if (rambo3 && present(rambo3, this_object()))
  {
    write("Rambo III bars the way.\n");
    return 1;
  }
  return 0;
}
