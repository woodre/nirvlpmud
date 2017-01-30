inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Demonology Department";
  long_desc = 
   "You are in front of the demonology department.\n";
  dest_dir = ({"/players/bastion/guild/court2", "east",
               "/players/bastion/guild/room/demonology2", "west"});
  }
}
