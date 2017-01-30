#include "/players/pavlik/guild/mages/defs.h"
inherit "/obj/monster";

#define MAX_MISSING	5
#define TARG capitalize(target->query_name())

object owner;		/* owner */
object target;		/* target */
int mirror_num;		/* for tracking ourself */
string *room_msgs;	/* room messages */
int owner_missing;	/* how long our owner is gone (if missing) */
int chance;		/* base chance that illusion is detected */
int decrease;		/* how fast the base chance decreases */

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("image");
  set_alias("image");
  set_short("image");
  set_long("image");
  set_race("mirror image");
  set_level(1);
  set_can_kill(1);
  set_ac(100);
  set_armor_params("physical", 0, 100);
  set_armor_params("magical", 0, 100);
  set_wc(0);
  set_hp(10000);
  mirror_num = 0;
  owner_missing = 0;
  owner = 0;
  room_msgs = ({});
  set_dead_ob(this_object());
  if(!present("party object", this_object()))
	move_object(clone_object(OBJ_DIR + "fake_party"), this_object());
}

init() {
  ::init();
  if(this_player() == owner)
	add_action("dispell_mirrors","dispell");
}

id(str) {
  if(!owner)
	return str == "mirror image";
  else
  {
	string name;
	name = owner->query_real_name();
	return str == "~"+name || str == name+"'s image" || str == name+"'s mirror image" ||
	  str == "image" || str == "mirror image";
  }
}

short()
{
  if(!owner)
	return;
  else
	return "~"+owner->short();
}

long()
{
  if(!owner)
	return;
  else
	return owner->long();
}

/*
 * experience awarded to this object is passed on
 * to the spell caster
 */
add_exp(i)
{
  if(i > 0 && owner) {
    owner->add_exp(i);
    tell_object(owner,"Experience Gain: "+i+"\n");
    if(owner->query_level() < 20 && owner->query_extra_level() < 100)
    {
      int xpn;
      xpn = (int)call_other("/bin/play/_xpnext", "query_next_xp", 0, owner);
      if(xpn <= 0) write("You are ready to advance to your Next Level.\n");
      else write("Experience needed for your Next Level: "+xpn+".\n");
    }
  }  
}

set_owner(ob){ owner = ob; }
query_owner(){ return owner; }

set_target(ob){ target = ob; }
query_target(){ return target; }

set_chance(i){ chance = i; }
query_chance(){ return chance; }

set_decrease(i){ decrease = i; }
query_decrease(){ return decrease; }

set_mirror_num(i){ mirror_num = i; }
query_mirror_num(){ return mirror_num; }

is_mirror(){ return 1; }

begin_mirror(ob)
{
  if(!owner)
  {
	destroy_all_mirrors();
	return 1;
  }

  target = ob;
  ob->set_can_kill(1);
  ob->attack_object(this_object());

  if(mirror_num > 1)
  {
	tell_room(en,
	  TARG+" turns and attacks "+HIY+"another"+NORM+" of "+OWN+"'s "+HIC+"illusions"+NORM+"!\n",
	  ({owner}));
	tell_object(owner,
	  TARG+" turns and attacks "+HIY+"another"+NORM+" one of yoour "+HIC+"illusions"+NORM+".\n");
  }

  room_msgs = ({
	OWN+" "+HIB+"blinks"+NORM+" out and then "+MAG+"reappears"+NORM+".\n",
	OWN+" "+HIM+"flickers"+NORM+" in and out of "+HIC+"existance"+NORM+".\n",
	OWN+" "+HIBLK+"fades"+NORM+" from view only to "+HIC+"reappear"+NORM+" suddenly\n",
	TARG+"'s attack passes "+HIY+"harmlessly"+NORM+" through "+OWN+".\n",
	TARG+"'s misses "+OWN+" *again* and "+HIM+"cries"+NORM+" in total "+HIY+"frustration"+NORM+".\n",
	TARG+"'s "+HIG+"futile"+NORM+" attack "+HIW+"misses"+NORM+" "+OWN+".\n",
	OWN+" "+HIG+"taunts"+NORM+" "+TARG+" mercillessly.\n",
	TARG+" "+HIM+"flails"+NORM+" wildly at "+OWN+" with "+HIW+"no result"+NORM+".\n",
  });

  call_out("mirror", 3);
  return 1;
}


