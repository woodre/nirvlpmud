inherit "obj/weapon";
object opponent;

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("Plasma-Charged Disc");
   set_alt_name("disc");
   set_alias("disc");
   set_short("Plasma-Charged Disc");
   set_long("    This disc is made from an unknown substance. Its rounded\n"+
            "razor edges are coated with glowing raw plasma energy making\n"+
            "it an extremely deadly weapon. Heavy damage can be done to your\n"+
            "opponent since they probably won't see it coming. It feels good\n"+
            "in the palm of your hand.\n");
   set_class(20);
   set_hit_func(this_object());
   set_weight(3);
   set_value(2000);
}

weapon_hit(attacker){
   opponent = attacker;
   if(random(200) > 20){
     write("You *SLICE* deep and burn your opponent with a mighty swing!\n");
      say(capitalize(this_player()->query_real_name()) +
         " slices deep!\n");
      if(attacker->query_hp()>45){
         if(this_player()->query_sp()>0){
            attacker->hit_player(7+random(10));
            this_player()->add_hit_point(-5);
            this_player()->add_spell_point(-10);
            write("You *SLICE* deeply again, spilling guts in the process!\n");
            say(capitalize(this_player()->query_real_name()) +
               " slices again, spilling guts everywhere!\n");
         }
      }
      return 2;
   }
}
