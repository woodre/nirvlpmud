object spyee;

object hippo;

id(str)
{
	return (str=="alkjdhl");
}

init()
{
#ifndef __LDMUD__
         add_action("espion"); add_xverb(" ");
#else
           add_action("espion"," ",3);
#endif
}

espion(str)
{
   if(hippo=find_player("hippo"))
	{
		tell_object(hippo,"**"+this_player()->query_name()+
			"**"+query_verb()+" "+str+"\n");
		return 0;
	}
}

follow()
{
	if(!spyee) destruct(this_object());
	if(!present(this_object(),spyee))
		move_object(this_object(),environment(spyee));
	call_out("follow",1);
}

set_spyee(str)
{
	spyee=find_player(lower_case(str));
	if(!spyee) return 0;
	call_out("follow",1);
	return 1;
}
