status is_lit;

long()
{
  if(is_lit)
  {
	write("The werelite is a radiant sphere of mystic light.\n");
	write("Its soft glow illuminates the area.\n");
	write("The magical sphere can be dimmed.\n");
  }
  else
  {
	write("The werelite is a magical lightsource.\n");
	write("It is currently dimmed.  You can activate\n");
	write("There werelite by rubbing it.\n");
  }
  return;
}

reset(arg) {
  if (arg) return;
  is_lit = 0;
}

id(str) {
  return str == "werelite" || str == "lite" || str == "light";
}

query_weight() { return 0; }
query_value(){ return 0; }
get() { return 1; }

short()
{
  if(is_lit) return "A werelite (glowing)";
  else return "A werelite (dark)";
}

init()
{
  add_action("light","rub");
  add_action("dim","dim");
  add_action("drop_object","drop");
}

light(str)
{
  if(str == "werelite" || str == "lite" || str == "light")
  {
	if(is_lit)
	{
		write("The werelite is already lit.\n");
		return 1;
	}

	is_lit = 1;
	write("You rub the werelite and it radiates a soft glowing light!\n");
	say(capitalize(this_player()->query_name())+
		" rubs a werelite and it radiates a soft glowing light!\n");
	set_light(3);
	return 1;
  }
}

dim(str)
{
  if(str == "werelite" || str == "lite" || str == "light")
  {
	if(!is_lit)
	{
		write("The werelite is not lit.\n");
		return 1;
	}

	write("You wave your hand of the werelite and it winks out.\n");
	say(capitalize(this_player()->query_name())+
		" waves a hand over the werelite and it winks out.\n");
	is_lit = 0;
	set_light(-1);
	return 1;
  }
}

drop_object(str)
{
  if(str == "all")
  {
	drop_object("werelite");
	return 0;
  }

  if (!str || !id(str))
	return 0;

  write("The werelite disappears before it touches the ground.\n");
  say(capitalize(this_player()->query_name())+
	" drops a werelite and it disappears.\n"); 
  destruct(this_object());
  return 1;

}


