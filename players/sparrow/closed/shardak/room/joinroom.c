#include "../ansi.h"

/*
 * Shardak guild (tm) Dragnar/John
 * Joining room by Balowski/Rasmus, March 21st 1995
 * Last change April 14th 1995 (give player scar _after_ setting rank)
 * Player will be moved here when joining, Shardak appears and claws a
 * scar into the palm of the player. (clones the guild object)
 * All commands are blocked while being in this room.
 */
#pragma strict_types
#include "/players/balowski/lib.h"
#include "../def.h"
#include "../people.h"

inherit ROOM;

int     counter;                /* heartbeat counter */
status binx;

void
create()
{
    ::create();
    set_short("Initiation room");
    set_long("The joining room of the guild of Shardak.\n");
    set_property("no teleport", 1);
}

void
init()
{
    ::init();
    if(this_player())
    if (present(GUILD_ID, this_player()) || next_inventory( this_player()))
{
        write( "\
You feel a great pain in your chest.\n\
You lose consciousness for a second.\nYou wake up in the grotto.\n");
       move_object( this_player(), PATH + " grotto");
        say( this_player()->query_name() + " " +
             this_player()->query_mmsgin() + ".\n");
        return;
    }
    counter= 1;
    set_heart_beat(1);
    add_action("freeze"); add_xverb("");
    add_action("okay", "jR@ss4n");
}

status
freeze()
{
    write( "You are paralyzed.\n");
    return (this_player()->query_level() < 20);
}

status okay()
{
    if(!binx) return 0;
    write("\
Shardak whispers to you:\n\
\t\"Within my ranks, the will of the majority is suppressed\n\
\t by MY will.  You are nothing more than sheep to me.\n\
\tWith the powers I grant you.. you are to be my slaves.\n\
\tAny attacks upon me will result in your banishment from\n\
\tthis guild.\n\n\
\tDo you agree to my terms, mortal?\"\n [y/n] ");
    input_to("okay2");
    return 1;
}


status
okay2(string arg)
{
    if(arg != "yes" && arg != "YES" && arg != "Y" &&
       arg != "y")
    {
      write("Fine, mortal.\n");
      move_object(this_player(), DEST);
      return 1;
    }
    write("\
Shardak whispers to you:\n\
\t\"Good.  You show promise.  But any authority of higher rank\n\
\t above you in the guild, may take away your powers, or even\n\
\t " + BOLD + "EXECUTE" + NORM + " you... at their own discretion.\n\
\t Tread carefully if you wish to go on.  And any whining and\n\
\t bickering will only result in more pain...\n\n\
\tDo you agree to these terms, mortal?\"\n [y/n] ");
    input_to("okay3");
    return 1;
}

status
okay3(string arg)
{
    if(arg != "yes" && arg != "YES" && arg != "Y" &&
       arg != "y")
    {
      write("Fine, mortal.\n");
      move_object(this_player(), DEST);
      return 1;
    }
    write(HIR+"\n\tYOU JOINED AT YOUR OWN RISK.. REMEMBER THAT.\n\n"+NORM);
    write("\
Shardak tells you:\n\
\t\"Remember, no more griping.  And mailing wizards or anyone else\n\
\t except the Master or the Law, will serve no purpose...\"\n");
    counter ++;
    set_heart_beat(1);
    return 1;
}

void
heart_beat()
{
    string text;
    object who;

    switch (counter) {
        case 5:
            text=
"The room seems to grow colder and you are filled with a sudden fear.";
            break;
        case 7:
            text= "A mist slowly fills the room.";
            break;
        case 8:
            text= "The mist swirls around and takes the shape of Shardak.";
            break;
        case 12:
            text= "Shardak walks toward you as he stares into your soul.";
            break;
        case 14:
            text=
"Cold fingers grasp your wrists as Shardak pulls you close to him.";
            break;
        case 17:
            text=
"You feel great pain as Shardak takes a claw and begins to cut a symbol\n\
into the palm of your hand.  Your blood begins to flow onto the floor.";
            break;
        case 22:
            text=
"You hand feels on fire as Shardak finishes his work, then lets 3 drops of\n\
your blood fall into the bowl.  He shoves your hand into the bowl of blood.";
            break;
        case 27:
            text=
"Shardak sends a message to your mind: The blood of the group now runs in\n\
your veins.  Prove to me your abilities and I will give you great powers.";
            break;
        case 32:
            text=
"Shardak touches your hand and the wound closes.  Only the scar remains.";
            break;
        case 34:
            text= "The mist envelopes Shardak and he is gone.";
            break;
    }
    who= first_inventory( this_object());
    if (who && text) {
        tell_object( who, text);
        tell_object( who, "\n\n");
    }

    if(counter == 14)
    {
      binx = 1;
      command("jR@ss4n", who);
      binx = 0;
      set_heart_beat(0);
      return;
    }
    counter++;
    if (counter > 37) {
        set_heart_beat(0);
        if (who) {
            object gob;

            /* reset guild stats, in case some schmuck ;
            who->add_guild_exp( -((int) who->query_guild_exp()));

            /* mark 'who' as being in a guild */
            who->add_guild_rank(1);
            who->add_guild_exp(1);

            /* give 'em a mark */
            gob = clone_object(GUILDOBJ);
            gob->add_sacrifice(20000 + random(6666));
            gob->GuildClass(10);
            gob->ClassName("Novice");
            gob->BaseXp((int)who->query_exp());
            gob->ClassName("Novice");
            command("save", who);
            who->set_home(PATH+"grotto");
            move_object(gob, who);
            gob->save_me();
            command("save", who);
            /* no this_player, 'who' won't feel the move_player */
            tell_object(who, "You travel back to the cave.  A new exit appears.\n");
            who->move_player("X#" + PATH + "cave");
        }
    }
}
