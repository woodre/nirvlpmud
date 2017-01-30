#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

init() {
        add_action("ww","ww");
}
reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Dark room";
long_desc =
     "   \n"+
"  Meditation room.\n\n";

dest_dir = ({})
;
}
ww() {
  call_other(this_player(), "move_player", "ww#players/francesco/workroom");
  return 1;
  }

