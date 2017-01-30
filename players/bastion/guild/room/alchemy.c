inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Alchemy Department";
  long_desc = 
   "You are in front of the alchemy department.\n";
  dest_dir = ({"/players/bastion/guild/court1", "east",
               "/players/bastion/guild/room/alchemy2", "west"});
  }
}
