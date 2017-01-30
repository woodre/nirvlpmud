neo_physical_special()
{
	int total;
	total = 0;
	
	if(ArmorTotal)
	{
		if(!random(30) < ArmorTotal) 
		  tell_object(environment(this_object()), 
		    (string)environment(this_object())->query_pgcol()+
		    "["+HIW+"armor"+(string)environment(this_object())->query_pgcol()+"]"+NORM+
		    " Your armor glistens as it resists damage.\n");
		    
    total += ArmorTotal;
	}
	
  total += defense_tentacles();

  if((string)environment(this_object())->query_real_name() == "forbin" ||
    (string)environment(this_object())->query_real_name() == "fred" ||
    (string)environment(this_object())->query_real_name() == "toy" ||
    (string)environment(this_object())->query_real_name() == "fone") 
    tell_object(environment(this_object()), 
      HIG+"Armor total: "+total+".\n"+NORM);

	return total;
}
