#include "/players/jareel/define.h"
inherit "obj/monster.c";
int a;
int b;
int c;
int d;
int e;
int f;
reset(arg)  {
a = 2400;
b = 2400;
c = 1600;
d = 1600;
e = 1200;
f = 1200;
 ::reset(arg);
  if(arg) return;

set_name("azzared");
set_alias("shop keeper");
set_race("human");
set_alt_name("keeper");
set_short("The shop keeper Azzared");
set_long(
  "You see a psychotic delusional old man standing\n"+
  "with his head down looking over some berries.  His teeth\n"+
  "dazzle in the light, and his grin looks a little fake.\n");

set_level(10);
set_hp(150);
set_al(0);
set_wc(14);
set_ac(8);
set_heal(5,5);
set_aggressive(0);
set_dead_ob(this_object());
add_money(400);
}
init() { 
    ::init(); 
add_action("heals","buy");
}
heals(arg) {
if(!arg) { return 0; }
if(arg == "1" || arg == "potent berries") {
 if(!this_player()->add_weight(1)) {
    write("You can't carry that wussy.\n");
return 1; }
if(this_player()->query_money() < a) {
write("Your broke punk get out of here!\n");
return 1; }
TP->add_money(-a);
write("Azzared hands you some berries.\n");
say(TPN+" buys some berries from Azzared.\n");
MOCO("/players/jareel/heals/highden_berries.c"),TP);
return 1; }
if(arg == "2" || arg == "potent potion") {
 if(!this_player()->add_weight(1)) {
    write("You can't carry that wussy.\n");
return 1; }
if(this_player()->query_money() < b) {
write("Your broke punk get out of here!\n");
 return 1; }
TP->add_money(-b);
write("Azzared hands you a potion.\n");
say(TPN+" buys a potion from Azzared.\n");
MOCO("/players/jareel/heals/highden_potion.c"),TP);
return 1; }
if(arg == "3" || arg == "berries") {
 if(!this_player()->add_weight(1)) {
    write("You can't carry that wussy.\n");
return 1; }
if(this_player()->query_money() < c) {
write("You broke punk get out of here!\n");
return 1; }
TP->add_money(-c); 
write("Azzared hands you some berries.\n");
say(TPN+" buys some berries from Azzared.\n");
MOCO("/players/jareel/heals/regular_berries.c"),TP);
return 1; }
if(arg == "4" || arg == "potion") {
 if(!this_player()->add_weight(1)) {
    write("You can't carry that wussy.\n");
return 1; }
if(this_player()->query_money() < d) {
write("Your broke punk get out of here!\n");
return 1; }
TP->add_money(-d);
write("Azzard hands you a potion.\n");
say(TPN+" buys a potion from Azzared.\n");
MOCO("/players/jareel/heals/regular_potion.c"),TP);
return 1; }
if(arg == "5" || arg == "hybrid berries") {
 if(!this_player()->add_weight(1)) {
    write("You can't carry that wussy.\n");
return 1; }
if(this_player()->query_money() < e) {
write("Your broke punk get out of here!\n");
return 1; }
TP->add_money(-e);
write("Azzared hands you some berries.\n");
say(TPN+" buys some berries from Azzared.\n");
MOCO("/players/jareel/heals/cheep_berries.c"),TP);
return 1; }
if(arg == "6" || arg == "diluted potion") {
 if(!this_player()->add_weight(1)) {
    write("You can't carry that wussy.\n");
return 1; }
if(this_player()->query_money() < f) {
write("Your broke punk get out of here!\n");
return 1; }
TP->add_money(-f);
write("Azzared hands you a potion.\n");
say(TPN+" buys a potion from Azzared.\n");
MOCO("/players/jareel/heals/cheep_potion.c"),TP);
return 1; }
}
