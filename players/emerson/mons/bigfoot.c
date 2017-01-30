inherit "/obj/monster";
int lvl,wcc;

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob2, ob3, gold;
   ob2 = clone_object("/players/emerson/weap/bigfoot.c");
move_object(ob2,this_object());
   ob3 = clone_object("/players/emerson/armor/hide.c");
   move_object(ob3,this_object());
 gold = clone_object("obj/money");
gold->set_money((3000));
  move_object(gold,this_object());
set_short("bigfoot");
set_name("bigfoot");
set_alias("bigfoot");
     set_race( "human");
set_long("This is the legendary bigfoot, he is a hairy manlike creature\n"+
"which stands 15 feet tall,but at present he is huddled in the corner.\n"+
"Looking at him makes the hair on the back of you neck stick up in fear!\n");
     set_level(20);
     set_ac(20);
     set_wc(33);
     set_hp(1000);
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(15);
     set_a_chat_chance(35);
     load_chat("Something stirs in the far corner of the freezer...\n");
load_a_chat("The Bigfoot crushes you with his huge hands!\n");
load_a_chat("You are crushed by the Sasquatch's big feet!\n");
   }
}
short() { return 0; }
