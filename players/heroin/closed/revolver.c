#define TP this_player()->query_name()
#define ENV enviroment 
#define CAP capitalize
#define TO this_object()
#define ENVTP enviroment(this_player())
#define ENVTO enviroment(this_object())
#define RN this_player()->query_real_name()
#define BOLD ESC+"[1m"
#define NOSTYLE ESC+"[0m"

id(str){return str=="roulette" || str == "game" || str == "russian";}
short(){ return "Russian Roulette";}
long(){ write("You have in your hand a russian roulette revlover.\n"+
"There are six chambers and one bullet.  The game is simple: \n"+
"You put the gun in you mouth and pull the trigger..If you survive\n"+
"you get 20000 life experience, if you dont you DIE.  If you want to\n"+
"try your luck, just type 'pull trigger'\n");
return 1;}
init(){
if(this_player()->query_level() <10) {
destruct(TO);
}
if(this_player()->query_level() >=10){
add_action("play_game", "pull_trigger");
add_action("bet","bet");
add_action("odds","odds");
}
}
play_game(){
object crap;
int i;
i=random(6);
if(i<=2) {
write("<<<<<<<<<<BOOM>>>>>>>>>>  Guess you're dead.\n");
say(TP+" puts the gun in their mouth...<<*BOOM*>>..Too Bad for them.\n");
this_player()->add_exp(-30000);
crap = present("russian",this_player());
destruct(crap);
return 1; }
else {
say ("Click...empty chamber, Whew.  You exhale, that was a close one.\n");
write("Well, you win THIS TIME..wanna try your luck again?\n");
this_player()->add_exp(18000);
crap = present("russian",this_player());
destruct(crap);
return 1;
}
crap = present("russian", this_player());
destruct(crap, this_player());
return 1;
}
get() {return 1;}
drop() {return 1;}


