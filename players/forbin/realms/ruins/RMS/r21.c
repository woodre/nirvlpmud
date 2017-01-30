#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  object angel;
  if(!present("archangel")) {
    angel = clone_object(NPC+"angel.c");
    angel->set_up(30, 20, "ice", "ice_lance.c", "lance");
    angel->set_level(20);
    angel->set_hp(600);
    angel->add_spell("ice2",
    "\tYou scream in pain as twin rays of pure $HC$ICE$N$ slam into you.\n",
    "The Archangel's eyes fire twin rays of pure $HC$ICE$N$ at #CTN#.\n",
    15, "20-35", "other|ice", 0);
    move_object(angel, this_object()); 
  }
  if(!present("mane")) {
    move_object(clone_object(NPC+"shadowmane.c"), this_object()); 
  }
  if(arg) return;
set_light(-1);

short_desc = RUINS;
long_desc =
"  As you follow the hallway you round the corner only to find that what\n"+
"seemed untouched has been mauled by whatever powerful forces assaulted\n"+
"this place. Before you the hallway has been burned and torn asunder. The\n"+
"walls, although still standing, are completely marred their old glory wiped\n"+
"away by the evil that has enveloped everything in this place. The broken\n"+
"hallway continues eastward through an archway into an open room and also\n"+
"back to the north.\n";

items = ({
  "walls",
  "You look closely and see that fire and claws have torn away the beauty\n"+
  "and perfection that once was, leaving now a reminder of what happened\n"+
  "here",
  "archway",
  "It looks as though perhaps a huge door might have once stood in its\n"+
  "frame, but now you only see a gaping hole",
});

dest_dir = ({
  RMS+"r19.c","north",
  RMS+"r22.c","east",
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
