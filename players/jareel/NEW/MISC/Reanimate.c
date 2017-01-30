#include "/players/jareel/ansi.h"
#define user environment(this_object())

query_auto_load() {
    return "/players/jareel/NEW/MISC/Reanimate.c:"; }
 id(str){ return str == "mark" || str == "Zombie_Dragon_Mark"; }
short() {
    return HIK+"The Mark of the Legendary Dragon "+NORM+BOLD+"Necronsan"+NORM; }
long() {
    write("      A Mark that shows\n");
	write("       that you are one\n");
	write("      of the blessed to\n");
	write("     survive the horrors\n");
	write("    of the Dragon legend\n");
	write("          Necrosan.\n");
    write("    Death can be overcome...\n");
}
drop() {return 1;}
init() {
  call_out("hb",10);
  add_action("live","live");
}

hb() {
  if(environment(this_object())->query_ghost()) {
     command("live",environment(this_object()));
     return 1;}
    call_out("hb",10);
return 1;
}


live() {
    tell_room(environment(this_player()),"Suddenly...\n\t"+YEL+
               "There is a loud booming noise.....\n\n"+NORM);
    tell_object(this_player(),"You feel strange rush come over you....\n\n"+RED+"< < < < <B O O O M > > > > >\n\n"+NORM);
    call_other(this_player(), "remove_ghost", 0);
    tell_room(environment(this_player()),"\n"+NORM);
    return 1;
}