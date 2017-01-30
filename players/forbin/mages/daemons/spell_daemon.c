#include "/players/forbin/mages/def.h"

string *AbjuSpells, *ConjSpells, *EnchSpells, *EvocSpells;
string *DiviSpells, *IlluSpells, *NecrSpells, *TranSpells;

/* Prototype Declaration */
void load_spells(string arg);

id() { return "msd"; }

short() { return "Mage Spell Daemon ["+HIR+"Do Not Destruct"+NORM+"]"; }

void save_daemon()
{
  save_object("players/forbin/mages/log/msd_save");
}

int restore_daemon()
{
  int a;
  a = restore_object("players/forbin/mages/log/msd_save");
  return a;
}

void reset(mixed arg) 
{
  if(arg) return;

  AbjuSpells = ConjSpells = EnchSpells = EvocSpells = ({ });
  DiviSpells = IlluSpells = NecrSpells = TranSpells = ({ });

  if(!restore_daemon())
  {
    load_spells("abju");
    load_spells("conj");
    load_spells("ench");
    load_spells("evoc");
    load_spells("divi");
    load_spells("illu");
    load_spells("necr");
    load_spells("tran");
    save_daemon();
  }
  else
    restore_daemon();
}

level_and_name(s1, s2) {
  int l1,l2;
  l1 = call_other("/players/forbin/mages/spells/"+s1,"s_spell_level");
  l2 = call_other("/players/forbin/mages/spells/"+s2,"s_spell_level");
  if(l1 != l2) return l1 > l2;
  return s1 > s2;
}


