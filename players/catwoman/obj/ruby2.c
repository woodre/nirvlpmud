inherit "obj/treasure";
query_auto_load(){
	return("players/catwoman/obj/ruby:");
}

init() {
        add_action("present","present");
  ::init();
}

reset(arg) {
  set_alias("ruby");
  set_id("fonymoney");
  set_short("ruby");
  set_long("truly a treasure\n");
  set_value(2500);
  set_weight(1);

}


drop() {return 1;}
present(str){
object me;
object them;
	me = this_player();
	them = present(str, environment(me));
	if(!str){return 0;}
	move_object(this_object(),them);
	write("gift sent.\n");
	return 1;
}

