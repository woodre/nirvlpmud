inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Conjuration Department";
  long_desc = 
   "You are in front of the conjuration department.\n";
  dest_dir = ({"/players/bastion/guild/court3", "north",
               "/players/bastion/guild/room/conjuration2", "south"});
  }
}
