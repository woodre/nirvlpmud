inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Courtyard";
  long_desc = 
   "You are in a courtyard.\n";
  dest_dir = ({"/players/bastion/guild/room/gm", "north",
               "/players/bastion/guild/courtyard", "east",
               "/players/bastion/guild/room/security", "south",
               "/players/bastion/guild/room/alchemy", "west",
               "/players/bastion/guild/room/path1", "northwest"});
  }
}
