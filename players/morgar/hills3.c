/* 10/11/05 Earwax: Converted to land. */
/* Also converted it to room.c */

inherit "/players/earwax/housing/land.c";
inherit "/room/room.c";

/*
ONE_EXIT("players/morgar/hills","east",
         "Rolling hills",
         "You are in some rolling hills.  The hills continue\n" +
         "to the east.\n", 1)
*/

void reset(status arg) {
  ::reset(arg);
  if (arg) return;

  set_light(1);
  short_desc = "Rolling Hills";
  long_desc = "You are in some rolling hills.  The hills continue to the west";
  dest_dir = ({ "/players/morgar/hills", "west" });

  set_lot_size(6);
  set_realm_name("Rolling Hills");
  set_cost(760000);
  setup_land();
}
