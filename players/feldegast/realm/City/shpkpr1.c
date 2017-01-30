#include "/players/feldegast/defines.h"
#define LOG_FILE "/players/feldegast/log/market.log"
init() {
  add_action("menu","ask");
  add_action("menu","list");
  add_action("buy","buy");
  add_action("buy","purchase");
}
id(str) {
  return str=="vendor"||str=="merchant"||str=="shopkeeper";
}

short() {
  return "A shopkeeper";
}

long() {
  write("A tall merchant standing behind a wooden counter.\n"+
        "You can 'ask' him for a list of what he sells.\n"
  );
}

menu() {
  write("The vendor says:  I sell the following:\n\n"+
        "              1. A leather gauntlet        75 coins\n"+
        "              2. A pair of boots          100 coins\n"+
        "              3. A green cloak            100 coins\n"+
        "              4. A crystal amulet         100 coins\n"+
        "              5. A plumed helmet          125 coins\n"+
        "              6. A steel shield           200 coins\n"+
        "              7. A suit of scale mail     700 coins\n"+
        "              8. Set of armor (all)      1500 coins\n"+
        "              9. Quarterstaff            1000 coins\n"
  );
  return 1;
}
status money_check(int arg) {
  if (!(this_player()->query_money()>=arg)) {
    write("You don't have enough money!\n");
    return 1;
  }
  this_player()->add_money(-arg);
  return 0;
}
buy(str) {
  object ob;
 
  if (!str) {
    write("The shopkeeper asks: What do you want to buy?\n");
    return 1;
  }

  write_file(LOG_FILE,
  ctime(time())+" "+capitalize(TP->query_real_name())+" bought "+str+"\n");
  if(str=="staff" || str=="quarterstaff" || str=="9") {
    if(check_weight(4)) return 1;
    if (money_check(1000)) 
      return 1;
    move_object(clone_object("/players/feldegast/arena/equip/staff"),this_player());
    write("You have bought a staff.\n");
    return 1;
  }

  if(str=="gauntlet" || str=="gauntlets"||str=="gloves" || str=="1") {
    if(check_weight(1)) return 1;
    if (money_check(75)) 
      return 1;
    move_object(clone_object("/players/feldegast/arena/equip/gauntlet"),this_player());
    write("You have bought a pair of gauntlets.\n");
    return 1;
  }

  if(str=="cloak" || str=="3") {
    if(check_weight(1)) return 1;
    if (money_check(100)) 
      return 1;
    move_object(clone_object("/players/feldegast/arena/equip/cloak"),this_player());
    write("You have bought a green cloak.\n");
    return 1;
  }
  if(str=="boot"||str=="boots"||str=="2") {
    if(check_weight(1)) return 1;
    if (money_check(100)) 
      return 1;
    move_object(clone_object("/players/feldegast/arena/equip/boots"),this_player());
    write("You have bought a pair of boots.\n");
    return 1;
  }
  if(str=="amulet" || str=="crystal" || str=="4") {
    if(check_weight(1)) return 1;
    if(money_check(100))
      return 1;
    move_object(clone_object("/players/feldegast/arena/equip/amulet"),this_player());
    write("You have bought a crystal amulet.\n");
    return 1;
  }
  if(str=="helmet"||str=="helm" ||str=="5") {
    if(check_weight(1)) return 1;
    if (money_check(125)) 
      return 1;
    move_object(clone_object("/players/feldegast/arena/equip/helmet"),this_player());
    write("You have bought a plumed helmet.\n");
    return 1;
  }
  if(str=="shield" || str=="6") {
    if(check_weight(1)) return 1;
    if (money_check(200)) 
      return 1;
    move_object(clone_object("/players/feldegast/arena/equip/shield"),this_player());
    write("You have bought a steel shield.\n");
    return 1;
  }
  if(str=="suit" || str=="mail" || str=="7") {
    if(check_weight(3)) return 1;
    if (money_check(700)) 
      return 1;
    move_object(clone_object("/players/feldegast/arena/equip/mail"),this_player());
    write("You have bought a suit of mail.\n");
    return 1;
  }
  if(str=="set" || str=="all" || str=="8") {
    if(check_weight(9)) return 1;
    if(money_check(1500)) return 1;
    transfer(clone_object("/players/feldegast/arena/equip/mail"),this_player());
    transfer(clone_object("/players/feldegast/arena/equip/shield"),this_player());
    transfer(clone_object("/players/feldegast/arena/equip/helmet"),this_player());
    transfer(clone_object("/players/feldegast/arena/equip/amulet"),this_player());
    transfer(clone_object("/players/feldegast/arena/equip/boots"),this_player());
    transfer(clone_object("/players/feldegast/arena/equip/cloak"),this_player());
    transfer(clone_object("/players/feldegast/arena/equip/gauntlet"),this_player());
    write("You have bought a full set of armor.\n");
    say(this_player()->query_name()+" bought a full set of armor.\n");
    return 1;
  }

  write("The shopkeeper says: I don't sell that.\n");
  return 1;
}
check_weight(int W) {
  if(!this_player()->add_weight(W)) {
    write("You can't carry that much!\n");
    return 1;
  }
}
