#define tp this_player()->query_name()

inherit "room/room";

reset(int arg){
 if(!arg){

set_light(0);
short_desc = "The ice mines";
long_desc=
 "You stand within a cold, narrow ice tunnel.\n"+
 "The passage walls are merely packed snow, and\n"+
 "the ceiling appears to be drippingly unstable.\n";

items=({
 "tunnel","You're in a tunnel",
 "walls","The walls are merely packed ice",
 "ceiling","The ceiling is dripping.  That don't look too stable",
 });

  dest_dir=({
 "/players/saber/closed/quest/ice/x9.c","north",
 "/players/saber/closed/quest/ice/x11.c","south",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("out_of_here","northeast");
  add_action("out_of_here","ne");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

out_of_here()  {
  write("\nYou take the hidden trail to the north east.\n"+
     "\nThe ice is very slick...in fact...\n"+
     "\n\nYou slide down the ice into a pit!\n\n");
this_player()->move_player("into the ice#players/saber/closed/quest/ice/final.c");
return 1;
        }
