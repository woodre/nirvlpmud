id(str) { return str == "co"; }

short() { return "Co"; }

get()
{ return 1;
}

init()
{
	add_action("co","co");
}

co()
{
 object ob;

 if(!(ob = environment(environment(this_player()))))
 {
  write("This isn't going to work.\n");
  return 1;
 }

 move_object(this_player(), ob);
 this_player()->look();
 return 1;
}

