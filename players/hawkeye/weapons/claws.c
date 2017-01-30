inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("claws");
   set_alt_name("claw");
   set_alias("claws");
   set_short("Claws of light and dark");
   set_long("These are a pair of gauntlets. The right glove is lined\nwith small claws that glow with a fierce light, while\nthe left is armed with claws which radiate a pure\ndarkness. Use these claws well.\n");
   set_class(18);
   set_weight(2);
   set_value(10000);
   set_hit_func(this_object());
}

query_save_flag() { return 1;}

weapon_hit(attacker){
   string what,how;
   int align,dam;
   align=attacker->query_alignment();
   if(random(this_player()->query_level()+this_player()->query_wc())>random(attacker->query_ac()+attacker->query_level()/2)){
      dam = random(this_player()->query_wc() + 3);
      if(dam>20){
         what="smashed";
         how=" with a bone crushing sound.";
      }
      if(dam<20){
         what="hit";
         how=" very hard.";
      }
      if(dam<10){
         what="hit";
         how=" hard.";
      }
      if(dam<5){
         what="hit";
         how=".";
      }
      if(dam<3){
         what="grazed";
         how=".";
      }
      if(dam==1){
         what="tickled";
         how=" in the stomach.";
      }
      if(dam==0){
         what="missed";
         how=".";
      }
      write("You "+what+ " "+ capitalize(attacker->query_real_name())+how+"\n");
      say(capitalize(this_player()->query_real_name())+ " "+what+" "+capitalize(attacker->query_real_name())+ how+ "\n");
   }
   if(random(6)>2){
      if(align<0){
         say(capitalize(this_player()->query_real_name())+"'s claw of light rips into its malovelent opponent.\n\n");
         write("Your claw of light rips into your malovelent opponent.\n\n");
	  attacker->heal_self(-(3+(random(2))));
      }
      else{
         say(capitalize(this_player()->query_real_name())+"'s claw of light fails to fully penetrate its opponent.\n\n");
         write("Your claw of light fails to fully penetrate your opponent.\n\n");
         attacker->heal_self(-random(2));
      }
   }
   if(random(6)>2){
      if(align>-1){
         say(capitalize(this_player()->query_real_name())+"'s claw of dark rips into its benevolent opponent.\n\n");
         write("Your claw of dark rips into your benevolent opponent.\n\n");
attacker->heal_self(-(3+(random(2))));
      }
      else{
         say(capitalize(this_player()->query_real_name())+"'s claw of dark fails to fully penetrate its opponent.\n\n");
         write("Your claw of dark fails to fully penetrate your opponent.\n\n");
         attacker->heal_self(-random(2));
      }
   }
}
