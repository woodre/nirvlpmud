/*
 *     hex.c             
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
    move_object(clone_object("/players/katya/area/mountain/o/hpouch.c"),
      this_object());
  }

     set_name("Hex Goblinitter");
     SetMultipleIds(({"hex","goblinitter","hex goblinitter", "fairy"}));     
     set_short("Hex Goblinitter");
     set_race("fairy");
     set_long("\
   Hex Goblinitter has a fairy, with blue straight hair.  His wings\n\
are bright blue and sparkle in the sunlight.  Hex is wearing a \n\
small blue outfit, with a silk pouch to his side, which he carries\n\
his fairy dust in.\n");
     set_gender("male");
     set_level(20);
     set_ac(18 + random(10));
     set_wc_bonus(37);
     set_wc(35 + random(10));
     set_hp(2000 + random(500));
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
    "\n\t"+query_name()+" showers you in "+HIB+"fairy dust!\n\n"+
RED+"                                                                 *"+NORM+"\n"+
BLU+"             *"+NORM+"\n"+
YEL+"                                               *"+NORM+"\n"+
GRN+"                                                                            *"+NORM+"\n"+
HIK+"                       *                                     *"+NORM+"\n"+
WHT+ "                                             *"+NORM+"\n"+
MAG+"       *"+NORM+"\n"+
"You agonize in pain!\n");
  tell_room(environment(),
    "\n\t"+query_name()+" showers "+attacker_ob->query_name()+"  in "+HIB+"fairy dust!\n\n"+
RED+"                                                                 *"+NORM+"\n"+
BLU+"             *"+NORM+"\n"+
YEL+"                                               *"+NORM+"\n"+
GRN+"                                                                                      *"+NORM+"\n"+
WHT+ "                                             *"+NORM+"\n"+
MAG+"       *"+NORM+"\n"+
    attacker_ob->query_name()+" agonizes in pain!!\n",
    ({ attacker_ob }));
    
  attacker_ob->hit_player(50+random(50),"magical");
}

