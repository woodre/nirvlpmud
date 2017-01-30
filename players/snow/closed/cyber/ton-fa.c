/* CyberNinja Guild Weapon Coded by Ulath 6-97 */

#include "/players/llew/closed/ansi.h"
#include "/players/ulath/closed/ninjaweps/wepdefs.h"
#define TONFA "/players/ulath/closed/ninjaweps/tonfadaem.c"

inherit "/players/snow/closed/cyber/weapon.c";

object master;

reset(arg) {
   int artwc;
   string tonshort;
   ::reset(arg);
   tonshort = "Ton-Fa <steel>";
   artwc = -10;
if(!GOB || !ARTR) tonshort = "Ton-Fa <rubber>";
if(GOB) { if(ARTR) artwc = (ARTR/3)+1; }
   if(TP->query_level() < 20) {if(artwc > 5) artwc = 5; }
   if(artwc == 3) tonshort = "Ton-Fa <titanium>";
   if(artwc == 4) tonshort = "Ton-Fa <adamantium>";
   if(artwc == 5) tonshort = "Ton-Fa <ether-alloy>";
   if(artwc > 5) tonshort = "Ton-Fa <vortex-forged>";

   master = this_player();
   
   if(arg) return;
   set_name("ton-fa");
   set_alt_name("tonfa");
   set_alias("fa");
   set_short(tonshort);
   set_long("A three foot long staff with a handle about 1/3 of\n"+
            "the way down, perpendicular to the pole. In the trained\n"+
            "arms of a Cyberninja, it it a very deadly weapon.\n");
   set_class(artwc+12);
   set_weight(2);
   set_hit_func(this_object());
   call_out("wep_beat",5);
}

wep_beat() {
   object myenv;
   myenv = environment(TO);
   if(!myenv) return 1;
   if(!master) { destruct(TO); return 1; }
   if(myenv != master && myenv->is_player() && TO->wielded()) {
      myenv->stop_wielding(); destruct(TO); return 1;
   }
   if(!myenv->is_player()) destruct(TO);
   call_out("wep_beat",25);
   return 1;
}

offer_tonfa(arg) {TONFA->offer_tonfa(arg); return 1;}
weapon_hit() {TONFA->weapon_hit(); return 1;}
ton_stab() {TONFA->ton_stab(); return 1;}
ton_gut_punch() {TONFA->ton_gut_punch(); return 1;}
ton_face_smash() {TONFA->ton_face_smash(); return 1;}
ton_multi_hit() {TONFA->ton_multi_hit(); return 1;}
r_attack() {TONFA->r_attack(); return 1;}
ton_head_slap() {TONFA->ton_head_slap(); return 1;}
ton_back_strike() {TONFA->ton_back_strike(); return 1;}
ton_throat_blow() {TONFA->ton_throat_blow(); return 1;}
ton_aura() {TONFA->ton_aura(); return 1;}
ton_finish() {TONFA->ton_finish(); return 1;}

