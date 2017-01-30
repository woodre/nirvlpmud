void reset(int arg)
{
    if(arg) return;
    call_out("heal",1);
}

heal(){
	int xx;
	object obj;
	obj = users();
	for (xx = 0; xx < sizeof(obj); xx ++){
		if(present(obj[xx], environment(this_object()))) {
			if(obj[xx]->query_guild_name()=="druid"){
				present("druid_guild_object",obj[xx])->add_mana(100);
				tell_object(obj[xx],"mana goes higher");
			}
		}
	}
call_out("heal",10);
}
