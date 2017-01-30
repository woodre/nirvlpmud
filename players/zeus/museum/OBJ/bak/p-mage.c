inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
string *x;
object cc;  int y,z;
reset(arg){
 if(arg) return;

x = allocate(9);
x[0]="Heldurabhoricka waves her hands in the air.\n";
x[1]="Heldurabhoricka smiles at you.\n";
x[2]="Heldurabhoricka stands tall, looking past you.\n";
x[3]="Heldurabhoricka says:  Hello there.\n";
x[4]="Heldurabhoricka puts her hands together... they begin to glow.\n";
x[5]="Heldurabhoricka walks in a circle.\n";
x[6]="Heldurabhoricka looks as though wind is blowing against her.\n";
x[7]="Heldurabhoricka prays silently.\n";
x[8]="Huldurabhoricka conjures up a ball of ice.\n";

  set_short("A holographic projection of Heldurabhoricka");
  set_long(
"This is a life size holographic projection of Heldurabhoricka.  She\n"+
"is wearing a long red robe with a black lining that reaches all the\n"+
"way down past her feet.  She is holding a book of spells proudly.\n"+
"She has a delicate face, and looks rather young, her auburn hair flowing\n"+
"over her shoulders.  She is a beautiful sight.\n");
  set_value(0);
  set_weight(1000);
  z=0;
}

get(){  return 0;  }
id(str){ return str == "projection" || str == "heldurabhoricka"; }
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
