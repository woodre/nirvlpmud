inherit "obj/weapon";

void reset(int arg) {
  ::reset(arg);
  if(arg)
    return;
  set_name("demonsword");
  set_short("The Demon Sword");
  set_alias("sword");
  set_long(\
"This is a long, thin, blue metal sword.  There is a black demon\n" +
"inscribed into the blade.  It looks like it could be truly the most\n" +
"powerful weapon ever created.\n");
  set_class(50);
  set_weight(4);
  set_value(25000);
  call_other(this_object(),"set_save_flag",0);
  set_hit_func(this_object());
}

int weapon_hit(object attacker) {
  if(random(125) < (int)this_player()->query_attrib("int")) {
    say("The demon comes off the sword and smites his opponent!\n");
    write("The demon comes off of your sword and smites your opponent!\n");
    return 5;
  }
  return 0;
}
