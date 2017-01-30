#include "/players/fred/closed/bloodfist/defs.h"

inherit "/obj/monster";
#define WAIT_LENGTH 12
#define SELL_LENGTH 6
#define HONORVAL ((int)HONOR_DAEMON->query_honor(controller->query_real_name()) / 150)
#define WISVAL (((int)controller->query_attrib(4) + (int)controller->query_attribb(4)) / 9)
#define FAIVAL (((int)controller->query_attrib(5) + (int)controller->query_attribb(5)) / 8)

object who, what, gob, controller, m;
int sending, c, d, selling, sold_value;

reset(arg) {
  ::reset(arg);
  if (arg) return;

  c = WAIT_LENGTH;
  d = SELL_LENGTH;
  set_hp(200);
  set_no_exp_value();
  call_out("controller_check", 60);
}

id(str){ return str == "pet" || str == name || str == alt_name
|| str == alias; }

void init(){
  ::init();
  add_action("accept", "accept");
  add_action("decline", "decline");
}

controller_check()
{
  if(!controller) return;
  if(!find_player(controller->query_real_name()))
  {
    tell_room(environment(), short()+" wanders off.\n");
    move_object(this_object(), "/room/void.c");
    destruct(this_object());
  }
  else
    call_out("controller_check", 60);
}

void set_controller(object a){ controller = a; }

status send(object a, object b, object c, object d)
{
  who = a;
  what = b;
  gob = c;
  controller = d;
  sending = 1;
  return 1;
}

status sell(object a, object b) 
{
  gob = a;
  controller = b;
  selling = 1;
  set_hbflag("hbstayon"); /* forces hb to continue while in void */
  return 1;
}

status set_sold_value(int num) 
{
  sold_value = num;
  return 1;
}

status accept(string str)
{
  if(str != "delivery") return 0;
  if(this_player() != who) return 0;
  if(!this_player()->add_weight(what->query_weight()))
  {
    write("You can't carry it.\n");
    return 1;
  }
  write("You accept the delivery from "+controller->query_name()+".\n"+
    short()+" gives you "+what->short()+".\n");
  move_object(what, who);
  gob->sent();
  sending = 0;
  c = WAIT_LENGTH;
  return 1;
}

status decline(string str)
{
  if(str != "delivery") return 0;
  if(this_player() != who) return 0;
  write("You decline the delivery from "+controller->query_name()+".\n");
  if(controller)
    tell_object(controller, this_player()->query_name()+
      " declines the delivery.\n");
  gob->sent();
  sending = 0;
  c = WAIT_LENGTH;
  return 1;
}


heart_beat() {
  ::heart_beat();
  if(!environment()) return;
  if(sending)
  {
    if(!present(who, environment()))
    {
      tell_room(environment(), short()+" leaves following "+
        who->query_name()+".\n");
      move_object(this_object(), environment(who));
      tell_room(environment(), short()+" arrives following "+
        who->query_name()+".\n");
    }
    c--;
    if(c <= 0)
    {
      c = WAIT_LENGTH;
      if(controller)
        tell_object(controller, who->query_name()+
          " waited too long to accept the delivery.\n");
      gob->sent();
      sending = 0;
    }
  }
  if(selling)
  {
    d--;
    if(d <= 0)
    {
      if(controller) 
      {
        move_object(this_object(), environment(controller));
        if(sold_value) 
        {
          tell_object(controller, 
            short()+" returns with some coins.\n");
          tell_room(environment(controller), 
            short()+" returns with some coins for "+
            controller->query_name()+".\n", ({ controller }));
          m = clone_object("obj/money");
          m->set_money(sold_value);
          move_object(m, environment(controller));
          tell_room(environment(controller),
            short()+" drops some coins.\n");
        }
        else
        {
          tell_room(environment(controller), 
            short()+" returns.\n");
        }      
      }
      d = SELL_LENGTH;
      set_sold_value(0);
      gob->sent();
      selling = 0;
      set_hbflag(0); /* remove hbstayon flag */
    } 
  }
  if(controller->query_attack() && 
     controller->query_attack()->is_npc() &&
     environment(this_object()) == environment(controller) &&
     (HONORVAL + WISVAL + FAIVAL) > random(100)) 
  {
	  pet_attack(controller->query_attack());
  } 
}

pet_attack(object attacker) 
{
	int damage;
	string where, how;
	object oldaob;
	
	if(!attacker) return;
   	if(attacker->is_player()) return;
        if(!present(attacker, environment())) return;
        if(!controller) return;
	if(attacker != controller->query_attack()) return;
	if(!present(controller, environment())) return;
        if(attacker == this_object()) return;
	oldaob = attacker->query_attack();
	tell_room(environment(),
  	short()+" charges forward to attack "+attacker->query_name()+"!\n");
	damage = (((weapon_class / 2) + random(weapon_class)));
	if(attacker->query_hp() < damage)
	{
		tell_object(controller, 
		short()+" circles and waits for you to finish "+attacker->query_name()+".\n");
		return;
	}
	switch(damage)
	{
		case 30..10000: how = "D E V A S T A T E D"; break;
		case 25..29:    how = "massacred"; break;
		case 21..24:    how = "butchered"; break;
		case 17..20:    how = "smashed"; break;
		case 12..16:    how = "struck"; break;
		case 7..11:     how = "hit"; break;
		case 3..6:      how = "grazed"; break;
		case 1..2:      how = "knicked"; break;
	}
	switch(random(5))
	{
		case 0:  where = "head"; break;
		case 1:  where = "chest"; break;
		case 2:  where = "leg"; break;
		case 3:  where = "arm"; break;
		case 4:  where = "shoulder"; break;
	}
	tell_room(environment(),
  	short()+" "+how+" "+attacker->query_name()+" in the "+where+".\n");
	attacker->heal_self(-damage);
	if((random(((WISVAL + FAIVAL) / 10) + armor_class)) < (random(attacker->query_wc())))
	{
		tell_room(environment(),
      short()+" is struck by "+attacker->query_name()+" as it attacks!\n");
          this_object()->hit_player(((attacker->query_wc() / 3) + random(attacker->query_wc())));
	}
	else
	{
    tell_room(environment(),
		  short()+" dodges the side attack of "+attacker->query_name()+"!\n");
	}
	attacker->attack_ob(oldaob);
	return;
}
