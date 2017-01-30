#define TOB this_object()

inherit "/obj/monster.talk";

object ob;

void reset(int arg) {
   :: reset(arg);
   if (!arg) {
      
      set_name("wildcat");
     set_alias("graham");
      set_short("Wildcat");
     set_long("This is Wildcat.  He can find time no matter what to play\n"+
              "on the computer.  You might as well kill him too.\n");
      set_level(19);
      set_al(-1000);
      set_hp(300);
      set_wc(3);
      set_ac(15);
set_dead_ob(this_object());  /* addes by Eurale 3/29/97  */
      set_chat_chance(20);
     load_chat("Wildcat screams:  Why the hell did you do that!?\n");
     load_chat("Wildcat pounds the keyboard.\n");
    load_chat("Wildcat pouts.\n");
    load_chat("Wildcat whimpers:  He was trying to kill me.\n");
    load_chat("Wildcat rushes out of your way, his tail tucked between his leggs.\n");
    set_a_chat_chance(50);
    load_a_chat("Wildcat screams:  How can you kill me!?!?!\n");
    load_a_chat("Wildcat cries:  That's it! You're dead meat.\n");
   }
}  

monster_died() {
tell_room(environment(),
  "As he dies he screams, 'HELP ME!' and in rushes help...\n\n");
move_object(clone_object("players/lew/easthall/eric.c"),
  environment(this_object()));
return 0; }
