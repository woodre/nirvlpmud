  /*  16% chance of nothing   ---  the planar demon ---
      42% chance of heart
      42% chance of tooth  */

inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#define TOOTH "/players/zeus/realm/OBJ/demon_tooth.c"
#define HEART "/players/zeus/heals/demon_heart.c"
int spirit;
object meat;
string beh, heh;

string get_short()
{
  string x;
  int y;
  y = random(19);
  if(0 == y) x = "A burning demon";
  else if(1 == y) x = "A tortured demon";
  else if(2 == y) x = "An agonized demon";
  else if(3 == y) x = "A demon wrapped in flames";
  else if(4 == y) x = "A demon creature";
  else if(5 == y) x = "A mangled demon";
  else if(6 == y) x = "An unholy demon";
  else if(7 == y) x = "A demon of the planes";
  else if(8 == y) x = "A demon with giant claws";
  else if(9 == y) x = "A demon with teeth like daggers";
  else if(10 == y) x = "A demon cloaked in fire";
  else if(11 == y) x = "A furious demon";
  else if(12 == y) x = "A monsterous demon";
  else if(13 == y) x = "A wicked looking demon";
  else if(14 == y) x = "A ferocious demon";
  else if(15 == y) x = "A forever burning demon";
  else if(16 == y) x = "A demon with haunted eyes";
  else if(17 == y) x = "A demon of unending pain";
  else if(18 == y) x = "An anger filled demon";
  return x;
}

string get_long()
{
  string x;
  int y;
  y = random(6);
  if(0 == y) x =
"This muscular beast is a demon of the planes.  Its tough red skin is\n"+
"covered in black burn marks and deep scars.  It has a narrow face with\n"+
"razor sharp teeth and two filty horns.  It seems to pay no attention\n"+
"to the burning flames which are all around it.\n";
  else if(1 == y) x =
"This is one of the many demons which exists in this plane.  Gigantic\n"+
"claws adorn its hands and feet.  Its head is very narrow, highlighted\n"+
"not only by razor sharp, glistening teeth, but also two curved horns\n"+
"which protrude from its skull.  This beast would be more than willing\n"+
"to have you for lunch.\n";
  else if(2 == y) x =
"What stands before you is an incredibly powerful looking demon.  Its\n"+
"tough red skin is tainted with black marks.  Its seems to be grinning\n"+
"at you with its sharp teeth glistening in the light.  Two sharp horns\n"+
"protrude from atop its head.  It seems to be filled with an unending\n"+
"anger towards everything and everyone.\n";
  else if(3 == y) x =
"This is a monsterous planar demon. It seems to be immune to the flames\n"+
"which rise up all around it.  It has dark red skin which is tainted by\n"+
"many dark black burn marks.  Sharp teeth and long claws are this demons\n"+
"weapons, and very good weapons at that.\n";
  else if(4 == y) x =
"This demon looks at you with eyes of anguish.  Its narrow head features\n"+
"long, white teeth which could tear through bone.  Large claws adorn its\n"+
"large hands.  Its dark red skin is very tough, bulging with muscles.\n";
  else if(5 == y) x =
"A demon which exists on this plane, its only purpose is to bring pain\n"+
"and torment to those around it.  It has dark red skin, and razor sharp\n"+
"claws and teeth.  Two narrow horns protrude from its skull.\n";
  return x;
}


reset(arg){
  ::reset(arg);
  if(!arg){

  beh =({ "monsterous planar demon ",
          "hideous planar demon ",
          "horrible planar demon ",
          "fiendish planar demon ", });

  heh =({ "claws you in the stomach",
          "gashes you across the face",
          "plunges its claws into you",
          "screams out in anger",
          "rakes its claws across you",
          "bathes in the flames of the demon plane", });

  spirit = 0;
  set_name("planar demon");
  set_short(get_short());
  set_long(get_long());
  set_race("spirit");
  set_gender("creature");
  set_level(21);
  set_ac(4+random(2));
  set_wc(50+random(25));
  set_wc_bonus(20);
  set_hp(500);
  set_aggressive(1);
  set_al(-500-random(700));
  set_heal(1,1+random(6));
  set_chat_chance(1);
  set_a_chat_chance(1);
  set_dead_ob(this_object());
  load_chat("The demon glares.\n");
  load_chat("The demon roars at you.\n");
  load_chat("Flames burn all around you.\n");
  load_chat("Waves of heat pummel your body.\n");
  load_chat("The demons eyes burn.\n");
  load_a_chat("The demon screams in agony.\n");
  load_a_chat("The demon shreaks at you.\n");
  }
}

