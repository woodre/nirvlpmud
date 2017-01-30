inherit"room/room";

reset(arg) {

   if(!arg) {

   set_light(1);
   short_desc = "The Elvis Discount Emporium";
   long_desc =
"Welcome to the ELVIS' DISCOUNT EMPORIUM!! (where you always save more money)"+
"\n\nBehind the counter is an elderly man with a strange white outfit on, th"+
"at\nglitters annoyingly.  He claims to be Elvis...\n   This appears to be s"+
"ome kind of understocked novelty store, full of\nwith a few useful things f"+
"or sale.\n   type 'list' to see whats for sale.\n";
   dest_dir = ({
      "players/blue/stores/storefront","southwest"
   });

   if(!present("elvis", this_object())) {
      object elvis;
      elvis=clone_object("players/blue/stores/cant_kill");
      elvis->set_name("elvis");
      elvis->set_short("The feebled King Elvis");
      elvis->set_long("Once the king of Rock 'n' Roll, elvis appears to be "+
            "left with only a small\nshop to show for it all.  He claims that"+
           " the wizard Blue stole his castle.\n   Not likely.\n");
      elvis->set_chat_chance(30);
      elvis->load_chat("Elvis says: Check this out...'Well you can do anythi"+
                       "ng, but lay off a' my\nBlue Suede Shoes...'  Dig?\n");
      elvis->load_chat("Elvis says: Suppose you could help out the shop? This"+
                       " is all I got.\n");
      elvis->load_chat("Elvis grumbles something about Blue taking away his "+
                       "castle and filling it with monsters.\n");
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
      write(ob->short() + "\n            "+find_cost(ob)+"\n");
      ob=next_inventory(ob);
   }
   return 1;
}

find_cost(item) {
   int cost;
   cost= 2 * call_other(item, "query_value");
   return cost;
}

buy_me(item) {
   object player, item_object;
   string item_name, cap_name;
   int money, weight, cost;
   player=this_player();
   cap_name = capitalize(this_player()->query_name());
item_object = present(item, find_object("players/blue/stores/nov_store"));
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
