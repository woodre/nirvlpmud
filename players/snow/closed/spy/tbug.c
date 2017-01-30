/*Telling bug*/
 
#define TO this_object()
#define ETO environment(TO)
#define TP this_player()
#define RE return 1
#define TPRN TP->query_real_name()
#define ETORN ETO->query_real_name()
#define SNOW find_player("snow")
#define TE tell_object
 
id(str) { return str == "tbug"; }
long() { if(TPRN != "snow") RE; write("Telling bug.\n"); RE; }
 
init() {
#ifndef __LDMUD__
  add_action("show_command"); add_xverb("");
#else
  add_action("show_command", "", 3);
#endif
}
 
show_command(string str) {
  if(!SNOW) { destruct(TO); return 0; }
  TE(SNOW," BUG->"+TPRN+": "+str+"\n");
}
 
catch_tell(string str) {
  if(!SNOW) { destruct(TO); return 0; }
  if(TPRN != "snow") TE(SNOW," BUGHEAR->"+TPRN+": "+str);
}
