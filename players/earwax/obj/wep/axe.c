/*
 *      File:                   filename.c
 *      Function:               
 *      Author(s):              YourName@Nirvana
 *      Copyright:              Copyright (c) 2004 YourName
 *                                      All Rights Reserved.
 *      Source:                 05/24/2004
 *      Notes:                  
 *      Change History:
 */
 
/* General overview:
 * Wears more slowly:  when maxed, it wears at 20% the normal rate for weapons.
 * Does the most average damage of any current weapons - it's a two-hander, one
 * that deals damage based off how high it's trained and the xlevel of the
 * wielder - so only a +100 with the weapon maxed will attain that level of
 * damage.  For others, it'll range from being a crappy weapon to a normal high-
 * end weapon.  Specials based off AHP - 50% at 50% AHP, as it lowers chance is 
 * higher, at 90% AHP chance is 10%, so on and so forth.  I may have to lessen
 * the impact - ie, grant base 50% chance, and adjust it based on that, but for
 * now I'd rather it be purely based on AHP.  Also has a bhead special, but it's
 * a fatality that's probably even at max less likely to hit than any guild 
 * fatality.  It's just something thematic and nice.
*/

#include <ansi.h>

#define WC 20
#define WEPD "/players/earwax/obj/wep/wepd.c"

inherit "/players/vertebraker/closed/std/weapon.c";

/* Global Variables */
static object  CurrentOwner;
static int     CurrentHits;
static int     CurrentLevel;
static string  CurrentName;
static int     LastHits;
static int    *AxeLevels;

status id(string arg)
{
  return arg == "axe" || arg == "lochaber axe" || arg == "blood-bath"
    || arg == "bloodbath, the lochaber axe" || arg == "weapon" || arg == "lochaber"
    || arg == short_desc || arg == cap_name || arg == "bloodbath";
}

void reset(status arg)
{
  ::reset(arg);
  
  if (arg)
    return;
    
  set_name(RED+"Bloodbath"+NORM);
  set_class(WC);
  set_short(cap_name);
  set_type("axe");
  set_weight(9);
  set_value(2000); /* Going to have a specific query_value function anyway */
  set_two_handed(1);
  long_desc = short_desc+" is a Lochaber Axe about six feet long.  It's comprised of a\n\
six-foot pole to the top and bottom of which are steel ferrules, the\n\
business end also having a wicked foot-long spike and a long curved \n\
hook on one side, and a two-foot blade that comes to a razor-sharp \n\
point at its top, but is almost a foot thick at its base.  This is a \n\
brutally effective weapon that is as capable of pulling cavalry off \n\
their mounts, as actually beheading them.  The steel is of such high\n\
quality that it rarely needs sharpening, especially when wielded by \n\
one experienced with it.  It takes much practice and experience to \n\
attain such mastery but well-worth it, to have complete control over\n\
such a devastating weapon.\n";
  set_hit_func(this_object());
  AxeLevels = ({
    0,     /*  0:    0 */
    100,   /*  1:  100 */
    300,   /*  2:  200 */
    600,   /*  3:  300 */
    1100,  /*  4:  500 */
    1900,  /*  5:  800 */
    3200,  /*  6: 1300 */ 
    5300,  /*  7: 2100 */
    8700,  /*  8: 3400 */
    14200, /*  9: 5500 */
    23100, /* 10: 8900 */
  });
}

void do_behead(object ob)
{
  if (!ob) return;
  call_out("behead", 0, ob);
}

void do_beheading(object ob)
{
  object here;
  string obname;
  int atthp, attmhp;
  
  if (!ob) return;
  
  here = environment(ob);
  obname = (string)ob->short();
  if (!obname) obname = (string)CurrentOwner->query_possessive()+" foe";
  atthp = (int)ob->query_hp(); attmhp = (int)ob->query_mhp();
  
  if (10*atthp/attmhp >= 1)
    return;
  
  if (environment(ob) != environment(CurrentOwner))
    return;
  
  tell_room(here, HIK+"\n\n With a mighty swing, \n     "
    +(string)CurrentOwner->query_name()+" charges forward with "+(string)CurrentOwner->query_possessive()+" lochaber axe, "
    +short_desc+HIK+
    "\n          at "+obname+", practically cleaving the body in half!\n\n\n"+NORM, ({ ob, CurrentOwner }));
    
  tell_object(ob, HIK+"\n\n With a mighty swing at you, \n     "
    +(string)CurrentOwner->query_name()+" charges at you with "+(string)CurrentOwner->query_possessive()+" lochaber axe, "
    +short_desc+HIK+
    ".\n          Your world goes black and you know no more.\n\n"+NORM);
    
  tell_object(CurrentOwner, HIK+"\n\n With a mighty swing, \n     You charge forward with your trusty lochaber axe "
    +short_desc+HIK+" and cleave "+obname+" with all your strength, \n          cackling with glee as you practically split the body in half.\n\n\n"+NORM);
    
  ob->heal_self(-atthp);
  ob->hit_player(1000, "other|earwax");
  CurrentOwner->add_spell_point(-random(51));
}
    
void new_level()
{
  CurrentLevel++;
  WEPD->set_info(CurrentName, CurrentHits, CurrentLevel);
  set_class(WC+(CurrentLevel/2));
  tell_object(CurrentOwner, HIK+"Your mastery of "+short_desc+HIK+" has increased.\n"+NORM);
}

