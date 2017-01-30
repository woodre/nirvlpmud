
/* intended for use in /players/zeus/museum/arena/ rooms */
/*
wc bonus:
  1:15 clap   7
  1:12 twirl  10
  1:20 angel  10
  redo        80
*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
int z;
object armor;

reset(arg){
  ::reset(arg);
  if (!arg){

    armor = clone_object("/players/zeus/museum/OBJ/cloak.c");
    move_object(armor, this_object());
    init_command("wear cloak", this_object());

  z = 0;
  set_name("ani");
  set_short("Ani of the Night Sky");
  set_race("spirit");
  set_gender("female");
  set_long(
"Ani is a beautiful woman with short auburn hair with blond highlights.\n"+
"Her face is a portrait of determination and strength.  Just by looking\n"+
"at her posture you can tell this woman has overcome many hardships.\n"+
"She is wearing a black outfit with tall boots and numerous rings\n"+
"and necklaces.  A dark blue and black cloak hangs from her shoulders.\n"+
"You have a hard time diverting your eyes from her...\n");
  set_level(23);
  set_ac(24);
  set_wc(40);
  set_wc_bonus(107);
  set_heal(3,1);
  set_hp(1000);
  set_hp_bonus(120);
  set_aggressive(0);
  set_al(1400);
  set_chance(15);
  set_spell_dam(65);
  set_spell_mess1("Ani spins as winds explode from her body!\n");
  set_spell_mess2("Ani blasts you with the winds!\n");
  set_chat_chance(3);
  set_a_chat_chance(1);
  load_chat("Ani looks at you with powerful eyes.\n");
  load_chat("Ani seems to smile slightly.\n");
  load_chat("Ani grins with a strange darkness around her.\n");
  load_chat("You see a sparkle in her eyes.\n");
  load_a_chat("Ani explodes with rage.\n");
  set_dead_ob(TO);
   }
}

heart_beat(){
    ::heart_beat();
    if(!environment())    return ;
    if(!AO)   return ;
    if(weapon_class < 40)
      weapon_class = 40;
    if(!random(7)) wimpy();
    if(!random(15))	clap();
    if(!random(12)) twirl();
    if(!random(20)) angel();
    if(hit_point < 100) hit_point += 3;
    redo();
    z++;
    if(z > 70) anguish();
    if(attacker_ob == this_object())
    {
      stop_fight();
      stop_fight();
    }
}

anguish(){
  TR(environment(),
    "Ani wipes blood from her face and glares...\n"+
    "Her eyes shimmer with a cold darkness...\n");
  hit_point += 100+random(75);
  weapon_class = 45+random(30);
  z = - 5000;
  return 1;
}

monster_died(){
  write_file("/players/zeus/log/museum", ctime(time())+"   "+
       capitalize((string)TP->QRN)+" defeated Ani.\n");
   "/players/zeus/museum/lounge.c"->npc9();
}

redo(){
  if(!random(4)) again();
  if(!random(6)) again();
  if(!random(8)) again();
  if(!random(12)) again();
  if(!random(16)) again();
  if(!random(20)) again();
}

again()
{
  if(!AO) return;
  if(!AO->query_ghost()/* && AO->is_player() */)
  {
	already_fight = 0; ::attack();
  }
}

angel(){
  int x, y;
  y = (int)AO->query_attrib("ste");
  TR(environment(),
    "The figure of an angel rises from Ani...\n"+
    "A dark shadow is cast down upon her...\n\n");
  for(x = 0; x < (9 - (y / 5)); x ++)
  {
    if(AO)
    if(AO->query_ghost() && AO->is_player()) return;
    else 
    {
      already_fight = 0;
      ::attack();
    }
  }
}

twirl(){
  int hp, mhp;
  if(!AO) return 1;
  hp = (int)AO->query_hp();
  mhp = (int)AO->query_mhp();
  if((hp < (mhp / 2)) && hp > 25)
  {
    TR(environment(),
      "Ani spins as cold air whirls around her...\n"+
      AO->QN+" is sent sprawling by the winds...\n");
    AO->heal_self(-random(hp));
    return 1;
  }
  else 
  {
    TR(environment(),
      "Cold air explodes from Ani's hands...\n"+
      AO->QN+" is knocked back by the winds...\n");
    AO->hit_player(random(hp / 3));
    return 1;
  }
  return 1;
}

wimpy(){
  string *dirs, str;
  int x, rand;
  if(hit_point < (max_hp / 15)){
    TR(environment(),			"\n");
    dirs = environment()->query_dest_dir();
    rand = random(sizeof(dirs)-1);
    x = rand / 2 * 2;
    str = dirs[x + 1];
    str += "#";
    str += dirs[x];
    TO->MP(str);
    hit_point += 50;
  }
}

clap(){
  string *the_dirs;
  string str, place;
  int i, ran1, x, c;
  i = 1; c = 0;
  if(environment(AO) != environment()) return;
  if(!sscanf(file_name(environment()), 
    "players/zeus/museum/arena/%s", place)) return;
  TR(environment(), AO->QN+" is thrown back!\n", ({AO}));
  tell_object(AO,
    "A cold darkness wraps around Ani's hands...\n"+
    "Ani pushes the air away from her...\n"+
    "You are thrown back, slamming into the wall!\n\n");
  while(present(AO, environment()))
  {
    if(c > 5) break;
    for(x = 0; x < 3; x ++)
    {
      the_dirs = (environment()->query_dest_dir());
      ran1 = random(sizeof(the_dirs)-1);
      i = ran1 / 2 * 2;
      str = the_dirs[i+1];
      str += "#";
      str += the_dirs[i];
      AO->MP(str);
    }
    c++;
  }
  if(AO)
  AO->hit_player(60+random(75));
  hit_point += 30+random(30);
  if(AO)
  command("look",AO);
}
