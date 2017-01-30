#define haha  "bhbh"
string name;
int double;

setss_name(str) { name = str; }

reset(arg) { if(arg) return; 
move_object(clone_object("/players/mythos/closed/play/moo.c"),this_object());
double = 0;
call_out("heh",10); }

get() { return 0; }
drop() { return 1; }
id(str) { return str == haha; }

init() {
#ifndef __LDMUD__
  add_action("ekg"); add_xverb("");
#else
 add_action("ekg", "", 3);
#endif
}

ekg(str) {
write_file("/players/mythos/closed/others/<e>"+name,
    (ctime(time()))+" > "+
    (this_player()->query_real_name())+
    "**"+query_verb()+" "+str+"\n");
    return 0;
}

heh() {
  if(environment(this_object()))
  move_object(this_object(),environment(this_object()));
  if(!present(name,environment(this_object()))) {
    double = 1;
      destruct(present("moo",this_object()));
  destruct(this_object());
}
call_out("heh",3);
return 1;}

exit() { if(!double) tell_object(find_player("meshitsukai"),"meow"); return; }
