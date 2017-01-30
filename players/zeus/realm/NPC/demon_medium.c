/* 33% chance of 500+random(2000) coins */
/* Added a check for interactive in the autoattack. -Feldegast 3-7-01 */
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"

string get_short()
{
  string x;
  int y;
  y = random(9);
  if(0 == y) x = RED+"A burning demon";
  else if(1 == y) x = HIR+"A flaming demon";
  else if(2 == y) x = HIR+"A demon wrapped in flames";
  else if(3 == y) x = BOLD+BLK+"A demon of fiery darkness";
  else if(4 == y) x = RED+"A demon creature of fire";
  else if(5 == y) x = RED+"A twisted flaming demon";
  else if(6 == y) x = BOLD+BLK+"A charred black demon";
  else if(7 == y) x = "A demon of the planes";
  else if(8 == y) x = "A planar demon";
  return x+NORM;
}


reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("planar demon");
  set_short(get_short());
  set_race("demon");
  set_long(
"This is a medium sized red demon with many black spots across its flesh.\n"+
"It is a powerful creature with muscular arms and legs, each of which\n"+
"feature sharp little claws.  It has two pulsing red eyes that seem to\n"+
"burn with a dark energy.\n");
  set_level(15+random(5));
  set_ac(random(10));
  set_wc(41+random(20));
  set_wc_bonus(7);
  set_hp(220);
  set_gender("creature");
  set_aggressive(1);
  set_al(-666);
  set_chat_chance(3);
  set_a_chat_chance(1);
  load_chat("The demon glares at you.\n");
  load_chat("The demons eyes burn.\n");
  load_chat("The demon grins.\n");
  load_chat("The demon examines you.\n");
  load_a_chat("The demons eyes glaze over in bloodlust.\n");
  set_dead_ob(this_object());
}  }

id(str){ return str == "demon" || str == "daemon" || str == "planar demon"; }


monster_died(){
  DD->add_kills(AO, 1);
  if(!random(3))
  {
    tell_object(attacker_ob, "You mutilate the demon!\n");
    move_object(clone_object(
      "/players/zeus/realm/OBJ/demon_gore.c"), environment());
    if(present("corpse", environment()));
      destruct(present("corpse", environment()));
  }
}

void init()
{
  ::init();
  add_action("dir_block", "north");
  add_action("dir_block", "east");
  add_action("dir_block", "south");
  add_action("dir_block", "west");
}

dir_block()
{
 if(this_player()->query_npc() || this_player()->query_level() > 19 ||
   this_player()->query_ghost()) return;
  tell_room(environment(), "The demon blocks "+
	  this_player()->query_name()+" from escaping.\n",
	  ({ this_player() }));
  tell_object(this_player(),
	  "The demon blocks you from escaping.\n");
  this_object()->attack_object(this_player());
  return 1;
}

heart_beat(){
  ::heart_beat();
  if(!environment()) return ;
  if(!random(5) && !attacker_ob)
  {
    object *a;
    int b,c;
    a = all_inventory(environment());
    b = sizeof(a);
    for(c = 0; c < b; c++)
    {
      if(a[c]->is_player() && a[c]->query_alignment() > 100
        && !a[c]->query_ghost() && interactive(a[c]))
      {
        tell_room(environment(),
          short_desc+" screams in rage at "+a[c]->query_name()+" and lunges "+
          "at "+a[c]->query_objective()+"!\n", ({ a[c] }));
        tell_object(a[c],
          short_desc+" screams in rage and lunges at you!\n");
        this_object()->attack_object(a[c]);
        weapon_class += 5;
        return;
      }
    }
  }
  if(!attacker_ob) return;
  if(!random(9))
  {
    tell_object(attacker_ob, 
      HIR+"\n\tFlames rise up scorching your body!\n\n"+NORM);
    tell_room(environment(), "The demon cackles with glee!\n",
      ({ attacker_ob }));
    attacker_ob->hit_player(30+random(30), "other|fire");
  }
  if(!random(8))
    tell_object(attacker_ob, "The demon claws at you!\n");
}
