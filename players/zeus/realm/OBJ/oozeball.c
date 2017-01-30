inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
int burn, malcountdown;
string thrower;

reset(arg){
  if(arg) return;

  malcountdown = 15+random(6);
  burn = 0;
  set_weight(1);
  set_value(1000+random(300));
}

id(x){ 
  if(burn) return x == "poison";
  else return x == "ball" || x == "ooze" || x == "toxic ooze"
    || x == "zeus toxic ooze" || x == "ball of ooze" || x == "oozeball"; 
}

void init(){
  ::init();
  add_action("throwf", "throw");
}

who(x){ if(!x) write("Who do you want to throw the ball of ooze at?\n");
        else write("You can't do that here.\n"); }
drop(){ if(burn) return 1; return 0; }
get(){ if(burn) return 0; return 1; }
can_put_and_get(){ if(burn) return 0; return 1; }
query_save_flag(){ return 1; }

short(){ if(!burn){
  return "A small ball of black toxic ooze encased in a hard shell"; } }

long(){
  if(!burn)
  {
    write(
      "This is what appears to be a ball of ooze from the monster that has\n"+
      "hardened up on the outside making it possible to carry around.  From\n"+
      "the smell of it you think the toxins on the inside are still very\n"+
      "deadly.  If it were thrown at someone it might crack open and burn\n"+
      "them with the ooze.\n");
  }
}

good(object tgt){
  if(!random(11) || (present("zeus toxic ooze", tgt) &&
    present("zeus toxic ooze")->query_weight()))
  {
    write("The ball bounces off "+tgt->query_name()+" and lands "+
      "on the ground.\n");
    tell_room(environment(this_player()), this_player()->query_name()+
      " throws a ball of ooze at "+tgt->query_name()+" only to have\n"+
      "it ricochet off and land on the ground fully intact.\n",
      ({ this_player() }));
    move_object(this_object(), environment(this_player()));
  }
  else
  {
    write("You throw the ball of ooze at "+tgt->query_name()+".\n"+
      "The hard shell shatters on impact splashing ooze across "+
      tgt->query_name()+".\n"+
      "The black ooze slowly melts through "+tgt->query_name()+
      "'s skin!\n");
    tell_room(environment(this_player()), this_player()->query_name()+
      " throws a ball of ooze at "+tgt->query_name()+".\n",
      ({ this_player() }));
    local_weight = 0;
    move_object(this_object(), tgt);
    burn = 1;
    call_out("burn", 2);
    if(tgt->is_npc()){
      tell_room(environment(this_player()), "\n"+tgt->query_name()+
        " screams in rage!\n\n");
      tgt->attack_object(this_player());
    }
    thrower = this_player()->query_real_name();
  }
}

throwf(str){
  object tgt;
  string e,f;
  if(!present(this_object(), this_player())) return 0;
  if(burn) return 0;
  if(!str)
  {
    if(tgt = this_player()->query_attack()){}
    else
      who();
  }
  else if(tgt = present(str, environment(this_player())))
  {
    if(!this_player()->valid_attack(tgt))
      write("You can't do that.\n");
    else if((string)environment(this_player())->realm() == "NM")
      who(2);
    else
      good(tgt);
  }
  else if(sscanf(str, "%s at %s", e,f))
  {
    if(tgt = present(f, environment(this_player())))
    {
      if(!this_player()->valid_attack(tgt))
        write("You can't do that.\n");
      else if((string)environment(this_player())->realm() == "NM")
        who(2);
      else
        good(tgt);
    }
  }
  else
    who();
  return 1;
}

burn(){
  if(!environment()) return;
  if(!living(environment()) || environment()->query_ghost()){ 
    destruct(this_object());
    return; 
  }
  tell_object(environment(), GRN+"The ooze burns away at your skin!\n"+NORM);
  tell_room(environment(environment()), GRN+environment()->query_name()+
    " is burned by the ooze!\n"+NORM, ({ environment() }));
  if(environment()->query_hp() < 15) /* death */
  {
    object death;
    death = clone_object("/obj/monster.c");
    death->set_name(thrower);
    environment()->stop_fight();
    environment()->stop_fight();
    environment()->attacked_by(death);
    environment()->hit_player(666, "other|poison");
  }
  else {
    environment()->hit_player(15, "other|poison");
    malcountdown--;
    if(malcountdown)
      call_out("burn", 9);
    else {
      tell_object(environment(), "You start to feel better...\n");
      tell_room(environment(environment()), environment()->query_name()+
        " starts to feel better.\n", ({ environment() }));
      destruct(this_object());
    }
  }
}

extra_look(){  
  if(living(environment()) && (this_player() != environment()) && burn)
    return GRN+environment()->query_name()+
    " has a toxic ooze burning through "+environment()->query_possessive()+
    " skin"+NORM;
  else if(living(environment()) && burn) 
    return GRN+"You have a splash of toxic ooze burning you"+NORM; 
}
