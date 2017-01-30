/*
 * Doppleganger guild information room
 * Rumplemintz
 */

#pragma strong_types

inherit "room/room";

void reset(status arg) {
  if (arg)
    return;
  if (!present("board", this_object()))
    move_object(clone_object("/players/guilds/dopplegangers/obj/iboard"),
                this_object());
  if (!present("sign", this_object()))
    move_object(clone_object("/players/guilds/dopplegangers/obj/isign"),
                this_object());
  short_desc = "Dopple Info Room";
  long_desc =
"This is the Doppleganger's information room.  Examine the board and sign\n" +
"to get some information on the new additions to the guild.\n";
  set_light(1);
  dest_dir = ({ "/players/guilds/dopplegangers/room/guildhall", "east" });
}

