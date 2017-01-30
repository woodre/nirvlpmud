#include "../DEFS"

int cmd(string str){
    if(!str || (str !="church" && str !="guild")){
	write("Where do you want to login? (church/guild)\n");
	return 1;
    }
    if(str == "church")
	this_player()->set_home("/room/church.c");
    if(str == "guild")
	this_player()->set_home(PATH+"/room/necro2.c");
    write("<"+HIR+"NeCRo"+OFF+"> Your login position has been changed.\n");
    return 1;
}
