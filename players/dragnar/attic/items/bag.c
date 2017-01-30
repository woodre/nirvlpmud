inherit "obj/treasure";

void
reset(int arg) {
   if (arg) return;
   set_id("bag");
   set_short("A corpse bag");
   set_long(
"A bag that was buried in the grave with a corpse.  It was believed\n" +
"that money would help the spirit on it's journey.  Maybe you should\n"+
"type 'coins' to get what's in the bag.\n");
   set_weight(0);
   set_value(1200);
   set_save_flag();
}

void init() { add_action("cmd_coins","coins"); }

status
cmd_coins(string str) {
   int coinage;

   if (str) return 0;
   if(environment() != this_player()) return 0;
   coinage=(random(1000)+3000);
   this_player()->add_money(coinage);
   write("You grab the "+coinage+" coins from the bag.\n");
   write("The bag crumbles into dust.\n");
   destruct(this_object());
   return 1;
}
