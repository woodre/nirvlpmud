inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){

  set_name("desert fiend");
  if(!random(2))
    set_short("A giant desert fiend");
  else
    set_short("A giant fiend of the desert");
  set_alias("fiend");
  set_race("creature");
  set_gender("creature");
  set_long(
"This is a giant atrocity that exists with one purpose--  death.  It\n"+
"is about five feet tall, with tough skin a faded brown color which\n"+
"makes it hard to see.  It has two gangly arms each of which have two\n"+
"very long claws which tend to drag on the ground.  It has two pointed\n"+
"ears, with a narrow face.  Its black eyes are very small and hidden.\n"+
"Do not fight this monster unless you are prepared for a tough fight.\n");
  set_level(22);
  set_ac(18);
  set_wc(44+random(4));
  set_wc_bonus(9);
  set_hp(800+random(230));
  set_heal(1,3);
  set_chat_chance(3);
  set_a_chat_chance(3);
  load_chat("A fiend watches you closely.\n");
  load_chat("A fiend claws at the ground.\n");
  load_chat("A fiend wanders slowly about.\n");
  load_chat("A fiend perks its ears up.\n");
  load_chat("A fiend looks off into the sands.\n");
  load_a_chat("A fiend tears into your leg.\n");
  load_a_chat("A fiend jumps into the air.\n");
  load_a_chat("A fiend lunges at you.\n");
  set_dead_ob(this_object());
  }  
}

id(str){ return str == "zeus_inculta_npc"
             || str == name || str == alt_name || str == alias; }

monster_died(){
  object x,y, gold;
  x = present("corpse", environment());
  x -> set_short("The remains of a desert fiend");
  x -> set_long(
    "These are the mutilated remains of a desert fiend.  It\n"+
    "is bloody and has sustained very bad damage.  It looks\n"+
    "as though its arms are both broken, as well as one of its\n"+
    "legs has been severed.  Its black eyes stare off into space.");
  y = clone_object("/obj/treasure.c");
  y -> set_name("fiend flesh");
  y -> set_alias("flesh");
  y -> set_short("Flesh from a desert fiend");
  y -> set_weight(1);
  y -> set_value(800+random(110));
  y -> set_long(
    "This is a piece of bloody flesh from a desert fiend.  A patch of the\n"+
    "fiends brown skin can be seen on one side, although much of it is\n"+
    "soaked in blood.  The otherside is torn and bloody muscle.  This was\n"+
    "the best sample you could find on the fiend and is somewhat valuable.\n");
  move_object(y, x);
  tell_room(environment(),
    "You discover a pile of coins among the remains of the fiend.\n");
  gold = clone_object("/obj/money.c");
  gold -> set_money(5000 + random(4000));
  move_object(gold, environment());
  if(!(random(5)))
    move_object(clone_object("/players/fred/closed/bloodfist/obj/gem.c"), environment());
  return 1; 
}

wimpy(){
  string *dirs;
  string str;
  int x, rand;
  if(!present(attacker_ob, environment())) return;
  if(!environment()->query_dest_dir()) return;
  tell_room(environment(), "\n");
  dirs = environment()->query_dest_dir();
  rand = random(sizeof(dirs)-1);
  x = rand / 2 * 2;
  str = dirs[x + 1];
  str += "#";
  str += dirs[x];
  this_object()->move_player(str);
}

void heart_beat(){
  ::heart_beat();
  if(!environment())
    return;
  if(!random(3) && !attacker_ob)
  {
    object *a;
    int b,c;
    a = all_inventory(environment());
    b = sizeof(a);
    for(c = 0; c < b; c++)
    {
      if(a[c]->is_player() && a[c]->query_alignment() > 100
        && !a[c]->query_ghost() && a[c]->query_level() > 15)
      {
        tell_room(environment(),
          "A fiend screams in rage at "+a[c]->query_name()+" and lunges "+
          "at "+a[c]->query_objective()+"!\n", ({ a[c] }));
        tell_object(a[c],
          "A fiend screams in rage and lunges at you!\n");
        this_object()->attack_object(a[c]);
        return;
      }
    }
  }
  if(!attacker_ob)
    return;
  if(!random(13))
  {
    tell_room(environment(),
      "The fiend lunges at "+attacker_ob->query_name()+", grabbing "+
      "onto "+attacker_ob->query_possessive()+" leg.\n"+
      "The fiend begins clawing at "+attacker_ob->query_name()+"'s leg, "+
      "drawing blood!\n"+
      attacker_ob->query_name()+" manages to kick the fiend away.\n",
      ({ attacker_ob }));
    tell_object(attacker_ob,
      "\nThe fiend lunges at you, grabbing onto your leg.\n"+
      "The fiend begins clawing at your leg, drawing blood!\n"+
      "You manage to kick the fiend off you.\n");
    attacker_ob->hit_player(56+random(33));
    hit_point -=3;
  }
  else if(!random(5) && hit_point < 24)
  {
    tell_room(environment(),
      "The fiend lashes out at "+attacker_ob->query_name()+" as it flees!\n");
    attacker_ob->hit_player(35);
    wimpy();
  }
}

