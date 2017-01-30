#include <ansi.h>
#include "../lib/guild_defs.h"

inherit G_HALL;

static int dag;
object dood;
string org_long;
string *ppl;

void reset(status arg)
{
   if(arg) return;
   set_light(-5);
   set_short(CEN);
   org_long = "\
  The ancient altar before you was once devoted to the ancient wizard\n\
Gorhurtrix of the Damned. A frozen human skeleton is bound to the\n\
ancient stone. A stone dagger plunged deep into its ribcage; a small\n\
crystal goblet clutched in its left hand, tightened into a deathgrip.\n\
You think you might be able to \"pull\" the goblet from the hand.\n";
  set_long(org_long);
   add_item(({"altar","skeleton","stone","dagger","crystal tablet","tablet",
              "eyes", "hand", "left hand"}),"");
   dood = 0;
   set_exits(({
     ROOMDIR + "f6", "north",
     ROOMDIR + "f4", "south",
  }));
   dood = 0;
   ppl = ({ });
    restore_object("players/vertebraker/classic/undead/room/altarSave");
  set_long(org_long);
}

void init()
{
  ::init();
  add_action("cmd_pull", "pull");
}

int cmd_pull(string str)
{
  if(member_array((string)TP->QRN, ppl) > -1)
  {
    write("Gorhurtrix has heard your call.\n");
    return 1;
  }
  if((string)TP->query_guild_name() == "Undead") {
    write("Gorhurtrix has heard your call.\n");
    return 1;
  }
  if(dag == 2)
  {
    if(str != "dagger" && str != "the dagger") return 0;
    write("You pull the dagger effortlessly from the skeleton's chest.\n");
    write("A ghostly visage of an old wizard appears.\n");
   write("The dagger vanishes.\n");
    write("Gorhurtrix tells you: I promise to consider thee, warrior.\n");
    write("Gorhurtrix tells you: But now- until the mist claims me again, I rest.\n");
    write("Gorhurtrix disappears in a puff of smoke.\n");
    (OBJDIR + "gorThanks")->shoutCast();
    dood = 0;
    write_file(LOGDIR+"app", (string)this_player()->query_real_name());
    write_file(LOGDIR + "app", "\n");
    ppl += ({ (string)TP->QRN });
    save_object("players/vertebraker/classic/undead/room/altarSave");
    set_long(org_long);
    dag=0;
    return 1;
  }
  if(query_long() != org_long) return 0;
  if(str != "goblet" && str != "goblet from the hand" &&
     str != "the goblet" && str != "the goblet from the hand" &&
     str != "goblet from hand" && str != "the goblet from hand")
     return 0;
  if(dood) { write("Somebody already did that.\n"); return 1; }
  write("You tug on the goblet...\n");
  if((int)TP->query_attrib("str") + (int)TP->query_attrib("wil") < random(50))
  {
    write("It remains firmly clenched in the skeleton's hand.\n");
    return 1;
  }
  write("You yank the goblet free.\n");
  write("It disappears into a cloud of " + RED + "red mist" + NORM + ".\n");
  write("The skeleton's eye sockets burn " + HIR + "RED" + NORM + "...\n");
  set_long("\
  The ancient altar before you was once devoted to the ancient wizard\n\
Gorhurtrix of the Damned. A frozen human skeleton is bound to the\n\
ancient stone. Its " + HIR + "red eyes" + NORM + " stare into your soul.  A stone dagger\n\
plunged deep into its ribcage, the skeleton has its left hand firmly\n\
clenched.\n");
  dood = TP;
  call_out("call1", 8);
  return 1;
}

void call1()
{
  if(!dood || !present(dood, TO)) return reset(0);
  tell_object(dood,
"\n\tYou feel the skeleton's eyes burning into your soul....\n\n");
  call_out("call2", 10);
}

void call2()
{
  if(!dood || !present(dood, TO)) return reset(0);
  tell_object(dood,
"\n" + HIK + 
"A voice speaks to you:\n" + NORM + 
"  Adventurer- I am one of the Damned. I am Gorhurtrix, Legend\n\
of Nirvana. And I am not of this world...\n");
  call_out("call3", 10);
}

void call3()
{
  if(!dood || !present(dood, TO)) return reset(0);
  tell_object(dood,
"\n" + HIK + "A voice speaks to you:\n" + NORM + 
"  I was banished to this earthly plane thousands of years ago\n\
as a result of the great war of wizards. Death followed my\n\
every waking shadow upon my entrance here.\n");
  call_out("call4", 10);
}

