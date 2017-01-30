#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/monster";
object ob, attacker_ob;

attaccante(attacker_ob) {ob=attacker_ob; }

reset(arg){
  ::reset();
  if(arg) return;
   set_name("Test");
   set_race("human");
   set_gender("creature");
   set_alias("carcrash");
     set_short("carcrash");
     set_long("A bunch of contorted metal sheets and broken items\n");
   set_level(5);
   set_hp(20);
   set_wc(30);
   set_ac(5);
   set_al(-100);
   set_aggressive(1);
   set_message_hit(({
"let"," knock onto the taxi dashboard",
"let"," knock onto the taxi dashboard",
"let"," knock onto the taxi dashboard",
"let"," knock onto the taxi dashboard",
"let"," knock onto the taxi dashboard",
"let"," knock onto the taxi dashboard",
"let"," knock onto the taxi dashboard",
"let"," knock onto the taxi dashboard"}));

}

init() {
::init();
}

heart_beat() {
  if(!environment()) return;
   attack_object(ob);
   ob->hit_player(75);
  destruct(this_object());
}	
