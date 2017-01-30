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


init() { soul_init();}

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


#include "soul_com.c"
