inherit "/players/mizan/core/monster.c";

reset(arg)
{
   object gold, what;
   ::reset(arg);

   if(arg) return;
   
   /* descriptions */
   set_name("Father Bob");
   set_race("human");
   set_alias("bob");
   set_short("Father Bob");
   set_long("This is Father Bob, of the Church of the Automatic Transmission.\n"+
   "He is a slightly graying, bearded, heavyset man with the tattoo of a\n"+
   "Harley Davidson hardtail proudly emblazoned on his right arm, and the\n"+
   "iron cross on his left. You instantly fear him, because to get here,\n"+
   "you have obviously sinned.\n");
   
   /* vital stats */
   set_level(23);
   set_hp(800 + random(800));
   set_al(22);
   set_wc(36);
   set_ac(23);
   set_chance(10);
   
   /* combat spell stuff */
   set_spell_dam(4);
   set_spell_mess1("Father Bob punts you in the behind!\n"+
      "Father Bob shouts: You will go to HELL boy! Just like all\n"+
      "  those other independent suspension bastards!\n");
   set_spell_mess2("Father Bob punches you in the jaw!\n"+
      "Father Bob exclaims: Take that, you pink-assed communist!\n");
   
   /* attack chats */
/*
   set_a_chat_chance(10);
   load_a_chat("Father Bob shouts: Jesus SAVES! He can save YOU too my brother,\n"+
      "  all you need is love, and a Hog!\n");
   load_a_chat("Father Bob exclaims: Huuuuush puppy.. You're a jumpy little\n"+
      "  varmint...\n");
   load_a_chat("Father Bob exclaims: Now hold on here boy, you're just making\n"+
      "  a darg-gone fool outta yerself.\n");
   load_a_chat("Father Bob exclaims: Now don't make me hurt you, boy.\n");
*/

   /* chat related stuff */
   set_chat_chance(10);
   load_chat("Father Bob orates: 'May your days be bright and sunny, May the bugs\n"+
      "  not stick to your teeth, and may there be a truck stop every few hours\n"+
      "  on the open road...'\n");
   load_chat("Father Bob orates: ...And on the sixth day, God gave man a Harley,\n"+
      "  and the Lord said: 'Now THAT is GOOD!'\n");
   load_chat("Father Bob orates: ...So Matthew took the can of Gum-Out, and held it\n"+
      "  aloft over his head... and he said: 'THIS... will clean my carburetor...'\n");
   load_chat("Father Bob orates: ...Luke said to the Lord, 'My car needs a tune up...'\n"+
      "  ...And the Lord grew upset, and spake: 'You need the shit beaten\n"+
      "  out of you! Go get your own copy of Chilton's!\n");
   load_chat("Father Bob says: JESUS rides a Harley in Heaven. Hallelujah!\n");
   load_chat("Father Bob says: Cars? Pfft. I don't like cars. They make me sick.\n");
   load_chat("Father Bob says: Don't let that turd-banned squint-neck little freak\n"+
      "  tell you wrong. JESUS Saves! You can count on Him for that.\n");
   load_a_chat("Father Bob chuckles: You can't get 40 miles a gallon driving a CAR!\n");
   load_a_chat("Father Bob cries AMEN! Hallelujah! A Harley in Heaven for every\n"+
      "  man, woman, and child. And the Lord said that was good!\n");

   /* gold */
   gold = clone_object("obj/money");
   gold->set_money(random(2)+10);
   move_object(gold,this_object());

   /* treasures */
   what=clone_object("players/mizan/etheriel/items/thingamajig.c");
   move_object(what, this_object());
}

int old_hp;

heart_beat()
{
   int my_hp;

   my_hp = query_hp();
   if(old_hp && old_hp != my_hp)
   {
      say("DAM INFLICTED: [" + (old_hp - my_hp) + "]\n");
   }

   old_hp = my_hp;

   ::heart_beat();
}