inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Jarvis Hall";
  long_desc = 
   "You stand before Jarvis Hall\n";
  dest_dir = ({"/players/bastion/guild/jarvis_entry", "north",
               "/players/bastion/guild/courtyard", "south"});
  }
}
