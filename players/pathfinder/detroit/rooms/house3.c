/* players/pathfinder/detroit/rooms/house */
 
inherit "room/room";
 
int i;
 
reset(arg) {
if(!present("dog")) {
  for(i=0;i<2;i++) {
  move_object(clone_object("players/pathfinder/detroit/monsters/dog"), this_object());
}
    }
 
if(!arg) {
set_light(1);
short_desc = "Ordinary House";
long_desc = "\n"+
"  You enter the house cautiously.  You notice nothing \n"+
"particularly out of the ordinary, but rather a plain ordinary\n"+
"house until you see two silent black shapes lurking around in\n"+
"the shadows.  The suddenly lunge at you as you are overcome by\n"+
"the size and ferocity of these beasts!  You see a \n"+
"shimmer of light in a back room.\n";
dest_dir = ( {
"players/pathfinder/detroit/rooms/backroom", "backroom",
"players/pathfinder/detroit/rooms/hood2", "leave",
});
items = ({
  "drugs", "There are various drugs laying all over the place.",
  "people", "They are in their own little world now that they are high.",
  "druggie", "High off his last hit from the joint, he is upset you busted in.",
  "house", "Nice looking house, with nothing to make it extraordinary.",
        });
}
}
 
init() {
  ::init();
  if(this_player() && (int)this_player()->is_player() &&
     (int)this_player()->query_level() < 10) {
    write("The beasts lunge forward at you as you run for your life!\n");
    say("The beasts lunge at "+capitalize(this_player()->query_name())+" as they run for their life!\n");
    write("After you finish running you find yourself at a\n");
    write("police station, precinct 13.\n");
    call_other(this_player(),"move_player","station#players/pathfinder/detroit/rooms/station");
}
}

