mixed valid_attack(string str, object player)
{
  object local_target;
  
  if(player->query_ghost()) return 0;
  
  if(!str) return 0;

  local_target = present(str, environment(player));
  
  if(!local_target)
    local_target= (object)player->query_attack();
  
  if(!local_target)
  {
    tell_object(player,
      "What do you want to attack?\n");
    return 0;
  }
  
  if(!player->valid_attack(local_target))
  {
    tell_object(player,
      "You can't attack "+str+"!\n");
    return 0;
  }
  
  if((string)environment(player)->realm() == "NM")
  {
    tell_object(player,
      "Your power is being drained here.\n");
    return 0;
  }

  return local_target;
}
