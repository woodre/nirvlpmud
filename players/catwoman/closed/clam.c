object ob1, ob2;
int is_open;

reset(arg) {
/*for cloning monster etc*/
        if(!ob1){
                ob1 = clone_object("players/catwoman/monster/eel");
                move_object(ob1, this_object());
                }
        if(!ob2){
                ob2 = clone_object("players/catwoman/monster/eel");
                move_object(ob2, this_object());
                }

     set_light(1);
     if (arg) return;
is_open = 0;
}


init() {
     add_action("south", "swim");
     add_action("open", "open");
	add_action("read","read");
     add_action("pick", "pick");
   }
pick(){
        write("No stealing!\n");
        return 1;
}
        
south() {
  call_other(this_player(),"move_player", "up#players/catwoman/city/22");
  return 1;
}
 
open(str) {
if(present("eel")) {
  write("The eel shreeks and bites at your hand.\n"); return 1; }
if(str == "clam") {
  if(is_open == 0) {
    write("You grasp the clam shell and split it open.\n");
    is_open = 1;
    return 1; }
  else {
    write("The clam is already open.\n"); return 1; }
  return 1; }
}

read(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "clam") {
  write("How do you read a clam?\n"); return 1; }
if(str == "shell" && is_open == 1) {
  write("The scribbling on the shell reads....\n"+
	"Buried at the end of the cobblestone\n"+
	"path by the mansion is a special item.\n"+
	"You'll know what to do with it...\n");
  move_object(clone_object("players/catwoman/closed/qst1.c"),
		this_player());
  return 1; }
else {
  write("The clam is closed and there's nothing to read on it's shell.\n");
  return 1; }
}

 
short() { return "Metropolis bay"; }

long() {
 write("You are at the bottom of metropolis bay\n");
 write("There is a giant dead clam here\n");
 write("\n");
 write("     Obvious exit: swim\n");
}

realm() { return "NT";}

