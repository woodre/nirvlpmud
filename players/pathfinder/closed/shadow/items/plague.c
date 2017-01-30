
#define ME environment(this_object())->query_name()
#define ENV environment
#define ENVTO environment(this_object())
#define CAP capitalize

int times;
string caster;

id(str) {
  return str == "plague" ||
         str == "plagueobject" ||
         str == "sickness";
}

query_weight() { return 0; } /* no weight */
get() { return 0; }  /* can get */

set_caster(me) { caster = me; }

reset(arg) {
  if(arg) return;
  caster = "\0";
  times = 0;
}

init() {
  call_out("sickness_effect", 15);
}

sickness_effect() {   
  object who;
  int damage;
  if(times > 5) {
    tell_room(ENV(ENVTO), "You see " + CAP(ME) + " begin to get healthy once again,\n" +
        "purging their body of the plague.\n");
    destruct(this_object());
  }

  who = find_player(caster);


  if(!ENVTO->query_attack() && !present(caster, ENV(ENVTO))) {
    ENVTO->set_agressive(1); /* makes monster aggressive */
  }

  if(!ENVTO->query_attack() && present(caster, environment(ENVTO))) {
    ENVTO->set_aggressive(1); /* makes monster aggressive */
    ENVTO->attack_object(who); /* attacks the caster */
  }
 

  tell_room(ENV(ENVTO), "You can see " + CAP(ME) +
            " suffering from the horrific effects of the plague.\n");

  damage = random(15) + 15; /* do 15 + random 15 damage */

  who->spell_object(ENVTO, "plague effects", damage, 0);
/*
  ENVTO->heal_self(-damage);
*/
  times++;
  call_out("sickness_effect", 15);
  return 1;
}


