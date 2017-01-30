#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
string msgout;

init() {
        add_action("ww","ww");
}
reset(arg) {
  if(arg) return;

msgout = " ";


set_light(1);

short_desc = "In a tree" ;
long_desc =
     "   \n"+
     "    The branch of a tree fitted with a love seat.\n\n",

/* dest_dir = ({
   "/players/francesco/workroom.c","do",
   "/players/francesco/workroom.c","not",
   "/players/francesco/workroom.c","disturb",

}); */
dest_dir = ({
   "/players/francesco/workroom.c","Ki_ss_ing",



});
}
ww() {
  call_other(this_player(), "move_player", "ww#players/francesco/workroom");
  return 1;
  }

