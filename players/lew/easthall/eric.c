#define TOB this_object()

inherit "/obj/monster.talk";

object ob;

void reset(int arg) {
   :: reset(arg);
   if (!arg) {
      
      set_name("roomstalker");
      set_alias("roomstalker");
      set_short("Roomstalker");
     set_alias("eric");
      set_long("This is Roomstalker.  He would reather kill you then give\n"+
         "give up his terminal.  Kill him and log him off.\n");
      set_aggressive(1);
     set_a_chat_chance(50);
      load_a_chat("Roomstalker cries:  Get away from my terminal.\n");
      load_a_chat("Roomstalker tries to kick you.\n");
    load_a_chat("Roomstalker yells:  Damn it I said go away.\n");
    load_a_chat("Roomstalker gossips:  F*****G Dopps!\n");
      set_level(19);
      set_al(-300);
      set_hp(500);
      set_wc(15);
      set_ac(9);
      move_object(clone_object("players/lew/easthall/terminal"), this_object());
   command("wield card", this_object());
   }
}  


