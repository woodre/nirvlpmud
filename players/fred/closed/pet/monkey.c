/* spider monkey by Verte and Fred */

#define VOID   "/players/vertebraker/closed/void"
#define CHURCH "/room/church"

#define M_DEBUG

#include "/players/vertebraker/ansi.h"

status ghost() { return 0; }

inherit "/players/vertebraker/closed/std/monster";
inherit "/players/vertebraker/closed/std/m_efuns";

object owner;
string location, cmd, bling;
status Busy, aoo, chew;

void
renegades_of_funk()
{
    chat_str = 0;

    load_chats(({ 
               cap_name + " chitters!\n", 
               cap_name + " looks for a tree to climb.\n",
               cap_name + " scurries around.\n",
               cap_name + " gobbles down some dirt.\n",
               cap_name + " screams!\n",
               cap_name + " snickers and does a spiderlike dance.\n",
               cap_name + "'s pupils dilate and expand quickly.\n",
               cap_name + " \
claps his hands together like an organ grinder monkey.\n",
               cap_name + " goes: eee! EEeeeee!\n",
               cap_name + " does some monkey ballet.\n" }));
}

void
reset(status arg)
{
    if(arg) return;
    monster::reset();
    set_name("spider monkey");
    set_alias("spider");
    set_alt_name("spider monkey");
    set_race("monkey");
    set_short("A spider monkey");
    set_long("\
A cute little spider monkey.\n");
    set_al(0); /* a monkey! */
    set_gender("creature");
    set_level(10); /* stats per monster.guide */
    set_chat_chance(10);
    renegades_of_funk();
}

status
is_pet() /* flags it as a pet */
{
    return 1;
}

void
set_owner(object x)
{
    owner = x;
}

void
init()
{
    int s; string *fl;
    monster::init();

    add_action("cmd_name", "mname");
    add_action("cmd_train", "mtrain");
    add_action("cmd_spank", "spank");
}  

status
cmd_name(string arg)
{
    if(this_player() != owner)
      return 0;

    if(!arg)
    {
      notify_fail("What would you like to name your spider monkey?\n");
      return 0;
    }

    write("You name your spider monkey " + arg + ".\n");
    name = lower_case(arg);
    cap_name = capitalize(arg);
    set_long("A cute little spider monkey named " + cap_name + ".\n");
    renegades_of_funk();
    call_out("nog_dat", 2, this_player());
    return 1;
}

string
short()
{
    return ((cap_name != "Spider monkey") ? 
             cap_name + " the Spider Monkey" :
             "A Spider Monkey");
}

void
long()
{
    monster::long();

    if(this_player() == owner)
    {
      write(cap_name + " chitters at you, its master.\n\
'mname <name>' to name your monkey something else.\n\
'mtrain <cmd>' to change his remembered command he will\n\
               execute in his remembered location\n\
               (see below for details).\n\n\
You can have your monkey 'remember' a location to run to,\n");
      write("\
or have him 'fetch' to execute his trained command,\n\
or have him 'come' to you by saying the keyword aloud in\n\
conjunction with his name.  " + cap_name + " can also 'get'\n\
things, 'give' his things to you, or 'drop' everything.\n\
i.e. 'say " + name + " remember this!'\n\
     - " + cap_name + " will remember your current location.\n\
     'tell " + name + " " + name + ", come'\n\
     - " + cap_name + " will come to you.\n\n");
    }
}
  

void
cmd_spank(string str)
{
    if(id(str) && !attacker_ob)
    {
      call_out("squirm", 2, this_player());
      set_heart_beat(1);
      this_object()->heart_beat(); /* heh */
    }
}

void
squirm(object ah)
{
    object e, m;
    if(!ah || !(e = environment(ah)) || !(m = environment()))
      return;
    tell_room(m, cap_name + " squirms unhappily.\n");
}

