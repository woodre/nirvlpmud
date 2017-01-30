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
    call_out("poison_player",60);
    return 1; }
  }
}
