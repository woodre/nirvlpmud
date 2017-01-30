#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define rate 6
#define USER this_player()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()
#define Hunter "/players/maledicta/town/mobs/hunter2.c"
inherit "room/room";

int cost,heal_for;
string type;
string mess;

reset(arg) {
/* Adding back in for now - Rumplemintz */
if(!find_object(Hunter)){
 move_object(Hunter, this_object());
 }		
/* */
if(!present("bar_owner", this_object())){
move_object(clone_object("/players/maledicta/town/mobs/bartender.c"), this_object());
}		
  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+" [restaurant]";
long_desc =
"  This is a small comfortable restaurant. Lining the walls and spaced around\n"+
"the room are several tables and booths. Lights hang from the ceiling, giving\n"+
"off a soft glow. A large bar can be seen near the back of the building, a few\n"+
"wooden stools sitting before it. You notice a door leading out the back of\n"+
"the bar. A large sign hangs on the wall near the entry showing the restaurants\n"+
"specials.\n";

items = ({
  "walls",
  "They are decorated with pleasant wallpaper and polished wood",
  "tables",
  "Large tables made of wood and polished to a fine finish. They are very clean",
  "booths",
  "Set against the walls, they are well padded and comfortable",
  "lights",
  "You look closely and see that the lights are covered with a yellowish tinted\n"+
  "glass so as to soften the light",
  "bar",
  "A long wooden bar. It has been polished so as to almost show your reflection\n"+
  "in its surface",
  "stools",
  "Tall stools that are covered with a comfortable red padding",
  "sign",
  "Perhaps you should try reading it?",
  
});

dest_dir = ({
  "/players/maledicta/town/rooms/t7.c","out",
  "/players/vital/dest/spaceport/rooms/backalley.c", "backdoor"
});

}

init(){
  ::init();
  add_action("read_it", "read");
  add_action("order_item", "order");
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	
  

read_it(string str){
	if(!str){ write("Read what?\n"); return 1; }
	  if(str = "sign"){
  	write("      The sign reads.....\n\n");
  	write(
"\t "+BLU+"************************************************\n"+
"\t **"+HIB+"********************************************"+NORM+""+BLU+"**\n"+
"\t **"+HIB+"*                                          *"+NORM+""+BLU+"**\n"+
"\t **"+HIB+"*     Welcome to the Careful Wanderer      *"+NORM+""+BLU+"**\n"+ 
"\t **"+HIB+"*                                          *"+NORM+""+BLU+"**\n"+
"\t **"+HIB+"*  "+HIB+"Beer..........................50 coins  *"+NORM+""+BLU+"**\n"+
"\t **"+HIB+"*  "+HIB+"Wine.........................250 coins  *"+NORM+""+BLU+"**\n"+
"\t **"+HIB+"*  "+HIB+"Finewine.....................500 coins  *"+NORM+""+BLU+"**\n"+
"\t **"+HIB+"*  --------------------------------------  *"+NORM+""+BLU+"**\n"+
"\t **"+HIB+"*  "+HIB+"Water.........................50 coins  *"+NORM+""+BLU+"**\n"+
"\t **"+HIB+"*  "+HIB+"Lemonade.....................250 coins  *"+NORM+""+BLU+"**\n"+
"\t **"+HIB+"*  "+HIB+"Cola.........................500 coins  *"+NORM+""+BLU+"**\n"+
"\t **"+HIB+"*  --------------------------------------  *"+NORM+""+BLU+"**\n"+
"\t "+NORM+""+BLU+"**"+HIB+"*  "+HIB+"Salad.........................50 coins  *"+NORM+""+BLU+"**\n"+
"\t **"+HIB+"*  "+HIB+"Hamburger....................250 coins  *"+NORM+""+BLU+"**\n"+
"\t **"+HIB+"*  "+HIB+"Steak........................500 coins  *"+NORM+""+BLU+"**\n"+
"\t **"+HIB+"*                                          *"+NORM+""+BLU+"**\n"+
"\t **"+HIB+"********************************************"+NORM+""+BLU+"**\n"+
"\t ************************************************"+NORM+"\n"+
"\t You may '"+HIM+"order"+NORM+"' any item listed.                \n");
  	return 1;
        }
  return;
  }
order_item(string str){
if(!present("bar_owner", this_object())){
write("You don't see anyone here that can serve you!\n");
return 1;
}		
   if(!str){ 
   	write("The waiter says: I'm sorry, order what?\n");
   	return 1;
      }
else if(str == "beer" || str == "Beer"){
     	cost = 50;
     	type = "drink_alcohol";
     	heal_for = 5;
     	}
else if(str == "wine" || str ==  "Wine"){
     	cost = 250;
     	type = "drink_alcohol";
     	heal_for = 15+random(20);
     	}
else if(str == "finewine" || str ==  "Finewine"){
     	cost = 500;
     	type = "drink_alcohol";
     	heal_for = 40+random(20);
     	}
else if(str == "water" || str ==  "Water"){
     	cost = 50;
     	type = "drink_soft";
     	heal_for = 5;
     	}
else if(str == "lemonade" || str ==  "Lemonade" || str == "ade"){
     	cost = 250;
     	type = "drink_soft";
     	heal_for = 15+random(20);
     	}
else if(str == "cola" || str ==  "Cola"){
     	cost = 500;
     	type = "drink_soft";
     	heal_for = 40+random(20);
     	}
else if(str == "salad" || str ==  "Salad"){
     	cost = 50;
     	type = "eat_food";
     	heal_for = 5;
     	}
else if(str == "hamburger" || str ==  "burger" || str == "Hamburger"){
     	cost = 250;
     	type = "eat_food";
     	heal_for = 15+random(20);
     	}
else if(str == "steak" || str == "Steak"){
	cost = 500;
	type = "eat_food";
	heal_for = 40+random(20);
        }
else{ 
	write("The waiter says: I'm sorry, but we do not have that.\n");
	return 1;
	}
if(this_player()->query_money() < cost){
	write(
"The waiter looks at you slightly embarrased and says,\n"+
"                               'I'm sorry, but that isn't enough money.'\n");
	return 1;
	}
if (!call_other(this_player(), type, rate)) {
	write(
"The waiter says: I'm sorry but you don't look like you can handle a "+str+".\n");
	say(
this_player()->query_name()+" whispers something to the waiter.\n"+
"The waiter shakes his head and smiles sadly.\n");  
return 1;
      }

if(type == "drink_soft" || type =="drink_alcohol")
	mess = "drink";

else mess = "eat";

write(
"You order a "+HIM+""+capitalize(str)+""+NORM+".\n"+
"You quickly "+mess+" it and think to yourself, 'That was very good!'.\n");
call_other(this_player(), "heal_self", heal_for);
write(
"     -=[HP "+HIB+""+HP+""+NORM+"/"+HIB+""+MHP+""+NORM+"]=-"+
"     -=[SP "+HIB+""+SP+""+NORM+"/"+HIB+""+MSP+""+NORM+"]=-\n");

say(
this_player()->query_name()+" quickly "+mess+"'s a "+str+".\n");
    call_other(this_player(), "add_money", - cost);
    
write("You have "+this_player()->query_money()+" coins left.\n");
    return 1;
    }
     				
