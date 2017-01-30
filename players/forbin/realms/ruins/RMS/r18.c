#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  object angel;
  if(!present("archangel")) {
    angel = clone_object(NPC+"angel.c");
    angel->set_up(26, 15, "ice", "ice_staff.c", "staff");
    move_object(angel, this_object()); 
  }
  if(arg) return;
set_light(1);

short_desc = RUINS;
long_desc =
"   This room is crafted into a perfect circle. Several holy symbols\n"+
"cover the marble floor, each engraved in gold.  Wall sconces provide\n"+
"light to this warm room. An archway to the south leads to a small\n"+
"chamber. To the east is a hallway and to the north is the wall room.\n";

items = ({
  "symbols",
  "Each symbol is carved deeply into the floor, their etched\n"+
  "surface filled with some type of shining blue metal. Even\n"+
  "with all the evil that surrounds the ruins for some reason\n"+
  "the symbols traced here on the floor are more at home than\n"+
  "anything that lies outside in the cursed ruins. You feel that\n"+
  "this is a place of reverance and a deep feeling of goodness\n"+
  "flows through it",
  "sconces",
  "Trimmed in gold, they blaze with a warm endless light",
  "floor",
  "Made from polished marble, you can actually see your\n"+
  "reflection in its stones",
});

dest_dir = ({
  RMS+"r17.c","north",
  RMS+"r20.c","south",
  RMS+"r19.c","east",
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
