#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define attacker attacker_ob
int i,z,y;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;

  move_object(clone_object("/players/pestilence/club/arm/bstring.c"),
        this_object());
  command("wear g-string");

  set_name("Shelly"); 
  set_alt_name("shelly");
  set_alias("stripper");
  set_short("Shelly the stripper");
  set_long("Shelly is a light skinned, brunette.  She stands about 5 feet\n"+
           "two inches tall.  Her hair flows gently down past her shoulders.\n"+
           "Currently she isn't dancing, she's waiting backstage for her turn\n");
  set_race("human");
  set_gender("female");
  set_level(18);
  set_wc(30+random(6));
  set_ac(16+random(4));
  set_hp(400+random(200));
  set_wc_bonus(7);
  set_heal(15,5);
  add_money(2000+ random(2000));
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(0);
  load_chat("Shelly says: I don't think you should be backstage.\n");
  load_chat("Shelly says: Jim, get these punks out of here!\n");
  set_chat_chance(10);
  load_a_chat("Shelly screams!\n");
  set_a_chat_chance(10);
  set_spell_mess2("Shelly slaps you hard across your face.\n");
  set_spell_mess1("Shelly slaps her attacker, hard across the face.\n");
  set_chance(20);
  set_spell_dam(40);
}
init() {
  ::init();


}

heart_beat(){
int z;
::heart_beat();
if(!environment()) return; 

if(attacker_ob && present(attacker_ob,environment(this_object()))){
z = random(10);
if(z>8){
   tell_room(environment(this_object()), 
  "Shelly digs her nails into her attacker, drawing "+HIR+"blood"+NORM+".\n");
  tell_object(attacker_ob,
  "Shelly digs into your skin with her nails, leaving a trail of "+HIR+"blood"+NORM+".\n");
    attacker->hit_player(20+random(30));
     }
}
}
