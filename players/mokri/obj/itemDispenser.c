inherit "/obj/treasure.c";

string *items;

reset(int arg) {
   if(arg) return;
   set_id("dispenser");
   set_name("dispenser");
   set_alias("item dispenser");
   set_short("An Item Dispenser");
   set_long("\nA large, tall machine with a slot in the middle.\nType 'list' for a list of items.\nType 'buy #' to buy that game.\n");
}

int list() {
   string *tmp;
   int x;

   write("Items currently for sale\n"+
      "================================\n");

   for(x = 0; x < sizeof(items); x++) {
      tmp = explode(items[x],"^");
      write((x+1) + ".  " + pad(tmp[0],15) + " " + tmp[1] + " coins\n");
   }

   return 1;
}

int buy(string str) {
   int number,itemCost,itemWeight;
   string *tmp;

   if(!str || sscanf(str,"%d",number) != 1) {
      write("Syntax: buy #\n");
      return 1;
   }

   if(number < 1 || number > sizeof(items)) {
      write("Please select a number between 1 and " + sizeof(items) + ".\n");
      return 1;
   }

   tmp = explode(items[(number-1)],"^");
   if(sscanf(tmp[1],"%d",itemCost));
   if(sscanf(tmp[2],"%d",itemWeight));

   if(this_player()->query_money() < itemCost) {
      write("You do not have the " + itemCost + " coins to purchase '" + tmp[0] + "'.\n");
      return 1;
   }

   if(!this_player()->add_weight(itemWeight)) {
      write("You cannot carry that much.\n");
      return 1;
   }

   this_player()->add_money(-itemCost);
   write("You purchase '" + tmp[0] + "'.\n");
   say(this_player()->query_name() + " purchases '" + tmp[0] + "'.\n");
   move_object(clone_object(tmp[3]),this_player());
   return 1;

}

init() {

   ::init();

   items = ({ "Battleship^100^1^/players/mokri/obj/bship","Farseer Bot^5000^2^/players/mokri/obj/farseerBot" });
   add_action("list","list");
   add_action("buy","buy");

}
get() { return 0; }
