
/* intended for use in /players/zeus/museum/arena/ rooms */
/*
wc bonus:
  1:15 clap   7
  1:12 twirl  10
  1:20 angel  10
  redo        80
*/
/*
//  2005.08.20 -Forbin
//  Changes:
//    AC 24 -> 35
//    WC 40 -> 66
//    HP 1000 -> 1300 + r600
//    set_heal 3,1 -> 12,3
//    15, 65 spell to 20 50-80 other|wind add_spell
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
  set_ac(34);
  set_wc(86);
  set_wc_bonus(107);
  set_heal(16,3);
  set_hp(1800+random(600));
  set_hp_bonus(120);
  set_aggressive(0);
  set_al(1400);
  add_spell("ettin_spell",
    "Ani spins as winds explode from her body!\n"+
    "You are knocked back as you are blasted with the winds.\n",
    "Ani spins as winds explode from her body!\n"+
    "#CTN# is knocked back as #TO# is blasted with the winds.\n",
    20, "50-80", "other|wind");  
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

query_z_museum_mob() { return 1; }

heart_beat(){
    ::heart_beat();
    if(!environment())    return ;
    if(!AO)   return ;
    if(query_wc() < 66)
      set_wc(66);
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
  set_wc(66 + random(30));
  z = - 5000;
  return 1;
}

monster_died(){
  write_file("/players/zeus/log/museum", ctime(time())+"   "+
       capitalize((string)TP->QRN)+" defeated Ani.\n");
   "/players/zeus/museum/lounge.c"->npc9();
  emit_channel("junk","\n(junk) "+HIY+"["+HIW+"Museum Arena"+HIY+"]"+NORM+" "+
    capitalize((string)this_player()->query_real_name())+
    " has defeated Ani of the Night Sky.\n\n"+NORM);   
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
  if(random(2)) return;
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
    AO->hit_player(1+random(hp/3),"other|wind");
    return 1;
  }
  else 
  {
    TR(environment(),
      "Cold air explodes from Ani's hands...\n"+
      AO->QN+" is knocked back by the winds...\n");
    AO->hit_player(1+random(hp / 3), "other|wind");      
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
