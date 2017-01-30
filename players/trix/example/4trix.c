inherit "room/room";
object knight;
reset(arg) {
	knight=clone_object("/players/mathiast/monsters/knights/blue3.c");
	move_object(knight,this_object());
if (!arg) {
	set_light(1);
	short_desc="Niniva's market";
	long_desc="	You have entered the market area of Niniva.  There is\n"+
	"much activity going on here.  Farmers come here to sell their crops,\n"+
	"so you might be able to find some supplies to buy here.\n"+
	"You might want to 'browse' the market in order to find out what\n"+
	"is for sale here.\n";
dest_dir = ({
	"/players/mathiast/rooms/town/road1.c","south",
	"/players/mathiast/rooms/town/square.c","north",
	});
}
}
init() {
	::init();
	add_action("browse","browse");
	add_action("haggle","haggle");
	}
browse(){
write("\nThings in the market today inclue:\n"+
	"\nAn apple	Some berries\n"+
	"Beef Jerky	Apple cider\n"+
	"Grape juice	Goat milk\n"+
	"Wine		Ale\n"+
	"Beer		A seed\n"+
	"Herbal tea	A lemon drop\n"+"\n"+
"You can haggle for any of these items.  (Type: haggle <item>)\n\n");
return 1;
}
haggle(str){
object item;
string name;
int value, cost;
if(!str) { write("Huh?\n"); return 1; }
if (str == "apple" || str == "An apple") {
	name = str;
	item = clone_object("/players/mathiast/items/apple.c");
	value = 500 + random(100);
}
else if (str == "berries" || str == "Some berries" || str == "berry"){
	name = str;
	item = clone_object("/players/mathiast/items/berries.c");
	value = 300 + random(100);
}
else if (str == "jerky" || str == "beef jerky"){
	name = str;
	item = clone_object("/players/mathiast/items/jerky.c");
	value = 400 + random(100);
}
else if (str == "wine"){
	name = str;
	item = clone_object("/player/mathiast/items/wine.c");
	value = 500 + random(110);
}
else if (str == "ale"){
	name = str;
	item = clone_object("/players/mathiast/items/ale.c");
	value = 400 + random(100);
}
else if( str == "beer"){
	name = str;
	item = clone_object("/players/mathiast/items/beer.c");
	value = 300 + random(100);
}
else if (str == "cider"){
	name = str;
	item = clone_object("/players/mathiast/items/cider.c");
	value = 500 + random(100);
}
else if (str == "juice" || str == "grape juice"){
	name = str;
	item = clone_object("/players/mathiast/items/juice.c");
	value = 300 + random (100);
}
else if (str == "milk" || "goat milk"){
	name = str;
	item = clone_object("/players/mathiast/items/milk.c");
	value = 400 + random(100);
}
else if (str == "seed"){
	name = str;
	item = clone_object("/players/mathiast/items/seed.c");
	value = 250 + random(50);
}
else if (str == "drop" || str == "lemon drop"){
	name = str;
	item = clone_object("/players/mathiast/items/drop.c");
	value = 30 + random(20);
}
else if (str == "tea" || str == "herbal tea"){
	name = str;
	item = clone_object("/players/mathiast/items/tea.c");
	value = 10000;
} else { write("Haggle for what?\n"); return 1;}
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
write("You settle on a price of " + value + " gold coins for a " + name + ".\n");
say(call_other(this_player(), "query_name", 0) + " buys a " + name + ".\n");
return 1;
}
