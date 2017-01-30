inherit "/players/sandman/paladin/obj/weapon.c";
 reset(arg) {
    ::reset();
    if (arg) return;
    set_name("blessed axe");
    set_alias("axe");
    set_short("A blessed axe");
    set_long("A well balanced combat axe forged of cold steel.\n"+
       "It feels like it belongs in your hand, and looks very sharp.\n"+
       "There is a Bardic rune upon the hilt.\n");
    set_class(16);
    set_weapon_type("axe");
    set_weight(2);
    set_value(1000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
  if(this_player()->query_guild_name() == "bard" ||
    this_player()->query_guild_name() == "paladin")  {
  if(this_player()->query_attrib("pie") > random (65))  {
  write("You hurl your axe at "+attacker->query_name()+".\n\n"+
    "The axe strikes "+attacker->query_name()+" and then returns to your hand.\n");
  say(this_player()->query_name()+" hurls "+this_player()->query_possessive()+" axe at "+attacker->query_name()+"\n\n"+
    "The axe strikes "+attacker->query_name()+" and then returns to "+this_player()->query_possessive()+" hand.\n");
return 5;
        }
        }
    return;
        }
