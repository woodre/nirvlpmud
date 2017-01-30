#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/monster.c";
id(str) { return str=="lost soul" || str=="spirit" || str=="child"; }
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("lost soul");
 set_short("A lost soul "+HIC+"["+HIW+"child"+HIC+"]"+NORM);
 set_long(
 "  Lost souls are members of the spirit world who don't realize that\n"+
 "they are dead yet. Many are former citizens of Celestia, who have died\n"+
 "a sudden or unexpected death.  Celestia was a peaceful city, and many\n"+
 "of the souls are harmless, peaceful beings.  This one was a child \n"+
 "taken before her time.\n");
 set_level(15);
 set_hp(250+random(150));
 set_wc(20);
 set_chat_chance(10);
 load_chat("The soul drifts around aimlessly...\n");
 load_chat("The soul moans in anguish...\n");
set_chance(15);
 set_spell_dam(20+random(30));
 set_spell_mess1("The soul strikes with supernatural\n\n"+CYN+"          ~"+HIC+"  P O W E R  "+NORM+CYN+"~"+NORM+"\n\n");
 set_spell_mess2("The soul strikes with supernatural\n\n"+CYN+"          ~"+HIC+"  P O W E R  "+NORM+CYN+"~"+NORM+"\n\n");
 set_dead_ob(TO);
}
monster_died() {
object corpse;
corpse = present("corpse",ENV(TO));
tell_room(ENV(TO),"  The spirit whispers: "+HIC+"Thank you for releasing me"+NORM+"\n\n     The spirit fades to nothing, leaving something behind.\n");
MO(CO("/players/linus/Plains/obj/essence.c"),ENV(TO));
if(corpse) destruct(corpse);
return 1;
}
