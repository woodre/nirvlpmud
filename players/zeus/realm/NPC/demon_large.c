inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
int eat;
object nmy;

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("a huge cursed demon");
  set_short("A huge cursed demon");
  set_race("demon");
  set_gender("creature");
  set_long(
"This is a large red demon.  Its massive body is bulging with muscles.\n"+
"It is hunched way over, its powerful arms dragging on the ground.  Large\n"+
"claws protrude from its hands and feet.  A constant grin adorns its face,\n"+
"which is highlighted by two glowing red eyes.  This is a creature of pure\n"+
"evil, its only purpose to cause pain and agony to all who encounter it.\n");
  set_wc(30);
  set_wc_bonus(44);
  set_ac(7);
  set_level(22);
  set_hp(550);
  set_aggressive(1);
  set_al(-1000);
  set_dead_ob(TO);
   }
}
id(str){ return str == "demon" || str == "daemon" || str == "cursed demon"
|| str == "a huge cursed demon"; }

monster_died()
{
  write("As the huge demon slumps to the ground, you plunge your weapon\n"+
    "into the demons chest and cut out its heart.\n");
  MO(CO("/players/zeus/heals/demon_heart.c"), AO);  
  DD->add_kills(attacker_ob, 1);
}

attack_special()
{
  if(!present(attacker_ob, environment())) return;
  TR(environment(TO),
    "The cursed demon slashes "+AO->QN+" with its huge claws...\n"+
    AO->QN+" staggers backwards and blood gushes forth...\n", ({AO}));
  tell_object(AO,
    "The cursed demon slashes you with its huge claws...\n"+
    "You stagger backwards and blood gushes forth...\n");
  AO->hit_player((int)AO->query_level()+
    random((int)AO->query_extra_level())+random(10));
  return;
}


heart_beat()
{
  ::heart_beat();
  if(!environment()) 
    return ;
  if(AO)
  {
    nmy = AO;
    if(environment(AO) == environment())
    {
      eat = ((int)AO->query_level()+random((int)AO->query_extra_level())-random(5));
      if(eat > 50) eat = 50;
      AO->hit_player(eat);
    }
    if(!random(9))
      attack_special();  
    return ;
  }
  else if(!AO)
  {
    if(!nmy) return ;
    if(present(nmy, environment()))
    {
      if(!present(nmy, environment())->query_ghost())
      {
        TR(environment(), "The cursed demon roars in anger!\n");
        TO->attack_object(nmy);
      }
    }
  }
}

calculate_worth(){
  if(nmy && nmy->is_player())
    set_wc_bonus(nmy->query_level() + (nmy->query_extra_level() / 2) + 40);
  return ::calculate_worth();
}
