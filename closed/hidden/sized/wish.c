
id(str) { return str == "lamp"; }
reset () {}
short() {
	return "A magical lamp";
}
long() {
write("A lamp with great powers is in your possession! To use just\n" +
"type wish <#>. Type wishlist to get a list of items you can wish for.\n");
}
init() {
	add_action("wish","wish");
	add_action("wishlist","wishlist");
	}
wish(str){
	string wished, item_name;
	object item;
	if(str=="7") {
	this_player()->add_money(5000);
	write("You wish for coins and they magically appeared!\n");
	say(capitalize(this_player()->query_name())+ "wished for coins and they magically appeared!\n");
	destruct(this_object());
	return 1;
	}
	else if(str == "1"){wished = "/players/dragnar/heal/auto_heal.c"; item_name = "healer"; }
	else if(str == "2"){wished = "/players/dragnar/heal/sisco.c"; item_name = "sisco";}
else if(str == "3") {wished = "/players/dragnar/heal/firewater.c"; item_name = "firewater";}
	else if(str == "4") {wished="/players/dragnar/weapons/sword.c"; item_name = "katana";}
	else if(str == "5") {wished="/players/dragnar/weapons/launcher.c"; item_name = "launcher"; }
	else if(str == "6") {wished="/players/dragnar/armor/suit2.c"; item_name = "suit"; }
	else {return 1;}
write("You wish for "+item_name+" and it magically appears!\n");
	say(capitalize(this_player()->query_real_name())+ " just wished for "+item_name+" and it magically appeared!\n");
	item=clone_object(wished);
	move_object(item, this_player());
	destruct(this_object());
	return 1;
}
wishlist() {
write("				ITEMS ON WISH LIST\n" +
"1.  Magic Healer\n" +
"2.  Picher of sisco\n" +
"3.  Bottle of firewater\n" +
"4.  Ninja Katana\n" +
"5.  Missle launcher\n" +
"6.  Black ninja suit\n" +
"7.  Gold coins\n");
return 1;
}
get() { return 1; }
query_weight() { return 0; }
query_value() { return 5000; }
query_save_flag(){return 1;}
