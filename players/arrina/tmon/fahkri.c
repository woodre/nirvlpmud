 inherit "/obj/monster";
#include "/players/beck/MortalKombat/MKQuestNPC.h"
  reset(arg) {
    ::reset(arg);
    if (!arg) {
  object ob;
   ob = clone_object("/players/arrina/weapons/punchknife.c");
  move_object(clone_object("/players/dragnar/MKScar/scar"),this_object());
   move_object(ob,this_object());
       set_alias("guard");
       set_alt_name("qurd");
      set_name("fahkri");
      set_short("Fahkri, the Guard");
      set_race( "demon");
      set_gender( "male");
      set_long("Fahkri is the guardian of the Qurd tunnels.\n"+
        "His strength is remarkable!  As you look at him, you\n"+
        "see that although he looks somewhat human, his body is\n"+
        "covered with fur, and his eyes are enormous, the pupils\n"+
        "huge, to adapt for the lack of light.\n");
      set_level(22);
      set_ac(25);
     init_command("wield knife");
      set_wc(40);
      set_hp(1200);
      set_al(-2000);
      set_aggressive(0);
      set_chat_chance(20);
       load_chat("Fahkri warns: You will get lost in the home of my people.\n");
       load_chat("Fahkri says: I guard this entrance for my people.\n");
       load_chat("In the distance, you hear a scream of abject terror!\n");
       }
 }
