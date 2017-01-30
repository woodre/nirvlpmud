#include "/players/jaraxle/define.h"
inherit "obj/armor";

int SHORT;
reset(arg) {
   set_name("boots");
   set_alias("fire boots");
   set_long(
      "These boots cast an eternal flame.\n");
   
   set_ac(1);
   set_type("boots");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(100);
   set_arm_light(0);  /*  makes armor glow if it's > 0  */
}
short(){ return "Boots of the "+RED+"Eternal"+NORM+""+(worn_by?" ("+HIR+"worn"+NORM+")":""); }
id(str){ return str == "jars_fire_boots" || str == "fire" || str == "eternal boots" || str == "boots"; }

init(){
   ::init();
   
   add_action("enflame","enflame");
}

enflame(arg){
   if(!present("verte_eternal_flame",environment(this_player()))){ write("You need an Eternal Flame to do this.\n"); return 1; }
   if(TP->query_attrib("wil") < 20){ write("You do not have the willpower to stick your hands in the flames.\n"); return 1; }
   if(environment() == TP){
      if(arg == "boots"){
         call_out("flame_on", 3, TP);
         if(worn){ command("remove jars_fire_boots",TP); write("You carefully remove your boots.\n"); }
         write("You hold the boots over the Eternal Flame.\n");
         return 1;
         
      }
      notify_fail("Enflame what?\n"); return 0; }
}
flame_on(arg){
   tell_object(arg,"Flames caress the boots, covering them in a red glaze.\n");
   MOCO("/players/jaraxle/3rd/pyramid/items/e_boots2.c"), arg);
destruct(this_object());
return 1; }
