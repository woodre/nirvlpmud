#include "../defs.h"

cmd(str){
  if(str == "portal") return raise_portal();
}

raise_portal() {
object ob;
  ob = GOB;
  if(GRAVESITE){
    if(tp->query_sp() < 60) {
      notify_fail("You do not have the spell points to raise a bone portal\n");
      return 0; 
    }
    if(!GOB->checklev(6,11)) return 1;
    if(present("boneportal",environment(tp))) {
      write("There is already a portal of bone within the area.\n");
      return 1;
    }
    if((ob->query_spine() < 1) || (ob->query_blood() < 5)) {
      write("You do not have the spell components available for the spell.\n");
    return 1; }
    write("You take out a spine from your pouch and lay all the bones on the ground.  Then you\n"+
          "begin to pour blood across them and chant some words silently to yourself.\n");
    say(tp->query_name()+" takes out a spine from "+tp->query_possessive()+" pouch and lays all the bones on the ground.  Then "+tp->query_pronoun()+"\n"+
          "begin to pour blood across them and chants some words silently to "+tp->query_objective()+"self.\n");
    call_out("move_portal",5,tp);
    tp->add_spell_point(60);
    ob->add_val(3);
    ob->add_blood(-5);
    ob->add_spine(-1);
    return 1;
  }
  else{
    notify_fail("There are not enough bones in the ground to cast this spell.\n");
    return 0;
  }
}
 
move_portal(player){
object ob;
string location;
  tell_room(environment(player),"The earth begins to shake as a portal rises from the bones of the dead.\n");
  ob = clone_object(OBJ+"/misc/boneportal.c");
  location = environment(player)->short()+"#"+file_name(environment(player));
  ob->set_location(location);
  ob->set_time(250);
  move_object(ob,environment(player));
}