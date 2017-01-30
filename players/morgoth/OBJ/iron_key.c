inherit "obj/treasure";

reset(arg)
{
    if (arg) return;
    set_id("key");
  set_alias("iron key");
    set_short("A small iron key");
    set_value(10);
    set_weight(1);
}
