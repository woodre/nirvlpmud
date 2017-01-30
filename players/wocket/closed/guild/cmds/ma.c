#include "/players/wocket/closed/ansi.h"
#include "/players/wocket/closed/guild/defs.h"

cmd(string str){

if(this_player()->query_attack()){
object attacker;
attacker = this_player()->query_attack();

attacker->hit_player(20);
tell_room(environment(this_player()),"EXTRIA HIT --- .9\n");
attacker->hit_player(20);
tell_room(environment(this_player()),"EXTRA HIT --- 1\n");
attacker->hit_player(20);
tell_room(environment(this_player()),"EXTRA HIT --- 3\n");
return 1;
}
write("you failed.\n");
return 0;
}
