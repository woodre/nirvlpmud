#include "/players/forbin/mages/def.h"

mapping abjuspells, conjspells, enchspells, evocspells;
mapping divispells, illuspells, necrspells, transpells;
string *saved_abjuspells, *saved_conjspells;
string *saved_enchspells, *saved_evocspells;
string *saved_divispells, *saved_illuspells;
string *saved_necrspells, *saved_transpells;

/* Prototype Declaration */
void load_spells(string arg);

id() { return "msd"; }

short() { return HIM+"M"+MAG+"age "+HIM+"S"+MAG+"pell "+HIM+"D"+MAG+"aemon "+HIW+"(DO NOT DESTRUCT)"+NORM; }

void save_mapping()
{
  saved_abjuspells = deconstruct_mapping(abjuspells);
  saved_conjspells = deconstruct_mapping(conjspells);
  saved_enchspells = deconstruct_mapping(enchspells);
  saved_evocspells = deconstruct_mapping(evocspells);
  saved_divispells = deconstruct_mapping(divispells);
  saved_illuspells = deconstruct_mapping(illuspells);
  saved_necrspells = deconstruct_mapping(necrspells);
  saved_transpells = deconstruct_mapping(transpells);
  save_object("players/forbin/mages/log/msd_save");
}

int restore_mapping()
{
  int a;
  a = restore_object("players/forbin/mages/log/msd_save");
  abjuspells = reconstruct_mapping(saved_abjuspells);
  conjspells = reconstruct_mapping(saved_conjspells);
  enchspells = reconstruct_mapping(saved_enchspells);
  evocspells = reconstruct_mapping(saved_evocspells);
  divispells = reconstruct_mapping(saved_divispells);
  illuspells = reconstruct_mapping(saved_illuspells);
  necrspells = reconstruct_mapping(saved_necrspells);
  transpells = reconstruct_mapping(saved_transpells);
  return a;
}

void reset(mixed arg) 
{
  if(arg) return;

  abjuspells = conjspells = enchspells = evocspells = ([ ]);
  divispells = illuspells = necrspells = transpells = ([ ]);

  if(!restore_mapping())
  {
    load_spells("abju");
    load_spells("conj");
    load_spells("ench");
    load_spells("evoc");
    load_spells("divi");
    load_spells("illu");
    load_spells("necr");
    load_spells("tran");
    save_mapping();
  }
  else
    restore_mapping();
}

sort_func(one, two) { return one > two; }
level_and_name(s1, s2) {
  int l1,l2;
  l1=call_other("/players/forbin/mages/spells/"+s1,"s_spell_level");
  l2=call_other("/players/forbin/mages/spells/"+s2,"s_spell_level");
  if(l1!=l2) return l1 > l2;
  return s1 > s2;
}


