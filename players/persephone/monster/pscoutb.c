inherit "obj/monster";
object cutlass,glove;
string chats;
reset(arg) {
 ::reset();
  if (arg) return;
   cutlass = clone_object("/players/persephone/weapon/cutlass.c");
   move_object(cutlass, this_object());
   set_name("pirate");
   set_level(13);
   set_al(-100);
   set_short("A pirate scout");
   set_long("One of the famed advance scouts of Vvladimir.\n"+
            "You wonder why you see him so far away from his master.\n"); 
   set_hp(195);
   init_command("wield cutlass");
   set_wc(17);
   set_ac(10);
   set_aggressive(0);
   set_chance(5);
   set_spell_dam(10);
   set_spell_mess1("Skillfully thrusts his cutlass.\n");
   set_spell_mess2("Strikes you with a sudden slice of his cutlass\n");
   set_chat_chance(25);
   set_a_chat_chance(20);
   load_chat("The Black Pirate charges on Jenny's elite Pirates.\n");
   load_chat("Black Pirate shouts: Ahoy me landlubbers what you doing here?\n");
   load_chat("Black Pirate states: We will wipe Jeny's mob out soon the traitors\n");
   load_a_chat("The Black Pirate knocks out your weapon\n");
   load_a_chat("Black Pirate exclaims: You will pay for your deceipt\n");
   load_a_chat("The Black Pirate screams at you\n");
   load_a_chat("Black Pirate shouts: Come and aid me my hearties\n");
 }
