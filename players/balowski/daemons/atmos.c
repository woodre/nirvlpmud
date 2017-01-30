/*
//      /bin/soul/atmos.c
//      from the Nightmare Mudlib
//      everyone's soul commands
//      created by Jubal@TMI 0.8 910120
//      Tinkered by Balowski for Vortex (3.2@314), June '95
//	Tinkered again for Nirvana, Sept '96
*/
#define SOUL_DB "/players/balowski/daemons/soul.db"
#define SOUL_SAVE "players/balowski/daemons/atmos"
#define MESSAGE_EFUN
#define NO_MAPPINGS

mixed atmos;
static int line;

void
reset(int arg) {
    if (arg)
	return;
    if (restore_object(SOUL_SAVE)) {
#ifdef NO_MAPPINGS
	atmos = order_alist(atmos);
#endif
	return;
    }
#ifdef NO_MAPPINGS
    atmos = ({ ({ }), ({ }), });
#else
    atmos = ([ ]);
#endif
    line = 1;
#ifdef NOISY    
#ifdef MESSAGE_EFUN
    message("broadcast", "Atmos shouts: A new reality has begun!\n", users());
#else
    shout("Atmos shouts: A new reality has begun!\n");
#endif
#endif
    set_heart_beat(1);
}

/**********************************************************************
	Define the flags we need for various types of cmds.
*/

/* the default adverb for the cmd is overridden by an environment
   variable */
#define ENVIRONMENT 0x0001

/* use the optional verb instead of the query_verb() one */
#define OVERB 0x0002

/* apostrophize the target's name */
#define APOSTROPHE 0x0004

/* always use the adverb */
#define FORCEADVERB 0x0008

/* definitions for non-standard formats */
#define FORMAT0 0x0100
#define FORMAT1 0x0200
#define FORMAT2 0x0400
#define FORMAT (FORMAT0|FORMAT1|FORMAT2)

/* special variables used by the messages */
#define OBJECTIVE 0x0010
#define POSSESSIVE 0x0020
#define SUBJECTIVE 0x0040
#define VARIABLE (OBJECTIVE|POSSESSIVE|SUBJECTIVE)


/**********************************************************************
	expand_macro() expands the $ variables.
*/

private string
expand_macro( string msg, int flags, int personal )
{
    string s1, s2;

    if (flags & OBJECTIVE) while( sscanf( msg, "%s$O%s", s1, s2 ) == 2 )
		msg = s1 + ( personal ? "your"
			    	      : objective(this_player()) ) + s2;
    if( flags & POSSESSIVE ) while( sscanf( msg, "%s$P%s", s1, s2 ) == 2 )
		msg = s1 + ( personal ? "your"
			    	      : possessive(this_player()) ) + s2;
    if( flags & SUBJECTIVE ) while( sscanf( msg, "%s$S%s", s1, s2 ) == 2 )
		msg = s1 + ( personal ? "you"
			    	      : subjective(this_player()) ) + s2;
    return msg;
}


/**********************************************************************
	describe_action() takes the pieces of cmd outputs and puts them
	together into messages, and displays them to the appropriate
	people.
*/

