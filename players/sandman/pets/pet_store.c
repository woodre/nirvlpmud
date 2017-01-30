reset(arg) {
   if (arg) return;
   set_light(1);
}

init() {
   add_action("north","north");
   add_action("buy","buy");
}

north()
{
   this_player()->move_player("north#players/sandman/SURR/path6");
   return 1;
}

short() {
   return "A pet store";
}

long() {
   write("You have entered a small, yet tidy, pet store. The\n"+
        "shelves are lined with animals of all sorts. A small\n"+
        "sign below the counter reads:\n\n"+
        "The Lord of Dreams Proudly Presents Custom Pets!\n"+
        "You tell us how much you want to spend on a pet,\n"+
        "and we'll fix you up!\n\n"+
        "Just type 'buy <amount>' where amount is the\n"+
        "amount your willing to spend on your pet.\n"+
        "You can also 'buy manual' to see what special tricks\n"+
        "your pet can do (these are free).\n\n");
   write("The only exit is to the north.\n");
}

buy(str) {
   object pet;
   int coins, stats;

   if (str == "manual") {
      write("The storeowner hands you a manual.\n");
      say("The storeowner hands "+this_player()->query_name()+
         "a manual.\n");
     move_object(clone_object("players/sandman/pets/manual"),
                this_player());
     return 1;
   }
   if (sscanf(str,"%d", coins) == 1) {
      if (this_player()->query_money() < coins) {
        write("The storeowner says: You don't have that kind of "+
              "money.\n");
        return 1;
      }
      if (coins < 500 || coins > 10000) {
        write("The storeowner says: We don't have anything in that "+
              "price range.\n");
        return 1;
      }
      stats = coins / 500;
      pet = clone_object("players/sandman/pets/pet");
      pet->set_level(stats);
      pet->set_ac(stats/4);
      pet->set_wc(stats);
      pet->set_hp(10*stats);
      pet->patch_owner(this_player());
      move_object(pet, this_object());
      write("The storeowner gives you a fine pet!\n");
     say("The storeowner gives "+this_player()->query_name()+
         " a fine pet!\n");
     this_player()->add_money(-coins);
     return 1;
   }
}
