inherit "obj/weapon";
#define ME capitalize(this_player()->query_name())
#define IT capitalize(attacker->query_name())

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_short("Zesline");
  set_long(
  "A long sharp thorn from the hardened shell of Ymyaze the guardian,\n"+
  "Zesline makes a perfect implement of destruction.  Its long jagged\n"+
  "blade gleams with sinister powers.\n");
  set_name("Zesline");
  set_alias("zesline");
  set_type("dagger");
  set_class(18);
  set_weight(2);
  set_value(10000);
  set_save_flag(1);
  set_hit_func(this_object());
}

init() {
  ::init();
  add_action("weaptest", "weaptest");
  add_action("weaptest2", "weaptest2");
  add_action("weaptest3", "weaptest3");
}

weaptest()
{
  if(this_player()->query_level() >= 21)
  {
	write("Weapon class is: "+class_of_weapon+"\n");
	return 1;
  }
}

weaptest2(str)
{
  int x;
  if(this_player()->query_level() >= 21)
  {
	sscanf(str, "%d", x);
	class_of_weapon = x;
	write("Weapon class is now: "+class_of_weapon+"\n");
	return 1;
  }
}

weaptest3(str)
{
  int x;
  if(this_player()->query_level() >= 21)
  {
	sscanf(str, "%d", x);
	set_class(x);
	write("Weapon class is now: "+query_class()+".\n");
	write("class_of_weapon: "+class_of_weapon+".\n");
	return 1;
  }
}


weapon_hit(attacker) {

  if(random(5)==0) tell_room(environment(this_player()),
  ME+" slices open a long jagged wound across his enemies chest!\n");
  else if(random(5)==1) tell_room(environment(this_player()),
  "Zesline snickers evily through the air.\n");
  else if(random(5)==2) tell_room(environment(this_player()),
  ME+" buries Zesline up to the hilt in "+IT+"'s body!\n");
  else if(random(5)==3) tell_room(environment(this_player()),
  ME+" shoves Zesline deep into "+IT+"'s gut and twists the knife cruelly!\n");
  else if(random(5)==4) tell_room(environment(this_player()),
  IT+" shies away from the sinister power of Zesline!\n");

  if(random(3)==0) return random(6);
  else return 0;
}

