inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Entryway to Jarvis Hall";
  long_desc = 
   "This is the entryway to Jarvis Hall. Myste has yet to finish it.\n";
  dest_dir = ({"/players/bastion/guild/jarvis_hall", "north",
               "/players/bastion/guild/advance2", "east",
               "/players/bastion/guild/jarvis", "south",
               "/players/bastion/guild/advance", "west"});
  }
}
