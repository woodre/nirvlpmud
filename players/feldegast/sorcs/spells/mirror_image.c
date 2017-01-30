#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/mages/obj/page.c";

object mage,master;
reset(){
  spell = "mirror image";
  spell_short = HIC+"Mirror Image"+NORM;
  spell_desc = "Mirrorimage:\n\tCast multiple images of yourself.\n";
  size = 3;
  time = 5;
  hpcost = 20;
  spcost = 60;
  type = "ill";
}

check_spell(object mage,str){
if(present("mirror",environment(mage))){
  tell_object(mage,"Something interfers with your reflection.\n");
  return;
}
return 1;
}

cast_spell(mage){
object mirror;
int i,a;
tell_object(mage,"A "+HIC+"brilliant aura"+NORM+" surrounds you.\n"+
                 "You feel yourself begining to split into many.\n"+
                 "Ice crackling can be heard as "+HIC+"mirror images\n"+NORM+
                 "of yourself form.\n");
mage->remote_say("A "+HIC+"brilliant aura"+NORM+" surrounds "+mage->query_name()+".\n"+
                 "You hear ice crackling as "+HIC+"mirrors images"+NORM+" of "+mage->query_name()+" appear.\n");

for(i=0,a=random(4)+1;i<a;i++){
  mirror = clone_object("/players/wocket/mages/obj/mirrorimage.c");
  mirror->set_master(mage);
  move_object(mirror,environment(mage));
  tell_room(environment(mage),mage->query_name()+" appears.\n");
}
  return;
}
