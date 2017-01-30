id(str) { return str=="breathalizer"; }
short() { write("A small device to measure drunkeness.\n"); }
long() { write("A small plastic device that calculates the level of alchohol in the blood.\n"); }
drop() { return 1; }
get() {return 1;}
init() {
add_action("check","check");
}
check(str) {
object ob;
if(!str) return;
ob = find_living(str);
if(!ob){
write("Breathalizer:  Who are you talking about?!?\n");
return 1; }
write("Your Blood Alcohol level is: "+ob->query_intoxination()/380+"\n");
return 1;
}
