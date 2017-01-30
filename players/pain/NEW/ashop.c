inherit "room/room";
#include "/players/pain/color.h"
#undef EXTRA_RESET
#define EXTRA_RESET keep_reset();

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "The Bigelow Armor Shop";
    no_castle_flag = 0;
    long_desc =
	  "A small dusty shop that smells of metal and polish.\n"+
          "A large counter stands ten feet back from the door.\n"+
          "Behind the counter an assortment of armors hangs from the wall.\n"+
          "A small, clearly lettered sign sits on the counter.\n";

items = ({
	"sign", "A small, handwritten sign listing the items for sale",
});

    dest_dir =
        ({
        "players/pain/NEW/square", "west",
        });

    if(!present("keeper"))
        move_object(clone_object("/players/pain/NEW/mon/skeeper"),this_object());

}

init(){

::init();
    add_action("buy","buy");
    add_action("read","read");
}

read(str) {

if(!str) { 
    write("What would you like to read?\n");
    return 1;
}

if(str != "sign") {
    write("You cannot read "+str+".\n");
    return 1;
}

write(	  "The sign reads:\n\n"+
	  " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=  \n"+
	  "\n"+
	  "  [1]     A "+BOLD+"white"+END+" helmet               300 coins         \n"+
	  "  [2]     A small "+BOLD+"white"+END+" shield         250 coins         \n"+
	  "  [3]     A pair of "+BOLD+"white"+END+" boots        300 coins         \n"+
	  "  [4]     A magical "+BOLD+"white"+END+" amulet       200 coins         \n"+
	  "  [5]     A shoddy "+BOLD+"white"+END+" cloak         150 coins         \n"+
	  "  [6]     A "+BOLD+"white"+END+" metal ring           150 coins         \n"+
	  "  [7]     A suit of "+BOLD+"white"+END+" chainmail    800 coins         \n"+
	  "  [8]     A suit of "+BOLD+"white"+END+" platemail   1300 coins         \n"+
	  "\n"+
	  " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n"+

	  "\n"+
	  " What would you like to buy?\n");
return 1;
}

buy(str){
   int ac,x,cost,wt;
   object armor;
   string sht,type,name;

   if (!str){
	write("What would you like to buy?\n"+
	  "Syntax: buy < number >\n");
	   return 1;
	}
   if (sscanf(str,"%d", x) != 1) {
     write("Syntax: buy < number >\n");
     return 1;
   }
   switch(x){
   case 1:
    ac = 1;
    cost = 300;
    wt = 1;
    sht = "A "+BOLD+"white"+END+" helmet";
    type = "helmet";
    name = "helmet";
    break;
   case 2:
    ac = 1;
    cost = 250;
    wt = 1;
    sht = "A small "+BOLD+"white"+END+" shield";
    type = "shield";
    name = "shield";
    break;
   case 3:
    ac = 1;
    cost = 300;
    wt = 1;
    sht = "A pair of "+BOLD+"white"+END+" boots";
    type = "boots";
    name = "boots";
    break;
   case 4:
    ac = 1;
    cost = 200;
    wt = 1;
    sht = "A magical "+BOLD+"white"+END+" amulet";
    type = "amulet";
    name = "amulet";
    break;
   case 5:
    ac = 1;
    cost = 150;
    wt = 1;
    sht = "A shoddy "+BOLD+"white"+END+" cloak";
    type = "cloak";
    name = "cloak";
    break;
   case 6:
    ac = 1;
    cost = 150;
    wt = 1;
    sht = "An "+BOLD+"white"+END+" metal ring";
    type = "ring";
    name = "ring";
    break;
   case 7:
    ac = 2;
    cost = 800;
    wt = 2;
    sht = "A suit of "+BOLD+"white"+END+" chainmail";
    type = "armor";
    name = "chainmail";
    break;
   case 8:
    ac = 3;
    cost = 1300;
    wt = 3;
    sht = "A suit of "+BOLD+"white"+END+" platemail";
    type = "armor";
    name = "platemail";
    break;
    }
if((x>8)||(x<1)){
    write("You must select an item. (1-8)\n");
    return 1;
    }

    if(this_player()->query_money() < cost){
     write("You can't afford it.\n");
     return 1;
     }
     if(!call_other(this_player(),"add_weight",wt)){
      write("You can't carry that much.\n");
      return 1;
      }
    call_other(this_player(),"add_money",-cost);
    armor = clone_object("obj/armor");
    armor->set_name(name);
    armor->set_short(sht);
    armor->set_alias(type);
    armor->set_weight(wt);
    armor->set_ac(ac);
    armor->set_long("A "+BOLD+"white"+END+" piece of armor from Bigelow.\n");
    armor->set_value(cost - 50);
    armor->set_type(type);
    move_object(armor,this_player());
    write("You bought "+sht+".\n");
    return 1;
    }

keep_reset() {
if(!present("keeper"))
move_object(clone_object("/players/pain/NEW/mon/skeeper"),this_object());
}
