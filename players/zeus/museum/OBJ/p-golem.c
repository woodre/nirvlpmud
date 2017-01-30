inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
string *x;
object cc;  int y,z;
reset(arg){
 if(arg) return;

x = allocate(9);
x[0]="The golem stands silently.\n";
x[1]="The golem watches you.\n";
x[2]="The golem looks at you.\n";
x[3]="The golems eyes flash with fire.\n";
x[4]="The golems eyes burn with a passion.\n";
x[5]="The golem stands waiting.\n";
x[6]="The three golems glare at you simultaneously.\n";
x[7]="The golem says: Welcome to the museum.\n";
x[8]="The golem comicly smacks one of the smaller golems.\n";

  set_short("A holographic projection of three Granite Golems");
  set_long(
"This is a holographic projection of three granite golems.  The one in\n"+
"the center is a towering beast, with a very muscular appearance.  The\n"+
"two smaller golems stand to each side of it, only reaching up to its\n"+
"knees.  All three of the golems eyes burns with a fire of pure evil.\n");
  set_value(0);
  set_weight(1000);
  z = 0;
}

get(){  return 0;  }
id(str){ return str == "projection" || str == "golem" ||
str == "golems" || str == "granite golems"; }
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
