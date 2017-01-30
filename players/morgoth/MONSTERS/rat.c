inherit "obj/monster";

reset(arg)
{
  if (arg) return;
  ::reset(arg);
  set_name("rat");
  set_short("A castle rat");
  set_long("One of the rats that inhabit Morgoth's castle\n"+
           "They are harmless if left alone but very viscious\n"+
           "when attacked.  They have very sharp teeth and claws.\n");
  set_level(10);
  set_ac(8);
  set_wc(14);
  set_whimpy();
}
