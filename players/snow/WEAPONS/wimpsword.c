/*
A wimpy sword that will store... it has a kick though.
*/
 
#define MEAT this_player()->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define TPN capitalize(this_player()->query_name())
 
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("wimpsword");
    set_alias("sword");
    set_short("The WimpSword");
    set_long(
"A short sword for those with few choices in weapons...\n");
    set_class(10);
    set_weight(1);
    set_value(200);
    set_hit_func(this_object());
}
weapon_hit() {
int W;
    W = random(30);
wimp_hit();
  if(W < 10)  {
  say(TPN+
" swings wimpily at "+MEATN+" in a feeble display of skill!\n");
  write(
"You swing wimpily at "+MEATN+" in a feeble display of skill!\n");
return 2;
   }
       return;
}
 
wimp_hit() {
  if(!MEAT->query_npc()) return 1;
else
call_other(MEAT,"heal_self",-(random(10)));
return 1;
}
