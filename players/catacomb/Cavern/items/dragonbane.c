inherit "/obj/weapon.c";
#include <ansi.h>
#define TPN this_player()->query_name()
#define ATN attacker->query_name()

reset (arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("dragonbane");
  set_short(YEL+"Dragonbane"+NORM+", the war spear");
  set_alias("spear");
  set_long(
 "  The spear is roughly six feet long.  At the end is a dangerous\n"+
 "barbed tip.  A small ribbon hangs below the tip.  The picture on\n"+
 "the handle depicts a warrior slaying a dragon.  \n" );
  set_type("polearm");
  set_class(18);
  set_weight(3);
  set_value(1500);
  set_hit_func(this_object()); 
}

dragon_check(object ob)
{
  if(call_other(ob,"id", "dragon") || call_other(ob, "id", "wyrm"))
  return 1;
else return 0;
}

mixed
weapon_hit(object attacker) 
{
  string name;
  int chance;
  chance = random (100);
    if(environment() && environment()->is_player()) {
    name=((string)environment()->query_name()); }
    if(!name) return 0;
    
    if ((random(10) > 6) && (dragon_check(attacker)))
    {
    	write(RED+"\n\nThe spear glows a bright red as it feeds on dragon blood.\n\n"+NORM);
	return 5;
    }
    else
    {
	if (chance >= 85)
	{
	  write("\n\n     You leap into the air and descend upon "+ATN+"\n");
	  write("     with "+HIW+"CONCUSSIVE"+NORM+" force making "+ATN+" fall to\n");
	  write("             ground in agonizing pain.\n\n");
	  say("\n\n     "+TPN+" leaps into the air and descends on "+ATN+"\n");
	  say("     forcing them to bow to their superior power.\n\n");
	  return 3;
	}
	if (chance <= 15)
	{
 	  write("\n\n     As you extract the spear fountains of blood rise from the wound.\n\n");
	  say("\n       Fountains of blood rise from the wounds caused by "+TPN+".\n");
	  return 2;
	}
	else
	  return 0;
    }
}


  
