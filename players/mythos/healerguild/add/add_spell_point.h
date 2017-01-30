add_spell_point(arg) {
  object thypl;
  int TGR;
  int INF_MIN, INF_MAX, INF_ADD;
  thypl = this_player();
  if(thypl) 
    if (level < EXPLORE && thypl->query_interactive() && thypl != this_object()) {
      if(thypl->query_level() > EXPLORE) 
        log_file("POINTS", name + " sp-add "+ arg + call_other(thypl, "query_real_name", 0) + " " + ctime(time()) + "\n");
      else {
        if(environment(thypl) != environment(this_object())) {
          arg = 0;
          /* tell_object(thypl,"Player to Player Spell Point transfers are not allowed.\n"); */
          tell_object(thypl,cap_name+" is not here.\n");
          tell_object(this_object(),"Attempted Spell Point transfer Aborted.\n");
        return 1; }
        if(thypl->query_guild_name() == "healer") { 
           TGR = thypl->query_guild_rank();    /* between 5 and 40 */ 
           INF_MIN = liv_infuse + (3 - TGR/10)*arg/2; 
           INF_MAX = LIV_INFUSE_LIMIT/2 - TGR; 
           INF_ADD = (3 - TGR/10)*arg/2; 
           if(INF_MIN < 0) INF_MIN = 0; 
           if(INF_MAX < 0) INF_MAX = 0;
           if(INF_ADD < 0) INF_ADD = 0;
        } else { INF_MIN = infuse+3*arg/2; INF_MAX = (INFUSE_LIMIT)/2; INF_ADD = 3*arg/2; }
        if((INFUSE_LIMIT) < INF_MIN || infuse > INF_MAX) {
          int blah;
          blah = 2*((INFUSE_LIMIT) - infuse)/3;
          tell_object(thypl,cap_name+" must wait before absorbing "+arg+" spell points.\n");
          if(infuse < INF_MAX && blah > 0 )
             tell_object(thypl,cap_name+" may absorb up to "+blah+" spell points.\n");
          tell_object(this_object(),"You must wait before absorbing more spell points.\n");
          arg = 0;
        return 1; }
        if(arg > 0) infuse += INF_ADD;
      }
    }
    spell_points += arg;
    if(arg < 0 && guild_name=="Knights Templar" && this_object()->query_mounted()) spell_points += arg;
    if (spell_points > max_spell) spell_points = max_spell;
    /* spell points can go negative */
}
