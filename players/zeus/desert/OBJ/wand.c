#include <ansi.h>
inherit "/obj/weapon.c";
#define QPS 10

reset(arg) {
   ::reset(arg);
   if (arg) return;

  set_name("wand of the desert soul");
  set_short(YEL+"The Wand of the Desert Soul"+NORM);
  set_long(
"The Wand of the Desert Soul is about ten inches long, the length of\n"+
"which is covered with mystical engravings.  A soft halo of light can\n"+
"be seen around the wand, as if hinting at its magical properties.\n");
  set_type("staff");
  set_value(6320);
  set_weight(3);
  set_class(13);
  set_read("You don't understand how to read the mystical engravings.\n");
}

id(str){ return str == "wand" || str == "desert wand" ||
str == "wand of the desert soul" || str == "zeus_inculta_q_wand"; }

void init(){
  ::init();
  add_action("free", "free");
  add_action("look", "look");
  add_action("look", "l");
}

status look(string str)
{
  if(str != "engravings" && str != "at engravings") return 0;
  write("It is impossible to read the engravings, they don't seem to\n"+
    "make any sense.  However as you stare at them, you notice they\n"+
    "almost look like a person trapped within a flat prison.\n");
  return 1;
}

void six(object me)
{
  tell_object(me, "\n"+
    "Well done, you have freed the Soul of the Desert Sand.\n"+
    "You receive "+QPS+" quest points for your effort.\n");
    destruct(this_object());    /*  Added 5-21-03  Fred */
}

void five(object me)
{
  tell_room(environment(me), "\n"+
    "For a moment, you think you see the image of a smiling spirit among\n"+
    "the cloud of dust, but as the sand blows away, the image vanishes...\n");
  call_out("six", 8, me);
}

void four(object me)
{
  tell_room(environment(me), "\n\n"+
    "There is a sudden flash and then the light is gone.  Lacking the magic\n"+
    "to maintain its form, the dust from the cloak falls to the ground...\n");
  call_out("five", 7, me);
}

void three(object me)
{
  tell_room(environment(me), "\n"+
    "The cloak continues to glow brighter and brighter...\n");
  call_out("four", 5, me);
}

void two(object me)
{
  tell_room(environment(me), "\n"+
    "The cloak slowly begins to glow at the same intensity as the wand...\n");
  call_out("three", 4, me);
}

status free(string str)
{
  object cloak;
  if(!present(this_object(), this_player())) return 0;
  if(str != "soul" && str != "desert soul" && str != "cloak") return 0;
  cloak = present("zeus_inculta_q_cloak", this_player());
  if(!cloak) return 0;
  write("You wave the wand over the cloak of the desert...\n");
  say(this_player()->query_name()+" waves the wand over the cloak of "+
    "the desert.\n");
  destruct(cloak);
  this_player()->set_quest("inculta_creperum");
  write_file("/players/zeus/log/Q", ctime(time())+" -  "+
     capitalize((string)this_player()->query_real_name())+
     " solved the Inculta Creperum quest.\n");
  write_file("/players/zeus/log/Qsolve", ctime(time())+" -  "+
     capitalize((string)this_player()->query_real_name())+
     " solved the Inculta Creperum quest.\n");
  call_out("two", 4, this_player());
  return 1;
}

