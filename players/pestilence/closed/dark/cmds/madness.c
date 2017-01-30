#include <ansi.h>

main(string str){
  object target, web, comp;
  object USER;
  USER = this_player();
  if(this_player()->query_ghost()) 
    return 0;
  if(this_player()->query_guild_rank() < 7) 
    return 0;
    
  if(!this_player()->query_attack()) {
    tell_object(this_player(), "You can only do this in combat!\n");
    return 1;
  }
  if(str){
    target = present(str, environment(this_player()));
  }
  else{
    target = this_player()->query_attack();
  }

  if(!target) {
    tell_object(this_player(), "You do not see "+str+" here.\n");
    return 1;
  }

  if(living(target)) {
    if(this_player()->query_spell_point() < 150) {
      tell_object(this_player(), "You don't have enough mana for this.\n");
      return 1;
    }
    if(present("do_infection", target)) {
      tell_object( USER, capitalize(target->query_name())+" ignores the shadows.\n"); 
      return 1;
    }
    if(present("do_madness", target)) {
      tell_object( USER, capitalize(target->query_name())+" already suffers from madness!\n"); 
      return 1; 
    }
    if(random(100) > (USER->query_attrib("int") + USER->query_attrib("wil") + random(100))) {
      tell_object(USER, "You attempt madness on "+target->query_name()+", but fail!\n");
      USER->add_spell_point(-50);
      return 1;
    }
    tell_object(USER, "You focus your will and "+HIK+"black tentacles"+NORM+ " rise from the ground\n\
under "+target->query_name()+ "'s feet driving them into "+HIR+" m A d N e S s!\n"+NORM);
    tell_room(environment(USER), 
      USER->query_name()+" focuses their will and "+HIK+"black tentacles"+NORM+ " rise from the\n\
ground under "+target->query_name()+ "'s feet driving them into "+HIR+" m A d N e S s!\n"+NORM,  ({USER}));
    USER->add_spell_point(-150);
    web = clone_object("/players/pestilence/closed/dark/obj/madness.c");
    move_object(web,target);
    return 1;
  }
  else 
    return 0;
  return 1;
}
