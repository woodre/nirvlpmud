
#define NAME this_player()->query_name()

int gate_open;
inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Courtyard";
  long_desc = 
   "You are in a large courtyard. Ahead of you is a building which reads\n" +
   "\"Hall of Training.\" Strange plants grow between the cobbles, and\n" +
   "you swear you see an ant wearing sunglasses. The gates to the Guild\n" +
   "lie south.\n";
  items = ({"hall",
             "You hear the sounds of voices and muffled explosions",
            "courtyard",
            "Hmm, perhaps these AREN'T real cobblestones. You don't seem\n" +
            "to see that ant anywhere",
            "gates",
            "You recall this is where you came in",
            "guild",
            "The air seems laden with latent magic"});
  dest_dir = ({"players/bastion/guild/jarvis", "north",
               "players/bastion/guild/court3", "east",
               "players/bastion/antaria/citadel/guild", "south",
               "players/bastion/guild/court1", "west"});
  }
}

init(arg) {
  ::init(arg);
  add_action("south", "south");
}

south() {
  if(!gate_open) {
    tell_room(this_object(), "The gates open before " + NAME + ".\n");
    ("players/bastion/antaria/citadel/guild")->set_gate_open(1);
    tell_room("players/bastion/antaria/citadel/guild", "The gates swing " +
     "open.\n");
    gate_open=1;
    call_out("close_gate", 4);
    return 0;
  }
}

set_gate_open(i) { gate_open=i; }

close_gate() {
  ("players/bastion/antaria/citadel/guild")->close_gate();
}
