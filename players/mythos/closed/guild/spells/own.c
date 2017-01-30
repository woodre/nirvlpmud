#define ep environment(this_object())
#define eep environment(ep)

string owner;
int level;

id(str) {return str == "owned";}

get() { return 0;}
drop() { return 1;}

query_save_flag() { return 1;}

set_owner(str) { owner = str; }
set_level(n) { level = n; }
query_owner() { return owner;}
query_level() { return level; }

reset(arg) { 
  if(arg) return;
  call_out("checks",10);
}

checks() {
if(ep) {
if(eep) {
  if(!(eep->query_owned()) && eep->query_real_name() != owner) {
      if(living(eep)) tell_object(eep,"The "+ep->short()+" vanishes.\n"); 
      move_object(ep,"/players/mythos/closed/guild/storage.c");
  } } }
  call_out("checks",100);
return 1;}