call4()
{
  if(!dood || !present(dood, TO)) return reset(0);
  tell_object(dood,
"\n" + HIK + "A voice speaks to you:\n" + NORM +
"  I ruled through my connection to the energies of death\n\
and my knowledge of how to work them. I allowed many\n\
followers to tread my path and learn my secrets. But\n\
there was one pupil who was more desiring of power than\n\
any of my other students ..\n");
  call_out("call5", 10);
}

call5()
{
  if(!dood || !present(dood, TO)) return reset(0);
  tell_object(dood,
"\n" + HIK + "A voice speaks to you:\n" + NORM + 
"  This man's name was Habdazar the Vain.\n\
Little did I know how true his title fit him.\n\
I taught my students in the arts of combat magic, as\n\
well as dark magiks long forgotten. Habdazar challenged\n\
me within this very Castle that I constructed in order\n\
to test his skills.\n");
  call_out("call6", 10);
}

call6()
{
  if(!dood || !present(dood, TO)) return reset(0);
  tell_object(dood,
"\n" + HIK + "A voice speaks to you:\n" + NORM +
"  I easily beat Habdazar on the field of battle- him\n\
being but a lowly human. But as I drew back my death\n\
energy from his body to spare his life, he intoned a\n\
spell of rejection. It caused the energy to rebound\n\
across the walls of this magical place...\n");
  call_out("call7", 10);
}

call7()
{
  if(!dood || !present(dood, TO)) return reset(0);
  tell_object(dood,
"\n" + HIK + "A voice speaks to you:\n" + NORM + 
"  The death energy mixed with the spiritual energy\n\
of the Isle of Magi and compacted... formed a new\n\
compound entirely. Finally, it manifested itself in\n\
a humanoid form comprised of a reddish mist...\n");
  call_out("call8", 10);
}

call8()
{
  if(!dood || !present(dood, TO)) return reset(0);
  tell_object(dood,
"\n" + HIK + "A voice speaks to you:\n" + NORM +
"  It was not just a form, but life... it was the\n\
energy of the Undead which emerged that day.\n");
  call_out("call9", 10);
}

call9()
{
  if(!dood || !present(dood, TO)) return reset(0);
  tell_object(dood,
"\n" + HIK + "A voice speaks to you:\n" + NORM +
"  After observing the new creature momentarily,\n\
it began to wrap itself around me, seeking a new\n\
host to involve its power. I allowed it to circle,\n\
but kept it at a safe distance. I decided to return\n\
to my study to learn more of this curious power.\n");
  call_out("call10", 10);
}

call10()
{
  if(!dood || !present(dood, TO)) return reset(0);
  tell_object(dood,
"\n" + HIK + "A voice speaks to you:\n" + NORM +
" ...But no sooner had I turned my back upon the fallen\n\
Habdazar when he plunged this infernal stone dagger deep\n\
within my side! The energy leapt from my body and swirled\n\
around Habdazar...\n");
  call_out("call11", 10);
}

call11()
{
  if(!dood || !present(dood, TO)) return reset(0);
  tell_object(dood,
"\n" + HIK + "A voice speaks to you:\n" + NORM +
"  As I lay dying from the enchanted stone dagger,\n\
the mist built around Habdazar until it completely swallowed\n\
his body. It tore his body to ribbons, and in minutes\n\
there was no longer evidence that there had ever been\n\
a Habdazar the Vain.\n");
  call_out("call12", 10);
}

call12()
{
  if(!dood || !present(dood, TO)) return reset(0);
  tell_object(dood,
"\n" + HIK + "A voice speaks to you:\n" + NORM +
"  The mist spoke to me then.. very much as how I am\n\
speaking to you now. We bonded then through our very\n\
souls- and as I died, it transferred its final energies\n\
into my silent heart.\n");
  call_out("call13", 10);
}

call13()
{
  if(!dood || !present(dood, TO)) return reset(0);
  tell_object(dood,
"\n" + HIK + "A voice speaks to you:\n" + NORM +
"  Life ended for me there, but eternal unlife greeted\n\
me with its temperate embrace. You see, I have become\n\
eternal life. I have become God.\n");
  call_out("call14", 10);
}

call14()
{
  if(!dood || !present(dood, TO)) return reset(0);
  tell_object(dood,
"\n" + HIK + "A voice speaks to you:\n" + NORM +
"  My power lies in those of the arcane magics of undeath.\n\
I hold supreme energy for those who are willing to take it-\n\
but I only will admit those who are truly worthy...\n\
Dare you offer yourself for consideration?\n\
If so, 'pull' the dagger from my body.\n");
  set_long(long_desc + "You may \"pull\" the dagger from the skeleton.\n");
  dag=2;
}


query_ppl() { return ppl; }

