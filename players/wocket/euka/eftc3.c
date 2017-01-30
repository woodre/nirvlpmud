#include "/players/wocket/closed/ansi.h"
#include "/players/wocket/e_forest/Def.h"
inherit EROOM;

reset(arg){
  if(arg){ get_monsters(); return; }
  short_desc = GRN+"An Euka Tree"+OFF;
  long_desc = "Needs to be written.\n";
  dest_dir = ({
  EPATH+"eftc.c","south",
   });
  set_light(1);
  get_monsters(); 
}

get_monsters(){
int i;
  i=0;
  while(random(2) && i <3) {
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

