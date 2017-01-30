inherit "/players/pavlik/guild/mages/inherit/pet.c";
inherit "obj/monster";
#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/dragon.h"
#include "/players/pavlik/guild/mages/include/string.h"

#define PET capitalize(name)

object owner;
int follow;
string follow_msg;
string dragon_long;
string dragon_short;
string name2;
string owner_name;
int dragon_level;
int dragon_exp;
int dragon_attack;
int dragon_defense;
int dragon_stamina;
int dragon_magic;
int max_sp;
int sp;
int sp_list;
int spell_count;
int casting;
int wimpy;
int assist;

set_name2() {  
  if( owner )
    name2 = owner->query_real_name()+"'s dragon";
  else
    name2 = "noone's dragon";
}
query_name2() { return name2; }

set_owner_name(str) { owner_name = str; }
query_owner_name() { return owner_name; }


set_owner(ob){ 
  if( ob ) {
    owner = ob; 
    owner_name = ob->query_real_name();
    set_heart_beat(1);
  }
}
query_owner(){ return owner; }

set_follow(i){ follow = i; }
query_follow(){ return follow; }

set_follow_msg(str){ follow_msg = str; }
query_follow_msg(){ return follow_msg; }

set_dragon_long(str){ dragon_long = str; }
query_dragon_long(){ return dragon_long; }

set_dragon_short(str){ dragon_short = str; }
query_dragon_short(){ return dragon_short(); }

set_dragon_level(i){ dragon_level = i; }
query_dragon_level(){ return dragon_level; }

raise_dragon_level(i)
{
  if(!i) dragon_level++;
  else dragon_level += i;
  if(dragon_level < 1) dragon_level = 1;
  if(dragon_level > MAX_LEVEL) dragon_level = MAX_LEVEL;
  update_dragon();
}

set_dragon_exp(i){ dragon_exp= i; }
query_dragon_exp(){ return dragon_exp; }
add_dragon_exp(i){ dragon_exp += i; }
add_exp(i)
{
  dragon_exp += i;
  if(dragon_exp < 0) dragon_exp = 0;
}

set_dragon_attack(i){ dragon_attack = i; }
query_dragon_attack(){ return dragon_attack; }

raise_dragon_attack(i)
{
  if(!i) dragon_attack++;
  else dragon_attack += i;
  if(dragon_attack < 1) dragon_attack = 1;
  if(dragon_attack > MAX_ATTACK) dragon_attack = MAX_ATTACK;
  update_dragon();
}

set_dragon_defense(i){ dragon_defense = i; }
query_dragon_defense(){ return dragon_defense; }

raise_dragon_defense(i)
{
  if(!i) dragon_defense++;
  else dragon_defense += i;
  if(dragon_defense < 1) dragon_defense = 1;
  if(dragon_defense > MAX_DEFENSE) dragon_defense = MAX_DEFENSE;
  update_dragon();
}

set_dragon_stamina(i){ dragon_stamina = i; }
query_dragon_stamina(){ return dragon_stamina; }

raise_dragon_stamina(i)
{
  if(!i) dragon_stamina++;
  else dragon_stamina += i;
  if(dragon_stamina < 1) dragon_stamina = 1;
  if(dragon_stamina > MAX_STAMINA) dragon_stamina = MAX_STAMINA;
  update_dragon();
}

set_dragon_magic(i){ dragon_magic = i; }
query_dragon_magic(){ return dragon_magic; }

raise_dragon_magic(i)
{
  if(!i) dragon_magic++;
  else dragon_magic += i;
  if(dragon_magic < 1) dragon_magic = 1;
  if(dragon_magic > MAX_MAGIC) dragon_magic = MAX_MAGIC;
  update_dragon();
}

set_max_sp(n){ max_sp = n; }
query_max_sp(){ return max_sp; }

set_sp(i){ sp = i; }
query_sp(){ return sp; }
add_spell_point(i)
{
  sp += i;
  if(sp > max_sp) sp = max_sp;
}

set_casting(i){ casting = i; }
query_casting(){ return casting; }

set_wimpy(i){ wimpy = i; }
query_wimpy(){ return wimpy; }

set_assist(i){ assist = i; }
query_assist(){ return assist; }



short()
{
  return capitalize(name)+" "+dragon_short+" Dragon";
}

long()
{
  if(tp == owner)
  {
	if(!dragon_long || dragon_long == "none")
	{
                write("You have not created a description for your dragon yet.\n");
                write("It looks rather drab and unremarkable right now.\n");
                write("Use <name> 'setdescrip' to create your dragon's description.\n");
        }
        else
        {
                write(dragon_long+"\n");
        }
	write("\n");
	dragon_score();
  }
  else
  {
        if(!dragon_long || dragon_long == "none")
                write("This is a large, rather plain looking dragon.\n");
        else
                write(dragon_long+"\n");
  }
  return;
}


