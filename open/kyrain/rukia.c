/*    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */
inherit "/obj/monster";
#include <ansi.h>
 
 reset(arg) {
 ::reset(arg);
  if(arg) return;
  set_name("rukia");
  set_alt_name("kuchiki");
   set_race("Soul Reaper");
  set_alias("rukia");
  add_money(10000+random(10000));
  set_heal(4,4);
  set_short("Rukia Kuchiki");
  set_long("Rukia has jet black short hair."+
        "she is wearing a black kemono,\n"+
        "and is wielding a beautiful white sword.\n");
  set_level(26);/*Watch the level of the mob, bigger mob more u gotta add to him*/
  set_hp(1200+random(400));/*1700 hp max*/
  set_al(0);/*Neutral alignment*/
  set_wc(47);
  set_ac(20);
 /*This will give your NPC a item (weapon in this case)*/
  move_object(clone_object("/players/sami/examples/soden.c"),this_object());
  init_command("wield sword");/*This has the mob Wield the weapon*/

 /*some additions made by Sami to help you understand a few things and show you what can be done*/
  set_armor_params("other|fire",0,25,0);/*These here give your mobs resistances to the following elements by 25%*/
  set_armor_params("other|electric",0,25,0);
  set_armor_params("other|good",0,25,0);
  set_armor_params("other|magical",0,-50,0);/*This will make him weak to magical attack*/
  
  set_multi_cast(2);/*gives the mob a chance to multi-cast the following spells each round*/
                    /*This also gives you one Special Advantage*/
 add_spell("kido_shakkaho",
  ""+HIG+"#MN#"+NORM+" finds his "+HIR+"mark"+NORM+" and"+HIC+" devastates "+NORM+"you with her "+RED+"fireball"+NORM+"\n",
  " "+HIG+"#MN#"+NORM+" devastates #TN# with her "+RED+"fireball"+NORM+"\n",
  40,({25,25}),({"other|light","other|fire"}),1);
  
   add_spell("kido_byakurai",
  ""+HIG+"#MN#"+NORM+" holds his palm outright and "+HIY+"lightning"+NORM+" leaps from her hands "+YEL+"frying"+NORM+" you\n",
  " "+HIG+"#MN#"+NORM+" "+YEL+"frys"+NORM+" #TN# with "+HIY+"lightning bolts"+NORM+"\n",
  40,({25,25}),({"other|light","other|electric"}),1);
}