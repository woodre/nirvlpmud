#include "/players/forbin/realms/flame_forest/ffdefine.h"
/* 2005.08.12 Forbin 
// -changed from obj/armor.c to bfeq object to support 
//  modifying of Bloodfist guild attribute bonuses
// inherit "/obj/armor.c"; 
*/
inherit "/players/forbin/closed/bfeq.c";

void start(object ob);
void stop(object ob);

reset(arg) 
{
  if(arg) return;
  ::reset();  
  set_name("juju");
  set_alias("trinket");
  SetMultipleIds(({"juju trinket"}));
  set_short(HIK+"A "+HIR+"ju"+NORM+RED+"ju"+HIK+" trinket"+NORM);
  set_long(
  "  The bulk of this juju, or charm, is made up of an inch and a half\n"+
  "black and white bone.  A candy-stripe spiral has been painted down\n"+
  "it in blood.  A great many pieces of short, coarse hair, grey in\n"+
  "color, have been tied to one end of the bone with fine silver thread,\n"+
  "as has a single red albatross feather.  A simple cord of sinew is\n"+
  "attached through an eyehole to make wearing the trinket possible.\n"+  
  "  You sense an evil presence resides inside this juju.\n");
  set_ac(1);
  set_params("other|evil", 0, 5, "do_evil_special"); /* 10% evil resistance */ 
  set_params("other|dark", 0, 5, "do_dark_special"); /* 10% dark resistance */
  set_type("necklace");
  set_weight(1);
  set_value(1000);
  set_bf_guild_bonus(5, 15);  
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
      "You tie the trinket around your neck.\n");
    tell_room(environment(environment()),
      (string)this_player()->query_name()+
      " ties a trinket around "+
      (string)this_player()->query_possessive()+
      " neck.\n", ({ environment() }));
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
      "You untie the trinket from around your neck.\n");
    tell_room(environment(environment()),
      (string)this_player()->query_name()+
      " unties a trinket from around "+
      (string)this_player()->query_possessive()+
    " neck.\n", ({ environment() }));
    stop(this_player());
  }
  return x;
}

drop() {
  if( worn )
    this_object()->remove("juju trinket");
  ::drop();
}

give() {
  if( worn )
    this_object()->remove("juju trinket");
}

void start(object ob) 
{
  call_out("corrupt_wearer", 10, ob);   
}

int corrupt_wearer(object ob) 
{
  if(!ob || !((status)this_object()->query_worn()))
    return 1;  
    
  if((int)ob->query_alignment() > -1000) 
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
    return 0502;  /* 5% [05]02 resistance boost 2 05[02] ac boost */
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