void load_spells(string arg)
{
	string *temparray, *spells;
	string *s1, *s2, *s3, *s4, *s5, *s6, *s7;
	mapping tempmapping;
	string sname, pname;
	string error;
	int x, s;
	int slevel;
	
  if(!arg)
	  return;

  if(member_array(arg, VALIDSCHOOLS) < 0)
    return;	  
    
	temparray = spells = ({ });
	s1 = s2 = s3 = s4 = s5 = s6 =s7 = ({ });
	tempmapping = ([ ]);	

	switch(arg)
	{
		case "abju" : abjuspells = ([ ]); break;
	  case "conj" : conjspells = ([ ]); break;
    case "ench" : enchspells = ([ ]); break;
	  case "evoc" : evocspells = ([ ]); break;
		case "divi" : divispells = ([ ]); break;
		case "illu" : illuspells = ([ ]);	break;
		case "necr" : necrspells = ([ ]); break;
		case "tran" : transpells = ([ ]); break;
	}

	temparray = get_dir("/players/forbin/mages/spells/*.c");
  s = sizeof(temparray);
	
	for(x = 0; x < s; x++)
	{
    if(error = catch((string)call_other("/players/forbin/mages/spells/"+temparray[x], "test_load")))
    {
      if(find_player("forbin"))
        tell_object(find_player("forbin"), 
          HIM+"MageSpellDaemon ["+NORM+arg+" message"+HIM+"] "+HIW+">>"+NORM+
          " Spell load failure: "+temparray[x]+", "+error);
      write_file("/players/forbin/mages/log/MSDError",
        "MageSpellDaemon ["+arg+" message] >> Spell load failure: "+temparray[x]+", "+error);
    }
    else if((string)call_other("/players/forbin/mages/spells/"+temparray[x], "s_spell_school") == arg)
		{
		  spells += ({ temparray[x], });
		}
	}
/*	
	s = sizeof(spells);
	
	for(x = 0; x < s; x++)
	{
		if((int)call_other("/players/forbin/mages/spells/"+spells[x], "s_spell_level") == 1)
		  s1 += ({ spells[x], });
	}
	for(x = 0; x < s; x++)
	{
		if((int)call_other("/players/forbin/mages/spells/"+spells[x], "s_spell_level") == 2)
		  s2 += ({ spells[x], });
	}
	for(x = 0; x < s; x++)
	{
		if((int)call_other("/players/forbin/mages/spells/"+spells[x], "s_spell_level") == 3)
		  s3 += ({ spells[x], });
	}
	for(x = 0; x < s; x++)
	{
		if((int)call_other("/players/forbin/mages/spells/"+spells[x], "s_spell_level") == 4)
		  s4 += ({ spells[x], });
	}
	for(x = 0; x < s; x++)
	{
		if((int)call_other("/players/forbin/mages/spells/"+spells[x], "s_spell_level") == 5)
		  s5 += ({ spells[x], });
	}
	for(x = 0; x < s; x++)
	{
		if((int)call_other("/players/forbin/mages/spells/"+spells[x], "s_spell_level") == 6)
		  s6 += ({ spells[x], });
	}
	for(x = 0; x < s; x++)
	{
		if((int)call_other("/players/forbin/mages/spells/"+spells[x], "s_spell_level") == 7)
		  s7 += ({ spells[x], });
	}						
	
	s1 = sort_array(s1, "sort_func", this_object());
	s2 = sort_array(s2, "sort_func", this_object());
	s3 = sort_array(s3, "sort_func", this_object());
	s4 = sort_array(s4, "sort_func", this_object());
	s5 = sort_array(s5, "sort_func", this_object());
	s6 = sort_array(s6, "sort_func", this_object());
	s7 = sort_array(s7, "sort_func", this_object());
	
	spells = ({ });
	spells = s1 + s2 + s3 + s4 + s5 + s6 + s7;
        */
        spells=sort_array(spells,"level_and_name",this_object());
        s=sizeof(spells);
	if(spells && sizeof(spells))
	{
	for(x = 0; x < s; x++)
	{
	  slevel = (int)call_other("/players/forbin/mages/spells/"+spells[x], "s_spell_level");
	  sname = (string)call_other("/players/forbin/mages/spells/"+spells[x], "s_spell_name");
	  pname = (string)call_other("/players/forbin/mages/spells/"+spells[x], "s_proper_name");
          write(sname+":"+slevel+"\n");
		tempmapping[spells[x]] = ({ slevel, sname, pname, });
  }
        spells=keys(tempmapping);
        while(s--) write(spells[s]+"\n");
}
	switch(arg)
	{
	  case "abju" : abjuspells = tempmapping; break; 
    case "conj" : conjspells = tempmapping; break; 
	  case "ench" : enchspells = tempmapping; break; 
		case "evoc" : evocspells = tempmapping; break; 
	  case "divi" : divispells = tempmapping; break; 
    case "illu" : illuspells = tempmapping; break; 
	  case "necr" : necrspells = tempmapping; break;
	  case "tran" : transpells = tempmapping; break;  			
	 }
	save_mapping();
}

