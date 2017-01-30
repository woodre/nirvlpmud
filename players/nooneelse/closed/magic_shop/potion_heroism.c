/*
  potion_heroism.c
*/

inherit "obj/treasure";

int potion_used;
string str;
object who_obj;

init() {
  ::init();

  add_action("drink", "drink");
}

drink(str) {
  object obj;
  if (!str || !id(str) || potion_used) return 0;
  write("You drink the potion and the vial crumbles to dust.\n"+
        "You feel like a real HERO!!\n");
  say(this_player()->query_real_name()+
      " drinks from a vial,  which then crumbles to dust.\n"+
      this_player()->query_name()+" suddenly grows bulging muscles!\n");
  potion_used=1;
  who_obj=environment(this_object());
  if (!living(who_obj)) destruct(this_object());
  who_obj->reduce_hit_point(-75);
  call_out("warnoff", 720);
  call_out("warnoff2", 840);
  call_out("offhero", 900);
  return 1;
}

warnoff(){
  tell_object(who_obj,
    "\nWARNING>>> 3 minutes until heroism wears off!!!\n"+
    "           You better have more than 75 hp then or YOU DIE!\n\n");
  return 1;
}

warnoff2(){
  tell_object(who_obj,
    "\nWARNING>>> ONE minute until heroism wears off!!!\n"+
    "           You better have more than 75 hp then or YOU DIE!\n\n");
  return 1;
}

offhero(){
  tell_object(who_obj,
              "The heroism wears off.  You feel your health drain away.\n");
  who_obj->hit_player(75);
  return 1;
}

reset(arg) {
  if (arg) return 0;

  set_short("A glass vial");
  set_long("It is a small glass vial filled with a blue liquid.\n");
  set_value(1000);
  set_weight(1);
}

short() {
  if (potion_used)
    if (this_player()->query_level()>=21)
      return "Heroism potion effects (only wiz can see)";
    else
      return;
  else
    return "A glass vial";
}

drop() {
  if (potion_used)
    return 1;
  else
    return 0;
}

query_value() {
  if (potion_used)
    return 0;
  else
    return 1000;
}

id(str) {
  if (potion_used)
    return str=="heroism spell" ||
           str=="spell" ||
           str=="heroism";
  else
    return str=="vial" ||
           str=="glass vial" ||
           str=="small vial" ||
           str=="small glass vial" ||
           str=="potion" ||
           str=="heroism potion";
}
