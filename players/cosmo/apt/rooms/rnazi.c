/* Apartment Room */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=BLU+"Soup Shop"+NORM;
  no_castle_flag = 0;
  long_desc=
"  You open the door and walk into the shop, following the\n"+
"wonderful aroma in the air.  Your nose leads you into this small\n"+
"shop and behind the counter you see an angry looking man in a\n"+
"tall chef's hat.  Perhaps he can serve you some of the delicious\n"+
"soup that you smell.  You see a small sign on the back wall. The\n"+
"door is behind you.\n",

  items=
  ({
    "door","It is closed behind you",
    "sign","It looks like a menu.  Try reading it",
  });

  dest_dir= ({
    "players/cosmo/apt/rooms/rs4", "out",
  });

  if(!present("nazi", this_object())){
    move_object(clone_object("/players/cosmo/apt/mon/nazi.c"), this_object());
  }
}

init() {
  ::init();
  add_action("read","read");
  add_action("order","order");
  add_action("smell","smell");
}

read(arg) {
  if(!arg) { write("What would you like to read?\n"); return 1; }
  if(arg =="menu" || arg =="sign") {
    write("\n"+
          YEL+"    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
             +"    ~ Welcome to the Soup Shop! ~\n"
             +"    ~                           ~\n"
             +"    ~ Current prices:           ~\n"
             +"    ~  Small cup ........  475  ~\n"
             +"    ~  Large bowl ....... 1850  ~\n"
             +"    ~                           ~\n"
             +"    ~ You may <order> a <cup>   ~\n"
             +"    ~             or a <bowl>.  ~\n"
             +"    ~                           ~\n"
             +"    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+NORM+"\n");
  }
  else { write("You are unable to read the "+arg+".\n"); }
  return 1;
}

order(arg) {
  if(!present("nazi", this_object())){
    write("The Soup Nazi is not here to take your order.\n");
    return 1;
  }
  if(!arg) {
    write("What would you like to order?\n");
    return 1;
  }
  if(arg=="bowl") {
    if(this_player()->query_money() < 1850) {
      write("Show me the money!\n");
      return 1;
    }
    if(!call_other(this_player(),"add_weight",4)) {
      write("You cannot carry that much.\n");
      return 1;
    }
    write("You purchase a bowl of soup.\n");
    say(capitalize(tp)+" buys a bowl of soup.\n");
    this_player()->add_money(-1850);
    move_object(clone_object("/players/cosmo/apt/obj/sbowl.c"), this_player());
    return 1;
  }
  if(arg =="cup") {
    if(this_player()->query_money() < 475) {
      write("Show me the money!\n");
      return 1;
    }
    if(!call_other(this_player(),"add_weight",1)) {
      write("You cannot carry that much.\n");
      return 1;
    }
    write("You purchase a cup of soup.\n");
    say(capitalize(tp)+" buys a cup of soup.\n");
    this_player()->add_money(-475);
    move_object(clone_object("/players/cosmo/apt/obj/scup.c"), this_player());
    return 1;
  }
}

smell(arg) {
  if(!arg) { write("What would you like to smell?\n"); return 1; }
  if(arg=="soup" || arg=="aroma") {
    write("The aroma of the soup is absolutely tantilizing.  You are\n"+
      "suddenly struck with hunger pains and can't wait to taste some.\n");
    return 1;
  }
  else { write("You cannot smell the "+arg+".\n"); return 1; }
}
