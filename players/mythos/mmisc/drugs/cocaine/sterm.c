#define tp environment(this_object())
id(str) { return str == "sterm_cocaine" || str == "sterm"; }
int timer;
static int cadd, ctol, catime;
query_auto_load() { return "/players/mythos/mmisc/drugs/cocaine/sterm.c:"; }

init_arg() {
  if(!restore_object("players/mythos/mmisc/drugs/cocaine/sterm/"+tp->query_real_name())) 
  return;
}

get() { return 0; }
drop() {return 1;}
query_weight() { return 0; }
query_value() { return 0; }
set_timer(j) { timer = j; }

reset(arg) {
if(arg) return;
    call_out("ceffect",10);
}

init() {
  add_action("ssex","sex"):
}

ssex(str) {
  if(!str) { write("What?\n"); return 1;}
  if(tp->query_gender() == "male") {
    write("Hmmm....  \nYou can't seem to get it up.\n"); }
    else {
    write("Somehow you don't feel up to it.\n");}
    say(capitalize(tp->query_real_name())+
    " wished to have sex but was somehow unable to.\n");
    if(tp->query_gender() == "male") {
    say("A possible impotence....\n"); }
return 1;}

ceffect() {
  move_object(this_object(),tp);
  timer = timer + 1;
  save_object("players/mythos/mmisc/drugs/cocaine/sterm/"+tp->query_real_name());
  if(timer > 10) {
  if(tp->query_attrib("wil") < random(31)) {
  switch(random(5)) {
  case 0 : tell_object(tp,"Your heart flutters...\n"); 
           tell_room(environment(tp),capitalize(tp->query_name())+
           " looks a bit flushed\n"); break;
  case 1 : tell_object(tp,"You feel wanton.\n"); break;
  case 2 : tell_object(tp,"You feel really good.\n"); break;
  case 3 : tell_object(tp,"It is a bit hard to breath.\n"); break;
  case 4 : tell_object(tp,"You are in a state of bliss.\n");
            tell_room(environment(tp),capitalize(tp->query_name())+
           " looks very happy!\n"); break;
  }}}
  if(timer > 60) {
  if(cadd > 10) {
  if(tp->query_attrib("wil") < random(100) && !present("lterm_cocaine",tp)) {
  move_object(clone_object("/players/mythos/mmisc/drugs/cocaine/lterm.c"),tp);
  command("save",tp); }
  }
  tell_object(tp,"The drug's effects wear off.\nYou feel a bit tired but overall you are fine.\n");
  destruct(this_object());
  return 1;}
  if(timer == 50) {
  tell_object(tp,"You feel cold shivers run up and down your back.\nYou feel ill.\n");
  commnd("puke",tp);
  }
  if(timer > 50) {
  restore_object("players/mythos/mmisc/drugs/cocaine/add/"+tp->query_real_name());
  if(cadd > 20) {
  if(tp->query_attrib("wil") < random(40)) {
  tell_object(tp,"You need cocaine.\nWithout it you feel you can not face the day.\n");
  }
  }
  }
  if(timer > 30) {
  if(random(10) == 0) {
  tell_object(tp,"You feel dizzy.  You may wish to take a rest.\n"); }
  if(tp->query_sp() > 3*(tp->query_msp())/4) {
  tp->add_spell_point(3*(tp->query_msp())/4 - tp->query_sp()); }
  if(tp->query_wc() > 5) {
  tp->set_wc(5); }
  }
  if(timer == 20) {
  tell_object(tp,"The room seems to fade.  Then things seem to come back into focus.\n");
  }
  call_out("seffect",10);
}
