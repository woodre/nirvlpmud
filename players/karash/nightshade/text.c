/*This is a weapon testing monster made by Sweetness*/
/*It will give you the damage that you do in a round*/
/*and will not die. Just look at mushie to see the  */
/*commands to use with him. If you like it let me know*/
inherit "obj/monster";
int mushie;
object room;
init(){
   ::init();
   add_action("mushie","mushie");
}
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("mushroom");
   set_race("mushroom");
   set_alias("mushie");
   set_short("Mushie the Mushroom");
   set_long("This is a mushroom to test your weapons on.\n"+
      "Type 'mushie off' to turn it off.\n"+
      "Type 'mushie damage' to turn it on.\n");
   set_level(20);
   set_hp(1000);
   set_al(0);
   set_wc(0);
   set_ac(0);
   enable_commands();
   set_heart_beat(1);
}
mushie(arg){
   mushie = 0;
   if(!arg){write("Type 'mushie damage' to turn me on.\n");
      write("Type 'mushie off' to turn me off.\n");
      return 1;}
   if(arg == "off"){mushie = 0; return 1;}
   if(arg != "damage"){write("Type 'mushie damage' to turn me on.\n");
      write("Type 'mushie off' to turn me off.\n");
      return 1;}
   mushie=1;
   return 1;
}
heart_beat(){
	int hps, diff;
   ::heart_beat();
   hps=this_object()->query_hp();
diff=hps-this_object()->query_hp();
   room=environment(this_object());
   if(mushie == 1)
	say("You just did "+diff+" damage.\n");
}
