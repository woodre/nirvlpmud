inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("bug");
  set_short("A tiny bug");
  set_long(
"This is a tiny black bug.  It has four little legs, two\n"+
"bulging little eyes, and a wide, cavernous mouth.  It also\n"+
"has two little wings on the top of its body, allowing it to\n"+
"fly around.  It has a hard little body.\n");
  set_race("insect");
  set_gender("creature");
  set_level(1);
  set_ac(2);
  set_wc(18+random(3));
  set_hp(50);
  set_chance(10);
  set_spell_dam(10+random(4));
  set_spell_mess1("A bug flys around the room!\n");
  set_spell_mess2("A bug bites your flesh!\n");
  call_out("dest", 15+random(11));
} }
/*
void init()
{
	::init();
	add_action("squash_cmd", "squash");
	add_action("squash_cmd", "crush");
}
*/
dest()
{
  if(environment())
  {
	tell_room(environment(),
		"A tiny bug flys away...\n");
    destruct(this_object());
  }
}

squash_cmd(str)
{
  if(str != "bug") return 0;
  tell_room(environment(this_object()), this_player()->query_name()+
	  " cruely squashes a tiny bug.\n", ({ this_player() }));
  write("You cruely squash a tiny bug.\n");
  destruct(this_object());
  return 1;
}
