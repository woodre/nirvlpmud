/*
 * cell.c - Redone by Rumplemitnz
 */

inherit "room/room";

object demon, demons_chest, cash;

void throw_out_players();

void
reset(status arg)
{
  room::reset(arg);
  throw_out_players();
  if (!demon)
  {
    demon = clone_object("/players/padrone/walker/npc/chaosdemon");
    demons_chest = clone_object("/obj/chest");
    cash = clone_object("/obj/money");
    cash->set_money(4000);
    move_object(cash, demons_chest);
    move_object(demons_chest, demon);
    move_object(demon, this_object());
  }
  if (arg)
    return;
  short_desc = "Cell inside the walking castle";
  long_desc = "This is an air-tight steel room inside the walking castle.\n"+
              "There are no openings, except for a heavy steel door to the south.\n"+
              "The floor has been engraved with anti-teleport runes, and on the\n"+
              "walls you see spells of imprisonment softly glowing in the dim light.\n";
  dest_dir = ({
    "/players/padrone/walker/vault", "south",
  });
}

void
init()
{
  room::init();
  if (!this_player()->query_npc())
    log_file("padrone", ctime(time()) + ": " + this_player()->query_name() +
             " entered the (walking) cell.\n");
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
      this_obj->move_player("out#/players/padrone/walker/upper_hall");
    }
  }
}

void
put_in_vault(object an_object)
{
  if (demon && present(demon, this_object()) && demons_chest)
    move_object(an_object, demons_chest);
  else
    move_object(an_object, "/players/padrone/store");
}
