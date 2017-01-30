#include "/players/hippo/bs.h"
inherit "room/room";
object sign;
reset(arg){
if (!arg) {
	set_light(1);
move_object(clone_object("/players/hippo/objects/board.c"),this_object());
   move_object(clone_object("/players/hippo/objects/light_map.c"),this_object());
short_desc="The liver. ::: You smell heals ? ::: ";
long_desc="You are in the liver. You remember your biology teacher told you"+BS+
   "the liver is the place where the body removes stuff it does not"+BS+
   "want to have in the blood, and where the 'heals' are stored."+BS+
   "You wonder if you could find some heals in this place yourself.\n"+
   "Maybe you could search for them?"+BS+""+BS+
   "Besides, there is a book here. After 'copy book', you could take one."+BS;
dest_dir = ({
   "/players/hippo/rooms/ratrium.c","heart",
   "/players/hippo/rooms/liver2.c","cancer",
   "/players/hippo/rooms/pancreas.c","pancreas",
	});
}
}
init() {
	::init();
   add_action("search","search");
   add_action("appropriate","appropriate");
   add_action("do_copy","copy");
	}
search(){
   write("You see a lot of heals all over, and somehow, you see a price"+BS+
   "above all of them. You wonder why you should pay, but you suppose"+BS+
   "that you just have to..."+BS+
   "You see the following heals, laying around:"+BS+
""+BS+
"enzymes : 420 "+BS+
"     cp : 420 "+BS+
"    amp : 200 "+BS+
"    adp : 400 "+BS+
"    atp : 3000"+BS+
"  blood : 1750"+BS+
   ""+BS+
   "You could appropriate these items to yourself."+BS);
return 1;
}
appropriate(str){
object item;
string name;
int value, cost;
if (str == "blood" || str == "Ten drops of blood"){
   name = str;
   item = clone_object("/players/hippo/heals/blood.c");
   value = 1750;
}
else if (str == "atp" || str == "Some atp"){
   name = str;
   item = clone_object("/players/hippo/heals/atp.c");
   value = 3000;
}
else if (str == "adp" || str == "Some adp"){
   name = str;
   item = clone_object("/players/hippo/heals/adp.c");
   value = 400;
}
else if (str == "amp" || str == "Some amp"){
   name = str;
   item = clone_object("/players/hippo/heals/amp.c");
   value = 200;
}
else if (str == "enzymes" || str == "A copple of enzymes"){
   name = str;
   item = clone_object("/players/hippo/heals/enzymes");
   value = 420;
}
else if (str == "cp" || str == "A creatine phosphaat"){
   name = str;
   item = clone_object("/players/hippo/heals/cp.c");
   value = 420;
} else { write("What are you trying to appropriate??"+BS); return 1;}
if (call_other(this_player(), "query_money", 0) < value) {
	write("That costs " + value + " gold coins, which you don't have.\n");
	destruct(item); return 1;
	}

if (!call_other(this_player(), "add_weight", 1)){
	write("You can't carry that much!\n"); 
	destruct(item); return 1;
	}
move_object(item,this_player());
call_other(this_player(), "add_money", - value);
write("You get a " + name + " and you feel " + value + " gold coins are withdrawn from your pocket"+BS);
say(call_other(this_player(), "query_name", 0) + " buys a " + name + ".\n");
return 1;
}
do_copy(arg) {
   if (!arg=="book") {
      write("You can only copy a book, man!"+BS);
      return 0; 
   }
   write("You make a copy of the book. Now you can get yourself one."+BS);
   move_object(clone_object("/players/hippo/objects/light_map.c"),this_object());
   return 1;
}