dragon_score()
{
  write("  Level: "+strpad(dragon_level, " ", 20));
  write("Hit Points: "+query_hp()+"/"+query_mhp()+"\n");

  write("  Experience: "+strpad(dragon_exp, " ", 13));
  write("Spell Points: "+sp+"/"+max_sp+"\n");

  write("  Attack : "+strpad(dragon_attack, " ", 21));
  write("Stamina: "+dragon_stamina+"\n");

  write("  Defense: "+strpad(dragon_defense, " ", 23));
  write("Magic: "+dragon_magic+"\n");

  write("\n");
  write("Autoassist is ");
  if(assist) write("on.\n"); else write("off.\n");
  write(PET+" will flee at "+wimpy+" hit points.\n");
}


update_dragon()
{
  save_stats();
  configure_dragon();
  return 1;
}


save_stats()
{
  object obj;

  if(!owner || !(obj = present("mageobj", owner)))
  {
	destruct(this_object());
	return;
  }

  if(!name) name = "generic";
  if(!follow_msg) follow_msg = "stomps";

  obj->set_dragon_descrip(
	lower_case(name)+"#"+dragon_short+"#"+follow_msg+"#"+dragon_long);
  obj->set_dragon_stats(
	dragon_level+"#"+dragon_exp+"#"+dragon_attack+"#"+dragon_defense+"#"+dragon_stamina+"#"+dragon_magic);

}


configure_dragon()
{
  object obj;
  string dragon_name;

  if(!owner)
  {
	destruct(this_object());
	return 0;
  }

  if(!(obj = present("mageobj", owner)))
  {
	destruct(this_object());
	return 0;
  }

#ifdef __LDMUD__
  remove_action(lower_case(name), owner);
#else
  remove_action(lower_case(name));
#endif

  if(sscanf(obj->query_dragon_descrip(), "%s#%s#%s#%s",
	dragon_name, dragon_short, follow_msg, dragon_long) != 4)
  {
	dragon_name = "generic";
	dragon_short = "the";
	dragon_long = 0;
	follow_msg = "stomps";
  }

  if(sscanf(obj->query_dragon_stats(), "%d#%d#%d#%d#%d#%d",
	dragon_level, dragon_exp, dragon_attack, dragon_defense, dragon_stamina, dragon_magic) != 6)
  {
	dragon_level = 1;
	dragon_exp = 0;
	dragon_attack = 1;
	dragon_defense = 1;
	dragon_stamina = 1;
	dragon_magic = 1;
  }

  if(!dragon_name) dragon_name = "generic";
  if(!dragon_short) dragon_short = "the";
  if(!follow_msg) follow_msg = "stomps";
  if(!dragon_level) dragon_level = 1;
  if(!dragon_attack) dragon_attack = 1;
  if(!dragon_defense) dragon_defense = 1;
  if(!dragon_stamina) dragon_stamina = 1;
  if(!dragon_magic) dragon_magic = 1;

  name = capitalize(dragon_name);
  set_name(capitalize(dragon_name));
  set_name2(owner->query_real_name()+"'s dragon");
  set_follow_msg(follow_msg);

  set_hp(50 + (dragon_stamina * 5));	/* max 550 */
  set_wc(10 + (dragon_attack / 4));	/* max 25  */
  set_ac(0 + (dragon_defense / 4));	/* max 15  */
  max_sp = 50 + (dragon_magic * 5);	/* max 550 */
  sp = max_sp;

/*
  sp_list = present("mageobj", query_owner())->query_dragon_spells();
  sp_list = random(3)+1;
*/

  if(tp && tp == owner)
	add_action("dragon_commands", dragon_name);

  this_object()->set_heart_beat(1);
  return 1;
}


dragon_commands(str)
{
  string cmd, arg;
  if(tp == owner )
  {
    if(!str) {
      notify_fail(PET+" blows "+HIBLK+"smoke"+NORM+" from its nosrils and shakes its head in "+HIC+"confusion"+NORM+".\n");
      return 0;
    }
	if(sscanf(str, "%s %s", cmd, arg) == 2)
	{
		if(cmd == "name")	{ dragon_name(arg); return 1; }
		else if(cmd == "get")	{ pet_get(arg); return 1; }
/*
                else if(cmd == "say")   { dragon_say(arg); return 1; }
*/
		else if(cmd == "give")	{ pet_give(arg); return 1; }
		else if(cmd == "drop")	{ pet_drop(arg); return 1; }
		else if(cmd == "exp")	{ transfer_exp(arg); return 1; }
		else if(cmd == "kill")	{ dragon_kill(arg); return 1; }
		else if(cmd == "assist") { dragon_assist(arg); return 1; }
		else if(cmd == "wimpy") { dragon_wimpy(arg); return 1; }
		else if(cmd == "setmove") { dragon_setmove(arg); return 1; }
		/* guard */
		/* say   */
		/* emote */
		/* look  */
		/* setlook */
	}
	/* save   */
	/* report */
	/* lead   */
	/* kill   */
	else if(str == "kill")		{ dragon_kill(); return 1; }
	else if(str == "assist")	{ dragon_assist(); return 1; }
	else if(str == "dismiss")	{ dragon_dismiss(); return 1; }
	else if(str == "setdescrip")	{ dragon_setdescrip(); return 1; }
	else if(str == "stay")		{ dragon_stay(); return 1; }
	else if(str == "follow")	{ dragon_follow(); return 1; }
	else if(str == "feed")	        { feed_dragon(); return 1; }
  }
}


