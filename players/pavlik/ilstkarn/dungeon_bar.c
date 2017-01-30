#include "/players/pavlik/guild/mages/rooms/ROOMS"
#define tp this_player()
#define ME capitalize(this_player()->query_name())
object lkatva, top_list;
object band;

reset(arg) {
  if (arg) return;
  set_light(1);
}

short() {
  return "Cell Block #9";
}

query_ilstkarn(){ return "dungeon_bar"; }

init() {
  add_action("out","out");
  add_action("north","north");
  add_action("order","order");
  add_action("order","buy");
  add_action("read_menu","read");
  add_action("read_menu","look");
}

out() {
  tp->move_player("out#players/pavlik/ilstkarn/cell2");
  return 1;
}

north() {
  write("You can't go that way yet.\n");
  return 1;
}

long(){
  write("\n"+
  "    ============================ \n"+
  "    || C|E|L|L| B|L|O|C|K #|9 || \n"+
  "    ============================ \n"+
  "\n"+
  "You have entered the roughest, toughest, dirtiest bar known to man.\n"+
  "Cell Block #9 is where the crude denizens of Ilstkarn spend there\n"+
  "spare time.  The crowd is noisy, drunk and rowdy.  More than one\n"+
  "person has spilled blood in the not-uncommon bar brawls.  There is\n"+
  "a menu of what is avaliable on the back wall.\n");
  write("     There are two obvious exits: out, north.\n");
  return;
}

read_menu(str){
  if(str == "menu" || str == "at menu"){
  write("\n");
  write(
  "        ============================ \n"+
  "        || C|E|L|L| B|L|O|C|K #|9 || \n"+
  " ============================================== \n"+
  " || 1. Rotgut                        140     || \n"+
  " || 2. 40 Lashes                     300     || \n"+
  " || 3. Antfarm (coffee)              180     || \n"+
  " || 4. Melted Water                  420     || \n"+
  " || 5. Electric Chair                500     || \n"+
  " || 6. 18 and Life                   850     || \n"+
  " ============================================== \n"+
  "\n"+
  "Use: buy <#> to purchase.\n");
  return 1;
  }
}

order(str) {
  string name, short_desc, mess;
  int value, cost, strength, heal;

  if(!str){
    return 0;
  }

  if(str == "1"){
    heal = 10;
    strength = 10;
    value = 140;
    short_desc = "a glass of Rotgut";
    mess = "Blech!";
  } else if(str == "2"){
    heal = 25;
    strength = 12;
    value = 300;
    "a 40 Lashes drink";
    mess = "Whoa Nilly!";
  } else if(str == "3"){
    heal = 0;
    strength = -10;
    value = 180;
    short_desc = "an Antfarm";
    mess = "Warms you right up!";
  } else if(str == "4"){
    heal = 30;
    strength = 10;
    value = 420;
    short_desc = "a Melted Water";
    mess = "The room spins";
  } else if(str == "5"){
    heal = 50;
    strength = 17;
    value = 500;
    short_desc = "an Electric Chair";
    mess = "zzzZZZAP!";
  } else if(str == "6"){
    heal = 40;
    strength = 5;
    value = 850;
    short_desc = "an 18 & Life";
    mess = "The room spins";
  } else {
    return 0;
  }

  if(tp->query_money() < value){
    write("You don't have the funds.\n");
    return 1;
    }

  if(!call_other(tp, "drink_alcohol", strength)){
    write("You can't stomach another drink right now.\n");
    return 1;
  }

  say(ME+" buys "+short_desc+" from the bar.\n");
  say(ME+" tips "+this_player()->query_possessive()+" head back and downs the drink!\n");
  write("You buy "+short_desc+" from the bar.\n");
  write("You tip your head back and down the drink!\n");
  write(mess+"\n");
  tp->heal_self(heal);
  tp->add_intoxination(strength);
  tp->add_money(-value);
  return 1;
}

okay_follow() { return 1; }
