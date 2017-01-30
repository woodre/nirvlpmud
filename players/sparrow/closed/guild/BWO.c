/* Black Willow Order guild object
   A Vertebraker and Sparrow production
*/
#include <ansi.h>

inherit "/players/vertebraker/dev/guild_object";
inherit "/players/sparrow/closed/guild/std/methods.c";
#define OBJDIR "/players/sparrow/closed/guild/obj/";
#define AC_CAP 10

static status loaded;
static status bw_wield_flag;
object guildWep, donorWep;
int parish,renown,worth,guildXp,tLight;
static object shadow;
/* Parish Delegations Follow

   key:  delegation[0]: Choir
         delegation[1]: Merchants
         delegation[2]: Monestary
         delegation[3]: Craftsman

   More to follow, just wanted to get it set up - Sparrow
*/
int *delegate;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  guild_file=basename(this_object());
  guild_name="black_willow";
  cmd_dir="/players/sparrow/closed/guild/cmds/";
  save_dir="players/sparrow/closed/guild/save/"; /* must be missing prepending foreslash */
  set_heart_beat(1);

}

status id(string str){
  if(str=="notweapon") {
    return !bw_wield_flag;
  }
  return (status)::id(str) ||
     str=="black_willow_object" ||
     str=="dark_sight_object" ||
     str=="generic_wc_bonus";
}

short() {
  return 0;
}

long() { write("This is a temporary object for the Black Willow Order.\n"); }


init() {
  object BWM;
  BWM = environment(this_object());
  if(!BWM) return;
  if(!loaded)
  {
    shadow=clone_object("/players/sparrow/closed/guild/obj/player_shadow");
    shadow->start_shadow(BWM);

    BWM->RegisterArmor(this_object(), ({ "physical", 0, 0, "armor_special" }));
    loaded = 1;
  }
  ::init();
  if (!this_object()) return;
  if(BWM->query_guild_rank() == 0) {
    BWM->add_guild_rank(1);
  }
  if(!renown) {
    renown = 1;
  }
  if(!parish) {
    parish = 1;
  }
  if(!worth) {
    worth = 1;
  }
  /* delegations */
  if(!delegate) {
    delegate = ({0,0,0,0});
  }
}

extra_look() {
  object BWM;
  BWM = environment(this_object());
  if(this_player() == environment()) {
    write("You have soft whisps of "+HIK+"dark shadows"+NORM+" flowing out from your eye sockets!\n");
  }
  else {
    write((string)BWM->query_name()+" has soft whisps of "+HIK+
       "dark shadows"+NORM+" flowing out from "+possessive(BWM)+" eyes!\n");
  }
}

int modify_atk_chance(int x)
{
  int dex, luck, light_level;
  int chance;

  light_level=set_light(0);
  dex=(int)environment()->query_attrib("dex");
  luck=(int)environment()->query_attrib("luc");
  dex/=3;
  luck/=6;
  if(dex > 10) dex=10;
  if(luck > 5) luck=5;

  chance = x;
  chance += (light_level * -1);
  chance += dex;
  chance += luck;

  return chance;
}

void do_atk(object atk)
{
  int dam;
  string *msg;

  dam = (int)this_object()->get_rank_bonus();
  dam = random(dam);
  msg = (string *)this_object()->query_message_hit(dam);

  tell_object(environment(),
    "You "+msg[1]+" "+(string)atk->query_name()+msg[0]+".\n");
  tell_room(environment(environment()),
    (string)environment()->query_name()+" "+msg[1]+" "+(string)atk->query_name()+msg[0]+".\n", ({ environment() }));

  atk->hit_player(dam, "physical");
}

void multiple_attacks()
{

  int chance;
  object e, room;
  object ao;

  e = environment();
  if(!e) return;

  if(!(room=environment(e))) return;
  if(!(ao=(object)e->query_attack())) return;
  if(!present(ao, room)) return;


  chance = (int)e->query_guild_rank() * 15;
  if(chance > 99) chance = 99;
  chance = modify_atk_chance(chance);
  if(chance > 99) chance = 99;

  if(chance > random(100))
  {
    do_atk(ao);
    chance = (int)e->query_guild_rank() * 8;
    if(chance > 95) chance = 95;
    chance = modify_atk_chance(chance);
    if(chance > random(100))
    {
      do_atk(ao);
      chance = (int)e->query_guild_rank() * 5;
      if(chance > 90) chance = 90;
      chance = modify_atk_chance(chance);
      if(chance > 90) chance = 90;
      if(chance > random(100))
      {
        do_atk(ao);
      }
    }
    if(chance > 95) chance = 95;
  }


}

