inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
    set_id("bonepoison");
    set_weight(0);
    set_value(0);
call_out("poison_player",6);
}

poison_player() {
  tell_object(environment(this_object()),
    "You feel a burning sensation coursing through your veins...\n");
  call_other(environment(this_object()),"heal_self",-(14 + random(10)));

  call_out("poison_player",10);
   return 1;
}

drop()  { return 1; }
get()   { return 1; }
can_put_and_get()  { return 0; }
