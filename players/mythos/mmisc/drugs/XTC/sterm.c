#define tp environment(this_object())
id(str) { return str == "sterm_XTC" || str == "sterm"; }
int timer;
static int cadd, ctol, catime;
query_auto_load() { return "/players/mythos/mmisc/drugs/XTC/sterm.c:"; }

init_arg() {
  if(!restore_object("players/mythos/mmisc/drugs/XTC/sterm/"+tp->query_real_name())) 
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
  save_object("players/mythos/mmisc/drugs/XTC/sterm/"+tp->query_real_name());
  if(timer > 10) {
  if(tp->query_attrib("wil") < random(31)) {
  switch(random(5)) {
  case 0 : tell_object(tp,"You feel abit out of it.\n"); 
           tell_room(environment(tp),capitalize(tp->query_name())+
           " seems a bit dazed.\n"); break;
  case 1 : tell_object(tp,"You feel abit dizzy.\n"); 
           tell_room(environment(tp),capitalize(tp->query_name())+
           " stumbles.\n"); break;
  case 2 : tell_object(tp,"You bite your tongue.\n");
           tell_room(environment(tp),capitalize(tp->query_name())+
           " yelps in pain.\n"); break;
  case 3 : tell_object(tp,"You hear someone creeping up on you.\n"); break;
  case 4 : tell_object(tp,"You feel bad.\n"); break;
  }}}
  if(timer > 60) {
  if(cadd > 10) {
  if(tp->query_attrib("wil") < random(100) && !present("lterm_XTC",tp)) {
  move_object(clone_object("/players/mythos/mmisc/drugs/XTC/lterm.c"),tp);
  command("save",tp); }
  }
  tell_object(tp,"The drug's side effects wear off.\nYou feel a bit tired but overall you are fine.\n");
  destruct(this_object());
  return 1;}
  if(timer == 50) {
  tell_object(tp,"You feel cold shivers run up and down your back.\nYou feel ill.\n");
  command("puke",tp);
  }
  if(timer > 40) {
  restore_object("players/mythos/mmisc/drugs/XTC/add/"+tp->query_real_name());
  if(tp->query_ac() > 8) {
  tp->set_ac(8); }
  if(tp->query_hp() > 7*(tp->query_mhp())/8) {
  tp->add_hit_point(7*(tp->query_mhp())/8 - tp->query_hp()); }
  if(cadd > 20) {
  if(tp->query_attrib("wil") < random(60)) {
  tell_object(tp,"You need XTC.\nWithout it you feel you can not face the day.\n");
  }
  }
  }
  if(timer == 35) {
  tell_object(tp,"You feel dizzy.  You may wish to take a rest.\n");
  }
  if(timer == 20) {
  tell_object(tp,"The room seems to fade.  Then things seem to come back into focus.\n");
  }
  call_out("seffect",10);
}
