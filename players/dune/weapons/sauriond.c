 /* WHOA!
  * Before you start tearing this weapon apart because it returns 7
  * and has a special hit, realize that it totally drains the user
  * of all sps during combat.
  */
 inherit "obj/weapon.c";

 id(str)  {
  return str == "Sauriond" || str == "sword" || str == "sauriond";
 }

 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("sauriond");
    set_alias("sauriond");
    set_short("Sauriond, the long sword");
    set_long("Sauriond is an ancient rune-sword that was\n"+
           "lost long ago.  It's material is of black stone.\n"+
           "The sword is quite heavy, and you strain to lift it.\n"+
           "Sauriond has a laced silver and gold hilt, with\n"+
           "a gleaming runed blade.\n");
    set_read("This blade was forged by Dune.\n");
    set_class(17);
    set_weight(8);
    set_value(40000);
    set_hit_func(this_object());
}

weapon_hit(attacker){
 int num;
 num = this_player()->query_spell_point();
 if (num <= 5) {
   say("THRASH\n");
   write("THRASH\n");
   say("Sauriond wants revenge and sucks its foe dry.\n");
   write("Sauriond wants revenge and sucks its foe dry.\n");
   return 5;}
 call_other(this_player(),"add_spell_point", -10);
 say("CLANG!!!!!\n");
 write("CLANG!!!!!\n");
 say("Sauriond trembles violently with soul power.\n");
 write("Sauriond trembles violently with soul power.\n");
 write("You feel empty inside.\n");
 return 5;
}

