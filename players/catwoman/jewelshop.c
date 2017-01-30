#define COST item->query_value() * 2
object item;
object me;
reset(arg){
     if(arg) return;
     set_light(1);
}

short(){ return "The Local jewel shop."; }
long(){
	write("The Local Jewel Shop.\n");
	write("MOTE** Not responsible for losses due to crashes.\n");
	write("West is the Board walk and east is the hall of Doors.\n");
     write("Commands: list, sell, buy <number>\n");
}
init(){
 
/*   if(!present("thief guild", this_player())) {
      write("You are not a Thief...Leave us!\n");
      move_object(this_player(),"room/church");
      return 1;
   }*/
    add_action("east","east");
    add_action("west","west");
    add_action("list", "list");
}
sell(str){
int SALE;
object ob;
string a;
if(!str){return 0;}
sscanf(str, "%s",a);
ob = present(a, this_player());
if(!str){
	write("sell what?\n");
	return 1;
	}
if (!ob || !call_other(ob, "id", "fonymoney")){
write("sorry we dont buy those here\n");
return 1;
}
else {
	SALE = (5*(ob->query_value()*2)) /6;

	
	this_player()->add_money(SALE);
write_file("/players/catwoman/LOGS/sell_ruby",this_player()->query_name()+" sold a ruby. "+ctime(time())+"\n");
	destruct(ob);
	write("ok\n");
	return 1;
	}
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
     write("1. rubys ................5000 coins\n");
     write("11. A takeout menu from the revenge shop sold out\n");
     write("Please buy by the numbers.\n\n");
     write("What would you like to buy?");
     input_to("buy");
     return 1;
}

buy(str){
me = this_player();
     if(str == "1"){
       item = clone_object("players/catwoman/obj/ruby");
       check();
write_file("/players/catwoman/LOGS/ruby_buy",me->query_name()+" bought a ruby. "+ctime(time())+"\n");
       return 1;
     }
     if(str == "11") {
item = clone_object("players/catwoman/obj/menu");
check();
write_file("/players/catwoman/shop_log",me->query_name()+" bought a menu.\n");
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
   "east#players/catwoman/hall");
   return 1;
}
west(){
call_other(this_player(), "move_player",
   "west#players/catwoman/city/44");
   return 1;
}
realm() {return "NT";}
