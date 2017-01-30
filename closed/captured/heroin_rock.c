id(str) { return str == "rock"; }
 
reset() {}
 
long() { write("You have a ordinary pebble.\n"); }
 
short() { return "A small rock"; }
 
init() {
    add_action("cast"); add_verb("cast");
    add_action("rock"); add_verb("rock");
}
 
cast(arg) {
    if (arg=="heal") {
    rock();
        return 1;
    } else {
        return 0;
    }
}   
rock(str){
         object obj;
         int damage;
 
 if(!this_player()->query_attack()){
         write("You must be fighting to use this spell.\n");
         return 1; 
        }
 
 if(!str && !this_player()->query_attack()){
         write("Usage: rock<target>.\n");
         return 1; 
         }
 
 if(!str && this_player()->query_attack())
         obj = this_player()->query_attack();
 else
        obj = present(str, environment(this_player()));
 
 if(!obj){
         write("That is not here.\n");
         return 1; 
         }
 
damage = 1000 ;
 obj->hit_player(damage);
 return 1;
 }            
get() {return 1;}
