/*
 * workroom.c
 * Just a quick room to act as Angmar's workroom.
 * -- Rumplemintz
 */

inherit "room/room";

void
reset(status arg)
{
  room::reset(arg);
  if (arg)
    return;
  short_desc = "Angmar's Monster Lab";
  long_desc = "This is Angmar's workroom. Here is where he creates his creations.\n"+
              "Angmar the Necromancer has long been rumoured to be dead, but\n"+
              "his creations live on.\n";
  dest_dir = ({
    "/players/angmar/castle/inside", "west"
  });
}