static string *
describe_action(string verb, object victim, string pre, string post, int flags)
{
    object pob;
    string src_name, victim_name, v_ext;
    string msg, v_msg, by_msg;
    int i;

    if (! verb || this_player()->query_ghost() ||
	(i = strlen( verb ) ) < 2) return 0;
    if (verb[i-1] == 's' || verb[i-1] == 'x' || verb[i-1] == 'z' ||
	verb[i-1] == 'o' || verb[i-1] == 'h' &&
	(verb[i-2] == 't' || verb[i-2] == 'c' || verb[i-2] == 's' ))
      v_ext = "es";
    else v_ext = "s";
    verb = " " + verb;
    post = ( post ? " " + post + "." : "." );

    pob = this_player();
    src_name = (string) pob -> query_name() || "Someone";

    if (victim)	{
	pre = ( pre ? " " + pre + " " : " " );
	victim_name = (string) victim -> query_name() || "Someone";
	if (flags & APOSTROPHE) {
	    victim_name += "'" +
	      ( victim_name[ strlen( victim_name ) - 1 ] != 's' ? "s" : "" );
	}
    }
    else {
	victim_name = "";
	pre = ( pre ? " " + pre : "" );
    }

    /* tell the commander */
    msg = "You" + verb + pre + victim_name + post + "\n";    
    if (flags & VARIABLE) msg = expand_macro(msg, flags, 1);

    /* tell the commandee */
    if (victim)	{
	v_msg = src_name + verb + v_ext + pre + "you" +
	  (flags & APOSTROPHE ? "r" : "") + post + "\n";
	if (flags & VARIABLE) v_msg = expand_macro( v_msg, flags, 0 );
    }
    else
      victim = this_object();

    /* tell the innocent bystanders */
    by_msg = src_name + verb + v_ext + pre + victim_name + post + "\n";
    if (flags & VARIABLE) by_msg = expand_macro(by_msg, flags, 0);
    return ({ msg, v_msg, by_msg, });
}


/**********************************************************************
	extract_args() splits a string into a name and adjective.  If
	there is an object around the player which responds to the
	first word of the string, and is living (and is not the player
	herself), then the first element in the return array will be
	the living object.  The second argument will either be the rest
	of the argument string, or the entire string if no match is
	found.  If the found object is not living, or is the player
	herself, then extract_args() returns 0.
*/

static mixed *
extract_args(string arg, object *ppl)
{
    string name, adj;
    object victim;
    int i;

    if (!arg || arg == "") return ({ 0, 0 });
    if (sscanf( arg, "%s %s", name, adj) < 2) {
	name = arg;
    }
    if (victim = present("shardak_qt", this_player())) {
	name = (string) victim->query_nickname(name);
	victim = 0;
    }
    /*victim = present( name, environment( previous_object() ) );*/
    i = sizeof(ppl);
    while (i--) {
	if (ppl[i] && ppl[i]->id(name)) {
	    victim = ppl[i];
	    break;
	}
    }
    if (!victim) {
	adj = arg;
    }
    else {
	if (!living(victim) || victim == this_player()) return 0;
    }
    return ({ victim, adj });
}


/**********************************************************************
	do_soul() is the command hook which receives control from the
	player object to determine if a soul command has been called,
	and take appropriate action if this is the case.
*/

int do_cmd(string verb, string args, string chan, object *ppl)
{
    mixed *dat, *argv;
    string adverb, *msgs;

    /* check if the command exists */
#ifdef NO_MAPPINGS
    if(!(dat = assoc(verb, atmos))) return 0;
#else
    if(!(dat = atmos[verb])) return 0;
#endif

    /* parse the argument string */
    if (!(argv = extract_args(args, ppl))) return 0;

    /* check if we need an environment override */
    if (argv[1]) adverb = argv[1];
    if (!adverb && (dat[0] & ENVIRONMENT)) {
	adverb = (string) previous_object()->getenv(verb);
    }
    if (adverb && (dat[0] & FORCEADVERB) && dat[2]) {
	adverb = dat[2] + " " + adverb;
    }
    else if (!adverb) {
	adverb = dat[2];
    }
    if (adverb && !strlen(adverb)) adverb = 0;

    if (!(dat[0] & FORMAT))
      msgs = describe_action(dat[0] & OVERB ? dat[4] : verb,
		      argv[0],
		      argv[0] ? dat[1] : 0,
		      adverb ? adverb : 0,
		      dat[0]);
    else if (dat[0] & FORMAT0)
      msgs = describe_action(dat[0] & OVERB ? dat[4] : verb,
		      0,
		      adverb ? adverb : 0,
		      0,
		      dat[0]);
    else if (dat[0] & FORMAT1)
      msgs = describe_action(dat[0] & OVERB ? dat[4] : verb,
		      argv[0],
		      (dat[3] ? dat[3] : "") +
		       (dat[3] && argv[0] ? " " : "") +
		       (argv[0] ? dat[1] : ""),
		      adverb ? adverb : 0,
		      dat[0] );
    else if (dat[0] & FORMAT2)
      msgs = describe_action(dat[0] & OVERB ? dat[4] : verb,
		      argv[0],
		      argv[0] ? dat[1] : dat[3],
		      adverb ? adverb : 0,
		      dat[0]);

    previous_object()->message(chan, msgs[0], this_player());
    if (msgs[1])
    previous_object()->message(chan, msgs[1], argv[0]);
    previous_object()->message(chan, msgs[2], ppl,
			       ({ this_player(), argv[0] }));
    return 1;
}


