#define user environment(this_object())
id(str) { return str=="join"; }
reset(arg) {
	if(arg) return;
}
init(){
call_out("hb",1);
call_out("hb2",10);
call_out("hb3",20);
call_out("hb4",30);
call_out("hb5",40);
call_out("hb6",50);
call_out("hb7",60);
call_out("hb8",70);
call_out("hb9",80);
call_out("hb10",90);
}
hb() {
	tell_object(user, "The room seem to grow colder and you are filled with a sudden fear.\n");
	}
hb2() {
	say("A mist slowly fills the room.\n"); }
	hb3() {
	say("The mist swirls around and takes the shape of Shardak.\n"); }
	hb4() {
	say("Shardak walks toward you as he stares into your soul.\n"); }
	hb5() {
	say("Cold fingers grasp your wrists as Shardak pulls you close to him.\n");
	}
	hb6() {
	say("You feel great pain as Shardak takes a claw and begins to cut a symbol\n"+
"into the palm of your hand.  Your blood begins to flow onto the floor.\n"); }
	hb7() {
	say("You hand feels on fire as Shardak finishes his work, then lets 3 drops\n"+
"of your blood fall into the bowl.  He shoves your hand into the bowl of blood.\n"); }
	hb8() {
	say("Shardak sends a message to your mind: The blood of the group now runs\n"+
"in your veins.  Prove to me your abilities and I will give you great powers.\n"); }
	hb9() {
	say("Shardak touches your hand and the wound closes.  Only the scar remains.\n"); }
	hb10() {
	object mark;
	mark=clone_object("/players/dragnar/guild/mark.c");
    move_object(mark, environment(this_object()));
	say("The mist envelops Shardak and he vanishes.\n");
	destruct(present("nomove", environment(this_object())));
	destruct(this_object());
	}
get() { return 1; }
