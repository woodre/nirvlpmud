
#define COST item->query_value() * 2
object item;
reset(arg){
     if(arg) return;
     set_light(1);
}

short(){ return "K-mart"; }
long(){
     write("You have entered a busy K-mart.  The shelves are filled\n");
     write("useful gadgets and worthless junk.  Maybe you can find a\n");
     write("couple things of use here.  There are sliding doors to the south.\n");
     write("Commands: list, buy <number>\n");
}
init(){
    add_action("buy", "buy");
     add_action("list", "list");
    add_action("about", "about");
    add_action("south", "south");
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
/*
     write_file("players/deathmonger/KMART/buy_log",
     this_player()->query_real_name()+" bought a "+item->short()+" "+ctime(time()));
*/
}
}
list(){
     write("Presently, K-mart has the following items in stock:\n");
     write("1.  Dreadnought                12000 coins\n");
     write("2.  Soot mine                    600 coins\n");
     write("3.  Shouting mine                600 coins\n");
      write("4.  Artillery shell              800 coins\n");
     write("5.  Bubble of Privacy           1000 coins\n");
     write("6.  A 'thing'                    200 coins\n");
     write("7.  Laughing gas                 300 coins\n");
     write("8.  Shopping Network Headphones   20 coins\n");
     write("9.  Memorial Wreath              100 coins\n");
     write("Please buy by the numbers.\n\n");
     write("What would you like to buy?");
     input_to("buy");
     return 1;
}

buy(str){
     if(str == "1"){
/*
       item = clone_object("players/deathmonger/KMART/dreadnought");
       check();
*/
write("I'm Sorry but that item is unavailble right now.\n");
       return 1;
     }
     if(str == "2"){
       item = clone_object("players/deathmonger/ASSASSIN_BAK/MINES/soot_mine");

       check();
       return 1;
     }
     if(str == "3"){
      item = clone_object("/players/deathmonger/ASSASSIN_BAK/MINES/shout_mine");
       check();
       return 1;
     }
     if(str == "4"){
       item = clone_object("players/deathmonger/KMART/shell");
       check();
       return 1;
     }
     if(str == "5"){
       item = clone_object("players/deathmonger/MAGIC/bubble");
       check();
       return 1;
     }
     if(str == "6"){
     write("Item removed due to abuse.\n");
     return 1;
       item = clone_object("players/deathmonger/MAGIC/thing");
       check();
       return 1;
     }
     if(str == "7"){
       item = clone_object("players/deathmonger/MISC/laugh");
       check();
       return 1;
     }
     if(str == "8"){
       item = clone_object("players/deathmonger/MISC/shopping");
       check();
       return 1;
     }
     if(str == "9") {
       item = clone_object("players/persephone/obj/wre");
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
     if(item->id() == "dreadnought"){
       move_object(item, environment(this_player()));
       write("The dreadnought rumbles with power!\n");
       write("Make sure you 'drop' it before using it.\n");
       return 1;
     }
     move_object(item, this_player());
     return 1;
}

south(){ 
call_other(this_player(), "move_player",
   "south#room/northroad3");
   return 1;
}

