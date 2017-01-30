#include "/players/wocket/closed/ansi.h"
#include "/players/wocket/closed/guild/defs.h"

int COST;
object target;

cmd(string str){
COST = 15;
write(this_player()->query_name()+" says:  "+BOLD+"VINKITE "+capitalize(str)+NORM+"\n");
if(str == ""){
    target = (object) this_player()->query_attack();
    }
else{
    target = present(str,environment(this_player()));
    }
if(!target){
    write("Your orieka is confused.\n");
    return 1;
    }

if(!target->is_npc()){
    write(ORIEKA->query_o_cap_name()+" shakes its head.\n");
    say(ORIEKA->query_o_cap_name()+" shakes its head.\n");
    return 1;
}
if(this_player()->query_spell_point() < 15){
    write(ORIEKA->query_o_cap_name()+" can not drain enough energy.\n");
    return 1;
}
if(MYORIEKA->query_sp() > 15){
COST = 15;
MYORIEKA->add_sp(-15);
}
else
COST = 45;
if(this_player()->query_spell_point() < COST){
    write(ORIEKA->query_o_cap_name()+" can not drain enough energy.\n");
    return 1;
}
call_out("dospell",1);
write("test1\n");
}

dospell(){
write("test2\n");
write("\n");
write("...the binding begins to pulsate...\n");
write(ORIEKA->query_o_cap_name()+" summons a gust of wind to destroy "+target->query_name()+".\n");
write("The breeze wales as it rushes by.\n");
write("Sound is shattered as "+target->query_name()+" screams in pain.\n");
target->heal_self(-random(45));
this_player()->add_spell_point(-COST);
this_player()->attack_object(target);
return 1;
}
