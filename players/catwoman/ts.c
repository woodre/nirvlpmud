
#define COST item->query_value() * 2
object item;
object me;
reset(arg){
     if(arg) return;
     set_light(1);
}

short(){ return "Catwoman's shop of revenge."; }
long(){
   write("This is a little shop for items of revenge. To most it would look like a\n"
+ "run down store, but to a thief it is the source of some most excellent\n"
+ "items. east is to lockers and shop and pub or west to hall.\n");
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
    add_action("east", "east");
    add_action("out", "west");
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
     write("1.  Rune (bomb)                          sold out\n");
     write("2.  Deathsword                           6000 coins\n");
     write("3.  Blowgun  (+bag of darts)             10000 coins\n");
     write("4.  Amulet of teleportation              sold out\n");
     write("5.  Ball of judgment(for wep and armor)  200 coins\n");
     write("6.  Potion of strength (temp wc of 30)   1400 coins\n");
     write("7.  Deathsword charger                   1000 coins\n");
     write("8.  evil alignment potion                 500 coins\n");
     write("9.  Saki (togo)                          2000 coins\n");
     write("10. Eggrolls (togo)                      3000 coins\n");
     write("11. A takeout menu from the revenge shop sold out\n");
     write("12. A boiling lava (drink) healing shot  10000 coins\n");
     write("13. A sobering Ooze (drink) sobering shot 300 coins\n\n");
     write("Please buy by the numbers.\n\n");
     write("What would you like to buy?");
     input_to("buy");
     return 1;
}

buy(str){
me = this_player();
     if(str == "1"){
       write("The shop is out of that item.\n"); /* Feldegast 6-19-01 */
       return 1;
       item = clone_object("players/catwoman/obj/rune");
       check();
       return 1;
     }
     if(str == "2"){
       item = clone_object("players/catwoman/weapon/dsword");
       check();
       return 1;
     }
     if(str == "3") {
       item = clone_object("players/catwoman/weapon/gunbag");
       check();
        return 1;
     }
/*
     if(str == "4") {
        return 1;
     }
  taken out per boltar - mythos <9-18-97> teleportation amulets are not to be sold */
     if(str == "5") {
item = clone_object("players/catwoman/obj/ball");
check();
 return 1;
     }
     if(str == "6") {
        item = clone_object("players/catwoman/obj/potion");
check();
 return 1;
     }
     if(str == "7") {
item = clone_object("players/catwoman/obj/swordbat");
check();
return 1;
     }
     if(str == "8") {
item = clone_object("players/catwoman/obj/epotion");
check();
return 1;
     }
     if(str == "9") {
item = clone_object("players/catwoman/obj/saki");
check();
return 1;
     }
     if(str == "10") {
item = clone_object("players/catwoman/obj/eggroll");
check();
return 1;
     }
     if(str == "11") {
return 1;
     }
     if(str == "12") {
item = clone_object("players/catwoman/obj/lava");
check();
return 1;
     }
     if(str == "13") {
item = clone_object("players/catwoman/obj/ooze");
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
   "east#players/catwoman/tl");
   return 1;
}
out(){
call_other(this_player(), "move_player",
   "west#players/catwoman/hall2");
   return 1;
}
realm() {return "NT";}
