/*
 * Magicserver (C) Mentar, Tubmud, 1994
 *
 * revised by Coogan, 14-Dec-98
 *
 */

#pragma strong_types

#include <kernel.h>
#include <event.h>
#include <message.h>
#include <skilltree.h>
#include <libs.h>
#include <is_wizard.h>

#define MAGICHOME       "/global/magic/"
#define MAGICSAVE       (MAGICHOME+"save/spells")
#define MAGICSPELLS     (MAGICHOME+"spells/")
#define MAGICTRASH      (MAGICHOME+"obsolete/")

#define EPRIO_START_MAGIC       900
#define EPRIO_INFLUENCE_MAGIC   700
#define EPRIO_PREVENT_MAGIC     500
#define EPRIO_EXECUTE_MAGIC     0
#define EPRIO_FINISH_MAGIC      -500

inherit ACCESS;
inherit "basic/path";
inherit "basic/create";

object locate_spell (string spell);

private mapping spells;
private mapping spellist;


nomask int query_prevent_shadow() { return 1; }

public string* query_lores() {
  return ({ "aer", "animal", "aqua", "corpus", "herba", "ignis",
            "imago", "mens", "terra", "vis", "mortus" });
}

public string* query_arts() {
  return ({ "cernatur", "fiat", "mutetur", "obsequatur", "pereat" });
}

