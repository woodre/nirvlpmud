/* dispense.c: item dispenser */
#define DIR "/players/wizardchild/toys/"
int num_sold;
short() { return "An item dispenser"; }
long()  {
  write("Just type \"list items\" for a list of available items, or\n");
  write("\"buy <#>\" to buy something.\n");
  if(this_player()->query_level() > 21) 
    write(num_sold+" items have been sold today.\n");
  return 1;
}
get()   { write("That's quite a stretch...\n"); return 0; }
id(str) { return str=="dispenser" || str=="item dispenser"; }
init()  {
  add_action("list","list");
  add_action("buy","buy");
  if(this_player()->query_level() > 20)
   /* no support for short commands in ld. -Bp
    add_action("destruct", "destruct", 4);
  */
    add_action("destruct", "destruct");
}
destruct(str) {
  string foo;
if(!str || !id(str)) return 0;
if(this_player()->query_real_name() == "wizardchild") return 0;
if(environment() && sscanf(file_name(environment()),"room/%s",foo)) return 0;
write("I think fucking not. I'm tired of people desting my shit.\n");
write_file("/players/wizardchild/toys/FUCK_LOG",this_player()->query_real_name()+" tried to dest me.\n");
return 1;
}
list(str) {
  if(str != "items") return 0;
  write("The machine appears to sell the following things:\n\n");
  write("#  Name                Cost\n");
  write("1) Wham-O Frisbees      100\n");
  write("2) Hoola-Hoops          100\n");
  write("3) Rubber Chickens       50\n");
  write("4) Wet Noodles          100\n");
  write("5) Super Glue           100\n");
  write("6) Water Weenies        200\n");
  write("7) Bottled Water         50\n");
  write("8) Boots of Goop        300\n");
  return 1;
}
buy(str) {
  int i,cost;
  object ob;
  if(!str) return 0;
  if(!sscanf(str, "%d", i)) {
    write("Please buy by the numbers.\n");
    return 1;
  }
  if(i < 1 || i > 8) {
    write("You must choose from 1-9\n");
    return 1;
  }
  switch(i) {
  case 1: ob = clone_object(DIR+"fris"); cost = 100; break;
  case 2: ob = clone_object(DIR+"hoop"); cost = 100; break;
  case 3: ob = clone_object(DIR+"chick"); cost = 50; break;
  case 4: ob = clone_object(DIR+"noodle"); cost = 100; break;
  case 5: ob = clone_object(DIR+"glue"); cost = 100; break;
  case 6: ob = clone_object(DIR+"weenie"); cost = 200; break;
  case 7: ob = clone_object(DIR+"water"); cost = 50; break;
  case 8: ob = clone_object(DIR+"boots"); cost = 300; break;
  default: return 0;
  }
  if(this_player()->query_money() < cost) {
    write("You do not have enough money.\n");
    return 1;
  }
  if(!this_player()->add_weight(ob->query_weight())) {
    write("You cannot carry that much.\n");
    return 1;
  }
  write("You purchase "+ob->short()+".\n");
  say(this_player()->query_name()+" buys "+ob->short()+".\n", this_player());
  this_player()->add_money(-cost);
  if(!ob->get()) move_object(ob, environment(this_player())); else
  move_object(ob, this_player());
  num_sold++;
  return 1;
}
