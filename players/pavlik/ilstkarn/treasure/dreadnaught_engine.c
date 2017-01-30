/*
 * This item is gotten from: ~/monsters/ilstkarn/dreadnaught.c
 * The object is a one-time use damage spell.
 */

reset(arg){
  if(arg) return;
}

id(str){
  return str == "scrap" || str == "metal" || str == "dreadnaught_engine";
}

long(){
  write(
  "This is a twisted piece of the Dreadnaught.  It looks like it was part of\n"+
  "an evil machines engine.  The twisted metal is warm to the touch.  Some bubbling\n"+
  "liquid is cupped in the hollow of the metal.\n");
  write("Type 'splash <str>' to splash the liquid on someone.\n");
  return;
}

short(){
  return "A twisted scrap of metal";
}

get() {
  return 1;
}

query_weight() {
  return 4;
}

query_value() {
  return 300;
}

query_save_flag() {
  return 1;
}

init() {
  add_action("drink_not","drink");
  add_action("splash","splash");
}

drink_not(str) {
  if(str == "scrap" || str == "metal" || str == "liquid") {
    write("You consider drinking the bubbling fluid but decide against it.\n");
    write("It really looks like unfriendly stuff.\n");
    write("You might consider splashing this foul lidquid on someoneelse.\n");
    return 1;
  }
}

splash(str) {
  string me, who;
  object ob;

  if(str) {
    ob = present(str, environment(this_player()));
    if(!ob || !living(ob)) return 0;
    if(!ob->query_npc() && this_player()->query_attack() != ob) {
      write("You cannot do that.\n");
      return 1;
    }
    if(this_player()->query_guild_name() == "rangers")
    {
      write("You can not use this.\n");
      return 1;
    }
    me = capitalize(this_player()->query_name());
    who = capitalize(ob->query_name());
    write("You hurl the twisted chunk of metal at "+who+".\n");
    tell_room(environment(this_player()),
    me+" splashes a foul bubbling liquid all over "+who+"!\n"+
    "The toxic fluid hisses and burns into "+who+"'s skin!!!\n");
    ob->hit_player(15+random(25), "other|poison");
    ob->attack_object(this_player());
    this_player()->attack_object(ob);
    destruct(this_object());
    return 1;
  }
}


    
    

