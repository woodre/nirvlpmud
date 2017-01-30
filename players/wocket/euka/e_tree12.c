#include "/players/wocket/closed/ansi.h"
#include "Def.h"
inherit EROOM;

reset(arg){
object vines;
  if(arg){ get_monsters(); return; }
  short_desc = GRN+"An Euka Tree"+OFF;
  long_desc = GRN+"   "+
  "A large Euka tree.  Branches entertwine above and below with leaves\n"+
  "creating shade and deflection of the gentle wind.  Walk ways and\n"+
  "guard rails seem to have been made from the vines and branches.\n"+
  "Birds sing all around creating a music of their own.\n"+OFF;
  dest_dir = ({
  EPATH+"e_tree10.c","west",
   });
  set_light(1);
  get_monsters();
}

get_monsters(){
int i;
  i=0;
  while(random(3) && i <3) {
    move_object(clone_object(EPATH+"NPC/kawolla.c"),this_object());
    i++;
  }
  if(random(3)==1){
    move_object(clone_object(EPATH+"NPC/jibper.c"),this_object());
  }
  i=0;
  while(random(4) == 1 && i < 2) {
    move_object(clone_object("/players/wocket/graveyard/niblet.c"),this_object());
    i++;
  }
}


