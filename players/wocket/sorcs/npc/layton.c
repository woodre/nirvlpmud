#include "defs.h"

inherit "obj/monster.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("layton");
  set_alias("mageborn");
  set_short("Layton Mageborn");
  set_long(
"Layton Mageborn is a man of indeterminate age, and neat\n\
appearance.  He wears a rich purple robe embroidered with\n\
golden thread.  He appears bored, and disinterested in your\n\
presence.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(14);
  set_hp(200);
  set_wc(19);
  set_ac(10);
  set_al(300);
  set_a_chat_chance(20);
  load_a_chat("Layton casts a "+BOLD+"MAGIC MISSILE"+NORM+"!\n");
  load_a_chat("Layton sprays his opponent with "+RED+"FIRE DARTS"+NORM+"!\n");
  load_a_chat("You are struck by an unseen force!\n");
  load_a_chat("Layton gestures franticly as he mutters an incantation.\n");
  load_a_chat("Layton's spell fails.\n");
  move_object(clone_object("/players/feldegast/equip/boots2.c"),this_object());
  move_object(clone_object("/players/feldegast/equip/p_robe.c"),this_object());
}

void init()
{
  call_out("hell",1);
}

void long(string str)
{
  ::long(str);
  call_out("hello",2);
}

void hell()
{
  say("Layton looks up from the book he was reading.\n");
}

void hello()
{
    say("Layton says: Greetings, adventurer.  Although we mostly sell stuff\n"+
        "             for those who have mastered the craft of magic, there\n"+
        "             are a few items which you may find of use.  You may ask\n"+
        "             me for a 'list' of what we sell.\n");
}

void book()
{
  say("Layton smiles at you and says, \"Nothing that would interest YOU, I'm sure.\"\n");
}

void catch_tell(string str)
{
  string a,b;
  if(sscanf(str,"%slist%s",a,b)==2)
  {
    environment()->list();
    return;
  }
  if(sscanf(str,"%shello%s",a,b)==2)
  {
    call_out("hello",2);
    return;
  }
  if(sscanf(str,"%sbook%s",a,b)==2)
  {
    call_out("book",2);
    return;
  }
}

