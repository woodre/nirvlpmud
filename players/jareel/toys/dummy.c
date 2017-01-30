#include "/players/jareel/define.h"
int hp_old,this,rnds,tot,high,avg;
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("dummy");
   set_short("A dummy");
   set_long(
      "This is a prac dummy.\n\
      By Vertebraker.\n");
   set_no_exp_value();
   set_hp(100000000); 
   hp_old = 100000000; }

heart_beat() {
   ::heart_beat();
   if(query_attack()) {
      do_math();    
      tell_room(USER,
         BOLD+BLK+"this    total    average   high    rnds\n"+NORM);
      tell_room(USER,
         HIW+pad(this,8)+pad(tot,9)+pad(avg,10)+pad(high,8)+pad(rnds,4)+"\n"+NORM);
   }
}

do_math() {
   this = hp_old - hit_point;
   hp_old -= this;
   rnds += 1;
   tot += this;
   avg = tot/rnds;
   if(this > high) high = this; }

init() {
   ::init();
   add_action("run_reset","reset"); }

run_reset() {
   if(TP->query_level() < 20) return 0;
   if(present("wiztool",TP) && attacker_ob) command("peace",TP);
   this = 0; rnds = 0; tot = 0; high = 0; avg = 0;
   tell_room(USER,"Dummy says, \"My stats have been erased.\n      Have a nice day.\"\n");
   reset();
   return 1; }
