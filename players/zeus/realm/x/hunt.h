/***************************************************/
/*  this function allows the npcs to randomly hunt  */
/*  players while they are in the arena.            */
/***************************************************/

hunt()
{
  int c,d,yes;
  object y, meat;  
  meat = 0; c = 0; yes = 0;  nmys = ({ });
  if(!ENV) return;
  if(!sscanf(file_name(ENV), "players/zeus/realm/x/r/%s", w))
	return;
  while(c < 9)
  {
	y = all_inventory(arena[c]);
	for(d = 0; d < sizeof(y); d++)
	{
	  if(y[d]->is_player() && !y[d]->query_ghost())
	  {
		nmys += ({ y[d], });
		yes = 1;
	  }
	}
	c++;
  }
  if(yes)
  {
	meat = nmys[random(sizeof(nmys))];
	if(!present(meat, ENV))
	{
	  TR(environment(), LEAVE);
	  MO(TO, environment(meat));
	  TR(environment(), ARRIVE);
	} 
	TO->attack_object(meat); 
  }
}

