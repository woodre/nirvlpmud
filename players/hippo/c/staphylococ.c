#include "/players/hippo/bs.h"
inherit "obj/monster";
object dna_string;
void reset(int arg){
   ::reset(arg);
     if(arg) return;
set_name("staphylococ");
set_alias("coc");
set_short("A staphylococ");
set_long("This is a staphylococ, a bacteria that looks quite tough to kill."+BS);
set_level(20);
  set_hp(500 + random(100));
set_ac(17);
set_wc(32 + random(5));
set_al(-random(100));
add_money(1500+random(1000));   /* Fred */
set_aggressive(1);
dna_string = clone_object("/players/hippo/heals/dna_string");
if(dna_string) {
   move_object(dna_string,this_object());
}
set_a_chat_chance(20);
   load_a_chat("Heya!!! Don't attack me, you fool!"+BS);
   load_a_chat("You wanna die ??"+BS);
   load_a_chat("Never attack a bactery !!"+BS);
   load_a_chat("I'll infect you.. you'll never get out of here alive !!"+BS);
   load_a_chat("Stay away from my DNA. I had to fight for that myself!"+BS);
}
