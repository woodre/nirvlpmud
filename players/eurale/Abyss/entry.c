#define tpn this_player()->query_name()
#define tp this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Lineman Shack";
long_desc =
  "  You have entered an old wooden lineman shack.  It was put here\n"+
  "to provide shelter from the elements while out tending fences.  It\n"+
  "sure has seen better days.  The windows provide light and the only\n"+
  "thing left is an old blanket hung over a rod to provide a makeshift\n"+
  "door for what was once a gear closet.\n";

items = ({
  "windows","Open squares, the glass has been broken out long ago",
  "blanket","A faded red blanket acting as a curtain door to the closet",
  "closet","An old gear or clothes closet that you could probably enter",
});

dest_dir = ({
	"players/eurale/Drygulch/dgs3.c","out",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("enter","enter");
}

enter(str) {
if(!str) { write("Enter what?\n"); return 1; }
if(str == "closet") {
  write("You move the blanket aside and step into the closet.\n");
  say(tpn+" steps behind the blanket.\n");
  tp->move_player("closet#players/eurale/Abyss/entry1.c");
  return 1; }
}
