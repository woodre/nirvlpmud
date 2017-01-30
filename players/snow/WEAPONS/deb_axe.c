/*
There were so many good-oriented weapons out there that I decided to
go the other way. Hence the Axe of Debauchery.
*/
 
#define TP this_player()
#define TPA TP->query_alignment()
#define TPW call_other(TP,"query_attrib","wil")
#define MEAT TP->query_attack()
#define MEATA MEAT->query_alignment()
#define MEATN capitalize(MEAT->query_name())
#define TPN capitalize(TP->query_name())
 
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("battleaxe of debauchery");
    set_alias("battleaxe");
    set_short("The BattleAxe of Debauchery");
    set_long(
"Evil and wickedness seep out from this battleaxe in an almost tangible\n"+
"aura. The huge weapon longs for pure blood.\n");
    set_class(19);
    set_weight(5);
    set_value(1000);
    set_hit_func(this_object());
set_save_flag(0);
}
weapon_hit() {
int W,AL;
    W = random(TPW);
    AL = TPA/100;
      if(AL > 8) AL = 8;
  if(W > 10)  {
  say(TPN+"'s BattleAxe surges in bloody rage!\n");
  write("Your BattleAxe surges in bloody rage!\n");
     if(MEATA > 0) {
call_other(MEAT,"heal_self",-4);
     }
return -(AL);
   }
       return;
}
