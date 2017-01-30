#define COST item->query_value() * 2
object item;
object me;
reset(arg){
     if(arg) return;
     set_light(1);
}

short(){ return "Catwoman's Shop."; }
long(){
   write("This is a little shop for items of intrigue.\n"
+ "The source of some most excellent\n"
+ "items.\n");
     write("Commands: list, buy <number>\n");
}
init(){

/*   if(!present("thief guild", this_player())) {
      write("You are not a Thief...Leave us!\n");
      move_object(this_player(),"room/church");
      return 1;
   }*/
    add_action("buy", "buy");
     add_action("list", "list");
    add_action("about", "about");
    add_action("lounge", "lounge");
    add_action("play", "play");
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
     write("1.  Naughty Nighty                       \n");
     write("2.  Teddy                                \n");
     write("3.  Tea                                  \n");
     write("4.  Beer  (doesn't heal)                 \n");
     write("5.  Flowers                              200 coins\n");
     write("6.  Roses                                600 coins\n");
     write("7.  Bottled Water                        \n");
     write("8.  Banana                               \n");
     write("9.  Frisbee                              \n");
     write("10. Spray paint (can)                    Sold out\n");
     write("11. Naughty Toy (in bag)                 \n");
     write("12. Diamond Necklace                     10000 coins\n");
     write("13. Saphire Necklace                     1000 coins\n\n");
     write("14. Ruby Necklace                        10000 coins\n");
     write("15. Diamond Bracelet                     1000 coins\n");
     write("16. Diamond Ring                         1000 coins\n");
     write("17. Popcorn                              \n");
     write("18. High Heels (spikes)                  \n");
     write("19. Thong                                \n");
     write("20. Spin the bottle game                 Sold out\n");
     write("Please buy by the numbers.\n\n");
     write("email Catwoman for more Ideas.\n\n");
     write("What would you like to buy?");
     input_to("buy");
     return 1;
}

buy(str){
me = this_player();
     if(str == "1"){
item = clone_object("players/catwoman/stuff/nighty");
check();
return 1;
     }
     if(str == "2"){
item = clone_object("players/catwoman/stuff/teddy");
check();
return 1;
     }
     if(str == "3") {
item = clone_object("players/catwoman/stuff/tea");
check();
return 1;
     }
     if(str == "4") {
item = clone_object("players/catwoman/stuff/beer");
check();
return 1;
     }
     if(str == "5") {
item = clone_object("players/catwoman/stuff/flowers");
check();
return 1;
     }
     if(str == "6") {
item = clone_object("players/catwoman/stuff/roses");
check();
return 1;
     }
     if(str == "7") {
item = clone_object("players/catwoman/stuff/water");
check();
return 1;
     }
     if(str == "8") {
item = clone_object("players/catwoman/stuff/banana");
check();
return 1;
     }
     if(str == "9") {
item = clone_object("players/catwoman/stuff/frisbee");
check();
return 1;
     }
     if(str == "10") {
item = clone_object("players/catwoman/stuff/paint");
check();
return 1;
     }
     if(str == "11") {
item = clone_object("players/catwoman/stuff/toy");
check();

return 1;
     }
     if(str == "12") {
item = clone_object("players/catwoman/stuff/dneck");
check();
return 1;
     }
     if(str == "13") {
item = clone_object("players/catwoman/stuff/sneck");
check();
return 1;
     }
     if(str == "14") {
item = clone_object("players/catwoman/stuff/rneck");
check();
return 1;
     }
     if(str == "15") {
item = clone_object("players/catwoman/stuff/dbrace");
check();
return 1;
     }
     if(str == "16") {
item = clone_object("players/catwoman/stuff/dring");
check();
return 1;
     }
     if(str == "17") {
item = clone_object("players/catwoman/stuff/popcorn");
check();
return 1;
     }
     if(str == "18") {
item = clone_object("players/catwoman/stuff/heels");
check();
return 1;
     }
     if(str == "19") {
item = clone_object("players/catwoman/stuff/thong");
check();
return 1;
     }
     if(str == "20") {
item = clone_object("players/catwoman/stuff/sgame");
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

lounge(){
call_other(this_player(), "move_player",
   "in#players/catwoman/lounge");
   return 1;
}
play(){
call_other(this_player(), "move_player",
   "in#players/catwoman/play");
   return 1;
}
realm() {return "NT";}

