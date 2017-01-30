
/*
50% dual hit:  wc 20
dmg func:      wc 13
opp heal func: wc 13
*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#define OQN AO->QN
#define OQP AO->POS

int old_hp, new_hp, damage;
int old_opp_hp, new_opp_hp, heal;
object nmy;

reset(arg) {
   ::reset(arg);
   if (!arg) {

  old_hp = 0;
  old_opp_hp = 1000;

  set_name("jerek");
  set_short("Jerek the Mutant");
  set_alias("mutant");
  set_race("mutant");
  set_gender("male");
  set_long(
"Jerek is a very strong mutant.  His skin, which is a pale greenish color,\n"+
"seems to be just hanging off of his bones. His round face is highlighted\n"+
"by his two eye sockets which sink very deep into his face.  Plates of\n"+
"metal are visible beneath his skin all over his body, and razor sharp\n"+
"blades are protruding from his knuckles on each hand.\n");
  set_level(21);
  set_hp(1000); 
  set_ac(28);
  set_heal(1+random(2),1);
  set_wc(45);
  set_wc_bonus(46);
  set_al(-140);
  set_aggressive(1);
  set_chat_chance(4);
  set_a_chat_chance(1);
  load_chat("Jerek growls at you.\n");
  load_chat("Jerek watches you.\n");
  load_chat("Jerek makes a fist.\n");
  load_chat("Jerek says: I am a master fighter.\n");
  load_chat("Jerek says: Your death shall be a painful one.\n");
  load_chat("Jerek glares at you.\n");
  load_a_chat("Jerek dodges to the side.\n");
  set_dead_ob(TO);
  call_out("hunt", 60);
   }
}

monster_died(){
  write_file("/players/zeus/log/museum", ctime(time())+"   "+
  capitalize((string)TP->QRN)+" defeated Jerek.\n");
   "/players/zeus/museum/lounge.c"->npc4();
  move_object(clone_object("/players/zeus/museum/OBJ/kblades.c"),
    environment());
}

damage_function(){
  if(!present(AO, environment())) return 0;  
  new_hp = hit_point;
  damage = (old_hp - new_hp);
  if(damage > 38)
  {
    TR(environment(),
      "\nJerek jumps at "+OQN+"....\n\n"+
      HIR+"  -= SLASH =-\n"+NORM+
      RED+"\t\t - -- == SLASH == -- -\n"+NORM+
      HIR+"\t\t\t\t\t    -= SLASH =-\n\n"+NORM+
      OQN+" staggers back, blood running down "+OQP+" body...\n\n", ({AO}));
    tell_object(AO,
      "\nJerek jumps at you....\n\n"+
      HIR+"  -= SLASH =-\n"+NORM+
      RED+"\t\t - -- == SLASH == -- -\n"+NORM+
      HIR+"\t\t\t\t\t    -= SLASH =-\n\n"+NORM+
      "You stagger back, blood running down your body...\n\n");
    AO->hit_player(50+random(40));
  }
  old_hp = new_hp;
}


opponent_heal_function(){
  if(!present(AO, environment())) return 0;  
  new_opp_hp = (int) AO->query_hp();
  heal = (new_opp_hp - old_opp_hp);
  if(heal > 75)
  {
    TR(environment(),
      "\nJerek runs at "+OQN+", slashing at "+OQP+" stomach...\n"+
      OQN+" is eviscerated by Jereks claws...\n"+
      OQP+" intestines spilling forth...\n\n", ({AO}));
    tell_object(AO,
      "\nJerek runs at you, slashing at your stomach...\n"+
      "\t\tYou are eviscerated by Jereks claws...\n"+
      "\t\t\t\t\tYour intestines spilling forth...\n\n");
    AO->hit_player(-heal + (heal/5));
  }
  old_opp_hp = new_opp_hp;
}

hunt(){
  string w;
  if(!environment()) return;
  if(!sscanf(file_name(environment()), "players/zeus/museum/arena/%s", w))
	  return;
  call_out("hunt", 30+random(15));
  if(!nmy) return;
  if(!sscanf(file_name(environment(nmy)), 
	  "players/zeus/museum/arena/%s", w)) return;
  if(!nmy->query_ghost() && !present(nmy, environment()))
  {
	  move_object(this_object(), environment(nmy));
    tell_room(environment(this_object()), 
      "Jerek charges into the room...\n\n");
	  TO->attack_object(nmy);
	  return;
  }
}

side_attack(object sickem){
  if(!sickem) return;
  if(present(sickem, environment()))
  {
    tell_room(environment(), "Jerek spins as his claws rip into "+
      sickem->query_name()+"!\n"+RED+"Blood "+
      "drips from "+sickem->query_name()+" onto the floor.\n"+NORM,
      ({ sickem }));
    sickem->hit_player(30);
  }
}

void heart_beat(){
  ::heart_beat();
  if(!environment()) 
    return ;
  if(!AO)
  {
    old_opp_hp = 1000;
    return ;
  }
  nmy = AO;

  damage_function();
  opponent_heal_function();
  if(!random(2))
  {
    if(!AO->query_ghost())
    {
      already_fight = 0; ::attack();
    }
  }
  if(AAO && !random(5))
    side_attack(AAO);
}
