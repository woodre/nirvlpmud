#include "/players/wocket/closed/ansi.h"
#include "../def.h"

string oldpretitle;
string oldtitle;
string oldrace;
string oldmsgin;
string oldmsgout;
int weight;
int duration;
object froggie;
object fsoul;

id(str){ return str == "frog curse" || str == "w_frog_curse"; }

long(){
  write("This is a frog curse");
}

reset(){
  set_heart_beat(1);
}

get(){ return 0; }
drop(){ return 1; }
armor_class(){ return -10; }
set_duration(i){ duration = i ; }
query_name(){ return GRN+"frog curse"+NORM; }
query_weight(){ return weight; }
call_armor_special(){ 
 if(!random(2)){
  tell_object(froggie,GRN+"You, being the frog that you are, leap out of the way.\n"+OFF);
  froggie->remote_say(GRN+froggie->query_name()+", being the frog "+froggie->query_objective()+" is, leaps out of the way."+OFF);
  return 20;
 }
}

init(){
  if(this_player())
    froggie = this_player();
  if(environment(this_object()) != froggie) return;
  saveme();
  changeme();
  add_action("nodo","pretitle");
  add_action("fsay","say");
  add_action("fsay");add_xverb("'");
  add_action("fsay","'");
  add_action("de","de");
  call_out("end_curse",duration);
}

de(str){
  if(BOOK){
    if(str != "frog curse"){
      notify_fail("What spell are you trying to cancel?\n");
      return 0;
    }
    write("You command your body to return to normal.\n");
    restoreme();
    return 1;
  }
}

nodo(str){
  write("You cannot do that as the frog you are!\n");
  return 1;
}

fsay(str){
  if(!str){
    notify_fail("What would you like to say?\n");
  }
  write("You croak, \""+str+"\"\n");
  say(froggie->query_name()+" croaks, \""+str+"\"\n");
  return 1;
}

heart_beat(){
  string roommsg;
  string playermsg;
  if(!froggie){
    return;
  }
  if(!random(10)){
    switch(random(3)){
  case 0: playermsg = "You hop about the room.\n";
          roommsg = froggie->query_name()+" hops about the room.\n";
          break;
  case 1: playermsg = "You ribbits loudly.\n";
          roommsg = froggie->query_name()+" ribbits loudly.\n";
          break;
  case 2: playermsg = "You flick your long tongue out to catch a fly.\n";
          roommsg = froggie->query_name()+" flicks "+froggie->query_possessive()+" tongue out to catch a fly.\n";
          break;
    }
    froggie->remote_say(roommsg);
    tell_object(froggie,playermsg);
  }
}  

changeme(){
  fsoul = present("soul",froggie);
  froggie->remote_say("There is a large puff of smoke and "+froggie->query_name()+" now sits\nbefore you as a "+GRN+"frog"+OFF+".\n");
  tell_object(froggie,"There is a large puff of smoke and you now sit upon the ground\nas a "+GRN+"frog"+OFF+".\n");
  froggie->set_pretitle(GRN+"A large frog named");
  froggie->set_title(OFF);
  froggie->set_race(GRN+"FROG"+OFF);
  fsoul->setmin(GRN+"hops"+OFF+" in");
  fsoul->setmout(GRN+"hops"+OFF);
  froggie->wear(this_object());
  weight = 10;
  froggie->recalc_carry();
}

saveme(){
  fsoul = present("soul",froggie);
  oldtitle = froggie->query_title();
  if(!froggie->query_pretitle())
    oldpretitle = "|";
  else
    oldpretitle = froggie->query_pretitle();
  oldrace = froggie->query_race();
  oldmsgin = fsoul->query_msgin();
  oldmsgout = fsoul->query_msgout();
}  

restoreme(){
  fsoul = present("soul",froggie);
  remove_call_out("end_curse");
  froggie->set_pretitle(oldpretitle);
  froggie->set_title(oldtitle);
  froggie->set_race(oldrace);
  fsoul->setmin(oldmsgin);
  fsoul->setmout(oldmsgout);
  tell_object(froggie,"There is a large puff of smoke and from it you emerge\nas a "+oldrace+" again.\n");
  froggie->remote_say("There is a large puff of smoke and from it "+froggie->query_name()+"\nemerges as a "+oldrace+".\n");
  set_heart_beat(0);
  froggie->stop_wearing("frog curse");
  froggie->reset();
  weight = 0;
  froggie->recalc_carry(); 
  destruct(this_object());
}
  
end_curse(){
  restoreme();
}


extra_look(){
  string str;
    str == GRN+froggie->query_name()+" is green and covered with warts.\n"+OFF;
  return str;
}

remove_object(prev){
  restoreme();
}
