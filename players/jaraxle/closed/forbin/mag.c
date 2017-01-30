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
   return str=="jar_mag";
}

short() {
   if(this_player() && this_player()->query_level() > 20)
     return "Magic bonus: "+HIM+time_left+NORM+" hbs remaining";
}


query_auto_load() {
   return "/players/jaraxle/closed/forbin/prep_stat.c:"+time_left+"/"+attrib+"/"+how_much;
}

init_arg(str) {
   if(sscanf(str,"%d/%s/%d",time_left,attrib,how_much)!=3)
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
   how_much = 1+random(3);
   attrib="mag";
   amount=amt;
   time_left = DURATION;
   TP->set_attrib("mag", TP->query_attrib("mag")+how_much);
   move_object(this_object(),TP);
   command("save",TP);
}  


stop() {
   if(!environment()) return;
   if(environment()->is_player()){
     tell_object(environment(), ""+MAG+"The intense headache you once had, quickly receeds"+NORM+".\n");
      environment()->set_attrib("mag",environment()->query_attrib("mag")-how_much);
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
