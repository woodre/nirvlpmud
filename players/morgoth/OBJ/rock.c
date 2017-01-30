inherit "obj/treasure";

reset(arg)
{
    if (arg) return;
    set_id("rock");
  set_short("A large rock");
set_long(
  "A very large rock.  It looks much to heavy to move but you\n"+
  "might be able to roll it if you're strong enough.\n");
    set_value(10);
    set_weight(1);
}
get()
{ return 0; }
