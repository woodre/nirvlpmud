string messages;

void do_it() { 
	write(restore_object("players/illarion/noticeLD"));
	write("bloop\n");
	write(implode(explode(messages,"\\n"),"\n")); 
	
	write(restore_object("players/illarion/notice"));
	write(implode(explode(messages,"\\n"),"\n"));
}
