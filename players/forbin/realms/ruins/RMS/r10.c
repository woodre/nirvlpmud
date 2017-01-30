#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  object angel;
  if(!present("archangel")) {
    angel = clone_object(NPC+"angel.c");
    angel->set_up(29, 13, "fire", "flaming_axe.c", "axe");
    move_object(angel, this_object()); 
  }
  if(arg) return;
set_light(-1);

short_desc = RUINS;
long_desc =
"   The hallway here has been seriously damaged. Looking out past the\n"+
"crumbled walls you see that what remains of the ruins on this side\n"+
"has been leveled.  Looking down you see a huge gaping hole, the stones\n"+
"around it scorched and blackened.  The hallway leads back to the south.\n";

items = ({
  "ruins",
  "The building would have continued out for quite some\n"+
  "distance, but instead nothing stands. Large piles of\n"+
  "rocks dot the landscape, with an occassional wall\n"+
  "standing only about waist high",
  "hole",
  "You inspect the hole closer and see that it wasn't dug\n"+
  "but was melted into the floor",
  "walls",
  "You see that the walls here were torn apart and scattered outside",
  "hallway",
  "Looking about you can barely tell that this once was a long"+
  "hallway. Its walls are crumbled and fallen, exposing the"+
  "interior of the ruins to the elements"
  
  
});

dest_dir = ({
  RMS+"r08.c","south",
  RMS+"r11.c","down",
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
