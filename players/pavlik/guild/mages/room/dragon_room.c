inherit "/players/pavlik/guild/mages/inherit/room";
inherit "room/room";
#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/dragon.h"

#define VRI GRN+"Vrideen"+NORM

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The "+HIR+"Dragon "+NORM+HIBLK+"Chamber"+NORM;
  long_desc=
	"Huge deep gashes mark nearly every inch of every wall of this chamber.\n"+
	"This deep chamber below the Tower is home of "+YEL+"Vrideen"+NORM+", the Dragon Master.\n"+
	"Several large whips and other more strange 'training implements' are\n"+
	"stowed neatly in the corner.  There is a "+RED+"scorched"+NORM+" piece of "+CYN+"wood"+NORM+" with\n"+
	"writing on it on the southern wall.\n";

  items=({
    "wood",
	"Vrideen the Dragon Master: \n"+
	"   train <stat> \n"+
	"   cost  <stat> \n"+
	" notice: your dragon Must be present",
    "sign",
	"Vrideen the Dragon Master: \n"+
	"   train <stat> \n"+
	"   cost  <stat> \n"+
	" notice: your dragon Must be present",
  });

  dest_dir=({
	ROOM_DIR+"summon_room",		"east",
  });

  if(!present("vrideen", this_object()))
	move_object(clone_object(NPC_DIR+"vrideen"), this_object());

}

realm(){ return "NT"; }

init(){
  ::init();
  if(!mage_check()) return;
  add_action("guild_move","gm");
  add_action("train_dragon","train");
  add_action("train_cost", "cost");
}


train_cost(str)
{
  object obj;
  int exp_cost;
  int gold_cost;

  if(!str)
  {
	notify_fail(VRI+" stares at you blankly.\n");
	return 0;
  }

  if(str != "level" && str != "attack" && str != "defense" && str != "stamina" && str != "magic")
  {
	notify_fail(VRI+" stares at you blankly.\n");
	return 0;
  }

  obj = present(tp->query_real_name()+"'s dragon", this_object());

  if(!obj)
  {
	notify_fail(VRI+" ignores your "+YEL+"dragonless"+NORM+" person.\n");
	return 0;
  }

  if(str == "level" && obj->query_dragon_level() >= MAX_LEVEL)
  {
	notify_fail(VRI+" croaks: "+capitalize(obj->query_name())+"'s level can increase no further.\n");
	return 0;
  }

  if( (str == "attack" && obj->query_dragon_attack() >= MAX_ATTACK ) ||
      (str == "defense" && obj->query_dragon_defense() >= MAX_DEFENSE)
  )
  {
	notify_fail(VRI+" croaks: "+capitalize(obj->query_name())+" has already mastered the art of "+HIC+str+NORM+".\n");
	return 0;
  }

  if( (str == "stamina" && obj->query_dragon_stamina() >= MAX_STAMINA ) ||
      (str == "magic" && obj->query_dragon_magic() >= MAX_MAGIC)
  )
  {
	notify_fail(VRI+" croaks: "+capitalize(obj->query_name())+" has already realized maximal "+HIC+str+NORM+".\n");
	return 0;
  }

  if(!(gold_cost = get_gold_cost(obj, str)))
  {
	notify_fail(VRI+" stares at you blankly.\n");
	return 0;
  }

  if(!(exp_cost = get_exp_cost(obj, str)))
  {
	notify_fail(VRI+" stares at you blankly.\n");
	return 0;
  }

  if(str == "level")
  {
	write(VRI+" croaks: "+IT+" must have "+CYN+exp_cost+NORM+" total experience points to advance.\n");
	if(obj->query_dragon_experience() >= exp_cost)
		write(VRI+" croaks: "+IT+" has "+HIW+"already achieved"+NORM+" this goal.\n");
	write(VRI+" croaks: The training will cost you "+YEL+gold_cost+NORM+" gold coins.\n");
  }
  else
  {
	write(VRI+" croaks: "+IT+" will spend "+CYN+exp_cost+NORM+" experience points to increase "+str+".\n");
	write(VRI+" croaks: The training will cost you "+YEL+gold_cost+NORM+" gold coins.\n");
  }

  return 1;
}  


