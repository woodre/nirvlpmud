#include <ansi.h>
inherit "obj/weapon";


reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_alias("sword");
	  set_type("sword");
        set_short(""+BOLD+"Sword"+NORM+" of "+HIC+"Ice"+NORM+"");
        set_long("This is the Legendary "+BOLD+"Master Sword"+NORM+" wielded by\n"+
		"The famous Hero of Hyrule, Link. This blade hums with "+HIY+"HOLY"+NORM+"power.\n");
        set_params("other|ice",4,0);
	    set_class(17);
        set_weight(3);
        set_value(7200);
        set_name("Sword of "+HIC+"ICE"+NORM+"");
        message_hit = 
    ({
        BOLD+" EVISCERATED "+NORM," Blood gushes everywhere",
        HIR+" HACKED "+NORM," extremely hard",
        HIY+" CHOPPED "+NORM," viciously",
        HIC+" minced "+NORM,", with precision",
        HIG+" sliced "+NORM," drawing a little blood",
        HIB+" struck "+NORM," lightly",
        HIW+" grazed "+NORM," very lightly"
    });
	

}
init()
{  add_action("chilling_blast", "chill"); }

int chilling_blast(string str)
{
  object victim, me;
  int cost, damage;
  string vn, mn, sm1, sm2;

  if((int)(me=this_player())->query_level() < 5) return 0;
  me->spell_block();
  if((int)me->query_spell_block())
    return (write("You are unable to do that.\n"), 1);
  if((int)me->query_spell_dam())
    return (write(
     "Your magical energy has already been used " +
     "in an attack spell this round.\n"), 1);

  if(!str)
  {
    if(!(victim = (object)me->query_attack()))
      return (write("Chill who?\n"), 1);
    if(!present(victim, environment(me)))
      return (write((string)victim->query_name() + " isn't here.\n"), 1);
  }
  else
  {
    if(!(victim = present(str, environment(me))))
      return (write("You don't see " + str + " here.\n"), 1);
    if(!living(victim))
    {
      write("You cannot attack that!\n");
      say((string)me->query_name() + 
       " foolishly tries to attack " + str + ".\n");
      return 1;
    }
    if(!me->valid_attack(victim))
      return 1;
    if(victim == me)
      return (write("You cannot cast chilling blast on yourself!\n"), 1);
  }

  damage = random((45)+15);
  cost = 35;
        
  switch(damage)
  {
    case 39:     sm1 = HIC+"DESTROYED"+NORM; break;
    case 37..38: sm1 = HIC+"Devastated"+NORM;  break;
    case 33..36: sm1 = RED+"Blasted"+NORM;     break;
    case 24..32: sm1 = "struck";               break;
    case 9..23:  sm1 = "hit";                  break;
    case 5..8:   sm1 = "grazed";               break;
    case 1..4:   sm1 = "singed";               break;
    default:     sm1 = "missed";               break;
  }
  switch(random(4))
  {
    case 0:
      sm2="frozen "+HIC+"icicle"+NORM+" of death";
      break;
    case 1:
      sm2="smoking blast of "+HIC+"chilling"+NORM+" winds";
      break;
    case 2:
      sm2="chunk of "+HIC+"ice"+NORM+"";
      break;
    case 3:
      sm2="splatter of "+HIC+" ice chips"+NORM+"";
      break;
  }
  me->spell_object(victim, "chill", damage, cost,
   "You "+sm1+" "+(vn=(string)victim->query_name())+" with a "+sm2+".\n",
   (mn=(string)me->query_name())+" "+sm1+" you with a "+sm2+".\n",
   mn+" "+sm1+" "+vn+" with a "+sm2+".\n");
  me->set_spell_dtype("other|ice");
  return 1;     
}