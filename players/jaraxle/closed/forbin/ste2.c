/*
-[ Modifed for Jaraxle's use 4/25/02 ]-
   */

#include "/players/jaraxle/define.h"
#define DURATION 200

object targ;
int time;
string attrib;
int amount;
int time_left;
int how_much;

int drop() { return 1; }
int get() { return 0; }

id(str) {
   return str=="jar_ste2";
}

short() {
   if(this_player() && this_player()->query_level() > 20)
      return "Stealth bonus: "+HIG+time_left+NORM+" hbs remaining";
}


query_auto_load() {
   return "/players/jaraxle/closed/forbin/prep_stat.c:"+time_left+"/"+attrib+"/"+how_much;
}

init_arg(str) {
   if(sscanf(str,"%d/%s/%d",time_left,attrib,amount)!=3)
      destruct(this_object());
   call_out("delayed_reset",1);
}

delayed_reset() { 
   if(environment()){
      targ = environment();
      if(!targ->is_player())
         destruct(this_object());
   }
}

start(target, atrb, amt) {
   targ=target;
   if(!targ) return;
   attrib="ste2";
   amount=amt;
   time_left = DURATION;
   how_much = 1+random(2);
   
   TP->set_attrib("ste", TP->query_attrib("ste")+1);
   move_object(this_object(),TP);
   command("save",TP);
}  

stop() {
   if(!environment()) return;
   if(environment()->is_player()){
      tell_object(environment(), ""+GRN+"Your legs relax and begin to respond normally"+NORM+".\n");
      environment()->set_attrib("ste",environment()->query_attrib("ste")-how_much);
      /** Great that it lowers, but when the player quits we need to save since
        * the inv destructions happens after the player save -- Gnar **/
      environment()->save_me();
   }
   destruct(this_object());
}

reset(arg) {
   if(arg) return;
   set_heart_beat(1);
}

remove_object() {
   stop();
}

heart_beat() {
   time_left--;
   if(time_left <= 0)
      stop();
}
