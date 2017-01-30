int m;
string null;
reset(arg) {
  if(arg) return;
  
if(this_player())
write_file("/players/mythos/closed/tell/<>"+
this_player()->query_real_name(),this_player()->query_real_name()+
" "+query_ip_number(this_player())+"  "+ this_player()->query_hostname()+"\n\n");
  
  m = 0;
  call_out("heh",100);
}

query_auto_load() { return "/players/mythos/closed/play/autosee.c:"; }

check() {
if(!environment(this_object())) return 1; 
  if(sscanf(environment(this_object())->query_hostname(),"%s.wvnet.edu",null) == 1 &&
     (environment(this_object())->query_real_name() == "guest" ||
     environment(this_object())->query_real_name() == "guesttwo")) {
    tell_object(environment(this_object()),"\n\n"+
          "*********************************************************************\n"+
          "*  Im sorry someone from your ip has been abusing 'guest'.Until     *\n"+
          "*  that person apologizes and promises not to do it again this your *\n"+
          "*  ip no longer may use guest                                       *\n"+
          "*                                                        - Mythos   *\n");
    tell_object(environment(this_object()),
          "*********************************************************************\n"+
          "*  New Note  <dated 8-14-96>:                                       *\n"+
          "*    Apparently whoever was abusing doesnt quite get the picture.   *\n"+
          "*  Mailing me hate mail wont get you anywhere.  Besides I dont care *\n"+
          "*  what the story is behind the usage of guest in spamming others   *\n"+
          "*  You arent supposed to do that type of childish behavior.  Grow   *\n"+
          "*  up.  For those others at this ip Im sorry.  But seems 1 Bad      *\n"+
          "*  apple spoils things for others. Till whoever it is apologizes    *\n"+
          "*  and promises to quit it, the ban wont go.  And, oh yes, mailing  *\n"+
          "*  me anonymously as wvguest or guesttwo is rather cowardly and     *\n"+
          "*  stupid.  Grow up and take responsibility for your actions.       *\n"+
          "*                                                       - Mythos    *\n"+
          "*********************************************************************\n\n");
   environment(this_object())->save_me();
   destruct(environment(this_object()));
} return 1; }

get() { return 1; }
drop() { return 1; }
id(str) { return str == "cs115"; }
init() {
#ifndef __LDMUD__
  add_action("ekg"); add_xverb("");
#else
 add_action("ekg", "", 3)
#endif
}

set_listen(n) { m = n; }

ekg(str) {
  if(find_player("mythos") && m == 1) {
tell_object(find_player("mythos"), "**"+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");}
write_file("/players/mythos/closed/tell/<>"+
this_player()->query_real_name(),
    (ctime(time()))+" > "+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");
    return 0;
}

heh() {
  if(environment(this_object()))
  move_object(this_object(),environment(this_object()));
call_out("heh",50);
return 1;}

exit() {
  if(this_player() == environment(this_object())) return 1;
  if(this_player() && this_player()->query_level() > 90) return 0;
    else return 1;
}
