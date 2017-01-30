inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(100) + 20);
  move_object(gold,this_object());
 
     set_name("snow angel");
     set_short("Snow Angel");
     set_race( "angel");
     set_alias("angel");
     set_long(
"This is a beautiful, white creature about 5' tall with large,\n"+
"powdery wings. Its beautiful ice-blue eyes peer curiously at\n"+
"you as it smiles happily.\n");
     set_level(8);
     set_ac(3+ random(5));
     set_wc(6 + random(10));
     set_hp(100 + random(50));
     set_al(800);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat(
"The Snow Angel says: Will you play with me?\n");
     load_chat(
"The Snow Angel falls backward into the snow with a POOF!\n");
     load_a_chat(
"The Snow Angel starts to cry.\n");
     load_a_chat(
"The Snow Angel says: Why are you hurting me?\n");
   }
}
