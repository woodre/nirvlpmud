inherit "/obj/monster";
int heal;

#include "/sys/lib.h"
#include <ansi.h>
#include "../defs.h"

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("cyclonian");
	set_alt_name("cyclone");
	set_race("element");
	set_alias("sand cyclone");
	set_short(HIY+"C"+NORM+YEL+"yc"+NORM+HIY+"l"+NORM+YEL+"oni"+NORM+HIY+"an"+NORM+", the God of the "+HIY+"S"+NORM+YEL+"an"+NORM+HIY+"ds"+NORM);
	set_long("\
	A large, swirling storm of air and sand sit idle in the\n\
	sands. This is the dreaded Cyclonian, the God of the Sands.\n\
	The sands around it gleam with brightness as the hot sun\n\
	glares down upon the earth. The whirlwind twitches slightly\n\
	as blood of its fallen enemies swirls around its body. Its\n\
	bright red eyes look hungrily across the desert for its next\n\
	victim.\n");
	set_level(26);
	set_hp(1400 + random (100));
	set_ac(30 + random (10));
	set_wc(46 + random(10));
	set_al(0);
	    heal = 2;
        set_hp_bonus((query_mhp()-600)*2);
	set_chat_chance(1);
        set_dead_ob(this_object());
	load_chat(query_name()+" breathes heavily as the sands whirl about him.\n");
	add_spell("sandwhirl","          $HK$#MN# summons a giant $H$$Y$Sa$H$$HY$n$H$$Y$d$H$$HY$sto$H$$H$$Y$rm$H$$HK$.\n          $HK$The sands around him begin to swirl $R$violently$HK$.\n          #HK#The sands begin to heat as they thrash about.\n          $HK$The sands flailing around form into glass shards.\n          $HK$The glass shards $HR$RIP$HK$ into your flesh.$N$\n",
		"$HK$#MN# $HR$RIPS$HK$ into #TN#'s flesh with glass shards!$N$.\n",
	15,210,"other|wind");
}


monster_died()
{
	object hourglass, gold;
	
        if(present("dervish_tattoo", this_object()->query_attack()))
        {
        	hourglass = clone_object(OBJECTPATH+"/hourglass.c");
        	move_object(hourglass, environment(this_object()));
        	return 1;
        }
     
        gold = clone_object("obj/money");
        gold->set_money(5000 + random(10000));
        move_object(gold, environment(this_object()));
        return 0;
}

heart_beat()
{
  ::heart_beat();
  if(!environment()) return;
        
  if(heal && (this_object()->query_hp() < 600))
  {
    this_object()->heal_self(10000);
    tell_room(environment(this_object()),
      "The sands around "+HIY+"C"+NORM+YEL+"yc"+NORM+HIY+"l"+NORM+YEL+"oni"+NORM+HIY+"an"+NORM+" glow brightly as they cover its body to recover its wounds.\n"); 
    heal --;
  }
}
