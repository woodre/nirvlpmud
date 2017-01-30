inherit "obj/treasure";
/*
query_auto_load(){
	return("players/catwoman/obj/ruby:");
}
*/

init() {
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

