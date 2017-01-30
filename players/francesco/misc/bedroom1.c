#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

init() {
        add_action("ww","ww");
}
reset(arg) {
  if(arg) return;



set_light(1);

short_desc = "Francesco's bedroom" ;
long_desc =
     "   \n"+
     "    Of course..... nothing else than a bed in this room.\n\n",

/* dest_dir = ({
   "/players/francesco/workroom.c","do",
   "/players/francesco/workroom.c","not",
   "/players/francesco/workroom.c","disturb",

}); */
dest_dir = ({
   "/players/francesco/workroom.c","Do_not_disturb",



});
}
ww() {
  call_other(this_player(), "move_player", "ww#players/francesco/workroom");
  return 1;
  }

