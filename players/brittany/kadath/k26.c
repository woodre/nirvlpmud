
inherit "room/room";
object top_list;
object player;
object newspaper;
object menu;
string items;
string dest_dir;

reset(arg) {
    if (!top_list || !present(top_list, this_object())) {
        top_list = clone_object("obj/level_list");
        move_object(top_list, this_object());
    }
 
    if (!newspaper || !present(newspaper, this_object())) {
        newspaper = clone_object("obj/newspaper");
        move_object(newspaper, this_object());
        }

    if (!menu || !present(menu, this_object())) {    
        menu = clone_object("/players/brittany/kadath/OBJ/barmenu.c");
        move_object(menu, this_object());
        }

 long_desc = 
   "     You are in the Merchants bar.  On one side of the room\n"+
   "there is a bar.  The bar along with some barstools sitting\n"+
   "evenly in front are made of stone.  A few tables are arranged\n"+
   "neatly on the other side.  Behind the counter hangs a bar menu.\n";

   items = ({
         "bar","The bar is long and made out stone",
         "barstools","The barstools are evenly spaced in front of the bar",
         "tables","Some private stone tables are arranged around the room",
          });

dest_dir = ({   
         "/players/brittany/kadath/k23.c","west",
          });
 
    set_light( 1);
}
short() {
    return  "The Merchants bar";
}
init() {
    add_action("move","west");
    add_action("order","order");
    add_action("order","buy");

}

move() {
    object ob;

     call_other(this_player(), "move_player",  "west" + "#" +"/players/brittany/kadath/k23.c");
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
   if (str == "wine" || str == "moontree wine") {
        name = "wine";
        short_desc = "A bottle of moontree wine";
        mess = "That feels good";
        heal = 5;
        value = 14;
        strength = 2;
    }
    else if (str == "coffee" || str == "cup of coffee") {
 
        name = "coffee";
        short_desc = "A small cup of coffee";
        mess = "You feel somewhat invigorated";
        heal = 0;
        value = 20;
        strength = -2;
}

    else if (str == "special" || str == "special of the house") {
        name = "special";
        short_desc = "A house special";
        mess = "A soothing sensation goes through your head";
        heal = 10;
        value = 160;
        strength = 8;

    } else if (str == "sap" || str == "gourd of sap") {
        name = "sap";
        short_desc = "A gourd of sap";
        mess = "A rushing dizzyness runs through you";
       heal = 25;
        value = 358;
        strength = 12;
#if 0
#endif
 } else {
       write("The merchant says: What do you want?\n");
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
        write("The merchant says: I think you've had enough.\n");
        say(call_other(this_player(), "query_name", 0) + " asks for a " +
                str + " but the merchant refuses.\n");

        return 1;
  }
    write("You pay " + cost + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
    call_other(this_player(), "add_money", - cost);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}
