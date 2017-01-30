/**********************************************
*
*     This room is the room where Dark Ones
*     go to be resurrected.  Here they must 
*     battle the demon to reach the outside.
*     once entered the room sets the player's
*     home here until the player leaves the
*     room.  Should many die there will be more
*     demons (all based against player's level).
*     The basic thing is that the players must 
*     go through a time consuming thing.  There 
*     is one way to get through without going
*     through the demon (i.e. tricking the demon)
*
************************************************/

#include "/players/mythos/closed/guild/def.h"
inherit "room/room";

reset(arg) {
  if(!arg) {
  set_light(-1);
    short_desc = BOLD+"LIMBO"+NORM;
    long_desc =
    "You are in a small room.  The walls, ceiling and floor are all bare.\n"+
    "Here is where you must defeat a demon to return to the realm of the\n"+
    "living.  Your Fae is your weapon and your will is your shield.  \n";
  items = ({
    "out","The EXIT to the realm of the living",
  });
} }
query_death_room() { return 1; }
realm() {return "NT"; }
init() {
  ::init();
    if(this_player()->query_ghost()) {
        call_other(this_player(), "remove_ghost", 0);
        tp->heal_self(500);
        call_other(tp,"set_home","/players/mythos/closed/guild/death/death.c");
        if(!present("deathmark",tp)) { 
        move_object(clone_object("/players/mythos/closed/guild/death/ddeath.c"),tp);
        tp->save_me();}
        }
    if(present("deathmark",tp)) {
      object ob,ob2;
      int n,m;
        ob2 = present(fear,this_player());
        n = (ob2->query_fae());
        m = (call_other(tp,"query_attrib","wil"));
        tp->set_wc(n);
        tp->set_ac(m/2);
        if(tl<6) {
       ob= clone_object("/players/mythos/closed/guild/death/demon.c");
       ob->set_owner(tpn);
       ob->set_level(6);
       ob->set_wc(10);
       ob->set_ac(5);
       ob->set_hp(90);
       ob->set_chance(3);
       ob->set_spell_dam(10);
          move_object(ob,this_object());
        }
        else if(tl<10) {
        ob= clone_object("/players/mythos/closed/guild/death/demon.c");
        ob->set_owner(tpn);
        ob->set_level(10);
       ob->set_wc(14);
       ob->set_ac(8);
       ob->set_hp(150);
       ob->set_chance(5);
       ob->set_spell_dam(15);
          move_object(ob,this_object());
        }
        else if(tl<15) {
        ob= clone_object("/players/mythos/closed/guild/death/demon.c");
        ob->set_owner(tpn);
        ob->set_level(15);
       ob->set_wc(20);
       ob->set_ac(12);
       ob->set_hp(225);
       ob->set_chance(7);
       ob->set_spell_dam(20);
        move_object(ob,this_object());
        }
        else {
        ob= clone_object("/players/mythos/closed/guild/death/demon.c");
        ob->set_owner(tpn);
        move_object(ob,this_object());
        }
        }
  add_action("out","out");
  add_action("trick","kill");
}

trick(str) {
  if(str==tpn) {
    write("\nYou take out a knife and slit your wrist...\n\n"+
          "As you slowly slip into the dark depths of death\n"+
          "you see the demon peer at you.  It growls and shakes\n"+
          "its head.  Everything fades......\n");
    destruct(present("deathmark",tp));
    move_object(this_player(),"/players/mythos/closed/guild/assembly.c");
    call_other(tp,"set_home","/players/mythos/closed/guild/assembly.c");
    pp->set_ggt(0);
    tp->save_me();
    command("look",this_player());
    return 1;}
    }

out() {
  if(tp->query_ghost() != 1 && !present("deathmark",tp)) {
  call_other(tp,"set_home","/players/mythos/closed/guild/assembly.c");
  call_other(this_player(),"move_player","out#players/mythos/closed/guild/assembly.c");
  pp->set_ggt(0);
  tp->save_me();
  return 1;}
  write("DEATH'S DOOR IS CLOSED To YOU\n"); return 1;}
