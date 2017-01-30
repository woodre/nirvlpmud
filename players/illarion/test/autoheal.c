static autoheal() {
    int x,y;
    object regen_ob;
    if (headache) {
        headache -= 1;
        if (headache == 0)
            tell_object(myself, "You no longer have a head ache.\n");
    }
/* changes to hp/sp regen by Forbin 2005.06.06 ************************************/
/*   -now supports multiple sp & hp regen objects *********************************/
    x=1;
    if((regen_ob = this_player()) && (regen_ob = present("hp_regen_object", regen_ob)))
    {
      while(regen_ob)
      {
        object ob;
        ob = next_inventory(regen_ob);
        if(y = (int)->query_hp_regen()) 
          x += y;
        regen_ob = ob;
      }
    }
        hit_point += intoxicated ? (3*x) : x; 
        if (hit_point > max_hp)
            hit_point = max_hp;
    x=1;
    if((regen_ob = this_player()) && (regen_ob = present("sp_regen_object", regen_ob)))
    {
      while(regen_ob)
      {
        object ob;
        ob = next_inventory(regen_ob);
        if(y = (int)->query_sp_regen()) 
          x += y;
        regen_ob = ob;
      }
    }
/* end addition by Forbin 2005.06.6 ***********************************************/    
        spell_points += intoxicated ? (3*x) : x;
        if (spell_points > max_spell)
            spell_points = max_spell;
    if (intoxicated) {
        if ((intoxicated -= 1) == 0) {
            headache = max_headache;
            max_headache = 0;
            tell_object(myself,
               "You suddenly without reason get a bad head ache.\n");
            if ((hit_point -= 3) < 0)
                hit_point = 0;
        }
    }
   if (interactive(this_object()))
    call_out("autoheal", INTERVAL_BETWEEN_HEALING);
}