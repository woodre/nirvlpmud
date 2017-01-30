/*
 *  Regeneration object for Bards of Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

inherit "obj/treasure";

int FIRST, SECOND, HEALTH;


reset(arg)  {
  if(arg) return;
    set_id("regen");
    call_out("regen",2);
        }

regen() {

 if(!(environment(this_object()))->query_interactive())  { endgame(); }
 
 FIRST = environment(this_object())->query_hp();
 SECOND = environment(this_object())->query_mhp();
 HEALTH = FIRST * 100 / SECOND;

  if(HEALTH < 100)  {
   call_other(environment(this_object()), "add_hit_point", 2);
        }
  if(HEALTH > 99)  {
   endgame();
        }
call_out("regen",2);
   return 1;
        }

endgame()  {
  remove_call_out("regen");
  say("\nYou stop regenerating.\n\n");
  destruct(this_object());
  return 1;
        }

drop()  { return 1; }
get()   { return 1; }
can_put_and_get()  { return 0; }
