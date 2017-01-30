inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
string *x;
object cc;  int y,z;
reset(arg){
 if(arg) return;

x = allocate(9);
x[0] = "Jerek slashes the air in front of him.\n";
x[1] = "Jerek looks picture perfect.\n";
x[2] = "Jerek grins evily.\n";
x[3] = "Jerek says:  Hello there.\n";
x[4] = "Jerek smiles at you.\n";
x[5] = "Jerek walks in place.\n";
x[6] = "Jerek says: Freedom is priceless.\n";
x[7] = "Jerek says: Never lower your guard.\n";
x[8] = "Jerek jumps into the air and slashes the air with two hands.\n";

  set_short("A holographic projection of Jerek");
  set_long(
"You are looking at a life size holographic projection of the Mutant\n"+
"Jerek being projected by a small electronic chip on the floor.  The\n"+
"projection is moving in place fluidly.  His hands are adorned with very\n"+
"deadly looking claws, and plates of metal are visible beneath his skin.\n");
  set_value(0);
  set_weight(1000);
  z=0;
}

get(){  return 0;  }
id(str){ return str == "projection" || str == "jerek"; }
void init(){ ::init();  if(!z){ call_out("chatter", 12); z=1; }  }

chatter(){ 
	if(!environment()) return;
	cc = all_inventory(environment(this_object()));
	for(y=0; y < sizeof(cc); y++){
		if(z && cc[y]->is_player()){
			TR(environment(), x[random(9)]); 
			call_out("chatter", 14);
			break;
		}
		else z = 0;
	}
}