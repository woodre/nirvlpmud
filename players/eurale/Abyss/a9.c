#define tpn this_player()->query_name()
#define tp this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "The Abyss";
long_desc =
  "  It is even darker here and more sinister.  The screaming continues\n"+
  "unabated but you can't make out the direction it's coming from.  The\n"+
  "air here is noticably colder as well.  Why this sudden and dramatic\n"+
  "change?  Did you just feel something touch you from behind?\n";

items = ({
});

dest_dir = ({
});

}

init() {
  ::init();
  add_action("west","west");
}

west() {
  tp->move_player("disappears#players/eurale/Abyss/a3.c");
  return 1; }

realm() { return "NT"; }
