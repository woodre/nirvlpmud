#include <ansi.h>

#define TO this_object()
#define ENV environment
#define ENVTO ENV(TO)
#define QN query_name()
#define TR tell_room
#define TP this_player()
#define MO move_object

inherit "/players/vertebraker/closed/std/mount";

object summoner;
object pack;

void summoner(object ob){ summoner = ob; }
object query_summoner(){ return summoner; }

void reset(status x)
{
 ::reset(x);
 if(x) return;
 set_silent_dismount();
 set_silent_mount();
 set_name(CYN+"winged "+HIK+"drakyr"+NORM);
 set_alias("winged drakyr");
 set_alt_name("drakyr");
 set_short("a "+query_name());
 set_gender("creature");
 set_long("\
A demon with an impressive 23' wingspan, the\n\
winged drakyr is a sight to fear.  With sharp\n\
black teeth and razor-like claws, this green\n\
monstrosity serves to strike fear in the hearts\n\
of all living beings.\n\
This one seems to be in a sort of trance, however.\n\
It stares blankly and does not respond to anything.\n");
 set_level(20);
 set_hp(500);
 set_wc(35);
 set_ac(15);
 set_spell_dam(100);
 set_chance(33);
 set_spell_mess1("The "+query_name()+" rakes at its enemy with its claws!");
 set_spell_mess2("The "+query_name()+" rakes at you with its claws!");
 set_no_exp_value(1);

 pack = clone_object("/obj/container");
 pack->set_name("bag");
 pack->set_short("drakyr saddle bag");
 pack->set_long("A large green saddle bag that fits comfortably over a drakyr.\n");
 pack->set_weight(2);
 pack->set_value(0);
 pack->set_max_weight(30);
 pack->set_can_open(1);
 move_object(pack, this_object());
}

void heart_beat()
{
 object env;
 if(root()) return;
 ::heart_beat();
 if(!(env=environment()))
  return destruct(TO);
 if(!summoner || summoner->query_ghost())
 {
  TR(env, "The "+query_name()+" flaps its wings and flies away.\n");
  MO(TO, "/room/void");
  return destruct(TO);
 }
 if(!random(125))
  TR(env, "The "+query_name()+" flaps its wings.\n");
 if(!random(125))
  TR(env, "The "+query_name()+" SCREEEEECHES loudly...\n");
 if(!random(125))
  TR(env, "The "+query_name()+" claws impatiently at the ground.\n");
}

int monster_died(object mob)
{
 object ob, corpse, next;
 
 if(!(corpse = present("corpse", environment()))) return 0;
 next = first_inventory(corpse);

 while(ob = next)
 {
   next = next_inventory(ob);
   if(ob->is_player())
   {
     tell_object(ob, "You fall off the Drakyr's back as it collapses lifelessly to the ground.\n");
     move_object(ob, environment());
   }
 }

 present("dark_circle", summoner)->set_drakyr(0);
 return 1;
}   

void init()
{
  ::init();
  
  if(!this_player()->query_mounted())
  {
    add_action("Cmd_release","release");
  }
  add_action("Cmd_bag","dbag");
  add_action("Cmd_unbag","dunbag");
}

int Cmd_release(string str)
{
  if(this_player() != summoner) return 1; 
  if(!str){ write("Release what?\n"); return 1; }
  if(str != "drakyr"){ notify_fail("Release what?\n"); return 0; }

  TR(environment(), "The "+query_name()+" SCREEEECHES loudly and flies off into the clouds.\n");
  
  present("dark_circle", summoner)->set_drakyr();

  move_object(this_object(), "/room/void");
  destruct(this_object());
  
  return 1;
}

status mountable(object ob)
{
 if(ob != summoner)
 {
  notify_fail("The "+query_name()+" denies you...\n");
  return 0;
 }
 return 1;
}

int cmd_mount(string str)
{
 object m;
 int val;
 m = (object)TP->query_mounted();
 val = ::cmd_mount(str);
 if(!m && ((object)TP->query_mounted() == TO))
 {
  write("You hop on the "+query_name()+"'s back.\n");
  TR(ENV(TP), (string)TP->QN+" hops on "+QN+"'s back.\n", ({TP}));
  TR(ENVTO,
query_name()+" SCREEEEEECHES!\n");
  emit_channel("junk", "\
You hear the cry of a "+query_name()+"!\n");
 }
 return val;
}

int cmd_dismount(string str)
{
 object m;
 int val;
 m = (object)TP->query_mounted();
 if(m == TO)
 {
  val = ::cmd_dismount(str);
  if(!TP->query_mounted())
  {
   write("You hop off of the "+query_name()+"'s back.\n");
  }
  return val;
 }
 return 0;
}

is_drakyr() { return 1; }

status Cmd_bag(string arg)
{
  object ob;
  string it;

  if (this_player() != summoner) return 0;
  if (!arg)
  {
    if (ob = first_inventory(pack))
    {
      write("The Drakyr's saddle bag contains:\n");
      while(ob)
      {
        if (it = (string)ob->short()) write(it + ".\n");
        ob = next_inventory(ob);
      }
    }
    else write("The Drakyr's saddle bag is empty.\n");
    return 1;
  }
  if(!(ob = present(arg, this_player())))
  {
    notify_fail("Bag what?\n");
    return 0;
  }
  transfer(ob, pack);
  write("You open the clasp on the Drakyr's saddle bag and stow a "+(string)ob->short()+".\n");
  say(this_player()->query_name()+" stows something in "+this_player()->query_possessive()+" Drakyr's saddle bag.\n", this_player());
  return 1;
}

status Cmd_unbag(string arg)
{
  object ob, next;
  string it;
  int num;

  if(this_player() != summoner) return 0;
  if(!arg){ notify_fail("Unbag what?\n"); return 0; }

  next = present(arg, pack);
  if(!next){ notify_fail("Unbag what?\n"); return 0; }

  transfer(next, this_player());

  write("You open the clasp on the Drakyr's saddle bag and retrieve a "+(string)next->short()+".\n");
  say(this_player()->query_name()+" retrieves something from "+this_player()->query_possessive()+" Drakyr's saddle bag.\n", this_player());
  
  return 1;
}
 
  
