#define ETO environment(this_object())
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
    set_id("toxin");
    set_weight(0);
    set_alias("poison");
    set_value(0);
/*
ld doesn't like this in preloads...
-Bp
call_out("poison_player",15);
*/
}

init() {
  while(remove_call_out("poison_player") != -1);
  call_out("poison_player",15);
}
query_auto_load() { return "/players/eurale/Keep/OBJ/poison.c:"; }

poison_player() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
    tell_object(environment(this_object()),
      "You feel a burning sensation coursing through your veins...\n");
    if(interactive(ETO))
    ETO->hit_player(20 + random(12));
    call_out("poison_player",30);
    return 1; }
  }
}

drop() {
if(environment()->is_dieing()) destruct(this_object());
else return 1; }
get()   { return 0; }
can_put_and_get()  { return 0; }
