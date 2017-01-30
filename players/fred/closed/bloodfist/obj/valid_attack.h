
mixed valid_attack(string str, object User)
{
  object local_nmy;
  if(User->query_ghost()) return 0;
  if(!str) return 0;

  local_nmy = present(str, environment(User));
  if(!local_nmy)
    local_nmy = (object)User->query_attack();
  if(!local_nmy)
  {
    TOU "What do you want to attack?\n");
    return 0;
  }
  if(!User->valid_attack(local_nmy))
  {
    TOU "You can't attack "+str+"!\n");
    return 0;
  }
  if((string)environment(User)->realm() == "NM")
  {
    TOU "Your power is being drained here.\n");
    return 0;
  }

  return local_nmy;
}

