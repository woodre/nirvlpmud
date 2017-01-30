heal_self(h) {
object thypl;
int liv_infuse,LIV_INFUSE_LIMIT;
int TGR;
int INF_MIN, INF_MAX, INF_ADD;
  if(dieing) return;
  if (!h)return;
  thypl = this_player();
  if(thypl)
   if(this_object()->query_interactive())
     if (level < EXPLORE && thypl->query_interactive() && thypl != this_object()) {
       if(thypl->query_level() > EXPLORE)
         log_file("POINTS", name + " heal_self "+ h + call_other(thypl, "query_real_name", 0) + " " + ctime(time()) + "\n");
       else {
         if(environment(thypl) != environment(this_object())) {
           h = 0;
           tell_object(thypl,cap_name+" is not here.\n");
           /* tell_object(thypl,"Player to Player Healing transfers are not allowed.\n"); */
           tell_object(this_object(),"Attempted Healing transfer Aborted.\n");
         return 1; }
         liv_infuse = this_object()->query_infuse();
         LIV_INFUSE_LIMIT = this_object()->query_infuse_limit();
         if(thypl->query_guild_name() == "healer") { 
           TGR = thypl->query_guild_rank();   /* between 5 and 40 */ 
           INF_MIN = liv_infuse + (6 - TGR/7)*h/2; 
           INF_MAX = LIV_INFUSE_LIMIT/2 - TGR; 
           INF_ADD = (6 - TGR/7)*h/2; 
           if(INF_MIN < 0) INF_MIN = 0; 
           if(INF_MAX < 0) INF_MAX = 0;
           if(INF_ADD < 0) INF_ADD = 0;
        } else { INF_MIN = liv_infuse+6*h/2; INF_MAX = LIV_INFUSE_LIMIT/2; INF_ADD = 6*h/2; }
         if(LIV_INFUSE_LIMIT < INF_MIN || liv_infuse > INF_MAX) {
           int blah;
           blah = (LIV_INFUSE_LIMIT - liv_infuse)/3;
           tell_object(thypl,cap_name+" must wait before absorbing "+h+" healing.\n");
           if(liv_infuse < INF_MAX && blah > 0 )
             tell_object(thypl,cap_name+" may absorb up to "+blah+" healing.\n");
           tell_object(this_object(),"You must wait before absorbing more healing.\n");
           h = 0;
         return 1;}
         if(h > 0) this_object()->add_infuse(INF_ADD);
      }
    }
    if(!is_npc)
      if(!this_object()->query_interactive()) {
         say(cap_name+" is disconnected.\n");
         stop_fight(); this_player()->stop_fight();
      return 0;}
    hit_point += h;
    if (hit_point > max_hp) hit_point = max_hp;
    spell_points += h;
    if (spell_points > max_spell) spell_points = max_spell;
   if(!attacker_ob && h < 0) hit_player(1);
   if(hit_point < 0) hit_point = 0;
}
