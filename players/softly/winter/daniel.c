#include "/players/softly/misc/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
move_object(clone_object("/players/softly/winter/caxe.c"),this_object());  

   set_name("daniel");
   set_alt_name("Daniel");   
   set_alias("dan");
   set_long("A tall handsome man, his dark hair pushed away from his\n"+
            "face, dominates the small room.  He is strong but a far\n"+
            "away look in his eyes makes you think he has a story to tell.\n");
   set_short("Daniel");
   set_type("human");
   set_level(20);
   set_wc(30);
   set_ac(17);
   set_hp(500);
   set_al(0);
   set_aggressive(0);
   add_money(15+random(60));
   set_a_chat_chance(10);
   load_a_chat("Daniel shouts: How dare you attack me?\n");
   load_a_chat("Daniel cries: What evil have you brought to my home?\n");
   set_chance(15);
   set_spell_dam(35);
   set_spell_mess1("The axe rips a " + HIR + "bloody" + NORM + " tear through flesh.\n");
   set_spell_mess2("The axe rips a " + HIR + "bloody" + NORM + " tear through your flesh.\n");
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
    tell_object(asker, "\
Daniel tells you: 'Tess and I were children together.  This was\n\
a beautiful place.  We swam and ran through the woods singing and\n\
chasing butterflies with our friend Erica.  When we got older Tess\n\
and I fell in love.  But Erica didn't want that.  She wanted both\n\
of us for herself.\n\n\
After about a year Erica went away to live with her relatives on the\n\
other side of the world.  Tess and I married and built this cottage\n\
one board at a time.  We looked out at the lake and thought about our\n\
children that would one day swim there.\n\n\
Then Erica returned.  She appeared at our doorstep enraged, demanding\n\
that we follow her.  We held each other and refused.  She reached into\n\
her bag, withdrew a strange bluish wand, and waved it while chanting.\n\
Since that day everything has been frozen.  And my beloved Tess waits\n\
outside the door for the day we can again be together as we once were.\n\n");
    tell_room(environment(asker), "\
Daniel whispers something to " + 
(string)asker->query_name() + ".\n", ({ asker }));
}
