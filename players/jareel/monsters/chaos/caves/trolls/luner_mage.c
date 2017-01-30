inherit "/obj/monster";
#include "/players/jareel/define.h"
#include "/players/jareel/ansi.h"


id(str) { return str == "olimite" || str == "human" || str == "mage" || str == "lunar"; } 

/* Global Variables */
int stuff;
int lives;
int M;
int sword;
int staff;
int L;

int My_Mhp;
int Rounds;
int Extra_Dam;
int Total_Wc;
int Total_Ac;

  
  
  
reset(arg){
  object scar;
  stuff = random(2);

    ::reset(arg);
  if (arg) return;
  lives = 3;
  set_name("olimite");
  set_race("human");
  set_gender("male");
  set_al(-1000);
  set_level(26);
  set_hp(1000); My_Mhp = max_hp;
  set_ac(90);
  set_dead_ob(TO);
  
  if(stuff == 0) { /* Dual Swords - Main Armor */ 
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/mondar_armor2.c"),this_object());
      init_command("wear armor");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      sword = present("iron bastard sword",this_object());
      sword->set_short("Iron Bastard Sword (offwielded)");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword"); 
    set_wc(11);    
  }

  if(stuff == 1){ /*Death Sword - Shield */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/mondar_shield.c"),this_object());
      init_command("wear shield");
    MOCO("/players/jareel/weapons/mondar_death_sword.c"),this_object());
      init_command("wield sword");
    set_wc(11);
  }

  

  set_short("Olimite");
  set_long(
    "Mondar is an old wrinkled man.  Having seen many\n"+
    "years of battles, his silver-white hair and scar \n"+
    "ridden body prove he is not someone to mess with.\n"+
    "A small lump rises in the back of your throat as\n"+
    "he catches you looking at him.\n");

  Total_Wc = this_object()->query_wc();
  Total_Ac = this_object()->query_ac();
  Rounds = 1;
  
}

life_check(){
  int temp;
  
  if(!present(attacker_ob, environment())) return;
    lives--;
  tell_room(environment(), 
    BOLD+BLK+"\nOlimte heals his wounds.\n\n"+NORM);
  
  temp = 50+random(11); 
  My_Mhp += temp;
  hit_point += temp;
  set_wc(query_wc() + 1 + random(2));
  set_ac(query_ac() + 1 + random(2));

}
 
heart_beat() {
  object       ob;
  ::heart_beat();
  corpse_loop();

  if(!attacker_ob) {
    return;
  }
  
 
  if(lives && hit_point <= 200)
    life_check();

  Rounds ++;
  Total_Wc += this_object()->query_wc();
  Total_Ac += this_object()->query_ac();
  M = random(10);

  if (!attacker_ob) {
    return;
  }

  switch(M) {          
    case 0..2: M_parry(); break;       /* 30% Emote                                      */
    case 3:    M_fistsmash(); break;   /* 10% deals random(25)+10  Avg 22 - Damage       */
    case 4:    M_heal(); break;        /* 10% heals random(51)     Avg 25 - Self-healing */ 
    case 5:    M_heal2(); break;       /* 10% heals random(51)     Avg 25 - Self-healing */
    case 6:    M_allied(); break;      /* 10% deals random(51)+50  Avg 75 - Damage       */
    default:   M_bladesharp(); break;  /* 30% deals random(31)+5   Avg 20 - Damage       */
  }

  if (lives == 1) {
    My_Mhp += 4;
    hit_point += 4;
  }
  else {
    My_Mhp += 3;
    hit_point += 3;
  }   
}

/* Note: changed all these to random(oddnumber) to make averages integers */
M_parry() {
    tell_room(environment(TO),
    "Olimite does nothing.\n");
}

M_fistsmash()  {
  int t;
  tell_room(environment(TO),
    "Olimite does damage.\n");
  t = 500;
  Extra_Dam += t;  
  call_other(attacker_ob,"hit_player",t);
}

void M_heal() { 
    int t;
    tell_room(environment(TO),
      "Olimite Heals\n"+
      "Olimite heal spam\n");
    t = 500;
    My_Mhp += t;
    heal_self(t);
}

void M_heal2()  {
    int t;
    tell_room(environment(TO),
    "Olimite heals some more\n"+
    "Olimite heals even more\n");
    t = 500;
    My_Mhp += t;
    heal_self(t);
}

