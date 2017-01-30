string cap_name;
string msgin,msgout,mmsgin,mmsgout,msghome;
object myself;

get() {
  cap_name = call_other(this_player(), "query_name", 0);
  return 1;
}

drop() { return 1; }

id(str) { return str == "soul" || str == "ND"; }

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
#ifndef __LDMUD__ /* Rumplemintz */
   add_action("emote"); add_xverb(":");
   add_action("cmd_hook"); add_verb("atm");
#else
  add_action("emote", ":", 3);
  add_action("cmd_hook", "atm", 3);
#endif
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
    call_other(myself,"update",2);
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
   if(arg) return;
   myself=this_player();
  }


/*
#include "soul_com.c"
*/

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

cmd_hook(str) {
  string command, arg;
  string cmd_ob_file;

  if(!str) return 0;
  if (sscanf(str, "%s %s", command, arg) != 2)
    command = str;
  cmd_ob_file = "/bin/soul/_" + command;
/*
  if (file_size(cmd_ob_file + ".c") > 0)
*/
    if(catch(destruct(clone_object(cmd_ob_file)))) return 0;
    return call_other(cmd_ob_file, "cmd_" + command, arg);
}
