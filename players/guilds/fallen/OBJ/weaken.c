inherit "/obj/treasure.c";
#include "../all.h"
#define EN environment()->query_name()
#define EOBJ environment()->query_objective()
#define EPOS environment()->query_possessive()
int weak, ac, cnt, total, x;
/* added by illarion */
int new_ac;

reset(arg){

    set_id("weaken_counter");
    set_alias(0);
    set_short(0);
    set_long(0);
    set_weight(0);
    set_value(0);
    /* no need for this unless the object is in use - ill
    set_heart_beat(1);
    */
    weak = 1;
    cnt = 0;
    x = 0;
}

weaken(int x){ 
    /* start the hb here - ill */
    set_heart_beat(1);
    return weak = x; 
}

drop(){  return 1; }

extra_look()
{
    if(ENV->is_npc())
	return BOLD+BLK+ENV->QN+" is being weakened by the shadows"+NORM; 
}

msgs(){
    int x;
    string z;
    x = random(5);
    switch(x)
    {
    case 0:
	z = "Shadows sap the strength of "+EN+".\n";
	break;
    case 1:
	z = "Shadows drain "+EN+" of "+EPOS+" strength.\n";
	break;
    case 2:
	z = "Shadows siphon the strength away from "+EN+".\n";
	break;
    case 3:
	z = "The shadows surround "+EN+" in an aura of decay.\n";
	break;
    case 4:
	z = "The shadows flit around "+EN+", distracting "+EOBJ+".\n";
	break;
    }
    tell_room(environment(environment()), HIW+z+NORM);
}

heart_beat()
{
    if(!environment()) return;
    if(!environment()->is_npc())
    {
	destruct(this_object());
	return;
    }
    if(!x)
    {
	ac = ENV->query_ac();
	x = 1;
    }
    if(weak)
    {
	if((ac * 2 / 3) > (ac - 4)) {
	    new_ac=ac*2/3;
	    /*
	    ENV->set_ac( ac * 2 / 3);
	    */
	}
	else {
	    new_ac=ac-4;
	    /*
	    ENV->set_ac(ac - 4);
	    */
	}
	ENV->RegisterArmor(this_object(),({"physical",new_ac-ac,0,0 }));
	cnt = 0;
	weak = 0;
    }
    else if(!weak)
	cnt++;
    if(cnt >= 3+random(2))
    { /* changed...
	  ENV->set_ac((int)ENV->query_ac()+1);
	  */
	new_ac++;
	/* also modified...
	if(ENV->query_ac() >= ac || 
	*/
	if(new_ac>=ac ||
	  (ENV->query_hp() < (ENV->query_mhp() / 10) && ENV->query_hp() < 50))
	{
	    tell_room(environment(ENV), BOLD+BLK+
	      "The shadows disappear from around "+ENV->QN+".\n"+NORM);
	    ENV->RemoveArmor(this_object());
	    destruct(this_object());
	    return;
	} else
	    ENV->RegisterArmor(this_object(),({"physical",new_ac-ac,0,0}));
    }
    if(!random(2))
	msgs();
}

/* added to keep spell from reducing monster exp */
no_exp_effect() { return 1; }

