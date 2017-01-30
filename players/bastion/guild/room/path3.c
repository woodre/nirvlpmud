inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Pathway";
  long_desc = 
   "You are on a path between the Necromancy and the Astrology Depts.\n";
  dest_dir = ({"/players/bastion/guild/court4", "northeast",
               "/players/bastion/guild/court3", "southwest"});
  }
}
