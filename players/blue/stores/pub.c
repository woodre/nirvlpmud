object newspaper, top_list;

reset(arg) {
   object scientist;
    if (!top_list || !present(top_list)) {
        top_list = clone_object("obj/level_list");
        move_object(top_list, this_object());
    }
   if(!present("scientist",this_object())) {
      scientist=clone_object("players/blue/stores/cant_kill");
         scientist->set_name("scientist");
         scientist->set_alias("mad scientist");
           scientist->set_short("A Mad Scientist Bartender");
         move_object(scientist, this_object());
   }
    if (arg) return;
    set_light( 1);
}

short() {
   return "The Mad Scientist Saloon";
}

init() {
   add_action("list_me","list");
    add_action("move","west");
    add_action("order","order");
    add_action("order","buy");
}

move() {
    object ob;

call_other(this_player(),"move_player","west#players/blue/stores/storefront");
    return 1;
}

long() {
   write(
"Welcome, welcome to the MAD SCIENTIST SALOON! Care to try any of our speci"+
"als?\nAll the drinks are made from the purist of chemicals and guaranteed to"+
"knock\nyou off you feet.\n   You may type 'list' to see the drinks.\n");

}

order(str) {
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "juice") {
        mess = "That feels good";
        heal = 1;
        value = 10;
        strength = 3;
    }
    else if (str == "essence" || str == "essence of donkey") {
        mess = "A tingling feeling goes through your body";
        heal = 10;
        value = 150;
        strength = 7;
    } else if (str == "acid") {
        mess = "A shock wave runs through your body";
        heal = 25;
        value = 230;
        strength = 14;
    } else if (str == "coffee" || str == "cup of coffee") {
        mess = "You feel somewhat invigorated";
        heal = 0;
        value = 20;
        strength = -2;
   } else { 
      write("The Mad Scientist says: What? My drinks not good enough for"+
           " you?  I\ndon't even know what that is!\n");
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
      write("You order a " + str + ", try to drink it, and sputter it all "+
         "over the room!\n");
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
    say(call_other(this_player(), "query_name", 0) + " orders a " + str +
".\n");
    call_other(this_player(), "add_money", - cost);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}

list_me() {
   write("Drinks___\n   Bug juice- 10 coins\n   Black Death Coffee- 20 coins\n"+
   "   Essence of Donkey- 150 coins\n   Perchloric acid (with lime) - 230 coi"+
"ns\n\n");
   return 1;
}
