inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Administrative Building";
  long_desc = 
   "This is the front of an administrative building.\n";
  dest_dir = ({"/players/bastion/guild/room/admin2", "northwest",
               "/players/bastion/guild/court2", "southeast"});
  }
}
