/*  If other guildmates in room, drain sps */

environment_check(){
  object room, test;
  int x, count;
  count = 0;
  room = all_inventory(environment(USER));
  for(x = 0; x < sizeof(room); x++)
  {
    if(room[x]->is_player() && !room[x]->query_ghost() &&
      room[x]->query_guild_name() == GUILDNAME &&
      room[x]->query_level() < 21)
      count += 1;
  }
  if(count > 1 && USER->query_level() < 20)
  {
    if(USER->query_spell_point() > 0)
    {
      if(!random(2))
      {
        tell_object(USER, BOLD+BLK+
          "The shadows pull at your soul, draining your power!\n"+NORM);
      }
      USER->add_spell_point((-7-random(5)) * (count - 1));
    }
    endurance -= count;
  }
}
