#define tp environment(this_object())
id(str) { return str == "sterm_barbs" || str == "sterm"; }
int timer;
static int cadd, ctol, catime;
query_auto_load() { return "/players/mythos/mmisc/drugs/barbs/sterm.c:"; }

init_arg() {
  if(!restore_object("players/mythos/mmisc/drugs/barbs/sterm/"+tp->query_real_name())) 
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
  save_object("players/mythos/mmisc/drugs/barbs/sterm/"+tp->query_real_name());
  if(timer > 10) {
  if(tp->query_attrib("wil") < random(31)) {
  switch(random(5)) {
  case 0 : tell_object(tp,"You feel abit out of it.\n"); 
           tell_room(environment(tp),capitalize(tp->query_name())+
           " seems a bit dazed.\n"); break;
  case 1 : tell_object(tp,"You feel abit dizzy.\n"); 
           tell_room(environment(tp),capitalize(tp->query_name())+
           " stumbles.\n"); break;
  case 2 : tell_object(tp,"You mumble to yourself.\n");
           tell_room(environment(tp),capitalize(tp->query_name())+
           " mumbles something.\n"); break;
  case 3 : tell_object(tp,"You dont feel good.\n"); break;
  case 4 : tell_object(tp,"You are tired.\n"); break;
  }}}
  if(timer > 50) {
  if(cadd > 10) {
  if(tp->query_attrib("wil") < random(100) && !present("lterm_barbs",tp)) {
  move_object(clone_object("/players/mythos/mmisc/drugs/barbs/lterm.c"),tp);
  command("save",tp); }
  }
  tell_object(tp,"The drug's side effects wear off.\nYou feel a bit tired but overall you are fine.\n");
  destruct(this_object());
  return 1;}
  if(timer == 40) {
  tell_object(tp,"You feel cold shivers run up and down your back.\nYou feel ill.\n");
  }
  if(timer > 40) {
  tp->set_ac(0);
  restore_object("players/mythos/mmisc/drugs/barbs/add/"+tp->query_real_name());
  if(cadd > 10) {
  if(tp->query_attrib("wil") < random(70)) {
  tell_object(tp,"You need barbs.\nWithout it you feel you can not face the day.\n");
  }
  }
  }
  if(timer == 30) {
  tell_object(tp,"You feel dizzy.  You may wish to take a rest.\n");
  tp->set_wc(3);
  }
  call_out("seffect",10);
}
