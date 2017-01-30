#include <ansi.h>
#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("wand of immolation");
set_type("wand");
set_alias("mar_wand");
set_short("Wand of Immolation");
set_long("A small wand created of bone, with a crystalline skull implanted in its,\n"+
         "it, center can be used to <"+HIR+"immolate"+NORM+"> a corpse. The Marketeer receieves\n"+
         "credits as they would normally.\n");
set_class(5);
set_weight(1);
set_value(27500);
}

init(){
  ::init();
add_action("wand_exchange","immolate");
}

wand_exchange(str) {
  object ob, corp;
  int creds;
if(!str) {write("What do you want to immolate?\n");  return 1; }
if(str != "corpse") {write("You can only immolate a corpse with the wand.\n");
   return 1; }
if(!present("corpse",environment(this_player()))) {
write("There must be a corpse to immolate here.\n");
return 1; }

ob = present("market_ob",this_player());
corp = present("corpse", environment(this_player()));

if(corp->id("bad_corpse")) {
write("You cannot exchange that particular corpse at the Bone Market!\n");
return 1; }

if(corp->query_corpse_level() < 11) {
  creds = (5+random(40));  }
if((corp->query_corpse_level() > 10) && (corp->query_corpse_level() < 16)) {
  creds = (20+random(40)); }
if((corp->query_corpse_level() > 15) && (corp->query_corpse_level() < 19)) {
  creds = (35+random(85)); }
if(corp->query_corpse_level() == 19) {
  creds = (50+random(85)); }
if(corp->query_corpse_level() == 20) {
  creds = (75+random(100)); }
if(corp->query_corpse_level() == 21) {
  creds = (125+random(110)); }
if(corp->query_corpse_level() == 22) {
  creds = (165+random(125)); }
if(corp->query_corpse_level() == 23) {
  creds = (200+random(130)); }
if(corp->query_corpse_level() == 24) {
  creds = (250+random(150)); }
if(corp->query_corpse_level() == 25) {
  creds = (300+random(175)); }
if(corp->query_corpse_level() == 26) {
  creds = (350+random(200)); }
if(corp->query_corpse_level() == 27) {
  creds = (400+random(250)); }
if(corp->query_corpse_level() == 28) {
  creds = (450+random(300)); }
if(corp->query_corpse_level() == 29) {
  creds = (650+random(350)); }
if(corp->query_corpse_level() == 30) {
  creds = (850+random(1000)); }
if(corp->query_corpse_level() > 30) {
  creds = (1500+random(1500)); }

write("You wave the wand, and the "+WHT+"crystalline skull"+NORM+" flares brightly.\n"+
      "     A "+HIR+"burst of flame"+NORM+" occurs, and the corpse turns to "+YEL+"dust"+NORM+".\n\n"+
      "You receive "+HIW+creds+NORM+" credits from the Marketplace.\n");
say(this_player()->query_name()+" "+HIR+"burns"+NORM+" the corpse with a thin wand.\n");
if(this_player()->query_level() < 20) {
  ob->add_total(creds);
  ob->add_current(creds);
  ob->save_me();
}
  destruct(corp);
return 1; 
}
