#define tp environment(this_object())
id(str) { return str == "lterm_acid" || str == "lterm"; }
int cadd, ctol, catime;
query_auto_load() { return "/players/mythos/mmisc/drugs/acid/lterm.c:"; }

init_arg() {
  restore_object("players/mythos/mmisc/drugs/acid/add/"+tp->query_real_name());
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
  if(tp->query_attrib("wil") < random(cadd + 25)) {
  switch(random(5)) {
  case 0 : tell_object(tp,"You feel nauseous.\n"); 
           command("puke",tp); break;
  case 1 : command("cry",tp); break;
  case 2 : command("laugh",tp); break;
  case 3 : tell_object(tp,"Something is wrong.\n"); break;
  case 4 : tell_object(tp,HIR+"Pr"+NORM+HIY+"ett"+NORM+HIG+"y co"+
                      NORM+HIB+"lors!\n"+NORM); break;
  }}
  if(!present("sterm_acid",tp)) {
  if(tp->query_attrib("mag") > 18) {
  tp->set_attrib("mag",18);
  tell_object(tp,"The long term effects of acid has ruined your mental powers!\n"+
                 "You may wish to seek treatment at a medical center.\n");}
  }
  if(tp->query_sp() > 3*(tp->query_msp())/4) {
  tp->add_spell_point(3*(tp->query_msp())/4 - tp->query_sp()); }
  tp->add_spell_point(-2);
  call_out("leffect",10);
}
