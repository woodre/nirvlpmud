int cmd_pee(string str)
{
  object c;
/* temp */
if ((string)this_player()->query_real_name() == "ew"){
"/players/earwax/lib/crap.c"->reset(0);
return 1;
}
  if(!str) return (write("Pee on what?\n"), 1);

  if(!(c = present(str, this_player())) &&
    !(c = present(str, environment(this_player())))) {
    write("You don't see \""+str+"\".\n");
    return 1;
  }

  if(!this_player()->query_soaked()) {
    write("You're too thirsty to pee!\n");
    return 1;
  }

  if(!present("pee_obj", c)) move_object(clone_object("/obj/verte/junk/pee_obj"), c);
write("You pee on "+(string)call_other(c,(living(c)?"query_name":"short"))+".\n");
say((string)this_player()->query_name()+" pees on "+(string)call_other(c,(living(c)?"query_name":"short"))+".\n", c);
  tell_object(c, (string)this_player()->query_name()+" peed on you!\n");
  return 1;
}
