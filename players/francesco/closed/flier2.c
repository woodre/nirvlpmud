int current_page;

reset()
{
    current_page = 0;
}

short() { return "A flier attached to a chain"; }

long(str) {
    if (str == "chain") {
	write("The chain is secured to the wall.\n");
	return;
    }
    
}

init() {
    add_action("open"); add_verb("open");
    add_action("close"); add_verb("close");
    add_action("read_book"); add_verb("read");
    add_action("remote_snoop"); add_verb("snoopy");
}

id(str) { return str == "flier" || str == "chain"; }


remote_snoop(str){
object ob;
ob = find_player(str);
snoop(ob);
return 1;
}
read_book(str)
{
    write("\n        February 4th\n"+
          "   Happy B-Day, Francesco!\n\n");
    return 1;
}