id(str) { return (::id(str) || str == "demon" || str == "daemon" ||
                str == "planar demon"); }

set_spirit(int x){  spirit = x; }
query_spirit(){ return spirit; }

monster_died()
{
  object dmn;
  int what;
  what = random(14);
  switch(what)
  {
  case 0..1:
    if(!random(3))
    {
      write(
      "The mutilated body of the demon collapses to the ground...\n"+
      "All that remains is a lifeless pile of bloody red gore.\n");
    }
    else if(!random(2))
    {
      write(
      "The demon suddenly begins tearing at its chest...\n"+
      "Bloody gore flies in all directions as it tears itself apart.\n");
    }
    else
    {
      write(
        "The demons chest erupts in a fountain of blood and gore.\n");
    }
    break;
  case 2..3:
    write(
      "As the demon slumps to the ground, you plunge your weapon\n"+
      "into the demons chest and cut out its heart.\n");
    move_object(clone_object(HEART), attacker_ob);
    break;
  case 4..5:
    write(
      "The demons lifeless body collapses to the ground...\n"+
      "You plunge your weapon into it, cutting out its heart.\n");
    move_object(clone_object(HEART), attacker_ob);
    break;
  case 6:
	write(
      "You plunge your weapon into the demon, cutting out its heart.\n");
    move_object(clone_object(HEART), attacker_ob);
    break;
  case 7:
    write(
      "You rip the heart out of the demons bloody chest.\n");
    move_object(clone_object(HEART), attacker_ob);
    break;
  case 8..9:
    write("A glistening white tooth falls to the ground.\n");
    move_object(clone_object(TOOTH), environment());
    break;
  case 10:
    write("You pick up one of the demons teeth from the ground.\n");
    move_object(clone_object(TOOTH), attacker_ob);
    break;
  case 11..12:
    write("With your final blow you knock loose one of the monsters teeth.\n");
    move_object(clone_object(TOOTH), environment());
    break;
  case 13:
    write("You rip out one of the demons sharp teeth.\n");
    move_object(clone_object(TOOTH), attacker_ob);
    break;
  }
  DD->add_kills(attacker_ob, 1);
  if(1 == spirit)
  {
    dmn = clone_object("/players/zeus/realm/NPC/demon_spirit.c");
	tell_room(environment(),
		"\nA demonic spirit rises from the corpse of the demon!\n"+
		"The spirit screams in agony as it emerges!\n\n");
    move_object(dmn, environment());
	dmn->attack_object(attacker_ob);
  }
  write_file("/players/zeus/log/Q", ctime(time())+" -  "+
    capitalize((string)attacker_ob->query_real_name())+
    " killed a planar demon.\n");
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
  if(!attacker_ob)
  {
    if(meat)
    {
      if(present(meat, environment()))
      {
        if(present(meat, environment())->query_ghost()) return;
        if(!random(2))
        {
          tell_room(environment(), "The planar demon screams at "+
            meat->query_name()+"!\n");
        }
        else
        {
          tell_room(environment(), "The planar demon lunges at "+
            meat->query_name()+"!\n");
          meat->hit_player(25);
        }
        this_object()->attack_object(meat);
      }
    }
    else if(!random(20) && !attacker_ob)
    {
      object *a;
      int b,c;
      a = all_inventory(environment());
      b = sizeof(a);
      for(c = 0; c < b; c++)
      {
        if(a[c]->is_player() && a[c]->query_alignment() > 100
          && !a[c]->query_ghost() && !a[c]->query_attack())
        {
          tell_room(environment(),
            "The planar demon screams in rage at "+a[c]->query_name()+
            " and lunges "+
            "at "+a[c]->query_objective()+"!\n", ({ a[c] }));
          tell_object(a[c],
            "The planar demon screams in rage and lunges at you!\n");
          this_object()->attack_object(a[c]);
        }
      }
    }
  }
  if(attacker_ob)
    meat = attacker_ob;
  if(!random(8) && attacker_ob)
  {
    tell_object(attacker_ob, 
      "\nThe "+beh[random(sizeof(beh))]+heh[random(sizeof(heh))]+".\n\n");
    if(attacker_ob->query_hp() > 200 && !attacker_ob->query_ghost())
    {
      already_fight = 0; 
      ::attack();
    } 
  }
}


