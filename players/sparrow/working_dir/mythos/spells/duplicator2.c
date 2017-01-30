#define ep environment(this_object())
#define eep environment(ep)

object own;
string name;

id(str) { return str == "duplicator";}

get() { return 0;}
drop() { return 1;}

query_save_flag() { return 1;}

set_name(str) { name = str; }
set_own(ob) { own = ob; }

reset(arg) { 
  if(arg) return;
  call_out("checks",5);
}

checks() {
object obs;
int j;
if(ep) {
  if(eep) {
  if(!own) {
    dest();
  return 1; }
  else {
    if(own->query_sp() < (ep->query_level())/2) { 
      tell_object(own,"You do not have any more energy to keep the replicant alive!.\n");
      dest();
    return 1; }
    else {
      own->add_spell_point(-(ep->query_level())/2);
      tell_object(own,"Your energy feeds the replicant.\n");
    }
    if(environment(own) != eep) {
      tell_object(own,"You must be in the same room as the replicant!\n");
      dest();
    return 1; }
  }
  if(ep->query_hp() < 75) { 
    tell_room(eep,capitalize(ep->query_name())+" is too weak!\n");
    dest();
  return 1;}
  if(present(name,eep)) {
    if(ep->query_attack()) {
      if((ep->query_attack())->id(name)) {
        call_out("checks",3);
       return 1;}
      if((ep->query_attack())->is_player()) (ep->query_attack())->heal_self(-100);
    }
    ep->attack_object(present(name,eep));
    call_out("checks",3);
  return 1;}
  dest();} }
return 1;}

dest() {
object obs;
int j;
 obs = all_inventory(ep);
  for(j=0;j<sizeof(obs);j++) {
    if(!(obs[j]->id("duplicator"))) {
      destruct(obs[j]);
    }
  }
  tell_room(eep,capitalize(ep->query_name())+" slowly fades away.......\n");
  destruct(ep);
return 1; }