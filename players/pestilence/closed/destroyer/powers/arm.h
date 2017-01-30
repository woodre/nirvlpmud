arm(string str){
object target, web, comp;
    if(USER->query_ghost()) return 0;
    if(USER->query_guild_rank() < 6) return 0;
/*    
        if(!USER->query_attack()){
                tell_object(USER,
                "You can only do this in combat!\n");
                return 1;}
*/
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
        if(target->query_weapon()){ 
                  tell_object(USER, ""+target->query_name()+" appears to be already armed.\n");
                  return 1;
            }
 
if(living(target)){
                if(USER->query_spell_point() < 30){
                        tell_object(USER, "You don't have enough mana for this.\n");
                        return 1;
                }
                        if (present("arm_ob", target)) {
                        tell_object(USER, "You cannot arm "+target->query_name()+" again!\n"); 
                        return 1; 
                }
if(random(100) > (USER->query_attrib("int") + USER->query_attrib("wil") + random(100))){
tell_object(USER,
"You attempt to arm "+target->query_name()+", but fail!\n");
USER->add_spell_point(-20);
return 1;
}
tell_object(USER, 
"You focus on "+target->query_name()+", and cause them to be armed!\n");
tell_room(environment(USER),
""+USER->query_name()+" focuses on "+target->query_name()+", and cause them to be armed!\n",  ({USER}));
                USER->add_spell_point(-30);
                web = clone_object("/players/pestilence/closed/destroyer/obj/arm.c");
                move_object(web,target);
              target->start_wielding();
                return 1;
                }
        else return 0;
        return 1;
}
