inherit "obj/weapon";
 reset(arg) {
  ::reset(arg);
    if (arg) return;
    set_name("crystal dagger");
    set_alias("dagger");
set_type("dagger");
    set_short("A crystal dagger");
    set_long("An ivory white dagger of gleaming crystal.\n"+
       "It has the weight of a feather, and looks very sharp.\n"+
       "There is a Bardic rune upon the hilt.\n");
    set_class(12);
    set_weight(2);
    set_value(100);
    set_hit_func(this_object());
}
weapon_hit(attacker){
  if(this_player()->query_guild_name() == "bard" ||
    this_player()->query_guild_name() == "paladin")  {
  if(this_player()->query_attrib("mag") > random (50))  {
  say("The crystal dagger pulses brightly.\n");
write("The crystal dagger pulses brightly.\n");
return 3;
        }
        }
    return;
        }
