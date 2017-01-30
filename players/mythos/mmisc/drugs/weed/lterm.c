#define tp environment(this_object())
id(str) { return str == "lterm_weed" || str == "lterm"; }
int cadd, ctol, catime;
query_auto_load() { return "/players/mythos/mmisc/drugs/weed/lterm.c:"; }

init_arg() {
  restore_object("players/mythos/mmisc/drugs/weed/add/"+tp->query_real_name());
}

get() { return 0; }
drop() {return 1;}
query_weight() { return 0; }
query_value() { return 0; }

reset(arg) {
if(arg) return;
    call_out("leffect",10);
}

leffect() {
  if(tp->query_attrib("wil") < random(cadd)) {
  switch(random(5)) {
  case 0 : tell_object(tp,"You feel nauseous.\n"); 
           command("puke",tp); break;
  case 1 : command("shiver",tp); break;
  case 2 : command("laugh",tp); break;
  case 3 : tell_object(tp,"Something is wrong.\n"); break;
  case 4 : tell_object(tp,"Things go black for a second.\n"); break;
  }}
  if(!present("sterm_weed",tp)) {
  if(tp->query_attrib("luc") > 18) {
  tp->set_attrib("luc",18);
  tell_object(tp,"The long term effects of weed has ruined your physical stamina.\n"+
                 "You may wish to seek treatment at a medical center.\n");}
  }
  call_out("leffect",10);
}
