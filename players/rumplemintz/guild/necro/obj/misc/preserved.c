string name,shortdesc,longdesc;
int corpse_level;
string info;

reset() { }
init(){
    add_action("bury_me","bury");
}

bury_me(str){
    if(!str){
	notify_fail("What would you like to bury?\n");
	return 0;
    }
    if(!id(str)){
	notify_fail("That is not something you can bury.\n");
	return 0;
    }
    write("You bury the corpse underneath the dirt.\n");
    say(this_player()->query_name()+" buried the corpse underneath the dirt.\n");
    destruct(this_object());
    this_player()->recalc_carry();
    return 1;
}

set_name(n) { name = n; }

short() {
    if(!name) {
	set_name("an unknown victim"); }
    if(shortdesc)
	return shortdesc+" (preserved)";
    return "corpse of "+name+" (preserved)";
}

long() {
    if(longdesc){
	write(longdesc);
	write("You can 'bury' this corpse if it is no longer wanted.\n");
	return;
    }
    write("The perfectly preserved corpse of "+name+".\n"+
      "The corpse is ready for harvesting.\n");
    write("You can 'bury' this corpse if it is no longer wanted.\n");
}

id(str) {
    return str == "corpse" || str == "preserved corpse" || str == "preserved";
}
set_short(s){ shortdesc = s; }
set_long(l){ longdesc = l; }
set_corpse_level(arg) {
    corpse_level = arg;
    return 1; 
}
query_preserved(){ return 1; }
query_weight() { return 1; }
query_value() { return 0; }
get() {return 1; }
query_name(){ return name; }
query_corpse_level() {return corpse_level; }
heal_value(){ return (corpse_level*9)/10; }
set_info(i){ info = i; }
query_info(){ return info; }
