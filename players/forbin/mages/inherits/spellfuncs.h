int is_mage(object x) { return (x->is_player() && present("forbin_mage_object", x)); }
int not_cleric(object x) { return !is_mage(x); }

void mage_say(string x)
{
  object *objs;
  int    s;
  objs = filter_array(all_inventory(environment(this_player())), "is_mage", this_object());
  
  s = sizeof(objs);
  while(s--)
  {
    if(objs[s] != this_player())
      tell_object(objs[s], x);
  }
}

void other_say(string x)
{
  object *objs;
  int s;
  objs = filter_array(all_inventory(environment(this_player())), "not_mage", this_object());
  
  s = sizeof(objs);
  while(s--)
  {
    if(objs[s] != this_player())
      tell_object(objs[s], x);
  }
}

spell_failure(int w, string x, string y, string z) /* w = spell level */
{                                                  /* x = primary attribute */
	int success_chance, fail_chance;                 /* y = secondary attribute */
	int level;                                       /* z = school */
	int school;
	int primary, secondary;

  level = w;
  primary = query_attribute(x); primary *= 2; primary /= 3;
  secondary = query_attribute(y); secondary *= 2; secondary /= 3;
  school = query_school(z); school *= 2;
  
  /* failure is based on spell level * 50, ranges from 50- 350 */
  fail_chance = level * 50;
  
  /* success is based on 2/3 primary stat + 1/3 secondary stat + 2 * school, 
     ranges from 0-300 */
  success_chance = primary + secondary + school;
  
  /* give level 1 mages a break */
  if(previous_object()->query_glevel() < 2) 
    total += 20;

  /* randomize fail_chance */
  fail_chance = random(fail_chance);
  
  if(this_player()->query_level() > 99)
    tell_object(this_player(),
      "Fail Chance: "+fail_chance+" [vs] Success Chance: "+success_chance+"\n"+
      "P["+x+"]: "+primary+" S["+y+"]: "+secondary+" S["+z+"]: "+school+"]\n");
      
  if(fail_chance > success_chance)
    return 1; /* failure */
  else
    return 0; /* success */  
}

string colorize_letters(string str) {
  string msg, letter;
  int i;

  msg = "";
  for(i = 0; i < strlen(str); i++) {
    letter = extract(str,i,i);
    switch(random(13)) {
      case 0: letter = RED+letter; break; 
      case 1: letter = YEL+letter; break;
      case 2: letter = GRN+letter; break;
      case 3: letter = BLU+letter; break;
      case 4: letter = CYN+letter; break;
      case 5: letter = MAG+letter; break;
      case 6: letter = HIR+letter; break;
      case 7: letter = HIY+letter; break;
      case 8: letter = HIG+letter; break;
      case 9: letter = HIB+letter; break;
      case 10: letter = HIC+letter; break;                  
      case 11: letter = HIM+letter; break;
      case 12: letter = HIW+letter; break;
    }
    msg += letter;
  }
  msg += NORM;
  return msg;
}

string colorize_string(string str) {
  string msg;
  switch(random(13)) {
    case 0: msg = RED+str+NORM; break; 
    case 1: msg = YEL+str+NORM; break;
    case 2: msg = GRN+str+NORM; break;
    case 3: msg = BLU+str+NORM; break;
    case 4: msg = CYN+str+NORM; break;
    case 5: msg = MAG+str+NORM; break;
    case 6: msg = HIR+str+NORM; break;
    case 7: msg = HIY+str+NORM; break;
    case 8: msg = HIG+str+NORM; break;
    case 9: msg = HIB+str+NORM; break;
    case 10: msg = HIC+str+NORM; break;                  
    case 11: msg = HIM+str+NORM; break;
    case 12: msg = HIW+str+NORM; break;
  }
  return msg;
}

void report_damage(int amount, object player, object target) 
{
  string what;
  
  switch(amount)
  {
    case 75..10000 : what = GuildColor+BOLD+"ANNIHILATES"+NORM; break;
    case 61..74    : what = GuildColor+BOLD"devastates"+NORM; break;
    case 46..60    : what = GuildColor+"pulverizes"+NORM; break; 
    case 31..45    : what = HIW+"crushes"+NORM; break;
    case 21..30    : what = "flattens"; break;
    case 11..20    : what = "smashes"; break;
    case 5..10     : what = "hits"; break;
    case 0..4      : what = "annoys"; break;
    default        : what = "hits"; break;
  }

  tell_object(player,
    "Your spell "+what+" "+(string)target->query_name());
  tell_room(environment(player),
    (string)player->query_name()+"'s spell "+what+" "+
    (string)target->query_name(), ({ player}));

  if(amount > 30) 
  {
    tell_object(player, "!");
    tell_room(environment(player),"!\n", ({ player }));
  }
  else 
  {
    tell_object(player, "!");
    tell_room(environment(player),"!\n", ({ player }));
  }
  if((int)player->query_level() > 99) 
  {
     tell_object(player, GuildColor+BOLD+"["+HIW+amt+GuildColor+BOLD+"]\n"+NORM);
  }
  else 
    write("\n");
  return;
}

mixed valid_spell(string str, object player, int pkflag, int nowepflag, string spellname)
{
  object target;
  
  if(player->query_ghost()) return 0;
  
  if(!str) return 0;

  target = present(str, environment(player));
  
  if(!target)
    target = (object)player->query_attack();
    
  if(!target)
  {
    tell_object(player,
      "What do you want to cast a spell upon?\n");
    return 0;
  }
  
  if(!player->valid_attack(target))
  {
    tell_object(player,
      "You cannot cast "+spellname+" upon "+str+"!\n");
    return 0;
  }
  
  if(pkflag && (int)target->is_player())
  {
    tell_object(player,
      "You cannot cast "+spellname+" upon a player!\n");
    return 0;
  }
  
  if(nowep && (string)player->query_weapon())
  {
   tell_object(player,
     "You cannot cast "+spellname+" while wielding a weapon!\n");
   return 0; 
  }
  
  if((string)environment(player)->realm() == "NM")
  {
    tell_object(player,
      "Your power is being drained here.\n");
    return 0;
  }

  return target;
}

