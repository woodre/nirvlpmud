/* Item Powers
What I would Like the item to do
I would like this item to track Demon souls Harvested
Snow's Ice Demons
Jareel's Dark Demons
Jareel's Sembrak
Jareel's Cacodeamon (HeroQuesting Cacodeamon also tho that is a future mob)
More Demons in the Future 

I would like the item to give powers the more demons you kill like resistance is cumulative
10 demons -10% Light/Fire damage(This is another Drawback to this when you kill 10 Dark or 10 Ice demons you take more damage from fire and light)
5% res ice/dark damage
100 demons +5 res ice/dark damage
1000 demons 1% res|physical
10000 demons
100000 demons +2% res|physical
1000000 demons +6% res|physical
1 Cacoemon Dark Glowing Eyes
5 cacodemon 1% res|physical
10 cacodemon 2% res|dark, 2% res|magical
100 cacodemon fire,poisen,sonic,ice,lazer,evil,wind,water,earth,mental 5% 
1000 sebrak caco (Greater Demon) 3% dark/magical
10000 sebrak caco (Greater Demon) 4% res|physical
100000 sebrak caco (Greater Demon) 5% res|Physical
1000000 sebrak caco (Greater Demon) +5%res|Physical

Ok so we can tweet the rewards to whatever it needs to be, consider 1million Demons would give the character 
over a billion xp in just killing dark demons calculating in the  re spawn time this would take a very long 
time to accomplish. 

What I would like to see is the Soul in the description at the bottom say next power up reward Resistance to ice/dark damage
when you level up that have it say next level up physical resistance. So They have something to come back to my area for..8)


HeroQuesting Demons (Raiding Prestige Group killing thingy want to work on soon...
*/



inherit "obj/armor";
#include "/players/jareel/ansi.h" /* much of the alignment code is based of the juju trinket */

void start(object ob);
void stop(object ob);

reset(arg) 
{
  if(arg) return;
  ::reset();  
  set_name("demon soul");
  set_alias("misc");
  SetMultipleIds(({"trapped demon soul"}));
  set_short(HIK+"A "+HIK+"Dark Demon "+HIR+"Soul"+NORM);
  set_long(

  "\n"+
  "                                                                                             \n"+
  "\n"+
  "\n"+
  "\n"+
  "\n"+  
  "\n");
  set_params("other|evil", 0, 5, "do_evil_special"); /* 10% evil resistance */ 
  set_params("other|dark", 0, 5, "do_dark_special"); /* 10% dark resistance */
  set_type("misc"); /* would like to make this an other armour or an auto load if possible see comment down a little bit */
  set_weight(0); /* This is a Demon Soul that has attached to the user */
  set_value(10000); /* Would Like this to be soul bound to the Player that got the killing blow on Morgus or at least
                      only the people who have gotten the death blow on Morgus can get the Item to work for them
					  so as to not have this Item just willy nilly all over the realm */
}

void 
init() {
 ::init();
 add_action("cmd_wear", "wear");
 add_action("cmd_remove", "remove");
}

int cmd_wear(string arg) 
{
  status wFlag;
  status x;
  wFlag = worn;
  x = (int)::wear(arg);
  if(!wFlag && worn) 
  {
    tell_object(environment(),
      "The eerie dark energy surrounds\n");
    tell_room(environment(environment()),
      (string)this_player()->query_name()+
      " as a demon leeches of the goodness of "+
      (string)this_player()->query_possessive()+
      " soul.\n", ({ environment() }));
    start(this_player());
  }
  return x;
}

status cmd_remove(string arg) 
{
  status wFlag, x;
  wFlag = worn;
  x = (int)::remove(arg);
  if(wFlag && !worn) 
  {
    tell_object(environment(),
      "You unbind the Dark Demon leech from your Soul.\n");
    tell_room(environment(environment()),
      (string)this_player()->query_name()+
      " disconnects from "+
      (string)this_player()->query_possessive()+
    " soul.\n", ({ environment() }));
    stop(this_player());
  }
  return x;
}

drop() {
  this_object()->remove("demon soul");
  ::drop();
}

give() {
  this_object()->remove("demon soul");
}

void start(object ob) 
{
  call_out("corrupt_wearer", 10, ob);   
}

int corrupt_wearer(object ob) 
{
  if(!ob || !((status)this_object()->query_worn()))
    return 1;  
    
  if((int)ob->query_alignment() > -1000) /* if alignment is -1000 there is no goodness for the trinket to feed on 
                                             so I would like it to suck hit points or spell points from the user not sure
                                             this is the way I want to do this.  I think the soul corruption should be
                                             a constant alignment reduction every 10 minutes or so of real time  */
  {
    call_other(ob, "add_alignment", -100);
    if(!random(4)) 
    {
      tell_object(ob,
        HIK+"You feel an inky, dark presence reach into your soul.\n"+NORM);
      tell_room(environment(ob),
        (string)ob->query_name()+"'s trinket sucks in the surrounding light.\n", ({ ob }));
    }
  }
  
  call_out("corrupt_wearer", 60+random(120), ob);
  return 1;        
  
}

void stop(object ob) 
{
  while(remove_call_out("corrupt_wearer") != -1);  
}

int do_special(object owner) 
{
  if(!owner) return 0;
  if((int)owner->query_attrib("luc") > random(200)) 
  {
    tell_object(owner,
      HIK+"A black field of energy surrounds you.\n"+NORM);
    tell_room(environment(owner),
      "A black field of energy surrounds "+
      (string)owner->query_name()+".\n", ({ owner }));
    return 2;
  }
}

int do_evil_special(object owner) 
{
  if(!owner) return 0;
  if((int)owner->query_attrib("luc") > random(80)) 
  {
    tell_object(owner,
      HIK+"Strands of black energy lash out from your body.\n"+NORM);
    tell_room(environment(owner),
      "Strands of black energy lash out from "+
      (string)owner->query_name()+"'s body.\n", ({ owner }));
    return 0502;  /* 5% [05]02 resistance boost 2 05[02]  */
  }
}

int do_dark_special(object owner) 
{
  if(!owner) return 0;
  if((int)owner->query_attrib("luc") > random(80)) 
  {
    tell_object(owner,
      HIK+"Strands of black energy lash out from your body.\n"+NORM);
    tell_room(environment(owner),
      "Strands of black energy lash out from "+
      (string)owner->query_name()+"'s body.\n", ({ owner }));
    return 0502;  /* 5% [05]02 resistance boost 2 05[02] ac boost */
  }
}