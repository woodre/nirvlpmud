#define tp this_player()->query_name()
inherit "obj/treasure";
int coffin_count;
string vamp_talk;
object lov;

reset(arg)
{   if (arg) return;
   set_id("coffin");
   set_short("A sleek black coffin");
  set_long(
 "A beautiful sleek black coffin.\n");
   set_weight(10000);
/*
   set_value(1000);
*/
  set_value(0);
   set_heart_beat(0);
}

query_save_flag() { return 1; }
init()
  {
   add_action("open_coffin", "open");
   add_action("up","u");
    add_action("up","up");
        }

open_coffin(str)  {
object ob;
 if(!str)  {
  write("Open what?\n");
  return 1;  }

  ob = this_player();
  lov = ob;
if(str == "coffin")  {
 if(coffin_count <1)  {
  coffin_count = coffin_count + 1;
move_object(clone_object("/players/saber/monsters/selena.c"),environment(this_object()));
write("The coffin lid open, revealing a beautiful dark skinned woman.\n"+
  "The woman steps out of the coffin.\n");
  say(tp+" opens the coffin\n"+
  "A beautiful dark skinned woman steps out.\n",ob);
  return 1;
}
write("The coffin has already been opened.\n");
  return 1;
}
}

up()  {
coffin_count = coffin_count + 1;
        }
