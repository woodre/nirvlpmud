#include "../defs.h"

cmd(str) {
object ob;
ob = GOB;

if(!ob) return;
  if(!GOB->checklev(10,10)) return 1;
  if(tp->query_spell_dam()){ 
    notify_fail("");
    return 0;
  }
  if(!str){
    notify_fail("What would you like to conjure?\n");
    return 0;
  }
  if(str != "sword"){
    notify_fail("That is not something you can conjure.\n");
    return 0;
  }
  if(tp->query_sp() < 50) { 
    write("You do not have the availble magic.\n"); 
    return 1; 
  }
  if(present("bonecleaver",tp)){
    write("You have already got one.\n");
    return 1;
  }/*
  if(ob->query_heart() < 2 || ob->query_spine() < 3 || ob->query_blood() < 20  || ob->query_soul() < 1) {
    notify_fail("You do not have the components available for this spell.\n");
    return 0; 
  }*/
  write("You whisper dark words calling the realm of the dead.\n");
  write("The room darkens.\n");
  say("The room darkens.\n");
  call_out("get_sword",3,tp);
  return 1;
}

get_sword(arg){
  tell_object(arg,"\n"+
        ROD+BOLD+BLK+"The room darkens as a swirl of purple mist surrounds your\n"+
        "      "+"hand.  As the mist dissipates a gleaming dagger is left in its\n"+
        "      "+"place."+OFF+"  You have conjured the necromantic sword of legend\n->>");
  arg->add_spell_point(-50);
/*  object ob;
ob = GOB;
  ob->add_val(2);
  ob->add_blood(-20);
  ob->add_spine(-3);
  ob->add_soul(-1);
  ob->add_heart(-2);
  ob->save_me();*/
  move_object(clone_object("/players/sami/closed/necro/nsword.c"),arg);
  arg->remote_say("Darkness swirls around the hand of "+arg->query_name()+" and a sword forms.\n");
}