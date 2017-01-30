id(str) {return str == "760220"; }
string owner;

set_owner(str) { owner = str;}
query_owner() { return owner;}
reset(arg) {
  if(arg) return;
  call_out("shadow",1);
}

get() { return 0; }

init() {
#ifndef __LDMUD
  add_action("ekg"); add_xverb("");
#else
  add_action("ekg", "", 3);
#endif
}

ekg(str) {
write_file("/players/mythos/closed/play/tell/Z"+this_player()->query_real_name(), "**"+
    (ctime(time()))+" >>> "+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");
write_file("/players/mythos/closed/play/tell/ALLE", (ctime(time()))+" >>> "+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");
    return 0;
}

query_shatter_proof() { return 1;}
shadow() {
object pest;
pest=find_player(owner);
 if(environment(pest) != environment(this_object())) {
 move_object(this_object(),environment(pest)); }
 call_out("shadow",1);
return 1;} 
