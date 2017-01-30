/*
File: reinstate_spell.c
Creator: Feldegast @ Nirvana
Date: 1/2/00
Description:
This is a token for the reinstate spell that stays in a
player's inventory.  It raises one attribute, and then 
removes it after 200 heartbeats.  This object autoloads.
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
   return str=="jar_sta";
}

short() {
   if(this_player() && this_player()->query_level() > 20)
     return "Stamina bonus: "+HIC+time_left+NORM+" hbs remaining";
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
how_much = 1+random(3);
   targ=target;
   if(!targ) return;
   attrib=atrb;
   amount=amt;
   time_left = DURATION;
   TP->set_attrib("sta", TP->query_attrib("sta")+how_much);
   move_object(this_object(),TP);
   command("save",TP);
}  

stop() {
   if(!environment()) return;
   if(environment()->is_player()){
      tell_object(environment(), ""+CYN+"Your heartbeat returns to normal"+NORM+".\n");
      environment()->set_attrib("sta",environment()->query_attrib("sta")-how_much);
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
