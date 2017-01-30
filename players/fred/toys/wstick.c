#include "/players/fred/ansi.h"
inherit "/obj/weapon.c";
#define atn attacker->query_name()
#define tpn this_player()->query_name()

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("stick");
  set_short(BOLD+HIY+"Whooping"+NORM+BOLD+" Stick"+NORM);
  set_long(
 "  A long thick piece of wood used to punish the patients\n"+
 "that got out of hand. It has been nicknamed the Whooping\n"+
 "Stick for obvious reasons.\n" );
  set_type("polearm");
  set_class(18);
  set_weight(3);
  set_value(1600);
  set_hit_func(this_object());
  }
  weapon_hit(object attacker){
  int z;
  z = random(50);
   if(z < 5){
    write("\n"+
          "      You swing the "+GRN+"Stick"+NORM+" through the air hitting\n"+
          "              "+HIY+atn+NORM+" solidly on the chest!\n\n");
    say("\n"+tpn+" hammers "+atn+" with the "+GRN+"Stick"+NORM+".\n");
    return 6; }
  }

init(){
  ::init();
   add_action("grumble","whoop");
  }

grumble(string str){
  object nut;
  if(!str){ write("Whoop who?\n"); return 1; }
  if(str){ 
    nut = present(str, environment(this_player())); }
  if(!nut){
    tell_object(this_player(),
      "You do not see "+capitalize(nut->query_name())+" here.\n"); }
    write("You swing the "+GRN+"Stick"+NORM+" around quickly and "+BOLD+RED+"WHOOP "+NORM+capitalize(nut->query_name())+"'s ass!\n"); 
    say(""+tpn+" swings the "+GRN+"Stick"+NORM+" around quickly and "+BOLD+RED+"WHOOPS "+NORM+capitalize(nut->query_name())+"'s ass!\n");
    command("pout", nut);
    command("worship fred", nut);
  return 1; }
