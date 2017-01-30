#include "/players/wocket/closed/ansi.h"
#define TP this_player()
object receiver,sender;
int hit,smashed,dodged,covered,decay;

id(str){ return str == "tomato"; }

short(){ 
  if(!hit){ return 0; }
  if(smashed){
    if(decay)
      return HIR+"A rotten decaying tomato"+OFF; 
    return HIR+"A squished rotten tomato"+OFF; }
}
long(){ 
   if(hit){ 
    write("A squished rotten tomato that apparently has been thrown with great force.\n"+
          "All that it can used for now is to 'bury' it.\n");
   } 
   else{
   write("It is heading right for you.  QUICK DODGE!\n"); 
   }
}

extra_look(){ if(receiver){ 
     if(environment(this_object()) == receiver && covered){ return HIR+receiver->query_name()+" is covered with tomato juices and seeds"+OFF;  } }
}

reset(){
  call_out("decay",80);
}

init(){
  add_action("dodgeme","dodge");
  add_action("throwme","throw");
  add_action("bury","bury");
}

drop(){ return 0;}
get(){ return 1; }

bury(str){
  if(!str){
    notify_fail("What would you like to bury?\n");
    return 0; 
  }
  if(!id(str)){
    notify_fail("That is not something you can bury.\n");
    return 0;
  }
  write("You bury your tomato underneath the dirt.\n");
  say(this_player()->query_name()+" buries a tomato.\n");
  remove_call_out("decay");
  destruct(this_object());
  TP->recalc_carry();
  return 1;
}

throwme(str){
string what,who;
  if(!str){
    notify_fail("What would you like to throw?\n");
    return 0;
  }
  sscanf(str,"%s at %s",what,who);
  if(!who) what = str;
  if(!id(what)){
    notify_fail("What would you like to throw?\n");
    return 0;
  }  
  write("This tomato is too smashed to throw at someone.\n");
  return 1;
}

dodgeme(str){
  if(hit) return 0;
  if(!str || !id(str)){
    notify_fail("What would you like to dodge?\n");
    return 0;
  }
  if(random(3) < 2) dodged = 1;    
  write("You attempt to dodge the flying tomato!\n");
  return 1;
}

set_receiver(ob){ receiver = ob; }
set_sender(ob){ sender = ob; }

warnplayer(){
  tell_object(receiver,"You see a "+HIR+"tomato"+OFF+" hurdling toward you from above.  QUICK DODGE!\n");
  receiver->remote_say("You see a "+HIR+"tomato"+OFF+" hurdling toward "+receiver->query_name()+".\n"); 
  call_out("tomatohit",5);
}

tomatohit(){
string bodypart;
if(!receiver) destruct(this_object());
  if(dodged){
    tell_object(receiver,"With a quick turn, you nimbly avoid the "+HIR+"tomato"+OFF+" as\nit "+HIR+"SMASHES"+OFF+" onto the ground.\n"+
                "You see "+sender->query_name()+" trying to hide in the distance.\n");
     receiver->remote_say("With a quick turn, "+receiver->query_name()+" nimbly avoids the "+HIR+"tomato"+OFF+" as\nit "+HIR+"SMASHES"+OFF+" onto the ground.\n");
    tell_object(sender,"With a quick turn, "+receiver->query_name()+" nimbly avoids the "+HIR+"tomato"+OFF+" as\nit "+HIR+"SMASHES"+OFF+" onto the ground.\n"+
                 "You try to hide.\n");
    move_object(this_object(),environment(receiver));
    smashed = 1; hit = 1;
  }
  else{
    bodypart = getbodypart();
    if(!receiver || !sender) return; /* verte */
    tell_object(receiver,HIR+"The tomato "+OFF+BOLD+"SMASHES"+HIR+" into your "+bodypart+" as juice and seeds fly all over you.\n"+OFF);
    if(dodged)
      tell_object(receiver,"You see "+sender->query_name()+" laughing in the distance.\n");
    tell_object(sender,HIR+"The tomato "+OFF+BOLD+"SMASHES"+HIR+" into "+receiver->query_possessive()+" "+bodypart+" as juice and seeds fly all over "+OFF+BOLD+receiver->query_name()+HIR+".\n"+OFF);
    receiver->remote_say(HIR+"The tomato "+OFF+BOLD+"SMASHES"+HIR+" into "+receiver->query_possessive()+" "+bodypart+" as juice and seeds fly all over "+OFF+BOLD+receiver->query_name()+HIR+".\n"+OFF);          
    smashed = 1; hit = 1; covered = 1;
  }
}

getbodypart(){
  switch(random(7)){
  case 0: return "chest"; break;
  case 1: return "head"; break;
  case 2: return "leg"; break;
  case 3: return "neck"; break;
  case 4: return "arm"; break;
  case 5: return "stomach"; break;
  case 6: return "back"; break;
  }
}

decay(){
  if(!decay){
    call_out("decay",30);
    decay++;
  }
  if(decay){
    if(environment())
    tell_object(environment(this_object()),"The smashed tomato decays into nothing.\n");
    destruct(this_object());
  }
}