transfer_exp(str)
{
  int xp;

  if(!sscanf(str, "%d", xp) == 1)
  {
	write("You must transfer at least 10 experience points to "+PET+".\n");
	return 1;
  }

  if(xp < 10)
  {
	write("You must transfer at least 10 experience points to "+PET+".\n");
	return 1;
  }

  if(tp->query_guild_exp() - xp < ("/players/pavlik/guild/mages/inherit/advance")->rank_costs(tp->query_guild_rank()))
  {
	write("You cannot afford to transfer that much experience to "+PET+".\n");
	return 1;
  }

  write("You transfer "+HIC+xp+NORM+" experience points to "+PET+".\n");
  tp->add_guild_exp(-xp);
  dragon_exp += xp;
  save_stats();
  return 1;
}


dragon_setdescrip()
{
  dragon_long = "";
  write("Enter the description for your dragon one line at a time.\n");
  write("type '**' on a line by itself to finish.\n");
  write("> ");
  input_to("add_descrip");
  return 1;
}


add_descrip(str)
{
  if(str == "**")
  {
	write(PET+"'s description has been changed.\n");
	save_stats();
	return 1;
  }
  else
  {
	dragon_long = dragon_long + str + "\n";
	write("> ");
	input_to("add_descrip");
	return 1;
  }
}


dragon_assist(str)
{
  if( (!str && assist) || str == "off")
  {
	write(PET+" will "+HIR+"not"+NORM+" "+HIC+"auto-assist"+NORM+" you in combat.\n");
	assist = 0;
	return 1;
  }
  if( (!str && !assist) || str == "on")
  {
	write(PET+" "+HIY+"will"+NORM+" "+HIC+"auto-assist"+NORM+" you in combat.\n");
	assist = 1;
	return 1;
  }
}


dragon_kill(str)
{
  object obj;

  if(!str)
	obj = tp->query_attack();
  else
	obj = present(str, environment());

  if(!obj)
  {
	write(PET+" gives you a puzzled look.\n");
	return 1;
  }

  if(environment()->query_no_fight())
  {
	tell_object(obj, PET+" looks at you and snarls menacingly.\n");
	tell_room(environment(), PET+" looks at "+IT+" and snarls menacingly.\n", ({obj}));
	return 1;
  }

  obj->set_can_kill(1);
  set_can_kill(1);

  tell_room(environment(),
    HIC+PET+NORM+" looses an "+HIM+"ear-splitting "+NORM+HIY+"R~O~A~R"+NORM+" and tears into "+IT+"!\n");

  attack_object(obj);
  if(!obj->query_attack())
	obj->attack_object(this_object());

  return 1;
}


dragon_say(str)
{
  if(!str) return 0;

  say(query_name()+" says: \""+str+"\"\n");
  return 1;
}

dragon_name(str)
{
  if(!str) return 0;

  str = lower_case(str);

  if(!valid_string(str, 30))
  {
	write("Invalid dragon name, try again.\n");
	return 1;
  }

  remove_action(lower_case(name));
  name = capitalize(str);
  set_name(capitalize(str));
  add_action("dragon_commands", lower_case(name));
  write("Your dragon is now named "+HIC+capitalize(str)+NORM+".\n");
  save_stats();
  return 1;

}


dragon_setmove(str)
{
  if(!str) return 0;

  str = lower_case(str);

  if(!valid_string(str, 30))
  {
	write("Invalid dragon move, try again.\n");
	return 1;
  }

  follow_msg = str;
  write("Dragon move is now: "+HIC+str+NORM+"\n");
  return 1;
}


