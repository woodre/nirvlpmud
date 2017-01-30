inherit "/obj/monster.c";
#include "/sys/lib.h"
#include <ansi.h>
#define tpn this_player()->query_name()
#define ATT USER->query_attack()

reset(arg) {
  ::reset(arg);
  if(arg) return;
        
  set_name("link");
  set_alias("link_1");
  set_race("hologram");
  set_short(""+HIG+"Link"+NORM);
  set_long(
    " What do you expect? its"+HIG+" Link"+NORM+" The hero of legend. Long green robes\n"+
    "cover this hero's body. It appears he is carrying an entire armory! This"+HIY+" Hero"+NORM+".\n"+
    "appears to be very"+HIR+" D A N G E R O U S"+NORM+" beware. \n");
  set_heal(20,10);
  set_level(27);
  add_money(12000+random(10000));
  set_hp(2000+random(500));
  set_hp_bonus(2000);
  set_al(-800);
  set_ac(32+random(4));
  set_wc(40);
  set_aggressive(0);
  set_armor_params("other|evil",0,25,0);
  set_armor_params("other|dark",0,25,0);
  set_armor_params("other|ice",0,25,0);
  set_armor_params("other|water",0,25,0);
  set_armor_params("other|magical",0,50,0);
  set_armor_params("other|fire",0,-50,0);
  move_object(clone_object("/players/sami/area/coinarea/obj/armor/shield.c"),this_object());
init_command("wear shield");
move_object(clone_object("/players/sami/area/coinarea/obj/wep/msword.c"),this_object());
init_command("wield sword");
  set_multi_cast(2);
  add_spell("light_arrow",
  ""+HIG+"#MN#"+NORM+" finds his "+HIR+"mark"+NORM+" and"+HIC+" devastates "+NORM+"you with his "+HIY+" A R R O W"+NORM+"\n",
  " "+HIG+"#MN#"+NORM+" strikes #TN# in the "+HIR+"S K U L L"+NORM+" with his "+HIY+"A R R O W"+NORM+"\n",
  40,({25,25}),({"other|light","other|light"}),1);
   add_spell("ice_arrow",
  ""+HIG+"#MN#"+NORM+" finds his "+HIR+"mark"+NORM+" and"+HIC+" devastates "+NORM+"you with his "+HIB+" A R R O W"+NORM+"\n",
  " "+HIG+"#MN#"+NORM+" strikes #TN# in the "+HIR+"S K U L L"+NORM+" with his "+HIB+"A R R O W"+NORM+"\n",
  40,({25,25}),({"other|ice","other|ice"}),1);
  add_spell("fire_arrow",
  ""+HIG+"#MN#"+NORM+" finds his "+HIR+"mark"+NORM+" and"+HIC+" devastates "+NORM+"you with his "+HIR+" A R R O W"+NORM+"\n",
  " "+HIG+"#MN#"+NORM+" strikes #TN# in the "+HIR+"S K U L L"+NORM+" with his "+HIR+"A R R O W"+NORM+"\n",
  40,({25,25}),({"other|fire","other|fire"}),1);
  add_spell("cross_slash",
  ""+HIG+"#MN#"+NORM+" slashes "+HIR+"you"+NORM+" in the"+HIC+" chest"+NORM+" with his downward slash.\n",
  " "+HIG+"#MN#"+NORM+" slashes "+HIR+"#TN#"+NORM+" in the"+HIC+" chest"+NORM+" with his downward slash.\n",
  40,({25,25}),({"other|earth","other|laser"}),1);
   add_spell("Bomb_om", 
 HIG+" Link "+NORM+"pulls a out a "+HIB+"B O M B"+NORM+"and throws it at YOU"+HIR+"\n"+
"               @@@@@@      @@@       @@@    @@@        @@@\n"+
"               @@@@@@@   @@   @@   @@   @@  @@@@@    @@@@@\n"+
"               @@@   @@  @@   @@   @@   @@  @@@ @@  @@ @@@\n"+
"               @@@   @@  @@   @@   @@   @@  @@@  @@@@  @@@\n"+
"               @@@@@@@@  @@   @@   @@   @@  @@@        @@@\n"+ 
"               @@@@@@@@  @@   @@   @@   @@  @@@        @@@\n"+
"               @@@   @@  @@   @@   @@   @@  @@@        @@@\n"+
"               @@@   @@  @@   @@   @@   @@  @@@        @@@\n"+
"               @@@@@@@   @@   @@   @@   @@  @@@        @@@\n"+
"               @@@@@@      @@@       @@@    @@@        @@@"+NORM+"\n"+
"              You"+HIY+" burst "+NORM+"into "+HIR+"FLAMES "+NORM+"\n", 
  " #TN# "+HIY+" bursts"+NORM+" into "+HIR+" FLAMES"+NORM+"\n",
  50,({45,20}),({"other|fire","other|good"}),1);

  add_spell("Heal_spell",
    HIG+"Link"+NORM+" takes a"+HIR+" Red Potion"+NORM+" in a bottle from under his cloak.\n",
    HIG+"Link"+NORM+" drinks the"+HIY+" Red Potion"+NORM+" and feels"+HIR+"Rejuvenated"+NORM+".\n",
   65,"20-30",0,3,"heal_me");
 
 add_spell("Boomerang_toss",
  HIG+"Link"+NORM+"throws his "+HIY+"Boomerang"+NORM+" and "+HIR+"Chaos"+NORM+" is unleashed.\n"+
  HIG+"Link"+NORM+" catches the returning "+HIY+"Boomerang"+NORM+" and returns it within his robes.\n",
  " "+HIG+"#MN#"+NORM+" destroys #TN# with a boomerang throw.\n",
  
  40,({45,20}),({"other|physical","other|physical"}),1);
   }
      heart_beat() {
  object       ob;
  ::heart_beat();

  if(!attacker_ob) {
    return;
  }}

heal_me( object target, object room, int damage ) {
  int amt;
  amt = 50 + random(80);
  damage = 25 + random(25);
  set_hp_bonus( hp_bonus + amt );
  heal_self(amt);
}
query_extra_level() { return 100; }
