#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";



reset(arg){
    if (arg) return;

}

short() { return "A computer"; }

long() {
    write("The computer is a plain PC, with LCD monitor and wireless keyboard.\n"+
          "It is possible to 'login', provided the userid and password are known.\n");
    return 1;}


init() {
  ::init();
  add_action("login","login");
  return; 
}

login() {
      if(present("paper",this_player())) return 0;
       write("Userid and password must be gotten at machining\n"+
                   "lab and at foundry lab, respectively.\n");
return 1;}

get(stri) {
    if(stri == "computer") {
        notify_fail("Please, dont remove the computer from this room.  It would fail its goal.\n");
        return 0;
    }
    return 0;
}

id(str) { return str == "computer_fran" || str == "computer" || str == "puter";}