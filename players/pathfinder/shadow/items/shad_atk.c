
#define ME environment(this_object())->query_name()
#define ENV environment
#define ENVTO environment(environment(this_object()))
#define CAP capitalize

int times;
string caster;

id(str) {
  return str == "shadow_attack_object" ||
         str == "shadow_attack";
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
  call_out("shadow_attacking", 10);
}

shadow_attacking() {
  object who;
  int damage;
  if(times > 3) {
    tell_room(ENVTO,"You see " + CAP(ME) + " regain control of their shadow.\n");
    destruct(this_object());
  }

  tell_room(ENVTO, "You can see " + CAP(ME) +
            "'s shadow continue pummeling its master with blows!\n");

  damage = random(15) + 10; /* do 10 + random 15 damage */

  ENVTO->heal_self(-damage);
  times++;
  call_out("shadow_attacking", 15);
  return 1;
}

