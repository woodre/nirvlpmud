#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/monster.c";
string COLOR,COLOR2,MSG;
int x, y, i;
id(str) { return str=="spirit" || str=="linus_angel_mob" || str=="lost soul"; }
reset(arg) {
 COLOR = ({HIC,HIB,HIY,HIG,HIW,HIM});
 COLOR2 = ({CYN,BLU,YEL,GRN,WHT,MAG});
 MSG = ({ "P O W E R", "F U R Y", "E N E R G Y", "S T R E N G T H" });
 x = random(sizeof(COLOR));
 y = random(sizeof(MSG));
 ::reset(arg);
 if(arg) return;
 set_name("Soul");
 set_short("Blessed soul "+COLOR[x]+"["+HIW+"spirit"+NORM+COLOR[x]+"]"+NORM);
 set_long(
 "  Lost souls are members of the spirit world who don't realize that\n"+
 "they are dead yet. Many are former citizens of Celestia, who have died\n"+
 "a sudden or unexpected death.  Celestia was a peaceful city, and many\n"+
 "of the souls are harmless, peaceful beings.  They wander the streets\n"+
 "of the city unaware that they shouldn't be here.\n");
 set_level(20);
 set_wc(30+random(10));
 set_wc_bonus(5);
 set_chat_chance(10);
 load_chat("The soul drifts around aimlessly...\n");
 load_chat("The soul moans in anguish...\n");
 set_chance(15);
 set_spell_dam(10+random(31));
 set_spell_mess1("The spirit emits an ear piercing shriek!");
 set_spell_mess2("The spirit emits an ear piercing shriek!");
 set_dead_ob(TO);
}
monster_died() {
object corpse, stuff;
corpse = present("corpse",ENV(TO));
tell_room(ENV(TO),"  The spirit whispers: "+COLOR[x]+"Thank you for releasing me..."+NORM+
"\n\n       The spirit fades to nothing, leaving something behind.\n");
stuff = CO("/players/linus/Plains/obj/essence.c");
stuff->set_color(COLOR[x]);
MO(stuff, ENV());
if(corpse) destruct(corpse);
return 1;
} 
heart_beat() {
 ::heart_beat();
 if(attacker_ob){
  i = random(30);
   switch(i) {
    case  0..10: return 0; break;
    case 11..15: hit_me_baby(); break;
    case 16..30: return 0; break;
  }
 }
}
hit_me_baby() {
 if((attacker_ob) && (attacker_ob->query_ghost())) return;
 tell_room(ENV(TO),"The spirit strikes with supernatural\n\n"+
                    COLOR2[x]+"         ~"+NORM+COLOR[x]+"  "+MSG[random(sizeof(MSG))]+
                    "  "+NORM+COLOR2[x]+"~"+NORM+"\n\n", ({ attacker_ob }));
 tell_object(attacker_ob,"The spirit strikes with supernatural\n\n"+
                          COLOR2[x]+"         ~"+NORM+COLOR[x]+"  "+MSG[random(sizeof(MSG))]+
                          "  "+NORM+COLOR2[x]+"~"+NORM+"\n\n"); 
 attacker_ob->hit_player(15+random(41));
 return 1;
}
 
