/***************************************************/
/*  allows npcs to 'summon' demons while in combat  */
/*  demons can block movement like other demons     */
/*  will also increase weapon class by 5 of npc     */
/***************************************************/

demon_check()
{
  object demon;
  int x;
  if(!attacker_ob) return 0;
  if(present("tyborlek enchantment", attacker_ob)) return 0;
  if("/players/zeus/closed/fl_demon"->query_e(attacker_ob->query_real_name()))
    return 0;
  if(hit_point > 400)
	  x = 7;
  else if(hit_point > 300)
	  x = 6;
  else if(hit_point > 200)
	  x = 5;
  else if(hit_point > 100)
	  x = 4;
  else if(hit_point >= 0)
	  x = 3;
  if(0 == random(x))
  {
	tell_room(environment(),
		"A demon emerges from the shadows.\n");
	demon = clone_object("/players/zeus/realm/x/NPC/demon.c");
	move_object(demon, environment());
	demon->attack_object(attacker_ob);
	weapon_class += 5;
	return 1;
  }
  else return 0;
}

