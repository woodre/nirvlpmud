#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";
#define TPN this_player()->query_name()

int x;
int play;
int passwordwritten;
int useridwritten;
string argomento;
string argomento1;
string userid;
string password;

set_userid(argomento) {userid=argomento;}
set_password(argomento1) {password=argomento1;}

reset(arg){
    if (arg) return;
    set_id("paper");
    set_alias("paper");
    set_short(HIW+"A piece of paper"+NORM);
}

long() {
    if(passwordwritten || useridwritten){
	write("The paper has something written on it which can be 'read'.\n");
	return 1;}
    else
	write("It is possible to 'write' the 'password' and the 'userid' on the paper.\n");
    return 1;}


init() {
    ::init();
    add_action("read_paper","read");
    add_action("write_paper","write");
    add_action("login","login");
    if(this_player() != environment(this_object())) 
	return; 
}

read_paper(str) {
    if (!str) {notify_fail("Read what?\n");return 0;}
    if(str == "paper") {
	if(useridwritten && passwordwritten) 
	{write("The password is "+password+"\n");
	    write("The userid is "+userid+"\n"); return 1;}
	if(passwordwritten) 
	{ write("The password is "+password+"\n"); return 1; }
	if(useridwritten) 
	{ write("The userid is "+userid+"\n"); return 1;}
	write("Nothing is written on the paper.\n");
	return 1;}
    notify_fail("You cannot read the "+str+".\n");
    return 0;}

write_paper(str) {
    if (!str) {notify_fail("Write what?\n");return 0;}
    if (str=="password" && password) {
	if(passwordwritten) {notify_fail("The password has been already written on the paper.\n"); return 0;}
	write("You write "+password+" on the paper.\n");
	passwordwritten = 1;
	return 1;}
    if (str=="userid" && userid) {
	if(useridwritten) {notify_fail("The userid has been already written on the paper.\n"); return 0;}
	write("You write "+userid+" on the paper.\n");
	useridwritten = 1;
	return 1;}
    notify_fail("You cannot write the "+str+" on the paper.\n");
    return 0;}

login() { 
    if(!present("computer_fran",environment(this_player())))
    {notify_fail("What / where / when do you want to login?\n");  return 0;}
    else {
	write("Please enter the userid:");
	input_to("enter_userid");}
    return 1;
}

enter_userid(string str) {
    if(str== userid) {
	write("Please enter the password:");
	input_to("enter_password"); }
    else
    {write("Hmmm, no, that didnt work.\n"); return 1;}
    return 1;
}

enter_password (string str) {
    if(str==password) {
	this_player()->set_quest("mastermind");
	write_file("/players/francesco/masterquest/mastermindsolved.log",ctime(time())+"  "+TPN+
	  " solved mastermind quest with userid = "+userid+" and password = "+password+"\n"); 
	play=1;
	call_out("congrats",3); 
	return 1;}
    else
    {write("Hmmm, no, that didnt work.\n"); return 1;}
}

congrats() {
    /*      write_file("/players/francesco/masterquest/mastermindsolved.log",ctime(time())+"  "+TPN+
		   " solved mastermind quest with userid = "+userid+" and password = "+password+"\n"); 
    */
    narrate_it();
    x += 1;
    if(x<6) call_out("congrats",10);
    else { play = 0; x = 0; 	
	/*         this_player()->set_quest("mastermind"); */
	destruct(this_object());}
    return 1; }

narrate_it() {
    string lyric1;
    switch(x) {
    case 0: lyric1 = "\nAfter typing the correct userid and the correct password the\n"+
	"computer goes all black, then flashes and beeps, then goes \n"+
	"all black again.\n\n";break;
    case 1: lyric1 = "The computer lights up again and some words and drawings begin\n"+
	"to appear on the screen.\n\n";break;
    case 2: lyric1 = "'The computer had been recently formatted and the data had been \n"+
	"transferred on Fran's portable computer.'\n\n";break;
    case 3: lyric1 = "'Therefore, it is not possible to steal his data anymore.'\n\n";break;
    case 4: lyric1 = "'Yet, in recognition of your efforts, on behalf of Nirvana's\n"+
	"administrators, Francesco will credit you 11 quest points.'\n\n";break;
    case 5: lyric1 = "\n    CONGRATULATIONS\n\n";break;}
    say (HIW+lyric1+NORM);
    return 1; }


get() {return 0;}
drop() {return 1;}

