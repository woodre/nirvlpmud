inherit "/obj/monster";
#include "/players/pavlik/closed/colors.h"
#define IT capitalize(target->query_name())
#define ME capitalize(owner_name)
#define EN environment(this_object())

/*
 * See the file: /players/pavlik/magse/spells/mirror_image
 * for details of this object!
 */

string owner_name;
object owner;
object target;
int mirror_num;
int msg_num;

/* the chance the monster sees through the illusion */
int chance;

/* how much the chance decreases each time (based on guild stat) */
int decrease;

reset(arg) {
  ::reset();
  if(arg) return;
  set_name("image");
  set_short("image");
  set_long("image");
  set_can_kill(1);
  set_ac(50);
  set_wc("NON");
  set_hp(1000);
  set_level(1);
  mirror_num = 0;
  owner = "nobody";
  msg_num = 0;
}

init(){
  ::init();
  if(this_player() == owner)
	add_action("dispell_mirrors","dispell");
}

id(str) {
  return str == "~"+owner_name || str == owner_name+"'s image" ||
  str == "image" || str == "mirror image";
}

short() {
  if(!owner) return;
  else return "~"+owner->short();
}

long(){
  if(!owner) return;
  else return owner->long();
}

set_owner(ob){ owner = ob; owner_name = ob->query_real_name(); }
query_owner(){ return owner; }
query_owner_name(){ return owner_name; }
set_target(ob){ target = ob; }
query_target(){ return target; }
set_chance(i){ chance = i; }
set_decrease(i){ decrease = i; }
set_mirror_num(i){ mirror_num = i; }
query_mirror_num(){ return mirror_num; }
is_mirror(){ return 1; }

begin_mirror(ob) {
  target = ob;
  ob->set_can_kill(1);
  ob->attack_object(this_object());
  if(mirror_num > 1) tell_room(EN,
  IT+" turns and attacks another of "+ME+"'s illusions!\n");
  call_out("mirror", 1);
  return 1;
}

mirror() {

  if(!owner || !EN) return destruct(this_object());                
  if(!environment(owner)) return call_out("mirror", 2);

  if(!target || !present(target, EN)) {
	destroy_all_mirrors();
	return 1;
  }

  if(!owner || !present(owner, EN)) {
	destroy_all_mirrors();
	return 1;
  }

  if(owner->query_attack() != target) {
	destroy_all_mirrors();
	return 1;
  }

  if(!target->query_attack() == this_object()){
	/* don't get distracted by something else! */
	tell_room(EN, IT+" turns and attacks the "+HIB+"shimmering image"+NORM+" of "+ME+"!\n");
	target->attack_object(this_object());
  }

  /* does the monster see through our illusion? */
  if(random(100) > chance) {
	tell_room(EN, HIR+IT+" sees through "+ME+"'s illusion!\n"+NORM);
	end_mirror();
	return 1;
  }

  /* do we have the sp's to maintain this? */
  if(owner->query_sp() < 0) {
	tell_object(owner, HIW+"You cannot maintain the Mirror Image spell any longer."+NORM+"\n");
	destroy_all_mirrors();
	return 1;
  }
 
  /* some emotes to keep it interesting */ 
  if(msg_num == 0)
	tell_room(EN, IT+"'s attack passes "+HIC+"harmlessly"+NORM+" through "+ME+"!\n");
  else if(msg_num == 1)
	tell_room(EN, ME+HIM+" flickers"+NORM+" strangely.\n");
  else if(msg_num == 2)
	tell_room(EN, IT+" swings and "+HIY+"completely misses"+NORM+" "+ME+".\n");
  else if(msg_num == 3)
	tell_room(EN, ME+" seems to "+HIB+"blink in and out"+NORM+" of existance.\n");

  msg_num++;
  if(msg_num > 3) msg_num = 0;

  /* decrease the chance by amount (decrease based on guild stat) */
  chance -= decrease;

  /* take maintence cost from player */
  owner->add_spell_point(-(5+random(5)));

  call_out("mirror", 4);
  return 1;
}

dispell_mirrors(str){
  if(str == "image"){
	write("You wave your hand and the "+HIC+"mirror image disappears.\n"+NORM);
	say(capitalize(owner_name)+" waves his hand and his "+HIC+" illusion disappears.\n"+NORM);
	destroy_all_mirrors();
	return 1;
  }
}

end_mirror() {
  object next;

  tell_room(EN, ME+"'s "+HIB+"mirror image"+NORM+" sighs softly and disappears.\n");

  next = find_next_mirror();
  if(next) {
	next->begin_mirror(target);
  }
  else {
	tell_room(EN, HIR+IT+" discovers the real "+ME+" and attacks viciously!\n"+NORM);
	/* commenting out the wc raise for now */
	/* target->set_wc(target->query_wc() + 2); */
	target->attack_object(owner);
  }
  destruct(this_object());
  return 1;
}

destroy_all_mirrors() {
  object obj;
  int i;
 
  obj = all_inventory(EN);
  for(i=0; i<sizeof(obj); i++) {
	if(obj[i]->is_mirror() && obj[i] != this_object()) {
		tell_room(EN, ME+"'s "+HIB+"mirror image"+NORM+" sighs softly and "+HIY+"disappears"+NORM+".\n");
		destruct(obj[i]);
	}
  }
  destruct(this_object());
  return 1;
}

/* 03/16/06 Earwax: Redid this fun, fixing bug */
find_next_mirror() {
  object *obj;
  int i;

  if (!EN) return 0;
  i = sizeof(obj = all_inventory(EN));
  while(i--)
    if (obj[i]->query_mirror_num() == (mirror_num+1))
      return obj[i];

  return 0;
/*
  for(i=0; i<sizeof(obj); i++) {
	if(obj[i]->query_mirror_num() == (mirror_num+1))
		return obj[i];
  }
  return 0;
*/
}

