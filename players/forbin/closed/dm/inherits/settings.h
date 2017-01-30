/* guild experience *******************************************************/
void set_gexp(int x) { GuildXP = x; }
void add_gexp(int x) { GuildXP += x; }
void sub_gexp(int x) { GuildXP -= x; }
int query_gexp() { return GuildXP; }

/* guild level ************************************************************/
void set_glevel(int x) { GuildLevel = x; }
void advance_glevel() { GuildLevel ++; }
int query_glevel() { return GuildLevel; }

/* abilities **************************************************************/
mixed query_learned(string x)
{
  if(!x)
    return Learned;
  else 
    if(member_array(x, Learned) < 0) 
      return 0;
  else 
    return 1;
}
void learn(string x) { Learned += ({ x }); }
void unlearn(string x) { Learned -= ({ x }); }

/* fae stat ***************************************************************/
int query_fae() { return Fae; }
void add_fae(int x) { Fae += x; }
void sub_fae(int x) { Fae -= x; }
void set_fae(int x)
{
  Fae = x;
  if(Fae < 0)
    Fae = 0;
  if(Fae > 30)
    Fae = 30;
}

/* sacrifice **************************************************************/
int query_sacrifice() { return Sacrifice; }
int query_sacrifice_level()
{
  if(Sacrifice > 100000) return 5;
  if(Sacrifice > 80000)  return 4;
  if(Sacrifice > 40000)  return 3;
  if(Sacrifice > 20000)  return 2;
  else                   return 1;
  
 
}
void add_sacrifice(int x) { Sacrifice += x; }
void sub_sacrifice(int x) 
{ 
  Sacrifice -= x; 
  if(Sacrifice < 0) 
    Sacrifice = 0; 
}
void set_sacrifice(int x) 
{ 
  Sacrifice = x; 
  if(Sacrifice < 0) 
     Sacrifice = 0; 
}
void wipe_sacrifice() { Sacrifice = 0; }
status check_sacrifice(int x) 
{ 
  if(Sacrifice >= x) 
    return 1; 
  else 
    return 0; 
}

/* casting checks *********************************************************/
mixed query_casting(int x)
{ 
  if(x)
    return CurrentSpell;
  else
    return Casting; 
}
void set_casting(int x) { Casting = x; }
status casting_check()
{
  if(Casting)
  {
    tell_object(environment(previous_object()), 
      "You are currently casting a spell.\n");
    return 1;
  }
  return 0;
}

/* talent *****************************************************************/
void set_talent() { Talent = 1; }
int query_talent() { return Talent; }

/* special ability settings ***********************************************/
void set_symbol_pain(int x) { SymbolPain = x; }
int query_symbol_paint() { return SymbolPain; }