magic_stone(str) {
object ob;
  if(Glevel < 4) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(!str)
    ob = Me->query_attack();
  else
    ob = present(lower_case(str), environment(Me));
  if(!ob || !living(ob)) {
    write("Magic stone who?\n");
    return 1;
  }
  if(interactive(ob)) {
    if(!PK) {
      write("You are not a player killer.\n");
      return 1;
    }
   if(ob->query_npc() != 0) {
      write("You can not attack a non player killer.\n");
      return 1;
    }
    if(Env(Me)->query_property("NOPK")) {
      write("You cannot player kill in this room.\n");
      return 1;
    }
  }
  if(Time3 > time()) {
    write("You have to wait a little longer to cast magical stone again.\n");
    return 1;
  }
  if(SP < 10) {
    write("You do not possess enough energy to ask Matry.\n");
    return 1;
  }
  write("You create a magical stone and hurl it at "+ob->query_name()+"!.\n");
  say(Name+" creates a magical stone and hurls it at "+ob->query_name()+".\n");
ob->attack_object(this_player());
  ob->hit_player(random(Wis) + 10 + (Faith * 3));
  Gain(EXP10);
  Ssp(10);
  Time3 = time() + 2;
  return 1;
}

fairy_fire(str) {
object ob;
  if(Glevel < 2) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(!str)
    ob = Me->query_attack();
  else
    ob = present(lower_case(str), environment(Me));
  if(!ob || !living(ob)) {
    write("Fairy fire who?\n");
    return 1;
  }
  if(interactive(ob)) {
    if(!PK) {
      write("You are not a player killer.\n");
      return 1;
    }
   if(ob->query_npc() != 0) {
      write("You can not attack a non player killer.\n");
      return 1;
    }
    if(Env(Me)->query_property("NOPK")) {
      write("You cannot player kill in this room.\n");
      return 1;
    }
  }
  if(Time3 > time()) {
    write("You have to wait a little longer to cast magical stone again.\n");
    return 1;
  }
  if(SP < 5) {
    write("You do not possess enough energy to ask Matry.\n");
    return 1;
  }
write("Your hands burst into flames and you reach out towards "+ob->query_name()+"!.\n");
say(Name+"'s hands burst into flames and reaches for "+ob->query_name()+".\n");
ob->attack_object(this_player());
  ob->hit_player(random(Wis) + 5 + (Faith * 2));
  Gain(EXP10);
  Ssp(5);
  Time3 = time() + 3;
  return 1;
}
holy_word(str) {
object ob;
int ali;
int ali_check;
  if(Glevel < 9) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(!str)
    ob = Me->query_attack();
  else
    ob = present(lower_case(str), environment(Me));
  if(!ob || !living(ob)) {
    write("Nothing here that would be affected by that word.\n");
    return 1;
  }
  if(interactive(ob)) {
    if(!PK) {
      write("You are not a player killer.\n");
      return 1;
    }
    if(!ob->query_npc()) {
      write("You can not attack a non player killer.\n");
      return 1;
    }
    if(Env(Me)->query_property("NOPK")) {
      write("You cannot player kill in this room.\n");
      return 1;
    }
  }
  if(Time3 > time()) {
    write("You have to wait a little longer to cast the word again.\n");
    return 1;
  }
  if(SP < 50) {
    write("You do not possess enough energy to ask Matry.\n");
    return 1;
  }
  ali = ob->query_alignment();
  if(ali < 0) ali_check = 0;
  else ali_check = 1;
  if(ali_check && Me->query_alignment() > 0) {
    write(ob->query_name()+" will not be affected by your holy word.\n");
    return 1;
  }
  if(!ali_check && Me->query_alignment() < 0) {
    wriet(ob->query_name()+" will not be affected by your unholy word.\n");
    return 1;
  }
  if(!ali_check) {
    write("You call to Matry and pray for a holy word.\n");
    say(Name+" calls to Matry and prays for a holy word.\n");
    tell_room(Env(Me),"You hear Matry utter a sweet and holy word of good.\n"
    +ob->query_name()+" screams out in pain as the word penetrates to "
    +ob->query_possessive()+" soul!\n");
    ob->hit_player((random(Wis) + 20) + (random(Faith * 10)));
    Gain(EXP40A);
    Ssp(50);
    Time3 = time() + 3;
    return 1;
  }
  write("You call to Matry and pray for an unholy word.\n");
  say(Name+" calls to Matry and prays for an unholy word.\n");
  tell_room(Env(Me),"You hear Matry utter a painful and unholy word of evil.\n"
  +ob->query_name()+" screams out in pain as the word penetrates to "
  +ob->query_possessive()+" soul!\n");
  ob->hit_player((random(Wis) + 20) + (random(Faith * 10)));
  Gain(EXP40A);
  Ssp(50);
  Time3 = time() + 3;
  return 1;

}


