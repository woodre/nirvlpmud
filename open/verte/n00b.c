#define N00B_LEVEL 8
#define N00B_HEALTH_PCT 10

void heart_beat()
{
  ::heart_beat();
  if(root()) return;
  this_object()->n00b();
}

void n00b()
{
  object *objs, obj;
  int    x, y;
  
  objs = all_inventory(environment(this_object()));
  y = sizeof(objs);
  
  for(x = 0; x < y; x ++)
  {
    if(!(obj = objs[x])) continue;
    if(obj->is_player() && (int)obj->query_level() < N00B_LEVEL
       && (object)obj->query_attack() == this_object())
    {
      int hp, mhp;
      hp = (int)obj->query_hp();
      mhp = (int)obj->query_mhp();
      if(hp * 100 / mhp <= N00B_HEALTH_PCT)
      {
        tell_object(obj, "4 U Die, Saving jah n00b.\n");
        move_object(obj, "/room/prison"); /* or wherever */
      }
    }
  }
}
        
      
