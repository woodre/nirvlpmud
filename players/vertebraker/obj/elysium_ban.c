#define ok_chars ({"fleshhunter","shinshi","viral","myth"})
void reset(int x)
{
	if(x) return;
	call_out("done_for", 1);
}

void done_for()
{
	object *us;
	int s;
	string junk;
	us=users();
	s=sizeof(us);
	while(s--)
		if(us[s] && sscanf(query_ip_name(us[s]),"%saberdn01.md.comcast%s",junk,junk))
	 	{
       if(member_array((string)us[s]->query_real_name(),ok_chars) > -1) continue;
	 		tell_object(us[s],
	 			"\n\n\tYou are no longer welcome on Nirvana.\n"+
	 			"\tStay on Elysium.\n\n");
	 		destruct(us[s]);
	 	}
	call_out("done_for", 1);
}
	 		
