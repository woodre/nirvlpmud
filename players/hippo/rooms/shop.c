#include "/players/hippo/bs.h"
inherit "room/room";
object sign;
reset(arg){
if (!arg) {
	set_light(1);
short_desc="The liver";
long_desc="You are in the liver. You remember your biology teacher told you"+BS+
   "the liver is the place where the body removes stuff it does not"+BS+
   "want to have in the blood, and where the 'heals' are stored."+BS+
   "You wander if in this place, you could find some heals. "+BS+
   "Maybe you could search for them?"+BS;
dest_dir = ({
   "/players/hippo/rooms/heart.c","heart",
   "/players/hippo/workroom.c","out",
	});
}
}
init() {
	::init();
   add_action("search","search");
   add_action("appropriate","appropriate");
	}
search(){
   write("You see a lot of heals all over, and somehow, you see a price"+BS+
   "above all of them. You wander why you should pay, but you suppose"+BS+
   "that you just have to..."+BS+
   "You see the following heals, laying around:"+BS+
   "amp"+BS+
   "adp"+BS+
   "atp"+BS+
   "blood"+BS+
   "enzymes"+BS+
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
   value = 4300 + random(1000);
/*
}
else if (str == "atp" || str == "Some atp"){
   name = str;
   item = clone_object("/players/hippo/heals/atp.c");
   value = 2850 + random(300);
}
else if (str == "adp" || str == "Some adp"){
   name = str;
   item = clone_object("/players/hippo/heals/adp.c");
   value = 1900 + random(200);
}
else if (str == "amp" || str == "Some amp"){
   name = str;
   item = clone_object("/players/hippo/heals/amp.c");
   value = 950 + random(100);
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
*/
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
