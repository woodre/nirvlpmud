inherit "room/room";
object machine;
reset(arg) {
   if(!arg) {
	machine=clone_object("/players/dragnar/zap.c");
	move_object(machine, this_object());
      set_light(1);
      short_desc="Wastelands";
	long_desc="There is a great deal of rubble laying around here.  Pieces of old machines\n"+
"are scattered everywhere over the glass-like surface of the land.  Only\n"+
"one seems to be in one peace.\n",
      dest_dir = ({
	"/players/dragnar/rooms/entrance.c","north",
	});
}
}
init() {
   ::init();
   add_action("list","list");
   add_action("buy","buy");
}
list(){
   write("\nThings that are available for purchase:\n"+
      "1. magic healer                 30000 coins\n" +
      "2. pack of healing		10000 coins\n"+
      "3. pitcher of sisco             10000 coins\n" +
      "4. bottle of firewater          9000 coins\n" +
      "5. 12 pack of bud               4800 coins\n" +
      "6. 12 pack of beast             3600 coins\n" +
      "7. bottle of vodka              2500 coins\n" +
      "8. hotdog                       4800 coins\n" +
      "9. bottle of snapple            4000 coins\n" +
      "10. hamburger                    1000 coins\n" +
      "11. double burger                1400 coins\n" +
      "12. thermos of coffee            4000 coins\n" +
      "13. pack of speed pills          3000 coins\n" +
      "14. bag of pretzels              3500 coins\n" +
	"15. can of beer\t\t\t500 coins\n"+
	"16. list of items		10 coins\n\n"+
      "Just buy an item.  \(Type: buy <#>\)\n\n");
   return 1;
}
buy(str){
   object item;
   string name;
   int value, cost;
   if(!str) { write("Huh?\n"); return 1; }
   else if (str == "healer" || str == "1"){
      name = str;
      item = clone_object("/players/dragnar/heal/auto_heal.c");
      value = 30000;
   }
   else if (str =="pack" || str =="2"){
      name=str;
      item=clone_object("/players/dragnar/heal/pack.c");
      value=10000;
   }
   else if (str == "sisco" || str== "3") {
      name = str;
      item = clone_object("/players/dragnar/heal/sisco.c");
      value = 10000;
   }
   else if (str == "firewater" || str == "4") {
      name = str;
      item = clone_object("/players/dragnar/heal/firewater.c");
      value = 9000;
   }
   else if (str == "bud" || str == "5"){
      name = str;
      item = clone_object("/players/dragnar/heal/bud.c");
      value = 4800;
   }
	else if(str=="beast" || str=="6"){
      name = str;
      item = clone_object("/players/dragnar/heal/beast.c");
      value = 3600;
   }
	else if(str == "hotdog" || str=="8"){
      name=str;
      item=clone_object("/players/dragnar/heal/hotdog.c");
      value=4800;
   }
	else if(str=="snapple" || str=="9"){
      name=str;
      item=clone_object("/players/dragnar/heal/snapple.c");
      value=4000;
   }
	else if(str=="hamburger" || str=="10"){
      name=str;
      item=clone_object("/players/dragnar/heal/burger.c");
      value=1000;
   }
	else if(str=="double burger" || str=="11"){
      name=str;
      item=clone_object("/players/dragnar/heal/dbburger.c");
      value=1400;
   }
	else if(str=="coffee" || str=="12"){
      name=str;
      item=clone_object("players/dragnar/heal/coffee.c");
      value=4000;
   }
	else if(str=="speed" || str=="13"){
      name=str;
      item=clone_object("/players/dragnar/heal/speed.c");
      value=3000;
   }
   else if(str =="pretzel" || str =="14"){
      name=str;
      item=clone_object("/players/dragnar/heal/pretzel.c");
      value=3500;
   }
   else if(str =="beer" || str =="can" || str=="15"){
      name=str;
      item=clone_object("/players/dragnar/heal/bud2.c");
      value=500;
   }
	else if(str=="vodka" || str=="7"){
      name=str;
      item=clone_object("/players/dragnar/heal/vodka.c");
      value=2500;
}
	else if(str=="list" || str=="16"){
	name=str;
	item=clone_object("/players/dragnar/heal/list.c");
	value=10;
   } else { write("What?\n"); return 1;}
   if (call_other(this_player(), "query_money", 0) < value) {
      write("That costs " + value + " gold coins, which you don't have.\n");
      destruct(item); return 1;
   }
   
   if (!call_other(this_player(), "add_weight", 1)){
      write("You can't carry that much!\n"); 
      destruct(item); return 1;
   }
   move_object(item,this_player());
   call_other(this_player(), "add_money", - value);
   write("You put " + value + " gold coins into the machine and it gives you your item.\n");
   say(capitalize(this_player()->query_name())+" puts some coins into the machine and makes a purchase.\n");
   return 1;
}
