#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/monster";

reset(arg){
  ::reset();
  if(arg) return;
   set_name("usher");
   set_race("human");
   set_gender("female");
   set_alias("husher");
     set_short("Marion, a department usher");
     set_long("The usher is wearing a blue uniform with a pin on its collar. \n"+
              "She must have been hired not long ago, she still is learning\n"+
              "her duties and she is just getting acquainted with the secrets\n"+
              "of the Academy.\n");
   set_dead_ob(this_object());
   set_level(5);
   set_hp(75);
   set_wc(9);
   set_ac(5);
}

init() {
::init();
}

heart_beat() {
object ob;
  if(!environment()) return;
  if(ob = present("prof", environment())) 
    { if(ob->query_attack()) attack_object(ob->query_attack()); } 
  if(ob = present("prof", environment())) {
    if(random(20) >= 17) {
      say("Marion hands Professor a small book.\n");}    
  }     
  ::heart_beat();
}	
