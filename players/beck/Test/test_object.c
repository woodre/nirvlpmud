
#include "/players/beck/Test/DoDamageModular.c"
id(str) { return str=="fly" || str=="fly"; }
reset () { HitPoint = 500; }
short() {
return "A Fly";
}
long() {
write("The partially digested remains of a small horse fly.\n");
return 1;
}
get() {
	return 1;
	}
query_weight() { return 1; }
query_value() { return 100; }
init(){
add_action("hit","hit");
}
hit(){
DoDamage(15);
write("Hit Points: "+HitPoint+"\n");
return 1;
}
