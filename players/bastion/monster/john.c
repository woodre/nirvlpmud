
inherit "obj/monster";

reset(arg) {
     object money;
     ::reset(arg);
     if(!arg) {
          set_name("john");
          set_race("insect");
          set_level(5);
          set_hp(75);
          set_al(-100);
          set_short("John");
          set_long("He looks pretty untrustworthy. Better stay away.\n");
          set_aggressive(0);
          set_wc(9);
          set_ac(5); 
set_chat_chance(15);
load_chat("John says: I'm really an asshole.\n");
load_chat("John says: Please kill me. I know I deserve it.\n");
load_chat("John begs for your forgiveness.\n");
load_chat("John looks shiftily about the room.\n");
          set_dead_ob(this_object());
          }
}

monster_died ( ob ) {
   say("John gasps: I'm so sorry. I deserve to die...\n");
}

init () {
   set_heart_beat(1);
   ::init();
}
