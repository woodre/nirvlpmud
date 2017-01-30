#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
/*This room contains the hunter that will buy back swords from the archangels that are
  killed by players, giving cash in return. A secret way in and out can be found here
  if you ask the hunter. It leads to the entrance and can also be used to bypass the
  guardian in the entryhall.*/

inherit "room/room";

int secret;

reset(arg) {
 if(!present("eghyron")){
   move_object(clone_object("/players/maledicta/ruins/mobs/eghyron.c"), this_object());}
  if(arg) return;
set_light(1);
set_secret(0);
short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"   This room seems to have been some type of old storage chamber. Broken\n"+
"shelves line the cracked and blackened walls.  The roof here is partially\n"+
"collapsed allowing a strong cold wind to whistle through it. An open\n"+
"doorway leads south to the hallway.\n";

items = ({
  "shelves",
  "You're not sure what they used to carry, but they look heavy,\n"+
  "and if not for the fire damage they would have most likely\n"+
  "weathered the damages well. One in particular looks a little\n"+
  "odd",
  "shelf",
  "You look closely and see that it might be movable",
  "walls",
  "As with most of the other areas you have seen so far, the walls\n"+
  "here seem to have been damaged by fire",
  "roof",
  "Upon investigation you notice that only one small corner\n"+
  "of the room has collapsed from damage. It seems well intact\n"+
  "overall",
  
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r3.c","south",
});

}

set_secret(int n){ secret = n; }
query_secret(){ return secret; }

init(){
     ::init();
     add_action("secret_open", "move");
     add_action("secret_go", "enter");
     
}

secret_open(string str){
    if(!str){ write("move what?\n"); return 1; }
      if(str == "shelf"){
        if(this_object()->query_secret() == 0){
	  write("You move the shelf revealing a hole in the wall!\n");
	  this_object()->set_secret(1);
	  return 1;
	  }
	    write("The shelf is already moved!\n");
	    return 1;
	    }
       write("That didn't seem to work.\n");
       return 1;
      }
       	
	
secret_go(string str){
	if(!str){ write("enter what?\n"); return 1; }
	if(str == "hole" && this_object()->query_secret() == 1){
	write("You enter the hole and safely move out of the ruins.\n");		
	say(tpn+" enters a hole.\n");
          move_object(tp, "/players/maledicta/ruins/rooms/r1.c");
          tell_room(environment(tp), tpn+" arrives.\n", ({tp}));
          command("look", tp);
          return 1; }
          if(str == "hole"){
          write("What hole?\n");
          return 1;}
              write("That didn't quite seem to work.\n");
              return 1;
              }
         