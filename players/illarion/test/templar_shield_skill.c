int skill_check_test(object wearer, int raw_dam) {
  int ac_bonus,res,wres,align,pie,dex;
  object shield_ob,weapon_ob;
  string weapon_type;
  shield_ob=wearer->query_shield();
  weapon_ob=wearer->query_weapon();
  pie=wearer->query_attrib("pie");
  dex=wearer->query_attrib("dex");
  align=wearer->query_alignment();
  if(weapon_ob) weapon_type=weapon_ob->query_type();
  /* More defensive capabilities based on weapon skill */
  if(weapon_type) {
    int wskill;
    wskill=query_skill(weapon_type);
    if(wskill && align > 0 && random(dex) > 15) {
      wres=10+random(2*wskill);
      wres=100*wres*align/1000;
      if(wres < 100)
        wres=0;
      else
        tell_object(wearer,"You partially deflect the blow with your "+weapon_type+".\n");
      
    }
  }
  if(shield && shield_ob) {
    /* Original Shield Code, reworked for efficiency */
    ac_bonus=random(shield);
    if(!ac_bonus)
      ac_bonus=1;
    else if(ac_bonus >3)
      if(random(100)>15)
        ac_bonus=3;
      else
        ac_bonus=3+random(ac_bonus-2);
    /* Additional resistance bonus based on align and piety */
    if(align > 0 && random(pie) > 10) {
      res=10+random(2*shield);  /* 11-29% initial resistance */
      res=100*res*align/1000;     /* modified based on how 'good' the knight is */
      if(res < 100)
        res=0;
      else
        tell_object(wearer,"Your shield glows with a holy aura!\n");
    }
  }
  res=res+wres;
  if(wearer->is_testchar())
    tell_object(wearer,"Templar ac: "+ac_bonus+" Templar res: "+(res/100)+"\n");
  return ac_bonus+res;
}