#define TP this_player ()
#define ENV enviroment 
#define CAP capitalize
#define TO this_object()
#define ENVTP enviroment(this_player())
#define ENVTO enviroment(this_object())
#define RN this_player()->query_real_name()
#define BOLD ESC+"[1m"
#define NOSTYLE ESC+"[0m"
query_auto_load() {
return "/players/heroin/closed/hunt_stone.c:";
}
id(str){return str=="gem";}
short(){ return "Predator's control gem";}
long(){ write("If you have this gem, then you have destroyed the Predator.\n"+
"This gem allowed the predator to transport himself around Angst's realm\n"+
"Since you are now a master hunter, you may use the gem.  And by looking at\n"+
"the gem, you get the idea that you should FASTEN it to yourself somehow.\n");
return 1;}
init(){
if(TP->query_level() < 10) {
destruct(TO);
}
if(((TP->query_level()) >=10)) {
add_action("give_stone", "give");
add_action("fasten","fasten");
add_action("look","look");
}
}
fasten(){
write("You appear before Angst, He bows-for you are now a hunter.\n");
move_object(this_player(),"players/heroin/hunting_grounds/hunt1.c");
command("look",this_player());
return 1;
}
get() {return 1;}
drop() {return 1;}


