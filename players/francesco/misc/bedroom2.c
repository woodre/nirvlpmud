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

short_desc = "Village green";
long_desc =
     "   \n"+
    "  A simple room, with a desk and two chairs at the side.\n"+
    "Francesco uses it for receiving his students and for\n"+
    "talking with his friends.\n\n",
/*
     "    Of course..... nothing else than a bed in this room.\n\n",
*/

dest_dir =({
   "/players/francesco/workroom.c","n",
   "/players/francesco/workroom.c","w",
   "/players/francesco/workroom.c","e",

});
}
ww() {
  call_other(this_player(), "move_player", "ww#players/francesco/workroom");
  return 1;
  }

