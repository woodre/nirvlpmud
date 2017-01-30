/* the guardian can be found here, it is not aggro but will not allow further
   movements into the ruins. */
#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  
 if(!present("guardian")) {
   move_object(clone_object(NPC+"guardian.c"), this_object());
 }    
  if(arg) return;
set_light(-1);

short_desc = RUINS;
long_desc =
"  This is the entryhall of the ruins.  Lying on the blackened floor\n"+
"are piles of stones and a rusted set of shackles. The roof here has\n"+
"collapsed, exposing the storm filled skies beyond. To the east the\n"+
"hallway continues leading into dark shadows.\n";

items = ({
  "shadows",
  "Deep and uninviting, you cannot penetrate the darkness that\n"+
  "fills the hallway",  
  "entryhall",
  "You search your surroundings, noticing the walls here are torn and\n"+
  "blasted as if some unnatural force had thrown its rage against it",
  "floor",
  "You look at the floor carefully and see that it has been torn up\n"+
  "by what looks like possible claw marks. It is also melted and burnt\n"+
  "in multiple places",
  "shackles",
  "An old set of shackles, they seem out of place even in this\n"+
  "mutilated environment",
  "roof",
  "You look carefully at the roof and see that it has been broken away,\n"+
  "exposing the hallway to the elements",
  "piles",
  "Made from the collapsed ceiling and torn walls and floor",
  "skies",
  "Dark and foreboding, they do not look pleasant",
  "stones",
  "Collected together into several large and small piles, they came from\n"+
  "the walls and ceiling"
});

dest_dir = ({
  RMS+"r01.c","out",
  RMS+"r03.c","east",
});

}

query_ruinsroom() { return 1; }

short() { 
  int i;
  string sh;
  if(set_light(0) > 0) { 
    if(this_player()) {
      if(!environment(this_player())->query_ruinsroom() && this_player()->query_level() < 40) return HIW+RUINS+NORM; 
      else { 
        sh = HIW+short_desc+" ["+NORM;
        if(!dest_dir || no_exits) sh += "no exits";
        else {
          for(i=1; i<sizeof(dest_dir); i+=2) {
            sh += translate_exit(dest_dir[i]);
            if (i < sizeof(dest_dir)-2) sh += ",";
          }
        }
        sh += HIW+"]";
        return sh+NORM; 
      }
    }
    else return HIW+RUINS+NORM;   
  }
  else return "Dark room";     
}