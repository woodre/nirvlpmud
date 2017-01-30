wound(string str){
object target, web, comp;
    if(USER->query_ghost()) return 0;
    if(USER->query_guild_rank() < 3) return 0;
    
        if(!USER->query_attack()){
                tell_object(USER,
                "You can only do this in combat!\n");
                return 1;}
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

if(living(target)){
                if(USER->query_spell_point() < 30){
                        tell_object(USER, "You don't have enough mana for this.\n");
                        return 1;
                }
                        if (present("wound", target)) {
                        tell_object(USER, "You cannot wound "+target->query_name()+" again!\n"); 
                        return 1; 
                }
if(random(100) > (USER->query_attrib("int") + USER->query_attrib("wil") + random(100))){
tell_object(USER,
"You attempt to wound "+target->query_name()+", but fail!\n");
USER->add_spell_point(-20);
return 1;
}
tell_object(USER,
"You cause a "+HIR+"bloody"+NORM+" wound on "+target->query_name()+" leaving them in extreme pain!\n");
tell_room(environment(USER),
""+USER->query_name()+" inflicts a "+HIR+"bloody"+NORM+" wound on "+target->query_name()+" leaving them extreme pain!\n",  ({USER}));
                USER->add_spell_point(-30);
                web = clone_object("/players/pestilence/closed/dark/obj/wound.c");
                move_object(web,target);
                return 1;
                }
        else return 0;
        return 1;
}