void
catch_tell(string str)
{
    string a, b, c, d, za, vx;
    object e, x, z, o;

    if(!(e = environment()) || !str)
      return;

#ifdef M_DEBUG
    tell_object(find_player("fred"), HIR + "%" + NORM + str);
#endif
    if(!chew) { this_object()->soul_init(); chew = 1; }
    if((sscanf(str, "%s %ss " + cap_name + ".\n", c, d) == 2) && 
       (c != cap_name) || (sscanf(str, "%s %ss you%s\n", c, d, za) == 3) ||
        (sscanf(str, "%s %ss at you%s\n", c, d, za) == 3))
    {

#ifdef M_DEBUG
      tell_object(find_player("fred"), "bacon grease called\n");
#endif

      call_out("bacon_grease", 1, ({ d, lower_case(c) }));
      return;
    }

    if((x = this_player()) && (x == owner) && 
       (x != this_object()) && !Busy)
    {

      if((sscanf(str, "%s leaves %s.\n", a, b) == 2) 
        && ((string)owner->query_name() == a))
      {
        aoo = 1;
        command(b, this_object());
        aoo = 0;
        return;
      }

      str = lower_case(str);

      if(!text_contains(str, name) &&
         !text_contains(str, alias) &&
         !text_contains(str, alt_name) && 
         !text_contains(str, race))
        return;

      if((vx = query_verb()) && ((vx == "drop") || (vx == "give") || (vx == "take") || (vx == "get"))) return;

      if(text_contains(str, "remember"))
      {
        if(root(e) && ((string)e->realm() != "NT" ||
           (status)e->okay_follow()))
        {
          location = file_name(e);
          call_out("nog_dat", 1, x);
        }
        else
          call_out("fuk_dat", 1, x);

        return;
      }

      if(text_contains(str, "fetch"))
      {
        if(location)
        {
          z = find_object(location);
          if(!z)
          {
            location->load_it();
            z = find_object(location);
          }
          if(z)
          {
            call_out("nog_dat", 1, x);
            call_out("fetch_it", 2, x);
          }

          else
            call_out("fuk_dat", 1, x);

          return;
        }
      }
 
      if(text_contains(str, "come"))
      {
        if((o = environment(owner)) && (e != o))
        {
          call_out("nog_dat", 1, x);
          call_out("cmere", 2, x);
        }
        else
          call_out("fuk_dat", 1, x);

        return;
      }

      if(text_contains(str, "give"))
      {
        call_out("nog_dat", 1, x);
        call_out("give_em", 2, x);
        return;
      }

      if(text_contains(str, "drop"))
      {
#ifdef M_DEBUG
        tell_object(find_player("fred"), "drop zone\n");
#endif
        call_out("nog_dat", 1, x);
        call_out("drop_em", 2, x);
        return;
      }
  
      if((text_contains(str, "get") ||
          text_contains(str, "take")))
      {
        call_out("nog_dat", 1, x);
        call_out("get_em", 2, x);
      }
    }
}

void
bacon_grease(string *heh)
{
    string a, b;
    a = heh[0]; b = heh[1];
#ifdef M_DEBUG
    tell_object(find_player("fred"), "bacon grease\n");
    tell_object(find_player("fred"), "bacon grease cmd: " + a + " " + b + "\n");
#endif
    (int)call_other("/bin/soul/_"+ a +".c", "cmd_"+ a +"", b);
}

void
heart_beat()
{
    object e, m; 

    monster::heart_beat();

    if(!owner || !(m = environment()))
    {
      move_object(this_object(), VOID);
      destruct(this_object());
      return;
    }

    if((e = environment(owner)) && (e != m) && !Busy)
    {
      tell_room(m, cap_name + " scurries away following " +
      (string)owner->query_name() + ".\n");
      move_object(this_object(), e);
      tell_room(e, cap_name + " scurries in following " +
      (string)owner->query_name() + ".\n", ({ owner }));
      tell_object(owner, cap_name + " scurries in following you.\n");
    }
      
    if(attacker_ob)
      tell_object(owner, 
        BOLD + cap_name + NORM + ": " + 
          (((hit_point * 10) / max_hp)) + "/10\n");

}

void
nog_dat(object who)
{
    object e, m;

    if(!who || !(e = environment(who)) || !(m = environment()))
      return;

    if(m == e)
    {
      tell_object(who, cap_name + " nogs at you.\n");
      tell_room(m, cap_name + " nogs at " + (string)who->query_name() +
       ".\n", ({ who, this_object() }));
    }

    else
      tell_object(who, cap_name + " nogs at you from afar.\n");
}

void
fuk_dat(object who)
{
    object e, m;

    if(!who || !(e = environment(who)) || !(m = environment()))
      return;

    if(m == e)
    {
      tell_object(who, cap_name + " gives you the evil monkey eye.\n");
      tell_room(m, cap_name + " gives " + (string)who->query_name() +
      " the evil monkey eye.\n", ({ who }));
    }

    else
      tell_object(who, cap_name + " \
gives you the evil monkey eye from afar.\n");
}

void
fetch_it(object x)
{
    object e, m;

    if(!x || !(e = environment(x)) || !(m = environment()))
      return;

    if((bling = file_name(m)) == location)
    {
      tell_room(m, cap_name + " looks around and snickers.\n");
      bling = 0;
      call_out("do_cmd", 1);
      return;
    }
    
    tell_room(m, cap_name + " scurries away.\n");
    move_object(this_object(), location);
    tell_room(environment(), cap_name + " scurries in.\n");
    Busy = 1;
    call_out("do_cmd", 1);
}

