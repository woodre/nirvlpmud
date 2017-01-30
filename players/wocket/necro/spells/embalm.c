/* [6.6.01]  Verte reshuffled the ob1 check, to make
    sure the cmd doesn't bug out if a corpse isn't here :) */
#include "../defs.h"

cmd(str)  {
string name;
object gob,ob1,ob2;
int trans_level;
string info;
  gob = previous_object();
  if(!str || str != "corpse"){
    notify_fail("What would you like to embalm?\n");
    return 0;
  }
  ob1 = present("corpse",environment(tp));
/* redundant code that was bugging out the cmd.
    6.6.01 verte */
/*
  trans_level = ob1->query_corpse_level();
  sscanf(ob1->short(),"corpse of %s",name);
*/
  if(!ob1){
    ob1 = present("corpse",tp);
   }
   if(!ob1) {
      notify_fail("There is no corpse here to preserve.\n");
      return 0;
    }
    trans_level = ob1->query_corpse_level();
    sscanf(ob1->short(),"corpse of %s",name);
  if(!name){
    notify_fail("That corpse is too badly decayed to embalm.\n");
    return 0;
  }
  if(gob->query_blood() < 2) {
    notify_fail("You do not have enough blood to preserve the corpse.\n");
    return 0; 
  }
  if(ob1->query_preserved()){
    notify_fail("That corpse has already been preserved.\n");
    return 0;
  }
  info = ob1->query_info();
  write("You pull out spices and some blood from your necromantic component\n"+
        "pouch and embalm the corpse. The corpse is now preserved.\n");
  say(tpn+" bends over and embalms the corpse.\n");
  ob2 = clone_object(OBJ+"/misc/preserved.c");
  ob2->set_name(name);
  ob2->set_corpse_level(trans_level);
  ob2->set_info(info);
  destruct(ob1);
  move_object(ob2,environment(this_player()));
  gob->add_blood(-2);
  return 1;
}
