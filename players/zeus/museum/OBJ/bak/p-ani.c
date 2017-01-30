inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
string *x;
object cc;  int y,z;

reset(arg){
 if(arg) return;

x = allocate(9);
x[0] = "Ani smiles happily.\n";
x[1] = "Ani says: Hello there.\n";
x[2] = "You see a twinkle in Ani's eye.\n";
x[3] = "Ani stands tall and bows to you.\n";
x[4] = "Ani looks off in the distance.\n";
x[5] = "Ani suddenly stand alert.\n";
x[6] = "Ani says: Welcome to the museum.\n";
x[7] = "Ani flips into the air gracefully.\n";
x[8] = "Looking at Ani, you can't help but smile.\n";

  set_short("A holographic projection of Ani");
  set_long(
"Standing before you is a life size holographic projection of Ani,\n"+
"one of the most powerful people ever.  She has short auburn hair\n"+
"with blonde highlights, and is wearing a black outfit.  Her face\n"+
"is a picture of determination and strength.  She moves with such\n"+
"grace and beauty that you find yourself smiling uncontrollably.\n");
  set_value(0);
  set_weight(1000);
  z = 0;
}

get(){  return 0;  }
id(str){ return str == "projection" || str == "ani"; }
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
