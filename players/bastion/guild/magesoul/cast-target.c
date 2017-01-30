
int casting_spell, casting_timer, casting_time;
int spell_level;
static int charge;
string current_spell, bing1, bing2, *spells_learned;

int clear_spell();

int cast(string str) {
     string spell, what, *properties;
     int spell_cost, chance;
     if(casting_spell) {
          write("You are already casting a spell.\n");
          return 1;
     }
     if(!str) {
          write("Cast <spell> (<arg1>) (<arg2>)\n");
          return 1;
     }
     if(sscanf(str, "%s %s", spell, what)==2) {
          if(sscanf(what, "%s %s", bing1, bing2)!=2)
               bing1=what;
     }
     else
          spell=str;
     if(member_array(spell, spells_learned)==-1) {
          write("You know of no such spell.\n");
          clear_spell();
          return 1;
     }
     spell_ob="players/bastion/guild/spell/" + spell;
     properties=(string*)spell_ob->query_property();
     if(me->query_attack() && 
       member_array("no_attack", properties)!=-1) {
          write("You are too busy fighting to concentrate!\n");
          clear_spell();
          return 1;
     }
     if(!valid_target(properties)) {
          clear_spell();
          return 1;
     }
     target=set_target(properties);
     spell_level=(int)spell_ob->query_spell_level();
     if(spell_level > guild_level) {
          write("You are not skillful enough to cast that spell.\n");
          clear_spell();
          return 1;
     }
     spell_cost=(int)spell_ob->query_spell_cost();
     if(!deduct_cost(spell_cost)) {
          clear_spell();
          return 1;
     }
     current_spell=spell;
     spell_ob->cast_spell(target, bing1, bing2);
     set_spell_heart_beat();
     return 1;
}

int set_spell_heart_beat() {
  casting_time=(int)spell_ob->query_casting_time();
  casting_spell=1;
}

int valid_target(string *props) {
  object here;
  here=environment(player());
  if(bing1 && member_array("no_target", props)!=-1 &&
    member_array("nonparsed", props)==-1) {
    write("That spell doesn't require a target.\n");
    return 0;
  }
  if(!bing2 && member_array("two_arguments", props)!=-1) {
    write("You need to supply more information to cast that.\n");
    return 0;
  }
  if(member_array("nonliving_target", props)!=-1 &&
    member_array("living_target", props)==-1) {
    if(!bing1) {
      write("You need to specify a target.\n");
      return 0;
    }
    if(!present(bing1) || !present(bing1, here)) {
      write("That is not here.\n");
      return 0;
    }
  }
  if(member_array("living_target", props)!=-1 &&
    member_array("nonliving_target", props)==-1) {
    if(bing1 && !present(bing1, here) && 
     member_array("distant_target", props)==-1) {
      write("That person is not here.\n");
      return 0;
    }
    if(bing1 && !find_player(bing1) &&
     member_array("distant_target", props)!=-1) {
      write("That person is not logged in.\n");
      return 0;
    }
    if(!bing1 && !player()->query_attack() && 
     member_array("attack_spell", props)!=-1) {
      write("You need to specify a target.\n");
      return 0;
    }
    else if(!bing1 && member_array("attack_spell", props)==-1 &&
     member_array("self_target", props)==-1) {
      write("You need to specify a target.\n");
      return 0;
    }
  }
  if(member_array("living_target", props)!=-1 &&
   member_array("nonliving_target", props)!=-1) {
    if(!bing1 && member_array("self_target", props)==-1) {
      write("You need to specify a target.\n");
      return 0;
    }
    if(!present(bing1) && !present(bing1, here)) {
      write("That person or item is not here.\n");
      return 0;
    }
  }
  return 1;
}

object set_target(string *props) {
  object here;
  here=environment(player());

  if(member_array("non_parsed", props)!=-1 ||
   member_array("no_target", props)!=-1)
    return player();
  if(member_array("nonliving_target", props)!=-1 &&
   member_array("living_target", props)==-1) {
    if(bing1 && present(bing1))
      return present(bing1);
    else if(bing1 && present(bing1, here))
      return present(bing1, here);
  }
  if(member_array("living_target", props)!=-1 && 
   member_array("nonliving_target", props)==-1) {
    if(!bing1 && member_array("attack_spell", props)!=-1)
      return (object)player()->query_attack();
    else if(bing1 && present(bing1, here))
      return present(bing1, here);
    else if(bing1 && find_player(bing1))
      return find_player(bing1);
    else
      return player();
  }
  if(member_array("living_target", props)!=-1 &&
   member_array("nonliving_target", props)!=-1) {
    if(bing1 && present(bing1))
      return present(bing1);
    else if(bing1 && present(bing1, here))
      return present(bing1, here);
    else if(bing1 && find_player(bing1))
      return find_player(bing1);
    else
      return player();
  }
  write("Error: Set_target().\n");
  log_file("players/bastion/guild/log/error","Error: Set_target() -- magesoul.c");
}

int try_spell() {
     int chance, intel, mag, cost;
     intel=(int)player()->query_attrib("int");
     mag=(int)player()->query_attrib("mag");
     chance=(int)spell_ob->query_base_chance();
     chance=chance + (guild_level * 4) + ((intel/4)*2) + ((mag/4)*2);
     cost=(int)spell_ob->query_spell_cost();
     earn_experience(spell_level, intel, mag, cost);
     if(chance < (random(100) + 1)) {
          write("The spell backfires however, nearly turning everyone\n"+
                "in the room into a newt.\n");
          say(me->query_name() + "'s spell backfires however, nearly turning "+
                "everyone\n in the room into a newt.\n");
     }
     else
       spell_ob->heart_beat_spell(target, bing1, bing2);
     clear_spell();
     return 1;
}

int deduct_cost(int cost) {
     if(cost <= charge)
          charge-=cost;
     else if(!charge) {
          if(cost > (me->query_spell_point())) {
               write("You lack the energy.\n");
               return 0;
          }
          me->add_spell_point(-cost);
     }
     else {
          if(cost > (charge + me->query_spell_point())) {
               write("You lack the energy.\n");
               return 0;
          }
          me->add_spell_point(-(cost - charge));
          charge=0;
     }
     return 1;
}

int earn_experience(int lev, int in, int ma, int cost) {
     int amt;
     amt=(lev + in + ma) / 10;
     amt=(amt * cost) / 2;
     player()->add_exp(amt);
     return 1;
}

int interrupt_spell() {
     if(casting_spell && casting_timer < casting_time && casting_time > 1) {
          write(capitalize(current_spell) + " interrupted.\n");
          clear_spell();
          return 1;
     }
}

int clear_spell() {
  casting_spell=0; casting_time=0; casting_timer=0; spell_ob=0;
  target=0; bing1=0; bing2=0; current_spell=0; spell_level=0;
}