void M_bladesharp() {
  int t;
  tell_room(environment(TO),
      "Olimite does Damage.\n"+
      "\n"+
      "\n"+
      "\n");
  t = 500;
  Extra_Dam += t;
  call_other(attacker_ob,"hit_player",t);
}

void M_allied()  {
    int t;
    tell_room(environment(TO),
      "Olimite does a lot of damage\n"+
      "\n"+
      "\n"+
      "\n");
    t = 500;
    Extra_Dam += t;
    call_other(attacker_ob,"hit_player",t);
}

void corpse_loop()    {
  object ob;
  if((ob = present("corpse", environment())) && (int)ob->is_corpse()) {
    tell_room(environment(),
      "Olimite takes: "+(string)ob->short()+".\n");
    move_object(ob, this_object());
    this_object()->corpse_loop();
  }
}
monster_died() {
  if(objectp(sword)) sword->reset();
  log_file("jareel.olimite.exp", ctime()+": "+this_object()->calculate_worth()+"\n");
  return 0;
}

/* Manually calculate worth here */
/* Copied and modified from /obj/living.c code */
calculate_worth() {
  int hp_factor, wc_factor, ac_factor, exp_worth;
  int hp_diff,tmp_hp,x;

/* up to 2000 hp is weighted normally
   for each additional 1000hp 10 is added
   to the divisor (/60, /70, etc)
*/
   tmp_hp = My_Mhp;
   x = 1;
   hp_factor = 0;
   while(tmp_hp>2000) {
     hp_diff = tmp_hp-2000;
     if(hp_diff > 1000)
       hp_diff = 1000;
     hp_factor += hp_diff / (50+10*x);
     x++;
     tmp_hp -= hp_diff;
   }
   hp_factor += tmp_hp/50;
    
/* This gets WAY too inflated for values > 1000
  hp_factor = (max_hp / 50) + 1;
*/
/* did this manually by adding all heals to his max hit points
  hp_factor += hp_bonus / 50;
*/
/* using this just as a guideline 
  wc_factor = this_object()->query_damage_potential();
  if(!wc_factor)
    wc_factor = this_object()->query_wc();
  wc_factor += this_object()->query_spell_chance() * this_object()->query_spell_dam()/ 200;
  wc_factor += this_object()->query_spell_exp();
  wc_factor += wc_bonus;
*/
  /* Calculate wc_factor here */
  wc_factor  = Total_Wc  / Rounds; /* His average weapon-class over the fight  */
  wc_factor *= 2;                  /* He has an extra attack() call per round  */
  wc_factor += Extra_Dam / Rounds; /* From the 3 spells driven by heart_beat() */


/* Once again, using this as a guideline 
  ac_factor = this_object()->query_defense_potential();
  if(!ac_factor)
    ac_factor = this_object()->query_ac();
   if(this_object()->query_heal_rate() > 0 && this_object()->query_heal_intv() > 0)
      ac_factor += (this_object()->query_heal_rate() * 3) / this_object()->query_heal_intv();
  ac_factor += ac_bonus;
*/
  ac_factor  = Total_Ac /Rounds;

#ifdef DEBUG
tell_room(environment(find_player("jareel")), "STATS ARE AS FOLLOWS: \n");
tell_room(environment(find_player("jareel")), "My_Mhp: "+My_Mhp+"\n");
tell_room(environment(find_player("jareel")), "Total_Wc: "+Total_Wc+"\n");
tell_room(environment(find_player("jareel")), "Total_Ac: "+Total_Ac+"\n");
tell_room(environment(find_player("jareel")), "Extra_Dam: "+Extra_Dam+"\n");
tell_room(environment(find_player("jareel")), "=========================\n");
tell_room(environment(find_player("jareel")), "hp_factor: "+hp_factor+"\n");
tell_room(environment(find_player("jareel")), "wc_factor: "+wc_factor+"\n");
tell_room(environment(find_player("jareel")), "ac_factor: "+ac_factor+"\n");
#endif

  exp_worth = 1;
  if(hp_factor) exp_worth*= hp_factor;
  if(wc_factor) exp_worth*= wc_factor;
  if(ac_factor) exp_worth*= ac_factor;
  if(exp_worth < 0) {
    log_file("NEG_EXP",ctime()+" "+file_name(this_object())+"\n");
    exp_worth=0;
  }
#ifdef debug
tell_room(environment(find_player("jareel")), "=========================\n");
tell_room(environment(find_player("jareel")), "exp_worth: "+exp_worth+"\n");
#endif
  return exp_worth;
}
