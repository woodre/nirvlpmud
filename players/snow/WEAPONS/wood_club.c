/*
A wooden club with small return according to strength.
*/
 
#define TP this_player()
#define TPS call_other(TP,"query_attrib","str")
#define MEAT TP->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define TPN capitalize(TP->query_name())
#define GEN TP->query_possessive()
 
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("wooden club");
    set_alias("club");
    set_short("A studded wooden club");
    set_long(
"This is a piece of wood about 3 feet long, with metal studs and a worked\n"+
"leather grip. You should be able to bash things with it.\n");
    set_class(12);
    set_weight(3);
    set_value(500);
    set_hit_func(this_object());
}
weapon_hit() {
int W;
    W = random(30);
  if(W < TPS)  {
  say(TPN+" bashes "+MEATN+" with "+GEN+" club!\n");
  write("You bash "+MEATN+" with your club!\n");
return TPS/3;
   }
       return;
}