void init()
{
  ::init();
  add_action("do_save", "save");
  
  if (environment(this_object()) == this_player() && this_player() != CurrentOwner)
  {
    int *axeinfo;
    
    CurrentOwner = this_player();
    CurrentName = (string)this_player()->query_real_name();
    axeinfo = (int*)WEPD->query_info(CurrentName);
    if (!axeinfo) axeinfo = ({ 0, 0 });
    CurrentHits = axeinfo[0];
    CurrentLevel = axeinfo[1];
    LastHits = hits;
    set_class(WC+(CurrentLevel/2));
  }
}

int query_axe_level()   { return CurrentLevel; }
int query_axe_hits()    { return CurrentHits;  }
string query_axe_name() { return CurrentName;  }

status do_save(string arg)
{
  WEPD->set_info(CurrentName, CurrentHits, CurrentLevel);
  return 0;
}

int weapon_hit(object attacker)
{
  int thits, xlev, tdam;
  int atthp, attmhp;
  
  if (!attacker || !CurrentOwner || !environment() 
  || environment(this_object()) != CurrentOwner)
    return 0;
    
  xlev = (int)CurrentOwner->query_extra_level();
  atthp = (int)attacker->query_hp();
  attmhp = (int)attacker->query_mhp();
  
  if (LastHits < hits)
  {
    thits = (hits - LastHits);
    CurrentHits += thits;
    
    if (CurrentLevel < 10) /* Costs HP/SP to max it too :) */
      CurrentOwner->heal_self(-1);
    
    if (CurrentLevel < 10 && AxeLevels[CurrentLevel+1] < CurrentHits)
    {
      new_level();
    }
    
    /* As the player becomes more proficient with this weapon, wear slows */
    if ( CurrentLevel && random(CurrentLevel/2) )
    {
      hits = LastHits; 
    }
 
    /* Some extra unblocked damage, but only on hits */     
    tdam = 5+random(xlev/10);
    attacker->hit_player(tdam, "other|earwax");
    atthp -= tdam;
    
    /* A beheading special that very rarely hits even with max weapon */
    if (attacker && atthp < 100 && ((atthp*100)/attmhp) <= random(CurrentLevel) )
      do_beheading(attacker);
      
    if (!attacker) 
      attacker = (object)CurrentOwner->query_attack();
        
    if (!attacker) 
      return 0;
  }
  else if ( CurrentLevel && misses && random(CurrentLevel/2) )
  {
    misses--; /* Slow wear further */
  }
    
  atthp = (int)attacker->query_hp();
  attmhp = (int)attacker->query_mhp();

  /* Special hits more often as the mob gets lower in hps */
  if ( random(100) > ((100*atthp) / attmhp) )
  {
    tdam = 2 + (xlev/10) + CurrentLevel;
    
    if (random(tdam) < 5)
      tdam = 5;
      
    attacker->hit_player(tdam); 
  }
  if (!attacker) attacker = (object)this_player()->query_attack();
  if (!attacker)
    return 0;
    
  atthp = (int)attacker->query_hp();
  
  if ( attacker && atthp < 100 && ((atthp*100)/attmhp) < random(CurrentLevel) )
    do_beheading(attacker);
  
  LastHits = hits;
  return random(CurrentLevel/2); /* This will rarely affect damage much */
}
/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */

int wield(string arg)
{
  if ((int)CurrentOwner->query_attrib("str") < 30)
  {
    notify_fail("You aren't strong enough to wield "+short_desc+".\n");
    return 0;
  }
  
  if ((object)CurrentOwner->query_attack())
  {
    notify_fail("Your attention is too diverted to wield the axe!\n");
    return 0;
  }
  
  LastHits = hits;
  return ::wield(arg);
} 
 
void long(string arg)
{
  int wear; string t;

  wear = (int)query_wear();
  write(long_desc);
  
  if ((status)environment(this_object())->is_player())
  {
    if (this_player() == CurrentOwner)
    {
      switch(CurrentLevel)
      {
        case 0:  write("You have absolutely no skill with this weapon.\n"); break;
        case 1:  write("You have almost no skill with this weapon.\n"); break;
        case 2:  write("You have started to gain some skill with this weapon.\n"); break;
        case 3:  write("You are marginally skilled with this weapon.\n"); break;
        case 4:  write("You are almost skilled with this weapon.\n"); break;
        case 5:  write("You are skilled with this weapon.\n"); break;
        case 6:  write("You are highly skilled with this weapon.\n"); break;
        case 7:  write("You are an "+BLU+"expert"+NORM+" with this weapon.\n"); break;
        case 8:  write("You are a "+BLUE+"master"+NORM+" with this weapon!\n"); break;
        case 9:  write("You are a "+HIB+"GrandMaster"+NORM+" with this weapon!\n"); break;
        case 10: write(HIK+"Your mastery with the "+short_desc+HIK+" is complete.\nYou are one with your weapon.\n"+NORM);
      }
    }
  }              
  
  t = (string)enchant_long();
  if (t) write(t);
  write("It is ");  
  if (wear < 40) write("like new.\n");
  else if (wear < 100) write("a little worn.\n");
  else if (wear < 200) write("somewhat worn.\n");
  else if (wear < 400) write("worn.\n");
  else write("well worn.\n");
}
   
