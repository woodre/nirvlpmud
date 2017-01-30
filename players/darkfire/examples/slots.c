int bet;
object who;
string s1, s2, s3, *chars;

inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("machine");
   set_short("A Slot Machine");
   set_long("A tall box with flashing lights and a\n"+
      "lever on the side.  On the other side of\n"+
      "the machine is a slot where you can 'insert'\n"+
      "your chips to bet.\n"+
      "   Minimum bet: 100 chips\n"+
      "   Maximum bet: 5000 chips\n"+
      "   Betting increments: 100 chips\n");
   set_weight(10000);
}

get() { return 0; }

init() {
   ::init();
   
   add_action("insert","insert");
}

insert(arg) {
   int amt;
   
   if(!present("casino chips",this_player())) {
      write("Go get some chips first!\n");
      return 1; }
   
   if(bet) {
      write("This slot machine is currently in use.\n"+
         "Please wait your turn.\n");
      return 1; }
   if(!arg || sscanf(arg,"%d",amt) != 1) {
      write("How many chips would you like to insert?\n");
      return 1; }
   
   if(amt < 100 || amt > 5000) {
      write("Please look at the machine for betting rules.\n");
      return 1; }
   
   if(present("casino chips",this_player())->query_chip_value() < amt) {
      write("You can't cover that bet!\n");
      return 1; }
   
   if(amt%100) {
      write("You must bet in 100 chip increments!\n");
      return 1; }
   
   bet = amt;
   s1 = 0;
   s2 = 0;
   s3 = 0;
   present("casino chips",this_player())->add_chip_value(-amt);
   chars = ({ "@@@","###","$$$","***" });
   write("You place "+amt+" chips in the slot and pull the lever.\n"+
      "The dials are sent spinning!\n");
   who = this_player();
   call_out("spin_wheel",2);
   return 1; }

spin_wheel() {
   int win, tmp;
   
   tmp = random(sizeof(chars));
   if(s2 && s1) s3 = chars[tmp];
   if(!s2 && s1) s2 = chars[tmp];
   if(!s1) s1 = chars[tmp];
   
   if(s1 && !s2)
      tell_object(who,"\n=======\n"+
      "|     |\n"+
      "| "+s1+" |\n"+
      "| "+s1+" |\n"+
      "| "+s1+" |\n"+
      "|     |\n"+
      "=======\n");
   
   if(s2 && !s3)
      tell_object(who,"\n=======    =======\n"+
      "|     |    |     |\n"+
      "| "+s1+" |    | "+s2+" |\n"+
      "| "+s1+" |    | "+s2+" |\n"+
      "| "+s1+" |    | "+s2+" |\n"+
      "|     |    |     |\n"+
      "=======    =======\n");
   
   if(s3)
      tell_object(who,"\n=======    =======    =======\n"+
      "|     |    |     |    |     |\n"+
      "| "+s1+" |    | "+s2+" |    | "+s3+" |\n"+
      "| "+s1+" |    | "+s2+" |    | "+s3+" |\n"+
      "| "+s1+" |    | "+s2+" |    | "+s3+" |\n"+
      "|     |    |     |    |     |\n"+
      "=======    =======    =======\n");
   if(!s3) {
      call_out("spin_wheel",2);
      return 1; }
   
   if(s1 == s2) win = (bet*4);
   if(win && s1 == s3) win = (bet*10);
   
   if(win) {
      who->add_money(win);
      tell_object(who,"\nYOU WIN "+win+" GOLD COINS!\n"); }
   if(!win) tell_object(who,"\nYOU LOSE!\n");
   bet = 0;
   return 1; }
