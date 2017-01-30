#include "/players/maledicta/ansi.h"
#define ALLY "players/boltar/templar/daemon/Ally.c"
#define TP this_player()

short(){ return BOLD+"The Viewing Crystal"+NORM; }

query_value(){ return 0; }
query_weight(){ return 2000; }

id(str){ return str == "crystal" || str == "viewing_crystal"; }

long(){
write(
"This is the viewing crystal of the Alliance.  With this\n"+
"magical item an alliance member can view the area around\n"+
"a knight or alliance member.  To use it simply, 'view'\n"+
"the knight or alliance member.\n");
}

init() {
  object cross;
  cross = present("KnightInvite", this_player());
  if(cross){
    add_action("viewer","view");
  }
}


viewer(str){
int max;
object ob;
object whoda;
if(!str){
  write("View who?\n");
  return 1;
  }

whoda = find_living(str);

if(!whoda){
  write("The crystal is unable to find that person.\n");
  return 1;
  }
if(whoda->query_level() > 19){
  write("You cannot view wizards!\n");
  return 1;
  }
if(!present("KnightInvite", whoda)){
      write("You cannot focus on someone outside of the Templar order or\n"+
            "a non-alliance member.\n");
      return 1;
  }

write(WHT+"You focus the magic of the crystal...\n"+
"An image of "+capitalize(str)+" sprouts up onto the wall:"+NORM+"\n");
write(
HIY+"=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="+NORM+"\n");
call_other(environment(whoda), "long");
ob = first_inventory(environment(whoda));
	max = 15;
	while(ob && max > 0) {
	    if (ob != this_object()) {
		string short_str;
		short_str = call_other(ob, "short");
		if (short_str) {
		    max -= 1;
                write(short_str + ". \n");
            }
	    }
	    ob = next_inventory(ob);
	}
if(whoda->query_attack()){
write(capitalize(str)+" is "+HIR+"FIGHTING!"+NORM+"\n");
}
write(
HIY+"=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="+NORM+"\n");
return 1;
}
