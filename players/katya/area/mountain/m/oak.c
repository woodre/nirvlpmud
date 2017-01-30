/*
 *     oak.c             
 *     Katya@Nirvana
 *     Copyright (c) 2007 Katya
 *     All Rights Reserved.
 *    
 */

#include <ansi.h>
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object gold;
    gold = clone_object("obj/money");
    gold->set_money(random(5000) + 5000);
    move_object(gold,this_object());
   if(!present("pouch"))
  {
    move_object(clone_object("/players/katya/area/mountain/o/opouch.c"),
      this_object());
  }

     set_name("Oak Iceshimmer");
     SetMultipleIds(({"oak","iceshimmer","oak iceshimmer", "fairy"}));     
     set_short("Oak Iceshimmer");
     set_race("fairy");
     set_long("\
   Oak Iceshimmer has blue wings with purple tips, her curly brown\n\
hair falls down her back to her feet.  She carries a silk pouch that\n\
contains her fairy dust over her right shoulder.  Her purple lace dress\n\
flows down to her feet, dancing in the wind.\n");
     set_gender("female");
     set_level(19);
     set_ac(17 + random(10));
     set_wc(30 + random(10));
     set_wc_bonus(37);
     set_hp(1500 + random(500));
     set_al(100);
     enable_commands();
   }
}

heart_beat()
{
  ::heart_beat();
  if(attacker_ob)
  {
    if(random(50) < 25) fairy_dust();
  }
}

fairy_dust()
{
  tell_object(attacker_ob,
    "\n\t"+query_name()+" showers you in "+HIM+"fairy dust!\n\n"+
RED+"                                                                 *"+NORM+"\n"+
BLU+"             *"+NORM+"\n"+
YEL+"                                               *"+NORM+"\n"+
GRN+"                                                                            *"+NORM+"\n"+
HIK+"                       *                                     *"+NORM+"\n"+
WHT+ "                                             *"+NORM+"\n"+
MAG+"       *"+NORM+"\n"+
"You agonize in pain!\n");
  tell_room(environment(),
    "\n\t"+query_name()+" showers "+attacker_ob->query_name()+"  in "+HIM+"fairy dust!\n\n"+
RED+"                                                                 *"+NORM+"\n"+
BLU+"             *"+NORM+"\n"+
YEL+"                                               *"+NORM+"\n"+
GRN+"                                                                            *"+NORM+"\n"+
HIK+"                       *                                     *"+NORM+"\n"+
WHT+ "                                             *"+NORM+"\n"+
MAG+"       *"+NORM+"\n"+
    attacker_ob->query_name()+" agonizes in pain!!\n",
    ({ attacker_ob }));
    
  attacker_ob->hit_player(50+random(50),"magical");
}


