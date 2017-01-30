#include "/players/pestilence/ansi.h"

main(string str){
object target, web, comp;
object USER;
USER = this_player();
    if(this_player()->query_ghost()) return 0;
    if(this_player()->query_guild_rank() < 3) return 0;
    
        if(!this_player()->query_attack()){
               tell_object(this_player(),
                "You can only do this in combat!\n");
                return 1;}
        if(str){
        target = present(str, environment(this_player()));
        }
        else{
    target = this_player()->query_attack();
        }
        if(!target){
                  tell_object(this_player(), "You do not see "+str+" here.\n");
                  return 1;
            }

if(living(target)){
                if(this_player()->query_spell_point() < 30){
                        tell_object(this_player(), "You don't have enough mana for this.\n");
                        return 1;
                }
if(present("do_madness", target)) {
      tell_object( USER, capitalize(target->query_name())+" already suffers from madness!\n");
      return 1;
    }

                        if (present("do_infection", target)) {
                        tell_object(this_player(), "You cannot infect "+target->query_name()+" again!\n"); 
                        return 1; 
                }
if(random(100) > (USER->query_attrib("int") + USER->query_attrib("wil") + random(100))){
tell_object(USER,
"You attempt to infect "+target->query_name()+", but fail!\n");
USER->add_spell_point(-35);
return 1;
}
tell_object(USER,
"You focus your hatred on "+target->query_name()+" leaving them "+HBRED+"I N F E C T E D"+NORM+"!\n");
tell_room(environment(USER),
""+USER->query_name()+" focuses their hatred on "+target->query_name()+" leaving them "+HBRED+"I N F E C T E D"+NORM+"!\n",  ({USER}));
                USER->add_spell_point(-30);
                web = clone_object("/players/pestilence/closed/dark/obj/wound.c");
                move_object(web,target);
                return 1;
                }
        else return 0;
        return 1;
}
