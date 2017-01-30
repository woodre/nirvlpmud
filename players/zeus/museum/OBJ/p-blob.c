inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
string *x;
object cc;  int y,z;
reset(arg){
 if(arg) return;

x = allocate(8);

x[0]="King Boul-Goruk laughs heartily.\n";
x[1]="King Boul-Goruk grins at you.\n";
x[2]="King Boul-Goruk waves his mace through the air.\n";
x[3]="King Boul-Goruk says, \"I was the supreme ruler of Aystaine.\"\n";
x[4]="King Boul-Goruk says, \"All should kneel before me.\"\n";
x[5]="King Boul-Goruk looks around the room.\n";
x[6]="King Boul-Goruk makes a low rumbling noise that fills the room.\n";
x[7]="King Boul-Goruk laughs as he glares off into space.\n";

  set_short("A holographic projection of King Boul-Goruk");
  set_long(
"This is a life size holographic projection of King Boul-Goruk of Aystaine.\n"+
"It is a gigantic blob of dark green matter.  He is about eight feet tall,\n"+
"six feet wide and six feet long.  He has two large white eyes, a barely\n"+
"visible nose and a gigantic mouth.  A decorative cloak is tied around his\n"+
"thick neck, and in his right hand is a unique looking mace.\n");
  set_value(0);
  set_weight(1000);
  z = 0;
}

get(){  return 0;  }
id(str){ return str == "projection" || str == "king" ||
str == "boul-goruk" || str == "blob"; }
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
