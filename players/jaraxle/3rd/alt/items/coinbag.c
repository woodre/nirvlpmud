inherit "obj/treasure";

void
reset(int arg) {
   if (arg) return;
   set_id("coin bag");
   set_short("A coin bag");
   set_long(
      "A small cloth bag full of gold coins.  You can\n"+
      "<cash> this bag at any time.\n");
   set_weight(1);
   set_value(10000);
   set_save_flag();
}

void init() { add_action("cmd_coins","cash"); }

status
cmd_coins(string str) {
   int coinage;
   
   if (str) return 0;
   if(environment() != this_player()) return 0;
   coinage=(random(5000)+11000);
   this_player()->add_money(coinage);
   write("You grab the "+coinage+" coins from the bag.\n");
   destruct(this_object());
   return 1;
}
