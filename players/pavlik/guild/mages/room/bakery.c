#define ME this_player()->query_name()
#define PATH "players/pavlik/guild/mages/obj/heals/"
inherit "room/room";
  object bakers;
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="Biago's Bakery";
long_desc="You enter Biago's wonderful little bakery.  The fresh aromas of\n"+
   "sweet pastries fills the air.  Biago's is known world wide for the\n"+
   "most tantalizing pastries.  The little shop keeper takes very good\n"+
   "care of his shop, and his customers.  Biago works religiously at the\n"+
   "oven while Mrs. Biago works the counter.  There is a menu on the wall\n"+
   "behind the counter.  Helen waits patiently for your order.\n";

items=({
"menu",
" - - - - Biago's Bakery - - - - \n"+
"  1. Jug of Apple Cider   ...................... 3000 coins\n"+
"  2. Apple Pie   ............................... 1100 coins\n"+
"  3. Bag of Doughnuts   ........................  150 each [x]\n"+
"  4. Blueberry Muffin   ........................  150 coins\n"+
"  5. Thermos of Coffee  ........................  250 coins\n"+
"  6. Bag of Cookies [12]   .....................  400 coins\n"+
"  7. Loaf of French Bread  .....................  600 coins\n"+
" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"+
"Use: buy <#> to make a purchase.\n"+
"",
});

dest_dir=({
 "/players/pavlik/guild/mages/room/main.c", "south",
});

if(!present("bakers", this_object())){
   bakers = clone_object("players/pavlik/guild/mages/rooms/npc/bakers");
   move_object(bakers, this_object());
                        }

call_out("ran_messages", 10);
   }
}

init(){
  add_action("read","read");
  add_action("order","order");
  add_action("order","buy");
  add_action("south","south");
  add_action("converse","tell");
}

read(str){
 if(str == "menu"){
  command("look at menu", this_player());
  return 1;
  }
}

order(str){
  object obj;
  int cost;
  cost = 0;

  write("Temporary disabled.\n");
  return 1;
  
  if(!str){
    write("Helen says: You have to tell me what you want, child.\n"+
    "Helen pinches your cheeks playfully.\n");
    return 1;
  }

  if(str == "1"){
    cost = 3000;   obj = clone_object(PATH+"cider");
  } else if(str == "2"){
    cost = 1100;   obj = clone_object(PATH+"apple_pie");
  } else if(str == "3"){
    write("Helen says: And how many dougnuts would you like sweety?\n");
    input_to("how_many_cookies");
    return 1;
  } else if(str == "4"){
    cost = 150;    obj = clone_object(PATH+"muffin");
  } else if(str == "5"){
    cost = 250;    obj = clone_object(PATH+"thermos");
  } else if(str == "6"){
    cost = 400;    obj = clone_object(PATH+"cookies");
  } else if(str == "7"){
    cost = 600;    obj = clone_object(PATH+"bread");
  }

  if(cost == 0){
    write("Helen looks at you slightly concerned.\n"+
    "Helen says: Poor child, probably been hit on the head to hard.\n"+
    "            I can't understand a darn thing yer saying.\n");
    return 1;
    }

  if(this_player()->query_money() < cost){
    write("Helen shakes her finger at you.\n"+
    "Helen says: Now, now .. you can't take what you don't have the\n"+
    "            money for!  Now don't you wish you saved up?\n");
     destruct(obj);
    return 1;
    }
    if(!this_player()->add_weight(obj->query_weight())){
      write("You cannot carry any more.\n");
      destruct(obj);
      return 1;
    }

  write("You make a purchase from Biago's Bakery.\n");
  say(ME+" makes a purchase from Biago's Bakery.\n");
  move_object(obj, this_player());
  this_player()->add_money(-cost);
  return 1;
}

how_many_cookies(str){
  object obj;
  int many, cost;

  if(!str){
    write("Helen says: You want how many?\n");
    input_to("how_many_cookies");
    return 1;
  }

  sscanf(str, "%d", many);
  obj = clone_object(PATH+"cookies");

  if(many < 1){
    write("Helen says: Ok, 1 tasty doughnut!.\n");
    obj->set_cookies(1);
  } else if(many > 12){
    write("Helen says: The most I can put into one bag is 12.\n");
    obj->set_cookies(12);
  } else {
    write("Helen says: Ok, "+many+" tasty dougnuts!\n");
    obj->set_cookies(many);
  }
  cost = many * 150;
  if(this_player()->query_money() < cost){
    write("Helen shakes her finger at you.\n"+
    "Helen says: Don't go trying to buy things you can't pay for!\n");
    destruct(obj);
    return 1;
  }
  write("You make a purchase from Biago's Bakery.\n");
  say(ME+" makes a purchase from Biago's Bakery.\n");
  this_player()->add_money(-cost);
  this_player()->add_weight(many * obj->query_weight());
  move_object(obj, this_player());
  return 1;
}

south(){
  write(
  "Helen says: Have a good day, sweety!\n"+
  "Helen waves happily.\n");
  this_player()->move_player("south#players/pavlik/guild/mages/room/main");
  say(ME+" leaves the bakery.\n");
  return 1;
}

converse(str) {
  string who, what;
  object obj;

  if(sscanf(str, "biago %s", what) == 1) {
    if(what == "magic key") {
      if(present("topaz ring", this_player())) {
        write(
        "Biago tells you: But I already gave it to you!\n");
        return 1;
      }
      if(("players/pavlik/ilstkarn/ilstkarn_portal")->query_key() > 3) {
        write(
        "Biago tells you: Aye, I know the key that you speak of, but I\n"+
        "have given it away to someone else.  You will have to find the\n"+
        "mystic portal by yourself.\n");
        return 1;
      }
      else {
        write(
        "Biago tells you: Yes indeed.  I am told that this magical ring\n"+
        "will take you to the Portal of Ilstkarn.  Be careful, lad...\n"+
        "that place is very dangerous!\n");
        write("Biago gives you a topaz ring.\n");
        say("Biago gives something to "+ME+".\n");
        obj = clone_object("players/pavlik/armor/ilstkarn_ring");
        move_object(obj, this_player());
        ("players/pavlik/ilstkarn/ilstkarn_portal")->add_key();
        return 1;
      }
    }
    else {
      write("Biago doesn't seem to hear you.\n");
      return 1;
    }
  }
}

ran_messages(){
  int x;

  x = random(10);
if(x == 0) 
tell_room(this_object(),
"The sweet aromas of the bakery make your mouth water.\n");
if(x == 1) 
tell_room(this_object(),
"Hawkeye enters the Bakery and buys a bag of doughnuts.\n");
if(x == 2) 
tell_room(this_object(),
"A robust merchant with a full purse enters the shop, smiling merrily.\n");
if(x == 3)
tell_room(this_object(),
"Armageddon makes a purchase from Biago's Bakery.\n");
if(x == 4)
tell_room(this_object(),
"Biago pulls a loaf of french bread from the oven.\n"+
"Mmmmmm ... it smells good!\n");
if(x == 5)
tell_room(this_object(),
"Helen smiles happily.\n");
if(x == 6)
tell_room(this_object(),
"Pain enters the bakery and buys a jug of cider.\n");
if(x == 7)
tell_room(this_object(),
"Sandman makes a purchase from Biago's Bakery.\n");
if(x == 8)
tell_room(this_object(),
"Helen sneaks a blueberry muffin while Biago isn't looking.\n");
if(x == 9)
tell_room(this_object(),
"Saber stuffs a handful of cookies into his mouth.\n");
call_out("ran_messages", 25);
return 1;
}
