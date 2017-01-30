inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("scientist");
  set_alias("norm");
  set_race("human");
   set_hp_bonus(-10000);
  set_short("An important "+BOLD+"Scientist"+NORM);
  set_long(
    "A tall, short haired scientist stands here. His face hidden.\n"+
    " A badge rests upon his long white lab coat that reads 'Norm'.\n"+
	"            "+HIR+"DO NOT KILL."+NORM+" You have been warned.\n");
  set_level(27);
  set_hp(9500+random(499));
  set_al(800);
  set_heal(50,50);
 set_armor_params("other|evil",0,50,0);
 set_armor_params("other|physical",0,55,0);
 set_ac(90+random(20));
  set_wc(55);
  set_chat_chance(2);
  load_chat("Norm says: You must be new around these parts?\n");
  load_chat("Norm says: I've done it! Finaly, ive created a teleporter that\n"+
            "will take you across the galaxy! Dare to give it a try?\n");
  
 load_chat("Norm says: If you find any broken projectors, bring them to me. I'll buy them!\n");
  set_aggressive(0);
  set_multi_cast(1);
   add_spell("Justice_punch",
  ""+HIR+"#MN#"+NORM+" draws back and unleashes a critical punch to your"+HIY+" H E A D"+NORM+"!!!\n",
  " "+HIR+"#MN#"+NORM+"lands a critical strike on his attackers "+HIR+"S K U L L"+NORM+"\n",
  50,({80,80}),({"other|good","other|evil"}),1);
   add_spell("shield_toss", 
  "#MN# "+HIR+" D E S T R O Y S"+NORM+" you with an "+MAG+"atomic blast"+NORM+".\n",
  "#MN# "+HIR+" D E S T R O Y S"+NORM+" his opponent with an "+MAG+"atomic blast"+NORM+".\n",
  60,({80,80}),({"other|laser","other|ice"}),1);
}

init()
{
        ::init();
        add_action("exchange","exchange");
}

exchange(str)
{
        object proj;
		proj = present("broke_projector", this_player());
		if(str == "projector")
		{
                
                if(proj)
        {
                        write("Scientist takes the Projector and gives you some coins.\n"
);
                this_player()->add_money(4000+random(3000)); 
                destruct(proj);
                return 1;
        }
		else
                {
                write("Scientist says: It looks like you dont have any projector's to trade. \n");
                        return 1;
                }
                
        }
        
        else
        {
                write("Scientist says: I only trade coins for projector's. \n");
                return 1;
        }       
        
}
