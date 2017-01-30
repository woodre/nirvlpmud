
inherit "obj/monster";

reset(){
set_name("worm");
set_alias("gold worm");
set_short("A golden parasitic worm");
set_long("This horrible parasite lives off of eating gold coins.\n");
set_ac(5);
set_wc(9);
set_hp(75);
set_level(5);
set_heart_beat(1);
::reset();
}

heart_beat(){
    int i;
    i = random(10);
    if(i < 9){
   tell_object(environment(this_object()), 
    "The hungry worm greedily takes a bite at your gold.\n");
      environment(this_object())->add_money(-random(300));
      return 1;
   }
     ::heart_beat();
}
