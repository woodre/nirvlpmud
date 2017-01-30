#define tp this_player()->query_name()

inherit "room/room";
#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

int gem, number, CALL;

reset(int arg){

  CALL = 0;

if(!present("drake"))  {
  number = random(3) + 2;
  for(gem = 0; gem < number; gem++)  { 
  move_object(clone_object("/players/saber/monsters/mr/youngdrake.c"),this_object()); 
   }
   }
   
/*
if(!present("egg"))  {
  number = random(10);
  if(number > 7) number = 2; else number = 1;
  
  for(gem = 0; gem < number; gem++)  { 

  move_object(clone_object("/players/saber/stuff/drakeegg.c"),this_object()); 
   }
   }
*/


 if(!arg){

 set_light(3);
 short_desc="In the Sun";

 long_desc="\n"+HIR+
"                  ~   ~   ~   F   I   R   E   ~   ~   ~"+NORM+"\n\n"+
"You float within the fires of the sun, sizzling and steaming in the \n"+
"inferno of coruscating liquid flame chaotically swirling around you.\n\n";


items=({
 "sun","You stand within the fires of the sun - good think you wear the sun cloak!\n"+
       "By the way, you shouldn't stare into the sun...\n"+
       "But since you did, it appears that there is somebody futher in there.\n"+
       "You can try to < call > to it if you wish",
 "fire","You stand within the fires of the sun - good think you wear the sun cloak!\n"+
       "By the way, you shouldn't stare into the sun...\n"+
       "But since you did, it appears that there is somebody futher in there.\n"+
       "You can try to < call > to it if you wish",
 "liquid","You stand within the fires of the sun - good think you wear the sun cloak!\n"+
       "By the way, you shouldn't stare into the sun...\n"+
       "But since you did, it appears that there is somebody futher in there.\n"+
       "You can try to < call > to it if you wish",
 });


dest_dir=({
 "/players/saber/mr/mr3.c","down",
           });
  }   }


init(){
 ::init();
  add_action("search","search");
  add_action("down","d");
  add_action("down","down");
  add_action("call","call");
        }


down()  {
 say(tp+" rotates into a head dive.\n"+
     "You watch as "+tp+" falls from sight...\n");
 write("You rotate your body into a head dive and go\n\n"+
    "    Down\n\n"+
    "           dOwn\n\n"+
    "                  doWn\n\n"+
    "                         dowN\n\n");
call_other(this_player(), "move_player", "down#players/saber/mr/mr3.c");
return 1;
      }

call()  {
if(CALL == 1) { write("Nothing happens.\n"); return 1; }
say(tp+" looks further into the sun and yells \"Hay you!\"\n");
write("You look further into the sun and yell \"Hay you!\"\n");
tell_room(environment(this_player()), "\nSomething steps out of the inner core of the sun.\n\n");
move_object(clone_object("/players/saber/monsters/mr/dude.c"), this_object());
CALL = 1;
return 1;
      }

search() {
 write("You think you see something further into the sun.  You may wish to look at the sun.\n");
 say (tp +" searches the area.\n");
 return 1;  
        }
