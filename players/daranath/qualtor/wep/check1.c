
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("axe");
        set_short("Asterix' mighty axe") ;
        set_long("This is Asterix' axe. This is a VERY powerful weapon.\n") ;
        set_weight(3) ;
        set_value(3000);
        set_class(20) ;
	set_save_flag(1);
    set_hit_func(this_object());
}
query_save_flag() {return 1;}

/* added in this heal_self thingy cause this was originally a wc 20 with no drawback...
  *  one out of three times the healf_self goes off and the wielder takes some damage.
  *        -mythos <11/13/95  
  */
weapon_hit(attacker) {
  if(random(3) == 0) {
    this_player()->heal_self(-random(7) - 1);
    write("You lose your grip on the axe for a second!\n");
  }
return 0; }
