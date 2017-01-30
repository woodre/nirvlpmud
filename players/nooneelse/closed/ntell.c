#include "/players/nooneelse/ansi.h"

int check, li;

id(str) { return str == "ntell"; }

reset(arg) {
  if (arg) return;
  check = 0;
  li = 0;
}

silence(n) { check = n; }
query_silence() { return check; }
listen(a) { li = a; }

long() {
  write("\nAn {N}tell to Nooneelse... blatantly stolen from Eurale\n"+
        "                             (with his permission)\n"+
        "Usage: 'ntell' to talk, 'ntelle' to emote\n");
}

short() { return HIC+"{N}tell"+NORM; }

drop() {return 1;}
get() { return 0; }

/*  for autoload, add the following two lines: */
/*  query_auto_load() { return "/players/nooneelse/closed/ntell.c:"; }  */

init() {
  add_action("ntell",  "ntell");
  add_action("ntelle", "ntelle");
}

ntell(str) {
  string what, who;
  if (!str) {
    write("Ntell Nooneelse what?\n");
    return 1;
  }
  if (!sscanf(str, "%s", what)) {
    write("Usage: ntell [what]\n");
    return 1;
  }
  if (!find_player("nooneelse") || check == 1) {
    write("Nooneelse is not here....\n");
    return 1;
  }
  tell_object(find_player("nooneelse"),
              HIC+"{N} "+capitalize(this_player()->query_real_name())+
              " ntells you: "+NORM+what+"\n");
  write("You ntell Nooneelse : "+HIC+what+NORM+"\n");
  return 1; 
}

ntelle (str) {
  string whats;

  if (!str) {
    write("You ntelle what to Nooneelse?\n");
    return 1;
  }
  if (!sscanf(str, "%s", whats)) {
    write("Usasge: ntelle [what]\n");
    return 1;
  }
  if (!find_player("nooneelse") || check == 1) {
    write("Nooneelse is not here....\n");
    return 1;
  }
  tell_object(find_player("nooneelse"),
              HIC+"{N} "+capitalize(this_player()->query_real_name())+
              " "+whats+NORM+"\n");
  write(HIC+"You "+whats+" at Nooneelse"+NORM+"\n");
  return 1;
}

