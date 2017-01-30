inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);

     set_name("scourge");
     set_short("Scourge");
     set_long("A wicked multi tailed whip, the scourge has metal spikes\n"+
              "and nails set along the length of every tail. Not a\n"+
              "nice weapon.\n");
     set_weight(2) ;
     set_value(3000);
     set_class(20) ;
     set_hit_func(this_object());
}
query_save_flag() {return 1;}

weapon_hit(attacker) {
  if(random(3) == 0) {
    this_player()->heal_self(-random(7) - 1);
    write("The scourge backlashes and cuts you deeply!\n");
return 10;
  }
return 3; }
