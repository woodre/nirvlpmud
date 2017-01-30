inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
string *x;
object cc;  int y,z;
reset(arg){
 if(arg) return;

x = allocate(8);
x[0]="Tolbrehn kicks the air.\n";
x[1]="Tolbrehn spin kicks the air.\n";
x[2]="Tolbrehn stands perfectly still.\n";
x[3]="Tolbrehn says:  Hello there.\n";
x[4]="Tolbrehn smiles at you.\n";
x[5]="Tolbrehn walks in a circle.\n";
x[6]="Tolbrehn crosses his arms.\n";
x[7]="Tolbrehn chops at the air.\n";

  set_short("A holographic projection of Tolbrehn");
  set_long(
"This is a life size holographic projection of Tolbrehn the Shadowninja\n"+
"Master.  He is a very handsome young man, wearing a black and grey ninja\n"+
"suit.  His black face is painted with white and gray stripes.  Two black\n"+
"gloves adorn his hands, a trademark of the Shadowninja clan members.\n");
  set_value(0);
  set_weight(1000);
  z = 0;
}

get(){  return 0;  }
id(str){ return str == "projection" || str == "tolbrehn"; }
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