/**********************************************************************
	The heart_beat() is used when the object is first loaded to
	read in the command data file 10 lines at a time so that a
	heavy initial load is not placed on the system to set up soul
	commands.
*/

heart_beat()
{
    string *dat;
    int i;

    dat = read_file(SOUL_DB, line, 10);
    if (dat) dat = explode(dat, "\n");
    if (dat) for (i = 0; i < sizeof(dat); i++, line++) {
	string *expl;
	int j, flags;

	if(!dat[i] || dat[i] == "") continue;
	if(dat[i][0] == '#') continue;
	expl = explode( dat[i] + ":", ":" );
	if( ! expl || sizeof( expl ) < 6 ) continue;
	if( strlen( expl[0] ) == 0 ) continue;

	/* clean up the data */
	if( ! strlen( expl[2] ) ) expl[2] = 0;
	if( ! strlen( expl[3] ) ) expl[3] = 0;
	if( ! strlen( expl[4] ) ) expl[4] = 0;
	if( ! strlen( expl[5] ) ) expl[5] = 0;

	/* parse flags */
	flags = 0;
	for( j=0 ; j<strlen( expl[1] ) ; j++ )
	  switch( expl[1][j] ) {
	    case 'E': flags |= ENVIRONMENT; break;
	    case 'V': if( expl[5] ) flags |= OVERB; break;
	    case 'A': flags |= APOSTROPHE; break;
	    case 'F': flags |= FORCEADVERB; break;
	    case '0': flags |= FORMAT0; break;
	    case '1': flags |= FORMAT1; break;
	    case '2': flags |= FORMAT2; break;
	    case 'O': flags |= OBJECTIVE; break;
	    case 'P': flags |= POSSESSIVE; break;
	    case 'S': flags |= SUBJECTIVE; break;
	  }

	/* insert the command into the atmos alist */
#ifdef NO_MAPPINGS
	atmos = insert_alist(expl[0],
			     ({ flags, expl[2], expl[3], expl[4], expl[5] }),
			     atmos );
#else
	atmos[expl[0]] = ({ flags, expl[2], expl[3], expl[4], expl[5] });
#endif
    }
    if (i < 10) {
	set_heart_beat( 0 );
#ifdef NOISY	    
#ifdef MESSAGE_EFUN
	message("broadcast", "Atmos shouts: Our souls are "
		"now complete.\n", users());
#else
	shout("Atmos shouts: Our souls are now complete.\n");
#endif
#endif
	line = -1;
    }
}

/* too bad that I can't read anything when this_player is 0 */
status
force() {
    if (line == -1) line = 1;
    heart_beat();
    if (line == -1) write("Finished\n");
    return 1;
}

mixed *
query_atmos( string verb )
{
#ifdef NO_MAPPINGS
    return assoc(verb, atmos);
#else
    return atmos[verb];
#endif
}

string *
query_feelings()
{
#ifdef NO_MAPPINGS
    return atmos[0];
#else
    return m_indices(atmos);
#endif
}

#ifdef __VERSION__
void show_feelings() {
    write_file("/players/balowski/feelings.out",
	sprintf("%-#80s\n", implode(sort_array(query_feelings(), #'>), "\n")));
}
#endif
void save_me() { save_object(SOUL_SAVE);}
