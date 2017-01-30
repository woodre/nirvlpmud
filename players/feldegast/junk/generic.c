#define MAX_ALIGNMENT -1000
#include "/players/feldegast/defines.h"

inherit "/obj/monster.c";

int calc_exp();
int calculate_worth();

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("gene");
  set_alias("generic");
  set_short("Generic Monster");
  set_long("Command: level\n");
  set_level(1);
  set_wc(1);
  set_ac(1);
  set_hp(1);
  alignment=-1000;
}

void init()
{
  ::init();
  add_action("cmd_level","level");
}

int cmd_level(string arg)
{
  int *wc_a,*ac_a,*hp_a;
  int l;
  hp_a=({ 0,15,30,45,60,75,90,105,120,135,150,165,180,195,210,225,400,425,450,475,500,1000 });
  wc_a=({ 0,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,22,24,26,28,30,50 });
  ac_a=({ 0,3,3,4,4,5,5,6,7,7,8,9,9,10,11,12,13,14,15,16,17, 23 });
  if(!arg) return 0;
  sscanf(arg,"%d",l);
  write("You set the test monster's level to "+l+".\n");
  experience=0;
  set_level(l);
  set_hp(hp_a[l]);
  set_wc(wc_a[l]);
  set_ac(ac_a[l]);
  write("New experience = "+experience+"\n");
  calc_exp();
  return 1;
}

int calc_exp()
{
  int wa_bonus, exp_diff, exp_bonus, base_bonus;

      if (is_npc && experience > 1000000) {
	 experience = 1000000;
	  }
      exp_diff= alignment - MAX_ALIGNMENT;
      if (exp_diff < 0)
	exp_diff = -exp_diff;   /* Get absolute value */
      exp_diff /= 10;   /* Scale this down so we don't overflow! */
      exp_bonus = experience / 100;
      exp_bonus *= exp_diff;
      exp_bonus /= 1800; /* ALIGN_EXP_DIVISOR */
      /* Base bonus regardless of alignment is experience/75 */
      base_bonus = experience/190; /* EXP_DIVISOR; */
  write("Base Xp = "+base_bonus+"\n");
      /* Don't let the alignment bonus exceed 1/2 the base bonus */
      if (exp_bonus > base_bonus/2)
	exp_bonus = base_bonus/2;
  write("Align Bonus = "+exp_bonus+"\n");
      exp_bonus += base_bonus;
      wa_bonus = weapon_class * armor_class * 3; /* WA_FACTOR; */
      if (wa_bonus > base_bonus/3)
	   wa_bonus = base_bonus/3;
  write("Wc/Ac Bonus = "+wa_bonus+"\n");
       exp_bonus += wa_bonus;
  exp_bonus+=hit_point;
  write("Hit bonus = "+hit_point+"\n");

  write("--------------\n");
  write("Total = "+exp_bonus+"\n");
  write("Snow xp = "+calculate_worth()+"\n");
  return 1;
}

int calculate_worth() {
  int hp_factor, wc_factor, ac_factor, exp_worth;

  hp_factor = (max_hp / 50) + 1;

  wc_factor = weapon_class;
  wc_factor += spell_chance * spell_dam / 100;

  ac_factor = armor_class;
  ac_factor += (heal_rate * 3) / heal_intv;

  exp_worth = hp_factor * wc_factor * ac_factor;
  return exp_worth;
}
