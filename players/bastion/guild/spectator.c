inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Spectators' Booth";
  long_desc = 
   "You can watch combatants in the arena here.\n";
  dest_dir = ({"/players/bastion/guild/jarvis_hall", "east"});
  }
}
