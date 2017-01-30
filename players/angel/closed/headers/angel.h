/* EVERYTHING FROM HERE ON NEEDS TO HAVE IT'S */
/* STRINGS ADDED BY THE DRIVER AT LOADING AND */
/* NOT AT ACTUAL RUNTIME */
#pragma combine_strings

/* BASIC THINGS WE NEED LATER */
#include <security.h>
#include "/players/vital/closed/lib/lib.h"

/* ME - OH YES - ME */
#define ANGEL "angel"

/* DIRECTORY RELATED STUFF */
#define BASE        "/players/angel/"
#define CLOSED      BASE + "closed/"
#define STD         CLOSED + "std/"
#define HEADERS     CLOSED + "headers/"
#define DEST        BASE + "dest/"

/* OBJECT RELATED STUFF */
#define WORKROOM    (BASE + "workroom/workroom")

#define LIGHT		set_light(0)
#define SET_LIGHT	set_light

#define C(x)		capitalize(x)
#define L(x)		lower_case(x)
#define CAP(x)      capitalize(x)
#define LOW(x)      lower_case(x)
#define ENV         environment
#define MEMBER(x,arr)	(member_array(x,arr)>=0)
#define MUDHOST		query_host_name()
#define OUT(str)	write(str+"\n")
#define FOREACH(arr,x)	for(x=0;x<sizeof(arr);x++)
#define FORALL(x, y) for(x=first_inventory(y);x;x=next_inventory(x))
#define FILTER(set)	if (!str)return 0;if(!MEMBER(L(str),(explode(set,"#"))))return 0
#define NOTIFY(mes)	{OUT(mes);return 1;}
#define FAIL(mes)	notify_fail(mes+"\n"); return 0
#define GETENV(x)	x=ENV(ME);if(!x)return

/* PLAYER RELATED DEFINES */
#define ME		    this_object()
#define PL		    this_player()
#define TP          this_player()
#define QN          query_name()
#define QRN         query_real_name()
#define QL          query_level()
#define TPN         TP->QN
#define TPRN        TP->QRN
#define CTPN        CAP(TPN)
#define CTPRN       CAP(TPRN)
#define TPP         this_player()->query_possessive()
#define LVL         TP->QL
#define FP(x)       find_player(x)

/* OBJECT RELATED DEFINES */
#define TO          this_object()
#define CO(x)       clone_object(x)
#define LO(x)       load_object(x)
#define MO(x,y)     move_object(x,y)
#define MP(x)       move_player(x)
#define FO(x)       find_object(x)
#define MOVE(x,y)	MO(x,y)
#define DESTRUCT(ob)	destruct(ob)
#define IS_WIZARD(o)    (o->QL>=20)
#define OWNER(ob)	L(ENV(ob)->QRN())

/* SHORTCUTS FOR ME */
#define NULL			0
#define INTEGER			1
#define STRING			2
#define OBJECT			3
#define ARRAY			4
#define SLOT			5
#define INDEX			6
#define ASTERISK		7
#define MAPPING			8
#define RESULT			9
#define CLOSURE			10
#define SYMBOL			11
#define FLOAT			12
#define DELAY			13
#define S_ARRAY			14
#define S_MAPPING		15
#define S_CLOSURE		16
#define S_SYMBOL		17
#define S_FLOAT			18
#define S_STRING		19
#define S_OBJECT		20
#define S_EFUN			21
#define SUBCALL			22
#define MULTIARG		23

#define FALSE NULL
#define TRUE INTEGER

#define INDEXTYPE_UNKNOWN	"unknown"
#define INDEX_PLAIN		    "plain"
#define INDEX_INTERVAL		"interval"
#define INDEX_RIGHTBORDER	"rightborder"
#define INDEX_RBORDER		"rborder"
#define INDEX_LEFT		    "left"
#define INDEX_RIGHT		    "right"

#define H_BANNER	INTEGER
#define H_CENTER	STRING
#define HEADLINE(x)	write (headline(x,NULL));
#define CENTER(x)	write (headline(x,H_CENTER));
#define BANNER(x)	write (headline(x,H_CENTER|H_BANNER));

object armor, ring, helmet, misc, amulet, boots, shield;
object coins;
object human;
string str, name, alias, alt_name, race;
int x, y, z;
