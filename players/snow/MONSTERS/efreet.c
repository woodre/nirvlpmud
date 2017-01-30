inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold,ob;
  gold = clone_object("obj/money");
  gold->set_money(random(2000) + 3000);
  move_object(gold,this_object());
 
  ob = clone_object("/players/snow/WEAPONS/flame_scim.c");
  move_object(ob,this_object());
 
     set_name("efreeti");
     set_short("A powerful minion of fire");
     set_race("efreet");
     set_alias("minion");
     set_long("This is a fabled efreeti. It is about twelve feet tall and wielding \n" +
                    "a huge scimitar of flame. Be prepared for a battle as the efreet \n" +
                    "always fight to the death.\n");
     set_level(20);
     set_ac(18 + random(4));
     set_wc(24 + random(16));
     set_hp(350 + random(250));
     set_al(-800);
     set_aggressive(1);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The efreeti says: My master wishes you to die.\n");
     load_chat("The efreeti grins in anticipation of battle.\n");
     load_a_chat("The efreeti says: 'twil be a pleasure to disembowel you!\n");
     load_a_chat("The efreeti sends its scimitar blurring at you.\n");
set_spell_mess1("The flaming scimitar buries deep into its foe, sizzling flesh.\n");
set_spell_mess2("The efreeti's flaming scimitar burns deep into your flesh.\n");
set_chance(20);
set_spell_dam(20);
   }
}
 
init() {
  ::init();
    if(this_player()->query_level() > 21) {
add_action("mon_attack","efreetattack");
    }
}
 
mon_attack(arg) {
  object meat;
  string name,meatname,moname;
meat = present(arg,environment(this_object()));
name = capitalize(this_player()->query_real_name());
meatname = capitalize(arg);
moname = this_object()->query_real_name();
  if(!meat) { say(meatname+" is not here!\n"); return 1; }
  if(living(this_object())) {
call_other(this_object(),"attack_object",meat);
  }
  log_file("snow.atk",
ctime(time())+" "+name+" forced "+moname+" to attack "+meatname+"\n");
return 1;
}

efreet_life() {
 object meat;
meat = this_object()->query_attack();
call_out("efreet_life",1);
  if(meat) {
    if(random(10) < 7) return 1;
else
    say("The Efreet bellows forth flame upon "+
      capitalize(meat->query_name())+"!\n");
    tell_player(meat,"***You are severely burned!***\n");
  }
  if(!environment(this_object()) == environment(meat)) {
move_object(this_object(),environment(meat));
    say("An Efreet storms into the room looking for "+
      capitalize(meat->query_name())+"!\n");
  }
return 1;
}
