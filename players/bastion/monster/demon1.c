
object summoner_ob;
int is_summoned;
inherit "obj/monster";

reset(arg) {
     ::reset(arg);
     if(!arg) {
          set_name("vrock");
          set_alias("demon");
          set_race("demon");
          set_level(10);
          set_hp(150);
          set_al(-1000);
          set_short("a vrock");
          set_long("It is a type I demon.\n");
          set_aggressive(1);
          set_wc(14);
          set_ac(8); }
}

init() {
     ::init();
     set_heart_beat(1);
}

set_summoner(ob) { summoner_ob=ob; is_summoned=1; }
query_summoner() { write(summoner_ob); write("\n"); return 1; }

heart_beat() {
     ::heart_beat();
     if(is_summoned && !summoner_ob)
          summoner_gone();
     if(is_summoned && !query_attack()) {
          attack_object(summoner_ob->query_attack());
     }
     return 1;
}

summoner_gone() { call_out("self_destruct", 15); }

self_destruct() {
     say("The demon returns to the abyss.\n");
     move_object(this_object(), "room/void");
     destruct(this_object());
}
