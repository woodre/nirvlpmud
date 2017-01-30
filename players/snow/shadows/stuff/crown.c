/*
A crown worn by /pl/s/shadows/mon/sking.c
Has charges, does damage by hit_player, unstoreable
Made saveable [5/29/04] by V!
*/
 
inherit "obj/armor";
#include "/players/snow/closed/color.h"
#define SF BLINK+BOLD+" ~ ShadowFire ~ "+OFF+OFF
 
int charge;
 
query_save_flag() { return 0; }
 
init() {
  ::init();
add_action("shadow_blast","shadowblast");
}
 
reset(arg){
  if(arg) return;
  ::reset(arg);  
  set_short(BOLD+"ShadowCrown"+OFF);
  set_name("shadowcrown");
  set_long(
"The "+BOLD+"ShadowCrown"+OFF+" is a jagged mass of dark adamantium. Shadows writhe and\n"+
"twist... dancing seemingly of their own volition. Their power is evident and most\n"+
"likely could be used to blast opponents of the wearer with "+SF+".\n");
  set_alias("crown");
  set_type("helmet");
  set_ac(2);
  set_params("magical",2,0,0);
  set_params("other|dark",0,15,0);
  set_params("other|light",0,-15,0);
/* additional params added by illarion may 2005 */
  set_weight(2);
  set_value(5000);
}
 
shadow_blast(arg){
  string gender;
  object ob;
  int dam;
  if(!worn) return 0;
  if(!arg) {
    if(this_player()->query_attack()) {
      arg = this_player()->query_attack()->query_real_name(); }
      else { write("What do you wish to blast?\n"); return 1; } }
  ob = present(arg,environment(this_player()));
  if(!ob || !living(ob)) {
    write("The "+BOLD+"ShadowCrown"+OFF+" tells you:\n\n\t shadowblast <opponent>\n\n"); return 1; }
  if(!ob->query_npc()) { write("The crown cannot be used against players.\n"); return 1; }
  dam = random(15)+15;
  arg = capitalize(arg);
  if(ob->query_hp() < dam) { write(arg+" is too weak to blast.\n"); return 1; }
  if(!living(ob)) { write(arg+" is already dead!\n"); return 1; }
  if(this_player()->query_sp() < 20) { write("you do not have enough power!\n"); return 1;}
  if(charge > 14){ write("The "+BOLD+"ShadowCrown"+OFF+" has lost it's magical abilities.\n"); return 1; } 
/* converted to actually do dark and fire damage by illarion may 2005 */
  ob->hit_player(dam/2,"other|dark",dam/2,"other|fire");
  write("You concentrate and a stream of "+SF+" blasts "+arg+"!\n");
  say(capitalize(this_player()->query_name())+
      " sends a stream of "+SF+" blasting into the "+arg+"!\n");
  call_other(this_player(),"add_spell_point",-20);
  if(!this_player()->query_attack()) this_player()->attack_object(ob);
  if(!ob->query_attack()) ob->attack_object(this_player());
  charge = charge + 1;
  return 1;
}


/* Added by Fred to keep the proper charges when stored. [5/30/04] */

locker_arg(){ return ""+charge; }
locker_init(arg){ charge = atoi(arg);  }
restore_thing(str){ restore_object(str); return 1; }
save_thing(str){ save_object(str); return 1; }
generic_object(){ return 1; }
