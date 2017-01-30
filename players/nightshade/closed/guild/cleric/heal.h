can_heal() {
  if(heal_count < ((Glevel * 2) + 10)) return 1;
  else return 0;
}
heal_wait() {
  write("Matry does not answer your call at this time.\n");
  return 1;
}
offer(str) {
object ob;
  if(!str) { write("What ?\n"); return 1; }
  ob = present("corpse", Env(Me));
    if(!ob) { write("No corpse here.\n"); return 1; }
    write("You offer the corpse to Matry and feel healed as Matry blesses you.\n");
    say(Name+" offers the corpse to Matry.\n");
    destruct(ob);
    Gain(Glevel * 10);
    Boost(Glevel + random(10) + 5);
    return 1;
}

cure_light(str) {
object ob;
int am;
  if(!can_heal()) {
    heal_wait();
    return 1;
  }
  if(!str)
    ob = Me;
  else
    ob = present(lower_case(str), environment(Me));
  if(!ob || !living(ob)) {
    write("Who would you like to cure light wounds on?\n");
    return 1;
  }
  if(Mana < 20) {
    write("You do not possess enough healing energy.\n");
    return 1;
  }
  am = random(20) + 20 + (Faith * (random(5)));
  if(ob == Me) {
    am = random(15) + 20 + (Faith * (random(5)));
    write("You ask Matry to cure light wounds.\n");
    write("Matry grants you, your wish and heals you "+am+".\n");
    say(Name+" is slightly healed by Matry.\n");
    Gain(EXP20);
    Drain(20);
    ob->HEAL(am);
    heal_count++;
    return 1;
  }
  write("You ask Matry to cure "+ob->query_name()+"'s light wounds.\n");
  write("Matry hears your plea and heals for "+ob->query_name()+" "+am+".\n");
  say(Name+" asked Matry to heal"+ob->query_name()+
        "'s light wounds and was granted.\n", ob);
  tell_object(ob, Name+" asked Matry to heal your light wounds.\n");
  tell_object(ob, "Matry heals you "+am+" points.\n");
  Drain(20);
  Gain(EXP20);
  ob->HEAL(am);
  heal_count++;
  return 1;
}

cure_serious(str) {
object ob;
int am;
  if(Glevel < 8) {
    write("Matry says: You are not worthy enough to ask for such a spell.\n");
    return 1;
  }
  if(!can_heal()) {
    heal_wait();
    return 1;
  }
  if(!str)
    ob = Me;
  else
    ob = present(lower_case(str), environment(Me));
  if(!ob || !living(ob)) {
    write("Who would you like to cure serious wounds on?\n");
    return 1;
  }
  if(Mana < 40) {
    write("You do not possess enough healing energy.\n");
    return 1;
  }
  am = random(30) + 40 + (Faith * (random(5)));
  if(ob == Me) {
    am = random(20) + 40 + (Faith * (random(5)));
    write("You ask Matry to cure serious wounds.\n");
    write("Matry grants you, your wish and heals you "+am+".\n");
    say(Name+" is slightly healed by Matry.\n");
    Gain(EXP40);
    heal_count++;
    Drain(40);
    ob->HEAL(am);
    return 1;
  }
  write("You ask Matry to cure "+ob->query_name()+"'s serious wounds.\n");
  write("Matry hears your plea and heals for "+ob->query_name()+" "+am+".\n");
  say(Name+" asked Matry to heal"+ob->query_name()+
        "'s serious wounds and was granted.\n", ob);
  tell_object(ob, Name+" asked Matry to heal your serious wounds.\n");
  tell_object(ob, "Matry heals you "+am+" points.\n");
  Drain(40);
  Gain(EXP40);
  ob->HEAL(am);
  heal_count++;
  return 1;
}

cure_critical(str) {
object ob;
int am;
  if(Glevel < 10) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(!can_heal()) {
    heal_wait();
  return 1;
}
  if(!str)
    ob = Me;
  else
    ob = present(lower_case(str), environment(Me));
  if(!ob || !living(ob)) {
    write("Who would you like to cure critical wounds on?\n");
    return 1;
  }
  if(Mana < 60) {
    write("You do not possess enough healing energy.\n");
    return 1;
  }
  am = random(50) + 60 + (Faith *(random(5)));
  if(ob == Me) {
   am = random(40) + 60 + (Faith * (random(5)));
    write("You ask Matry to cure critical wounds.\n");
    write("Matry grants you, your wish and heals you "+am+".\n");
    say(Name+" is healed by Matry.\n");
    Gain(EXP40A);
    Drain(60);
    ob->heal_self(am);
    heal_count++;
    return 1;
  }
write("am='"+am+"'\n");
  write("You ask Matry to cure "+ob->query_name()+"'s critical wounds.\n");
  write("Matry hears your plea and heals for "+ob->query_name()+" "+am+".\n");
  say(Name+" asked Matry to heal"+ob->query_name()+
        "'s critical wounds and was granted.\n", ob);
  tell_object(ob, Name+" asked Matry to heal your critical wounds.\n");
  tell_object(ob, "Matry heals you "+am+" points.\n");
  Drain(60);
  Gain(EXP40A);
  ob->HEAL(am);
  heal_count++;
  return 1;
}

