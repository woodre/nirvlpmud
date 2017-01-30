#include "/players/fakir/color.h"
inherit "obj/monster";
int transformed;
int obj;
reset(arg) {
     ::reset(arg);
     if(!arg) {
          set_name("deceiver");
          set_alias("changeling");
          set_race("spirit");
          set_al(-600);
          set_short(YELLOW+"A Deceiver"+OFF);
          set_long(
             "Also known as a 'changeling', deceivers are the last of a race known\n"+
             "as the Imdahu, an evil mountain people.  They often sacrificed their\n"+
             "children to the Dark One for secret and powerful magics and spells.\n"+
             "Some, like this one, entered the Ways to seek even darker magics.\n");
          set_level(18);
          set_hp(450);
         move_object(clone_object("/players/fakir/ways/OBJ/flesh.c"),
         (this_object()));
          set_wc(26); 
          set_wc_bonus(25);
          set_heart_beat(1);
          set_ac(15);
          set_aggressive(0);
          set_chat_chance(15);
          load_chat(BOLD+YELLOW+"The deceiver circles you looking for a weakness."+OFF+"\n");
          load_chat(BOLD+YELLOW+"The deceiver watches with pale bloodless eyes."+OFF+"\n");
          load_chat(BOLD+BLUE+"The deceiver rasps: 'Light...the light...so bright...so hurting..."+OFF+"\n"); 
          load_chat(BOLD+BLUE+"The deceiver rasps: 'Darkness hides...darkness good...light will bring IT..IT sees the light..."+OFF+"\n");
          set_a_chat_chance(20);
          load_a_chat(BOLD+YELLOW+"The changeling  ^S U C K S^  the air from your lungs."+OFF+"\n");
          load_a_chat(BOLD+CYAN+"The changeling  ^E N G U L F S^  you in darkness."+OFF+"\n");
          load_a_chat(BOLD+BLUE+"The changeling rasps: 'So long...so very long...so empty...so alone.."+OFF+"\n");
          load_a_chat(BOLD+BLUE+"The changeling rasps: 'Emptyness...darkness...so dark...I hates the light...IT will come..."+OFF+"\n");
          load_a_chat(BOLD+BLUE+"The changeling rasps: 'IT will sees the light...darkness protects...darkness...darkness..."+OFF+"\n");
}
}

init() {
     
     ::init();
     return 1;
}

heart_beat() {
     if(!transformed && this_object()->query_attack()) {
          say(BOLD+WHITE+"The deceiver begins to shimmer and  ^E * X * P * A * N * D^..."+OFF+"\n");
          begin_transform(); }
     if(transformed && !this_object()->query_attack()) {
          say(BOLD+WHITE+"THE CHANGELING  ^s-h-r-i-n-k-s^  BACK UPON ITSELF."+OFF+"\n");
          transformed=0;
          reset(); }
     ::heart_beat();
     return 1;
}

begin_transform() { call_out("transform", 2); }

transform() {
     say(BOLD+WHITE+"The deceiver sucks in the darkness and expands ten-fold."+OFF+"\n");
     set_short("A Changeling");
     transformed=1;
     return 1;
}
