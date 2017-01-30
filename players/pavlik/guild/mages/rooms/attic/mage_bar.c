#include "/players/pavlik/guild/mages/rooms/ROOMS"
#define tp this_player()
#define ME capitalize(this_player()->query_name())
object lkatva, top_list;
object band;

reset(arg) {
  if(!present("lkatva", this_object())){
    lkatva = clone_object("players/pavlik/guild/mages/rooms/npc/lkatva");
    move_object(lkatva, this_object());
    }
    if (arg) return;
    set_light(1);
}

short() {
  return "Lkatva's Barrel";
}

query_mguild(){ return "Lkatva's Barrel"; }

init() {
  add_action("guild_move","gm");
  add_action("move","south");
  add_action("order","order");
  add_action("order","buy");
  add_action("read_menu","read");
  add_action("read_menu","look");
  mage_check();
}

move() {
  tp->move_player("south#players/pavlik/guild/mages/rooms/party_room");
  return 1;
}

long(){
  write(
  " -- Lkatva's Barrel --\n"+
  "Lkatva's Barrel is a quiet bar tucked into a small chamber here\n"+
  "in the Mage's Tower.  Lkatva, the proprietor, is world-reknown\n"+
  "for his strange and exotic drinks, the Wizards seem to prefer for\n"+
  "some reason.  He travels all of the realms to gather the strange\n"+
  "ingredients for his drinks.  Lkatva is a small friendly man who\n"+
  "is always ready to offer some advice to a friend.  There is a\n"+
  "menu of Lkatva's devious brews at the bar.\n");
  write("     There is one obvious exit: south.\n");
  return;
}

read_menu(str){
  if(str == "menu" || str == "at menu"){
  write("\n");
  write(
  "* * * * * Lkatva's Specialties: * * * * *\n"+
  "  1. Rotted Onion                  140    \n"+
  "  2. Snoring Fish                  300    \n"+
  "  3. Yellow Whistle (coffee)       180    \n"+
  "  4. Melted Water                  420    \n"+
  "  5. Knuckled Cabbage              500    \n"+
  "  6. Cardinal Sin                  850    \n"+
  "* * * * * * * * * * * * * * * * * * * * *\n"+
  "\n");
  return 1;
  }
}

order(str)
{
  string name, short_desc, mess;
  int value, cost, strength, heal;

  if(!str){
    write("Lkatva says: You would do you want to drink?\n");
    return 1;
    }

  if(str == "1" || str == "onion"){
    heal = 10;
    strength = 10;
    value = 140;
  } else if(str == "2" || str == "fish"){
    heal = 25;
    strength = 12;
    value = 300;
  } else if(str == "3" || str == "whistle"){
    heal = 0;
    strength = -10;
    value = 180;
  } else if(str == "4" || str == "water"){
    heal = 30;
    strength = 10;
    value = 420;
  } else if(str == "5" || str == "cabbage"){
    heal = 50;
    strength = 17;
    value = 500;
  } else if(str == "6" || str == "sin"){
    heal = 40;
    strength = 5;
    value = 850;
  } else {
    write(
    "Lkatva looks at you confused.\n"+
    "Lkatva says: I have never heard of such a drink, but if you\n"+
    "             bring me the recipe, I'm sure a could fix one up!\n");
    return 1;
  }

  if(tp->query_money() < value){
    write(
    "Lkatva says: Hey there buddy!  You gotta have the coinage to\n"+
    "             support this Boozing habit of yours, and right now\n"+
    "             you don't have it!\n");
    return 1;
    }

  if(!call_other(tp, "drink_alcohol", strength)){
    write(
    "Laktva puts three glasses on the bar for you.  You reach out\n"+
    "for the one on the left and your hand passes straight through\n"+
    "it!  You continue reaching until you fall right off your stool\n"+
    "and onto the floor!  When you come to, Laktva is standing above you.\n"+
    "Laktva says:  I think you've had enough for right now.\n"+
    "Laktva takes your car keys and hides them behind the bar.\n");
    return 1;
    }

  say(ME+" buys a drink from the bar.\n");
  write(
  "You buy a drink from the bar.  Lkatva mixes up a truly digusting\n"+
  "looking drink.  With a shrug, you grab the tall glass and down\n"+
  "the entire thing.  Hmmm...that wasnt half bad!\n");
  tp->heal_self(heal);
  tp->add_intoxination(strength);
  tp->add_money(-value);
  return 1;
}
