inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
string *x;
object cc;  int y,z;
reset(arg){
 if(arg) return;

x = allocate(7);
x[0] = "The light glows brightly.\n";
x[1] = "The light shimmers brightly.\n";
x[2] = "The spikes of light shrink and grow.\n";
x[3] = "You can't look directly at the enchanted light.\n";
x[4] = "The light pulses as it moves.\n";
x[5] = "The light fluctuates fluidly.\n";
x[6] = "Beams of light explode from the light.\n";

  set_short("A holographic projection of Enchanted Light");
  set_long(
"This is a projection of enchanted light.  It is constantly moving,\n"+
"beams of light exploding outwards.  You are unable to look directly\n"+
"into the light, which is very spiky, not smooth.  It doesn't appear\n"+
"to have any discernable features.  It is an incredibly powerful\n"+
"creature, a bond between dark magic and pure energy.\n");
  set_value(0);
  set_weight(1000);
  z=0;
}

get(){  return 0;  }
id(str){ return str == "projection" || str == "light" ||
str == "enchanted light"; }
void init(){ ::init();  if(!z){ call_out("chatter", 12); z=1; }  }

chatter(){ 
	if(!environment()) return;
	cc = all_inventory(environment(this_object()));
	for(y=0; y < sizeof(cc); y++){
		if(z && cc[y]->is_player()){
			TR(environment(), x[random(7)]); 
			call_out("chatter", 14);
			break;
		}
		else z = 0;
	}
}
