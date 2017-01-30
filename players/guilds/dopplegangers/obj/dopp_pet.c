#define WHO this_player()->query_real_name()

inherit "/obj/monster";

string owner, nme;

reset(arg) {
   ::reset();
   if(arg) return;
   set_name("Pet");
   set_short("Doplleganger's Pet");
   set_ep(0);
   set_alias("pet");
   set_can_kill(1);
   set_ep(0);
   set_ac(12);
   set_wc(20);
   set_hp(300);
   nme = "A Doppleganger's Pet";
   owner = "Nobody";
   enable_commands();
}

id(str) {
  return str == "pet" || str == "guild_monster";
}

heart_beat() {
  ::heart_beat();
  if(this_object()->query_attack()==owner) {
    say("The pet wimpers as its master smashes it.\n");
    owner->stop_fight();
    this_object()->stop_fight();
  }
  if(!find_living(owner)) {
    say(nme+"'s owner is missing.  He dies in a pool of sadness.\n");
    destruct(this_object());
  }
  if(environment(find_living(owner)) != environment(this_object())) {
    say(nme+" runs after its master.\n");
    move_object(this_object(),environment(find_living(owner)));
    say(nme+" runs in after its master.\n");
  }
}

set_nme(str) { nme = str; }

set_owner(str) { owner = str; }

go() { set_heart_beat(1); return 1; }
add_hp_to_me(x) {  this_object()->add_hit_point(x); }

short() { return nme; }

long() {
  object ob;
  object ob2;
  ob = this_player();
  ob2 = find_living(owner);
  write("This is the pet of "+capitalize(owner)+".\n");
  if(owner==this_player()->query_real_name()) {
    write("You can have the pet carry items by giving the item to it.\n");
    write("To get the item FROM the creature you can \"GET <item>\" (where\n");
    write("\"GET\" is in capital letters). You can \"release\" the pet and\n");
    write("\"name <string>\" the pet also.\n");
    if(ob->query_guild_rank()>7) {
      write("You can also have the pet \"attack <monster>\".\n");
    }
    if(ob->query_guild_rank()>8) {
      write("And you can \"ADD <x>\" to the pet to add <x> hit points to it\n(costing <x>*3 sp to you)\n");
    }
    write("The pet currently has: "+this_object()->query_hp()+" hp left.\n");
  }
}
   
init() {
  ::init();
  if(this_player()==find_living(owner)) {
    add_action("get","GET");
    add_action("set_my_name","name");
    add_action("release","release");
    if(find_living(owner)->query_guild_rank()>6) {
      add_action("atak","attack");
    }
    if(find_living(owner)->query_guild_rank()>7) {
      add_action("add","ADD");
    }
  }
}
   
get(str) {
  object ob;
  if(!str) {
    write("The pet peers at you quizically.\n");
    return 1;
  }
  if(!present(str,this_object())) {
    write("The pet peers at you quizically.\n");
    return 1;
  }
  ob = present(str,this_object());
  move_object(ob,this_player());
  this_object()->add_weight(ob->query_weight());
  this_player()->add_weight(ob->query_weight());
  write("Your pet gives you a "+capitalize(str)+".\n");
  say(capitalize(owner)+"'s pet gives him a "+capitalize(str)+"\n");
  return 1;
}
   
release() {
  object badge;

  badge = present("V-GUILD", find_player(owner));
  write("Your pet looks deep into your eyes as he turns and disappears into\nthe night.\n");
  say(capitalize(owner)+" releases his pet.\n");
  destruct(this_object());
  badge->set_pet_object(0);
  return 1;
}

atak(str) {
  object ob;
  if(!str) {
    write("Your pet peers at you quizically.\n");
    return 1;
  }
  if(!(ob=present(str,environment(this_object())))) {
    write("Your pet peers at you quizically.\n");
    return 1;
  }
  if(!ob->query_npc()) {
    write("Your pet looks up and down the player and doesn't believe him\nto be tasty enough to attack.\n");
    return 1;
  }
  ob->set_can_kill(1);
  this_object()->attack_object(ob);
  say(capitalize(nme)+" tears into "+capitalize(str)+".\n");
  write("Your pet tears into "+capitalize(str)+".\n");
  return 1;
}
   
add(str) {
  object ob;
  int x;
  if(!str) {
    write("Your pet peers at you quizically.\n");
    return 1;
  }
  if(!(sscanf(str,"%d",x))) {
    write("Your pet peers at you quizically.\n");
    return 1;
  }
  if(x < 1){
    write("Please try healing me a positive number.\n");
    return 1;
  }
  ob = find_living(owner);
  x = x*3;
  if(ob->query_sp()<x) {
    write("Your pet peers at you quizically.\n");
    return 1;
  }
  ob->add_spell_point(-x);
  this_object()->set_hp(this_object()->query_hp()+(x/3));
  write("Your pet feels better.\n");
  return 1;
}

set_my_name(str) {
  if(!str) {
    write("Your pet peers at you quizically.\n");
    return 1;
  }
  this_object()->set_nme(str);
  this_object()->set_short(str);
  write("Your pet's name has been changed.\n");
  return 1;
}
   
query_pet() { return 1; }
query_owner() { return owner; }

add_exp(x) {
  if(x<=0) return;
  if(find_player(owner)) find_player(owner)->add_exp(x);
}

/* Added this - Rumplemintz */
monster_died() {
  object badge;

  badge = present("V-GUILD", owner);
  badge->set_pet_object(0);
  tell_object(owner, "Your pet has died.\n");
/*
  ::monster_died();
*/
}

