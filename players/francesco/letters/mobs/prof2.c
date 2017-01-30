#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/monster";

reset(arg){
  ::reset();
  if(arg) return;
   set_name("professor");
   set_race("human");
   set_gender("male");
   set_alias("prof");
     set_short("Dr. Smith, an old assistant professor");
     set_long("Dr. Smith is wearing casual dress.  Almost bald and with thick\n"+
              "glasses, he is the typical bookworm.\n");
   set_level(5);
   set_hp(75);
   set_wc(9);
   set_ac(5);
}

init() {
::init();
}

id(str) {return str=="dr. smith" || str=="smith" || str=="Dr. Smith" || str=="prof" || str=="assistant" ;}

heart_beat() {
object ob;
int a;
  if(!environment()) return;
  if(ob = present("usher", environment())) 
    { if(ob->query_attack()) attack_object(ob->query_attack()); } 
  a= random(8);
  if(a==2)
   {
   if(ob = present("corpse", environment())) 
   say("The assistant sadly cries over the corpse of Professor.\n");
   }
  ::heart_beat();
}	
