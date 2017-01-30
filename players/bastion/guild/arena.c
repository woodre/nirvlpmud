inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Sorcerers' Arena";
  long_desc = 
   "You are in the arena.\n";
  dest_dir = ({"/players/bastion/guild/jarvis_hall", "south"});
  }
}
