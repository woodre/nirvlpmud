inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Courtyard";
  long_desc = 
   "You are in a courtyard.\n";
  dest_dir = ({"/players/bastion/guild/room/necromancy", "north",
               "/players/bastion/guild/room/path3", "northeast",
               "/players/bastion/guild/room/astrology", "east",
               "/players/bastion/guild/room/conjuration", "south",
               "/players/bastion/guild/courtyard", "west"});
  }
}
