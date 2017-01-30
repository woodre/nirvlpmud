inherit "obj/monster";
object obj, obj2;
reset(arg){
   ::reset(arg);
   if(arg) return;
 set_name("Askelon the drunk");
 set_race("drunk");
 set_alias("askelon");
 set_short("Askelon the drunk");
 set_long(
 "A tall filthy man that has been too deep in his cups for too long.\n"+
 "Askelon's overwhelming aroma makes you nauseous.  He forever holds a\n"+
 "bottle in one hand and a dangerous looking silver dagger in the other.\n");
 set_level(20);
 set_al(0);
 set_hp(1000);
 set_wc(20);
 set_ac(4);
 set_aggressive(0);
 set_can_kill(1);
 set_chat_chance(25);
 set_a_chat_chance(25);
 load_chat("Askelon burps rudely.\n");
 load_chat("Askelon takes a long pull from his bottle.\n");
 load_chat("Askelon stares into space with glazed eyes.\n");
 load_chat("Askelon mumbles something unintelligable.\n");
 load_chat("The drunk tries to stand but falls over.\n");
 load_a_chat("Askelon sings: 99 bottle 'o beer *hic* on the wall ...\n");
 load_a_chat("Askelon burps rudely.\n");
 load_a_chat("Askelon pauses to take a long pull from his bottle.\n");
 load_a_chat("Askelon stumbles and almost falls over.\n");
 obj = clone_object("obj/bag");
 move_object(obj, this_object());
 move_object(clone_object("players/pavlik/items/heals/sprig"), obj);
 obj2 = clone_object("obj/money");
 obj2->set_money(10+random(50));
 move_object(obj2, obj);
 move_object(clone_object("players/pavlik/weapons/silver_dagger"), this_object());
 init_command("wield dagger", this_object());
}

id(str){
  return str == "askelon" || str == "drunk" || str == "man" ||
  str == "drunk_man" || str == "ilstkarn_monster";
}

init() {
  ::init();
  call_out("trip", 2, this_player());
}

trip(ob) {
  if(ob->is_player() && present(ob, environment(this_object()))) {
    tell_object(ob,
    "You trip over something on the ground and fall down.\n"+
    "A dirty old drunkard points at you and laughs!\n");
  }
  return 1;
}

/*
 * Non of this heal_self crap
 */
heal_self(i) {
  if(i <=0) {
    return;
  }
  else {
    ::heal_self(i);
  }
  return;
}

query_intoxination(){ return 25+random(3); }
