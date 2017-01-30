#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob, ob2, ob3;
int a, b; a = random(7); b = random(4);
 ob = clone_object("obj/money");
  ob->set_money(random(400) + 250);
  move_object(ob, this_object());
if(b == 0){ ob2 = clone_object(ROOT+"obj/tiger_cloak.c"); }
if(b > 0) { ob2 = clone_object(ROOT+"obj/rag_cloak.c"); }
  move_object(ob2, this_object());
if(a == 0){ ob3 = clone_object(ROOT+"wep/tiger_scim.c"); }
if(a == 1){ ob3 = clone_object(ROOT+"wep/scimitar1.c"); }
if(a == 2){ ob3 = clone_object(ROOT+"wep/scimitar1.c"); }
if(a == 3){ ob3 = clone_object(ROOT+"wep/scimitar1.c"); }
if(a == 4){ ob3 = clone_object(ROOT+"wep/scimitar2.c"); }
if(a == 5){ ob3 = clone_object(ROOT+"wep/scimitar2.c"); }
if(a == 6){ ob3 = clone_object(ROOT+"wep/scimitar2.c"); }
  move_object(ob3, this_object());

set_name("Carver");
set_alias("platmon");
set_alt_name("Carver");
set_race("carver");
set_gender("creature");

set_short("An angry "+RED+"carver"+NORM);
set_long("A tall humanoid, the carver has an additional pair of arms ending in\n"+
         "large talons extending from the chest area. It has wrapped itself in\n"+
         "a large cloak, trying to stay warm from the breeze up upon the\n"+
         "plateau. The carver is an angry, hostile race.\n");

set_level(16);
set_ac(13);
set_wc(21 + random(4));
set_hp(280 + random(40));
set_al(-1000);
set_aggressive(1);

init_command("wield scimitar");
init_command("wear cloak");

set_a_chat_chance(80);
load_a_chat("Carver hits you very hard.\n");
load_a_chat("Carver hits you with a bone crushing sound.\n");
load_a_chat("Carver tears at you with its extra arms.\n");
load_a_chat("Carver rips at your body with its talons.\n");
load_a_chat("Carver swings it blade at your head, trying to end the fight at once.\n");
load_a_chat("Carver screams and howls madly during the fighting.\n");
load_a_chat("Carver seems to enjoy the fighting, taking it to you aggresively.\n");

   }
}