void load_spells(string arg)
{
	string *temparray, *spells, *sortedspells;
	string sname, pname;
	string error;
	int slevel;	
	int x, s;

	
  if(!arg)
	  return;

  if(member_array(arg, VALIDSCHOOLS) < 0)
    return;	  
    
	temparray = spells = sortedspells = ({ });

	switch(arg)
	{
		case "abju" : AbjuSpells = ({ }); break;
	  case "conj" : ConjSpells = ({ }); break;
    case "ench" : EnchSpells = ({ }); break;
	  case "evoc" : EvocSpells = ({ }); break;
		case "divi" : DiviSpells = ({ }); break;
		case "illu" : IlluSpells = ({ });	break;
		case "necr" : NecrSpells = ({ }); break;
		case "tran" : TranSpells = ({ }); break;
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
	
  spells = sort_array(spells,"level_and_name",this_object());
  s = sizeof(spells);
  
	if(spells && sizeof(spells))
	{
	  for(x = 0; x < s; x++)
  	{
	    slevel = (int)call_other("/players/forbin/mages/spells/"+spells[x], "s_spell_level");
  	  sname = (string)call_other("/players/forbin/mages/spells/"+spells[x], "s_spell_name");
	    pname = (string)call_other("/players/forbin/mages/spells/"+spells[x], "s_proper_name");
      write(sname+":"+slevel+"\n");
  		sortedspells += ({ sname, ({ pname, slevel, }), });
    }
  }
	switch(arg)
	{
	  case "abju" : AbjuSpells = sortedspells; break; 
    case "conj" : ConjSpells = sortedspells; break; 
	  case "ench" : EnchSpells = sortedspells; break; 
		case "evoc" : EvocSpells = sortedspells; break; 
	  case "divi" : DiviSpells = sortedspells; break; 
    case "illu" : IlluSpells = sortedspells; break; 
	  case "necr" : NecrSpells = sortedspells; break;
	  case "tran" : TranSpells = sortedspells; break;  			
	 }
	save_daemon();
}

void print_spells(string school, object who)
{
  string *spells;
	int x,l,s;
	int glevelcheck;
	
	glevelcheck = (int)present("forbin_mage_object", who)->query_glevel();
	if(who->query_level() > 99) glevelcheck = 7;

  if(!glevelcheck) 
		return;
	
  if(member_array(school, VALIDSCHOOLS) < 0)
    return;	 	
	
	switch(school)
	{
    case "abju" : spells = AbjuSpells; break;
	  case "conj" : spells = ConjSpells; break;
    case "ench" : spells = EnchSpells; break;
	  case "evoc" : spells = EvocSpells; break;
		case "divi" : spells = DiviSpells; break;
		case "illu" : spells = IlluSpells; break;
		case "necr" : spells = NecrSpells; break;
		case "tran" : spells = TranSpells; break;
	}
	
	s = sizeof(spells);
  
  tell_object(who,"\n");
  
  for(x = 1; x < s; x+=2)
  {
    tell_object(who,
      "\t"+pad(spells[x][0], 30)+"  "+pad(spells[x][1], -2)+"\n");

	}
  tell_object(who,"\n");	
}

status list_spells(string school, object gob, object player, object teacher)
{
  string tname;
  
  tname = (string)teacher->m_name();
  
  if(!(school == (string)teacher->m_school()))
  {
    tell_room(environment(player),
      tname+" says: "+(string)player->query_name()+
      ", I don't know that school of magic.\n");
    if(teacher)
      teacher->set_busy(0);
    return 1;
  }

  tell_object(player,"\n"+
    SGC+"["+PGC+"*"+SGC+"]"+PGC+
    "================================================"+
    SGC+"["+PGC+"*"+SGC+"]"+QGC+"\n");
  tell_object(player,
    (string)teacher->m_list_heading()+"\n");
  tell_object(player,
    SGC+"["+PGC+"*"+SGC+"]"+PGC+
    "================================================"+
    SGC+"["+PGC+"*"+SGC+"]"+QGC+"\n");    
  tell_object(player,
  TGC+"\tSpellname                      Level\n"+QGC);    
  tell_object(player,
    SGC+"["+PGC+"*"+SGC+"]"+PGC+
    "================================================"+
    SGC+"["+PGC+"*"+SGC+"]"+QGC+"\n");
  "/players/forbin/mages/daemons/spell_daemon.c"->print_spells((string)teacher->m_school(), player);
  tell_object(player,
    SGC+"["+PGC+"*"+SGC+"]"+PGC+
    "================================================"+
    SGC+"["+PGC+"*"+SGC+"]"+QGC+"\n");
  tell_room(environment(player),
    tname+" says something to "+(string)player->query_name()+".\n", ({ player }));
  if(teacher)
    teacher->set_busy(0);   
  return 1;
}

status spell_exists(string spellname, string school)
{
	string *spells;
  int x, s;
  int existsflag;
  
  existsflag = 0; 
  
  if(member_array(school, VALIDSCHOOLS) < 0)
    return 0;	   
  
	switch(school)
	{
		case "abju" : spells = AbjuSpells; break;
	  case "conj" : spells = ConjSpells; break;
		case "ench" : spells = EnchSpells; break;
		case "evoc" : spells = EvocSpells; break;
		case "divi" : spells = DiviSpells; break;
		case "illu" : spells = IlluSpells; break;
		case "necr" : spells = NecrSpells; break;
		case "tran" : spells = TranSpells; break;
	}
	
	s = sizeof(spells);
	for(x = 0; x < s; x+=2)
  {
    if(spells[x] == spellname)
    {
      existsflag = 1;  
      break;
    }
  }
  return existsflag;	  
}

status info_spell(string spellname, string school, object gob, object player, object teacher)
{
  object spellcode;
	string tname;
	
  if(teacher)
    tname = (string)teacher->m_name();
  else
    tname = "The MageSpellDaemon";  
  
  if(!spell_exists(spellname, school))
  {
    tell_object(player,
      tname+" says: I know of no spell by that name, "+(string)player->query_name()+".\n");
    if(teacher)
      teacher->set_busy(0);
    return 1;
  }  
  
  spellcode = SPELLS+implode(explode(spellname, " "), "_")+".c";
  spellcode->info(gob, player);
  if(teacher)
    teacher->set_busy(0);  
  return 1;
}

status learn_spell(string spellname, string school, object gob, object player, object teacher)
{
  string *spells;
  string tname, msg;
  int sl,p;
  
  if(teacher)
    tname = (string)teacher->m_name();
  else
    tname = "The MageSpellDaemon";
  
  if(!spell_exists(spellname, school))
  {
    tell_object(player,
      tname+" says: I know of no spell by that name, "+(string)player->query_name()+".\n");
    return 1;
  }
 
  if(gob->know_spell(spellname, school))
  {
    tell_object(player,
      tname+" says: You already know that spell, "+(string)player->query_name()+".\n");
    return 1;
  }
	switch(school)
	{
		case "abju" : spells = AbjuSpells; break;
	  case "conj" : spells = ConjSpells; break;
		case "ench" : spells = EnchSpells; break;
		case "evoc" : spells = EvocSpells; break;
		case "divi" : spells = DiviSpells; break;
		case "illu" : spells = IlluSpells; break;
		case "necr" : spells = NecrSpells; break;
		case "tran" : spells = TranSpells; break;
	}  
	
	(p = member_array(spellname, spells));
	
	if((sl = spells[p+1][1]) > (int)gob->query_glevel())
	{
    tell_object(player,
      tname+" says: Your guild level is not high enough to learn a level "+sl+" spell.\n");
    return 1;  	
	}
	if(sl > (int)gob->query_spell_level_trains())
	{
    tell_object(player,
      tname+" says: You do not have enough spell level trains to learn a level "+sl+" spell.\n");
    return 1;  	
	}	
	
	tell_object(player, "\n"+
	  tname+" explains the spell to you and leaves you to study in peace.\n"+
	  "Concentrating, you begin to write the details and workings of the\n"+
	  "spell into your spellbook, dispensing the knowledge you've learned\n"+
	  "through the pen you write with.\n\n");
	tell_room(environment(player),
	  (string)player->query_name()+" begins to scribe in "+
	  (string)player->query_possessive()+" spellbook, concentrating intently.\n", ({ player }));

  if(!random(2))
  {
    switch(random(10))
    {
      case 0: msg = "The page ignites, destroying all of your work.\n"; break;
      case 1: msg = "Your page tears, letting the magic seep out.\n"; break;
      case 2: msg = "You faint, destroying your concentration.\n"; break;
      case 3: msg = "You sneeze, destroying your concentration.\n"; break;
      case 4: msg = "The ink fades leaving your page blank.\n"; break;
      case 5: msg = "JiBbERiSh FiLLs yOuR MInD.\n"; break;
      case 6: msg = tname+" tears up your paper, while shouting: \"No, No, No!\"\n";  break;
      case 7: msg = "The page fades from this reality leaving you bewildered.\n"; break;
      case 8: msg = "The page flashes brightly and your writing is gone.\n"; break;
      case 9: msg = "Your pen rips the page, leaving your work useless.\n"; break;       
    }
    tell_object(player, msg+
      "\nYou fail to learn "+spells[p+1][0]+".\n");
    if(sl > 1)
      gob->sub_spell_level_trains((sl / 2));
    else
      gob->sub_spell_level_trains(random(2)); 
    if(teacher)
      teacher->set_busy(0);
    return 1;
  }	
  tell_object(player,
    "The ink begins to "+SGC+"glow"+NORM+" as the spell takes form within your magic spellbook.\n\n"+
    "You have learned "+spells[p+1][0]+".\n");
  gob->add_spell(spellname, school, sl);
  gob->sub_spell_level_trains(sl);
  if(teacher)
    teacher->set_busy(0);  
  return 1;
}
