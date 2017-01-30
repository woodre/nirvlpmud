/**********************************************************/
/* ac 1 weight 1                                          */
/* Will summon bugs during combat to aid the owner.       */
/* 1 in 10 chance if int stat is at 20.                   */
/* Each bug will dest in 15-25 seconds.                   */
/* 1 in 2500 chance of going non-store                    */
/**********************************************************/

#include <ansi.h>
inherit "obj/armor";
int am;

reset(arg){
  ::reset(arg);
  if(arg) return;  /* ???WTF??? -grr */

  am = 0; /* storable */
  set_name("crystal ring");
  set_value(1225);
  set_weight(1);
  set_ac(1);
  set_type("ring");
}

long(){
  write(
"This is a unique ring.  It has a gold band, with a large, flat crystal\n"+
"on the top.  Etched into the crystal is the image of a black bug.\n");
  if(am)
    write("There is a strange flaw visible in the surface of the ring.\n");
}

short(){
  if(worn){
    if(am)
      return "A "+BOLD+BLK+"flawed "+NORM+HIW+"crystal"+NORM+" ring with a "+
      BOLD+BOLD+"black"+NORM+" bug (worn)";
    else
      return "A "+HIW+"crystal"+NORM+" ring with a "+BOLD+BOLD+
      "black"+NORM+" bug (worn)";
  }
  else {
    if(am)
      return "A "+BOLD+BLK+"flawed "+NORM+HIW+"crystal"+NORM+" ring with a "+
      BOLD+BOLD+"black"+NORM+" bug";
    else
      return "A "+HIW+"crystal"+NORM+" ring with a "+BOLD+BOLD+"black"+
    NORM+" bug";
  }
}

id(str){
  return str=="ring" ||
         str=="crystal ring" ||
         str=="bug ring" ||
         str=="crystal bug ring";
}

query_save_flag(){ if(am) return 1; else return 0; }

do_special(owner)
{
  object att, bug;
  if(random(2501) == 777)
    am = 1;
  if(!owner || !owner->query_attack()) return 0;
  if(!owner->is_player()) return 0;
  att = owner->query_attack();
  if(owner->query_attrib("int") > random(200) && att->query_npc())
  {
    tell_room(environment(owner),  owner->query_name()+
	  "'s ring glows as a bug emerges from it!\n");
    bug = clone_object("/players/zeus/museum/NPC/bug.c");
    move_object(bug, environment(owner));
    bug->attack_object(att);
    if(owner->query_spell_point() > 0)
      owner->add_spell_point(-15);
    else
    {
      owner->add_hit_point(-15);
      if(owner->query_hp() < 1)
        owner->hit_player(666);
    }
  }
  return 0;
}
