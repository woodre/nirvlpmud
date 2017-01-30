#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

int x, NAME_ME;
reset(arg)  {
   ::reset(arg);
   if(arg) return;
NAME_ME = "nameless";
   
   set_name("lingering spirit");
   set_alias("spirit");
   set_alt_name("linger");
   set_race("spirit");
   set_light(2);
   set_level(25);
   set_hp(950+random(251));
   set_al(-1000);
   set_ac(20+random(9));
   set_aggressive(0);
   set_wc(30+random(19));
   set_ac_bonus(30);
   set_wc_bonus(100);
   set_dead_ob(this_object());
   set_a_chat_chance(15);
   load_a_chat("Lingering Spirit slides across the floor!\n");
   set_chat_chance(15);
   load_chat("Souls scream from inside the Spirit.\n");
   load_chat("A wave of cold air rushes past you.\n");
   load_chat("Souls scream from inside the Spirit.\n");
}
short(){ return ""+HIW+"Lingering Spirit"+BLK+BOLD+" ("+HIW+""+NAME_ME+""+BLK+BOLD+")"+NORM+""; }
long(){
       write("A wavering form of an unknown creature.  The spirit\n"+
             "floats silently, a mass of huge proportion.  The\n"+
             "face of "+NAME_ME+" seems to show itself at random\n"+
             "areas of the spirit's form.  A bright, white light\n"+
             "illuminates the body of the spirit.  Globes of lost\n"+
             "souls can be seen, floating throughout the spirit.\n");
}

monster_died() {
  string tname;

  tname = (this_player() ? this_player()->query_name() : "Unknown: "+object_name(previous_object()));
   tell_room(environment(this_object()),
     "The spirit fades to nothingness.\n");
   x = present("corpse",environment(this_object()));
   destruct(x);
   MOCO("/players/jaraxle/3rd/pyramid/items/myst_cloak.c"),environment());
write_file("/players/jaraxle/3rd/pyramid/s_kill.log",ctime(time())+" "+BLK+BOLD+""+tname+""+NORM+" killed "+HIW+"Lingering Spirit"+NORM+".\n");
return 0; }


hurt_me(){

string ATT_NAME;
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();

    say(HIW+"\nThe Lingering Spirit passes itself through "+ATT_NAME+"'s body.\n"+
        "A cold chill freezes over you!\n\n"+NORM);

    attacker_ob->add_hit_point(-20-random(21)); }
}

kill_me(){

string ATT_NAME;
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();

    say(HIW+HBRED+"\nLingering Spirit reaches into "+ATT_NAME+"'s chest...\n"+
        "Lingering Spirit squeezes "+ATT_NAME+"'s heart!\n"+NORM);
    attacker_ob->add_hit_point(-101-random(176));
    attacker_ob->hit_player(15);
}
}

heal_me(){

    say(BLK+BOLD+"\nLingering Spirit absorbs some of the darkness.\n"+NORM);
    this_object()->heal_self(20+random(21));
}

eat_me(){
  object blah;
  blah=present("corpse");
  if(blah) {
  move_object(blah,this_object());
  NAME_ME = ""+capitalize(blah->query_name())+"";
  say("Lingering Spirit swarms over "+blah->short()+"\n");
  say("The Lingering Spirit absorbs the corpse whole!\n");
  destruct(blah);
  }
     this_object()->heal_self(5+random(6));
}

eat_me2(){
  object blah;
  blah=present("corpse");
  if(blah) {
  move_object(blah,this_object()); 
  NAME_ME = ""+capitalize(blah->query_name())+"";
  say("The Lingering Spirit raises "+blah->short()+" into the air...\n");
  say("Lingering Spirit slowly drops the corps into it's mists!\n");
  destruct(blah);
  }
     this_object()->heal_self(1+random(2));
}

heart_beat(){
int i;
  ::heart_beat();
if(!attacker_ob){
x = random(2);
switch(x){

    case 0: eat_me();
  break;
    case 1: eat_me2();
    }
  }
if(attacker_ob){
i = random(16);
switch(i){

    case 0..3: hurt_me();
  break;

    case 4..5: kill_me();
  break;

    case 6..10: heal_me();
  break;
   
    case 11..15: return 0;
  break;
    }
  }
}

