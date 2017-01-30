#define user environment(this_object())
id(str) { return str=="nojoin"; }
int x;
reset(arg) {
	if(arg) return;
	if(!arg) x=0;
}
init(){
call_out("hb",1);
}
hb() {
	if(x == 1) {
	say("The room seems to grow colder and you are filled with a sudden fear.\n");
	}
	if(x == 5){
	say("A mist slowly fills the room.\n"); }
	if(x == 10){
	say("Hands reach out from the mist behind you and pull back your head.\n"); }
	if(x == 18){
	say("Cold fingers run over your exposed neck.\n");
	}
	if(x == 22){
	say("An evil dark evil voice from behind you says: You must be loyal to only me.\n"+
"Disban your other guild and you may join our ranks.\n"); }
	if(x == 26){
	say("The cold hands release you and the mist is gone.\n"); 
	destruct(present("nomove", environment(this_object())));
	destruct(this_object());
	}
x = x + 1;
call_out("hb",1);
}
get() { return 1; }
