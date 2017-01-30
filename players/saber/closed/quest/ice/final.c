#define tp this_player()->query_name()

inherit "room/room";

reset(int arg){
if(!present("ring"))  {
move_object(clone_object("/players/saber/closed/quest/items/ring.c"),this_object());  }
 if(!arg){

set_light(1);
short_desc = "The ice pit";
long_desc=
 "You stand deep within a pit of ice.\n"+
 "There is a portal before you.\n";

items=({
 "pit","You're in a pit",
 "portal","There is a portal before you",
 });

  dest_dir=({
 "/players/saber/tower/tower20+01.c","portal",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("out_of_here","portal");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

out_of_here()  {
write("\nYou step through the portal.\n"+
     "\nYour world fades away.\n"+
     "\nYou see light, and then the world begins to fade in around you.\n"+
     "\nYou are standing on a small trail of ice.\n\n");
this_player()->move_player("through the portal#players/saber/tower/tower20+01.c");
return 1;
        }

realm()  { return 1; }
