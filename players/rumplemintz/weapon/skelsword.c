inherit "obj/weapon";

void reset(int arg) {
  ::reset(arg);
  if(arg)
    return;
  set_name("skelsword");
  set_short("The Skeleton Sword");
  set_alias("sword");
  set_long(\
"This is the trusted sword of the Skull Leaders.\n" +
"This brilliant piece of work looks like it'll slice clean through anything.\n");
  set_class(18);
  set_weight(3);
  set_value(1000);
  call_other(this_object(),"set_save_flag",0);
  set_hit_fun(this_object());
}

int weapon_hit(object attacker) {
  if(random(50) < (int)this_player()->query_attrib("int")) {
    say("The Skeleton sword crushes it's foe!!\n");
    write(\
"The Sword takes control of you and forces you to hit DEEP, chopping a hunk off!\n");
    return 9;
  }
}
