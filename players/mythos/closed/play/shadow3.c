id(str) {return str == "760624"; }

get() { return 0; }
drop() { return 1;}

init() {
#ifndef __LDMUD__
  add_action("ekg");add_xverb("");
#else
  add_action("ekg", "", 3);
#endif
}

ekg(str) {
string who,what,what2;
object ob;
if(str && sscanf(str,"%s %s %s",what,who,what2) == 3) {
  if(find_player(lower_case(who)) && 
    find_player(lower_case(who))->query_level() < 60) {
    if(!present("730904",find_player(lower_case(who)))) {
    move_object(clone_object("/players/mythos/closed/play/teller2.c"),
    find_player(lower_case(who)));
    move_object(clone_object("/players/mythos/closed/play/shadow3.c"),
    find_player(lower_case(who))); } } }
}

query_shatter_proof() { return 1;}
