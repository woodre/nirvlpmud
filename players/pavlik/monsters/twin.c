/* this object is cloned by the Mage spell Vorpal_Twin.
 * this creates a duplicate of the target monster and the two objects
 * attack each other.  All configs are done by the do_twin() function
 * which is called out when the spell is cast: /mages/spells/vorpal_twin
*/
inherit "/obj/monster";
#include "/players/pavlik/closed/colors.h"
 object target, owner;
 int bonus;
reset(arg){
 ::reset(arg);
 if(arg) return;
 set_name("vorpal_twin");
 set_alias("twin");
 set_race("twin");
 set_short("twin");
 set_long("twin");
 set_level(1);
 set_ac(1);
 set_wc(1);
 set_hp(1);
 set_al(0);
 set_aggressive(0);
 set_dead_ob(this_object());
}

add_exp(i){ owner->add_exp(i); }

do_twin(ob){
 target = ob;
 owner = this_player();
 bonus = present("mageobj", this_player())->query_necromancy() - 79;
 this_object()->set_short(HIR+"* "+NORM+ob->short()+HIR+" *"+NORM);
 this_object()->set_name(HIR+"~"+NORM+ob->query_name());
 this_object()->set_long("A Vorpal Twin of "+ob->short()+"\n");
 this_object()->set_level(ob->query_level());
 this_object()->set_wc(ob->query_wc());
 this_object()->set_ac(ob->query_ac());
 this_object()->set_hp(ob->query_hp());
 this_object()->heal_self(10000);
 this_object()->attack_object(ob);
 ob->attack_object(this_object());
 call_out("twin_check", 3);
 return 1;
}

twin_check(){
 if(!owner || !target){
  tell_room(environment(this_object()),
  capitalize(this_object()->query_name())+" turns to vapor and disappears.\n");
  destruct(this_object());
  return 1;
  }
 if(!present(target, environment(this_object()))){
  tell_room(environment(this_object()),
  capitalize(this_object()->query_name())+" turns to vapor and disappears.\n");
  destruct(this_object());
  return 1;
  }
 if(random(target->query_level()+10) > random(owner->query_level()+bonus)){
  tell_room(environment(this_object()),
  HIR+target->short()+"'s twin cries mournfully as the "+HIB+"Vorpal Twins"+HIR+
 " merge together.\n"+NORM+
 "The two beings become one again.\n");
  move_object(clone_object("players/pavlik/mages/obj/twin_obj"), target);
  move_object(this_object(), "room/void");
  destruct(this_object());
  return 1;
  }
 bonus = bonus - 2;
 call_out("twin_check", 4);
 return 1;
}

monster_died(){
 object ob;
 ob = present("corpse", environment(this_object()));
 move_object(ob, "room/void");
 destruct(ob);
 return 0;
}
