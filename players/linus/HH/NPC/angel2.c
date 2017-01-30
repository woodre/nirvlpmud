#include "/players/linus/def.h"

inherit "/players/vertebraker/closed/std/monster.c";

string COLOR,COLOR2,MSG,BOOGALOO;

int x, y, i;

id(str) { return str=="cherub" || str=="linus_angel_mob" || str=="angel"; }

reset(arg) {

 COLOR = ({HIC,HIB,HIY,HIG,HIW,HIM});
 COLOR2 = ({CYN,BLU,YEL,GRN,WHT,MAG});
 MSG = ({ "P O W E R", "F U R Y", "E N E R G Y", "S T R E N G T H" });

  x = random(sizeof(COLOR));
  y = random(sizeof(MSG));

 BOOGALOO = COLOR[x]+"["+HIW+"cherubian"+NORM+COLOR[x]+"]"+NORM;

 ::reset(arg);
  if(arg) return;
 set_name("angel");
 set_short("Angel " + BOOGALOO);
 set_long(
 "  The angel looks on you with love and happiness.  He appears to be\n"+
 "human in nature, but has no legs.  Large wings extend past his\n"+
 "shoulders, beating in a smooth rhythm.  The angel wears a white\n"+
 "jacket, and a small badge can be seen on the right breast pocket\n"+
 "which reads: " + BOOGALOO + "\n");
 set_level(22);
 set_wc_bonus(5);
 set_ac_bonus(1);
 set_chat_chance(5);
 load_chat("The angel looks at you with love and happiness.\n");
 set_chance(15);
 set_spell_dam(10+random(31));
 set_spell_mess1("The angel emits an ear piercing shriek!");
 set_spell_mess2("The angel emits an ear piercing shriek!");
 set_dead_ob(TO);
}
monster_died() {
object corpse, stuff;
corpse = present("corpse",ENV(TO));
tell_room(ENV(TO),"  The angel whispers: "+COLOR[x]+"I hope you burn in hell!"+NORM+
"\n\n       The angel fades to nothing, leaving something behind.\n");
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
 tell_room(ENV(TO),"The angel strikes with supernatural\n\n"+
                    COLOR2[x]+"         ~"+NORM+COLOR[x]+"  "+MSG[random(sizeof(MSG))]+
                    "  "+NORM+COLOR2[x]+"~"+NORM+"\n\n", ({ attacker_ob }));
 tell_object(attacker_ob,"The angel strikes with supernatural\n\n"+
                          COLOR2[x]+"         ~"+NORM+COLOR[x]+"  "+MSG[random(sizeof(MSG))]+
                          "  "+NORM+COLOR2[x]+"~"+NORM+"\n\n"); 
 attacker_ob->hit_player(15+random(41));
 return 1;
}
 
