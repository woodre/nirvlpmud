#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define rate 6
#define USER tp
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()
#include "/players/jaraxle/ansi.h"
inherit "room/room";


int cost,heal_for;
string type;
string mess;
string name_it;
object owner;
reset(arg) {
if(!present("bar_maid")){
	owner = clone_object("/players/jaraxle/templar/mobs/bar_maid.c");
	move_object(owner, this_object());
	}
  if(arg) return;
set_light(1);

short_desc = "FeastHall "+HIW+"["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
"  You stand within a beautiful banquet hall.  Long tables extend the\n"+
"length of the room, each covered in fine cloth and candles. A stone\n"+
"fireplace can be found on both sides of the room, their fires providing\n"+
"a nice warmth to the room. A small sign indicates what is being served\n"+
"this day.\n";

items = ({
"tables",
"Wooden tables that extend out to the farthest reaches of the room. You\n"+
"estimate that every knight in the castle could easily sit at these\n"+
"tables, with extra room to spare",
"cloth",
"A fine spread that covers the tables",
"candles",
"Long white candles placed into steel settings",
"fireplace",
"A large stone fireplace that gives off a warm feeling",
"sign",
"You should try reading it.",
});

dest_dir = ({
  "/players/jaraxle/templar/rooms/hallway1","west",
});

}

init(){
    ::init();
   add_action("read_it", "read");
   add_action("order_it","order");
     this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }



read_it(){
write(
"The sign reads...\n\n"+
"   Welcome Knights, today we have available:\n\n"+
"      @@@@@@@@@@@@@@@@@@@@+@@@@@@@@@@@@@@@@@@@@\n"+
"      @                                       @\n"+ 
"      @  [1]  Beer........................50  @\n"+   
"      @  [2]  Wine.......................250  @\n"+
"      @  [3]  Fine Wine..................500  @\n"+
"      @                 ~:o:~                 @\n"+
"      @  [4]  Bread [slice]...............50  @\n"+
"      +  [5]  Bread [loaf]...............250  +\n"+
"      @  [6]  Pie........................500  @\n"+
"      @                 ~:o:~                 @\n"+
"      @  [7]  Meatpie.....................50  @\n"+
"      @  [8]  Ham........................250  @\n"+
"      @  [9]  Steak......................500  @\n"+
"      @                                       @\n"+
"      @@@@@@@@@@@@@@@@@@@@+@@@@@@@@@@@@@@@@@@@@\n"+
"\n\nYou may 'order #'\n");
  return 1;
}


order_it(string str){
	if(!present("KnightInvite", this_player())){
		write("Only knights are served here!\n");
		return 1;
	}
if(!present("bar_maid", this_object())){
write("You don't see anyone here that can serve you!\n");
return 1;
}		
   if(!str){ 
   	write("The server says: I'm sorry, order what?\n");
   	return 1;
      }
else if(str == "1"){
     	cost = 50;
     	name_it = "beer";
     	type = "drink_alcohol";
     	heal_for = 5;
     	}
else if(str == "2"){
     	cost = 250;
     	name_it = "wine";
     	type = "drink_alcohol";
     	heal_for = 15+random(20);
     	}
else if(str == "3"){
     	cost = 500;
     	name_it = "fine wine";
     	type = "drink_alcohol";
     	heal_for = 40+random(20);
     	}
else if(str == "4"){
     	cost = 50;
     	name_it = "slice of bread";
     	type = "drink_soft";
     	heal_for = 5;
     	}
else if(str == "5"){
     	cost = 250;
     	name_it = "loaf of bread";
     	type = "drink_soft";
     	heal_for = 15+random(20);
     	}
else if(str == "6"){
     	cost = 500;
     	name_it = "steaming pie";
     	type = "drink_soft";
     	heal_for = 40+random(20);
     	}
else if(str == "7"){
     	cost = 50;
     	name_it = "meatpie";
     	type = "eat_food";
     	heal_for = 5;
     	}
else if(str == "8"){
     	cost = 250;
     	name_it = "thick slice of ham";
     	type = "eat_food";
     	heal_for = 15+random(20);
     	}
else if(str == "9"){
	cost = 500;
	name_it = "large juicy steak";
	type = "eat_food";
	heal_for = 40+random(20);
        }
else{ 
	write("The server says: I'm sorry, but we do not have that.\n");
	return 1;
	}
if(this_player()->query_money() < cost){
	write(
"The server looks at you slightly embarrased and says,\n"+
"                   'I'm sorry good sir, but that isn't enough money.'\n");
	return 1;
	}
if (!call_other(this_player(), type, rate)) {
	write(
"The server says: I'm sorry but you don't look like you can handle a "+str+".\n");
	say(
this_player()->query_name()+" whispers something to the waiter.\n"+
"The server shakes her head and smiles sadly.\n");  
return 1;
      }

if(type == "drink_soft" || type =="drink_alcohol")
	mess = "drink";

else mess = "eat";

write(
"You order a "+capitalize(name_it)+".\n"+
"You quickly "+mess+" it and think to yourself, 'That was very good!'.\n");

write(
"     -=[HP "+HIG+""+HP+""+NORM+"/"+HIG+""+MHP+""+NORM+"]=-"+
"     -=[SP "+HIG+""+SP+""+NORM+"/"+HIG+""+MSP+""+NORM+"]=-\n");

say(
this_player()->query_name()+" quickly "+mess+"'s a "+str+".\n");
    call_other(this_player(), "add_money", - cost);
    call_other(this_player(), "heal_self", heal_for);
write("You have "+this_player()->query_money()+" coins left.\n");
    return 1;
    }
     				
