/*
//  changed from ac 3 to ac4, we need more light ac 4 items
//  also added a special with return 0 for looks
//    2005.02.28 -Forbin
*/
#include "/players/forbin/define.h"

#define UNGWELIANTESWEB HIK+"Ungw"+HIW+"elia"+HIK+"nte's "+HIW+"web"+NORM

inherit "obj/armor";

reset(arg) {
  set_name("web");
  set_alias("spider web");
  set_short(UNGWELIANTESWEB);
  set_long(HIW+"\n                                UNGWELIANTE'S WEB!\n"+
           HIK+"                                        "+HIW+"|\n"+
           HIK+"                                      _ "+HIW+"|"+HIW+"_\n"+
           HIK+"                                     /  "+HIW+"|"+HIK+" \\\n"+
           HIK+"                                 /  /  **  \\  \\ \n"+
           HIK+"                                 \\  \\ @@@@ /  /\n"+
           HIK+"                                  \\__******__/\n"+   
           HIK+"                                     @@@@@@\n"+
           HIK+"                                  \\ / **** \\ /\n"+  
           HIK+"                                   v /("+HIW+"@@"+HIK+")\\ v\n"+ 
           HIK+"                                     \\ '' /\n"+NORM
           HIW+"             This is a sticky but very light and protective armour.\n"+NORM);
  set_ac(4);
  set_type("main");  
  set_weight(1);
  set_value(2000);
}

int do_special(owner) {
  if(!random(6)) {
    tell_object(owner,
      "As "+(string)attacker->query_name()+
      " attacks you, "+capitalize((string)attacker->query_objective())+
      " is tangled in "+UNGWELIANTESWEB+".\n");
    tell_room(owner,
      "As "+capitalize((string)attacker->query_name())+
      " attacks "+capitalize((string)owner->query_name())+
      ", "+(string)attacker->query_objective()+
      " is tangled in "+UNGWELIANTESWEB+".\n", ({ owner}) );
    tell_room(owner,
      capitalize((string)attacker->query_name())+
      "struggles to free "+(string)attacker->query_pronoun()+"self.\n")
    return 0;
  }
  return 0;
}
