/*
 * Evil Fairy Queen Ekimmu
 * /mobs/queen.c
 * Cloud 2009
 */
 
 
#include "/obj/ansi.h"
inherit "/obj/monster";
int X;

reset(arg) 
{
   	::reset(arg);
   	if (!arg) 
	{

		object gold;
  		gold = clone_object("obj/money");
  		gold->set_money(random(1000) + 10000);
  		move_object(gold,this_object());
  

     	set_name("ekimmu");
     	set_alt_name("fairy");
     	set_short(""+HIK+"Ekimmu"+HIR+" the evil fairy queen"+NORM+"");
     	set_race( "Fay");
     	set_gender("female");
     	set_alias("queen");
     	set_long(
     	"Ekimmu's pale, white skin and dark, blackened eyes\n"+
     	"match her flowing, white and purple robe. A wicked\n"+ 
     	"expression across her face appears to be permanent.\n");     
     	set_level(26);
     	set_ac(23+random(3));
     	set_wc(45+random(3));
     	set_hp(1200 + random(150));
     	set_al(-1000);
     	set_aggressive(0);
     					    
    	X=random(100);
     	if(X < 50)
     	{     	
     		if(!present("orb")) 
     		{
     			move_object(clone_object("players/cloud/Fayawyn/obj/orb.c"),
       			this_object());
   			}
		}
		else
		{
		return 1;
		}
    
   }
}




heart_beat()
{
	int B;
	int V;
	B = random(100);
	V = random(100);
	::heart_beat();
	if(!environment()) return;
  	if(attacker_ob && present(attacker_ob, environment(this_object())))
  	{
    	if(B > 70) dark_orb();
    	if(V < 20) queen_heal();
  	}
}

dark_orb()
{
	tell_object(attacker_ob,
    "\n\t"+HIK+""+query_name()+" "+HIM+"releases an orb of darkness into you."+NORM+"\n\n" +
    ""+HIM+"                          .---.          "+NORM+"\n" + 
    ""+HIK+"                         '     `         "+NORM+"\n" + 
    ""+HIM+"                   ---==:       :==---   "+NORM+"\n" +
    ""+HIK+"                        '       '        "+NORM+"\n" +
    ""+HIM+"                          `---'          "+NORM+"\n\n");  
    
  tell_room(environment(),
   "\n\t"+HIK+""+query_name()+" "+HIM+"releases a orb of darkness into "+
    attacker_ob->query_name()+"."+NORM+"\n\n",({attacker_ob}));

    
  attacker_ob->hit_player(25+random(25), "other|dark");
}

queen_heal()
{
	tell_object(attacker_ob,
	""+HIB+"Ekimmu begins chanting and her wounds close up."+NORM+"\n");
	
	tell_room(environment(),
	""+HIB+"Ekimmu begins chanting and her wounds close up."+NORM+"\n",({attacker_ob}));
	
	this_object()->add_hit_point(20 + random(20));
}