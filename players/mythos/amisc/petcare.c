#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
#define user environment(this_object())
#define att user->query_attack()
#define attname att->query_name()

id(str) { return str == "petcare"; }

drop() {return 1;}

short() { return "A Glowing Band of Protection";}

init() {
  ::init();
  if(user->query_npc() != 1) {
  write("You may not use this!\n");
  destruct(this_object());
  }
  call_out("check",3);
  }

check() {
  if(att) {
    if(att->query_npc() != 1) {
    tell_room(environment(user),"\n\t\tF\tL\tA\tS\tH\n\n"+
             "A VOICE booms:  The GODS are angry!  Be gone miscreant!\n\n");
    tell_object(att,"The VOICE booms: A curse is on ye!\n"+BWHT+WHT);
    move_object(att,"/room/church.c");
    tell_room(environment(user),"Suddenly, "+capitalize(attname)+" is gone...\n");
    user->stop_fight();
    call_out("check",3);
    return 1;}
  call_out("check",3);
return 1;}
call_out("check",3);
return 1;}
