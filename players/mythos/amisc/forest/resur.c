#include "/players/mythos/closed/ansi.h"
#define user environment(this_object())

query_auto_load() {
    return "/players/mythos/amisc/forest/resur.c:"; }
 id(str){ return str == "mark" || str == "mythos_mark"; }
short() {
    return RED + "The Mark of the Blessed" + NORM; }
long() {
    write("A Mark that shows that you are one of the blessed.\n");
    write("Death can be overcome...\n");
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
               "There is a loud keening sound.....\n\n"+NORM);
    tell_object(this_player(),"You feel odd....\n\n\t\t"+BLU+"<<<<<ZAP>>>>>\n\n"+NORM);
    call_other(this_player(), "remove_ghost", 0);
    tell_room(environment(this_player()),"\n"+NORM);
    tell_object(this_player(),"The Mark disappears....\n"+NORM);
    destruct(this_object());
    return 1;
}
