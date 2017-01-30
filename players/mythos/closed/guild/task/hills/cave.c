#include "/players/mythos/closed/guild/def.h"
object beast;
inherit "room/room";
reset(arg) {
  if(!present("lilith")) {
  beast = clone_object("/players/mythos/closed/guild/task/hills/dragon.c");
  beast->set_chat_chance(20);
  beast->load_chat("The dragon gazes at you with unblinking eyes of death.\n");
  beast->load_chat("The dragon whispers: Come end my suffering. Kill me.\n");
  move_object(beast,this_object());
  }
  if(!arg) {
  set_light(-2);
    short_desc = "Cave of Deacrom ";
    long_desc =
    "You enter a dark cave.  The walls are covered with\n"+
    "odd runes and patterns.  Before you a large stone sits\n"+
    "and on top lies a large reptilian beast.  Something tells\n"+
    "you to leave now.\n";
  items = ({
    "out","Goes back to the hill",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/task/hills/hills2.c", "back",
  });
} }

realm() { return "NT"; }
