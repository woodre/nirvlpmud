#include "/players/softly/closed/define.h"
#include "/players/softly/point/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/vertebraker/closed/std/room";
int x,z,rod,summoned;


void init()
{
    ::init();
    add_action("new_say", "say");
#ifndef __LDMUD__
    add_action("new_say"); add_xverb("'");
#else
    add_action("new_say", "'", 3);
#endif
    add_action("wave_it", "wave");
}

wave_it(str){
if(!str) return;
if(!present("weird_rod_thing", this_player())) return;

if(present("weird_rod_thing", this_player()) && str == "rod"){
  write("You wave the rod.\n");
  rod = 1;
  return 1;
  }
return;
}

is_softly() { return 1; }

summon_erica(){
  if(!present("erica", this_object())){
  move_object(clone_object("players/softly/point/mobs/erica"),this_object());
  tell_room(this_object(), "erica appears.\n");
  summoned = 1;
  return 1;
  }  
}


new_say(string str){
     string me,it,it2;
   if(!str) return;
    if(str == "erica erica" || str == "erica Erica" || str == "Erica Erica" || str == "Erica erica" ){
      if(rod && !summoned && !present("erica", this_object())){
       summon_erica();
       tell_object(this_player(), "You say: "+str+"\n");
       tell_room(this_object(), this_player()->query_name()+" says: "+str+"\n", ({this_player()}));
       tell_room(this_object(), BOLD+"\n\n   Suddenly lightning flashes...."+BLK+"\n\n\n"+
                                     "            Blackness settles on the sea..."+NORM+BOLD+"\n\n\n"+
                                     "                      Erica appears before you..."+NORM+"\n\n\n\n");
       return 1;
       }
     }
    return;
    }       

reset(arg){
  if(!present("bird")) 
  move_object(clone_object("players/softly/point/mobs/bird.c"),this_object());
  if(!random(2))move_object(clone_object("players/softly/point/mobs/bird.c"),this_object());

 if(arg) return;
set_light(1);
summoned = 0;
rod = 0;
short_desc = "Misty Beach";
long_desc ="  Sand interspersed with sea grass flows between\n"+
           "the northwest forest and the vast sea to the east.\n"+
           "The mist is very warm and dense.  The grey sky and\n"+
           "desolate landscape create a sense of forboding.\n";

items = ({
  "sand", "The pale grey sand stretches to the water's edge",
  "sea","The blue-green sea is vast, flowing as far as the eye can see",
  "mist","The air is white with mist, which hangs heavily over\n"+
         "the sand and the surface of the sea.  It is warm and\n"+
         "dense, surrounding everything like a cloak",
  "sky","The dense mist mixes with the grey sky",
  "landscape","The landscape reveals little life in this isolated place",
  "forest","The forest has many pine and oak trees.  It seems\n"+
           "very old",
  });

dest_dir = ({
  "/players/softly/point/rooms/for17.c","northwest",
  });
}




