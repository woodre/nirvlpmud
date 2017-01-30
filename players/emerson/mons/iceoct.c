inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold,ob;
  gold = clone_object("obj/money");
  gold->set_money(random(4000));
  move_object(gold,this_object());

  ob = clone_object("players/snow/WEAPONS/ice_star");
  move_object(ob,this_object());
 
     set_name("Ice Octopus");
set_short("A beautiful crystalline structure with waving tentacles");
     set_race( "octopus");
     set_alias("structure");
     set_long(
"This is an incredible creature made entirely from living crystals of ice.\n"+
"Its eight crystal clear arms are tinged with a bluish light and in its eyes\n"+
"you see a piercing gleam of intelligence.\n");
     set_level(15 + random(5));
     set_ac(13+ random(10));
     set_wc(15 + random(15));
     set_hp(200 + random(200));
     set_al(0);
     set_aggressive(0);
set_chance(80);
set_spell_mess1(
"One of the ice octopus' crystal tentacles wraps around its prey. The\n"+
"hapless victim screams in pain!\n");
set_spell_mess2(
"A crystal tentacle wraps tightly around your body. You scream in pain!\n");
set_spell_dam(15);
call_out("tentacles",5);
   }
}

tentacles() {
  object meat;
meat = this_object()->query_attack();
  if(meat) {
tell_room(environment(this_object()),
  "The Ice Octopus reaches out with its tentacles!\n");
tell_room(environment(this_object()),capitalize(meat->query_name())+
  " is wrapped in tentacles of crystal!\n");
call_other(meat,"heal_self",-(random(20)+5));
  }
call_out("tentacles",5);
return 1;
}
