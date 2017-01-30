inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Astrology Department";
  long_desc = 
   "You are in front of the astrology department.\n";
  dest_dir = ({"/players/bastion/guild/court3", "west",
               "/players/bastion/guild/room/astrology2", "east"});
  }
}
