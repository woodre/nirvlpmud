locate(str) {
object ob, ob2;
  if(Glevel < 2) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(!str)
    ob = str;
  else
    ob = find_player(str);
  if(!ob || !living(ob)) {
    write("Your mind grows foggy and unclear.\n");
    return 1;
  }
  if(ob->query_invis()) {
    write("Your mind grows foggy and unclear.\n");
    return 1;
  }
  if(ob->query_level() > 49) {
    write("You can not see where a wizard is.\n");
    return 1;
  }
  if(SP < 10) {
    write("You do not possess enough energy to ask Matry.\n");
    return 1;
  }
  write("You close your eyes and a vision comes to you. You see the environment of\n"
+ "\t\t\t-=:{ " +ob->query_name()+ " }:=-\n");
  say(Name+ " closes " +Pos+ " eyes and starts to mutter a few words.\n");
  call_other(environment(ob), "long", 0);
  ob2 = first_inventory(environment(ob));
  while(ob2) {
    if(ob2->short()) write(ob2->short() + "\n");
    ob2 = next_inventory(ob2);
  }
  Ssp(10);
  Gain(EXP20);
  guildsave();
  return 1;
}

peace() {
object ob;
  ob = Me->query_attack();
  if(!ob) {
    write("You are not being attacked.\n");
    return 1;
  }
  if(Glevel < 3) {
    write("You are not worthy enough to ask Matry to bring peace.\n");
    return 1;
  }
  if(SP < 10) {
    write("You do not possess enough energy to ask Matry.\n");
    return 1;
  }
  write("Your goodness overwhelms your opponent, causing "+
    ob->query_objective()+" to stop fighting.\n");
  say(Name+"'s goodness overwhelms "+Pos+" enemy, causing " +
    ob->query_objective()+ " to stop fighting.\n", ob);
  tell_object(ob, Name+"'s goodness overwhelms you, causing your to top fighting.\n");
  ob->stop_fight();
  Me->stop_fight();
  Ssp(10);
  Gain(EXP20A);
  guildsave();
  return 1;
}

entrall() {
object ob;
ob = first_inventory(environment(this_player()));
  if(Glevel < 9) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(SP < 30) {
    write("You do not possess enough energy to ask Matry.\n");
    return 1;
  }
while(ob) {
  if(living(ob)) {
    if(ob->query_attack()) {
      (ob->query_attack())->stop_fight();
       ob->stop_fight();
    }
  }
ob=next_inventory(ob);
}
  write("You call to Matry and ask that there be peace.\n");
  say(Name+" calls to Matry and ask that there be peace.\n");
  Ssp(30);
  Gain(EXP30);
  guildsave();
  return 1;
}


detect_align() {
object ob;
  if(SP < 10) {
    write("You do not possess enough magical energy to detect alignment.\n");
    return 1;
  }
  ob = first_inventory(environment(Me));
  while(ob) {
 if(ob->query_alignment() > 50) write(ob->query_name()+" is good.\n");
    else
 if(ob->query_alignment() < -50) write(ob->query_name()+" is evil.\n");
    else
    write(ob->query_name()+ " has no alignment or it is neutral.\n");
    ob = next_inventory(ob);
  }
  Ssp(10);
  Gain(EXP10);
  return 1;
}

entangle(str) {
object ob, vine;
  if(!str) {
    write("Entangle who or what?\n");
    return 1;
  }
  if(Glevel < 7) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(SP < 20) {
    write("You do not possess enough magical energy to cast entangle.\n");
    return 1;
  }
  ob = present(lower_case(str), environment(Me));
  if(!ob || !living(ob)) {
    write("Entangle who?\n");
    return 1;
  }
  if(ob->query_level() > 19) {
    write("You can not entangle wizards.\n");
    return 1;
  }
  write("You entangle " +ob->query_name()+ "!!!\n");
  tell_object(ob, Name+" has entangled you!!\n");
  say(Name +" has entangled "+ob->query_name()+".\n", ob);
  vine = clone_object("players/nightshade/guild/obj/entangle");
  vine->set_spell_level(Glevel+Faith+ 5);
  move_object(vine, ob);
  Ssp(20);
  Gain(EXP30);
  return 1;
}

dispell(str) {
object ob, vine;
  if(!str) {
    write("Dispell magic on who?\n");
    return 1;
  }
  if(Glevel < 6) {
    write("You are not worthy enough to as Matry.\n");
    return 1;
  }
  if(SP < 10) {
    write("You do not possess enough magical energy to dispell magic.\n");
    return 1;
  }
  ob = present(str, environment(Me));
  if(!ob || !living(ob)) {
    write("No one here by that name.\n");
    return 1;
  }
  vine = present("MAGIC", ob);
  if(!vine) {
    write(ob->query_name()+" is not magically enchanted.\n");
    return 1;
  }
  if((vine->query_spell_level() - 2) > (Glevel+Faith+5)) {
    write("You can not dispell that magic. It's level is too high.\n");
    return 1;
  }
  write("You dispell the magical enchantment of "+ob->query_name()+".\n");
  say(Name+" dispells the magical enchantment of "+ob->query_name()+".\n", ob);
  tell_object(ob,Name+" casts a dispell magic on you.\n");
  destruct(vine);
  Gain((Glevel * 5)+(Faith * 5));
  Ssp(10);
  return 1;
}

