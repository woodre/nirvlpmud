/*   Bar Area-  Maledicta [01.06.01] */

#include "../define.h"
inherit ROOM;

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define rate 6
#define USER this_player()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int cost,heal_for;
string type;
string mess;

reset(arg) {
if(!present("patron", this_object())){
   MO(CO("/players/maledicta/ares/mobs/bpatron"), this_object());
   MO(CO("/players/maledicta/ares/mobs/bpatron"), this_object());
  if(!random(3)) MO(CO("/players/maledicta/ares/mobs/bpatron"), this_object());
   }
   if(arg) return;
   set_short("The Dangerous Blade [Bar]");
   set_light(1);
   set_long(
"   You stand before the bar of the Dangerous Blade. A small sign is\n"+
"crudely scratched into a board that hangs on the wall. To the west\n"+
"is a large stone fireplace and to the north is the entryway of the\n"+
"bar. There are several tables nearby with chairs around them.\n");
   add_item(
      "tables",
      "Large wooden tables that are crudely crafted and are probably\n"+
      "deemed of 'throwaway' quality");
   add_item(
      "chairs",
      "Simple wooden benches that are made of poor quality wood. Most\n"+
      "of them look as though they have been put together hurriedly and\n"+
      "are designed to be thrown away");
   add_item(
      "bar",
      "This is a large wooden bar that spans the entire width of the\n"+
      "room. Upon closer look you can see that it has been beat up and\n"+
      "bashed a lot");
   add_item(
      "sign",
      "A large sign that you can read");
   add_item(
      "fireplace",
      "A large stone fireplace that has a small fire burning in it. It\n"+
      "seems to give off a light smoke that fills the room\n");
   add_item(
      "ceiling",
      "The ceiling is made of large wooden beams and is very low");
   add_item(
      "air",
      "A thick odorous air that makes you want to crawl on the floor to\n"+
      "avoid its pungent sickness");
   add_item(
      "wall", 
      "The wall here has a sign hanging on it and is made of crude boards");
   add_exit(ROOMS+"bar1","north");
   add_exit(ROOMS+"bar5","west");
   add_exit(ROOMS+"bar6","east");

   set_chance(8);
   add_msg("You hear the sounds of people chatting at the tables.");
   add_msg("You hear the sounds of people chatting at the tables.");
   add_msg("The sound of breaking glass can be heard nearby.");
   add_msg("The bartender looks at you and shrugs.");
   add_msg("The bartender slides an ale over to a patron.");
   add_msg("The bartender half cleans a glass and then sits it down.");
   add_msg("The bartender slams his fist down on a roach and brushes it off the bar.");
   add_msg("The bartender looks at an infected wound on his palm.");
   add_msg("The sounds of an argument can be heard somewhere in a corner.");
   add_msg("A customer enters and moves past you to the bar.");
   add_msg("A customer shoves past you and exits the bar.");
   }



init(){
  ::init();
  add_action("read_it", "read");
  add_action("order_item", "order");
  }

read_it(string str){
	if(!str){ write("Read what?\n"); return 1; }
	  if(str = "sign"){
  	write("      The sign reads.....\n\n");
  	write(
"\t "+RED+"************************************************\n"+
"\t **"+HIR+"********************************************"+NORM+""+RED+"**\n"+
"\t **"+HIR+"*                                          *"+NORM+""+RED+"**\n"+
"\t **"+HIR+"*             "+BOLD+"The Dangerous Blade          *"+NORM+""+RED+"**\n"+ 
"\t **"+HIR+"*                                          *"+NORM+""+RED+"**\n"+
"\t **"+HIR+"*  "+NORM+"Ale..........................250 coins  "+HIR+"*"+NORM+""+RED+"**\n"+
"\t **"+HIR+"*  "+NORM+"Whiskey......................500 coins  "+HIR+"*"+NORM+""+RED+"**\n"+
"\t **"+HIR+"*  --------------------------------------  *"+NORM+""+RED+"**\n"+
"\t **"+HIR+"*  "+NORM+"Bread........................250 coins  "+HIR+"*"+NORM+""+RED+"**\n"+
"\t **"+HIR+"*                                          *"+NORM+""+RED+"**\n"+
"\t **"+HIR+"********************************************"+NORM+""+RED+"**\n"+
"\t ************************************************"+NORM+"\n"+
"\t You may '"+HIY+"order"+NORM+"' any item listed.                \n");
  	return 1;
        }
  return;
  }
order_item(string str){
   if(!str){ 
   	write("The waiter says: I'm sorry, order what?\n");
   	return 1;
      }
else if(str == "ale" || str ==  "Ale"){
     	cost = 250;
     	type = "drink_alcohol";
     	heal_for = 15+random(20);
     	}
else if(str == "whiskey" || str ==  "Whiskey"){
     	cost = 500;
     	type = "drink_alcohol";
     	heal_for = 40+random(20);
     	}
else if(str == "bread" || str ==  "Bread"){
     	cost = 250;
     	type = "eat_food";
     	heal_for = 15+random(20);
     	}
else{ 
	write("The Bartender looks at you and makes a silent prayer to Darna that you die.\n");
	return 1;
	}
if(this_player()->query_money() < cost){
	write(
"The Bartender snarls, 'You don't have enough coins!'\n");
	return 1;
	}
if (!call_other(this_player(), type, rate)) {
	write(
"You don't think you should.\n");	
return 1;
      }

if(type == "drink_soft" || type =="drink_alcohol")
	mess = "drink";

else mess = "eat";

write(
"You order a "+HIM+""+capitalize(str)+""+NORM+".\n"+
"You quickly "+mess+" it and flinch. You try not to wretch.\n");
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
     				

