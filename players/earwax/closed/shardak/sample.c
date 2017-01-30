/* A sample of how to do a room that sends shards to one destination, others
 * random destinations
*/

inherit "/room/room.c";

/* Global Variables */
string *bad_exits; /* an array of all the nasty places to send people */

void reset(status arg) {

  if (arg)
    return;

  set_light(1);
  bad_exits = ({ "/room/void", "/room/church", "/players/linus/workroom" });
}

short() {
  return "Sample Room";
}

long() {
  write("This is a sample portal room, fear it!\n");
}

int exit_function(string arg) {

  string dest;

  if (!present("shardak_mark",this_player())) {
    dest = bad_exits[random(3)];
    write("The portals just don't seem to work right for you.\n");
  }
  else {
    string cmd;

    cmd = query_verb();

    switch(cmd) {
      case "north" : dest = "/room/green"; break;
      case "east"  : dest = "/players/catwoman/lockers"; break;
      default      : dest = "/room/shop";
    }

    write("You step into the portals...\n");
  }

  move_object(this_player(),dest); /* should be silent move with this func */
  return 1;
}

void init() {
  add_action("exit_function","west");
  add_action("exit_function","north");
  add_action("exit_function","east");
}
