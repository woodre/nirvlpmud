inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Courtyard";
  long_desc = 
   "You are in a courtyard. Please beg myste to finish it.\n";
  dest_dir = ({
               "/players/bastion/guild/room/enchantment", "north",
               "/players/bastion/guild/room/post", "northeast",
               "/players/bastion/guild/room/dining", "east",
               "/players/bastion/guild/room/path5", "southeast",
               "/players/bastion/guild/room/path3", "southwest",
               "/players/bastion/guild/room/path4", "northwest" });
  }
}
