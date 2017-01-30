inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Hallway";
  long_desc = 
   "You are in a hallway.\n";
  dest_dir = ({"/players/bastion/guild/arena", "north",
               "/players/bastion/guild/gym", "east",
               "/players/bastion/guild/jarvis_entry", "south",
               "/players/bastion/guild/spectator", "west",
               "/players/bastion/guild/jarvis_hall2", "up",
               "/players/bastion/guild/jarvis_hall1", "down"});
  }
}
