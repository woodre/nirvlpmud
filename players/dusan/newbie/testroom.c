#include <ansi.h>
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
 if(arg) return;
set_light(1);
short_desc = "The Newbie Finals Room";
long_desc =
	"   This is where newbies take their final test before they are sent out \n"+
      "to find their own way in the world.  To one side of the room there is a  \n"+
      "large desk with a stack of papers on it.  Behind the desk is a large black \n"+
      "chalk board with something written on it.  To the other side of the room is \n"+
      "rows of desks and chairs.\n"+
      "You may "+BOLD+"grab exam"+NORM+" to take the Newbie Exam.\n";
      
items = ({
  "desk","A large wooden desk that sits near the wall",
  "papers","A large stack of 'exams' on the desk maybe you could 'grab' one ",
  "board","NEWBIE EXAM DAY HOPE YOU BROUGHT YOUR PENCILS AND KNOW ALL THE HELP FILES",
  "test","The newbie exam sitting on the desk",
  "exam","A small stack of papers stapled together with a lot of questions on it",
  "world","The rest of the mud at large",
  "newbies","You know who you are!!!",
  "desks","Small, uncomfortable wooden desks",
  "chairs","Hard wooden chairs",
});

dest_dir = ({
  "/players/softly/nhall/rooms/n4.c","south",
});

}
init(){
::init();
add_action("cmd_grab","grab"); }
cmd_grab(arg){
 if(present("exam",this_player())){
  notify_fail("You already have an exam!\n");
  return 0; }
  if(!arg){ write("grab what?\n"); return 1; }
  if(arg != "exam"){ write("grab what?\n"); return 1;} 
  move_object(clone_object("/players/dusan/newbie/mexam.c"), this_player()); 
  write("You take a copy of The Newbie Exam.\n"); 
  return 1; }
