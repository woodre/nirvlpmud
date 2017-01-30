#include "/players/wocket/closed/ansi.h"
#include "/players/wocket/closed/guild/defs.h"

cmd(string str){
write("You say:  "+BOLD+"KANA "+capitalize(str)+NORM+"\n");
say(this_player()->query_name()+" says:  "+BOLD+"KANA "+capitalize(str)+NORM+"\n");
if(!present(str,environment(this_player()))){
    write(ORIEKA->query_o_cap_name()+" shakes its head.\n");
    say(ORIEKA->query_o_cap_name()+" shakes its head.\n");
    return 1;
}
if(!present(str,environment(this_player()))->is_npc() == 1){
    write("The orieka shakes its head.\n");
    say("The orieka shakes its head.\n");
    return 1;
}
if(present(str,environment(this_player())) == MYORIEKA){
    write(ORIEKA->query_o_cap_name()+" growls and shakes its head.\n");
    say(ORIEKA->query_o_cap_name()+" growls and shakes its head.\n");
    return 1;
}
write(ORIEKA->query_o_name()+" wales as it rushes to attack.\n");
say(ORIEKA->query_o_name()+" wales as it rushes to attack.\n");
MYORIEKA->attack_object(present(str,environment(this_player())));
return 1;
}
