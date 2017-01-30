inherit "/obj/weapon";
#include <ansi.h>

/******************************************************************************
 * Program: frenzy_wand_new.c
 * Path: /players/nightshade/misc/
 * Type: Weapon/Treasure (Wand)
 * Created: September 2014 by Karash
 *
 * Purpose: A new loot item to be found in Nightshade's realm.  This wand acts in the
 *          same manner as the BCM freeze spell (prevents movement), but only has 5
 *          charges and gives the target NPC the ability to do extra physical damage
 *          equal to 40% of base WC while under this spell.
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


int num;

reset(arg){
  ::reset(arg);
  if (arg) return;
num = 5;

set_name("wand");
set_alias("frenzy wand");
set_alt_name("wand of frenzy");
set_short(HIM+"Wand of Frenzy"+NORM);
set_long("This long, smooth, shiny platinum wand has a single runic picture carved into\n\
it.  Some say the carving can be translated as madness, which can be used\n\
to '"+MAG+"enrage"+NORM+"' a '"+MAG+"target"+NORM+"' causing them to fight with an extra frenzy and no\n\
desire to flee.\n");
set_type("club");
set_class(5);
set_weight(1);
set_value(num * 250);
set_save_flag();
}

init() {
  ::init();
  add_action("Enrage","enrage");
}



Enrage(str) {

object ob, frzy;
int x;


 x = (60 - (LVL+(XLVL/4)));
  if(USER->query_ghost()){
    write("You can't use this item in your condition.\n"); return 1;}
  if(INT < 25) {
    write("You don't have the intelligence needed to use this wand.\n"); return 1;}
  if(USER->query_sp() < x) {
    write("You don't have enough energy to use this wand.\n"); return 1;}      
  if(!str && !TP->query_attack()){ write("Enrage what?\n"); return 1; }
  if(!str) ob = TP->query_attack();
  if(!ob) ob = present(str, ENV(TP));
  if(!ob || !present(ob, ENV(TP))){
    write("You don't see "+str+" here.\n"); return 1; }
  if(!living(ob)){
    write("Your words of frenzy have no effect on that!\n"); return 1;}
  if(ob->is_player()){
    write("Your words of frenzy have no effect on players.\n"); return 1;}
  if(ob->frenzy()){
    write(ob->query_name()+" is already frenzied.\n"); return 1; }

  /* PATH UPDATED */
  frzy = CO("/players/nightshade/misc/frenzy_obj_new.c");   
  frzy->set_time(LVL);
  frzy->do_shadow(ob);
  write(ob->query_name()+RED+" becomes enraged"+NORM+" and is able to fight with a "+HIM+"frenzy"+NORM+".\n");
  say(ob->query_name()+RED+" becomes enraged"+NORM+" and is able to fight with a "+HIM+"frenzy"+NORM+".\n");
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
  tell_object(this_player(), MAG+"< "+num+" charges remaining >\n"+NORM);
}

