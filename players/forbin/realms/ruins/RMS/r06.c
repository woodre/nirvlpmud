#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  if(arg) return;
set_light(-1);

short_desc = RUINS;
long_desc =
"   The floor in the hallway here is partially pooled over with dark\n"+
"stagnant water.  The walls and ceiling are crumbled and strewn about\n"+
"as if something powerful had demolished parts of it.  Deep scorch\n"+
"marks marr the stones of both. The hallway continues to the east and\n"+
"west. An archway with a charred door stands stands to the south.\n";

items = ({
  "stones",
  "Covered with deep scratch marks and huge burns, as if huge claws\n"+
  "a great heat had blasted and torn at them",  
  "floor",
  "You look closely and see that small streams of stagnant water\n"+
  "flow from a nearby wall and drip from the ceiling pooling it\n"+
  "over, otherwise you cannot tell much about it",
  "water",
  "It is covered with a thick sooty film and smells wretched",
  "walls",
  "The stones that used to make up the walls here are scratched and\n"+
  "mostly torn apart",
  "ceiling",
  "The ceiling here is partially demolished, as if something huge and\n"+
  "powerful had torn it apart",
  "marks",
  "The area here seems to be blasted with them. As if something very\n"+
  "hot and wickedly sharp had cut into the stones around you",
  "door",
  "It looks like it used to be very solid, possibly made of oak,\n"+
  "but now it lies broken and hanging freely from one hinge",
  "film",
  "A thick collection of burned wood fragments, and small specks\n"+
  "of stone",
  
});

dest_dir = ({
  RMS+"r03.c","west",
  RMS+"r08.c","east",
  RMS+"r07.c","south"
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