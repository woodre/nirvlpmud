/*
Basic mid-level seal.
*/
 
#define MEATN capitalize(this_object()->query_attack()->query_name())
 
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object ob; 
int R;
string shortdesc;

R = random(4);
  if(R == 0) shortdesc = "A matronly Arctic Seal";
  if(R == 1) shortdesc = "A smooth-skinned Arctic Seal";
  if(R == 2) shortdesc = "A glistening Arctic Seal";
  if(R == 3) shortdesc = "A lounging Arctic Seal";


  ob = clone_object("/obj/treasure");
  ob->set_name("pelt");
  ob->set_short("Arctic Seal pelt");
  ob->set_value(400);
  ob->set_alias("seal pelt");
  ob->set_long(
"The pelt of an Arctic Seal. It should be worth something at the shop.\n");
move_object(ob,this_object());
 
     set_name("arctic seal");
     set_short(shortdesc);
     set_race("animal");
     set_alias("seal");
     set_long(
"A speckled brown and white seal. It likes to play in the water and sun on the beach.\n");
     set_level(8);
     set_ac(6);
     set_wc(13);
     set_hp(random(40)+80);
     set_whimpy();
     set_heal(1,3);
     set_al(random(500));
     set_aggressive(0);
     set_chat_chance(5);
     set_a_chat_chance(7);
     load_chat("The Arctic Seal rolls onto its back.\n");
     load_chat("The Arctic Seal looks at you curiously.\n");
     load_a_chat("The Arctic Seal cries out in pain!\n");
     load_a_chat("The Arctic Seal peers sadly at you.\n");
set_chance(10);
set_spell_mess1("The Arctic Seal jumps into its foe!\n");
set_spell_mess2("The Arctic Seal jumps into you!\n");
set_spell_dam(10);
   }
}
