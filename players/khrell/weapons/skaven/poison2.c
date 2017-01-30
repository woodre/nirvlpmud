/* Ghetto attempt at a pk poison for the weepingblade *
 * - by Khrell (based on Eurale's Poison              */

/* 10 Minutes to start, I guess */
#define DURATION 600

inherit "obj/treasure";

void reset(status arg)  {
  if(arg) return;
  set_id("toxin");
  set_weight(0);
  set_alias("poison");
  set_value(0);
}

void poison_player(object who)
{
  if (!who || !(living(who)) || environment(this_object()) != who
    || !(interactive(who)))
    return;

  tell_object(who, "You feel burning agony surging through your being!\n");
  tell_room(environment(who), (string)who->query_name()+" contorts in agony!\n",
    ({ who }));
  who->hit_player(8 + random(5),"other|poison");
/*  while(remove_call_out("poison_player") != -1);  - not needed */
  call_out("poison_player", 30, who);

  /* Make sure the poison ends. */
  if (find_call_out("end_poison") == -1)
    call_out("end_poison", DURATION);
}

void end_poison()
{
  object ob;

  if ((ob = environment(this_object())))
    tell_object(ob, "The burning agony abates somewhat.\n");

  while(remove_call_out("poison_player") != -1);
  destruct(this_object());
}

drop() {
if(environment()->is_dieing()) destruct(this_object());
else return 1; }
get()   { return 0; }
can_put_and_get()  { return 0; }
