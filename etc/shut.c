#ifdef TESTMUD // Chameloid, 21-Jun-1998
#include "/players/bane/shut.c"
#else
/***************************************************************************
 shut.c / Armageddon.

 Rewritten by Carador, Jan-1996.

 You can start and stop Armageddon with the 'shutdown'-command.
 Type 'man shutdown' or simply 'shutdown' to see how.

 The blueprint of this file does all the technical things like counting
 and shutting down the game.

 The clones are the ones to be found at the login-positions. They are
 informing the players about the reboot.

***************************************************************************/

#pragma strong_types

#include <login.h>
#include <message.h>
#include <kernel.h> // Chameloid, 12-Dec-1996
#include <prop/npc.h>

#define SHUT "etc/shut"

inherit "/obj/monster";
inherit "/basic/time";
inherit "/basic/living/chat";

// All these variables are only set in the blueprint!
object *clones;
string reason;
int time_to_reboot;
string who;
int transport_offer;

//////////////////////////////////////////////////////////////////////////
// First the functions which are only used in the blueprint.
//

void shut()
{
  write("\
Note: Starting Armageddon now works with the wizard-command 'shutdown'.\n\
      It's something like 'shutdown <time> <why>'. But you may just type\n\
      'shutdown' and you'll see a more detailed description.\n");
}

int query_transport_offer()
{
  return transport_offer;
}

int query_when()
{
  if (!time_to_reboot) return 0;
  return time_to_reboot - time();
}

string query_who()
{
  return who;
}

string query_reason()
{
  return reason;
}

void clone_armageddon(string where)
{
  object arm;
  object room;

  if (clonep()) return;

  if (!clones) clones = ({});
  catch(room = load_object(where));
  if (!room || room->query_no_armageddon()) return;

  arm = clone_object(SHUT);
  arm->configure_armageddon(where == DEFAULT_LOGIN_LOCATION);
  clones += ({ arm });
  arm->move_living("X", room);
}

// This is called from /bin/shell
// or from the master if memory shortage is detected, Chameloid, 12-Dec-1996

void start_armageddon(int when, string why)
{
  int i, seconds;
  string *login_rooms;
  string prev_obj; // Chameloid, 12-Dec-1996

  prev_obj=load_name(previous_object()); // Chameloid, 12-Dec-1996
  
  if (clonep() || !when || !why
#if 0  // Alfe 97-Nov-17
       // this restriction is not very useful unless the efun shutdown()
       // is also secured against abuse.
                                ||
#  if 0 // Chameloid, 12-Dec-1996
      !this_player() || !interactive(this_player())
#  else
      (prev_obj!=MASTER && !(this_player() && interactive(this_player())))
#  endif
#endif
      ) {
#if 0  // Alfe 97-Nov-17
    return;
#else
    raise_error("Illegal use of start_armageddon()\n");
#endif
  }

  i = find_call_out("cont_shutting");

  if (i > 0) {
    if (prev_obj!=MASTER) // Chameloid, 12-Dec-1996
      write("\
There's already a shutdown in progress. Terminate that first if you like.\n\
You could do that with 'shutdown terminate'.\n");
    return;
  }

#if 1 // Chameloid, 12-Dec-1996
  if (prev_obj!=MASTER)
    who = this_player() && this_player()->query_vis_name();
  else
    who = "the game driver";
#else
    who = this_player()->query_vis_name();
#endif
    
  reason = why;
  seconds = when * 60;
  login_rooms = m_values(LOGIN_LOCATIONS);

  for (i=sizeof(login_rooms); i--;)
    call_out("clone_armageddon", 4, login_rooms[i]);

  call_out("cont_shutting", 4, seconds);
}

/*
 * this will remove all interactives from game, thus give them the
 * possibility to save themselves. after a delay of some seconds it
 * will truely shutdown the game.
 *                               Alfe 98-May-29
 */
