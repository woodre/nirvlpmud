inherit "obj/armor";
reset(arg) {
  if(!arg) {
    set_ac(1);
  set_value(2500);
  set_type("cloak");
  set_weight(1);
  set_name("cloak of the mystics");
  set_short("Cloak of the mystics");
  set_long("A long magical cloak.  It is very light and you\n"
+"can feel the magical enrgies flowing from the cloak into\n"
+"your body.  It has the following spells:\n"
+"NAME                        EFFECT                                COST\n"
+" Vent <person> <line>      Makes a person say a certain line       40\n"
+" Lightning <target>        Does (level*random 1-6) damage          40\n"
+" Teleport <item> <person>  Teleport an item to a person   50+10*weight\n"
+" **Teleport is for wizards only.\n");
  }
}
    init() {
  add_action("lightning","lightning");
  add_action("vent","vent");
  add_action("teleport","teleport");
}

lighning(str) {
    object ob;
  if(!str||str=="") {
    write("What?\n");
  return 1;
  }
    ob = present(str,environment(this_player()));
    if (!ob||living(ob)) {
  write("Who do you want to cast the lighning bolt on?\n");
  return 1;
  }
    if (call_other(this_player(),"query_spell_points")<40) {
  write("You don't have the strength to cast a lighning bolt!\n");
  return 1;
  }
  write("A massive bolt of blue lightning blasts from your\n"
  +"fingertips and sears "+capitalize(str)+"!\n");
  call_other(ob,"add_hit_point",-(random(6)*call_other(this_player(),"query_level")));
  say(call_other(this_player(),"query_name")+ "casts a lighning bolt.\n");
  if (call_other(this_player(),"query_level")<21) {
     call_other(this_player(),"restore_spell_points",-40);
  }
  return 1;
  }

vent(str) {
    int fail;
  string str1,dude;
    if (call_other(this_player(),"query_spell_points")<1) {
  write("You don't have enough spell points!\n");
  return 1;
  }
  sscanf(str,"%s %s",str1,dude);
  if (!present(str1,environment(this_player()))) {
  write("That person is not here!\n");
  return 1;
  }
  tell_room(environment(this_player()),capitalize(str1)+" says: "+dude+"\n");
  if (call_other(this_player(),"query_level")<21) {
  call_other(this_player(),"restore_spell_points",-40);
  }
  write("You attempt to cast the spell...\n");
    fail=random(100);
     if(fail<1) {
  say(call_other(this_player(),"query_name")+" screws up a ventriloquism spell! You see him speak!\n");
  write("You feel the magic begin to slip and go wrong!\n");
  }
  return 1;
  }

teleport(str) {
  int obweight;
  string str1,dude;
  sscanf(str,"%s %s",str1,dude);
  obweight = call_other(present(str1),"query_weight");
  if (call_other(this_player(),"query_spell_points")<(obweight*10)+50) {
  write("You can't seem to get that spell to work.\n");
  return 1;
  }
    if (call_other(this_player(),"query_level")<21) {
  write("Only wizards can use that function.\n");
  return 1;
  }
  move_object(present(str1,this_player()),find_living(dude));
  say(call_other(this_player(),"query_name")+" sends his "+str1+" to "+
    capitalize(dude)+".\n");
  write("You send the "+str1+" to "+capitalize(dude)+".\n");
  tell_object(find_player(dude),call_other(this_player(),"query_name")+
  " sent you a "+str1+".\n");
  return 1;
}
