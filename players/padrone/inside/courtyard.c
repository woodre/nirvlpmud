/*
 * courtyard.c
 * Recoded because other one was just hard to read
 * -- Rumplemintz
 */

inherit "room/room";

object billy, sam, sign;

void populate();

void
reset(status arg)
{
  room::reset(arg);
  populate();

  if (arg)
    return;
  short_desc = "The courtyard";
  long_desc = "You are standing in the courtyard of the Castle of Padrone,\n"+
              "a stronghold of Law, Order and Balance.\n"+
              "North lies the gate that leads out of the Castle,\n"+
              "and the main entrance is to the south.\n" +
              "Some local agencies have opened offices here.\n";
  set_light(1);
  dest_dir = ({
    "/players/padrone/inside/gate_room", "north",
    "/players/padrone/inside/main_hall", "south",
    "/players/padrone/inside/sheriffs_office", "east",
    "/players/padrone/inside/antonios", "west",
    "/players/padrone/inside/elizas_office", "northwest",
    "/players/padrone/inside/empty_room", "northeast",
    "/players/padrone/inside/surgeons_room", "southwest",
    "/players/padrone/inside/pmf_office", "southeast",
  });
}

void
populate()
{
  if (!billy || !living(billy))
  {
    billy = clone_object("/players/padrone/inside/npc/cy_billy");
    move_object(billy, this_object());
  }
  if (!sam || !living(sam))
  {
    sam = clone_object("/players/padrone/inside/npc/cy_sam");
    move_object(sam, this_object());
  }
  if (!sign || !present("sign", this_object()))
  {
    sign = clone_object("/players/padrone/obj/thing");
    sign->set_name("sign");
    sign->set_alias("roadsign");
    sign->set_short("In the middle of the yard, a sign points out directions");
    sign->set_read_file("/players/padrone/inside/courtyard_sign.txt");
    sign->set_can_get(0);
    move_object(sign, this_object());
  }
}
