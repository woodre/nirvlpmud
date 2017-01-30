inherit "obj/weapon";

init() {
  ::init();
}

reset(arg) {
  set_name("chisel");
  set_class(15);
  set_alias("chisel");
  set_id("chisel");
  set_alt_name("chisel");
  set_short("A cold chisel");
  set_long("made for carving stone\n");
  set_value(6000);
  set_weight(1);
    set_hit_func(this_object());
}
/*
drop(){
	write("The chisel falls and breaks into a zillion pieces.\n");
	destruct(this_object());
	return 1;
	}*/
weapon_hit(target) {
	string align;
	if(call_other(target,"id","stonedragon")){
	write("CRUNCH!!!!!\n");
	return 80;
	}
	return 0;
}
query_save_flag() {return 1;}



