#include "/players/jareel/define.h"
inherit "obj/monster.c";
int a;
int b;
int c;
reset(arg)  {
a = 9500;
b = 3000;
c = 600;
 ::reset(arg);

  if(arg) return;

set_name("grizwald");
set_alt_name("keeper");
set_alias("shop keeper");
set_race("human");
set_short("The shop keeper Grizwald");
set_long(
  "You see a psychotic delusional old man standing\n"+
  "with his head down looking over some weapons.  His\n"+
"eyes dazzle in the light, and his grin looks a\n"+
  "little fake.\n");
MOCO("/players/jareel/weapons/griz_sword.c"),this_object());
init_command("wield sword");
set_level(20);
set_hp(500);
set_al(0);
set_wc(30);
set_ac(17);
set_heal(5,5);
set_aggressive(0);
set_dead_ob(this_object());
set_spell_mess1("Grizwald waves his hand.\n");
 set_spell_mess2("Griswald waves his hand.\n");
set_chance(18);
set_spell_dam(40+random(50));
}

init() {
    ::init();
add_action("weps","buy");
}

weps(arg) {
       if(!arg) { return 0; }
       if(arg == "1" || arg == "bastard sword") {
       if(!this_player()->add_weight(1)) {
write("You can't carry that wussy.\n");
return 1; }
       if(this_player()->query_money() < a) {
write("Your broke punk get out of here!\n");
return 1; }
  TP->add_money(-a);
write("You buy a bastard sword.\n");
say(TPN+" buys a bastard sword.\n");
MOCO("/players/jareel/weapons/wep_shop_bastard_sword.c"),TP);
return 1; }
       if(arg == "2" || arg == "battle axe") {
       if(!this_player()->add_weight(1)) {
write("You can't carry that wussy.\n");
return 1; }
       if(this_player()->query_money() < a) {
write("Your broke punk get out of here!\n");
return 1; }
TP->add_money(-a);
write("You buy a battle axe.\n");
say(TPN+" buys a battle axe.\n");
MOCO("/players/jareel/weapons/wep_shop_battle_axe.c"),TP);
return 1; }
       if(arg == "3" || arg == "spear") {
       if(!this_player()->add_weight(1)) {
write("You can't carry that wussy.\n");
return 1; }
       if(this_player()->query_money() < b) {
write("You broke punk get out of here!\n");
return 1; }
TP->add_money(-b);
write("You buy a spear.\n");
say(TPN+" buys a spear.\n");
MOCO("/players/jareel/weapons/wep_shop_spear.c"),TP);
return 1; }
       if(arg == "4" || arg == "maul") {
       if(!this_player()->add_weight(1)) {
write("You can't carry that wussy.\n");
return 1; }
       if(this_player()->query_money() < b) {
write("Your broke punk get out of here!\n");
return 1; }
TP->add_money(-b);
write("You buy a maul.\n");
say(TPN+" buys a maul.\n");
MOCO("/players/jareel/weapons/wep_shop_maul.c"),TP);
return 1; }
       if(arg == "5" || arg == "dagger") {
       if(!this_player()->add_weight(1)) {
write("You can't carry that wussy.\n");
return 1; }
       if(this_player()->query_money() < c) {
write("Your broke punk get out of here!\n");
return 1; }
TP->add_money(-c);
write("You buy a dagger.\n");
say(TPN+" buys a dagger.\n");
MOCO("/players/jareel/weapons/wep_shop_dagger.c"),TP);
return 1; }
        if(arg == "6" || arg == "short sword") {
        if(!this_player()->add_weight(1)) {
write("You can't carry that wussy.\n");
return 1; }
       if(this_player()->query_money() < c) {
write("Your broke punk get out of here!\n");
return 1; }
TP->add_money(-c);
write("You buy a short sword.\n");
say(TPN+" buys a short sword.\n");
MOCO("/players/jareel/weapons/wep_shop_short_sword.c"),TP);
return 1; }
}
