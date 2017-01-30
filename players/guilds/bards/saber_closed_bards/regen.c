inherit "obj/treasure";
int first, second;
int health;

reset(arg)  {
  if(arg) return;
    set_id("regen");
    set_weight(0);
    set_value(0);
call_out("regen",2);
}

regen() {
 first = environment(this_object())->query_hp();
 second = environment(this_object())->query_mhp();
 health = first * 100 / second;
  if(health < 100)  {
   call_other(environment(this_object()), "add_hit_point", 2);
        }
  if(health > 99)  {
   endgame();
        }
call_out("regen",2);
   return 1;
}

endgame()  {
remove_call_out("regen");
say("You stop regenerating.\n");
destruct(this_object());
  return 1;
        }

drop()  { return 1; }
get()   { return 1; }
can_put_and_get()  { return 0; }
