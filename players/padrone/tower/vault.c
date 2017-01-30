/*
 * vault.c
 * Recoded by Rumplemintz
 */

/* Note, money is not put here, but in the walking castle cell */

inherit "room/room";

object thief1, thief2, lawbringer;

void put_back_lawbringer(object lb);
void check_for_players();

void
reset(status arg)
{
  room::reset(arg);
  if (check_for_players())
    return;
  if(!thief1)
  {
    thief1 = clone_object("/players/padrone/tower/npc/v_thief");
    move_object(thief1, this_object());
  }
  if (!thief2)
  {
    thief2 = clone_object("/players/padrone/tower/npc/v_thief2");
    move_object(thief2, this_object());
  }
  if (!lawbringer)
  {
    lawbringer = clone_object("/players/padrone/obj/lawbringer");
    if (thief2)
      move_object(lawbringer, thief2);
    else if (thief1)
      move_object(lawbringer, thief1);
    else
      move_object(lawbringer, this_object());
  }
  if (arg)
    return;
  short_desc = "Treasury Vault";
  long_desc = "This is the vault in the treasury in Padrone's Castle.\n"+
              "The walls are made of steel, and to the south a steel door leads out.\n"+
              "The floor has been engraved with anti-teleport runes.\n"+
              "But despite these precautions, and the fierce guards outside,\n"+
              "criminals have managed to sneak in to steal the contents.\n";
  dest_dir = ({
    "/players/padrone/tower/treasury", "south",
  });
}

void
init()
{
  room::init();
  log_file("padrone", ctime(time()) + ": " + this_player()->query_name() +
           " entered the (stationary) vault.\n");
}

string
realm()
{
  return "NT";
}

object
return_lawbringer()
{
  return lawbringer;
}

status
check_for_players()
{
  object obj, junk;
  status found;
  
  found = 0;
  obj = first_inventory(this_object());
  while (obj)
  {
    if (living(obj) && !obj->query_npc())
    {
      tell_object(obj, "Suddenly, you get a feeling that no new treasure\n"+
                       "will be put in the vault as long as you are here...\n");
      found = 1;
    }
    obj = next_inventory(obj);
  }
  junk = clone_object("obj/treasure");
  move_object(junk, "/players/padrone/tower/rambo_room");
  obj = first_inventory(environment(junk));
  destruct(junk);
  while (obj)
  {
    if (living(obj) && !obj->query_npc())
    {
      tell_object(obj, "Suddenly, you get a feeling that no new treasure\n"+
                       "will be put in the vault as long as you are here...\n");
      found = 1;
    }
    obj = next_inventory(obj);
  }
  return found;
}

void
put_back_lawbringer(object lb)
{
  if (lb != lawbringer)
    /* Not the real Lawbringer! */
    move_object(lb, "/players/padrone/store");
  else if (thief2 && living(thief2) && present(thief2))
    /* Yes, ignore any weight limits, he can carry everything */
    move_object(lb, thief2);
  else if (thief1 && living(thief1) && present(thief1))
    move_object(lb, thief1);
  else
    /* Yes, just put it on the floor */
    move_object(lb, this_object());
}
