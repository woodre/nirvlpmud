/*
  guildent.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(0);
  short_desc=("Black marble hall");
  no_castle_flag=1;
  long_desc="The walls of black room seem to be trying to absorb the light.\n";
  dest_dir=
    ({
      "players/nooneelse/black/guild_hall", "north",
      "/room/eastroad5", "south",
      "players/eurale/VAMPIRES/RMS/lounge","west",
    });
}
