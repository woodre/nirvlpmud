void save_gob() 
{
  object e;
  if((e = environment()) && !e->query_npc()) 
  {
    SavedDelays = deconstruct_mapping(Delays);
    save_object(SAVE_PATH + (string)e->query_real_name());
  }
}           

void backup_gob() 
{
  object e;
  if((e = environment()) && !e->query_npc()) 
  {
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
    Delays = reconstruct_mapping(SavedDelays);
    return result;
  }
}

void update_gob() 
{                                             
  object new;
  save_gob();
  new = clone_object(GUILD_FILE);
  move_object(new, environment());
  destruct(this_object());
}

void guild_quit() 
{ 
  environment(this_object())->set_guild_name("Dark Mages");
  save_gob();
  return; 
}

status check_glevel() 
{
  int x, y;
  x = SizeofGLC;
  y = GuildLevel;
  for(y = GuildLevel; y < x; y++) 
  {
    if(GuildXP > GuildLevelCosts[y+1]) 
    {
      return 1;
    }
    else 
      return 0;
  }
}