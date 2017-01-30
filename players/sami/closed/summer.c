inherit "/obj/weapon.c";
#include "/players/feldegast/defines.h"


int lit;

reset(arg) {
   ::reset(arg);
  if(arg) return;
  set_name("summersword");
  set_alias("summer");
  set_short(HIY+"Summersword"+NORM);
  set_type("sword");
  set_class(18);
  set_weight(4);
  set_long(
    "The Sword of Summer is a finely crafted longsword with a\n"+
    "gleaming blade and a sapphire pommelstone.  The silver\n"+
    "crosspiece is shaped like a stylized sun.  You can make\n"+
    "out cryptic runes just beneath the surface of the blade.\n"
  );
  set_value(1200);
  /* changed to fire <ill>
  set_hit_func(this_object());
  */
  set_params("other|fire",0,"fire_hit");
   
 
  
  /*  Changed set_read to 'read runes' for added 'super_nova' spell.  Sami  02/10/2015
  set_read("On the first side:\n"+
           BOLD+"  This Blade Was Forged by the Master Weaponsmith, Mertucio.\n"+NORM+
           "On the other side:\n"+
           HIY+"  In Luminus Vethi\n"+NORM);
}*/
}
void init() {
  ::init();
  add_action("cmd_intone","intone");
  add_action("cmd_intone","say");
  /*Added by Sami for update request  02/10/2015*/
  add_action("super_nova", "nova");
  add_action("read_runes", "read");
} 
  read_runes() {
  write("************~~~~~~~~~"+HIY+"powers"+NORM+"~~~~~~~~~~~~~~~************\n");
  write(""+BOLD+"  This Blade Was Forged by the Master Weaponsmith, Mertucio"+NORM+".\n"+
		" This blade has been empowered with the power of "+HIR+"nova"+NORM+". \n"+
		"               "+HIY+"  In Luminus Vethi\n"+NORM);
  write("************~~~~~~~~~"+HIY+"powers"+NORM+"~~~~~~~~~~~~~~~~************\n");
return 1; }

cmd_intone(str) {
  /* added an if(!str) Vertebraker [5.24.01] */
  if(!str || (lower_case(str) != "in luminus vethi"))
    return 0;
  if(lit) {
    write("Nothing happens.\n");
    return 1;
  }
  if(this_player()->query_sp() < 30) {
    write("You do not have enough magical energy.\nNothing happens.\n");
    return 1;
  }
  write("You exert your will as you intone the words:\n\t"+BOLD+"In Luminus Vethi\n"+NORM);
  this_player()->add_spell_point(-30);
  if(this_player()->query_attrib("wil") < 16) {
    write("Your will was not strong enough.  Nothing happens.\n");
    return 1;
  }
  write(HIY+"Your sword begins to give off a cheerful glow.\n"+NORM);
  say(TPN+"'s sword begins to glow.\n");
  lit = 1;
  set_light(1);
  call_out("lights_out",200*this_player()->query_level());
  return 1;
}

void lights_out() {
  set_light(-1);
  lit=0;
  if(environment()->is_player())
    tell_object(environment(),"The Summersword dims.\n");
}

fire_hit(attacker) {
  int w;

  w=random(3);

  if(set_light(0) <= 0) {
    if(!w)
      write(BOLD+BLK+"The Summersword lies dormant in your hands.\n"+NORM);
    return 0;
  }

  if(!w) {
    switch(random(4)) {
      case 0: write("The Summersword's blade burns "+BBLK+HIW+"white hot"+NORM+"!\n");
              say("The Summersword's blade burns "+BBLK+HIW+"white hot"+NORM+"!\n");
              break;
      case 1: write("The Summersword cuts through the air in an elegant sweep!\n");
              say("The Summersword cuts through the air in an elegant sweep!\n");
              break;
      case 2: write(HIY+"\nThe Summersword glows like the sun on a warm summer day.\n\n"+NORM);
              say(HIY+"\nThe Summersword glows like the sun on a warm summer day.\n\n"+NORM);
              break;
      case 3: write("The Summersword dances in your hands as you smite "+attacker->query_name()+"!\n");
              say(TPN+" smites "+attacker->query_name()+" with the Summersword!\n");
              break;
    }
    return 5;
  }
}

short() {
  if(lit)
    return ::short()+" ("+HIC+"*"+NORM+")";
  return ::short();
}

count_misses(w) {
  return 1;
}

count_hit_made(w) {
  return 1;
}
/*Super_nova spell added by sami as a request for update for Summersword*/
int super_nova(string str)
{
  object victim, me;
  int cost, damage;
  string vn, mn, sm1, sm2;

  if((int)(me=this_player())->query_level() < 15) return 0;
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
      return (write("Nova who?\n"), 1);
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
      return (write("You cannot cast super nova on yourself!\n"), 1);
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
      sm2="raging "+HIR+"flames"+NORM+" of death";
      break;
    case 1:
      sm2="smoking blast of "+HIC+"fiery"+NORM+" winds";
      break;
    case 2:
      sm2="ball of "+HIC+"fire"+NORM+"";
      break;
    case 3:
      sm2="sparks of "+HIR+"fire "+NORM+"";
      break;
  }
  me->spell_object(victim, "nova", damage, cost,
   "You "+sm1+" "+(vn=(string)victim->query_name())+" with a "+sm2+".\n",
   (mn=(string)me->query_name())+" "+sm1+" you with a "+sm2+".\n",
   mn+" "+sm1+" "+vn+" with a "+sm2+".\n");
  me->set_spell_dtype("other|fire");
  return 1;     
}