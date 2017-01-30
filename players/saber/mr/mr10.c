#define tp this_player()->query_name()

inherit "room/room";
#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

reset(int arg){

if(!present("minotar"))  {
move_object(clone_object("/players/saber/monsters/mr/wizard.c"),this_object());  }

 if(!arg){

 set_light(1);
 short_desc="Cavern of Silence";

 long_desc=
"You stand within a small natural cavern of dark rock.  The cave is lit \n"+
"by a multitude of black candles, placed together to form a mystic rune.\n"+
"The air, though heavy with smoke, is still and lifeless.\n";


items=({
 "cavern","You stand within a small, naturally lit cavern of dark rock",
 "candles","There sure are a lot of them",
 "rune","You think the rune is one of Necromancy",
 "smoke","The smoke is thick, and seems to seep into you",
 });


dest_dir=({
 "/players/saber/mr/mr9.c","out",
           });
  }   }


init(){
 ::init();
  add_action("search","search");
        }


search() {
 write("You find a lot of worthless candles.\n");
 say (tp +" searches the area.\n");
 return 1;  
        }
