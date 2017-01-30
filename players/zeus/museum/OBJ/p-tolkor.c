inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
string *x;
object cc;  int y,z;
reset(arg){
 if(arg) return;

x = allocate(8);
x[0]="Tol'kor swings his axe.\n";
x[1]="Tol'kor looks picture perfect.\n";
x[2]="Tol'kor grins evily.\n";
x[3]="Tol'kor says:  Hello there.\n";
x[4]="Tol'kor smiles at you.\n";
x[5]="Tol'kor walks in place.\n";
x[6]="Tol'kor raises his axe over his head.\n";
x[7]="Tol'kor says: Welcome to the museum.\n";

  set_short("A holographic projection of Tol'kor");
  set_long(
"This is a life size holographic projection of the Ogre Warrior Tol'kor.\n"+
"It is being projected by a small electronic chip on the floor.  The\n"+
"projection moves with the actual body movements of the original Tol'kor.\n"+
"He is holding his mighty axe across his body, and looks very fearsome.\n");
  set_value(0);
  set_weight(1000);
  z = 0;
}

get(){  return 0;  }
id(str){ return str == "projection" || str == "tol'kor"; }
void init(){ ::init();  if(!z){ call_out("chatter", 12); z=1; }  }

chatter(){ 
	if(!environment()) return;
	cc = all_inventory(environment(this_object()));
	for(y=0; y < sizeof(cc); y++){
		if(z && cc[y]->is_player()){
			TR(environment(), x[random(8)]); 
			call_out("chatter", 14);
			break;
		}
		else z = 0;
	}
}
