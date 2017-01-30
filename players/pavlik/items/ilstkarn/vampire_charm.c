#define ME capitalize(owner->query_name())
#define IT capitalize(obj->query_name())
#define ROOM environment(owner)

/*
 * This object is used by ~/monsters/ilstkarn/vampire.c
 * to make other beings fight the vampires attacker.
 * This object can start a fight between two players that do
 * not have thier PK set.
 */

object owner;
object obj;

reset(arg){
  if(arg) return;
}

id(str){  return "vampire_charm"; }
long(){ return; }
short(){ return; }
get(){ return 0; }
drop(){ return 0; }
query_weight(){ return 0; }
query_value(){ return 0; }
extra_short(){ return "++CHARMED++"; }
query_owner(){ return owner; }
set_owner(ob){ owner = ob; }

do_charm(ob) {
  obj = ob;
  owner->attack_object(obj);
  call_out("charm", 3);
}

charm() {
  if(!obj) {
    destruct(this_object());
    return 1;
  }

  /* if the Vampire or target is gone, then stop */
  if(!present("vampire", ROOM) || !present(obj, ROOM)) {
    tell_object(owner, "You will like you just woke up from a bad dream.\n");
    tell_room(ROOM, ME+" blinks confusedly.\n");
    destruct(this_object());
    return 1;
  }

  if(owner->query_ghost() || obj->query_ghost()) {
    destruct(this_object());
    return 1;
  }

  /* always have a chance to break free of the spell */
  if(!random(10)) {
    tell_object(owner, "You break free of the Vampire's charm!\n");
    tell_room(ROOM, ME+" breaks free of the Vampire's spell.\n");
    owner->stop_fight();
    destruct(this_object());
    return 1;
  }

  /* if we stopped attacking then get back to it! */
  if(owner->query_attack() != obj) {
    tell_object(owner,
    "> The Vampire commands you to attack "+IT+"!\n"+
    "> You try to refuse the command but you cannot.\n");
    tell_room(ROOM, "The Vampire commands "+ME+" to attack "+IT+".\n");
    owner->attack_object(obj);
  }

  call_out("charm", 3);
  return 1;
}

