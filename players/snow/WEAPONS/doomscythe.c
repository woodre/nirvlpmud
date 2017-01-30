/*THIS WEAPON NOT FOR GAME PLAY*/
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("headseeker");
    set_alias("scythe");
    set_short("A black scythe");
    set_long("This is a huge scythe that glows with negative energy.\n");
    set_class(18);
    set_weight(10);
    set_value(80000);
    set_hit_func(this_object());
}
weapon_hit() {
int W;
    W = random(10);
  if(W > 6)  {
  say("The dark scythe slices into its prey.\n"+
         "A blackness spreads through the wound.\n");
  write("Your scythe corrupts the flesh of your enemies.\n");
return (20 + (random(20)));
 
   }
       return;
}
 
init() {
    if (this_player()->query_level() > 20) {
 ::init();
  add_action("doom","doom");
   }
}
 
doom() {
 
  object ob;
     ob=first_inventory(environment(this_player()));
    while (ob) {
if (living(ob)) {
call_other(ob,"heal_self",-50);
       }
ob=next_inventory(ob);
    }
say(capitalize(this_player()->query_name()) +
      "has called DOOM upon all in the room!\n"+"\n"+
      "Everyone writhes in pain.\n");
write("You have called DOOM upon the room!\n"+
          "Everyone writhes in pain.\n");
  call_other(this_player(), "add_spell_point", -100);
return 1;
}
