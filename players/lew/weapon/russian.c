inherit "obj/weapon";
int chamber, aimed, round, pwr, hit;
static luc;
reset(arg) {
    if(!arg) {
      pwr=12;

       set_id("gun");
       set_short("A Russian Roulette gun");
       set_long("This is a Russian Roulette gun.  For instructions type\n"+
                "'help gun'.\n");
       set_class(pwr);
       set_weight(3);
       set_value(100);
       set_hit_func(this_object());
}
}


init() {
    ::init();

    add_action("spin", "spin");
    add_action("aim", "aim");
    add_action("squeeze", "squeeze");
    add_action("squeeze", "pull");
    add_action("help", "help");
}
help(str) {
    if(!str) return 0;
    if(str != "gun") return 0;
    write("This is a Russian Roulette gun.  For those who don't know\n"+
          "the object of this, I offer this simple explination.\n"+
          "You first spin the chamber, then place the gun to your head \n"+
          "and pull the trigger.  If you win, the weapon class goes up two.\n"+
          "But you must not be weilding the gun to gain wc.\n"+
          "But if you are unfortunate enough to lose......................\n"+
          "YOU DIE.\n");
    return 1;
}
spin(str) {
    if(!str) { write("Spin what?\n"); return 1; }
    if(str != "chamber") { write("Try spin chamber.\n"); return 1; }
    chamber = 1;
    write("Bzzzzzzzzzzzzzzz. Clink.\n");
    say(this_player()->query_real_name()+" spins the chamber of a gun.\n");
    round = random(60);
    return 1;
}
aim(str) {
    if(!str) { write("Aim where?\n"); return 1; }
    if(str != "head") { write("Try aim head.\n"); return 1; }
    write("Now squeeeeeeeeeze the trigger.\n");
   say(this_player()->query_real_name()+" puts the gun to his head.\n");
    aimed = 1;
    return 1;
}
squeeze(str) {
    if(!str) { write("Squeeze what?.\n"); return 1; }
    if(str != "trigger") { write("Try squeeze trigger.\n"); return 1; }
    if(chamber != 1) { write("You must spin the chamber.\n"); return 1; }
    if(aimed != 1) { write("You must aim the gun.\n"); return 1; }
    say(this_player()->query_real_name()+" pulls the trigger.\n");
    if(round > 10 ) { write("Congrats. You survived, this time.\n");
    say(this_player()->query_real_name()+" survived.\n");
   if(pwr > 20) { write("The gun is at max weapon class.  Adding return value.\n");
   hit += 1;
   return 1; }
   pwr=pwr+2;
  call_other(this_object(), "set_class", pwr);
    if(round > 0 ) round=round-round;
    if(aimed == 1) aimed=aimed-1;
    if(chamber == 1) chamber=chamber-1; return 1; }
    write("BANG!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"+
          "You lose.\n");
   say(this_player()->query_real_name()+" just comitted suicide.\n");
   call_other(this_player(), "hit_player", 1000);
   call_other(this_object(), "set_class", 14);
    pwr=14;
   if(aimed == 1) { aimed=aimed-1; }
   if(chamber == 1) {chamber=chamber-1; }
   if(round>0) { round=round-round; }
    return 1;
}
weapon_hit(attacker) {
   attacker->hit_player(hit);
   return 1;
}
