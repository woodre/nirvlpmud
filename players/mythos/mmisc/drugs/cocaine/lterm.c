#define tp environment(this_object())
id(str) { return str == "lterm_cocaine" || str == "lterm"; }
int cadd, ctol, catime;
query_auto_load() { return "/players/mythos/mmisc/drugs/cocaine/lterm.c:"; }

init_arg() {
  restore_object("players/mythos/mmisc/drugs/cocaine/add/"+tp->query_real_name());
}

get() { return 0; }
drop() {return 1;}
query_weight() { return 0; }
query_value() { return 0; }

reset(arg) {
if(arg) return;
    call_out("leffect",10);
}

init() {
  add_action("lsex","sex"):
}

lsex(str) {
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

leffect() {
  if(tp->query_attrib("wil") < random(cadd + 25)) {
  switch(random(5)) {
  case 0 : tell_object(tp,"You feel nervous.\n"); 
            tell_room(environment(tp),capitalize(tp->query_name())+
           " looks a bit nervous.\n"); break;
  case 1 : command("frown",tp); break;
  case 2 : command("sigh",tp); break;
  case 3 : tell_object(tp,"Something is wrong.\n"); break;
  case 4 : tell_object(tp,"You crave cocaine....\n"); break;
  }}
  if(!present("sterm_cocaine",tp)) {
  if(tp->query_attrib("mag") > 15) {
  tp->set_attrib("mag",15); 
  tell_object(tp,"The long term effects of cocaine has ruined your mental stability.\n"+
                 "You may wish to seek treatment at a medical center.\n");}
  }
  tp->add_spell_point(-10);
  tp->add_hit_point(-2);
  call_out("leffect",10);
}
