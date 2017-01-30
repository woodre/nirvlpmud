#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;
move_object(clone_object("/players/softly/point/obj/bwand.c"),this_object());   
   set_name("erica");
   set_alt_name("erica");   
   set_alias("erica");
   set_long("\
A tall winsome young woman, her dark wavy hair largely\n\
hidden by a dark blood red cloak appears suddenly.  Her\n\
black eyes contain a fire.  Her long thin fingers hold\n\
a bright blue rod that crackles with energy. She must\n\
have a 'story'.\n");
   set_short("Erica");
   set_race("mage");
   set_level(20);
   set_wc(30);
   set_ac(17);
   set_hp(800);
   set_al(-500);
   set_aggressive(1);
   add_money(15+random(60));
   set_dead_ob(this_object());
   set_a_chat_chance(20);
   load_a_chat(HIB+"\n\
          *                *\n\
        *   *            *   *\n\
      *  "+HIW+" z"+HIB+"   *        * "+HIW+"  z"+HIB+"   *\n\
        *   *            *   *\n\
          *                *\n\n"+NORM);
   load_a_chat(HIB+"\n\
      ~~~~~~~~~\n\
"+HIW+"               z\n\
"+HIB+"                ~~~~~~~~~\n\
"+HIW+"                         z\n\
"+HIB+"                          ~~~~~~~~~\n"+NORM);
   set_chance(20);
   set_spell_dam(50);
   set_spell_mess1("The "+HIB+"blue wand"+NORM+" crackles as "+BOLD+HIW+"lightning "+NORM+"flies out.");
   set_spell_mess2("\n\n\The "+HIB+"blue wand"+NORM+" crackles as "+BOLD+HIW+"lightning "+NORM+"flies out and smashes into you.\n");
}
void catch_tell(string str)
{
    object me;
    string X;
    if(sscanf(str, "%sstory%s\n", X, X))
    { 
      me = this_player();
      if(me->is_player())    
        call_out("dstory", 2, me);
    }
}
void dstory(object asker)
{
    if(!asker) return;
    tell_object(asker, "\n\
Erica rages: 'This used to be a wonderful place.  I grew up in the\n\
lighthouse and played with Daniel and Tess.  But during the year I\n\
went to study with Aunt Marie everything changed.  I went to the\n\
other side of the erlogarth to work while they played only with each\n\
other.  And my parents didn't even bother to take care of my room.\n\n\
It is good that Aunt Marie and her friends taught me what I needed\n\
to know.  Daniel and Tess can stay that way.  They are lucky they\n\
aren't frozen too, after all we meant to each other.\n\n\
I know what they say about me.  In the village they say I am a devil.\n\
I am just here helping Aunt Marie take her rightful place now that she\n\
has come here to live.  Once they understand that it is she who must\n\
be worshiped and praised, there will again be peace in this place.\n\n");
    tell_room(environment(asker), "\
Erica whispers in quiet rage to " + (string)asker->query_name() + ".\n", ({ asker }));
}

monster_died(){
  write_file("/players/softly/logs/point",
  ctime(time())+": "+this_object()->query_attack()->query_name()+" [L "+this_object()->query_attack()->query_level()+
  "+"+this_object()->query_attack()->query_extra_level()+"] killed Erica.\n");
}
