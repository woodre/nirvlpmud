inherit "/obj/weapon";
#include <ansi.h>

/******************************************************************************
 * Program: courage_wand_new.c
 * Path: /players/nightshade/misc/
 * Type: Weapon/Treasure (Wand)
 * Created: September 2014 by Karash
 *
 * Purpose: A new loot item to be found in Nightshade's realm.  This wand acts in the
 *          same manner as the BCM freeze spell (prevents movement), but only has 5
 *          charges and heals the target 20% or 1000hp, whichever is less.  
 *          The spell cannot be cast on players, can only be cast if target NPC is less
 *          than 80% health and heals target NPC when cast.
 *
 * History:
 *          
 ******************************************************************************/

#define TP this_player()
#define TPN TP->query_name()
#define TO this_object() 
#define MO move_object
#define CO clone_object
#define ENV environment
#define USER ENV(TO)
#define LVL USER->query_level()
#define XLVL USER->query_extra_level()
#define INT USER->query_attrib("int")

#define HEALMAX 1000



int num;

reset(arg){
  ::reset(arg);
  if (arg) return;
num = 5;

set_name("wand");
set_alias("courage wand");
set_alt_name("wand of courage");
set_short(HIB+"Wand of Courage"+NORM); 
set_long("This long, smooth, shiny platinum wand has a single runic picture carved into\n\
it.  Some say the carving has the meaning of courage, which can be used to\n\
'"+HIB+"encourage"+NORM+"' a '"+HIB+"target"+NORM+"' to boost their health and remove the desire to flee.\n");
set_type("club");
set_class(5);
set_weight(1);
set_value(num * 250);
set_save_flag();
}

init() {
  ::init();
  add_action("Encourage","encourage");
}


Encourage(str) {

object ob, brv;
int x;


 x = (60 - (LVL+(XLVL/4)));
  if(USER->query_ghost()){
    write("You can't cast a spell in your condition.\n"); return 1;}
  if(INT < 25) {
    write("You don't have the intelligence needed to use this wand.\n"); return 1;}
  if(USER->query_sp() < x) {
    write("You don't have enough energy to use this wand.\n"); return 1;}      
  if(!str && !TP->query_attack()){ write("Encourage what?\n"); return 1; }
  if(!str) ob = TP->query_attack();
  if(!ob) ob = present(str, ENV(TP));
  if(!ob || !present(ob, ENV(TP))){
    write("You don't see "+str+" here.\n"); return 1; }
  if(!living(ob)){
    write("Your words of encouragement have no effect on that!\n"); return 1;}
  if(ob->is_player()){
    write("Your words of encouragement have no effect on players.\n"); return 1;}
  if(ob->brave()){
    write(ob->query_name()+" is already brave enough.\n"); return 1; }

  /** To use this wand, target NPC is healed 20% or HEALMAX, whichever is lesser **/
  if((ob->query_hit_point() * 10 / ob->query_mhp()) >= 8) {
    write(ob->query_name()+" is currently too strong to be influenced by you.\n"); return 1; }
  if( (ob->query_mhp() / 5) < HEALMAX ) {
	ob->add_hit_point(ob->query_mhp() / 5); }
  else { ob->add_hit_point(HEALMAX); }
  
  /* PATH UPDATED */
  brv = CO("/players/nightshade/misc/courage_obj_new.c");   
  brv->set_time(LVL);
  brv->do_shadow(ob);
  write(ob->query_name()+MAG+" grows stronger"+NORM+" while gaining an "+HIC+"overwhelming"+NORM+" sense of "+HIC+"bravery"+NORM+".\n");
  say(ob->query_name()+MAG+" grows stronger"+NORM+" while gaining an "+HIC+"overwhelming"+NORM+" sense of "+HIC+"bravery"+NORM+".\n");
  USER->add_spell_point(-x);  
  
  num -= 1;
  TO->set_value(num * 250);
  
  if(num == 0) 
  {
    tell_room(environment(TP),
      "\n\The wand "+GRY+"TURNS GREY"+NORM+" and "+GRY+"MELTS"+NORM+" before your eyes...\n");
    destruct(TO);
    return 1; 
  }


  return 1; 
  
}


long() {
  ::long();
  tell_object(this_player(), CYAN+"< "+num+" charges remaining >\n"+NORM);
}

