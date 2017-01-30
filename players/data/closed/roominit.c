init(){
   ::init();
    add_action("cmd_report","dtypo");
    add_action("cmd_report","dbug");
    add_action("cmd_report","didea");
    add_action("search","search");
    add_action("area_help", "dhelp");
}

int area_help(){
	tell_object(this_player(),
		"Commands available:\n"+
		"dtypo.........................report a typo\n"+
                "dbug..........................report a bug\n"+
                "didea.........................suggest a idea\n");
return 1;}

int cmd_report(string str) {
  write_file("/players/data/log/feedback.log",
    ctime(time())+" "+capitalize((string)this_player()->query_real_name())+
    " reported a "+query_verb()+" from\n"+
   file_name(this_object())+":\n"+
    str+"\n");
  write("Your suggestion has been forwarded to Data.\n"+
        "Thank you for helping to make this a better area.\n");
  return 1;
}

int search(string str) {
  notify_fail("You find nothing.\n");
  say(this_player()->query_name()+" searches around the room.\n");
  return 0;
}