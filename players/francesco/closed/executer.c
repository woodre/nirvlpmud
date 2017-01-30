

reset()
{
    

}

short() { return "The executer"; }

long(str) {
    if (str == "executer") {
	write("Syntax: like a line of LPC, without the ;\n");
	return;
    }
    
}

status 
do_exec(string arg) {

  if ((string)this_player()->query_real_name() != "francesco")
    return 0;

  return (status) "/players/francesco/closed/exec2.c"->main(arg);
}

init() {
add_action("do_exec", "exec"); 
}      


id(str) { return str == "executer" ; }


read_book(str)
{
    write("\n        February 4th\n"+
          "   Happy B-Day, Francesco!\n\n");
    return 1;
}

get(str) {
    if (str == "flier") {
	write("The book is attached to a chain.\n");
	return 0;
    }
    if (str == "chain") {
	write("The chain is secured to the wall.\n");
	return 0;
    }
    return 0;
}
