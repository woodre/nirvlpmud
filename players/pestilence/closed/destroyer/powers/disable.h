disable(string str){
object target, web, comp;
    if(USER->query_ghost()) return 0;
if(this_player()->query_guild_rank() < 6){ write("You can't use this skill yet.\n"); return 1; }
/*
    if(USER->query_guild_rank() < 4) return 0;
*/    
    if (!USER->query_attack()){
        write("You must be fighting to use this skill.\n");
        return 1;
}
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
                        tell_object(USER, "You don't have enough energy for this.\n");
                        return 1;
                }
                        if(target->webbed()){ 
                        tell_object(USER, "You cannot disable "+target->query_name()+" again at this time!\n"); 
                        return 1; 
                }
if(random(100) > (USER->query_attrib("wil") + USER->query_attrib("pie") + random(100))){
tell_object(USER,
"You attempt to disable "+target->query_name()+" with a fierce kick to the knee, but fail!\n");
USER->add_spell_point(-20);
return 1;
}
tell_room(environment(USER),
""+USER->query_name()+" ravagely kicks "+target->query_name()+" in the knee, leaving them slightly disabled!\n", ({USER}));
tell_object(USER,
"You ravagely kick "+target->query_name()+" in the knee, leaving them slightly disabled!\n");          
                USER->add_spell_point(-35);
                web = clone_object("/players/pestilence/closed/destroyer/obj/disable.c");
                web->set_time(15 + USER->query_level() + USER->query_extra_level());
                web->web_person(target);
                return 1;
                }
        else return 0;
        return 1;
}
