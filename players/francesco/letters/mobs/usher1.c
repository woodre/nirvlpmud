#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/monster";

reset(arg){
  ::reset();
  if(arg) return;
   set_name("usher");
   set_race("human");
   set_gender("male");
   set_alias("gaspard");
     set_short("Gaspard, a department usher");
     set_long("The usher is wearing a blue uniform with a pin on its collar. \n"+
              "About 6 feet tall, he is also very robust.  He often smiles and\n"+
              "all professors of the Department like to let him get involved in\n"+
              "their activities.  Conversely, he likes to help the others. \n");
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
      say("Gaspard moves closer to Professor to aid him.\n");}    
  }     
  ::heart_beat();
}	