/*
Change log:
  9/2/01 Added dodging/riposting, and opponent switching to make this monster more
         difficult.  The loot it carries is unusually rich for its current difficulty. 
         These changes are in terms of 'intelligence' rather than in stats because I
         felt Julius Caesar would probably fight smarter instead of tougher.
         Also, added a chance of a centurion coming to Caesar's rescue.
         -Feldegast
*/

#include "/obj/ansi.h"

inherit "obj/monster";

int cent;

reset(arg){
        object ob1, ob2, ob3 ,gold;
        ::reset(arg);
        cent = 1;
   if(arg) return;
        set_short( "Giulius Caesar, the Emperor") ;
        set_long("He is an elderly man but he seems to be very powerful.\n") ;
        set_name ("giulius") ;
        set_gender( "male") ;
        set_alias( "caesar" );
        set_level(20);
        set_hp(510);
        set_al(0);
        set_wc(30);
        set_ac(17);
        if(random(2)) set_aggressive(1);
        if(random(2)) set_whimpy();
        set_race("human") ;
        set_chat_chance (20);
        load_chat("Giulius says: 'The die is cast!'\n");
        load_chat("Giulius mumbles: 'They want to kill me!'\n");
        load_chat("Giulius says: 'Damn Gauls! I want to destroy them.'\n");
        gold=clone_object("obj/money");
        gold->set_money(800 + random(400));
        move_object(gold,this_object());
        ob3 = clone_object ("/players/hurtbrain/castello/dag/crown") ;
        move_object(ob3,this_object());
        ob1 = clone_object ("/players/hurtbrain/castello/dag/tunic") ;
        move_object(ob1,this_object());
        ob2 = clone_object ("/players/hurtbrain/castello/dag/giul_sword") ;
        move_object(ob2,this_object());
}

hit_player(x) {
  if(x > 0 && !random(4))
  {
    if(!random(2))
      tell_room(environment(), "Giulius parries!\n");
    else
      tell_room(environment(), "Giulius dodges!\n");
    if(this_player() && this_player()!=this_object() && !random(3))
    {
      tell_room(environment(), HIR+"Giulius ripostes!\n"+NORM);
      this_player()->hit_player(30);
    }
    return 0;
  }
  else
    return ::hit_player(x);
}

heart_beat()
{
  object temp;
  ::heart_beat();
  if(attacker_ob && alt_attacker_ob && attacker_ob != alt_attacker_ob && !random(20))
  {
    temp=attacker_ob;
    attacker_ob = temp;
    alt_attacker_ob = temp;
    tell_room(environment(), "\nGiulius switches opponents!\n\n");
  }
  if(attacker_ob && cent && !random(200))
  {
    temp = clone_object("/players/hurtbrain/castello/dag/centurion.c");
    move_object(temp, environment());
    temp->attacked_by(attacker_ob);
    tell_room(environment(), "\nA centurion bursts into the room and defends his Emperor!\n\n");
    cent = 0;
  }
}

