
inherit "obj/monster";
int transformed;

reset(arg) {
     ::reset(arg);
     if(!arg) {
          set_name("chicken");
          set_alias("magic chicken");
          set_race("chicken");
          set_level(2);
          set_ep(1014);
          set_hp(60);
          set_al(0);
          set_short("a chicken");
          set_long("Its your average insipient, clucking chicken.\n");
          set_aggressive(0);
          set_wc(4);
          set_ac(3); 
          set_chat_chance(20);
          load_chat("The chicken looks at you.\n");
          load_chat("The chicken begins pecking at some grain.\n"); 
          set_a_chat_chance(10);
          load_a_chat("The chicken pecks at you.\n"); }
}

init() {
     set_heart_beat(1);
     ::init();
     return 1;
}

heart_beat() {
     if(!transformed && this_object()->query_attack()) {
          say("Suddenly, the chicken undergoes a transformation...\n");
          begin_transform(); }
     if(transformed && !this_object()->query_attack()) {
          say("The chicken returns to its normal size.\n");
          transformed=0;
          reset(); }
     ::heart_beat();
     return 1;
}

begin_transform() { call_out("transform", 2); }

transform() {
     say("The chicken towers above you!\n");
     this_object()->set_short("a giant chicken");
     this_object()->set_level(10);
     this_object()->set_ep(90000);
     this_object()->set_hp(200);
     this_object()->set_wc(12);
     this_object()->set_ac(5);
     transformed=1;
     return 1;
}
