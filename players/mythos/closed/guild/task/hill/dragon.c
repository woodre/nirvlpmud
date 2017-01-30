#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("dragon");
set_race("dragon");
  set_short(RED+"DRAGON"+NORM);
  set_long("A Massive Dragon sits before you.\n"+
           "Only it knows the correct portal to which\n"+
           "the Spear of Drafnor can be found....\n");
  set_hp(2000);
  set_level(30);
  set_al(-1000);
  set_wc(60);
  set_ac(20);
  set_heal(5,20);
  set_dead_ob(this_object());
  set_a_chat_chance(10);
  load_a_chat("The Dragon lashes out!!\n");
  load_a_chat("The Dragon strikes with blinding speed!\n"); 
  set_chance(40);
  set_spell_dam(60);
  set_spell_mess1(HIR+"\n>  >  > > >>> BLAZE <<< < <  <  <\n\n"+NORM);
  set_spell_mess2(HIR+"\n>  >  > > >>> BLAZE <<< < <  <  <\n\n"+NORM);
  set_mult(4);
  set_mult_chance(40);
  set_mult_dam1(10);
  set_mult_dam2(20); 
  call_out("checks",5);
}

checks() {
  if(this_object()->query_attack()) {
    if((this_object()->query_attack()) == this_object()) {
      this_object()->stop_fight();
      this_object()->heal_self(1000);
    }
  }
call_out("checks",5);
return 1;}


monster_died() {
string dir, opp;
  switch(random(8)) {
    case 0: dir = "/players/mythos/closed/guild/task/hill/stones.c"; 
            opp = "south";
            break;
    case 1: dir = "/players/mythos/closed/guild/task/hill/stones2.c"; 
            opp = "southwest";
            break;
    case 2: dir = "/players/mythos/closed/guild/task/hill/stones3.c"; 
            opp = "west";
            break;
    case 3: dir = "/players/mythos/closed/guild/task/hill/stones4.c"; 
            opp = "northwest";
            break;
    case 4: dir = "/players/mythos/closed/guild/task/hill/stones5.c"; 
            opp = "north";
            break;
    case 5: dir = "/players/mythos/closed/guild/task/hill/stones6.c"; 
            opp = "northeast";
            break;
    case 6: dir = "/players/mythos/closed/guild/task/hill/stones7.c"; 
            opp = "east";
            break;
    case 7: dir = "/players/mythos/closed/guild/task/hill/stones8.c"; 
            opp = "southeast";
            break;
    }
    tell_room(environment(this_object()),"The Dragon screams in pain!\n"+
                "\tIt thrashes about....\n"+
                "\t\tThen.... It falls...\n"+
                "\t\t\tYou hear it whisper with its last breath: "+opp+"\n");
    move_object(clone_object("/players/mythos/closed/guild/task/hill/spear.c"),dir);
return 0; }
