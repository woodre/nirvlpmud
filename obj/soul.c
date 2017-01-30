
string cap_name;
string msgin,msgout,mmsgin,mmsgout,msghome;
object myself;
#include "/closed/verte/qt/soul_inc.h"


get() {
  cap_name = call_other(this_player(), "query_name", 0);
  return 1;
}

drop() { return 1; }

id(str) { return str == "soul" || str == "player_soul" || str == "ND"; }

long() {
  write("It is transparent.\n");
}

ghost() {
  cap_name = call_other(this_player(), "query_name", 0);
  return call_other(this_player(), "query_ghost");
}


/*
init() { soul_init();}
a
*/
init() {
  soul_init();
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("emote"); add_xverb(":");
#else
  add_action("emote", ":", 3);
#endif
  qt_actions();
}

query_msgin() { return msgin; }
query_msgout() { return msgout; }
query_mmsgin() { return mmsgin; }
query_mmsgout() { return mmsgout; }
query_msghome() { return msghome; }
/* Some functions to set moving messages. */

setmin(m) {
    msgin = m;
    call_other(myself,"update",1);
    return 1;
}

setmmin(m) {
    mmsgin = m;
    call_other(myself,"update",1);
    return 1;
}

setmout(m) {
    msgout = m;
    call_other(myself,"update",3);
    return 1;
}

setmmout(m) {
    mmsgout = m;
    call_other(myself,"update",4);
    return 1;
}

setmhome(m) {
    msghome = m;
    call_other(myself,"update",9);
    return 1;
}


reset(arg) {
    soul_reset(arg);
   if(arg) return;
   myself=this_player();
   call_out("update_inventory", 1);
  }


#include "soul_com.c"

emote(str){
  if(ghost())
    return 0;
  if(!str)
    return 0;
 str = format(str,60);
  write("You "+str+"\n");
  say(call_other(this_player(), "query_name", 0) + " "+ str +"\n");
  return 1;
}





void update_inventory()
{
    object x;
    if((x=environment()) && x->is_player())
    {
      move_object(this_object(), x);
    }
    else return destruct(this_object());
    call_out("update_inventory", 1);
}
