object ob1, ob2, ob3;
reset(arg) {
	if(!ob1){
		ob1 = clone_object("players/catwoman/monster/ranger");
		move_object(ob1, this_object());
		}
	if(!ob3){
		ob3 = clone_object("players/catwoman/armor/mask");
		move_object(ob3, ob1);
		}
     set_light(1);
     if (arg) return;
}

init() {

     add_action("north", "north");
  add_action("question","question");
     add_action("pick", "pick");

   }
pick(){
	write("No stealing!\n");
	return 1;
}
	

north() {
  call_other(this_player(),"move_player", "north#players/catwoman/city/52");
  return 1; }

question(str) {
if(!str) { write("Question who?\n"); return 1; }
if(!present("ranger") && (str == "ranger" || str == "lone ranger")) {
  write("He doesn't seem to be here at the moment.\n");
  return 1; }
if(present("ranger") && str == "ranger" || str == "lone ranger") {
  write("\n");
  write("The ranger scratches his chin and drawls, 'I remember\n"+
	"having the item I think you boys is looking for.  I\n"+
	"wasn't sure who was after it so I hid it on Wizard\n"+
	"Island.........\n\n\n"+
	"It's been a while so good luck!'\n\n");
  return 1; }
}

short() { return "A Dead End"; }

long() {
 write("A dead end\n");
 write("To the north is Main Street\n");
 write("     Obvious exit: north\n");
}

realm() { return "NT";}

