id(str) { return str == "testd"; }

get() { return 1; }
drop() { return 0; }

init() {
	add_action("cmd_hook"); add_xverb("testcmd");
}

cmd_hook(str) {
	if (!str) 
           return 0;
	write("Command given: "+str+"\n");
	if (!("players/gowron/closed/monk/cmd/"+str->cmd()))
         return 0;
	return 1;
}
