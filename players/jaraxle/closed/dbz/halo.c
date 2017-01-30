/*
This is to check for someone who has been "wished" 
back to life by the other objs in this dir.
   This makes sure you can only be wished back to life
   within a set time limit.
*/

#include "/players/jaraxle/define.h"
#define DURATION 21600
/* [21600hb = 43200 secs] [43200secs / 60 = 720mins] [720 / 60 = 12hrs] */

object targ;
int time;
string attrib;
int time_left;

int drop() { return 1; }
int get() { return 0; }

id(str) {
   return str == "dbz_halo" || str == "halo";
}

short() {
   if(this_player() && this_player()->query_level() > 20)
      return "Wish to life: "+HIC+time_left+NORM+" hbs remaining";
}

long(){ write("A small "+HIY+"halo"+NORM+", signifying you were wished back to life.\n"); return 1; }

extra_look(){ write("(a small "+HIY+"halo"+NORM+")\n"); }

query_auto_load() {
  return "/players/jaraxle/closed/dbz/halo.c:"+time_left;
}

init_arg(str) {
  if(sscanf(str,"%d/%s/%d",time_left)!=1)
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

start(){
   time_left = DURATION;
/*

   move_object(this_object(),TP);
*/
   command("save",TP);
}  

stop() {
   if(!environment()) return;
   if(environment()->is_player()){
      tell_object(environment(), HIY+"The halo over your head slowly fades away"+NORM+".\n");
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
