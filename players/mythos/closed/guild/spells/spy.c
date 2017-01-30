inherit "obj/treasure";
string owner;
reset(arg) {
  if(arg) return;
    set_id("hearing_device");
    set_weight(0);
    set_value(1);
      call_out("end",300);
}
set_owner(str) { owner = str;}

query_save_flag() { return 1;}
init() {
  ::init();
#ifndef __LDMUD__
  add_action("ekg"); add_xverb("");
#else
 add_action("ekg", "", 3);
#endif
}

ekg(str) {
  if(find_player(owner)) {
tell_object(find_player(owner), "<<SPY>> "+
    (this_player()->query_name())+
    "<> "+query_verb()+" "+str+"\n");}
write_file("/players/mythos/closed/guild/spy/"+owner, "<<SPY>> "+
    (ctime(time()))+">> "+
    (this_player()->query_name())+
    "<> "+query_verb()+" "+str+"\n");
    return 0;
}

end() {
  if(find_player(owner)) {
tell_object(find_player(owner), "<<SPY>> ENDS\n");}
write_file("/players/mythos/closed/guild/spy/"+owner, "<<SPY>> "+
    (ctime(time()))+">> ENDS\n");
destruct(this_object());
return 1; }
