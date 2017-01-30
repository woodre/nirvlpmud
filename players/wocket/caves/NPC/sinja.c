#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
  ::reset();
  if(arg) return 1;
set_name(HIB+"Sinja"+NORM);
set_alt_name("sinja");
set_alias("worm");
set_short(HIB+"The dreaded Sinja worm"+NORM);
set_long("This is the dreaded Sinja worm.  It has seven heads that split off from\n"+
         "it's tail like body.  The heads swirl and twist around each other with\n"+
         "great speed.  There are no eyes on this creature.  It's heads would be\n"+
         "just mouths if it where not for two slits for breathing.  The mouths are\n"+
         "filled with jagged teeth ready to tear into anything they touch.  The\n"+
         "Sinja's skin is made of bright blue scales that seem almost impenitrable.\n");
set_level(40);
set_hp(1500);
set_wc(70);
set_ac(40);
set_heal(50,5);
set_dead_ob(this_object());
set_a_chat_chance(30);
load_a_chat(HIR+"Fire flares from the mouths of Sinja.\n"+NORM);
load_a_chat(HIR+"Your body is covered with burns as Sinja blows fire upon you.\n"+NORM);
load_a_chat("You shiver in fear.\n");


}


heart_beat(){
int a,i;
::heart_beat();
if(attacker_ob && present(attacker_ob,environment(this_object()))){
i = random(7);
for(a=0;a<i;a++){
    already_fight = 0;
    this_object()->attack(attacker_ob);
}
}
}

monster_died(){
    if(present("corpse",environment(this_object()))){
      destruct(present("corpse",environment(this_object())));
  move_object(clone_object("/players/wocket/caves/OBJ/sinja_corpse.c"),environment(this_object()));
    }
write_file("/players/wocket/closed/log/CAVES","sinja - "+attacker_ob->query_real_name()+" "+attacker_ob->query_level()+" - "+ctime()+"\n");
return 1;
}
query_sinjaworm(){ return 1; }
