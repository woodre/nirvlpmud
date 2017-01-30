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
}

id(str) { return str == "flier" || str == "chain"; }



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
