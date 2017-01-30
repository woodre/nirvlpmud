inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Courtyard";
  long_desc = 
   "You are in a courtyard. Please beg myste to finish it.\n";
  dest_dir = ({
               "/players/bastion/guild/room/alteration", "north",
               "/players/bastion/guild/room/path2", "northeast",
               "/players/bastion/guild/room/path1", "southeast",
               "/players/bastion/guild/room/demonology", "west",
               "/players/bastion/guild/room/admin", "northwest" });
  }
}
