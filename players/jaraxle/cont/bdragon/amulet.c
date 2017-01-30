inherit "/obj/armor";
#include "/players/jaraxle/define.h"
#define GUILDID "mageobj"
#define BONUS_TYPE "power"
#define BONUS_TYPE2 "evocation"
#define BONUS_AMOUNT 1
void
reset(status arg)
{
   if(arg) return;
   ::reset();
   set_name("amulet of lightning");
   set_alias("amulet_of_lightning");
   set_short(HIY+"Amulet "+NORM+"of "+HIY+"Lightning"+NORM);
   set_type("amulet");
   set_weight(1);
   set_long("A long silver necklace with a platinum gold amulet in\n"+
      "the shape of a lightning bolt dangling freely.\n");
   set_ac(0); /* physical ac */
   set_params("other|electricity", 2, 10, "do_elec_special");
   /* 2 ac, 30% resistance to other|electricity damage,
   plus it calls the 'do_elec_special()' function */
  /* changed to 10% elec protect - verte */
}
query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player()))
  {
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE2, BONUS_AMOUNT);	
  }
			
}

remove_guild_bonus()
{
  if(present(GUILDID, this_player()))
  {
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE2, -BONUS_AMOUNT);	
  }
}
void long(string arg)
{
   ::long(arg);
   if(this_player()->query_attrib("int") > random(40))
      return (write("You notice that something has been written upon the back.\n"+
         "You may be able to \"read\" it.\n"));
}

string
short()
{
  if(worn)
      return short_desc + (HIY + " (" + NORM + "worn" + HIY + ")" + NORM);
   else return short_desc;
}



do_special(owner){
   if(!random(6)){
      tell_object(owner, "The "+HIY+"amulet on your necklace flashes "+HIY+BLINK+"brightly"+NORM+"!\n");
      if(this_player() && this_player()!=owner)
         write(owner->query_name()+"'s "+HIY+"Lightning"+NORM+" amulet flashes brightly!\n");
      return 1+random(2);
   }
}

int
do_elec_special(object owner)
{
   if(!random(8))
      {
      tell_object(owner, "\
         Your "+YEL+"Lightning"+NORM+" amulet flashes and reflects some of the "+HIY+"electric"+NORM+" damage.\n");
      return 1504;
      /* 
      15% [15] resistance boost
      4  [04] ac boost 
      */
   }
}


init() {
   
   ::init();
   
   add_action("elec","electrify");
   add_action("cmd_read","read");
   
}

elec(str) {
   object victim;
   string b1,b2;
   string bash_mess1;
   string bash_mess2;
   int Dam1;
   Dam1 = 1+random(26);
   
   
   
   if(!worn){ return 0; }
   if(TP->query_spell_dam()) return 1;
/*
   if (str) victim = present(str, environment(TP));
   else {
      victim = TP->query_attack();
      if(victim && !present(victim, environment(TP)))
         victim = 0;
   }
*/
   
   if(!(victim = TP->query_attack())) {
    write("You must be in combat.\n");
   return 1;
  }
   
   
  if(!TP->valid_attack(victim)) {
      return 1;
   }
   
   switch(Dam1){
      case 21..100:
      bash_mess1 = ""+HIY+"ELECTRIFY"+NORM+"";
      bash_mess2 = ""+HIY+"ELECTRIFIES"+NORM+"";
      break;
      case 17..20:
      bash_mess1 = ""+HIW+"SHOCK"+NORM+"";
      bash_mess2 = ""+HIW+"SHOCKS"+NORM+"";
      break;
      case 10..16:
      bash_mess1 = ""+YEL+"rattled"+NORM+"";
      bash_mess2 = ""+YEL+"rattles"+NORM+"";
      break;
      case 5..9:
      bash_mess1 = ""+WHT+"zap"+NORM+"";
      bash_mess2 = ""+WHT+"zaps"+NORM+"";
      break;
      case 1..4: 
      bash_mess1 = "sting";
      bash_mess2 = "stings";
      break;
      default:
      bash_mess1 = "miss";
      bash_mess2 = "misses";
      break;
   }
   
   Dam1 *= this_player()->query_level();
   Dam1 /= 19;
   TP->spell_object(victim,"lightning strike", Dam1,30,
      "You "+bash_mess1+" "+victim->query_name()+" with a jolt of "+HIY+"lightning"+NORM+".\n",
      TP->query_name()+" "+bash_mess2+" you with a jolt of "+HIY+"lightning"+NORM+"!\n",
       TP->query_name()+" "+bash_mess2+" "+victim->query_name()+" with a jolt of "+HIY+"lightning"+NORM+"!\n");
  TP->set_spell_dtype("other|electric");
  TP->hit_player(1+random(5), "other|electric");
   return 1;
}

cmd_read(arg) {
   if(!arg) { notify_fail("Read what?\n"); return 0; }
   if(!id(arg)) return (notify_fail("You may read " + short_desc + ".\n"), 0);
   write("Forged in the deepest caverns, this amulet\n"+
      "grants the wearer the power of lightning to\n"+
      "electrify a foe with awesome power.\n"+
      "\t\tSmithed by Jaraxle the Wizard.\n");
   return 1;
}