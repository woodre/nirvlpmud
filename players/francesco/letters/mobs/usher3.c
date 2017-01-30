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
   set_alias("leo");
     set_short("Leo, a department usher");
     set_long("The usher is wearing a blue uniform with a pin on its collar. \n"+
              "He is of tiny frame and well on on ages.  He has been working \n"+
              "for 40 years in this Department and knows everything of it. \n");
   set_level(5);
   set_hp(75);
   set_wc(9);
   set_wc_bonus(3);
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
      say("Leo reaches professor closer with a smile.\n");}    
  }     
  ::heart_beat();
}	
