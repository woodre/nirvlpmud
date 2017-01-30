/*
 * office.c
 * Secret Police Office recode - Rumplemintz
 */

inherit "room/room";

object captain;

void
reset(status arg)
{
  room::reset(arg);
  if (!captain)
  {
    captain = clone_object("/players/padrone/secret_police/npc/captain");
    move_object(captain, this_object());
  }
  if (arg)
    return;
  short_desc = "The office of the Secret Police captain";
  long_desc = "Hidden behind the false shop, the secret police has an office.\n"+
              "You are now standing in the secret police captain's room, where\n"+
              "he makes decisions about national security sitting behind his big desk.\n"+
              "The walls are covered with impressing portraits of famous secret\n"+
              "police officers and spies, all of them masked to avoid recognition.\n";
  dest_dir = ({
    "/players/padrone/secret_police/hall", "south"
  });
}
