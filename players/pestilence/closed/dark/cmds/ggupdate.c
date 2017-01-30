#include "/players/pestilence/ansi.h"

main(){
        object target, comp, USER;
        int spamount, here;
        int cost;
        int gr;
       USER = this_player();
        if(USER->query_ghost()) return 0;
    if (USER->query_attack()){
        write("You can't update while fighting.\n");
        return 1;
    }
   move_object(clone_object("/players/pestilence/closed/dark/dark.c"),USER);
  write("<"+
HIK+"Dark Order"+NORM+"> Guild Status Updated.\n");
  destruct(previous_object());
return 1; }
