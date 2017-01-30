#include "/players/pestilence/ansi.h"

main(){
        object target, comp, USER, wep, myob;
        int spamount, here;
        int cost;
        int gr;
       myob = present("pesty_guild", this_player());
       USER = this_player();
        if(USER->query_ghost()) return 0;
  if(USER->query_weapon()) {
     write("You must unwield to update.\n"); return 1; }
 if(myob->query_offwep()) {
     write("You must unwield to update.\n"); return 1; }
    if (USER->query_attack()){
        write("You can't update while fighting.\n");
        return 1;
    }
  previous_object()->save_me();
  destruct(previous_object());
  write("<"+
HIK+"Dark Order"+NORM+"> Guild Status Updated.\n");
  move_object(clone_object("/players/pestilence/closed/dark/dark.c"),USER);
return 1; }
