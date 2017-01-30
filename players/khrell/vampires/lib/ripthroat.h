ripthroat(){
        object target, comp;
        int spamount;
        int cost;
        int gr;
        if(USER->query_ghost()) return 0;
   gr = this_player()->query_guild_rank();
   if(gr < 4) return 0;
   if(USER->query_attrib("dex") < 20){
    write("Your dexterity is too low for such a feat.\n");
    return 1;
    }

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
        
tell_object(USER,
RED+"You open your mouth wide, extend your fangs and"+HIW+"..."+NORM+"\n\n"+
HIR+"              ~  ~ ~~  "+NORM+RED+"R   I   P  "+NORM+HIR+"  ~~ ~  ~"\n+
"                          out their throat!\n\n"+
ATT->query_name()+"gurgles and stumbles then....\n\n"+
ATT->query_name()+" falls at your feet, dead!\n"+NORM);
                USER->add_spell_point(-cost);
                        target->heal_self(-(target->query_hp()));
                        target->hit_player(gr * 20);
                        return 1;
                }
                tell_object(USER, "Your opponent is still too healthy.\n");
                return 1;
        }
        tell_object(USER, "Your opponent is still too healthy.\n");
        return 1;
}
