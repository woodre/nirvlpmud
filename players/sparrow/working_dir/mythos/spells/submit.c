#include "/players/mythos/closed/guild/def.h"
string place, own;
int time;
id(str) {return str == "submit";}

get() { return 0;}
drop() { return 1;}

set_place(str) { place = str;}
set_own(str) { own = str; }
set_time(n) { time = n;}
query_place() { return place;}
query_own() { returnn own;}
reset(arg) {
  if(arg) return;
  call_out("submission",3); 
  }

submission() {
string here;
  if(time < 0 || !ep) { break_free(); return 1;}
  here =(ep->query_current_room());
  if(here != place) { time = time -1;}
  if(!present(own,environment(ep))) {
  move_object(ep,find_player(own)); }
  if(!find_player(own)) { time = time - 10; }
  if(present(own,environment(ep))->query_attack() &&
  ep->query_attack() != (present(own,environment(ep))->query_attack())) {
  ep->attack_object(present(own,environment(ep))->query_attack()); }
  call_out("submission",3);
return 1;}

break_free() {
if(ep) {
  if(environment(ep)) {
  if(present(own,environment(ep))) {
  ep->attack_object(present(own,environment(ep))); }
  ep->set_wc(50);
  ep->set_level(20);
  ep->set_ac(20);
  if(find_player(own) {
  tell_object(find_player(own),"You have lost control over "+ep->short()+"!\n");
  }
  tell_room(environment(ep),capitalize(epn)+" breaks free of its submission!\n");
  }}
  destruct(this_object());
return 1;}

break() {
  if(find_player(own) {
  tell_object(find_player(own),"You have lost control over "+ep->short()+"!\n");
}
destruct(this_object());
return 1;}
