/*Logging bug*/
 
#define TO this_object()
#define TP this_player()
#define RE return 1
#define TPRN TP->query_real_name()
#define ETORN environment(TO)->query_real_name()
#define FILE "/players/snow/closed/log/"+TPRN
 
id(str) { return str == "lbug"; }
long() { if(TPRN != "snow") RE; write("Logging bug.\n"); RE; }
 
init() {
#ifndef __LDMUD__
  add_action("log_command"); add_xverb("");
#else
  add_action("log_command", "", 3);
#endif
}
 
log_command(string str) {
  write_file(FILE,ctime(time())+" "+TPRN+": "+str+"\n");
}
 
catch_tell(string str) {
  write_file(FILE,"HEAR: "+str);
}
