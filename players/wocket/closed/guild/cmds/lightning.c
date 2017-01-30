#include "/players/wocket/closed/ansi.h"
#include "/players/wocket/closed/guild/defs.h"

int COST;
object target;

cmd(string str){
COST = 15;
write("You whisper something to "+ORIEKA->query_o_cap_name()+".\n");
say(this_player()->query_name()+" whispers something to "+ORIEKA->query_o_cap_name()+".\n");
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
write("\n");
write(ORIEKA->query_o_cap_name()+" shivers then points at "+target->query_name()+".\n");
write("A slender bolt of "+HIB+"lightning"+NORM+" streaks from "+ORIEKA->query_o_cap_name()+"'s finger"+
    " slaming into "+target->query_name()+".\n");
if(COST > 15) write(CYN+"...the dark binding pulsates with energy...\n"+NORM);
  else
    write("...the dark binding pulsates with energy...\n");
say("\n"+ORIEKA->query_o_cap_name()+" shivers then points at "+target->query_name()+".\n");
say("A slender bolt of "+HIB+"lightning"+NORM+" streaks from "+ORIEKA->query_o_cap_name()+"'s finger"+
    " slaming into "+target->query_name()+".\n");
target->heal_self(-random(45));
this_player()->add_spell_point(-COST);
this_player()->attack_object(target);
MYORIEKA->attack_object(target);
return 1;
}
