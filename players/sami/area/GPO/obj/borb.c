#include "/players/jaraxle/define.h"
#define USER environment(this_object())
#define ATT USER->query_attack()
inherit "obj/armor";
int change_color;

set_type(string str){
   type = str;
}


object ob;
int tmp, num;


reset(arg) {
   ::reset(arg);
   
   set_name("orb of blood");
   set_alias("blood orb");
   set_long("A small, rotting, slime covered orb.\n"+
      HIW+"'"+NORM+HIR+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+HIR+"deactivate"+HIW+"'"+NORM+" the orb.\n");
   set_ac(0);
   set_type("orb");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(0);
   set_value(4000);
set_params("other|evil", 2, 30, "do_laser_special");
   /* 2 ac, 30% resistance to other|laser damage, */
}

short(){
   
   return "Orb of "+RED+"Blood"+NORM+""+(worn_by?" (floating nearby)":""); }

id(str) {
   return str == "blood orb" || str == "orb" || str == "orb of blood";
}

query_worn() { return worn; }
query_type() { return type; }
query_save_flag(){ return 0; }

init(){
   ::init();
   
   add_action("wear_it","wear");
   add_action("wear_it","remove");
   add_action("activate","activate");
   add_action("deactivate","deactivate");
}

wear_it(str){
   if(id(str)){
      write("You can "+HIW+"'"+NORM+HIR+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+HIR+"deactivate"+HIW+"'"+NORM+" the orb to use this power.\n");
      return 1; }
}

activate(str){
   if(environment()->is_kid()){
      object room;
      tell_room(room, "The orb refuses the childs will.\n");
      return 1; }
   
   if(id(str)){
      if(!worn){
         write("The orb begins to slowly float to your side, pulsing as it floats closer.\n");
         present(str, this_player())->wear(str);
         return 1; }
      return 0; }
}

deactivate(str){
   if(id(str)){
      if(worn){
         write("The orb slowly sinks back into your hand.\n");
         present(str, this_player())->remove(str);
         return 1; }
      return 0; }
}

do_special(owner) {
   int i, cast;
   
   switch(random(5)){
      case 0: cast = ""+HIR+"ray of darkness"+NORM+"";
      break;
      case 1: cast = ""+HIM+"ray of death"+NORM+"";
      break;
      case 2: cast = ""+HIR+"ball of concentrated evil"+NORM+"";
      break;
      case 3: cast = ""+HIM+"beam of darkness"+NORM+"";
      break;
      case 4: cast = ""+HIR+"humming ball pure evil"+NORM+"";
      break;
   }
   
   i = random(8);
   if(!ATT) return;
   if(i==1){
      if(ATT->is_npc())
         ATT->heal_self(-(1+random(3)));
      else ATT->hit_player(random(2)+1, "other|evil");
      tell_room(environment(USER),
         capitalize(USER->query_name())+" zaps "+capitalize(ATT->query_name())+"with a "+cast+".\n", ({ USER }));
      tell_object(USER, "You zap "+capitalize(ATT->query_name())+" with a "+cast+".\n");
      return 0;}
   return 0; }

do_laser_special(object owner)
{
   if(!random(8))
      {
      tell_object(owner, "\
         The Orb of Laser glows a translucent blue as it absorbs some of the\n"+

         "\tlaser damage.\n");
      return 1504;
      /* 
      15% [15] resistance boost
      4  [04] ac boost 
      */
   }
}
/*
object gob;
     if(this_player()->query_guild_name() == "bloodfist") {
       if(gob = present("scar", this_player())) {
	     /players/fred/closed/bloodfist/daemon/honor_daemon"->query_honor("sorrow")
		   gob->rm_honor( "sorrow", 5 )
         if( random(3) ) gob->rm_honor( "sorrow", 5 );
         write("Your weapon feeds on your"+RED+"Bloodhonor"+NORM+" \n");
		 write("You feel stronger as "+RED+"Blood"+NORM+" races through your veins.\n");
         return 26;
		 }
		 }}
		 */