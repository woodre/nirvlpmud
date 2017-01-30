#include "../defs.h"

cmd(str) {
object ob,corpse,bodypart;
string what,from,file,part,whichbodypart;
  if(!str){
    notify_fail("What would you like to dismember?\n");
    return 0;
  }
  if(sscanf(str,"%s from %s",what,from) != 2){
    notify_fail("What would you like to dismember from a corpse?\n");  
    return 0;
  }
  if(from != "corpse"){
    notify_fail("You can not dismember "+what+" from "+from+".\n");
    return 0;
  }
  corpse = present("corpse",environment(this_player()));
  ob = GOB;
  if(!corpse){
    notify_fail("There is no corpse here to be dismembered.\n"); 
    return 0; 
  }
  if(what != "arm" && what != "leg" && what != "head"){
    notify_fail("You can only dismember an arm, a leg, or the head.\n");
    return 0;
  }
  if(!tp->query_weapon()){
    write("You must have weapon wielded!\n"); return 1; 
  }
  if(corpse->query_corpse_level() < 1){
    write("That corpse is worthless to you.\n");
    return 1;
  }
  switch(what){
    case "arm":  part = "arm";
                 if(!random(2)) whichbodypart = "left arm";
                 else           whichbodypart = "right arm";
                 break;
    case "leg":  part = "leg";
                 if(!random(2)) whichbodypart = "right leg";
                 else           whichbodypart = "left leg";
                 break;
    case "head": part = "head"; whichbodypart = "head";
                 break;
  }

  bodypart = clone_object(OBJ+"/bodyparts/lightable_bodypart.c");
  bodypart->set_part(part);
  bodypart->set_whichpart(whichbodypart);
  bodypart->set_name(capitalize(corpse->query_name()));
  move_object(bodypart,this_player());
  write("You "+HIR+"savagely hack at the corpse as blood splatters everywhere.\n"+OFF+
        "You "+HIR+"pick up the dismembered "+what+".\n"+OFF);
  say(tpn+HIR+" savagely hacks at the corpse as blood splatters everywhere.\n"+OFF+
      tpn+HIR+" picks up the dismembered "+what+".\n"+OFF);
  corpse->set_short("The "+HIR+"mutilated"+OFF+" corpse of "+capitalize(corpse->query_name()));
  corpse->set_long("This is the mutilated corpse of "+capitalize(corpse->query_name())+".\n"+
                   "Its "+what+" has been savagely hacked off as blood and chucks\n"+
                   "of flesh litter the surrounding area.  The corpse has become\n"+
                   "tottaly void for anything salvagable.\n");
  corpse->set_corpse_level(0);
  return 1;
}
