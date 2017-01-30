#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/monster.c";
id(str) { return (::id(str) || str=="linus_angel_mob" || str=="skeleton"); }
reset(arg) {
 ::reset(arg);
 set_name("Minion"); 
 set_long(
 "  Commonly called the walking dead, skeletal minions are the creation\n"+
 "of dark necromantic powers.  They thrive in consecrated areas, such as\n"+
 "cemetaries, where death and decay are in abundance.  Their form is\n"+
 "determined solely on the size of the skeletal remains from which they\n"+
 "are created.  Though most are created from human or humanoid remains,\n"+
 "skeletal minions can be created from animals as well.  the only sign\n"+
 "of life in the minion is the flickering "+HIR+"glow"+NORM+" of its eyes.\n");
 set_level(18);
 set_chance(10);
 set_spell_mess1("The minion "+HIW+"touches"+NORM+" its attacker, sending sharp pains through their body.\n");
 set_spell_mess2("The minion "+HIW+"touches"+NORM+" you, sending sharp pains through your body.\n"); 
 set_dead_ob();
 switch(random(34)) {
 case 0..9: minion1(); break;
 case 10..19: minion2(); break;
 case 20..29: minion3(); break;
 case 30..33: minion4(); break;
 default: minion1(); break;
}
}
minion1() {
 set_short("Skeletal minion "+RED+"["+HIK+"human"+NORM+RED+"]"+NORM);
 set_alias("human");
 set_wc(40);
 set_hp(200+random(400));
 set_spell_dam(10+random(60));
}
minion2() {
 set_short("Skeletal minion "+RED+"["+HIK+"animal"+NORM+RED+"]"+NORM);
 set_alias("animal");
 set_wc(35);
 set_hp(200+random(300));
 set_spell_dam(10+random(50));
}
minion3() {
 set_short("Skeletal minion "+RED+"["+HIK+"elf"+NORM+RED+"]"+NORM);
 set_alias("elf");
 set_wc(30);
 set_hp(400);
 set_spell_dam(20+random(60));
}
minion4() {
 set_short("Skeletal minion "+RED+"["+HIK+"giant"+NORM+RED+"]"+NORM);
 set_alias("giant");
 set_wc(50);
 set_hp(400+random(300));
 set_spell_dam(10+random(20));
}
monster_died() {
 object corpse;
 corpse = present("corpse",ENV());
 tell_room(ENV(TO),"The dark powers fade away, the skeleton falls into a pile.\n");
 MO(CO("/players/linus/Plains/obj/minion_remains.c"),TO);
 if(corpse) destruct(corpse);
 return 1;
}

