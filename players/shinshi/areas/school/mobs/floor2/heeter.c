inherit "/obj/monster";
int heal;

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("heeter");
	set_alt_name("teacher");
	set_race("teacher");
	set_alias("science teacher");
	set_short(HIK+"Mr. Heeter"+NORM);
	set_long("\
	This is the head of the Science department at\n\
	the high school, Douglas Heeter. He is a rather tall\n\
	man who looks to be in his mid fourties. He wears\n\
	a plain white dress shirt, black plants, and a black tie\n\
	He is also the coach of the wrestling team. Messing\n\
	with this teacher would not be very smart at all.\n");
        heal = 10;
        set_hp_bonus(1250); /* 10 heals avg of 125 */
	set_level(35);
	set_hp(3000 + random (100));
	set_ac(38 + random (10));
	set_wc(55 + random(10));
	set_al(7000);
	set_chat_chance(1);
        set_dead_ob(this_object());
	load_chat(query_name()+" says, \"You are late. Sit down and begin the drill!\"\n");
	load_chat(query_name()+" says, \"LATE! I will see you tomorrow for DETENTION!\"\n");
	/*add_spell("bodyslam","#MN# $R$BODYSLAMS$W$ you.\n",
		"#MN# BODYSLAMS #TN# to the ground.\n",
	35,175,"other|physical");*/
	add_spell("firemans","#MN# gets you into the Fireman's Carry.\n",
		"#MN# gets #TN# into the Fireman's Carry.\n",
	35,200,"other|physical");
	add_spell("russiandrag","#MN# gets you with the Russian Drag move.\n",
		"#MN# gets #TN# with the Russian Drag move.\n",
	25,175,"other|physical");
	add_spell("hiplock","#MN# throws you over his back and hiplocks you.\n",
		"#TN# is thrown over #MN#'s back and is hiplocked.\n",
	50,75,"other|physical");
}


monster_died()
{
  object gold;
  int x;
  x = random(100);

  if(x < 15) /* 15% */
  {
    move_object(clone_object("/players/shinshi/areas/school/obj/chemical1.c"), this_object());
    return 1;
  }
  
  gold = clone_object("obj/money");
  gold->set_money(5000+random(10000));
  move_object(gold, environment(this_object()));
  return 1;
}

heart_beat()
{
  ::heart_beat();
  if(!environment()) return;
        
  if(heal && (this_object()->query_hp() < 600))
  {
    this_object()->heal_self(100 + random(50));
    tell_room(environment(this_object()),
      "Mr. Heeter grabs a beaker full of green liquid off a table and chugs it down.\n"); 
    heal --;
  }
}