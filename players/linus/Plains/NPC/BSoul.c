#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/monster.c";
id(str) { return str=="lost soul" || str=="demon" || str=="soul"; }
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("lost soul");
 set_short("A lost soul "+HIR+"["+HIW+" demon "+HIR+"]"+NORM);
 set_long(
 "  Lost souls are members of the spirit world who don't realize that\n"+
 "they are dead yet. Many are former citizens of Celestia, who have died\n"+
 "a sudden or unexpected death.  Celestia was a peaceful city, but some\n"+
 "of the souls belonged to more sinister people.  They wander the streets\n"+
 "of the city waiting for the dark lord to rise again.\n");
 set_level(20);
 set_dead_ob(TO);
}
monster_died() {
object corpse;
corpse = present("corpse",ENV(TO));
tell_room(ENV(TO),"Blah blah\n");
MO(CO("/players/linus/Plains/obj/essence2.c"),ENV(TO));
if(corpse) destruct(corpse);
return 1;
}
