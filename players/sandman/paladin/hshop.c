
#define COST item->query_value() * 2
object item;
object me;
reset(arg){
     if(arg) return;
     set_light(1);
}

short() { return "Paladin Expedition Outfiters Inc."; }
long(){
  write("This is a small shop that equips Paladins for thier long and\n");
  write("dangerous journeys. The walls are lined with shelves full of all\n");
   write("types of curious items.\n");
     write("Commands: list, buy <number>\n");
      write("Obvious Exits: east.\n");
}
init(){
if(!present("guild_medal", this_player()) &&
   this_player()->query_interactive()) {
   call_other(this_player(), "move_player", "out#room/church");
   return 1;
   }
 
    add_action("buy", "buy");
     add_action("list", "list");
    add_action("about", "about");
    add_action("east", "east");
    add_action("out", "out");
}

check(){
     if(COST > this_player()->query_money()){
     write("That would cost you "+COST+" coins, which you don't have.\n");
     return 1;
     }
     if(!this_player()->add_weight(item->query_weight())){
       write("You can't carry that much.\n");
       return 1;
     }
     else {
     this_player()->add_money(-COST);
     do_buy();
}
}
list(){
     write("The shop now has available the following items:\n");
     write("1.  Iron Rations                        3000 coins\n");
     write("2.  Canteen of Water                    3000 coins\n");
     write("Please buy by the numbers.\n\n");
     write("What would you like to buy?");
     input_to("buy");
     return 1;
}

buy(str){
me = this_player();
     if(str == "1"){
       item = clone_object("players/sandman/paladin/obj/rations");
       check();
       return 1;
     }
     if(str == "2"){
       item = clone_object("players/sandman/paladin/obj/water");
       check();
       return 1;
     }
     else {
     write("We don't have that in stock.\n");
     return 1;
     }
}

do_buy(){
     write("You buy a "+item->short()+".\n");
     if(item->query_id() == "dreadnought"){
       move_object(item, environment(this_player()));
       write("The dreadnought rumbles with power!\n");
       write("Make sure you 'drop' it before using it.\n");
 
       return 1;
     }
     move_object(item, this_player());
     return 1;
}

east(){ 
call_other(this_player(), "move_player",
   "east#players/sandman/paladin/hall3");
   return 1;
}
out(){
call_other(this_player(), "move_player",
  "out#players/sandman/paladin/hall3");
   return 1;
}
realm() {return "NT";}