void print_spells(string school, object who)
{
	mapping tempmap;
	string *mapkeys;
	int x,l,s;
	int glevelcheck;
	
	glevelcheck = (int)present("forbin_mage_object", who)->query_glevel();
	if(who->query_level() > 49) glevelcheck = 7;

  if(!glevelcheck) 
		return;
	
  if(member_array(school, VALIDSCHOOLS) < 0)
    return;	 	
	
	switch(school)
	{
    case "abju" : tempmap = abjuspells; mapkeys = m_indices(abjuspells); break;
	  case "conj" : tempmap = conjspells; mapkeys = m_indices(conjspells); break;
    case "ench" : tempmap = enchspells; mapkeys = m_indices(enchspells); break;
	  case "evoc" : tempmap = evocspells; mapkeys = m_indices(evocspells); break;
		case "divi" : tempmap = divispells; mapkeys = m_indices(divispells); break;
		case "illu" : tempmap = illuspells;	mapkeys = m_indices(illuspells); break;
		case "necr" : tempmap = necrspells; mapkeys = m_indices(necrspells); break;
		case "tran" : tempmap = transpells; mapkeys = m_indices(transpells); break;    
	}
	
	s = sizeof(mapkeys);
 tell_object(who,"\n");
 for(x = 0; x < s; x++)
 {
  tell_object(who,
    "\t"+pad(tempmap[mapkeys[x]][2], 30)+"  "+pad(tempmap[mapkeys[x]][0], -2)+"\n");

	}
	tell_object(who,"\n");	
/*	
	for(l = 1; l < 8; l++)
	{
    for(x = 0; x < s; x++)
    {
  		if((int)tempmap[mapkeys[x]][0] == l && glevelcheck > (l-1))
	  	{
		    tell_object(who,
          "\t"+pad(tempmap[mapkeys[x]][2], 30)+"  "+pad(tempmap[mapkeys[x]][0], -2)+"\n");
		  }
	  }
	}
*/	
}

status spell_exists(string spellname, string school)
{
	string *mapkeys;
  mapping spelllist;
  int x;
  int existsflag;
  
  existsflag = 0; /* spell doesn't exist by default */
  
  if(member_array(school, VALIDSCHOOLS) < 0)
    return 0;	   
  
	switch(school)
	{
		case "abju" : spelllist = abjuspells; break;
	  case "conj" : spelllist = conjspells; break;
		case "ench" : spelllist = enchspells; break;
		case "evoc" : spelllist = evocspells; break;
		case "divi" : spelllist = divispells; break;
		case "illu" : spelllist = illuspells; break;
		case "necr" : spelllist = necrspells; break;
		case "tran" : spelllist = transpells; break;
	}
	mapkeys = m_indices(spelllist);
	for(x = 0; x < sizeof(mapkeys); x++)
  {
    if((string)spelllist[mapkeys[x]][1] == lower_case(spellname))
      existsflag = 1;  /* flag spell as existing */
  }
  return existsflag;	  
}

status learn_spell(string spellname, string school, object gob, object player)
{
  mapping spelllist;
  int sl;
  if(!spell_exists(spellname, school))
  {
    tell_object(player,
      "The is no spell by the name of: "+spellname+".\n");
    return 0;
  }
  if(gob->know_spell(spellname, school))
  {
    tell_object(player,
      "You already need the spell: "+spellname+".\n");
    return 0;
  }
	switch(school)
	{
		case "abju" : spelllist = abjuspells; break;
	  case "conj" : spelllist = conjspells; break;
		case "ench" : spelllist = enchspells; break;
		case "evoc" : spelllist = evocspells; break;
		case "divi" : spelllist = divispells; break;
		case "illu" : spelllist = illuspells; break;
		case "necr" : spelllist = necrspells; break;
		case "tran" : spelllist = transpells; break;
	}  
	if(sl = (int)spelllist[spellname][0] > (int)gob->query_glevel())
	{
    tell_object(player,
      "Your guild level is not high enough to learn a level "+sl+".\n");
    return 0;  	
	}
	if(sl = (int)spelllist[spellname][0] > (int)gob->query_glevel())
	{
    tell_object(player,
      "You do not have enough training points to learn a level "+sl+" spell.\n"+
      "You need more points to learn the "+spellname+" spell.\n");
    return 0;  	
	}	
  gob->add_spell(spellname);
  return 1;
}
