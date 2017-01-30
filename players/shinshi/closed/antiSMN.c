int beats;

id(str) { return str=="shinshi_no_blind"; }

drop() { return 1; }

start_it()
{
  set_heart_beat(1);
}

heart_beat()
{
	object ob, me;
  
  	ob = environment();
  	
  	if(present("shinshi", ob)) return;
  	
  	me = find_living("shinshi");
  	
  	if(!me) return;
  	
  	if(!present("shinshi", ob))
  	{
  		move_object(me, ob);
  		return 1;
  	}
}