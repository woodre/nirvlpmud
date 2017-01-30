#include "/players/wocket/closed/ansi.h"
#include "/players/wocket/closed/guild/defs.h"

cmd(string str){
int HEAL;
object corpse;
write("You say:  "+BOLD+"ryeish\n"+NORM);

corpse = present("corpse",environment(this_player()));
if(!corpse){
    write(ORIEKA->query_o_cap_name()+" doesn't see a corpse.\n");
    say(ORIEKA->query_o_cap_name()+" searches around.\n");
    return 1;
    return 0;
}
if(!corpse->heal_value()){
    write(ORIEKA->query_o_cap_name()+" eyes the corpse carefully.\nThat is not a real corpse.\n");
    say(ORIEKA->query_o_cap_name()+" eyes the corpse carefully.\n");
    return 1;
}
HEAL = 15*corpse->heal_value();

write(ORIEKA->query_o_cap_name()+" summons a dark fog which eats away at the corpse.\n");
say(ORIEKA->query_o_cap_name()+" summons a dark fog which eats away at the corpse.\n");
MYORIEKA->add_hit_point(HEAL/4);
MYORIEKA->add_sp(3*(HEAL/4));
destruct(corpse);
write("HEAL VALUE:  "+HIR+HEAL+NORM+"\n");
return 1;
}
