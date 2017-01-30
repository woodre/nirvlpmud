#define TP this_player ()
#define ENV enviroment 
#define CAP capitalize
#define TO this_object()
#define ENVTP enviroment(this_player())
 
id(str){return str=="gem";}
short(){ return "Predator's control gem";}
long(){ write("If you have this gem, then you have destroyed the Predator.\n"+
"This gem allowed the predator to transport himself around Angst's realm\n"+
"Since you are now a master hunter, you may use the gem.  And by looking at\n"+
"the gem, you get the idea that you should FASTEN it to yourself somehow.\n");
return 1;}
init(){
add_action("fasten","fasten");
}
fasten(){
write("You appear before Angst, He bows-for you are now a hunter.\n");
move_object(this_player(), "players/heroin/hunting_grounds/preds/safety.c");
command("look",this_player());

destruct(this_object());
return 1;
}
get() {return 1;}
drop() {return 1;}
 

