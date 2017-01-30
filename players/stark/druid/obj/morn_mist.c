void reset(int arg)
{
    if(arg) return;
}

init(){
add_action("new_look", "look", 1);
}

new_look(){
	write("BLAH!");
	return 1;
}