object ob1;
reset(arg) {

	if(!ob1){
		ob1 = clone_object("players/catwoman/monster/super");
		move_object(ob1, this_object());
		}
     set_light(1);
     if (arg) return;
}

init() {
     add_action("east", "east");
     add_action("pick", "pick");
  add_action("expose","expose");
   }
pick(){
	write("No stealing!\n");
	return 1;
}
	
east() {
  call_other(this_player(),"move_player", "east#players/catwoman/city/32");
  return 1;
}
short() { return "Roof west"; }

long() {
 write("Roof\n");
 write("This is the west side\n");
 write("     Obvious exit: east\n");
}

realm() { return "NT";}

expose(str) {
object ob,ob2;
if(!str) { write("Expose what?\n"); return 1; }
if(!present("superman") && str == "superman to kryptonite") {
  write("I'm afraid Superman isn't here.\n");
  return 1; }
if(present("superman") && str == "superman to kryptonite") {
  ob = present("kryptonite",this_player());
  ob2 = present("superman",environment(this_player()));
  write("\n\n");
  write("You take the green rock and expose Superman...\n\n"+
	"his flesh begins to bubble and turn black....\n\n"+
	"and with a SCREAM of agony, he slumps to the\n\n"+
	"ground, twitches violently and then shrivels up!\n\n");
  write("You have killed Superman and solved the quest.\n");
  this_player()->set_quest("super");
  destruct(ob);
  destruct(ob2);
  write_file("/players/catwoman/closed/LOG/super_quest",
  this_player()->query_real_name()+" solved the quest.     "+
  ctime(time())+"\n");
  return 1; }
}
