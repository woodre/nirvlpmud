#include "/players/pestilence/ansi.h"

main(string str) {
object target, web, comp;
int USER;
USER = this_player();
    if(USER->query_ghost()) return 0;
    if(USER->query_guild_rank() < 4) return 0;
    
        if(str){
        target = present(str, environment(USER));
        }
        else{
    target = USER->query_attack();
        }
        if(!target){
                  tell_object(USER, "You do not see "+str+" here.\n");
                  return 1;
            }
        if(target->is_living() && !target->query_npc()){
                write("You cannot cast this on players!\n");


        }
if(target->query_npc() && living(target)){
                if(USER->query_spell_point() < 30){
                        tell_object(USER, "You don't have enough mana for this.\n");
                        return 1;
                }
                        if(target->webbed()){ 
                        tell_object(USER, "You cannot chain "+target->query_name()+" again!\n"); 
                        return 1; 
                }
if(random(100) > (USER->query_attrib("int") + USER->query_attrib("wil") + random(100))){
tell_object(USER,
"You attempt to chain "+target->query_name()+", but fail!\n");
USER->add_spell_point(-20);
return 1;
}
tell_room(environment(USER),
""+HIK+"Darkness"+NORM+" erupts around "+target->query_name()+" leaving them "+HIR+"maniacally chained"+NORM+" to the ground!\n", ({USER}));
tell_object(USER,
""+HIK+"Darkness"+NORM+" erupts around "+target->query_name()+" leaving them "+HIR+"maniacally chained"+NORM+" to the ground!\n");          
                USER->add_spell_point(-35);
                web = clone_object("/players/pestilence/closed/dark/obj/distraught.c");
                web->set_time(20 + USER->query_level() + USER->query_extra_level());
                web->web_person(target);
                return 1;
                }
        else return 0;
        return 1;
}
