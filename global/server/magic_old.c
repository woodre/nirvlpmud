/********************************************
 * Magicserver Pre-Alpha (C) Mentar, Tubmud *
 ********************************************/

#pragma strong_types
#include <kernel.h>
#include <magic.h>
#include <event.h>
#include <wizlevels.h>
#include <grammar.h>
#include <message.h>

inherit ACCESS;
inherit "/basic/create";

private		mapping  spells;
private		mapping	 spellist;
private static	mapping  magic;
private static	int	*squares = ({ 1, 4, 9, 16, 25, 36, 49, 64, 81, 100,
                                      121, 144, 169, 196, 225, 256, 289, 324,
                                      361, 400, 441, 484, 529, 576, 625, 676,
                                      729, 784, 841, 900, 961, 1024, 1089,
                                      1156, 1225, 1296, 1369, 1444, 1521,
                                      1600, 1681, 1764, 1849, 1936, 2025,
                                      2116, 2209, 2304, 2401, 2500 });
private static	int	*triples = ({ 1, 8, 27, 64, 125, 216, 343, 512, 729,
				      1000, 1331, 1728, 2197, 2744, 3375,
				      4096, 4913, 5832, 6859, 8000, 9261,
				      10648, 12167, 13824, 15625, 17576,
				      19683, 21952, 24389, 27000, 29791,
				      32768, 35937, 39304, 42875, 46656,
				      50653, 54872, 59319, 64000, 68921,
				      74088, 79507, 85184, 91125, 97336,
				      103823, 110592, 117649, 125000 });

nomask int query_prevent_shadow() { return 1; }

private status error (string message)
{
  this_player()->tell_more(message+"\n");
  return 1;
}

private void save_me()
{
  unguarded("@magic",#'save_object,MAGICSAVE);
  unguarded("@magic",#'save_object,MAGICSAVE+"_backup");
}

private void magic_log (string file, string message)
{
  unguarded("@magic",#'write_file,({MAGICLOG+file,ctime(time())[4..<9]
   + " " + message+"\n"}));
}

status magic_error (string message)
{
  if (this_player()->query_level() < WL_WIZARD)
    write ("There's a big distortion in the magical aura !\nPlease "
      + "tell an archwizard about this immediately !\n");
  else
    write ("Magic error: "+message+"\n");
  unguarded("@magic",#'write_file,({MAGICLOG+"MAGIC_ERRORS",
    ctime(time())[11..18]+ " " + message+"\n"}));
  return 1;
}

private status illegal_access (object ob)
{
  if (ob->test_flag(96) || (ob->query_level() >= WL_WIZARD)
    || !query_once_interactive(ob))
      return 0;
  return !check_privilege("@magic");
}


public mixed query_magic (string str)
{
  if (!str)
    return m_indices (magic);
  return member (magic, str);
}

