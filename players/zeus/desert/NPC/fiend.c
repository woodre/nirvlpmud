inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){

  set_name("desert fiend");
  if(!random(2))
    set_short("A small desert fiend");
  else
    set_short("A small fiend of the desert");
  set_alias("fiend");
  set_race("creature");
  set_gender("creature");
  set_long(
"This is a small little atrocity that exists with one purpose--  death.\n"+
"It is only about two feet tall, with tough skin a faded brown color\n"+
"which makes it hard to see.  It has two gangly arms each of which have\n"+
"two very long claws which tend to drag on the ground.  It has two pointed\n"+
"ears, with a narrow face.  Its black eyes are very small and hidden.\n");
  set_level(15);
  set_ac(4);              /* mguide 12   for level 15*/
  set_wc(27+random(4));   /* mguide 20  */
  set_hp(200);            /* mguide 225 */
  set_heal(1,3);
  if(!random(2))
    set_aggressive(1);      /*  50% agro  */
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
  object x,y;
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
  y -> set_value(800+random(110));  /* mguide 875 */
  y -> set_long(
    "This is a piece of bloody flesh from a desert fiend.  A patch of the\n"+
    "fiends brown skin can be seen on one side, although much of it is\n"+
    "soaked in blood.  The otherside is torn and bloody muscle.  This was\n"+
    "the best sample you could find on the fiend and is somewhat valuable.\n");
  move_object(y, x);
  if(!(random(12)))
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
  if(!random(5) && !attacker_ob)
  {
    object *a;
    int b,c;
    a = all_inventory(environment());
    b = sizeof(a);
    for(c = 0; c < b; c++)
    {
      if(a[c]->is_player() && a[c]->query_alignment() > 100
        && !a[c]->query_ghost())
      {
        tell_room(environment(),
          "A fiend screams in rage at "+a[c]->query_name()+" and lunges "+
          "at "+a[c]->query_objective()+"!\n", ({ a[c] }));
        tell_object(a[c],
          "A fiend screams in rage and lunges at you!\n");
        this_object()->attack_object(a[c]);
        weapon_class = 30;
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
    attacker_ob->hit_player(16+random(5));
    hit_point -=3;
  }
  else if(!random(5) && hit_point < 24)
  {
    tell_room(environment(),
      "The fiend lashes out at "+attacker_ob->query_name()+" as it flees!\n");
    attacker_ob->hit_player(10);
    wimpy();
  }
}

