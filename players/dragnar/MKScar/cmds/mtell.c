#define user environment(previous_object())
#define capname capitalize(this_player()->query_name())

main( str ) {
    /* Dragnar/John 11/5/98
    *  A multiple tell that allows players to tell to more than
    *  one object at a time.  explode is used to split the list of
    *  tell objects into an array of strings.  Currently, no
    *  restrictions on the number of tells, and no check for
    *  'spamming' a single person with multiple tells.
    *
    *
    *  Dragnar/John 11/23/98
    *  Fixed the spamming problem with member_array to ensure that
    *  a player is only in the tell_list 1 time.
        *
        *  Dragnar/John 3/23/99
        *  Changed some formatting of the who variable, added checks from
        *  the player.c tell command like invis check, etc.
    */

    string *tell_list;
    string *who_list;
    object tellee;
    string what, wholist, who;
    int i,j;

    if(user->query_invis() > 0 && user->query_level() < 40) {
        write("Don't be annoying.  Become visible before you talk to someone!\n"
);
        return 1;
    }
        if( user->query_ghost() ) {
        write("In your current state that is impossible.\n");
            return 1;
    }
    if( user->query_spell_point() < 10 ) {
            write("You are low on power.\n");
         return 1;
    }
    if( !str || sscanf(str, "%s %s",who,what) != 2 ) {
        write("Usage: mtell player1,player2,player3 <message>\n");
        return 1;
    }
    what = "\""+what+"\"";
    tell_list = explode( who, "," );
    if( sizeof(tell_list) > 10 ) {
        write("You can't tell to more than ten people.\n");
        return 1;
    }
    who_list = allocate(sizeof(tell_list));
    who = 0;
    for( i = 0, j = 0; i < sizeof(tell_list); i++ ) {
/* changed by Vertebraker [5.24.01], check to see if tell_list[i] is not null */
        if(stringp(tell_list[i])) tell_list[i] = lower_case(tell_list[i]);
        else { write("Bog!\nFailure.\n"); return 1; }
        tellee = find_player( tell_list[i] );
        if(!tellee) tellee=find_living( tell_list[i] );
        if(!tellee || user->query_level() < tellee->query_level() &&
                  tellee->query_invis() >= 39) {
            write(capitalize(tell_list[i]) +" is not logged on.\n");
        }
        else if(!tellee->query_interactive() && !tellee->query_npc()) {
            write(capitalize(tell_list[i])+" is disconnected.\n");
        }
        else if( user->query_level() < 100 && in_editor(tellee) ) {
            write(capitalize(tell_list[i])+" is editing.  Try again later.\n");
        }
        else {
            if( tellee->query_player() ) {
            if(query_idle(tellee) > 120) {
                write("Warning: "+capitalize(tell_list[i])+" is idle.\n");
            }
            }
            if ( who == 0 ) {
                who = capitalize( tell_list[i] );
                                who_list[j] = tell_list[i];
                j++;
            }
            else {
                if( member_array(tell_list[i],who_list) == -1 ) {
                    who = who + ", " + capitalize(tell_list[i]);
                                        who_list[j] = tell_list[i];
                        j++;
                }
                        }
        }
    }
        for( i = 0; i < j; i++ ) {
        tellee = find_player( who_list[i] );
        if( !tellee ) tellee = find_living( who_list[i] );
        if( tellee ) {
            if( j == 1 ) {
                wholist = "you";
            }
            else {
                wholist = who;
            }
        tell_object_wblock(tellee, capname+" tells "+wholist+": "+what+"\n");
                tellee->add_tellhistory(capname+" tells you: " + what);
        set_reply( tellee->query_name(), this_player()->query_name(), who_list );
                }
        }
    if (who) {
        write("You tell " +(who)+ ": " +what+ "\n");
    }
    if(user->query_level() < 20 ) {
        this_player()->add_spell_point( -1 * j );
     }
    return 1;
}

void set_reply( string receiver, string sender, string *who ) {
    /* Sets the _reply in scar.c and allows player to reply to
    *  a list of people from an mtell.
    *  Dragnar/John 3/22/99
    */

    object ob;
    string who_list, temp_who, tellee, teller;
     int i;

    tellee = lower_case( receiver );
    teller = lower_case( sender );
    ob = present("bloodscar", find_living( lower_case( tellee ) ) );
    if( !ob ) {
        return;
    }
    else {
        for( i = 0; i < sizeof(who); i++ ) {
           if(temp_who)
             temp_who = lower_case( who[i] );
            if( temp_who == tellee )
               temp_who = teller;
                if( !who_list && temp_who) {
                    who_list = temp_who;
                }
                else if(temp_who) {
                    who_list = who_list + "," + temp_who;
                }
        }
        ob->set_reply_list( who_list );
        return;
    }
}
