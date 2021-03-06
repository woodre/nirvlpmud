
inherit "room/room";

reset(arg){

if(!present("soldier"))  {
move_object(clone_object("/players/traff/mon/soldier.c"),this_object());  }
if(!present("farmer"))  {
move_object(clone_object("/players/traff/mon/farmer.c"),this_object());  }
if(!present("drunk"))  {
move_object(clone_object("/players/traff/mon/drunk.c"),this_object());  }
if(!present("barmaid"))  {
move_object(clone_object("/players/traff/mon/barmaid.c"),this_object());  }
if(!present("barkeep"))  {
move_object(clone_object("/players/traff/mon/barkeep.c"),this_object());  }
if(!present("minion"))  {
move_object(clone_object("/players/traff/mon/minion.c"),this_object());  }

 if(!arg){

 set_light(1);
 short_desc="Delnoch Tavern";
long_desc=
("Warm smoke filled air engulfs you, as you enter the tavern.  Across\n"+
"the room a fire burns brightly in a large fireplace.  A large\n"+
"painting hangs over the fireplace.  To your left is a bar with mugs\n"+
"stacked at intervals along it.  Around the room are numerous\n"+
"tables and chairs.  Each table has a candle on it, which adds\n"+
"to the light of the room.  Behind the bar a board has been\n"+
"nailed to the wall.  It says, MENU.\n");

items=({
"menu","     Delnoch's Best Beer  :  24 coins\n"+
"     Ben's Special        : 162 coins\n"+
"     Deathwalker          : 485 coins\n\n",
"smoke","The smoke is not too thick, and has a pleasent aroma\n",
"fire","The fire blazes warmly",
"fireplace","A stone fireplace, with a blazine fire",
"painting","A large painting of a battle on one of the\n"+
"fortress walls.  At the center of the fighting is a grey\n"+
"haired man swinging a huge double bladed axe.  A bronze\n"+
"plaque attached to the frame says simply:\n"+
"                DRUSS THE LEGEND",
"bar","A wooden bar runs along the wall.  It appears plain but sturdy",
"mugs","Large wooden mugs, with rope handels\n",
"tables","None of the tables seem to match, but they are all made of\n"+
"wood from the nearby forest\n",
"chairs","The wooden chairs don't match either, but they seem to go with\n"+
"the tables",
"candle","A plain wax candle",
"floor","The floor is hard packed dirt. It might have been swept today",
"walls","The walls are rough cut timbers, chinked with clay",
 });

  dest_dir=({
"/players/traff/dmain.c","east",
      });
  }   }


init()  {
 ::init();
  add_action("east","east");
  add_action("search","search");
    add_action("move","east");
    add_action("order","order");
    add_action("order","buy");
/*
    add_action("look");
    add_verb("look");
*/
}

move() {
#ifdef MUST_STAY_WITH_DRINKS
     if (has_drink(this_player())) {
        tell_object(this_player(),
                    "You are not allowed to leave with drinks!\n");
        return 1;
     }
#endif
     call_other(this_player(), "move_player", "east" + "#" +"/players/traff/room/dmain.c");
     return 1;
}

order(str)
{
    object drink;
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "beer") {
	name = str;
	short_desc = "A bottle of beer";
	mess = "That feels good";
	heal = 0;
	value = 24;
	strength = 2;
    }
    else if (str == "special" || str == "ben's special") {
	name = "special";
	short_desc = "Ben's own special";
	mess = "A tingling feeling goes through your body";
	heal = 10;
	value = 162;
	strength = 8;
    } else if (str == "deathwalker" || str == "death") {
	name = "deathwalker";
	short_desc = "A deathwalker";
	mess = "You feel like you have been hit with an axe";
	heal = 45;
	value = 485;
	strength = 13;
#if 0
    } else if (str == "potion" || str == "potion of healing") {
	name = "potion";
	short_desc = "A potion of healing";
	mess = "You are totally healed";
	heal = 1000;
	value = 10000;
	strength = 0;
#endif
    } else {
       write("What ?\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("That costs " + value + " gold coins, which you don't have.\n");
	return 1;
    }
    drink = clone_object("obj/drink");
    if (!call_other(this_player(), "add_weight",
	call_other(drink, "query_weight"))) {
	write("You can't carry more.\n");
	destruct(drink);
	return 1;
    }
    if (!call_other(drink, "set_value", name + "#" + short_desc + "#" + mess +
	"#" + heal + "#" + value + "#" + strength)) {
	write("Error in creating drink.\n");
	destruct(drink);
	return 1;
    }
    call_other(drink, "set_pub");
    move_object(drink, this_player());
    call_other(this_player(), "add_money", - value);
    write("You pay " + value + " for a " + name + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " +
	name + ".\n");
    return 1;
}

#ifdef MUST_STAY_WITH_DRINKS
has_drink(obj) {
     status drink;
     object ob;
     ob = first_inventory(obj);
     while(ob) {
        if (call_other(ob, "id", "drk2"))
             drink = 1;
        if (call_other(ob,"can_put_and_get")) {
             if (has_drink(ob))
                  drink = 1;
        }
        ob = next_inventory(ob);
     }
     return drink;
}
#endif


search(str)  {

  if(str=="room" || str=="floor" || str=="ground" || str=="bar"
      || str=="mugs"  || str=="tables" || str=="chairs"  || str=="painting") {
  write("You search the "+str+" but find nothing of interest.\n");
    return 1; }

    write("Search what?\n");
  return 1; }
