inherit "obj/treasure";

int y;  /* y = charges */

string query_charge_sdesc(){
  if(y > 1) return ""+y+" charges");
  else if(y == 1) return ""+num_charges+" charge");
  else return "no charges");
}

string query_charge_ldesc(){
  if(y > 1) return "The wand has "+y+" charges.";
  else if(y == 0) return "The wand has "+y+" charge.";
  else return "The wand has no charges";
}

void reset(int arg){
  if(arg) return;
  set_name("wand");
  set_alias("teakwood wand");
  set_short("Teakwood wand with "+query_charge_sdesc()+"");
  set_long("This appears to be some sort of magical wand!\n"+
    "Maybe you could zap wand at someone...\n"+
    query_charge_ldesc()+"\n");
  set_weight(1);
  set_value(4100);
  set_save_flag(0);
  y = 1000;
}

void init(){
  ::init();
  add_action("zap","zap");
  add_action("zap","point");
}

int zap(string arg){
  object targ;
  string who, what, var;
  if(!arg || sscanf(arg, "%s %s %s", what, var, who) != 3) return 0;
  if(what != "wand" || var != "at") return 0;
  targ = present(who, environment(this_player()));
  if(!targ){
    write("I'm sorry but that target is not visible.\n");
    return 1;
  }
  if(targ->query_npc() != 1){
    write("The wand cannot zap players..\n");
    return 1;
  }
  targ->attack_object(this_player());
  targ->hit_player(500+random(50));
  write("\n");
  write(who->query_name()) + " is engulfed in a devistating ball of fire!\n");
  write("\n");
  say(capitalize(this_player()->query_real_name())+
    " waves a teakwood wand and "+who->query_name()+
    "\nburts into flame!\n\n");
  y = y-1;
  if(y > 0) write("You now have " + var + " charges left.\n");
  else write("Your wand splinters from overuse.\n");
  return 1;
}
