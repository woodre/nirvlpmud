#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";
int toomany;
reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;
set_no_clean(1);
set_name("The Golden Snitch");
set_alias("snitch");
set_race("ball");
set_short(HIY+"~"+HIW+"o"+HIY+"~"+NORM);
set_long(
  "  This is a small golden ball with smooth grooves and etchings\n"+
  "along its surface.  It might fit easily in the palm of your\n"+
  "hand if it wasn't moving so fast on buzzing silver wings.\n");
set_dead_ob(this_object());
set_level(1);
set_hp(80);
set_al(0);
set_wc(0);
set_ac(30);
set_death_emote("The Snitch has been caught!");
msgout = "flies";
no_exp_value = 1;
}

long(){ 
  write(
  "  This is a small golden ball with smooth grooves and etchings\n"+
  "along its surface.  It might fit easily in the palm of your\n"+
  "hand if it wasn't moving so fast on buzzing silver wings.\n");
return 1; 
}

random_move()
{
    string croom;
    int n;
    
    if(!environment()) return;
    if(toomany > 8){
     tell_room(environment(), "The Golden Snitch flies out.\n");
     move_object(this_object(), "room/vill_green");
     toomany = 0;
     }
    toomany += 1;
    croom = file_name(environment());
    n = random(4);
    if (n == 0)      command("west");
    else if (n == 2) command("east");
    else if (n == 3) command("south");
    else if (n == 4) command("north");
    if(croom == file_name(environment())){    
    n = random(6);
    if (n == 0) command("northeast");
    else if (n == 1) command("northwest");
    else if (n == 2) command("southeast");
    else if (n == 3) command("southwest");
    else if (n == 4) command("out");
    else if (n == 5) command("exit");
    }
    if(croom == file_name(environment())) random_move();   
    toomany = 0;
}

query_hbflag(){ return "hbstayon"; }

heart_beat(){ 
  if(!environment()) return;
  if(!random(4) && hit_point < 80) heal_self(1);
  if(random(2)) random_move();
  if(!random(10)) random_move();
  random_move();
  }

monster_died() {
  object corpse;
  corpse = present("corpse", environment()); 
  tell_room(environment(),
  "The wings of the Snitch slide back into the ball and it lies\n"+
  "dormant on the ground.\n");       
  move_object(clone_object("/players/maledicta/closed/snitch_ob.c"),
      environment());
 if(corpse)
    destruct(corpse);
return 1; }


query_limited_shadow(){ return 1; }
