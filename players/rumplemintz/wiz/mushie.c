/* ================================================== */
/* This is a weapon testing monster made by Sweetness */
/* It will give you the damage that you do in a round */
/* and will not die. Just look at mushie to see the   */
/* commands to use with him. If you like it let me    */
/* know.                                              */
/* ================================================== */

inherit "obj/monster";

int mushie;

void reset(status arg){
   if(arg) return;
   ::reset(arg);
   set_name("mushroom");
   set_race("mushroom");
   set_alias("mushie");
   set_short("Mushie the Mushroom");
   set_long("This is a mushroom to test your weapons on.\n"+
      "Type 'mushie off' to turn it off.\n"+
      "Type 'mushie damage' to turn it on.\n");
   set_level(1);
   set_hp(1000);
   set_al(0);
   set_wc(0);
   set_ac(0);
   mushie = 0;
   enable_commands();
   set_heart_beat(1);
   set_wander(1);
   set_wander_interval(1);
   set_wander_realm("/players/angel/area/stargate/room");
}

void init(){
   ::init();
   add_action("mushie", "mushie");
}

status mushie(string str){
   if(!str || (str !="off" && str !="damage")){
      write("Usage: mushie <damage/off>\n");
      return 1;
   }
   if(str == "off"){
      mushie = 0;
      return 1;
   }
   if(str == "damage"){
      mushie = 1;
      return 1;
   }
}

heart_beat(){
   int hps;
   ::heart_beat();
   hps=this_object()->query_hp();
   if(mushie == 1)
      say("You just did "+(1000 - hps)+" points of damage.\n");
   this_object()->heal_self(1000);
}
