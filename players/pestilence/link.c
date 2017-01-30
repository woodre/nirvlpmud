inherit "/obj/monster.c";
#include "/players/fred/ansi.h";
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
    " What do you expect? its"+HIG+" Link"+NORM+" The hero of legend. Long green robes.\n"+
    "cover this hero's body. it appears he is carring a entire armory! this"+HIY+" Hero"+NORM+".\n"+
    "appears to be very"+HIR+" D A N G E R O U S"+NORM+" beware. \n");
  add_money(8000+random(5000));
  set_level(26);
  set_hp(2000+random(500));
  set_al(-800);
  set_ac(32+random(4));
  set_wc(40);
  set_aggressive(0);
  move_object(clone_object("/players/sami/area/carnival/obj/armors/belt.c"),this_object());
init_command("wear belt");
  set_multi_cast(2);
  add_spell("super_jump",
  ""+HIG+"#MN#"+NORM+" finds his "+HIR+"mark"+NORM+" and"+HIC+"Devistates"+NORM+"you with his "+HIY+"A R R O W"+NORM+"\n",
  " "+HIG+"#MN#"+NORM+"strikes #AKN# in the "+HIR+"S K U L L"+NORM+" with his "+HIY+"A R R O W"+NORM+"\n",
  50,({25,25}),({"other|fire","other|light"}),1);
   add_spell("Bomb_om", 
 HIG+" Link "+NORM+"pulls a out a "+HIB+"B O M B"+NORM+"and throws it at YOU"+HIR+"\n"+
"                       @@@@@@@@   @@@@   @@@@@@@@      @@@@@@@@\n"+
"                       @@@@@@@@   @@@@   @@@@   @@     @@@@@@@@\n"+
"                       @@@@       @@@@   @@@@    @@    @@@@\n"+
"                       @@@@       @@@@   @@@@     @@   @@@@\n"+
"                       @@@@@@@@   @@@@   @@@@@@@@@@@   @@@@@@@@\n"+ 
"                       @@@@@@@@   @@@@   @@@@@@@       @@@@@@@@\n"+
"                       @@@@       @@@@   @@@@ @@@      @@@@\n"+
"                       @@@@       @@@@   @@@@  @@@     @@@@\n"+
"                       @@@@       @@@@   @@@@   @@@    @@@@@@@@\n"+
"                       @@@@       @@@@   @@@@    @@@   @@@@@@@@"+NORM+"\n"+
" and you"+HIY+" burst "+NORM+"into "+HIR+"FLAMES "+NORM+"\n", 
  "Room Message",
  60,({45,20}),({"other|fire","other|evil"}),1);

  add_spell("Heal_spell",
    HIG+"Link"+NORM+" takes a"+HIY+"Fairy"+NORM+" in a bottle from under his cloak.\n",
    HIG+"Link"+NORM+" Eats the"+HIY+" Fairy"+NORM+" and feels"+HIR+"Rejuvenated"+NORM+".\n",
   30,"20-30",0,3,"heal_me");
 
 add_spell("Boomerang_toss",
  HIG+"Link"+NORM+"throws his "+HIY+"Boomerang"+NORM+" and "+HIR+"Chaos"+NORM+" is unleashed upon the room.\n"+
  HIG+"Link"+NORM+" catches the returning "+HIY+"Boomerang"+NORM+" and returns it within his robes.\n",
  "Room Message",
  60,({45,20}),({"other|physical","other|physical"}),1);
   }
      heart_beat() {
  object       ob;
  ::heart_beat();

  if(!attacker_ob) {
    return;
  }}

heal_me( object target, object room, int damage ) {
  int amt;
  amt = 50 + random(30);
  damage= 10 + random(20);
  set_hp_bonus( hp_bonus + amt );
  heal_self(amt);
}
