inherit "obj/monster";

reset(arg) {
  ::reset(arg);

	set_name("will");
	set_alias("william");
        set_short("Will");
        set_long(
"This is Will.  He has this thing, he like to drink.  You notice he has\n"+
"a lot on him now, so go ahead, kill him and get your reward.\n");
        set_level(15);
	set_hp(238);
	set_wc(12);
	set_ac(8);
	set_chat_chance(60);
	load_chat("Will says: What the f*ck do you want.\n");
	load_chat("Will says: Sucks to be you.\n");
        set_heart_beat(1);
	set_a_chat_chance(30);
	load_a_chat("Will says: Oh really, think you're going to get this from me eh?\n");
}

heart_beat() {
  ::heart_beat();
  if(call_other(this_object(), "query_hp") < 50){
   command("drink tea", this_object());
  return;
}
}
