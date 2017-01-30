#include "/players/softly/misc/ansi.h"
inherit "/obj/monster";

init() {
  ::init();
  add_action("story","story");
  add_action("story","tale");
}

reset(arg) {
   ::reset(arg);
   if (arg) return;

move_object(clone_object("/players/softly/winter/thcloak.c"),this_object());

   set_name("Mr. Bryant");
   set_alt_name("bryant");   
   set_alias("man");
   set_long("A grey wizened old man huddled and wrapped in ragged\n"+
            "clothing which does not protect him from the cold.\n"+
            "He may once have been strong but looks very tired.\n"+
            "He is anxious to serve you and to tell you his 'story'.\n");
   set_short("Mr. Bryant, the Shopkeeper");
   set_type("human");
   set_level(10);
   set_wc(15);
   set_ac(7);
   set_hp(150);
   set_al(0);
   add_money(15+random(26));
   set_chat_chance(5);
   load_chat("Mr. Bryant says: You may warm yourself at the fire behind my shop.\n");
   load_chat("Mr. Bryant says: When I was young this was a warm shining lake.\n");
   load_chat("Mr. Bryant says: You can rent skates if you want to cross the lake..\n");
   load_chat("Mr. Bryant says: The story of my daughter and son-in-law is terrible.\n");
   load_chat("Mr. Bryant says: Be careful.  There are wild ermine in the woods.\n");
   load_chat("Mr. Bryant says: I'll tell you my story if you ask.\n");
   set_a_chat_chance(30);
   load_a_chat("Mr. Bryant pleads: Don't hurt me!  Who will run the shop?\n");
   load_a_chat("Mr. Bryant says: I just wanted to tell my story.\n");
   load_a_chat("Mr. Bryant says: I am not the evil one.\n");
   load_a_chat("Mr. Bryant says: Who will look after my daughter?\n");

}
void catch_tell(string str)
{
    object me;
    string X;
    if(sscanf(str, "%sstory%s\n", X, X))
    { 
      me = this_player();
      if(me->is_player())    
        call_out("bstory", 2, me);
    }
}
void bstory(object asker)
{
  if(!asker) return;
  tell_object(asker, "\nMr. Bryant tells you: This was once the most beautiful spot I ever\n"+ 
                     "saw.  The fish would leap through the golden surface of the lake\n"+
                     "and you could bask in the sun or swim through summer days in cool,\n"+
                     "clear water.  After Erica came back, though, it all changed.\n\n"+
                     "After Mrs. Bryant died, I came here to make sure my daughter\n"+
                     "was safe.  I can't do much, but I always leave out meat and\n"+
                     "water for her.  I do what I can to keep the hunters away.  You\n"+
                     "aren't a hunter, are you?\n\n");
  tell_room(environment(asker), "\
Mr. Bryant whispers something to " + 
  (string)asker->query_name() + ".\n", ({ asker }));
}


/* verte added this fun */
story() {
  me=this_player();
  if(me->is_player())
   call_out("bstory", 2, me);
  return 1;
}