public string *identify_spell (string spell, object ob)
{
string *parts, *matches, *entries;
int i;

  if (!spell)
    return ({});
  parts = explode (lower_case(spell), " ");

  // Every wizard knows all generic spells
  if (!ob || is_wizard(ob))
    matches = m_indices(spells);
  else if ((sizeof(parts) == sizeof(filter(parts, #'query_magic))))
    matches = m_indices(spells);
  else
    matches = ob->query_spellnames();
  for (i=0 ; i<sizeof(parts) ; i++)
  {
    if (!(entries = spellist[parts[i]]))
      return ({});
    matches &= spellist[parts[i]];
  }
  return matches;
}

public mixed query_data ()
{
  return copy (spells);
}

public mixed query_spells (string spell)
{
string str;

  if (!spell)
    return m_indices(spells);
  if (!member(spells,spell))
    return 0;
  if (!(str = spells[spell,1]))
    return 1;
  else
    return str;
}

private object locate_spell (string spell)
{
object sp;

  if (sp = spells[spell,2])
    return sp;
  if (!query_spells(spell))
    return 0;
  if (!(sp = load_object (spells[spell,0])))
    magic_error ("\""+spell+"\": Couldn't load the spell-blueprint");
  spells[spell,2] = sp;
  return sp;
}
  
public mapping query_spell_event (string spell)
{
object sp;

  if (!(sp = locate_spell (spell)))
    return 0;
  return sp->query_event();
}

public status forget_magic (object ob, string str)
{
  if (illegal_access(ob))
    return error ("You aren't allowed to do that !");
  return ob->forget_magic(str);
}

public status learn_magic (object ob, string str, int value)
{
  if (illegal_access(ob))
    return error ("You aren't allowed to teach players !");
  if ((value < 0) || (value > 50))
    return error ("The control can never be worse than 0 or better than 50.");
  if (value == 0)
    return forget_magic (ob, str);
  switch (query_magic(str)) {
    case 0:  return error("There is no magic called \""+str+"\".");
    case 1:  return ob->learn_magic(str, value);
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

private string build_spellname (string name, string author)
{
  if (!author || (author==""))
    return name;
  return capitalize(author)+"'s "+name;
}

public status add_spell (string file, int approve)
{
object spellob;
string spell,art,lore,dest,name,author,*parts;
mapping event;
int i;

  file = MASTER->normalize_path(file,this_player());
  name = this_player()->query_real_name();
  if ((unguarded("@magic",#'file_size,file)) <= 0)
    return error("No such file: "+file);
  if (approve && !check_privilege("@magic"))
    return error("Only Magic administrators can approve spells.");

  // For convenience, make sure that only the updated version is added
  if (!(spellob = load_object(file)))
    return error("Couldn't load this spellfile: "+file);
  destruct (spellob);
  if (!(spellob = load_object(file)))
    return error("Couldn't load this spellfile: "+file);

  if (!mappingp(event = spellob->query_event()))
    return error("File \""+file+"\" is no spell.");
  if (!(author = spellob->query_author()))
    return error("This spell lacks an author.");
  spell = build_spellname(event[E_SPELL], author);
  if (member(spells,spell) && (spells[spell,1] != name))
  {
    if (!(name = spells[spell,1]))
      return error("There's an approved spell called \""+spell+"\" already.");
    else
      return error(capitalize(name)+" wrote a spell \""+spell+"\" already.");
  }

  if (get_eval_cost() < 5000) for(;;);

  parts = explode(lower_case(spell)," ");
  for (i=0 ; i<sizeof(parts) ; i++)
  {
    if (!spellist[parts[i]])
      spellist[parts[i]] = ({});
    if (member(spellist[parts[i]], spell)==-1)
      spellist[parts[i]] += ({spell});
  }
  spells[spell,2] = spellob;
  if (!approve)
  {
    spells[spell,0] = file;
    spells[spell,1] = name;
  }
  else
  {
    dest = MAGICSPELLS + (lore = event[E_LORE]);
    if (unguarded("@magic",#'file_size,dest) != -2)
      return error ("\""+lore+"\" is no valid lore.");
    dest += "/" + (art = event[E_ART]);
    if (unguarded("@magic",#'file_size,dest) != -2)
      return error ("\""+art+"\" is no valid art.");
    dest += "/" + implode(explode(spell," "),"_") + ".c";
    if (!unguarded("@magic",#'copy_file,({file,dest})))
      return error("Couldn't install this spell !");
    spells[spell,0] = dest;
    spells[spell,1] = 0;
    magic_log ("SPELLS","Spell \""+spell+"\" approved by "+capitalize(name));
  }
  if (approve)
    write ("Spell \""+spell+"\" added and approved.\n");
  else
    write ("Spell \""+spell+"\" added.\n");
  save_me();
  return 1;
}

public status remove_spell (string spell)
{
string name,*spellname,file,*parts;
int i;

  name = this_player()->query_real_name();
  if (!sizeof(spellname = identify_spell(spell, this_player())))
    return error ("There's no spell called \""+spell+"\"");
  if (sizeof(spellname)>1)
    return error ("Which spell do you want to remove: " +
    		  make_list (spellname, 0, " or ") + " ?");
  if (!check_privilege("@magic") && (spells[spellname[0],1] != name))
    return error ("You aren't allowed to remove the spell \""
    	+spellname[0]+"\"");

  if (get_eval_cost() < 5000) for(;;);

  parts = explode(lower_case(spellname[0])," ");
  for (i=0 ; i<sizeof(parts) ; i++)
  {
    if (!spellist[parts[i]])
      continue;			// Sollte nicht passieren ...
    spellist[parts[i]] -= ({spellname[0]});
    if (!sizeof(spellist[parts[i]]))
      m_delete(spellist,parts[i]);
  }
  if (!spells[spellname[0],1])
  {
    magic_log ("SPELLS","Spell \""+spellname[0]+"\" deleted by "+capitalize(name));
    file = spells[spellname[0],0];
    unguarded("@magic",#'copy_file,({file,MAGICTRASH+explode(file,"/")[<1]}));
    unguarded("@magic",#'rm,file);
  }
  m_delete(spells,spellname[0]);
  save_me();
  printf("Spell \""+spellname[0]+"\" deleted.\n");
  return 1;
}

public int calculate_success (mapping data)
{
int level, control, art, lore, requisite, base, result, tmp;
mapping skills;

  level     = data[E_LEVEL];
  skills    = data[E_SKILL];
  art       = skills[data[E_ART]];
  lore      = skills[data[E_LORE]];
  requisite = skills[data[E_REQUISITE]];
  control   = skills[E_SPELL];

  if (requisite)
    base = ((art+lore+requisite) / 4
	  + insert_alist(((art*lore*requisite) + 1), triples));
  else
    base = ((art+lore) / 3
	  + insert_alist(((art*lore) + 1), squares));
  do
  {
    if ((tmp = random(level) / 2) > result)
      result = tmp;
    control -= random(level) * 2;
  } while (control > 0);
  result += base;

  control = skills[E_SPELL];
  if ((!(result % 20) && ((random(75)  + (level/2)) > control)))
    ; // Here comes a catastrophe soon.
  if (!(result % 10))
  {
    if ((random(100) + (level/2)) > control)
      ; // Here comes a failure soon.
    if ((tmp = random(100)) > control)
    {
      if ((control += ((tmp - control) / 10) + 2) > 100)
        control = 100;
      data[E_AGENT]->learn_spell(data[E_SPELL], control, 1);
    }
  }
  return result-level;
}

static void start_spell (mapping se)
{
  locate_spell(se[E_SPELL])->start_spell(se);
  this_player()->restore_spell_points(-se[E_COST]);
}

static void execute_spell (mapping se)
{
  if (se[E_HANDLED])
    return;
  else
    se[E_HANDLED] = locate_spell(se[E_SPELL])->execute_spell(se);
}

static void finish_spell (mapping se)
{
  locate_spell(se[E_SPELL])->finish_spell(se);
}

public status forget_spell (object ob, string spell)
{
  if (illegal_access(ob))
    return error ("You aren't allowed to do that !");
  return ob->forget_spell(spell);
}

public status learn_spell (object ob, string spell, int value)
{
string fullname, *tmp;

  if ((value < 0) || (value > 100))
    return error ("Noone can control spells less than 1 or better than 100.");
   switch(sizeof(tmp = identify_spell(spell, this_player())))
  {
    case 0:	return error("There is no spell called \""+spell+"\".");
    case 1:	fullname = tmp[0];
    		break;
    default:	return error ("Which spell do you want to teach: " +
    		  make_list (tmp, 0, " or ") + " ?");
  }
  if (value == 0)
    return forget_spell (ob, fullname);
  switch (to_string(query_spells(fullname))) {
    case "0":	return error("There is no spell called \""+fullname+"\".");
    case "1":	if (illegal_access(ob))
		  return error("You aren't allowed to teach players.");
		return ob->learn_spell(fullname, value);
    default :   if (illegal_access(ob))
                  return error("This spell hasn't been approved yet.");
                return ob->learn_spell(fullname, value);
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

public status spell_info (string spell, object ob)
{
mixed tmp;
object bp;
string out, author, spellname;

  if (!ob)
    tmp = identify_spell(spell, ob);
  else
    tmp = identify_spell(spell, 0);

  switch (sizeof(tmp))
  {
    case 0:	if (!is_wizard(this_player()))
		  message (({({ M_WRITE, "You don't know such a spell."})}));
		else
		  message (({({ M_WRITE, "There is no such spell."})}));
		return 1;
    case 1:     spellname = tmp[0];
		break;
    default:	message (({({ M_WRITE, "Which spell do you mean: ",
		  make_list (tmp, 0, " or "), " ?"})}));
		return 1;
  }

  bp = locate_spell(spellname);
  tmp = bp->query_event(this_player());
  if (tmp[E_LEVEL])
    out = "("+tmp[E_LEVEL]+")";
  else
    out = "(generic)";
  if ((author = bp->query_author()) != "")
    out += "   Invented by "+author;
  message(({({ M_WRITE, "=============================================================================" }),
  	    ({ M_WRITE, "Spell \"", spellname, "\" ", out }),
  	    ({ M_WRITE, "=============================================================================" })}));

  if (tmp[E_REQUISITE])
    out = "   Requisite: "+capitalize(tmp[E_REQUISITE])+" ("
	+ tmp[E_SKILL][tmp[E_REQUISITE]]+")\n";
  else
    out = "\n";
  message(({({ M_WRITE, "Art: ", capitalize(tmp[E_ART]), " (",
	tmp[E_SKILL][tmp[E_ART]],")   Lore: ", capitalize(tmp[E_LORE]),
	" (",tmp[E_SKILL][tmp[E_LORE]], ")", out })}));

  if (!tmp[E_COST])
    out = " variable casting cost ";
  else
    out = " fixed casting cost of "+to_string(tmp[E_COST])+" spell points ";
  switch (tmp[E_DELAY])
  {
    case 0:		out += "and goes into effect instantly.";
			break;
    case 1..1000:	out += "and takes only a second to cast.";
			break;
    case 1001..5000:	out += "and takes only a few seconds to cast.";
			break;
    case 5001..30000:	out += "and takes about "+
			       "/lib/language"->word_number(tmp[E_DELAY]/1000)+
			       " seconds to cast.";
			break;
    case 30001..60000:	out += "and takes more than half a minute to cast.";
			break;
    default:		out += "and takes alot of time to cast.";
			break;
  }
  switch(this_player()->query_spells(spellname))
  {
    case 0:		out += " You don't know this spell at all.";
			break;
    case 1..10:		out += " Except for the name, you don't know very much"+
 				" about the spell.";
 			break;
    case 11..20:	out += " You've barely started to get a grip on this spell.";
			break;
    case 21..30:	out += " Your control of this spell is still weak, you"+
				" definitely need more practice.";
			break;
    case 31..40:	out += " You can cast this spell most of the times, but"+
				" your control over it still leaves alot to be"+
				" desired.";
			break;
    case 41..50:	out += " You have average control of this spell.";
			break;
    case 51..60:	out += " You have a decent grip on this spell.";
			break;
    case 61..70:	out += " Your control over this spell is fine.";
			break;
    case 71..80:	out += " Your control over this spell is so good that"+
				" you feel confident enough to teach it.";
			break;
    case 81..90:	out += " You have mastered this spell so well that"+
				" only few mages could beat you in casting it.";
			break;
    case 91..95:	out += " Your control over this spell is excellent."+
				" Only archmages might beat you in casting it.";
			break;
    case 96..100:	out += " You have mastered this spell completely."+
				" Noone could beat you casting this spell.";
			break;
  }
  message(({({ M_RAW, M_WRITE, spellname, " has got a", out })}));
  if (out = bp->query_info())
    message(({({ M_RAW, M_WRITE, "\n", out })}));
  return 1;
}

public status cast_spell (mapping data)
{
object pl;
mapping se;
string spell;
mixed tmp;
int level, delay;

  switch (sizeof(tmp = identify_spell(data[E_SPELL],data[E_AGENT])))
  {
    case 0:	notify_fail ("Cast which spell?\n",-1);
		return 0;
    case 1:	break;
    default:	error ("Which spell do you want to cast: " +
                      make_list (tmp, 0, " or ") + " ?");
                return 1;
  }
  spell = tmp[0];
  if (!(se = query_spell_event(spell)))
    return magic_error ("\""+spell+"\": Invalid spell !");
  se[E_SPELL]  = spell;
  if (!(pl = data[E_AGENT]))
    return magic_error ("\""+spell+"\": No agent specified !");
  se[E_AGENT] = pl;
  level = pl->query_spells(spell);
  if (!level)
  {
    notify_fail ("You don't know this spell.\n",1);
    return 0;
  }
  if (pl->query_spell_points() < (se[E_LEVEL] / 2))
  {
    notify_fail ("You feel too exhausted to cast this spell.\n",1);
    return 0;
  }
  tmp = pl->query_magic();
  tmp[E_SPELL] = level;
  se[E_SKILL]  = tmp;
  if (tmp = data[E_TARGET])
    se[E_TARGET] = tmp;
  if (tmp = data[E_COMPONENT])
    se[E_COMPONENT] = tmp;
  if (!(tmp = locate_spell(spell)))
    return 1;
  if (!tmp->init_spell(se))
    return 1;
  se[E_SUCCESS] = calculate_success(se);
  delay = ((se[E_SUCCESS] + 100) * tmp->query_delay()) / 100000;
  call_out (#'send_event, delay, E_MAGIC, se);
  return 1;
}

status do_action (string verb, mapping args)
{
int number;
string spell;
mapping data;

  data = ([]);
  data[E_SPELL] = args[G_WORDS];
  data[E_AGENT] = this_player();
  if (strstr(verb,"component",0) >= 0)
  {
    if (!present(args[G_OBJECT], this_player())) return 0;
    data[E_COMPONENT] = args[G_OBJECT];
  }
  if (strstr(verb,"target",0) >= 0)
  {
    if (args[G_INDIRECT] == environment(this_player()))
      data[E_TARGET] = ({args[G_INDIRECT,1]});
    else
      data[E_TARGET] = ({args[G_INDIRECT]});
  }
  if (strstr(verb,"multi",0) >= 0)
  {
    if (number = args[G_ALL,1][1])
      data[E_TARGET] = args[G_ALL][0..number-1];
    else
      data[E_TARGET] = args[G_ALL];
  }
  return cast_spell(data);
}

void create()
{
  set_privilege("@magic");
  listen_event(E_MAGIC, EPRIO_START_MAGIC,   #'start_spell);
  listen_event(E_MAGIC, EPRIO_EXECUTE_MAGIC, #'execute_spell);
  listen_event(E_MAGIC, EPRIO_FINISH_MAGIC,  #'finish_spell);
  set_global_listening_event(E_MAGIC,1);
  unguarded("@magic",#'restore_object,MAGICSAVE);
  if (!spells || sizeof(spells)==0)
  {
    spells = m_allocate(0,3);
    spellist = ([]);
  }
  magic = ([ "cernatur", "fiat", "obsequatur", "pereat", "vertat",
  	     "aer", "animal", "aqua", "corpus", "herba", "ignis",
  	     "imago", "mens", "terra", "vis" ]);
  squares = order_alist (squares);
  triples = order_alist (triples);
}
