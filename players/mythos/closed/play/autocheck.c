#define tp this_player()
#define tpn tp->query_real_name()
#define ep environment(this_object())
#define mem "players/mythos/closed/play/check/"
static object ob;
static int a;

string name1, name2, name3, name4, name5, name6, name7;

query_auto_load() { return "/players/mythos/closed/play/autocheck.c:"; }

id(str) { return str == "again"; }

drop() { return 1;}
get() { return 0;}

init_arg() {
ob = users();
  restore_object(mem+tpn);
  for(a=0;a<sizeof(ob);a++) {
    if(ob[a]->query_real_name() == name1) { 
       ob[a]->save_me();
      ob[a]->quit();}
    if(ob[a]->query_real_name() == name2) { 
    ob[a]->save_me();
      ob[a]->quit();}
    if(ob[a]->query_real_name() == name3) { 
    ob[a]->save_me();
      ob[a]->quit();} 
    if(ob[a]->query_real_name() == name4) { 
    ob[a]->save_me();
      ob[a]->quit();} 
    if(ob[a]->query_real_name() == name5) { 
    ob[a]->save_me();
      ob[a]->quit();} 
    if(ob[a]->query_real_name() == name6) { 
    ob[a]->save_me();
      ob[a]->quit();} 
    if(ob[a]->query_real_name() == name7) { 
    ob[a]->save_me();
      ob[a]->quit();} 
  }
  this_player()->save_me();
}

init() {
ob = users();
  restore_object(mem+tpn);
  for(a=0;a<sizeof(ob);a++) {
    if(ob[a]->query_real_name() == name1) { 
    ob[a]->save_me();
      ob[a]->quit();}
    if(ob[a]->query_real_name() == name2) { 
    ob[a]->save_me();
      ob[a]->quit();}
    if(ob[a]->query_real_name() == name3) {
    ob[a]->save_me();
      ob[a]->quit();} 
    if(ob[a]->query_real_name() == name4) { 
    ob[a]->save_me();
      ob[a]->quit();} 
    if(ob[a]->query_real_name() == name5) {
    ob[a]->save_me();
      ob[a]->quit();} 
    if(ob[a]->query_real_name() == name6) {
    ob[a]->save_me();
      ob[a]->quit();} 
    if(ob[a]->query_real_name() == name7) {
    ob[a]->save_me();
      ob[a]->quit();} 
  }
  this_player()->save_me();
  return 1;
} 

exit() {
  if(this_player() == environment(this_object())) return 1;
  if(this_player() && this_player()->query_level() > 90) return 0;
    else return 1;
}
