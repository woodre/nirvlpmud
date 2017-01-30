id(str) { return str == "balldisp" || str == "dispenser"; }
 
short() {
  return "A money ball dispenser";
  }
  
long() {
  write("\n"+
        "This is a money ball dispenser.  You put in 10,000 coins and you \n"+
        "get an object worth 5,000 coins.  It is useful if you are going\n"+
        "and getting more coins.  To get buy a money ball type 'buy ball'.\n");
  }
  
init() {
  add_action("buy_ball","buy");
  }
 
buy_ball(str){
  object tp,ball;
  tp=this_player();
  if((!str) || (str != "ball")) {
    tell_object(tp,"Buy What?\n");
    return 1;
    }
if(tp->query_money() < 10000) { /* fixed by wizardchild */
    tell_object(tp,"You are too broke to afford this!\n");
    return 1;
    }
  tell_object(tp,"You stick your coins into the machine and push the button.\n");
  tell_object(tp,"A money ball falls into the tray before you, you quickly pick\n");
  tell_object(tp,"it up and put it in your pocket.\n");
  tell_room(environment(tp),capitalize(tp->query_name())+" buy a money ball from the machine\n");
  tell_room(environment(tp),"and quickly shoves it into their pocket.\n");
  tp->add_money(-10000);
  ball=clone_object("players/pathfinder/detroit/items/moneyball");
  move_object(ball,tp);
  return 1;
}