void
do_cmd()
{
    if(!cmd)
    {
      tell_room(environment(), cap_name + " \
gets a puzzled look on his face.\n");
      call_out("do_return", 1);
      return;
    }

    tell_room(environment(), cap_name + " chitters!\n");
    this_object()->init();
    command(cmd, this_object());
    call_out("do_return", 2);
}

void
do_return()
{
    object z, cha;

    if(!owner || !(z = environment()))
    {
      Busy = 0;
      return;
    }

    tell_room(z, 
cap_name + " looks around and squeaks excitedly!\n");

    if(!(cha = environment(owner)))
    {
      if(bling)
        move_object(this_object(), bling);
      else
        move_object(this_object(), CHURCH);

      if(environment() != z)
      {
        tell_room(z, cap_name + " scurries away.\n");
        tell_room(environment(), cap_name + " scurries in.\n");
      }

      Busy = 0;
      return;
    }

    if(cha != z)
    {
      tell_room(z, cap_name + " scurries away.\n");
      move_object(this_object(), cha);
      tell_room(cha, cap_name + " scurries in.\n");
    }

    Busy = 0;
    return;
}

void
cmere(object x)
{
    object e, m;

    if(!x || !(e = environment(x)) || !(m = environment()))
      return;

    if(m == e)
    {
      tell_room(m, cap_name + " looks around and goes: ehehehe.\n");
      return;
    }
    
    tell_room(m, cap_name + " scurries away.\n");
    move_object(this_object(), e);
    tell_room(e, cap_name + " scurries in.\n");   
}

status
cmd_train(string arg)
{
    if(!arg) 
    {
      notify_fail("Syntax: 'mtrain <cmd>'\n");
      return 0;
    }

    write("\
You glance at " + cap_name + " and go through the motions of\n\
" + arg + ".\n" + 
cap_name + " blinks his brown eyes at you.\n");

    if(0 == random(10))
      call_out("fuk_dat", 1, this_player());

    else
    {
      cmd = arg;
      call_out("nog_dat", 1, this_player());
    }

    return 1;
}

void
give_em(object x)
{
    int s, h;
    object *ob, e, c, d;

    if(!x || !(e = environment()) || (e != (c = environment(x))))
      return;

    s = sizeof(ob = all_inventory(this_object()));
    tell_room(e, cap_name + " squeaks excitedly.\n");

    while(s--)
    {
      d = ob[s];
      if((string)d->short() && (int)d->query_value())

          if(!transfer(d, x))
          {
            tell_object(owner, cap_name + " hands you " + (string)d->short() + ".\n");
            tell_room(environment(owner), cap_name + " hands something to " + (string)owner->query_name() + ".\n", ({ owner }));
          }
    }

    tell_room(e, cap_name + " grins at " + (string)x->query_name() +
    ".\n", ({ x }));
    tell_object(x, cap_name + " grins at you.\n");
}

void
drop_em(object x)
{
    object a, g, e, c;
    string sh;

    if(!x || !(e = environment()) || (e != (c = environment(x))))
      return;

    tell_room(e, cap_name + " squeaks excitedly.\n");

    a = first_inventory(this_object());
    while(a)
    {
      if((sh = (string)a->short()) && (int)a->query_weight()
         && (int)a->query_value()
         && !transfer(a, e))
        tell_room(e, cap_name + " drops: " + sh + ".\n");

      a = next_inventory(this_object());
    }

    if(money)
    {
      g = clone_object("/obj/money");
      g->set_money(money);
      move_object(g, e);
      tell_room(e, cap_name + " drops: " + money + " coins.\n");
      money = 0;
    }

}

void
get_em(object x)
{
    object e, a, b;
    string sh;
    int weight;
    if(!x || !(e = environment()))
      return;

   tell_room(e, cap_name + " chitters happily.\n");
   a = first_inventory(e);
    while(a)
    {
      b = a;
      a = next_inventory(a);
      if(!living(b) && (sh = (string)b->short()) && 
      (int)b->query_weight() && (int)b->query_value())
      {
        move_object(b, this_object());
        tell_room(e, cap_name + " gets: " + sh + ".\n");
      } 
     
    }
     
}

void
move_player(string x)
{
    object a;
    string y, z;

    if(!owner || !aoo) return (void)::move_player(x);
    
    sscanf(x, "%s#%s", y, z);

    if(!(a = find_object(z)))
    {
      z->load_it();
      a = find_object(z);
    }

    move_object(this_object(), a);
}

int
cmd_hook(string arg)
{
    return (int)call_other("/bin/soul/_"+query_verb(), "cmd_"+query_verb(), arg);
}
