fatal(){
        object target, comp;
        int spamount;
        int cost;
        int gr;
        if(USER->query_ghost()) return 0;
if(this_player()->query_guild_rank() < 2){ write("You can't use ability yet.\n"); return 1; }
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
                "You are too weak.\n");
                return 1;
        }
        
        if(USER->query_attack() && ATT->query_hp() < 60){
                if((ATT->query_hp()*10)/(ATT->query_mhp()) < 1){
        
/*
tell_object(USER,
HIK+"You pierce your opponent's heart with a solid blow"+HIW+"..."+NORM+"\n\n"+
HIR+"                   |          |          |\n"+
HIR+"               -"+HIW+"     ["+HIR+"  D  E  A  T  H"+HIW+"  ]"+HIR+"    - "+NORM+"\n"+
HIR+"                   |          |          |\n"+
ATT->query_name()+" crumbles from your blow!\n"+NORM);
*/
here = environment(this_player());
tell_room(here, 
 HIK+USER->query_name()+" tears "+USER->query_possessive()+" opponent's heart out with a fierce blow"+HIW+"..."+NORM+"\n\n");
tell_room(here,
HIR+"                   |          |          |\n"+
HIR+"               -"+HIW+"     ["+HIR+"  D  E  A  T  H"+HIW+"  ]"+HIR+"     -"+NORM+"\n"+
HIR+"                   |          |          |"+NORM+"\n");
tell_room(here,
"\n"+ATT->query_name()+" crumbles from "+USER->query_name()+"'s blow!\n");
                USER->add_spell_point(-cost);
                        target->hit_player(target->query_hp(), "other|pestilence");
                    if(target)
                        target->hit_player(cost * 4);
                        return 1;
                }
                tell_object(USER, "Your opponent is still too strong.\n");
                return 1;
        }
        tell_object(USER, "Your opponent is still too strong.\n");
        return 1;
}
