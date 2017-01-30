#include "/players/hippo/bs.h"
inherit "obj/monster";

object heal;
void reset(int arg){
   ::reset(arg);
     if(arg) return;
set_name("langerhans");
set_alias("cancer");
set_short("A carcinogene Langerhans cell");
set_long("This looks like a horrible cell.. Do you attack it or not?"+BS+
   ""+BS+"Never mind.. It's attacking you already. Beware!"+BS);
set_level(20);
set_ac(19);
set_wc(35);
set_al(-1000);
add_money(1500+random(800));  /* Fred */
set_hp(1000);
set_aggressive(1);
   move_object(clone_object("/players/hippo/heals/dna_repair"),this_object());
}

#include "/players/mythos/amon/hb_ag.h"
