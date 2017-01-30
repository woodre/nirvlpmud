inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
string *x;
object cc;  int y,z;
reset(arg){
 if(arg) return;

x = allocate(6);
x[0]="A bug flies by your face.\n";
x[1]="Bugs fly all about the room.\n";
x[2]="A tiny bug lands on you, then flies away.\n";
x[3]="The bugs fly all about the room.\n";
x[4]="The bug storm seems to writhe with bugs.\n";
x[5]="You notice bugs clinging to the walls.\n";

  set_short("A holographic projection of the Bug Storm");
  set_long(
"What you are looking at is a projection of hundreds of thousands of\n"+
"tiny black bugs.  They are flying about the room at incredibly fast\n"+
"speeds.  In the center of the room a large mass of the bugs are\n"+
"clinging onto one another.  At the center of the bugs lies the\n"+
"central consciousness of the storm, which controls each and every\n"+
"one as though it was just another limb.\n"); 
  set_value(0);
  set_weight(1000);
  z=0;
}

get(){  return 0;  }
id(str){ return str == "projection" || str == "storm" ||
str == "bugs" || str == "bug" || str == "bug storm"; }
void init(){ ::init();  if(!z){ call_out("chatter", 12); z=1; }  }

chatter(){ 
	if(!environment()) return;
	cc = all_inventory(environment(this_object()));
	for(y=0; y < sizeof(cc); y++){
		if(z && cc[y]->is_player()){
			TR(environment(), x[random(6)]); 
			call_out("chatter", 14);
			break;
		}
		else z = 0;
	}
}
