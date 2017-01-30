
inherit "obj/monster";

reset(arg) {
     object daemon;
     ::reset(arg);
     if(!arg) {
          set_name("daemon");
          set_alias("familiar");
          set_race("daemon");
          set_short("A daemon");
          set_long(
               "It is a large creature (six feet), with blue skin and large\n"+
               "bat-like wings. You recall mages typically use such creatures"+
               "\nas servants. A small key hangs on a chain about its neck.\n");
          set_ac(21);
          set_wc(38);
          set_level(24);
          set_hp(800);
          set_chat_chance(35);
          load_chat("Daemon says: Who are you?\n");
          load_chat("Daemon says: What are you doing here?\n");
          set_a_chat_chance(5);
          load_a_chat("Daemon says: You shall pay for this!\n");
          load_a_chat("The daemon lashes at your throat with it's "+
               "claws.\n");
          set_chance(25);
          set_spell_dam(10 + random(15));
          set_spell_mess2("The daemon casts a magic missile at you.");
          set_spell_mess1("The daemon casts a magic missile."); }
}

heart_beat() {
     ::heart_beat();
     if(this_object()->query_attack()) {
          if(random(100) < 25) 
               if(!present("demon 4", environment(this_object())))
                    gate_demon();
     }
}

gate_demon() {
     object demon, you;
     string type;
     int x;
     type=allocate(4);
     type[3]="players/bastion/monster/demon4";
     type[2]="players/bastion/monster/demon3";
     type[1]="players/bastion/monster/demon2";
     type[0]="players/bastion/monster/demon1";
     x=random(4);
     demon=clone_object(type[x]);
     demon->set_summoner(this_object());
     you=this_object()->query_attack();
     say("The daemon gates in a demon!\n");
     say("A demon steps from a sulfurous cloud.\n");
     move_object(demon, environment(this_object()));
     demon->attacked_by(you);
     you->attack_object(demon);
     return 1;
}

self_destruct() {
     if(this_object()->query_attack()) return 1;
     say("The daemon disappears in a puff of blue smoke.\n");
     move_object(this_object(), "players/bastion/room/void");
     destruct(this_object());
     return 1;
}
     
