inherit "obj/clean";

id(str) { return str=="dispenser"; }
short() { return "A fancy talker dispenser"; }
long() {
   write("The Fancy Talker Dispenser!\n");
}

howto() {
   write("You can purchase talkers from the dispenser for 100 coins.\n"+
   "Just type 'buy talker' to get your fancy talker.  The talkers\n"+
   "have a lifetime warranty, so if they ever break, you'll get a\n"+
   "full refund, but you'll have to bug Dune about that.\n");
}

buy(str) {
   object talker;
   if(str=="talker") {
   write("This item has been deactivated until it is brought under the\n"+
         "rules laid down by the gods concerning talking devices.\n");
   return 1;
   if(this_player()->query_money() < 100) {
   write("You don't have enough gold coins!\n");
   return 1;
   }
   if(!call_other(this_player(), "add_weight", 1)) {
   write("You can't carry that much.\n");
   return 1;
   }
   this_player()->add_money(-100);
   talker=clone_object("/players/dune/objects/talkobj.c");
   move_object(talker, this_player());
   write("You slide your coins in the machine and a talker falls out.\n");
   say(capitalize(this_player()->query_real_name())+
       " buys a talker from the dispenser.\n");
        return 1;
        }
}