train_dragon(str)
{
  object ob, obj;
  int exp_level;
  int exp_cost;
  int gold_cost;
  int x;

  if(str != "level" && str != "attack" && str != "defense" && str != "stamina" && str != "magic")
  {
	notify_fail(VRI+" stares at you blankly.\n");
	return 0;
  }

  obj = present(tp->query_real_name()+"'s dragon", this_object());

  if(!obj)
  {
	notify_fail(VRI+" ignores your "+YEL+"dragonless"+NORM+" person.\n");
	return 0;
  }

  if(str == "level" && obj->query_dragon_level() >= MAX_LEVEL)
  {
	notify_fail(VRI+" croaks: "+capitalize(obj->query_name())+"'s level can increase no further.\n");
	return 0;
  }

  if( (str == "attack" && obj->query_dragon_attack() >= MAX_ATTACK ) ||
      (str == "defense" && obj->query_dragon_defense() >= MAX_DEFENSE)
  )
  {
	notify_fail(VRI+" croaks: "+capitalize(obj->query_name())+" has already mastered the art of "+HIC+str+NORM+".\n");
	return 0;
  }

  if( (str == "stamina" && obj->query_dragon_stamina() >= MAX_STAMINA ) ||
      (str == "magic" && obj->query_dragon_magic() >= MAX_MAGIC)
  )
  {
	notify_fail(VRI+" croaks: "+capitalize(obj->query_name())+" has already realized maximal "+HIC+str+NORM+".\n");
	return 0;
  }

  if(str != "level")
  {
	if( (call_other(obj, "query_dragon_"+str, 0) + 1) > (obj->query_dragon_level() * 3) )
	{
		notify_fail(VRI+" croaks: "+IT+" must increase in level first.\n");
		return 0;
	}
  }

  if(!(gold_cost = get_gold_cost(obj, str)))
  {
	notify_fail(VRI+" stares at you blankly.\n");
	return 0;
  }

  if(!(exp_cost = get_exp_cost(obj, str)))
  {
	notify_fail(VRI+" stares at you blankly.\n");
	return 0;
  }

  if(gold_cost > tp->query_money())
  {
    write( VRI+" croaks: That would cost you "+YEL+gold_cost+" gold coins, which you don't have.\n");
    if( gold_cost > tp->query_bank_balance() ) {
	return 1;
    }
    write( VRI+" continues: Luckily for you I have upgraded and now accept bank transfers.\n"); 
  }

  exp_level = get_exp_cost(obj, obj->query_dragon_level());

  if(obj->query_dragon_exp() - exp_level < exp_cost)
  {
	notify_fail(VRI+" croaks: That would cost "+HIC+exp_cost+NORM+" experience points, which " +
	 	IT + " doesn't have.\n");
	return 0;
  }

  if(str == "level")
  {
	obj->raise_dragon_level();
	write("You pay "+YEL+gold_cost+NORM+" gold coins to advance "+IT+"'s level.\n");
	write(IT+" is now level "+HIC+obj->query_dragon_level()+NORM+".\n");
  }
  else
  {
	call_other(obj, "raise_dragon_"+str, 1);
	x = call_other(obj, "query_dragon_"+str);
	write("You pay "+YEL+gold_cost+NORM+" gold coins to train "+IT+"'s "+str+".\n");
	write("It costs "+IT+" "+HIC+exp_cost+NORM+" experience points.\n");
	write(IT+"'s "+HIW+str+NORM+" is now "+HIC+x+NORM+".\n");
	obj->add_dragon_exp(-exp_cost);
  }

  if( gold_cost > tp->query_money() ) {
    tp->add_bank_balance( -gold_cost );
    write( VRI+" grumbles: I should really start charging a fee for these bank transfers...\n");
  }
  else
    tp->add_money(-gold_cost);

  return 1;

}