silence(str) {
object ob, magic;
  if(!str) {
    write("Silence who?\n");
    return 1;
  }
  ob = present(str, environment(Me));
  if(!ob || !living(ob)) {
    write("No one here by that name.\n");
    return 1;
  }
  if(Glevel < 4) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(SP < 20) {
    write("You do not possess enough magical energy to cast silence.\n");
    return 1;
  }
  if(ob->query_level() > 49) {
    write("You can not silence a wizard!\n");
    return 1;
  }
  magic = clone_object("players/nightshade/guild/obj/silence");
  magic->set_spell_level(Glevel+Faith+5);
  move_object(magic, ob);
  write("You silence "+ob->query_name()+".\n");
  say(Name+" casts a silence spell on "+ob->query_name()+".\n", ob);
  tell_object(ob,Name+" casts a silence spell on you.\n");
  Ssp(20);
  Gain(EXP30);
  return 1;
}

/*
curse(str) {
object ob;
int wc, ac;
  if(!str) {
    write("Curse which monster?\n");
    return 1;
  }
  ob = present(str, environment(Me));
  if(!ob || !living(ob)) {
    write("No monster here by that name.\n");
    return 1;
  }
  if(!ob->query_npc()) {
    write("You can not curse players.\n");
    return 1;
  }
  if(SP < 30) {
    write("You do not possess enough magical energy to curse anyone.\n");
    return 1;
  }
  if(Glevel < 5) {
    write("You are not high enough level to cast curse.\n");
    return 1;
  }
  if(ob->query_cursed()) {
    write("The monster is already cused.\n");
    return 1;
  }
  ac = ob->query_ac();
  wc = ob->query_wc();
  write("You curse "+ob->query_name()+"!!!\n");
  say(Name+" curses "+ob->query_name()+"!!!\n");
  ob->set_wc(wc-2);
  ob->set_ac(ac-1);
  Ssp(30);
  Gain((Glevel*2)+(Honor*10));
  return 1;
}
*/

/*********************************************************8
pass_trace(str) {
  if(!str) {
    write("Pass with out trace in which direction?\n");
    return 1;
  }
  if(SP < 5) {
    write("You do not possess enough magical energy to pass with out trace.\n");
    return 1;
  }
  if(Glevel < 5) {
    write("You are not high enough level to pass with out trace.\n");
    return 1;
  }
  if(str == "n" || str == "s" || str == "e" || str == "w" ||
     str == "ne" || str == "nw" || str == "se" || str == "sw" ||
     str == "u" || str == "d" || str == "enter" || str =="out" ||
     str == "in" || str == "exit" || str == "leave" ) {
  Me->invis2();
    if(!command(str, Me)) {

      Me->vis2();
      return 1;
    }
    Me->vis2();
    Ssp(5);
    Gain(Glevel);
    return 1;
  }
  write("That is not a valid direction.\n");
  return 1;
}
***********************************************************/

know_alignment(str) {
object ob;
int ali;
string what;
  if(Glevel < 8) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(SP < 20) {
    write("You do not possess enough enough energy to ask Matry.\n");
    return 1;
  }
  if(!str)
    ob = str;
  else
    ob = present(lower_case(str), Env(Me));
  if(!ob || !living(ob)) {
    write("Who's alignment would you like to know?\n");
    return 1;
  }
  ali = ob->query_alignment();
  if(ali > 10000) what = "God like";
  else if(ali > 5000) what = "Heaven like";
  else if(ali > 1000) what = "Saintly";
  else if(ali > 500)  what = "Good";
  else if(ali > 100)  what = "Kind";
  else if(ali > 50)   what = "Nice";
  else if(ali > 0)    what = "Neutral good";
  else if(ali = 0)    what = "True neutral";
  else if(ali < -50)  what = "Neutral evil";
  else if(ali < -100)  what = "Naughty";
  else if(ali < -500) what = "Bad";
  else if(ali < -1000) what = "Evil";
  else if(ali < -5000)what = "Demonic";
  else if(ali < -10000)what = "Hell like";
  else what = "Devil like";
  write(ob->query_name()+" is "+what+".\n");
  Ssp(20);
  Gain(EXP20);
  return 1;
}

locate_object(str) {
object list, ob;
string name, name2;
string file;
int i;

  if(Glevel < 11) {
    write("You are not worthy enough to ask Matry to bring peace.\n");
    return 1;
  }
  if(SP < 30) {
    write("You do not possess enough energy to ask Matry.\n");
    return 1;
  }
  if(!str) {
    write("Locate2 <object> \n");
    return 1;
  }
  write("Looking for " +str+ ".\n");
  list = users();
  while(i < sizeof(list)) {
    ob = present(str, list[i]);
    if(ob) {
      name2 = list[i]->query_name();
      name = list[i]->query_name();
      name = capitalize(name);
      name = name+extract("               ",0,15-strlen(name));
        if(name2 == "Someone") write("");
        else
        write(name+": " +ob->short()+ "\n");
    }
    i ++;
  }
  Gain(EXP30);
  Ssp(30);
  return 1;
}



