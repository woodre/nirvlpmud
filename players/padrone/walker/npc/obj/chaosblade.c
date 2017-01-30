/*
 * chaosblade.c
 */

inherit "obj/weapon";

void
reset(status arg)
{
  weapon::reset(arg);
  if (arg)
    return;
  set_name("chaosblade");
  set_alias("chaosblade of death");
  set_alt_name("sword");
  set_short("A chaosblade of death");
  set_long("This is a slim, but very heavy, sword that seems to glow with\n"+
           "soft darkness. It looks strangely unnatural, and it would\n"+
           "probably be a bad move even to try to wield this weapon.\n"+
           "Maybe someone else wants it?\n");
  set_class(30);
  set_weight(7);
  set_value(2000);
  set_wield_func(this_object());
}

status
wield(object obj)
{
  if (!this_player())
    return 1;
  if ((string)this_player()->query_name() == "Chaosdemon")
    return 1;
  write("The sword twists away from your grip, hovers in the air and looks at you.\n");
  write("Then it laughs contemptuosly and disappears in a blinding flash.\n");
  write("You think you can hear the words 'Puny mortal!' from somewhere far away...\n");
  move_object(obj, "/players/padrone/store");
  say(this_player()->query_name() +
      " fails spectacularly at wielding the chaosblade.\n");
  return 0;
}
