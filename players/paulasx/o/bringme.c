inherit "obj/treasure";
object a;

reset(arg)
{
  if (arg) return;
  set_id("transer");
  set_short("Ultratranser");
  set_long("This is the ultratranser.\n"+
   "Usage : Trans [plyr/monster]\n"+
  "         Trans (will give you a list -- try it!)\n");
  set_weight(0);
  set_value(0);
}

init()
{
   a = users();
   add_action("bring_me", "Trans");
}



bring_me(str) {
  int i;

  if (str) {
  object ob;
  ob = find_living(str);
  if(!ob) {
     write("Could not locate '"+str+"'.\n");
     return 1;
  }

  move_object(ob, environment(this_player()));
  write("Ok.\n");
  return 1;
}


  for (i=0; i<sizeof(a); i++) {
  if (i<10)
     write("  "+i+": "+a[i]->query_real_name()+"\n");
  else
     write(" " +i+": "+a[i]->query_real_name()+"\n");
  }

  write("Trans > ");

  input_to("lookup");
  return 1;
}


lookup(t) {
  int num;

  sscanf(t, "%d", num);

  if (num>sizeof(a) || num<0) {
  write("Index out of range.\n");
  return 1;
  }

  move_object(a[num], environment(this_player()));
  write("Ok.\n");
return 1;
}
