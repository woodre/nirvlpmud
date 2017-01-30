
inherit "room/room";

reset(arg) {
  if(!arg) {

    set_light(1);
    short_desc = "Virtual Reality";
    long_desc = "You have entered another area in the virtual world of elof.\n"+
             "Here you hope to find Keivjam.  When you do, KILL HIM\n"+
             "Not that it'll be easy, but if you don't the mud shall\n"+
             "lag to an unspeakable level.\n";

    dest_dir = ( {
            "players/lew/elof/vir_wrld14", "north",
            "players/lew/elof/vir_wrld18", "east",
             "players/lew/elof/vir_wrld8", "west",
             "players/lew/elof/vir_wrld12", "south",
              } );
    }
}
init() {
  ::init();


    add_action("search", "search");
    add_action("link", "link");
}
search() {
   if(!present("link", this_player())) {
   write("You must kill keiver before he laggs the world.\n");
   return 1; }
   write("You find a link to the outside world. Becareful,"+
         "There is still someone on the consol, and i am sure\n"+
         "he is quite pissed right now.\n");
    return 1;
}
link() {
   if(!present("link", this_player())) {
   write("You must have killed Keivjam in order to link to.\n"+
         "the outside world.\n");
   return 1; }
   move_object(this_player(), "players/lew/stuart");
   call_other(this_player(), "look");
   return 1;
}

/* added by verte 2.10.15 */
long() {
  ::long();
  if(this_player() && present("link", this_player()))
  if(this_player() && this_player()->query_attrib("int") > random(40)) {
    write("There is a shimmering in reality here.\n");
}
}
