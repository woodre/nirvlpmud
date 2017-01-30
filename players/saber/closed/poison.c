inherit "obj/treasure";
int first, second;
int health;

reset(arg)  {
  if(arg) return;
    set_id("poison");
    set_weight(0);
    set_value(0);
call_out("poison",6);
}

poison() {
  if(!environment(this_object())) return 1;
  say("You feel the scorpion poison burning your blood!\n");
    /* changed to a dmg type */
    /* verte 6.6.01 */
   environment()->hit_player(random(15), "other|poison");

  first = first + 1;

  if(first > 1)  {

    if(random(20) > 14)  {
   endgame();
        }
        }

  if(first > 7)  {
    endgame();
        }

call_out("poison",random(20));
   return 1;
}

endgame()  {
remove_call_out("poison");
say("The poison has worn off.\n");
destruct(this_object());
  return 1;
        }

drop()  { return 1; }
get()   { return 1; }
can_put_and_get()  { return 0; }
