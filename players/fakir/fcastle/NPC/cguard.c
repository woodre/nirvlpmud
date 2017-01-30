inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {


string shortdesc;

int type;
  type = random(5);
  if(type == 0) shortdesc = "Clumsy";
  if(type == 1) shortdesc = "Rumpled";
  if(type == 2) shortdesc = "Skinny";
  if(type == 3) shortdesc = "Hungover";
  if(type == 4) shortdesc = "Sheepish";
  if(type == 5) shortdesc = "Drunken";
   
     set_name("guard");
     set_short("A "+shortdesc+" Castle Guard");
     set_race("human");
     set_long("A young country lad pressed into service for the castle guard.\n"+
              "He does not seem too terribly bright, nor dangerous.");
     set_level(9+random(4));
     set_ac(7+random(4));
     set_wc(13+random(3));
     set_hp(135+random(60));
     set_al(-150);
     set_aggressive(0);
     set_whimpy();
     set_chat_chance(5);
     set_a_chat_chance(5);
     load_chat("The guard yells: 'Over here...help! Someone has invaded the castle!'\n");
     load_chat("The guard says: 'I can probably handle you alone...you look like a weakling.'\n");
     load_chat("The guard quickly checks his weapon...\n");
     load_chat("The guard yells: 'Hey......anybody......guys?  I need help here!'\n");
     load_chat("The guard smirks and pokes you in the chest. He says: 'Your dead, bud!'\n");
     load_a_chat("The guard says: 'When I am done beating the stuffing out of you, I will \n"+
                          "toss you in the castle dungeon...'\n");
     load_a_chat("The guard spits and levels his pike at your chest.\n");
    money = random(400)+150;
   }
}

heart_beat() {
  object ob, ob2;
 ::heart_beat();
  ob = present("whitecloak", environment(this_object()));
  if(ob) {
    ob2 = ob->query_attack();
    if(ob2 && !this_object()->query_attack()) {
      if(present(ob2, environment(this_object())))
        this_object()->attack_object(ob2);
} } }

