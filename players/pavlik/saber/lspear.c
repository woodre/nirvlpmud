#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
     set_name("blessed spear");
     set_alias("spear");
    set_type("spear");         /* set type added by Pavlik */
     set_short("A blessed spear");
     set_long("A spear whose blade was forged from cold steel.\n"+
        "It has been blessed by the priests of Larn to battle evil.\n");
    set_class(17);
    set_weight(2);
    set_value(1000);
    set_save_flag(0);
    set_hit_func(this_object());
}
weapon_hit(attacker){
if(call_other(this_player(), "query_attrib", "pie") > random (60))
 {
  if(attacker->query_alignment() < 0)  {

tell_room(environment(this_player()),
"The blessed spear glows with a holy silver light.\n");

  return 8;
        }
    }
    return;
}
