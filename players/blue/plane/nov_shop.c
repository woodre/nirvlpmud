inherit"room/room";

reset(arg) {

   if(!arg) {

   set_light(1);
   short_desc = "The Elvis Discount Emporium";
   long_desc =
"Welcome to the Elvis Discount Emporium!!! (where you always save more money)"+
"\nThis is a strange and wonderous shop, sparcley populated with strange and"+
"\nwonderous things.  Behind the counter is an old man who claims to be Elvi"+
   "s.\n"+
"\n   Type 'list' to see commands.\n";

   dest_dir = ({
      "players/blue/stores/storefront","southwest"
   });

   if(!present("elvis", this_object())) {
      object elvis;
      elvis=clone_object("players/blue/stores/cant_kill");
      elvis->set_name("elvis");
      elvis->set_short("The feebled King, Elvis");
      elvis->set_long("Once great, elvis is now just a poor old man.  Blue "+
             "stole his castle and\nall Elvis has left is this strange shop."+
             "\n");
      elvis->set_chat_chance(20);
      elvis->load_chat("Elvis says: I am the King of Rock and Roll!!!\n");
      elvis->load_chat("Elvis says: Check it out....'You ain't nothin' but a"+
             " hound dog.'\n");
      move_object(elvis, this_object());
   }

   }
}

init() {
   ::init();

   add_action("list_me","list");
   add_action("buy_me","buy");

}

list_me() {
   object ob;
   ob=first_inventory("players/blue/stores/nov_store");
      if(!ob) {
         write("The shop is temporarily empty, sorry.\n");
         return 1;
      }
   while(ob) {
      write(ob->query_short() + "\n            "+find_cost(ob)+"\n");
      ob=next_inventory(ob);
   }
   return 1;
}

find_cost(item) {
   int cost;
   cost= 2 * call_other(item, "query_value");
   return cost;
}

buy(item) {
   object player, item_object;
   string item_name, cap_name;
   int money, weight, cost;
   player=this_player();
   cap_name = capitalize(this_player()->query_name());
   item_object = present(item, "players/blue/stores/nov_store");
      if(!item_object) {
         write("That is not sold here.\n");
         return 1;
      }
   item_name=item_object->query_name();
   weight=item_object->query_weight();
   money = player->query_money();
   cost = find_cost(item_object);
   if(money < cost) {
      write("You do not have enought money to buy that.\n");
      return 1;
   }
   if(!call_other(player, "add_weight", weight)) {
      write("You can't carry that much.\n");
      return 1;
   }
   move_object(item_object, player);
   call_other( player, "add_money",0 - cost);
   call_other("players/blue/stores/nov_store","reset");
   write("Ok.\n");
   write("Elvis thanks you.\n");
   say(cap_name + " buys a " + item_name + "\n");
   say("Elvis grins.\n");
   write("Elvis grins.\n");
   return 1;
}