private void save_shutdown() {
  // first we avoid any relogin by preventing cloning of obj/login
  efun::move_object(find_object("obj/login"),this_object());
  map(users(),#'remove_interactive);
  call_out(#'shutdown,10);  // 10 seconds should be enough
}

void cont_shutting(int seconds) {
  string delay;
  int new_delay;

  if (clonep())
    return;

  if (!time_to_reboot) {
    log_file("GAME_LOG", break_string(ctime(time()) +
                                      ": Started Armageddon (done by " + who + 
                                      ", when: in " + time_long(seconds) + 
                                      ", reason: " + reason + ").\n",78,2,1));
  }

  if (seconds <= 0) {
    send_message(({ M_TARGETS, users(), 
                    "Armageddon shouts: I will reboot now." }));
    log_file("GAME_LOG", break_string(ctime(time()) +
                                      ": Game shutdown by Armageddon (started"
                                      " by " + who + ").\n", 78, 2, 1));
    save_shutdown();
    return;
  }
  
  if (seconds <= 240 && !transport_offer) {
    message(({ 2,
               ({ M_TARGETS, #'users,
                  ("Armageddon shouts: Tell me if you want a trip to the"
                   " shop!") }) }));
    transport_offer = 1;
  }

  new_delay = seconds * 3 / 4 - 10;
  time_to_reboot=time()+seconds;
  call_out("cont_shutting", seconds - new_delay, new_delay);
  send_message(({ M_TARGETS, users(),
                  ("Armageddon shouts: Game reboot in " + time_long(seconds) +
                   ".") }));
}


void armageddon_destructed(object where)
{
  if (where) call_out("clone_armageddon", 10, load_name(where));
}

// Well, the reset, of course it is used both in the blueprint and
// in the clones.

void reset(int arg)
{
    string pon;

    monster::reset(arg);
    if (arg) return;

    pon = load_name(previous_object());

#if 0  // Alfe 97-Nov-17
#  if 0 // Chameloid, 12-Dec-1996
    if (pon != SHUT && pon != "bin/shell")
#  else
    if (pon != SHUT && pon != MASTER && pon != "bin/shell")
#  endif
    {
      call_out(#'destruct, 0, this_object());
      return;
    }
#endif
}

// Same applies for notify_destruct. It's important for both the
// blueprint and the clones. If the blueprint is destructed, all
// Armageddons will be destructed. This happens with the command
// 'shutdown terminate'.

// IMPORTANT:
// If a clone is destructed, the shutdown will NOT be cancelled.
// A new Armageddon will appear 10 seconds later.

void notify_destruct()
{
  object p;

  p = this_interactive() || this_player() || previous_object();

  if (clonep())
    SHUT->armageddon_destructed(environment());
  else if (clones && sizeof(clones))
    filter(clones - ({ 0 }), #'destruct);

  if (!p || load_name(previous_object()) == SHUT) return;

  log_file("GAME_LOG",
    ctime(time()) + ": " +
    (p->query_vis_name() || load_name(p)) + " destructed "+
    "Armageddon" + (environment() ? " in " + load_name(environment()) : "")+
    " (shutdown is " + (clonep() ? "NOT" : "now") + " terminated).\n");
}



//////////////////////////////////////////////////////////////////////////
// And now the functions, which are only used in the clones.
// These are mainly Armageddon's outfit and his chat_reactions.



private mixed make_header(string type)
{
  if (type == "tell")
    return ({ M_WRITE, M_ME, M_ME_VERB, "tell", " you: " });

  return ({ M_SAYS });
}


private status among_target(mixed *target) 
{
  return ( !sizeof(target) || sizeof(target & ({ this_object() })));
}


private mixed when_chat(string text, string type, object pl, mixed target)
{
  int when_reboot;
  mixed header;

  if (!among_target(target)) return;

  header = make_header(type);
  when_reboot = SHUT->query_when();

  return ({ header + ({ "The reboot will be in " +
            time_long(when_reboot) + "." }) });
}


private mixed why_chat(string text, string type, object pl, mixed target)
{
  string why_reboot;
  mixed header;

  if (!among_target(target)) return;

  header = make_header(type);
  why_reboot = SHUT->query_reason();

  if (!why_reboot) return ({ header + ({ "Strange. I don't know why." }) });

  return ({ header + ({ "As far as I know, the reason for the " +
     "reboot is '" + why_reboot + "'." }) });
}


private mixed who_chat(string text, string type, object pl, mixed target)
{
  mixed header;
  string who_reboot;

  if (!among_target(target)) return;

  header = make_header(type);
  who_reboot = SHUT->query_who();
  
  if (!who_reboot) return ({ header + ({ "Strange. I don't know " +
     "who started me." }) });

  return ({ header + ({ "Well, " + who_reboot + " told me to do that." }) });
}


private mixed shop_chat(string text, string type, object pl, mixed target)
{
  mixed header;

  if (!among_target(target)) return;

  header = make_header(type);

  if (!SHUT->query_transport_offer()) 
    return ({ header + ({ "Wait until the time has come." }) });

  return ({
    header + ({ "No problem, ", M_PL_DESCRIBE, "." }),
    2,
    lambda(0, ({ #'call_other, pl, "move_living", "X", "room/shop" }))
  });
}
 

varargs void configure_armageddon(status arm)
{
    if (arm) {
      set_name("Armageddon");
      set_alias("crasher");
      set_spell_mess1("Armageddon hits his enemy with a terrible fireball.");
      set_short("Armageddon the game crasher");
    }
    else {
      set_name("Armageddon's brother");
      set_alias("brother");
      add_id("armageddon");
      set_spell_mess1("\
Armageddon's brother hits his enemy with a terrible fireball.");
      set_short("One of Armageddon's brothers");
    }
    set_race("living");  // Coogan, 07-Jun-2001
    set_long("\
Armageddon and his brothers. A really kind family. Whenever you see one\n\
of them, it doesn't mean anything good for the world. The Armageddons\n\
enjoy shutting down the game. But you shouldn't attack one of them, or\n\
they would shut down you.\n\
Better ask some questions, such as 'when do you reboot' or\n\
'why do you reboot' or 'who started you'.\n");
    set_spell_mess2("You are hit by a terrible fireball.");
    set_property(P_NO_MONSTER_DATABASE); // Coogan, 22-Jan-1998
    set_level(19);
    set_wc(40);
    set_chance(50);
    set_spell_dam(100);
    set_hp(2000);
    set_ac(2000);
    set_male();
    set_default_chat_msg_type(({ "say", "tell" }));

    set_chat_reactions(({
       ({ ({ "when reboot", "when rebooted", "when shut", "when shutdown"  }),
          #'when_chat
       }),

       ({ ({ "why reboot", "why rebooted", "why shut", "why shutdown" }),
          #'why_chat
       }),

       ({ ({ "who started", "who start" }),
          #'who_chat,
       }),

       ({ "shop",
         #'shop_chat
       })
    }));
}
#endif