dragon_dismiss()
{
  write(
    "You "+HIC+"dismiss"+NORM+" your dragon.\n" +
    PET+" "+CYN+"bows low"+NORM+" before you and then "+HIC+"leaps"+NORM+" into the sky and "+HIBLK+"disappears"+NORM+".\n");
  say(
    OWN+" "+HIC+"dismisses"+NORM+" "+owner->query_possessive()+" dragon.\n" +
    PET+" "+CYN+"bows low"+NORM+" before "+OWN+" and then "+HIC+"leaps"+NORM+" into the sky and "+HIBLK+"disappears."+NORM+"\n",
    owner);
  save_stats();
  destruct(this_object());
  return 1;
}

feed_dragon(){
  object ob;
  ob = present("corpse",environment(this_object()));
  if(!ob){
    notify_fail(PET+" blows "+HIBLK+"smoke"+NORM+" from its nosrils and shakes its head in "+HIC+"confusion"+NORM+".\n");
    return 0;
  }
  say(PET+" opens its maw and "+HIR+"devours "+NORM+"the corpse with a few snaps of its jaws.\n");
  heal_self( ob->heal_value() );
  destruct(ob);
  return 1;
}


dragon_stay()
{
  write(
    "You command "+PET+" to "+HIC+"stay"+NORM+".\n" +
    "The mighty dragon bows its head in acquiesce.\n");
  say(
    OWN+" commands "+owner->query_possessive()+" dragon to stay.\n" +
    "The mighty dragon bows its head in acquiesce.\n",
    owner);
  follow = 0;
  return 1;
}


dragon_follow()
{
  write(
    "You command "+PET+" to "+HIC+"follow"+NORM+".\n" +
    "The dragon nods its mighty head and puffs of "+HIW+"smoke"+NORM+" jet from its nostrils.\n");
  say(
    OWN+" commands "+owner->query_possessive()+" dragon to follow.\n" +
    "The dragon nods its mighty head and puffs of "+HIW+"smoke"+NORM+" jet from its nostrils.\n",
    owner);
  follow = 1;
}


valid_string(str, max)
{
  int i, length;

  length = strlen(str);

  if(max && length > max)
	return 0;

  i=0;
  while(i<length)
  {
	if(str[i] < 'a' || str[i] > 'z')
		return 0;
	i += 1;
  }
  return 1;
}


monster_died()
{
  object ob;
  int i;

  /* make sure the owner is still around */
  if(!owner) return 0;

  tell_room(environment(this_object()),
    CYN+"\n"+
    PET+"'s body turns to stone and then explodes into thousands of pieces!\n"+
    "You are pelted with dagger-like shards of stone!\n"+NORM);

  /* dragon's death drains owner's spell points */
  tell_object(owner,
    HIC+PET+"'s death weakens you to the point of exhaustion.\n"+NORM);
    owner->add_spell_point(-random(100));

  /* lose a stat just like a player would */
  i = random(5);
  if(i == 0) {
	dragon_attack--;
	if(dragon_attack < 1) dragon_attack = 1;
	tell_object(owner, PET+"'s attack is now "+dragon_attack+".\n");
  }
  else if(i == 1) {
	dragon_defense--;
	if(dragon_defense < 1) dragon_defense = 1;
	tell_object(owner, PET+"'s defense is now "+dragon_defense+".\n");
  }
  else if(i == 2) {
	dragon_stamina--;
	if(dragon_stamina < 1) dragon_stamina = 1;
	tell_object(owner, PET+"'s stamina is now "+dragon_stamina+".\n");
  }
  else if(i == 3) {
	dragon_magic--;
	if(dragon_magic < 1) dragon_magic = 1;
	tell_object(owner, PET+"'s magic is now "+dragon_magic+".\n");
  }

  save_stats();

  /* no corpse to heal off of either */
  if(present("corpse of "+PET, environment(this_object())))
  {
	destruct(present("corpse of "+PET, environment(this_object())));
  }

  /* do some damage to everything in the room */
  ob = all_inventory(environment(this_object()));
  for(i=0; i<sizeof(ob); i++)
  {
	if(ob[i] && ob[i] != this_object())
		ob[i]->do_damage(random(30), "other|earth");
  }

  return 0;
}


dragon_wimpy(str)
{
  int x;

  if(!str)
  {
	write(PET+" will flee at "+CYN+wimpy+NORM+" hit points.\n");
	return 1;
  }

  if(sscanf(str, "%d", x) != 1)
  {
	write(PET+" gives you a puzzled look.\n");
	return 1;
  }

  if(x < 0 || x > query_mhp())
  {
	write(PET+" gives you a puzzled look.\n");
	return 1;
  }

  write(PET+" will now flee at "+CYN+x+NORM+" hit points.\n");
  wimpy = x;
  return 1;
}


dragon_flee()
{
  tell_room(environment(this_object()), PET+" "+HIC+"flees"+NORM+" the fight!\n");
  move_object(this_object(), GUILD_HOME);
  follow = 0;
}