mirror()
{
  if(!owner || !en)
	return destruct(this_object());

  if(!environment(owner))
	return call_out("mirror", 3);

  if(!target || !present(target, en)){
	  destroy_all_mirrors();
	  return 1;
  }

  if(!present(owner, en) || owner->query_attack() != target){
	  owner_missing++;
	  if(owner_missing > MAX_MISSING){
		  destroy_all_mirrors();
		  return 1;
	  }
  }

  if(!target->query_attack()){
	  destroy_all_mirrors();
	  return 1;
  }

  /*
   * make sure target didn't get distracted
   */
  if(target->query_attack() != this_object()){
	tell_room(en,
	  "~"+OWN+" "+HIG+"taunts"+NORM+" "+TARG+" mercilessly.\n" +
	  TARG+" turns and attacks the "+HIB+"shimmering image"+NORM+" of "+OWN+"!\n");
	target->attack_object(this_object());
  }

  /* does the monster see through our illusion? */
  if(random(150) > chance)
  {
	tell_room(en,
	  TARG+" "+HIR+"sees through"+NORM+" "+OWN+"'s "+HIC+"illusion"+NORM+"!\n",
	  ({owner}));
	tell_object(owner,
	  TARG+" "+HIR+"sees through"+NORM+" your "+HIC+"illusion"+NORM+"!\n");
	end_mirror(1);
	return 1;
  }

  /* do we have the sp's to maintain this? */
  if(owner->query_sp() < MIN_SP)
  {
	tell_object(owner,
	  SPELL_PROMPT+"You "+RED+"cannot maintain"+NORM+" the "+HIC+"Mirror Image"+NORM+" spell any longer."+NORM+"\n");
	destroy_all_mirrors();
	return 1;
  }
 
  /* some emotes to keep it interesting */ 
  tell_room(en, room_msgs[random(sizeof(room_msgs)-1)]);

  /* decrease the chance by amount (decrease based on guild stat) */
  chance -= decrease;

  /* take maintence cost from player */
  owner->add_spell_point(-(2+random(5)));

  call_out("mirror", 3);
  return 1;
}


dispell_mirrors(str)
{
  if(str == "image")
  {
	write("You wave your hand and the "+HIC+"illusion"+NORM+" is "+HIM+"dispelled"+NORM+".\n");
	say(OWN+" waves "+PO+" hand and the "+HIC+"illusion"+NORM+" is "+HIM+"dispelled"+NORM+".\n");
	destroy_all_mirrors();
	return 1;
  }
}


end_mirror(c)
{
  object next;

  if(owner){
	  tell_room(en,
	    OWN+"'s "+HIC+"mirror image"+NORM+" "+HIBLK+"sighs softly"+NORM+" and "+HIB+"disappears"+NORM+".\n",
	    ({owner}));
	  tell_object(owner,
	    "Your "+HIC+"mirror image"+NORM+" "+HIBLK+"sighs softly"+NORM+" and "+HIB+"disappears"+NORM+".\n");
  }
  else{
	tell_room(en,
	  "The "+HIC+"mirror image"+NORM+" "+HIBLK+"sighs softly"+NORM+" and "+HIB+"disappears"+NORM+".\n");
  }

  if(c){
	  if(next = find_next_mirror()){
		  next->begin_mirror(target);
	  }
	else{
		tell_room(en, TARG+" discovers the "+HIC+"real"+NORM+" "+OWN+" and attacks "+HIR+"viciously"+NORM+"!\n");
		target->attack_object(owner);
		/** Added by Dragnar **/
		if(owner && present("mageobj", owner))
			present("mageobj", owner)->remove_spell_object("mimage");
	}
  }
  destruct(this_object());
  return 1;
}

monster_died() { 
  object c;
  if(c = present("corpse", environment()))
  {
    destruct(c);
  }
}


destroy_all_mirrors()
{
  object obj;
  int i;
 
  obj = all_inventory(en);
  for(i=0; i<sizeof(obj); i++)
  {
	if(obj[i]->is_mirror() && obj[i] != this_object())
	{
		obj[i]->end_mirror();
	}
  }

  end_mirror();
  return 1;
}


find_next_mirror()
{
  object obj;
  int i;

  obj = all_inventory(en);
  for(i=0; i<sizeof(obj); i++)
  {

        if(obj[i]->query_mirror_num() == (mirror_num+1))
		return obj[i];
  }
  return 0;
}

