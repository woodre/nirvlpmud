
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
     write("couple things of use here.  There are sliding doors to the east.\n");
     write("Commands: list, buy <number>\n");
     write("There is a dark staircase leading down.\n");
}
init(){
    add_action("buy", "buy");
     add_action("list", "list");
    add_action("about", "about");
    add_action("east", "east");
    add_action("down", "down");
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
     write_file("players/deathmonger/KMART/buy_log",
     this_player()->query_real_name()+" bought a "+item->short()+" "+ctime(time()));
     do_buy();
}
}
list(){
     write("Presently, K-mart has the following items in stock:\n");
/*     write("1.  Dreadnought                12000 coins\n"); */
     write("2.  Portable hole               2000 coins\n");
     write("3.  Soot mine                    600 coins\n");
     write("4.  Shouting mine                600 coins\n");
     write("5.  Artillery shell              800 coins\n");
     write("6.  Bubble of Privacy           1000 coins\n");
     write("7.  A 'thing'                    200 coins\n");
     write("8.  Laughing gas                 300 coins\n");
     write("Please buy by the numbers.\n\n");
     write("What would you like to buy?");
     input_to("buy");
     return 1;
}

buy(str){
       if(str == "1"){
       item = clone_object("players/deathmonger/KMART/dreadnought");
       check();
       return 1;
     }
     if(str == "2"){
        write("Portable holes have been removed due to abuse.\n");
        return 1;
       item = clone_object("players/deathmonger/MISC/hole");
       check();
       return 1;
     }
     if(str == "3"){
       item = clone_object("players/deathmonger/ASSASSIN/MINES/soot_mine");
       check();
       return 1;
     }
     if(str == "4"){
       write("Item removed due to abuse.\n");
       return 1;
       item = clone_object("players/deathmonger/ASSASSIN/MINES/shout_mine");
       check();
       return 1;
     }
     if(str == "5"){
       item = clone_object("players/deathmonger/KMART/shell");
       check();
       return 1;
     }
     if(str == "6"){
       item = clone_object("players/deathmonger/MAGIC/bubble");
       check();
       return 1;
     }
     if(str == "7"){
        write("has been removed due to abuse.\n");
       return 1;
     }
    if(str == "8"){
       item = clone_object("players/deathmonger/MISC/laugh");
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
   "through the sliding doors#players/deathmonger/KMART/parking_lot");
   return 1;
}

down(){
     if(!present("license", this_player())){
       write("You get scared and run back up the stairs.\n");
       return 1;
     }
 call_other(this_player(), "move_player",
    "down#players/deathmonger/ASSASSIN/tavern");
     return 1;
}
