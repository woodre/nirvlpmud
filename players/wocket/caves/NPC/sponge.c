#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
::reset();
  if(arg) return;
set_name("sponge");
set_short("A cave sponge");
set_long("This is a large pale yellow cave sponge.  It has grown to a tremendous\n"+
         "size in this dark environment.  It looks very healthy as it seems to\n"+
         "regenerate at an astounding rate.  It doesn't have any visible\n"+
         "appendages but many quills seem hidden deep with in the ruffled outer\n"+
         "layer of flesh.\n");
set_level(20);
set_hp(500);
set_wc(25);
set_ac(20);
set_heal(10,20);
set_chance(25);
set_spell_dam(50);
set_spell_mess1("");
set_spell_mess2("Quills shoot from the sponge stabbing into you.\n");
set_dead_ob(this_object());
}

monster_died(){
int i;
for(i=0;i<2;i++){
if(random(2)==1){ move_object(clone_object("/players/wocket/caves/OBJ/spongeflesh.c"),this_object()); }
else{ move_object(clone_object("/players/wocket/caves/OBJ/spongejuice.c"),this_object()); }
}
}
