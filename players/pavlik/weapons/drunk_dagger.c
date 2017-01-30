inherit "obj/weapon";
#define TP environment(this_object())
#define ME capitalize(this_player()->query_name())
#define IT capitalize(attacker->query_name())

reset(arg){
 ::reset(arg);
 if(arg) return;
 set_alias("dagger");
 set_type("dagger");
 set_name("a Silver Dagger");
 set_short("A Slim Dagger");
 set_long(
 "This slim silver dagger looks like an overgrown sewing needle.  Its blade is\n"+
 "long and narrow, however it seems amazingly strong.  The blade is of fine\n"+
 "silver and there is a small gem on the hilt.\n");
 set_class(16);
 set_weight(1);
 set_value(5000);
 set_hit_func(this_object());
}

weapon_hit(attacker){
  int ranx;

 if(TP->query_intoxination() >= TP->query_level() + 1){
 ranx = random(10);

  if(ranx == 0) {
    tell_room(environment(TP),
    ME+" stumbles drunkenly and accidently stabs "+IT+" in the leg!\n");
  } else if(ranx == 1) {
    tell_room(environment(TP),
    ME+" swings his dagger around drunkenly and manages to poke "+IT+" in the eye!\n");
  } else if(ranx == 2) {
    tell_room(environment(TP),
    ME+" falls down in a druken stupor.\n");
    return;
  } else if(ranx == 3) {
    tell_room(environment(TP),
    ME+" belches LOUDLY!\n");
    return;
  } else if(ranx == 4) {
    tell_room(environment(TP),
    ME+" fumbles with his dagger and accidently slashes "+IT+" across the face!\n");
  } else if(ranx == 5) {
    tell_room(environment(TP),
    IT+" impales himself on "+ME+"'s wildly swinging dagger!\n");
  } else if(ranx == 6) {
    tell_room(environment(TP),
    ME+" stumbles around aimlessly.\n");
    return;
  } else if(ranx == 7) {
    tell_room(environment(TP),
    ME+" sings drunkenly while waving his dagger in the air.\n");
  } else if(ranx == 8) {
    tell_room(environment(TP),
    ME+" lurches forward and jabs "+IT+" in the gut!\n");
  } else if(ranx == 9) {
    tell_room(environment(TP),
    ME+" trips and accidently stabs himself in the arm.\n");
    TP->hit_player(3);
    return;
  }
  if(!random(2))
  return 4+random(5);
 }
 return 1;
}
