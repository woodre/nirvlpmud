object summoner_ob;
int is_summoned;
inherit "obj/monster";

reset(arg) {
     ::reset(arg);
     if(!arg) {
          set_name("demon");
          set_race("demon");
          set_level(19);
          set_hp(475);
          set_al(-1000);
          set_short("a demon");
          set_long("This creature from the nether regions looks to be the\n"+
                   "worst combination of ape and boar. Its tiny wings hardly\n"+
                   "look able to support its hoofed mass.\n");
          set_aggressive(1);
          set_wc(28);
          set_ac(16); }
}

init() {
     set_heart_beat(1);
     add_action("out", "out");
     ::init();
}

out() {
     if(this_player()->query_ghost()||this_player()->query_level()>39)
          return 0;
     write("The demon blocks you way!\n");
     return 1; 
}

set_summoner(ob) { summoner_ob=ob; is_summoned=1; }
query_summoner() { write(summoner_ob); write("\n"); return 1; }

heart_beat() {
     ::heart_beat();
     if(is_summoned && !summoner_ob)
          summoner_gone();
     if(is_summoned && !query_attack())
          attack_object(summoner_ob->query_attack());
     return 1;
}

summoner_gone() { call_out("self_destruct", 15); }

self_destruct() {
     say("The demon returns to the abyss.\n");
     move_object(this_object(), "room/void");
     destruct(this_object());
}