
object summoner_ob;
string temp;
int is_summoned;
inherit "obj/monster";

reset(arg) {
     ::reset(arg);
     if(!arg) {
          temp="Bastian";
          if(!summoner_ob)
               summoner_ob=find_player("bastion");
          set_name("demonic pig");
          set_alias("pig");
          set_race("guild_monster");
          set_level(20);
          set_al(-1000);
          set_short("A demonic pig, circling "+temp+"'s head");
          set_long("It is definately NOT a cow.\n");
          set_aggressive(0);
          set_wc(20);
          set_ac(15); }
}

init() {
     ::init();
     set_heart_beat(1);
}

set_summoner(str) {
     summoner_ob=find_player(str);
     temp=summoner_ob->query_name();
     is_summoned=1;
     set_short("A demonic pig, circling "+temp+"'s head");
}
query_summoner() { write(summoner_ob); write("\n"); return 1; }

heart_beat() {
     ::heart_beat();
     if(is_summoned && !summoner_ob)
          summoner_gone();
     if(is_summoned && !query_attack() && summoner_ob->query_attack()) {
          tell_room(environment(this_object()), "Demonic pig says: " +
            "Hey, stop that!\n");
          if(!(summoner_ob->query_attack())->is_player())
          attack_object(summoner_ob->query_attack());
     }
     if(!present(summoner_ob)) {
          say("The demonic pig does an aerial loop and flies after "+temp+".\n");
          tell_object(summoner_ob,
            "\nA voice chimes in your head: Hey! Wait for me! *snort*\n");
          move_object(this_object(), environment(summoner_ob));
          say("\nA demonic pig swoops into the room.\n");
     }
     return 1;
}

summoner_gone() { call_out("self_destruct", 15); }

self_destruct() {
     say("The demon returns to the abyss.\n");
     move_object(this_object(), "room/void");
     destruct(this_object());
}
is_npc() { return 0; }