call_lightning() {
object ob;
object obj;
int dam;
  if(Glevel < 6) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(SP < 30) {
    write("You do not possess enough energy to contact Matry.\n");
    return 1;
  }
  if(Env(Me)->query_property("NOPK")) {
  write("NO PK IN THIS ROOM. WILL NOT DAMAGE ANY PLAYERS.\n");
return 1;
}
  ob = first_inventory(environment(Me));
  write("You call upon the powers of nature and summon lightning to strike your enemies.\n");
  say(Name+" summons lightining which zaps " +Pos+" enemies!\n");
  while(ob) {
    obj = next_inventory(ob);
if((living(ob)) && (ob != Me) && (ob->query_npc() !=0)&&(ob->query_name() != "Pet")) {
     dam = random(Wis) + 10 + random(Glevel * 2);
      tell_room(environment(Me),
  "A bright bolt of lightning comes crashing down from the skies and\n"
+ "strikes " +ob->query_name()+"!!!\n");
     ob->attack_object(this_player());
      ob->hit_player(dam);
    }
    ob = obj;
  }
  Ssp(30);
  Gain(EXP30);
  return 1;
  }

earthquake() {
object ob;
object obj;
int dam;
  if(Glevel < 13) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(SP < 50) {
    write("You do not possess enough energy to contact Matry.\n");
    return 1;
  }
  ob = first_inventory(environment(Me));
  write("You call to Matry and request for an earthquake.\n");
  say(Name+" calls to Matry and request for an earthquake.\n");
  tell_room(Env(Me), "Matry causes the land to shake with violence.\n");
  while(ob) {
    obj = next_inventory(ob);
   if((living(ob)) && (ob != Me) && (ob->query_npc() != 0)) {
      dam = random(20) + random(Wis) + Glevel + (Faith * 5);
      tell_room(Env(Me),
      ob->query_name()+" is badly wounded by the violent earthquake!!!\n");
     ob->attack_object(this_player());
      ob->hit_player(dam);
    }
    ob = obj;
  }
  Ssp(50);
  Gain(EXP40A);
  return 1;
}

/*****************************************************
turn_undead() {
object ob, obj;
string race;  
int lev;
  write("You attempt to turn all the undeads in the room.\n");
  say(Name+" attempts to turn all the undeads in the room.\n");
  ob = first_inventory(Me);
  while(ob) {
    obj = next_inventory(ob);
    race = ob->query_race();
    if(race == "undead" || race == "Undead") {
      lev = ob->query_level();
      if((Glevel + 3) > lev) {
        if(Glevel > (lev + 10)) {
          tell_room(Env(Me),
          "Matry totally destroys the lower form of undead.\n");
          ob->hit_player(1000);
        }
        tell_room(Env(Me),
        "The undead turns and tries to flee!\n");
        ob->run_away();
      }
      write(ob->query_name()+" laughs at your failure to turn it.\n");
      say(ob->query_name()+" laughs at "+Name+"'s failure to turn it.\n");
    }
    ob = obj;
  }
  return 1;
}
****************************************************/

