inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Hallway";
  long_desc = 
   "You are inside the administrative building. The bursar is northeast. The\n"+
   "registrar is southwest.\n";
  dest_dir = ({"/players/bastion/guild/room/admin_office", "northwest",
               "/players/bastion/guild/room/bursar", "northeast",
               "/players/bastion/guild/room/admin", "southeast",
               "/players/bastion/guild/room/registrar", "southwest"});
  }
}