private string query_lore_path(string lore) {
  switch (lore) {
  case "aer"    : return S_MAGIC_AER;
  case "animal" : return S_MAGIC_ANIMAL;
  case "aqua"   : return S_MAGIC_AQUA;
  case "corpus" : return S_MAGIC_CORPUS;
  case "herba"  : return S_MAGIC_HERBA;
  case "ignis"  : return S_MAGIC_IGNIS;
  case "imago"  : return S_MAGIC_IMAGO;
  case "mens"   : return S_MAGIC_MENS;
  case "mortus" : return S_MAGIC_MORTUS;
  case "terra"  : return S_MAGIC_TERRA;
  case "vis"    : return S_MAGIC_VIS;
  default       : raise_error("Unknown magic lore!\n"); // Coogan, 26-Mar-2011
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

private string query_art_path(string art) {
  switch (art) {
  case "cernatur"   : return S_MAGIC_CERNATUR;
  case "fiat"       : return S_MAGIC_FIAT;
  case "mutetur"    : return S_MAGIC_MUTETUR;
  case "obsequatur" : return S_MAGIC_OBSEQUATUR;
  case "pereat"     : return S_MAGIC_PEREAT;
  default       : raise_error("Unknown magic art!\n"); // Coogan, 26-Mar-2011
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

public string query_magic_skill_path(string m) {
  return query_lore_path(m) || query_art_path(m);
}

public varargs mixed query_magic(string str) {
  if (!str)
    return query_lores() + query_arts();
  return !!(member(query_lores() + query_arts(), str) > -1);
}

public mapping query_spell_event(string spell) {
  object sp;

  if (!(sp = locate_spell(spell)))
    return 0;
  return sp->query_event();
}

public mixed query_data() {
  return copy(spells);
}

public mixed query_spells(string spell) {
  string author;

  if (!spell)
    return m_indices(spells);
  if (!member(spells, spell))
    return 0;
  if (!(author = spells[spell,1]))
    return 1;
  return author;
}

/****************************************************************************/

private status error(string m) {
  write(m + "\n");
  return 1;
}

private void save_me() {
  unguarded("@magic", #'copy_file, ({ MAGICSAVE, MAGICSAVE+"_backup" }));
  unguarded("@magic", #'save_object, MAGICSAVE);
}

private void magic_log(string file, string message) {
  log_file("MAGIC", ctime()[4..<9] + ": " + message + "\n");
}

void magic_error(string message) {
  if (!is_wizard(this_player()))
    write("There's a big distortion in the magical aura!\n"
          "Please tell an archwizard about this immediately!\n");
  else
    write("Magic error: " + message + "\n");
  log_file("MAGIC_ERROR", ctime() + ": " + message + "\n");
}

private status illegal_access(object ob) {  // rewritten, Coogan, 04-Jun-99
  // I'd like to use this_interactive() instead of this_player() ...
  // but for some unknown reasons this_interactive() returns 0.
  if (this_player() == ob)  // this check by Coogan, 04-Jun-99
    return 0;  // I assume the calling object is approved, even for players.
  if (is_wizard(this_player(), IW_TOOLUSER)) {
    if (!is_wizard(ob, IW_TOOLUSER))
      return !check_privilege("@magic");
    return 0;
  }
  return !check_privilege("@magic");
}

public string *identify_spell(string spell, object ob) {
  string *parts, *matches, *entries;
  int i;

  if (!spell)
    return ({ });
  parts = explode(lower_case(spell), " ");

  // Every wizard knows all generic spells
  if (!ob || is_wizard(ob))
    matches = m_indices(spells);
  // I don't know what the next if() is used for, because it always
  // returns an empty array. Coogan, 04-Jun-99 *puzzle*
  else if ((sizeof(parts) == sizeof(filter(parts, #'query_magic))))
    matches = m_indices(spells);
  else
    matches = m_indices(ob->query_spells());

  for (i=0; i<sizeof(parts); i++) {
    if (!(entries = spellist[parts[i]]))
      return ({ });
    matches &= spellist[parts[i]];
  }
  return matches;
}

object locate_spell(string spell) {
  object sp;
  if (sp = spells[spell,2])
    return sp;
  if (!query_spells(spell))
    return 0;
  if (catch(sp = load_object(spells[spell,0]))) {
    magic_error("\""+spell+"\": couldn't load the spell-blueprint "+
                spells[spell,0]);
    return 0;
  }
  spells[spell,2] = sp;
  return sp;
}

/****************************************************************************/

private string build_spellname(string name, string author) {
  if (!author || (author == ""))
    return name;
  return capitalize(author) + LIB_LANGUAGE->possessive_s_ending(author) +
         " " + name;
}

public status add_spell(string file, int approve) {
  object spellob;
  string spell,art,lore,dest,name,author,*parts;
  mapping event;
  int i;

  file = normalize_path(file, this_player());
  name = this_player()->query_real_name();
  if ((unguarded("@magic", #'file_size, file)) <= 0)
    return error("No such file: " + file);
  if (approve && !check_privilege("@magic"))
    return error("Only Magic administrators can approve spells.");

  // For convenience, make sure that only the updated version is added
  if (!(spellob = load_object(file)))
    return error("Couldn't load this spellfile: "+file);
  destruct (spellob);
  if (!(spellob = load_object(file)))
    return error("Couldn't load this spellfile: "+file);

  if (!mappingp(event = spellob->query_event()))
    return error("File '" + file + "' is no spell.");
  if (!(author = spellob->query_author()))
    return error("This spell lacks an author.");
  spell = build_spellname(event[E_SPELL], author);
  if (member(spells, spell) && (spells[spell,1] != name)) {
    if (!(name = spells[spell,1]))
      return error("There's already an approved spell called '"+spell+"'.");
    else
      return error(LIB_NAME->to_vis_name(name) +
                   " already wrote a spell '" + spell + "'.");
  }

  if (get_eval_cost() < 5000)
    for(;;);

  parts = explode(lower_case(spell), " ");
  for (i=0; i<sizeof(parts); i++) {
    if (!spellist[parts[i]])
      spellist[parts[i]] = ({ });
    if (member(spellist[parts[i]], spell)==-1)
      spellist[parts[i]] += ({ spell });
  }
  spells[spell,2] = spellob;
  if (!approve) {
    spells[spell,0] = file;
    spells[spell,1] = name;
  } else {
    dest = MAGICSPELLS + (lore = event[E_LORE]);
    if (unguarded("@magic", #'file_size, dest) != -2)
      return error("'" + lore + "' is no valid lore.");
    dest += "/" + (art = event[E_ART]);
    if (unguarded("@magic", #'file_size, dest) != -2)
      return error("'" + art + "' is no valid art.");
    dest += "/" + implode(explode(spell," "),"_") + ".c";
    if (!unguarded("@magic", #'copy_file, ({ file, dest })))
      return error("Couldn't install this spell!");
    spells[spell,0] = dest[1..<3];
    spells[spell,1] = 0;
    magic_log("SPELLS", "Spell '" + spell + "' approved by " +
                        LIB_NAME->to_vis_name(name));
  }
  if (approve)
    write("Spell '" + spell + "' added and approved.\n");
  else
    write("Spell '" + spell + "' added.\n");
  save_me();
  return 1;
}

public status remove_spell(string spell) {
  string name, *spellname, file, *parts;
  int i;

  name = this_player()->query_real_name();
  if (!sizeof(spellname = identify_spell(spell, this_player())))
    return error("There's no spell called '" + spell + "'");
  if (sizeof(spellname) > 1)
    return error("Which spell do you want to remove: " +
    		 make_list(spellname, 0, " or ") + "?\n");
  if (!check_privilege("@magic") && (spells[spellname[0],1] != name))
    return error("You aren't allowed to remove the spell '"+spellname[0]+"'");

  if (get_eval_cost() < 5000) for(;;);

  parts = explode(lower_case(spellname[0]), " ");
  for (i=0; i<sizeof(parts); i++) {
    if (!spellist[parts[i]])
      continue;                  // should never happen ...
    spellist[parts[i]] -= ({ spellname[0] });
    if (!sizeof(spellist[parts[i]]))
      m_delete(spellist, parts[i]);
  }
  if (!spells[spellname[0],1]) {
    magic_log("SPELLS", "Spell '" + spellname[0] + "' deleted by " +
                        LIB_NAME->to_vis_name(name));
    file = spells[spellname[0],0];
    unguarded("@magic", #'copy_file,
              ({ file, MAGICTRASH+explode(file, "/")[<1] }));
    unguarded("@magic", #'rm, file);
  }
  m_delete(spells, spellname[0]);
  save_me();
  write("Spell '" + spellname[0] + "' deleted.\n");
  return 1;
}

public status learn_magic(object ob, string str, int value) {
  if (illegal_access(ob))
    return error("You aren't allowed to teach players!");
  switch (query_magic(str)) {
  case 0: return error("There is no magic called '" + str + "'.");
  case 1: return ob->learn_magic(query_magic_skill_path(str), value), 1;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

public status forget_spell(object ob, string spell) {
  string spellname, *tmp;

  if (illegal_access(ob) ||
      (is_wizard(ob) && ob != this_player() && !check_privilege("@magic")))
    return error("You aren't allowed to do that!");

  switch (sizeof(tmp = identify_spell(spell, ob))) {
  case 0 : if (member(ob->query_spells(), spell)) {  // should no happen.
             ob->forget_spell(spell);
             return 1;
           }
           return error("There is no spell called '" + spell + "'.");
  case 1 : spellname = tmp[0];
           break;
  default: return error("Which spell do you want to let forget: " +
                        make_list(tmp, 0, " or ") + "?\n");
  }
  switch (to_string(query_spells(spellname))) {
  case "0": return error("There is no spell called '" + spellname + "'.");
  case "1": if (illegal_access(ob))
              return error("You aren't allowed to let players forget "
                           "spells.");
            return ob->forget_spell(spellname);
  default : if (illegal_access(ob))
              return error("This spell hasn't been approved yet.");
            return ob->forget_spell(spellname);
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

public status learn_spell(object ob, string spell) {
  string spellname, *tmp;

  switch (sizeof(tmp = identify_spell(spell, 0))) {
                              // changed this_player() to 0, Coogan, 04-Jun-99
  case 0 : return error("There is no spell called '" + spell + "'.");
  case 1 : spellname = tmp[0];
           break;
  default: return error("Which spell do you want to teach: " +
                        make_list (tmp, 0, " or ") + "?\n");
  }
  switch (to_string(query_spells(spellname))) {
  case "0": return error("There is no spell called '" + spellname + "'.");
  case "1": if (illegal_access(ob))
              return error("You aren't allowed to teach players.");
            return ob->learn_spell(spellname);
  default : if (illegal_access(ob))
              return error("This spell hasn't been approved yet.");
            return ob->learn_spell(spellname);
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

public status spell_info(string spell, object ob) {
  mixed tmp;
  object bp;
  string out, author, spellname;

  if (ob)
    tmp = identify_spell(spell, ob);
  else
    tmp = identify_spell(spell, 0);

  switch (sizeof(tmp)) {
  case 0 : if (!is_wizard(this_player()))
             message("You don't know such a spell.\n");
           else
             message("There is no such spell.\n");
           return 1;
  case 1 : spellname = tmp[0];
           break;
  default: message("Which spell do you mean: " +
                   make_list(tmp, 0, " or ") + "?\n");
           return 1;
  }

  if (!(bp = locate_spell(spellname)))
    return 0;
  tmp = bp->query_event();
  if ((author = bp->query_author()) && author != "")
    out = "   Invented by " + author;
  message("================================================================="
          "=============\n"
  	  "Spell \"" + spellname + "\" " + out + "\n"
  	  "================================================================="
          "=============\n");

  out = "\nLore: " + capitalize(tmp[E_LORE]);
  if (is_wizard(this_player()))
    out += " (skill level: " + tmp[E_LORE,1] + ")";
  out += "    Art: " + capitalize(tmp[E_ART]);
  if (is_wizard(this_player()))
    out += " (skill level: " + tmp[E_ART,1] + ")";
  out += "\n";

  if (tmp[E_REQUISITE])
    out = "Requisite: " + capitalize(tmp[E_REQUISITE]) + " (" +
	  tmp[E_SKILL][tmp[E_REQUISITE]] + ")\n";
  out += "\n";
  write(out);

  if (!tmp[E_COST])
    out = "variable casting cost ";
  else
    out = "fixed casting cost of "+to_string(tmp[E_COST])+" spell points ";
  switch (tmp[E_DELAY]) {
  case 0:
    out += "and goes into effect instantly.";
    break;
  case 1..1000:
    out += "and takes only a second to cast.";
    break;
  case 1001..5000:
    out += "and takes only a few seconds to cast.";
    break;
  case 5001..30000:
    out += "and takes about "+LIB_LANGUAGE->word_number(tmp[E_DELAY]/1000) +
           " seconds to cast.";
    break;
  case 30001..60000:
    out += "and takes more than half a minute to cast.";
    break;
  default:
    out += "and takes alot of time to cast.";
    break;
  }

#if 0
  switch(this_player()->query_spells(spellname)) {
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
#endif
  message(spellname + " has got a " + out + "\n");
  if (out = bp->query_info())
    send_message(({ M_WRITE, M_RAW, "\n", out }));
  return 1;
}

/*****************************************************************************/

static void start_spell(mapping se) {
  locate_spell(se[E_SPELL])->start_spell(se);
}

static void execute_spell(mapping se) {
  if (se[E_HANDLED] || se[E_SUCCESS] < 0)
    return;
  se[E_HANDLED] = locate_spell(se[E_SPELL])->execute_spell(se);
  this_player()->restore_spell_points(-se[E_COST]);
}

static void finish_spell(mapping se) {
  locate_spell(se[E_SPELL])->finish_spell(se);
}

void create() {
  set_privilege("@magic");
  listen_event(E_MAGIC, EPRIO_START_MAGIC,   #'start_spell);
  listen_event(E_MAGIC, EPRIO_EXECUTE_MAGIC, #'execute_spell);
  listen_event(E_MAGIC, EPRIO_FINISH_MAGIC,  #'finish_spell);
  set_global_listening_event(E_MAGIC, 1);
  unguarded("@magic", #'restore_object, MAGICSAVE);
  if (!spells || sizeof(spells) == 0) {
    spells = m_allocate(0,3);
    spellist = ([ ]);
  }
}