complete_heal(str) {
object ob;
int am;
  if(Glevel < 14) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(!can_heal()) {
    heal_wait();
    return 1;
  }
  if(!str)
    ob = Me;
  else
    ob = present(lower_case(str), environment(Me));
  if(!ob || !living(ob)) {
    write("Who would you like to heal?\n");
    return 1;
  }
  if(Mana < 100) {
    write("You do not possess enough healing energy.\n");
    return 1;
  }
  if(ob == Me) {
    write("You ask Matry to heal you.\n");
    write("Matry grants you, your wish and heals you fully.\n");
    say(Name+" is totally healed by Matry.\n");
    Gain(EXP40A);
    Drain(100);
    ob->HEAL(300);
    heal_count++;
    return 1;
  }
  write("You ask Matry to heal "+ob->query_name()+".\n");
  write("Matry hears your plea and heals "+ob->query_name()+".\n");
  say(Name+" asked Matry to heal"+ob->query_name()+
        " and was granted.\n", ob);
  tell_object(ob, Name+" asked Matry to heal you.\n");
  tell_object(ob, "Matry totally heals you.\n");
  Drain(100);
  Gain(EXP40A);
  ob->HEAL(300);
  heal_count++;
  return 1;
}


create(str) {
object bread, wine;
  if(Glevel < 5) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(!str) {
    write("Create food or drink?\n");
    return 1;
  }
  if(!can_heal()) {
    heal_wait();
    return 1;
  }
  if(str == "food") {
    if(Mana < 30) {
      write("You do not possess enough healing energy.\n");
      return 1;
    }
    write("You create a large loaf of bread.\n");
    say(Name+ " creates a large loaf of bread.\n");
  bread = clone_object("players/nightshade/closed/guild/obj/bread");
    bread->set_strength((Glevel * 2) + (Faith * 2));
    move_object(bread, Me);
    Drain(30);
    Gain(EXP30A);
    heal_count++;
    new_shield();
  return 1;
  }
  if(str == "drink") {
    if(Mana < 30) {
    write("You do not possess enough healing energy.\n");
    return 1;
  }
  write("You create a glass of wine.\n");
    say(Name+" creates a glass of wine.\n");
    wine = clone_object("players/nightshade/closed/guild/wine");
    wine->set_strength((Glevel * 2)+(Faith * 2));
    move_object(wine, Me);
    Drain(30);
    Gain(EXP30A);
    heal_count++;
    return 1;
  }
}

mend(str) {
object ob;
string who;
int am;
  if(!can_heal()) {
    heal_wait();
    return 1;
  }
  if(!str) {
    write("mend player amount\n");
    return 1;
  }
  if(Glevel < 3) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(sscanf(str, "%s %d", who, am) != 2) {
    write("mend player amount\n");
    return 1;
  }
  ob = find_player(who);
  if(!ob) {
    write("No one by that name is on now.\n");
    return 1;
  }
  if(ob->query_invis()) {
    write("No one by that name playing.\n");
    return 1;
  }
  if(ob == Me) {
    write("You can not mend yourself.\n");
    return 1;
  }
  if(am < 1) {
    write("Matry looks at you with disgust.\n");
    return 1;
  }
  if(SP < am) {
    write("You do not have "+am+" spell points.\n");
    return 1;
  }
  if(Me->query_hp() < am) {
    write("You do not have "+am+" hit points.\n");
    return 1;
  }
  if(Mana < am) {
    write("You do not have "+am+" mana points.\n");
    return 1;
  }
  write("You contact Matry and ask to sacrifice your life\n"
+ "engery to heal "+ob->query_name()+".\n");
  say(Name+" kneels down and prays to "+Pos+" Matry.\n");
  say(Name+" looks tired and drained.\n");
  tell_object(ob, Name+" has sacrificed "+Obj+"self to heal you "+am+" points.\n");
  Me->add_hit_point(-am);
  Me->add_spell_point(-am);
  ob->heal_self(am);
  heal_count++;
  Drain(am);
  Gain(am*2);
  return 1;
}

regenerate(str) {
object reg, ob;
  if(Glevel < 12) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(!can_heal()) {
    heal_wait();
    return 1;
  }
  if(Mana < 85) {
    write("You do not possess enough healing energy.\n");
    return 1;
  }
  if(!str)
    ob = Me;
  else
    ob = present(lower_case(str), environment(Me));
  if(!ob || !living(ob)) {
    write("Who would you like to regenerate?\n");
    return 1;
  }
  if(present("REGENERATE", ob)) {
    write(ob->query_name()+ " is already regenerating.\n");
    return 1;
  }
  reg = clone_object("/players/nightshade/closed/guild/obj/regenerate");
  move_object(reg, ob);
  write("You call to Matry and ask that you may regenerate.\n");
  say(Name+" calls to Matry and asks to regenerate "+
        ob->query_name()+".\n");
  Drain(85);
  Gain(EXP50);
  heal_count++;
  return 1;
}

