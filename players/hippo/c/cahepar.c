#include "/players/hippo/bs.h"
inherit "obj/monster";

void reset(int arg){
   ::reset(arg);
     if(arg) return;
set_name("hepatocyte");
set_alias("cancer");
set_short("A carcinogene hepatocyte");
set_long("This is a carcinogene hepatocyte. This means it's causing"+BS+
   "cancer in the liver. You should stop it quickly, else Hippo could die..."+BS+
   "But it'll be a very very hard task."+BS);
/* Changed from 25 to 20 (tough but nothing special) -Snow */
set_level(20);
set_ac(20);
set_wc(31);
add_money(2000+random(1000));  /*Fred 3-14-03 */
set_hp(800);
set_al(-1000);

move_object(clone_object("/players/hippo/heals/dna_string.c"),this_object());
set_a_chat_chance(5);
   load_a_chat("WHOAA!! What are you doing here?"+BS+"This is MY domain!!"+BS);
   load_a_chat("I'll scrumble you if you don't watch out!"+BS);
   load_a_chat("You'd better get out before i'll find my way in your body to the liver..."+BS);
   load_a_chat("I've nearly killed Hippo.. then it's your turn, i think"+BS);
   load_a_chat("You look like a good meal to me...."+BS);
}
