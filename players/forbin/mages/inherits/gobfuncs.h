check_schools() 
{
  int x, y, z;
  x = SizeofSC;
  y = SchoolsLvl;
  z = 0;
  for(y = SchoolsLvl; y < x; y++) 
  {
    if(SchoolsXP > (SchoolsCosts[y+1] * 1000)) 
    {
      SchoolsPts += 10;
      SchoolsLvl++;
      if(!z) 
      {
        tell_object(environment(this_object()),
         GuildColor+BOLD+"Your magicial abilities have increased.\n"+NORM);
        z = 1;
        save_gob();
      }
    }
    else return;
  }
}

mixed show_schools_percentage() 
{
 int a, b, percent;
 if(SchoolsLvl < SizeofSC) 
 {
   a = SchoolsXP - (SchoolsCosts[SchoolsLvl] * 1000);
   b = (SchoolsCosts[SchoolsLvl + 1] * 1000) - (SchoolsCosts[SchoolsLvl] * 1000);
   percent = ((a * 100) / b);  
   return percent;
 }
 else 
   return "MAX";
}

check_attributes() 
{
  int x, y, z;
  x = SizeofAC;
  y = AttribsLvl;
  z = 0;
  for(y = AttribsLvl; y < x; y++) 
  {
    if(AttribsXP > (AttribsCosts[y+1] * 1000)) 
    {
      AttribsPts += 10;
      AttribsLvl++;
      if(!z) 
      {
        tell_object(environment(this_object()),
         GuildColor+BOLD+"Your attributes have increased.\n"+NORM);
        z = 1;
        save_gob();
      }
    }
    else return;
  }
}

mixed show_attributes_percentage() 
{
 int a, b, percent;
 if(AttribsLvl < SizeofAC) 
 {
   a = AttribsXP - (AttribsCosts[AttribsLvl] * 1000);
   b = (AttribsCosts[AttribsLvl + 1] * 1000) - (AttribsCosts[AttribsLvl] * 1000);
   percent = ((a * 100) / b);
   return percent;
 }
 else
   return "MAX";
}

int show_next_guild_level()
{
	int a;
	if(GuildLevel < (SizeofGLC-1))
	{
	  a = GuildLevelCosts[GuildLevel + 1];
	  return a;
	}
}

int show_free_exp()
{
	int free, cur, lvl, xlvl;
	lvl = (int)MAGE->query_level();
  xlvl = (int)MAGE->query_extra_level();
  cur = (int)MAGE->query_exp();
  
  if(xlvl < 1 && lvl < 21)
    free = cur - (int)call_other("room/adv_guild","get_next_exp", lvl - 1);
  else if(xlvl > 0 && lvl < 21)
    free = cur - (int)call_other("room/exlv_guild","get_next_exp", xlvl - 1);
  else if(lvl >= 21)
    free = cur;  
  return free;  
}


advance_checks() 
{
  if(environment(this_object()))
  {
    environment(this_object())->set_max_hp();
    environment(this_object())->set_max_spell();
  }  
}

void save_gob() 
{
  object e;
  if((e = environment()) && !e->query_npc()) 
  {
    SavedSchools = deconstruct_mapping(Schools);
    SavedAttribs = deconstruct_mapping(Attribs);
    SavedDelays = deconstruct_mapping(Delays);
    save_object(SAVE_PATH + (string)e->query_real_name());
  }
}           

void backup_gob() 
{
  object e;
  if((e = environment()) && !e->query_npc()) 
  {
    SavedSchools = deconstruct_mapping(Schools);
    SavedAttribs = deconstruct_mapping(Attribs);
    SavedDelays = deconstruct_mapping(Delays);
    save_object(SAVE_BAK + (string)e->query_real_name());
  }
}

int restore_gob() 
{
  int result;
  object e;
  if((e = environment()) && !e->query_npc()) 
  {
    result = restore_object(SAVE_PATH + (string)e->query_real_name());
    Schools = reconstruct_mapping(SavedSchools);
    Attribs = reconstruct_mapping(SavedAttribs);
    Delays = reconstruct_mapping(SavedDelays);
    return result;
  }
}

void update_gob() 
{                                             
  object new;
  save_gob();
  new = clone_object(GUILD_FILE);
  new->no_login_msg();
  move_object(new, environment());
  new->advance_checks();
  destruct(this_object());
}

void guild_quit() 
{ 
  environment(this_object())->set_guild_name("Mages");
  advance_checks();
  save_gob();
  return; 
}

status know_spell(string x, string y) /* x = spellname */
{                                     /* y = school */ 
	if(member_array(y, VALIDSCHOOLS) > -1)
	{
  	switch(y)
	  {
  		case "abju" : if(member_array(x, LearnedAbju) > -1) return 1; 
  	                else return 0;
	    case "conj" : if(member_array(x, LearnedConj) > -1) return 1; 
  	                else return 0;
		  case "ench" : if(member_array(x, LearnedEnch) > -1) return 1; 
  	                else return 0;
  		case "evoc" : if(member_array(x, LearnedEvoc) > -1) return 1; 
  	                else return 0;
	  	case "divi" : if(member_array(x, LearnedDivi) > -1) return 1; 
  	                else return 0;
		  case "illu" : if(member_array(x, LearnedIllu) > -1) return 1; 
  	                else return 0;
  		case "necr" : if(member_array(x, LearnedNecr) > -1) return 1; 
  	                else return 0;
	  	case "tran" : if(member_array(x, LearnedTran) > -1) return 1; 
  	                else return 0;
  	}
  }
  return 0;
}

void set_previous_cast(string arg)
{
	
}
