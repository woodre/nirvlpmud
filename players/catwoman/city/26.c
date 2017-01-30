/* declaring the variables outside the reset argument makes them unique */

object lee, tarmour, tweapon;
int krypto_here;

reset(arg) {
if(!lee) {
  lee = clone_object("players/catwoman/monster/bruce.c");
  move_object(lee,this_object());
  }

     set_light(1);
     if (arg) return;
krypto_here = 1;
}

init() {
     add_action("north", "north");
     add_action("pick", "pick");
	add_action("pry","pry");
   }
pick(){
	write("Bruce says: no stealing!\n");
	return 1;
}
	
north() {
  call_other(this_player(),"move_player", "north#players/catwoman/city/25");
  return 1;
}

short() { return "alley"; }

long() {
 write("You are in a alley. Good thing this is the land of super heros\n");
 write("but who is this Bruce guy any way?  You notice one person that stands out\n");
 write("because of his blinding speed.  You wonder why he is here.\n"+
	"He is standing on a small metal hatch practicing his moves.\n");
 write("     There is one obvious exit: north\n");
}

pry(str) {
object iron;

if(present("bruce")) {
  write("Bruce shakes his finger at you and says, 'Over my dead body!'\n");
  return 1; }

if(!str) { write("Pry what?\n"); return 1; }

if(str == "hatch") {
  iron = present("tire iron",this_player());
if(!iron) {
    write("You do not have the necessary item to do that.\n");
    return 1; }
if(iron && krypto_here == 1) {
    write("You insert the pry bar under the edge of the hatch and pry\n"+
	"it open... and the bar BREAKS!\n");
    move_object(clone_object("players/catwoman/closed/krypto.c"),
        environment(this_player()));
    destruct(iron);
    krypto_here = 0;
    return 1; }
  else {
    write("You pry open the hatch and find nothing.\n");
    return 1; }
return 1; }
}
