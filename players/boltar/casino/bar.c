object newspaper, top_list;
object band;
static string a;

reset(arg) {
    if (!present("bartender"))
        move_object(clone_object("obj/bartender"), this_object());
    if (arg) return;
    if (!present("pokermachine"))
       move_object(clone_object("players/boltar/casino/poker"), this_object());
    set_light( 1);
}

short() {
    return "Casa de Nirvana Bar";
}

init() {
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("move");
    add_verb( "south");
    add_action("order");
    add_verb("order");
    add_action("order");
    add_verb("buy");
#else
  add_action("move", "south");
  add_action("order", "order");
  add_action("order", "buy");
#endif
    add_action("look", "look");
    add_action("look", "l");
    add_action("look", "examine");
    add_action("look", "read");
}

move() {
    object ob;
    call_other(this_player(), "move_player","south#"+"players/boltar/casino/restaurant");
    return 1;
}

long() {
 write("Dim lighting and dark decor make the inside of the bar\n"+
        "appear more intimate than it really is.  Several small\n"+
        "tables are scattered throughout the room, each flanked\n"+
        "by two comfortable wooden spindle-backed chairs, and each\n"+
        "covered with a deep scarlet tablecloth.  The warm amber \n"+
        "flicker of candlelight from the candles gracing the center \n"+
        "of each table and from the large circular iron chandeliers\n"+
        "supsended from the ceiling, casts a golden hue across \n"+
        "everything in the room, and causes faint shadows to dance \n"+
        "across the walls.  The short, slate grey carpet underfoot \n"+
        "muffles the voices of patrons as they sit over their drinks.\n"+
        "The walls are painted a light grey, and decorated with \n"+
        "various horse racing memorabilia.  A long mirror runs the \n"+
        "length of the north wall, reflecting the room back upon \n"+
        "itself and showing the exit to the south.  A highly polished \n"+
        "bar of deep mahogany stands before the mirror, along with a \n"+
        "tidy row of matching bar stools.  Various liquor bottles are \n"+
        "lined up along the back of the bar, and a large wooden rack \n"+
        "stores a myriad of glasses overhead.  A neatly lettered sign \n"+
        "behind the bar lists the prices for the various drinks that \n"+
        "are offered for consumption.\n");
}
look(str) {
  if (!str) return 0;
  if(str=="at exit"){
     write("The sole exit to the south leads back to the Restaurant.\n");
     return 1;}
  if(str=="at door"){
     write("The large door to the south is inset with thick frosted glass\n"+
     "that blurs the view of the room beyond. It leads to the Restaurant.\n");
     return 1;}
  if(str=="at chairs"){
    write("Two sturdy spindle-backed chairs flank each table.\n");
     return 1;}
  if(str=="at chair"){
    write("The sturdy, spindle-backed chair appears to be made of\n"+
        "mahogany, and is very heavy.\n");
    return 1;}
  if(str=="at ceiling"){
    write("The vaulted ceiling is barely discernable overhead in the \n"+
        "dim light of the room.  However, suspended by iron chains\n"+
        "from the ceiling are several large, circular iron chandeliers,\n"+
        "each holding dozens of twinkling candles.\n");
    return 1;}
  if(str=="at chandeliers"){
    write("Suspended by iron chains from the ceiling are several large,\n"+
        "circular iron chandeliers, each holding dozens of twinkling \n"+
        "candles which bathe the room in dim, golden light.\n");
    return 1;}
  if(str=="at chandelier"){
    write("The large iron chandelier holds dozens of twinkling candles\n"+
        "which bathe the room in dim, golden light.  The chandelier\n"+
        "is suspended high above the floor by a sturdy iron chain.\n");
    return 1;}
  if(str=="at floor"){
     write("The floor is covered by a high-quality, \n"+
        "yet sturdy, short-nap grey carpet.\n");
    return 1;}
  if(str=="at carpet"){
     write("The carpet is a high-quality, yet sturdy, \n"+
        "industrial grey with a short nap.\n");
    return 1;}
  if(str=="at flames"){
     write("Bright points of light twinkle and dance from the\n"+
        "tops of the candles and chandeliers, casting endless\n"+
        "patterns of shadows across the room.\n");
    return 1;}
  if(str=="at flame"){
     write("The bright point of light twinkles and dances with\n"+
        "each stray breeze.\n");
    return 1;}
  if(str=="at wall"){
    write("The wall is painted a soft grey to match the decor.\n"+
        "Various portraits showing equestrian and horse racing\n"+
        "scenes hang upon the wall.\n");
    return 1;}
  if(str=="at walls"){
     write("The walls are painted a soft grey to match the decor.\n"+
        "Various portraits showing equestrian and horse racing\n"+
        "scenes hang upon the walls.\n");
    return 1;}
  if(str=="at memorabilia"){
     write("Various portraits showing equestrian and horse racing\n"+
        "scenes hang upon the walls of the bar.\n");
    return 1;}
  if(str=="at table"){
     write("The small, round table is covered with a thick scarlet \n"+
        "tablecloth that seems to absorb the dancing golden light \n"+
        "from the candle that rests atop it.  \n");
    return 1;}
  if(str=="at tables"){
     write("Each small, round table is covered with a thick scarlet \n"+
        "tablecloth that seems to absorb the dancing golden light \n"+
        "from the candle that rests atop it.  \n");
    return 1;}
  if(str=="at tablecloth"){
     write("The heavy, scarlet tablecloth hangs several inches beyond\n"+
        "the edges of the table.\n");
    return 1;}
  if(str=="at candle"){
     write("The thick, squat candle rests in a flat ceramic holder\n"+
        "at the center of the table, its flame brightly dancing\n"+
        "to and fro with each passing breeze.\n");
    return 1;}
  if(str=="at candles"){
    write("Thick, squat candles rest in a flat ceramic holder\n"+
         "at the center of each table, their flames brightly \n"+
        "dancing to and fro with each passing breeze.\n");
    return 1;}
  if(str=="at glasses"){
     write("A myriad of different shaped glasses hang suspended\n"+
        "from a wooden rack above the bar.\n");
    return 1;}
  if(str=="at glass"){
     write("The foremost glass in the rack above the bar appears\n"+
        "to be a large beer stein.\n");
    return 1;}
  if(str=="at mirror"){
     write("The enormous polished mirror reflects runs the length\n"+
        "of the north wall, creating the illusion of another bar\n"+
        "beyond.  The barkeep can look into its spotless surface\n"+
        "and keep an eye on the patrons even when his back is turned.\n");
    return 1;}
  if(str=="at bar"){
     write("The huge mahogany bar is polished to a mirror sheen, and \n"+
        "darkly reflects the line of liquor bottles at its back edge.\n");
    return 1;}
  if(str=="at stools"){
     write("Four-legged bar stools rest at even intervals along\n"+
        "the length of the bar.  They are made of the same heavy,\n"+
        "rich mahogany as the bar.\n");
    return 1;}
  if(str=="at stool"){
     write("The four-legged bar stool rests beside the bar.  It is\n"+
        "made of the same heavy, rich mahogany as the bar.\n");
    return 1;}
  if(str=="at bottles"){
    write("Colorful liquor bottles of every shape and size line\n"+
        "the far edge of the bar.\n");
    return 1;}
  if(str=="at liquor"){
    write("Colorful liquor bottles of every shape and size, containing\n"+
        "every imaginable liquor, line the far edge of the bar.\n");
    return 1;}
  if(str=="at rack"){
     write("The heavy wooden rack is suspended from the celing by\n"+
        "dark iron chains.  Dozens of sparkling clean glasses of\n"+
        "every shape and size are held securely in its grip.\n");
    return 1;}
  if (str=="at sign"||str=="at large sign"||str=="sign"||str=="large sign") {
      write("A large sign here says:\n");
    write("Drinks available here:\n\n");
    write("     Beer on tap         :  10 coins\n");
    write("     Cup of coffee       :  20 coins\n");
    write("     Rusty Nail          : 150 coins\n");
    write("     Gin and Tonic       : 150 coins\n");
    write("     Pina Colada         : 150 coins\n");
    write("     Singapore Sling     : 200 coins\n");
    write("     Martini             : 200 coins\n");
    write("     Old Fashioned       : 230 coins\n");
    write("     Boilermaker         : 300 coins\n\n");
  return 1;
  }
  if(a!="bb") if(sscanf(str,"at %s",a)!=1) {
    a="bb"; if(look("at "+str)) a="dd"; else a="cc";}
  if(a=="dd") { a="cc"; return 1;}
  return 0;
}   
order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (!present("bartender")) {
       write("The bartender is gone and all the bottles appear to be \n"+
         "broken. Their contents spilled on the floor behind the bar.\n");
      return 1;
    }
    if (str == "beer") {
	mess = "The bartender places a beer in front of you.";
	heal = 1;
        value = 10;
	strength = 3;
    }
    else if (str == "pina" || str == "pina colada") {
	mess = "The bartender gives you a Pina Colada";
	heal = 10;
        value = 150;
        strength = 7;
    }
    else if (str == "gin and tonic" || str == "tonic") {
        mess = "The bartender gives you a Gin and Tonic";
        heal = 11;
        value = 150;
        strength = 8;
    }
    else if (str == "nail" || str == "rusty nail") {
        mess = "The bartender hands you your drink";
        heal = 11;
        value = 150;
        strength = 9; 
    }
    else if (str == "sling" || str == "singapore sling") {
        mess = "The bartender hands you a Singapore Sling";     
        heal = 17;
        value = 200;
        strength = 12;
    }
    else if (str == "martini") {
        mess = "The bartender places a Martini before you";
        heal = 14; 
        value = 200;
        strength = 10;
    } else if (str == "old" || str == "old fashioned") {
	mess = "The bartender hands you an Old Fashioned";
	heal = 25;
        value = 230;
        strength = 13;
    } else if (str == "boilermaker" ) {         
        mess = "The bartender hands you an Boilermaker";
        heal = 30;
        value = 300;
        strength = 14;
    } else if (str == "coffee" || str == "cup of coffee") {
	mess = "You feel somewhat invigorated";
	heal = 0;
	value = 20;
	strength = -2;
    } else {
       write("The bartender says: What do you want?\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("That costs " + value + " gold coins, which you don't have.\n");
	return 1;
    }
    cost = value;
    if (strength > (call_other(this_player(), "query_level") + 2)) {
	if (strength > (call_other(this_player(), "query_level") + 5)) {
	    /* This drink is *much* too strong for the player */
	    say(call_other(this_player(), "query_name", 0) + " orders a " +
		str + ", and immediately throws it up.\n");
	    write("You order a " + str + ", try to drink it, and throw up.\n");
	} else {
	    say(call_other(this_player(), "query_name", 0) + " orders a " +
		str + ", and spews it all over you!\n");
	    write("You order a " + str + ", try to drink it, and sputter it all over the room!\n");
	}
	call_other(this_player(), "add_money", - cost);
	return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
	write("The bartender says: I think you've had enough.\n");
	say(call_other(this_player(), "query_name", 0) + " asks for a " +
		str + " but the bartender refuses.\n");

	return 1;
    }
    write("You pay " + cost + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
    say("The bartender serves up the drink.\n");
    call_other(this_player(), "add_money", - cost);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    write("You consume your drink.\n");
    return 1;
}
