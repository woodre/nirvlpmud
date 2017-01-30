fatal(){
        object target, comp;
        int spamount;
        int cost;
        int gr;
        if(USER->query_ghost()) return 0;
if(this_player()->query_guild_rank() < 3){ write("You can't use this skill yet.\n"); return 1; }
/*
if(this_player()->query_guild_rank() < 2){ write("You can't use ability yet.\n"); return 1; }
*/
        if(!USER->query_attack()){
                tell_object(USER,
                "You can only do this in combat!\n");
                return 1;
        }
   if(!USER->query_weapon()){
      tell_object(USER,
      "You must have a weapon wielded!\n");
      return 1;
      }
        target = USER->query_attack();
        if(!target->query_npc()){
                tell_object(USER,
                "You cannot do this to players!\n");
                return 1;
        }
   if(!living(target)){
      tell_object(USER,
      "That didn't work.\n");
      return 1;
      }
        cost = target->query_hp()/3;
        if(cost > USER->query_sp()){
                tell_object(USER,
                "You don't have enough sps.\n");
                return 1;
        }
        
        if(USER->query_attack() && ATT->query_hp() < 60){
                if((ATT->query_hp()*10)/(ATT->query_mhp()) < 1){
        
here = environment(this_player());
tell_room(here, 
 YEL+USER->query_name()+" charges at "+ATT->query_name()+YEL+", then quickly circling behind them,\ngrabbing their head and quickly "+USER->query_name()+YEL+" "+NORM+"\n\n");
tell_room(here,
HIR+"\t\tS N A P S"+NORM+"\n"+
"\n"+YEL+ATT->query_name()+""+YEL+"'s neck, killing them instantly"+NORM+"!\n");
                USER->add_spell_point(-cost);
                        target->heal_self(-(target->query_hp()));
                        target->hit_player(cost * 8);
                        return 1;
                }
                tell_object(USER, "Your opponent is still too strong.\n");
                return 1;
        }
        tell_object(USER, "Your opponent is still too strong.\n");
        return 1;
}
