inherit "obj/monster";
object attacker;
string attacker_name;
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Nightmare");
   set_race("monster");
   set_alias("nightmare");
   set_short("Nightmare");
   set_level(21);
 set_long("A horrid nightmare summoned to terrorize some poor mortal.\n");
   set_hp(80);
   set_al(-1000);
   set_wc(15);
   set_ac(6);
   set_can_kill(1);
   set_heart_beat(1);
   call_out("blammo",50);
}
id(str){return str == "nightmare" || str == "mare";}
heart_beat(){
   ::heart_beat();
   attacker=this_object()->query_attack();
   if(!attacker){
      destruct(this_object());
   }
}

blammo() {
  say("The Nightmare slowly fades from view as it returns home.\n");
  destruct(this_object());
  return 1;
}
