#include "/players/mythos/closed/ansi.h"
#define tp this_player()
#define tpn tp->query_real_name()

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_alias("seller");
  set_long("A small man wearing black clothing.  He hides in\n"+
           "the shadows- occasionally muttering to himself.\n"+
           "He sees you looking at him and whispers to you:\n"+
           "   'You want some healing?  Want some drugs?\n"+
           "    Check out the <type> of drugs I have and\n"+
           "    <choose> some.'\n");
  set_weight(10000);
  set_value(0);
}
get() { return 0;}

init() {
  add_action("type","type");
  add_action("choose","choose");
  call_out("caller",50);
}

caller() {
  if(random(30) == 0) {
    tell_room(environment(this_object()),
    "You see a 'seller' in the shadows.....\n"); }
  call_out("caller",50+random(40));
}

type() {
  write("Drugs being sold:\n\n"+
        "combat               10000\n"+
        "acid (LSD)           10000\n"+
        "new_heroin (heroin)   8000\n"+
        "cocaine               5000\n"+
        "XTC                   3000\n"+
        "speed                 2000\n"+
        "weed                  700\n"+
        "barbs  <anti-intox>   2000\n");
return 1;}

choose(str) {
string name;
int value;
  if(!str) { write("What drug do you choose?\n"); return 1;}
  if(str != "combat" && str != "cocaine" && str != "barbs" && str != "xtc" &&
     str != "lsd" && str != "heroin" && str != "LSD" &&
     str != "speed" && str != "XTC" && str != "acid" && str != "new_heroin" &&
     str != "weed") { write("That is not available.\n"); return 1;}
  name = str;
  if(name == "xtc") name = "XTC";
  if(name == "heroin") name == "new_heroin";
  if(name == "LSD" || name == "lsd") name = "acid";
  if(name == "combat") value = 10000;
  if(name == "cocaine") value = 5000;
  if(name == "speed") value = 2000;
  if(name == "XTC") value = 3000; 
  if(name == "acid") value = 10000; 
  if(name == "new_heroin") value = 8000; 
  if(name == "barbs") value = 2000;
  if(name == "weed") value = 700;
  if(tp->query_money() < value) { write("You do not have enough!\n"); return 1;}
  move_object(clone_object("/players/mythos/mmisc/drugs/"+name+"/"+name+".c"),tp);
  tp->add_money(-value);
  write("You haven choosen to purchase "+name+".\n");
  say(capitalize(tpn)+" buys "+name+".\n");
return 1;}
