inherit "obj/armor";

reset(arg) {
  if(arg) return;
  set_id("Black Rose Duelists Ring");
  set_alias("ring");
  set_short("Black Rose Duelists Ring");
  set_long(
"A finely built solid silver ring.  The dark soul of it's previous owner \n"+
"has darkened the ring.  It bears the Rose Seal as it's insignia.  This \n"+
"is the symbol of those who duel for the Rose Bride.\n");
  set_ac(1);
  set_type("ring");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(1100);
}

init() {
::init();
add_action("wear","wear");
}


wear(arg){
	if(environment()->is_player()){
		write("The Duelist Ring shatters when you try to wear it!\n");
		destruct(this_object());
	return 1;}
return 0;}



