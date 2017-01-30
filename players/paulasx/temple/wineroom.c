object newspaper, top_list;

reset(arg) {
  if (!top_list || !present(top_list)) {
    top_list = clone_object("obj/level_list");
    move_object(top_list, this_object());
  }
  if (arg) return;
  set_light( 1);
}

short() {
  return "A wine room";
}

init() {
  add_action ("move"); add_verb ("south");
  add_action ("order"); add_verb ("order");
  add_action ("order"); add_verb ("buy");
  add_action ("read"); add_verb ("read");
  }

move() {
  object ob;
  call_other(this_player(), "move_player",  "south#players/paulasx/temple/vaultroom");
  return 1;
}


long() {
  write("You have entered a wine room.\n");
  write("You can order drinks here.\n\n");
  write("Type 'read menu' to see a list of drinks.\n");
  }

read(str) {
  if (str == "menu") {
    write("-----------------------------------------------|\n");
    write("|                   --------------------                |\n");
                 write("|           Alcoholic beverages          |\n");
    write("|            Boons Farm : 4 coins    |\n");
    write("|         Red Rose : 25 coins         |\n");
    write("|           White Zin : 50 coins        |\n");
    write("|            Port: 100 coins              |\n");
    write("|         Don Perignon : 150 coins  |\n");
    write("|                                               |\n");
    write("|         Non-alcoholic beverages         |\n");
    write("|         -----------------------         |\n");
    write("|             Water : 15 coins            |\n");
    write("|         Mango juice : 100 coins         |\n");
    write("|           Perrier : 250 coins           |\n");
    write("|         Papaya juice : 600 coins        |\n");
    write("|       Pineapple juice : 750 coins       |\n");
    write("|         Coconut milk : 900 coins        |\n");
    write("-------------------------------------------\n");
    return 1;
  }
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
  write("This wineroom no longer serves drinks\n\t\t\t-The Managment <5-4-98>\n");
  return 1;
  if (str == "boons") {
    mess = "That feels good";
    heal = 1;
    value = 4;
    strength = 3;
  }
  else if (str == "rose" || str == "red" || str == "red rose") {
    mess = "You get a pleasant buzz from the drink";
    heal = 5;
    value = 25;
    strength = 4;
  }
  else if (str == "white" || str == "zin" || str == "white zin") {
    mess = "A tingling feeling goes through your body";
    heal = 10;
    value = 50;
    strength = 8;
  }
  else if (str == "port") {
    mess = "Your brain fragments like an eggshell, then reassembles";
    heal = 18;
    value = 100;
    strength = 10;
  }
  else if (str == "don" || str == "perignon" || str == "don perignon") {
    mess = "mmm.. that was really worth it";
    heal = 25;
    value = 150;
    strength = 12;
  }
  else if (str == "water") {
    mess = "Holy water?? hmm.. good idea";
    heal = 1;
    value = 15;
    strength = 0;
  }
  else if (str == "mango" || str == "mango juice") {
    mess = "Nice, cool, and refreshing";
    heal = 6;
    value = 100;
    strength = 0;
  }
  else if (str == "perrier") {
    mess = "Not bad at all! And you thought only yuppies drank this...";
    heal = 15;
    value = 250;
    strength = 0;
  }
  else if (str == "papaya" || str == "papaya juice") {
    mess = "A pleasant sensation cools your palate";
    heal = 35;
    value = 600;
    strength = 0;
  }
  else if (str == "pineapple" || str == "pineapple juice") {
    mess = "The flavor tingles on your tongue as you sip";
    heal = 48;
    value = 750;
    strength = 0;
  }
  else if (str == "coconut" || str == "milk" || str == "coconut milk") {
    mess = "A strange but not unpleasant taste greets your tongue";
    heal = 56;
    value = 900;
    strength = 0;
  }
  else {
    write("The waiter stares at you, saying: We don't have that.\n");
    return 1;
  }

  if (call_other(this_player(), "query_money", 0) < value) {
    write("That costs " + value + " gold coins, which you don't have.\n");
    return 1;
  }
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
    call_other(this_player(), "add_money", - value);
    return 1;
  }
  if (!call_other(this_player(), "drink_alcohol", strength)) {
    write("The bartender says: I think you've had enough.\n");
    say(call_other(this_player(), "query_name", 0) + " asks for a " +
        str + " but the bartender refuses.\n");
    
    return 1;
  }
  write("You pay " + value + " coins for a " + str + ".\n");
  say(call_other(this_player(), "query_name", 0) + " sips a " + str + ".\n");
  call_other(this_player(), "add_money", - value);
  call_other(this_player(), "heal_self", heal);
  write(mess + ".\n");
  return 1;
}
