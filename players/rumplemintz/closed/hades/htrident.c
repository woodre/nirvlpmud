inherit "obj/weapon";
string owner;

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("Hades's Trident");
   set_alt_name("trident");
   set_alias("trident");
   set_short("Hades's trident");
   set_long("This is the mighty trident of Hades lord of the underworld.\n");
   set_class(18);
   set_hit_func(this_object());
   set_weight(3);
   set_value(100000);
   set_save_flag(0);
   owner=this_player()->query_real_name();
}
weapon_hit(attacker){
   if(random(30) > 20){
      write("The trident screams through the air.\n");
      say(capitalize(this_player()->query_name())+"'s trident screams through the air.\n",this_player());
      return(8);
   }
}
id(str) {return str == "hades_ob" || str == "trident";}
