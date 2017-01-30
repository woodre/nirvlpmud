#define tp environment(this_object())
id(str) { return str == "sterm_new_heroin" || str == "sterm"; }
int timer;
static int cadd, ctol, catime;
query_auto_load() { return "/players/mythos/mmisc/drugs/new_heroin/sterm.c:"; }

init_arg() {
  if(!restore_object("players/mythos/mmisc/drugs/new_heroin/sterm/"+tp->query_real_name())) 
  return;
}

get() { return 0; }
drop() {return 1;}
query_weight() { return 0; }
query_value() { return 0; }

set_timer(j) { timer = j; }

reset(arg) {
if(arg) return;
    call_out("seffect",10);
}

seffect() {
  timer = timer + 1;
  save_object("players/mythos/mmisc/drugs/new_heroin/sterm/"+tp->query_real_name());
  if(timer > 10) {
  if(tp->query_attrib("wil") < random(31)) {
  switch(random(5)) {
  case 0 : tell_object(tp,"You feel abit tired.\n"); 
           tell_room(environment(tp),capitalize(tp->query_name())+
           " seems a bit tired.\n"); break;
  case 1 : tell_object(tp,"You feel abit dizzy.\n"); 
           tell_room(environment(tp),capitalize(tp->query_name())+
           " stumbles.\n"); break;
  case 2 : tell_object(tp,"You feel good.\n");
           tell_room(environment(tp),capitalize(tp->query_name())+
           " seems to be in a state of bliss.\n"); break;
  case 3 : tell_object(tp,"You find breathing a bit hard.\n"); break;
  case 4 : tell_object(tp,"You feel abit tired.\n"); break;
  }}}
  if(timer > 60) {
  if(cadd > 15) {
  if(tp->query_attrib("wil") < random(200) && !present("lterm_new_heroin",tp)) {
  move_object(clone_object("/players/mythos/mmisc/drugs/new_heroin/lterm.c"),tp);
  command("save",tp); }
  }
  tell_object(tp,"The drug's effects wear off.\nYou feel a bit tired but overall you are fine.\n");
  destruct(this_object());
  return 1;}
  if(timer == 50) {
  tell_object(tp,"You feel ill.\n");
  command("puke",tp);
  }
  if(timer > 40) {
  if(tp->query_ac() > 5) {
  tp->set_ac(5); }
  if(tp->query_hp() > 3*(tp->query_mhp())/4) {
  tp->add_hit_point(3*(tp->query_mhp())/4 - tp->query_hp()); }
  restore_object("players/mythos/mmisc/drugs/new_heroin/add/"+tp->query_real_name());
  if(cadd > 10) {
  if(tp->query_attrib("wil") < random(50)) {
  tell_object(tp,"You need new_heroin.\nWithout it you feel you can not face the day.\n");
  }
  }
  }
  if(timer == 25) {
  tell_object(tp,"You feel ill.\n");
  command("puke",tp);
  }
  call_out("seffect",10);
}
