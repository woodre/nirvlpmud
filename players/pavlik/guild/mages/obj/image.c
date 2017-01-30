inherit "/obj/monster";
#include "/players/pavlik/closed/colors.h"
#define IT capitalize(target->query_name())
#define ME capitalize(owner_name)
#define EN environment(this_object())

string owner_name;
object owner;
object target;
int mirror_num;

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
}

init(){
 ::init();
 if(this_player() == owner)
  add_action("dispell_mirrors","dispell");
}

id(str){
  return str == "~"+owner_name || str == owner_name+"'s image" ||
  str == "image" || str == "mirror image" || str == "image "+mirror_num;
}

short(){
  if(!owner) return;
  else return "~"+owner->short();
}

long(){
  if(!owner) return;
  else return find_player(owner)->long();
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

begin_mirror(ob){
  target = ob;
  tell_room(EN,
  IT+" turns and attacks the "+HIB+"shimmering image"+NORM+" of "+ME+"!\n");
  ob->set_can_kill(1);
  ob->attack_object(this_object());
  call_out("mirror", 3);
  /* make sure this things doesn't stay forever */
  call_out("end_mirror", 60);
  return 1;
}

mirror(){
  if(!EN) return destruct(this_object());
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
    tell_room(EN,
    IT+" turns and attacks the "+HIB+"shimmering image"+NORM+" of "+ME+"!\n");
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
    tell_object(owner,
    "You cannot maintain the Mirror Image spell any longer.\n");
    destroy_all_mirrors();
    return 1;
  }
 
  /* random emotes to keep it interesting */ 
  if(random(4)==1) tell_room(EN,
  IT+"'s attack passes "+HIC+"harmlessly"+NORM+" through "+ME+"!\n");
  else if(random(4)==2) tell_room(EN,
  ME+HIM+" flickers"+NORM+" strangely.\n");
  else if(random(4)==3) tell_room(EN,
  ME+HIR+" taunts "+NORM+IT+"!\n");
  else tell_room(EN,
  IT+" swings and completely misses "+ME+".\n");

  /* decrease the chance by amount (decrease based on guild stat) */
  chance -= decrease;
  /* take maintence cost from player */
  owner->add_spell_point(-15);
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
  if(!EN) return destruct(this_object());
  tell_room(EN,
  ME+"'s "+HIB+"mirror image"+NORM+" sighs softly and disappears.\n");
  if(present("image "+(mirror_num+1), EN)) {
    present("image "+(mirror_num+1), EN)->begin_mirror(target);
  }
  else {
    tell_room(EN,
    HIR+IT+" discovers the real "+ME+" and attacks with vicously!\n"+NORM);
    target->set_wc(target->query_wc() + 2);
    target->attack_object(owner);
    return 1;
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
      tell_room(EN,
      ME+"'s "+HIB+"mirror image"+NORM+" sighs softly and disappears.\n");
      destruct(obj[i]);
    }
  }
  destruct(this_object());
  return 1;
}

