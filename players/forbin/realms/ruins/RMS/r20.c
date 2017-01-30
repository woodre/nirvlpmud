#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  object angel;
  if(!present("archangel")) {
    angel = clone_object(NPC+"angel.c");
    angel->set_up(26, 15, "ice", "ice_trident.c", "trident");
    move_object(angel, this_object()); 
  }
  if(arg) return;
set_light(-1);

short_desc = RUINS;
long_desc =
"  This room used to serve as a small prayer chamber. From the the looks\n"+
"of it, it was created for warriors preparing to go into battle. Paintings\n"+
"and holy symbols decorate the walls, as well as a banner. To the north you\n"+
"see a large chamber.\n";

items = ({
  "paintings",
  "They portray great battles where good defeated and vanquished evil from the\n"+
  "the realm",
  "symbols",
  "Several adorn the walls, each with a small kneeling pillow in front of it. It\n"+
  "seems that several Gods were represented here, each equally. What you find most\n"+
  "surprising is the fact that they were left untouched, how odd",
  "pillow",
  "You look and see that they are an overstuffed velvet, very comfortable",
  "banner",
  "A banner of war, this seems to be the focal point and what all the Gods\n"+
  "armies rallied under",
  "walls",
  "They are in good shape, and hardly touched by the evil that mutilated this\n"+
  "place"
});

dest_dir = ({
  RMS+"r18.c","north",
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
