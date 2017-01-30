inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset (arg){
 ::reset(arg);
  if(!arg){
   object quilt;
   quilt = clone_object("players/persephone/weapon/quil.c");
   move_object(quilt, TOB);
   init_command("wield quil");
   set_name("heironomus");
   set_alias("womble");
   set_short("Uncle Heironomus the Womble");
   set_long("Heironomous is the famed Womble Scribe he has written\n" +
            "many treaties on being a womble in a world designed\n" +
            "for humans\n");
   set_level(7);
   set_wc(11);
   set_ac(5);
   set_hp(115);
   set_al(100);
   set_aggressive(0);
   set_gender(0);
   set_chance(0);
   set_spell_dam(0);
   set_chat_chance(50);
    load_chat("Heironomous exclaims: Where did I put those glasses!\n");
    load_chat("Heironomus searches around the room for something.\n");
    load_chat("Heironomous yells: Wimbledon do you have my glasses!\n");
    load_chat("Heironomus sighs: I cannot write without my glasses\n");
   set_a_chat_chance(40);
    load_a_chat("Heironomus exclaims: Violence is bad!\n");
    load_a_chat("Heironomus states: The Pen is mightier than the sword\n");
    load_a_chat("Heironomus asks: Are all people like this?\n");
  }
}

