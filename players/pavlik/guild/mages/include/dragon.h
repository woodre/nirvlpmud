#define MAX_LEVEL	20
#define MAX_ATTACK	60
#define MAX_DEFENSE	60
#define MAX_STAMINA	50
#define MAX_MAGIC	50

/*
 * Exp Cost
 */
get_exp_for_level(i)
{
  if(i == 1)  return 0;
  if(i == 2)  return 4500;
  if(i == 3)  return 9000;
  if(i == 4)  return 25000;
  if(i == 5)  return 68500;
  if(i == 6)  return 120000;
  if(i == 7)  return 188000;
  if(i == 8)  return 290020;
  if(i == 9)  return 450000;
  if(i == 10) return 729000;
  if(i == 11) return 1004150;
  if(i == 12) return 1401600;
  if(i == 13) return 1989050;
  if(i == 14) return 2440500;
  if(i == 15) return 3001000;
  if(i == 16) return 3600500;
  if(i == 17) return 4408000;
  if(i == 18) return 5222500;
  if(i == 19) return 6012000;
  if(i >= 20) return 7000000;
}


get_exp_cost(obj, stat)
{
  int x;

  if(stat == "level")
        return get_exp_for_level(obj->query_dragon_level() + 1);
  else if(stat == "attack")
	x = call_other(obj, "query_dragon_"+stat);

  x++;
  if(x < 10) return 1000;
  else if(x < 20) return 1450;
  else if(x < 30) return 2400;
  else if(x < 40) return 5000;
  else if(x < 50) return 7250;
  else return 10000;
}


get_gold_cost(obj, stat)
{
  if(stat == "level")
        return obj->query_dragon_level() * 2400;
  else if(stat == "attack")
        return obj->query_dragon_attack() * 300;
  else if(stat == "defense")
        return obj->query_dragon_defense() * 300;
  else if(stat == "stamina")
        return obj->query_dragon_stamina() * 800;
  else if(stat == "magic")
        return obj->query_dragon_magic() * 900;
  else
        return 0;
}


