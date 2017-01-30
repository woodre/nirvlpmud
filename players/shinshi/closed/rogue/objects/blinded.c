inherit "/obj/treasure.c";
#define MAX_BEATS 10

int beats;
int damage;

id(str) { return str=="blinded_biatch"; }

drop() { return 1; }

init(){
	::init();
	
	add_action("look", "look");
	add_action("look", "examine");
	add_action("look", "l");
	add_action("look", "who");
	add_action("look", "who2");
	add_action("look", "who3");
	add_action("look", "who4");
	add_action("look", "who5");
}

look(){
	write("You are blinded and cannot see!\n");
	return 1;
}

start_it()
{
  set_heart_beat(1);
}

heart_beat()
{
  object ob;
  
  ob = environment();
  if(++beats == MAX_BEATS)
  {
    tell_object(ob,
      "The blinding powder wears off.\n");
    return destruct(this_object());
  }
}