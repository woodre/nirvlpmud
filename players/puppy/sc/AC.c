#include "/players/puppy/define.h"
inherit "obj/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("advancement chairman");
   set_alias("advancement chair");
   set_alias("chairman");
   set_alias("man");
   set_alias("ac");
   set_alias("AC");
   set_alias("scout");
   set_race("human");
   set_short("The Advancement Chairman");
   set_long(
      "A tall broad shouldered man stands before you blankly looking\n"+
      "into the sky.   An earlier call in the day has left his turnout\n"+
      "gear and helmet even more battered then it was when he started\n"+
      "the day.  His face, soiled with dirt, has a thin clear trail\n"+
      "from his right eye down past his chin.  His knuckles have\n"+
      "turned white from holding a second helmet so tight.  You might\n"+
      "be able to 'ask' the fireman about what he knows.\n");
   
   set_level(1000);
   set_hp(999999999);
   set_al(600);
   set_wc(18);
   set_ac(50);
   set_aggressive(0);
}

init()
{add_action("aask", "ask"); }

aask(str) {
   if(str == "fireman about ribbon") {
      write("The fireman pins a ribbon to your chest.  He looks down at you\n"+
         "and smiles.  He says, 'Never forget the fallen my friend!'\n");
      if(!present("ribbon",this_player())) 
         move_object(clone_object("/players/puppy/mem/ribbon.c"),this_player());
      return 1;
}

   if(str == "fireman about flag") {
      write("The fireman hands you a flag.\n"+
         "He says: 'Never forget what this means!'\n");
      if(!present("flag",this_player()))
         move_object(clone_object("/players/vertebraker/misc/amer_flag.c"),this_player());
      return 1;
   }

   if(str == "fireman") {
      write("The fireman says: You may ask me about the 'brotherhood' I\n");
      write("have known over the years, the 'flag' or the 'ribbon' I wear.\n"); 
      return 1;
   }

   if(str == "fireman about brotherhood") {
      call_out("say_prayer1",1);
      call_out("say_prayer2",6);
      call_out("say_prayer3",23);
      call_out("say_prayer4",31);
      call_out("say_prayer5",39);
      call_out("say_prayer6",47);
      call_out("say_prayer7", 55);
      call_out("say_prayer8", 66);
      return 1;
   }
else if(!str) {
      write("You would like to 'ask' 'who' 'about what'\n");
   return 1;
}

}   
say_prayer1() 
{
   say("The fireman glances at you.\n"+
      "\n");
   return 1;
}

say_prayer2()
{
   say("Yes, I can tell you about what I do.  One must dedicate something much\n");
   say("bigger then themselves to know how we live.  Our kind are very close\n");
   say("and when we lose a brother or sister we all feel so much pain.  We ask\n");
   say("for nothing more then a minute of your time to honor our fallen ones\n");
   say("and their family.\n");
   say("\n");
   return 1;
}

say_prayer3()
{
   say("\t When I am called to duty god\n"+
      "\t whenever flames may rage\n"+
      "\t give me strength to save a life\n"+
      "\t whatever be it's age\n"+
      "\n");
   return 1;
}

say_prayer4()
{
   say("\t Help me to embrace a little child\n"+
      "\t before it is to late\n"+
      "\t or save an older person from\n"+
      "\t the horror of that fate\n"+
      "\n");
   return 1;
}

say_prayer5()
{
   say("\t Enable me to be alert\n"+
      "\t to hear the weakest shout\n"+
      "\t and quickly and efficiently\n"+
      "\t to put the fire out\n"+
      "\n");
   return 1;
}

say_prayer6()
{
   say("\t I want to fill my calling and\n"+
      "\t to give the best in me\n"+
      "\t to guard my neighbor and\n"+
      "\t protect his property\n"+
      "\n");
   return 1;
}

say_prayer7()
{
   say("\t And if according to your will\n"+
      "\t I have to lose my life\n"+
      "\t bless with your protecting hand\n"+
      "\t my children and my wife\n"+
      "\n");
   return 1;
}

say_prayer8()
{
   say("The fireman lowers his head and clutches the helmet to his chest!\n");
   return 1;
}

