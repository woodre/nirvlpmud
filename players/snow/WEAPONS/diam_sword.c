#define INT call_other(this_player(),"query_attrib","int")
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("diamond sword");
    set_alias("sword");
    set_short("A clear sword");
    set_long(
"As you look more closely at this blade, you see that it is made of pure\n"+
"diamond- magically forged you assume. Words burn inside the blade:\n"+
"\n"+
"                  >>>WIT BRINGS MIGHT<<<\n");
    set_class(18);
    set_weight(1);
    set_value(15);
    set_hit_func(this_object());
}
weapon_hit() {
int W;
    W = random(100);
  if(W > 35) {
  say("The crystal blade slices into its foe.\n");
  write("Your diamond blade slices through your foe.\n" +
           "Your enemy screams in pain as you withdraw your blade.\n");
return (INT/2);
   }
  if(W == 0) {
    tell_room(environment(this_player()),
capitalize(this_player()->query_name())+"'s sword shatters on "+
this_player()->query_attack()->query_name()+"!\n");
    write("Your sword just SHATTERED!!\n");
call_other(this_player()->query_attack(),"hit_player",
           INT);
command("unwield sword", this_player());
destruct(this_object());
  }
       return;
}
