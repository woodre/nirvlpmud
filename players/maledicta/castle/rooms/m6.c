#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define TP this_player()
#define QN query_name()

inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "a small grove of trees";
long_desc =
"  Standing around you are numerous pine trees, their tall trunks and full\n"+
"branches blocking out the view of the mountains and everything around. A\n"+
"wide set of stairs and waist high stone platform stands before you, a pair\n"+
"of huge pillars standing upon it. The path leads out of the circle of trees\n"+
"and back up the hill.\n"; 

items = ({
  "trees",
  "Standing tall and sturdy, these pines encircle the platform before you\n"+
  "like woodland guardians",
  "mountains",
  "You can't see them from here, with the tall pines blocking the view",
  "stairs",
  "Made of stone, they are deep and in good shape",
  "platform",
  "Standing about waist high, it is made of stone and is huge",
  "pillars",
  "These pillars are remarkable. They stand nearly as tall as the huge pines\n"+
  "that encircle the grove and their girth is that of at least six men. Looking\n"+
  "carefully at them you notice several runes covering the base of each. They\n"+
  "stand apart by ten feet",
  "path",
  "A stone path that leads out of the grove",
  "hill",
  "You are unable to see it from here", 
  "runes",
  "You look carefully at them, and decide they might be readable",
  });

dest_dir = ({
  "/players/maledicta/castle/rooms/m4.c","out",
  });
}

init(){
   ::init();
   add_action("read_runes", "read");
   add_action("invoke_it", "invoke");
   }
   
 read_runes(string str){
if(!str){ write("Read what?\n"); return 1; }
if(str == "runes"){
	write("You begin to try and translate the runes...\n");
	call_out("finish_read", 3, this_player());
        }
else{
write("You can't read that!\n");
return 1;
    }
return 1;
}  

finish_read(object ob){
if(!present(ob)){ return 1; }	
	tell_object(ob,
	"You find that you can now 'invoke runes', using them as\n"+
	"a portal of some sort.\n");
	    }

invoke_it(string str){

if(!str){ write("invoke what?\n"); return 1; }	
   if(str == "runes"){

write(
" The pillars shimmer, energy begins to criss-cross between them....\n");
write(""+HIY+"             _________             _________\n");
write("             |       |             |       |\n");
write("             |       |             |       |\n");
write("             '| ||| |'             '| ||| |'\n");
write("              | ||| |///////////////| ||| |\n"); 
write("              | ||| |///////////////| ||| |\n");
write("              | ||| |///////////////| ||| |\n");
write("              | ||| |///////////////| ||| |\n");
write("              | ||| |///////////////| ||| |\n");
write("              | ||| |///////////////| ||| |\n");
write("              | ||| |///////////////| ||| |\n");
write("              | ||| |///////////////| ||| |\n");
write("              | ||| |///////////////| ||| |\n");
write("              | ||| |///////////////| ||| |\n");
write("             _|_____|_............._|_____|_"+NORM+"\n\n");
write("You step through and....\n\n");     	
    	write("      Find yourself elsewhere.....\n\n");
    	say(tpn+" disappears suddenly.\n");
          move_object(tp, "/players/maledicta/ruins/rooms/r1.c");
          tell_room(environment(tp), tpn+" arrives.\n", ({tp}));
          command("look", tp);
          return 1;
        }
write("invoke what?\n");   
return 1;
}              	
