#define tpn this_player()->query_name()
inherit "obj/treasure";
reset(arg) {
  if(arg) return;
set_id("note");
set_short("A note");
set_long(
	"This old parchment note has been buried for a long time and\n"+
	"is partially decomposed but it looks like you just might be\n"+
	"able to read enough of it to figure it out.\n");
	set_weight(1);
    set_value(10);
}

init() {
  ::init();
  add_action("read","read");
}

read(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "note") {
  say(tpn+" looks at the old paper he found..\n");
  write("You tip the note toward the light and read.....\n\n");
  write("Help!.....Please!....\n");
  write("The gator bit it off...  The doctor in Fiendsville saved\n");
  write("it and now I need it back.  I'll reward anyone who will\n");
  write("remand my hand back to me in any condition..\n");
  write("                         signed.... C.H.\n");
  destruct(this_object());
  return 1; }
}
