/* borrowed from the great Eurale */
#define ETO environment(this_object())
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
    set_id("toxin");
    set_weight(0);
    set_value(0);
call_out("poison_player",15);
}


poison_player() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
    tell_object(environment(this_object()),
      "You feel sick to your stomach from eating the rotten flesh.\n");
    if(interactive(ETO)) 
    ETO->hit_player(10 + random(10), "other|poison");
    call_out("poison_again",60);
    return 1; }
  }
}

poison_again() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
    tell_object(environment(this_object()),
      "You feel sick to your stomach from eating the rotten flesh.\n");
    if(interactive(ETO)) 
    ETO->hit_player(10 + random(10), "other|poison");
    call_out("poison_leave",60);
    return 1; }
  }
}

poison_leave() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
    tell_object(environment(this_object()),
      "The sickness seems to have subsided.\n");
    if(interactive(ETO)) 
    ETO->hit_player(10 + random(10), "other|poison");
    destruct(this_object());
    return 1; }
  }
}

drop() { return 1; }
