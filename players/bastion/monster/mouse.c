
inherit "obj/monster";
int transformed;

reset(arg) {
     ::reset(arg);
     if(!arg) {
          set_name("mouse");
          set_alias("magic mouse");
          set_race("mouse");
          set_level(2);
          set_ep(1014);
          set_hp(60);
          set_al(0);
          set_short("a mouse");
          set_long("It is a small and highly dextrous creature.\n");
          set_aggressive(0);
          set_wc(4);
          set_ac(3); 
          set_chat_chance(20);
          load_chat("The mouse looks at you.\n");
          load_chat("The mouse begins gnawing on a sack of grain.\n"); 
          set_a_chat_chance(10);
          load_a_chat("The mouse squeaks angrily.\n"); }
}

init() {
     set_heart_beat(1);
     ::init();
     return 1;
}

heart_beat() {
     if(!transformed && this_object()->query_attack()) {
          say("Suddenly, the mouse undergoes a transformation...\n");
          begin_transform(); }
     if(transformed && !this_object()->query_attack()) {
          say("The mouse returns to its normal form.\n");
          transformed=0;
          reset(); }
     ::heart_beat();
     return 1;
}

begin_transform() { call_out("transform", 2); }

transform() {
     say("The mouse towers above you!\n");
     this_object()->set_short("a giant mouse");
     this_object()->set_level(10);
     this_object()->set_ep(90000);
     this_object()->set_hp(200);
     this_object()->set_wc(12);
     this_object()->set_ac(5);
     transformed=1;
     return 1;
}

get () { return 1; }
