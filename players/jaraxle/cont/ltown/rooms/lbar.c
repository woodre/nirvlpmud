#include "/players/jaraxle/ansi.h"



#define tp this_player()

#define tpn this_player()->query_name()

#define tpp this_player()->query_possessive()

#define rate 6

#define USER this_player()

#define HP   USER->query_hp()

#define MHP  USER->query_mhp()

#define SP   USER->query_sp()

#define MSP  USER->query_msp()

inherit "room/room";



int cost,heal_for;

string type;

string mess;

object guard;

reset(arg) {

	if(!present("cont_lizardguard", this_object())){

guard = clone_object("/players/jaraxle/cont/ltown/mobs/lguard.c");

	move_object(guard, this_object());

}

if(!present("bar_owner", this_object())){

move_object(clone_object("/players/jaraxle/cont/ltown/mobs/lbartender.c"), this_object());

}		

  if(arg) return;

set_light(1);



short_desc = "Third Earth ["+HIG+"The Lizards Bite"+NORM+" (bar) ]";

long_desc =

"  This is a small rundown building made of wood and filled in\n"+

"with mud. A long counter can be found towards the back of the\n"+

"bar, and a sign hangs behind it. There are several tables and\n"+

"chairs lining the walls. A door leads out to the main road.\n";



items = ({

  "counter",

  "A long counter made of a polished wood. It has seen better days",

  "sign",

  "A large sign that has the specials for today. You can 'read'\n"+

  "it",

  "tables",

  "Numerous tables made of wood",

  "chairs",

  "Several chairs that are made of wood and look rundown",

  "door",

  "A wooden door with a few holes in it. The wind whistles through\n"+

  "it leaving a draft in the room",

  

});



dest_dir = ({

  "/players/jaraxle/cont/ltown/rooms/l1.c","out",

  

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

"\t "+HIG+"************************************************\n"+

"\t **"+HIG+"********************************************"+NORM+""+GRN+"**\n"+

"\t **"+HIG+"*                                          *"+NORM+""+GRN+"**\n"+

"\t **"+HIG+"*             "+NORM+GRN+"The Lizards Bite"+NORM+HIG+"             *"+NORM+""+GRN+"**\n"+ 

"\t **"+HIG+"*                                          *"+NORM+""+GRN+"**\n"+

"\t **"+HIG+"*  "+HIG+"Beer..........................50 coins  *"+NORM+""+GRN+"**\n"+

"\t **"+HIG+"*  "+HIG+"Darkale......................250 coins  *"+NORM+""+GRN+"**\n"+

"\t **"+HIG+"*  "+HIG+"Blackwine....................500 coins  *"+NORM+""+GRN+"**\n"+

"\t **"+HIG+"*  --------------------------------------  *"+NORM+""+GRN+"**\n"+

"\t **"+HIG+"*  "+HIG+"Water.........................50 coins  *"+NORM+""+GRN+"**\n"+

"\t **"+HIG+"*  "+HIG+"Swampgoo.....................250 coins  *"+NORM+""+GRN+"**\n"+

"\t **"+HIG+"*  "+HIG+"SweetWater...................500 coins  *"+NORM+""+GRN+"**\n"+

"\t **"+HIG+"*  --------------------------------------  *"+NORM+""+GRN+"**\n"+

"\t "+NORM+""+GRN+"**"+HIG+"*  "+HIG+"SwampSalad....................50 coins  *"+NORM+""+GRN+"**\n"+

"\t **"+HIG+"*  "+HIG+"Reptilerib...................250 coins  *"+NORM+""+GRN+"**\n"+

"\t **"+HIG+"*  "+HIG+"Crocsteak....................500 coins  *"+NORM+""+GRN+"**\n"+

"\t **"+HIG+"*                                          *"+NORM+""+GRN+"**\n"+

"\t **"+HIG+"********************************************"+NORM+""+GRN+"**\n"+

"\t ************************************************"+NORM+"\n"+

"\t You may '"+BOLD+"order"+NORM+"' any item listed.                \n");

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

else if(str == "ale" || str ==  "darkale"){

     	cost = 250;

     	type = "drink_alcohol";

     	heal_for = 15+random(20);

     	}

else if(str == "wine" || str ==  "blackwine"){

     	cost = 500;

     	type = "drink_alcohol";

     	heal_for = 40+random(20);

     	}

else if(str == "water" || str ==  "Water"){

     	cost = 50;

     	type = "drink_soft";

     	heal_for = 5;

     	}

else if(str == "swampgoo" || str ==  "Swampgoo" || str == "goo"){

     	cost = 250;

     	type = "drink_soft";

     	heal_for = 15+random(20);

     	}

else if(str == "sweetwater" || str ==  "Sweetwater"){

     	cost = 500;

     	type = "drink_soft";

     	heal_for = 40+random(20);

     	}

else if(str == "swampsalad" || str ==  "Swampsalad"){

     	cost = 50;

     	type = "eat_food";

     	heal_for = 5;

     	}

else if(str == "reptilerib" || str ==  "Reptilerib" || str == "rib"){

     	cost = 250;

     	type = "eat_food";

     	heal_for = 15+random(20);

     	}

else if(str == "crocsteak" || str == "Crocsteak"){

	cost = 500;

	type = "eat_food";

	heal_for = 40+random(20);

        }

else{ 

	write("The Bartender says: We ain't got that.\n");

	return 1;

	}

if(this_player()->query_money() < cost){

	write(

"The Bartender says, 'You ain't got enough money!'\n");

	return 1;

	}

if (!call_other(this_player(), type, rate)) {

	write(

"The Bartender looks at you and laughs.\n");	  

return 1;

      }



if(type == "drink_soft" || type =="drink_alcohol")

	mess = "drink";



else mess = "eat";



write(

"You order a "+HIG+""+capitalize(str)+""+NORM+".\n"+

"You quickly "+mess+" it.\n");



    call_other(this_player(), "heal_self", heal_for);

write(

"     -=[HP "+HIG+""+HP+""+NORM+"/"+HIG+""+MHP+""+NORM+"]=-"+

"     -=[SP "+HIG+""+SP+""+NORM+"/"+HIG+""+MSP+""+NORM+"]=-\n");



say(

this_player()->query_name()+" quickly "+mess+"'s a "+str+".\n");

    call_other(this_player(), "add_money", - cost);

write("You have "+this_player()->query_money()+" coins left.\n");

    return 1;

    }

     				

