inherit "obj/treasure";
int first;

reset(arg)  {
  if(arg) return;
first = 0;
    set_id("poison");
    set_weight(0);
    set_value(0);
call_out("poison_player",6);
}

poison_player() {
if(environment(this_object())) {
  tell_object(environment(this_object()),
    "You feel a burning sensation coursing through your veins...\n");
  call_other(environment(this_object()),"hit_player",(20 + random(15)));

  first = first + 1;
  if(first > 50) { endgame(); }
  call_out("poison_player",30);
  return 1; }
}

endgame()  {
remove_call_out("poison_player");
tell_object(environment(this_object()),"The poison has worn off.\n");
destruct(this_object());
  return 1;
        }

drop() {
if(environment()->query_ghost()) destruct(this_object());
else return 1; }
get()   { return 0; }
can_put_and_get()  { return 0; }