heart_beat() {
  object darkOb;
  string darkMs;
  int darkHp;
  object BWM;
  BWM = environment(this_object());
  if(!environment()) {
    set_heart_beat(0);
    return destruct(this_object());
  }
  darkOb = present("true_darkness", BWM);
  if(darkOb) {
    BWM->add_sp(-2);
  }
  if(BWM->query_guild_rank() == 20) {
    BWM->set_alignment(-1800);
  }	
  
  if(environment(BWM)->query_light() < 1) {
    switch(environment(BWM)->query_light()) {
      case -2..0:
        darkHp = 1;
        break;
      case -10..-3:
        darkHp = 2;
        break;
      case -18..-11:
        darkHp = 3;
        break;
      default:
        darkHp = 4;
    }
    switch(random(4)) {
      case 0:
        darkMs = BOLD+"The darkness whispers: '"+NORM+"Fear not for we will bind your wounds."+BOLD+"'\n"+NORM;
        break;
      case 1:
        darkMs = HIK+"The darkness infuses power into your body.\n";
        break;
      case 2:
        darkMs = "It feels as if the "+HIK+"shadows"+NORM+" flow through your very "+RED+"arteries"+NORM+".\n";
        break;
      case 3:
        darkMs = "Your parish has sent you energy through the "+HIK+"S"+HIW+"hadowplane"+NORM+"!\n";
        break;
    }
    /* BWO gains 1sp per hb in darkness, true_darkness takes 2 so they net -1  per round in darkness
         with true_darkness summoned */
      BWM->add_sp(1);
    if(BWM->query_hp() < BWM->query_mhp() ) {
      BWM->add_hp(darkHp);
      if(random(3) == 2 && !BWM->query_attack()) {
        tell_object(BWM, darkMs);
      }
    }
    if(BWM->query_sp() < 3) {
      darkOb->wink_out();
    }
  }
  multiple_attacks();
}

void addParish(int x) {
  if(x) {
    parish = parish + x;
  }
  return;
}

void addWorth(int x) {
  if(x) {
    worth = worth + x;
  }
  return;
}

void addDelegation(int job, int x) {
  if(job && x) {
    delegate[job] = x;
  }
  return;
}

int queryParish() {
  return parish;
}

int queryWorth() {
  return worth;
}

int *queryDelegation() {
  return delegate;
}

void setDonorWep(object w) {
  donorWep = w;
}

queryDonorWep() {
  return donorWep;
}

int proc_wep_specials(object atk) {
  string *fs;
  string special;
  int wc_return;
  int x, y;

  wc_return = 0;
  fs = get_dir("/players/sparrow/closed/guild/specials/");
  y = sizeof(fs);
  for(x=0; x < y; x ++) {
    if(!atk || atk->query_ghost()) return 0;
    sscanf(fs[x], "%s.c", special);
    wc_return += (int)call_other("/players/sparrow/closed/guild/specials/"+special, "main", atk);
  }
  return wc_return;
}


int get_rank_bonus() {
  object me;
  int wc_bonus;
  me = environment();
  wc_bonus=0;

  switch((int)me->query_guild_rank()) {
    case 1..4: wc_bonus += 10; break;
    case 5..6: wc_bonus += 12; break;
    case 7..8: wc_bonus += 13; break;
    case 9..10: wc_bonus += 14; break;
    case 11..12: wc_bonus += 15; break;
    case 13..14: wc_bonus += 16; break;
    case 15..16: wc_bonus += 17; break;
    case 17..18: wc_bonus += 18; break;
    case 19: wc_bonus += 19; break;
    case 20: wc_bonus += 20; break;
  }
    return wc_bonus;

}


int gen_wc_bonus() {
  object atk;
  object me;
  object room;
  int wc_bonus;
  int al_bonus;
  mixed *dp;
  int x;
  int light_bonus;
  int light_val;

  if(!(me = environment())) return 0;

  if(!(atk = (object)me->query_attack())) return 0;
  
  if(!present(atk, (room=environment(me)))) return 0;
  
  wc_bonus=0;
  wc_bonus += proc_wep_specials(atk);
  wc_bonus += get_rank_bonus();

  if(donorWep) {
    move_object(donorWep, me);
    bw_wield_flag=1;
    donorWep->wield((string)donorWep->query_name());
    dp = (mixed *)donorWep->query_params();
    for(x=2; x < sizeof(dp); x += 3)
      wc_bonus += (int)call_other(donorWep, dp[x], atk);
    donorWep->stopwield();
    bw_wield_flag=0;
    move_object(donorWep, this_object());
  }

  switch((int)me->query_alignment()) {

    case -666666..-500: al_bonus = 3; break;
    case -499..-250: al_bonus = 2; break;
    case -249..-1: al_bonus = 1; break;
    case 0: al_bonus = 0; break;
    case 1..250: al_bonus = -1; break;
    case 251..500: al_bonus = -2; break;
    case 501..750: al_bonus = -4; break;
    default: al_bonus = -5; break;
  }

  wc_bonus += al_bonus;
  light_val=set_light(0);
  
  if(light_val > 5) light_val = 5;
  
  else if(light_val < -5) light_val = -5;

  light_bonus = -light_val;
  wc_bonus += light_bonus;
  tell_object(me, HIR+"WC BONUS: "+NORM+wc_bonus+"\n");
  return wc_bonus;
}

void guild_login() {
  "/players/sparrow/closed/guild/obj/chatob"->resetchannel();
}

status display_notweapon_msg() {
  write("You may not wield weapons as a member of the Black Willow Order.\n");
  return 1;
}


int armor_special(object owner)
{
  object me;
  int owner_ac;
  int return_value;

  me=environment();

  owner_ac=(int)me->query_ac();

  if(owner_ac > AC_CAP)
    return_value -= (AC_CAP - owner_ac);

  return return_value;
}

void remove_object()
{
  if(shadow) destruct(shadow);
}