int timer;
inherit "obj/monster.c";


reset(arg) {
   ::reset(arg);
    if(arg) return;
    timer = 0;
}

heart_beat() {
   ::heart_beat();
   if(timer > 2) hit_player(10000);
    else timer++;
}
