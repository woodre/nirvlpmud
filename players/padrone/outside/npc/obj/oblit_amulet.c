/*
 * oblit_amulet.c
 * Sir Obliterator's amulet
 */

inherit "obj/treasure";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_id("amulet");
  set_alias("big black iron amulet");
  set_short("A big black iron amulet");
  set_long("This is Sir Obliterator's teleport device, a big and heavy black amulet\n" +
           "made of iron, engraved with some evil-looking runes. You cannot use\n"+
           "it to teleport, since it was made specifically for Sir Obliterator.\n");
  set_weight(4);
  set_value(20);
}
