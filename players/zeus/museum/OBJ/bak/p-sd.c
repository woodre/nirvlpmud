inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
string *x;
object cc;  int y, z;
reset(arg){
 if(arg) return;

x = allocate(10);
x[0]="The Smasher/Devourer says:  Fear me not but fear my hell.\n";
x[1]="The Smasher/Devourer says:  Man made me so I could kill.\n";
x[2]="The Smasher/Devourer says:  Praise me in the name of war.\n";
x[3]="The Smasher/Devourer says:  I destroy both rich and poor.\n";
x[4]="The Smasher/Devourer says:  I am the way, prepare for salvation.\n";
x[5]="The Smasher/Devourer says:  Strength in time of suffering.\n";
x[6]="The Smasher/Devourer says:  Man alone is a weakling.\n";
x[7]="The Smasher/Devourer says:  Ascension is what you ask.\n";
x[8]="The Smasher/Devourer says:  I will be the fall of man.\n";
x[9]="The Smasher/Devourer says:  I am the way, prepare for salvation.\n";

  set_short("A holographic projection of a Smasher/Devourer module");
  set_long(
"This is a holographic projection of a Smasher/Devourer module.  It was\n"+
"created by Humans to be one of the deadliest machines ever built.  It\n"+
"is of a bi-pedal design with an egg-shaped, armored mainframe.  What\n"+
"appear to be arms are actually weapons.\n");
  set_value(0);
  set_weight(1000);
  z = 0;
}

get(){  return 0;  }
id(str){ return str == "projection" || str == "smasher/devourer"; }
void init(){ ::init();  if(!z){ call_out("chatter", 12); z=1; }  }

chatter(){ 
	if(!environment()) return;
	cc = all_inventory(environment(this_object()));
	for(y=0; y < sizeof(cc); y++){
		if(z && cc[y]->is_player()){
			TR(environment(), x[random(10)]); 
			call_out("chatter", 14);
			break;
		}
		else z = 0;
	}
}
