/* Player manipulation Macros 		*/

#define TP this_player()
#define ME this_player()->query_real_name()
#define CME this_player()->query_name()
#define ROBE present("new_mrobe", this_player())
#define RANK ROBE->query_rank()
#define GXP ROBE->query_gxp()
#define MYSP TP->query_sp()
#define MYHP TP->query_hp()
#define NO_SP write("You do not have enough spell points\n");
#define LOW_RANK write("Your guild level is not high enough.\n");

/* Daemons			*/

#define CHATD "/players/gowron/closed/monk/chatd"

/* Paths			*/

#define HOME "/players/gowron/closed/monk/"
#define SAVEDIR HOME+"save/"
#define BINDIR "/players/gowron/closed/monk/bin/"

/* Stuff
			*/

#define RANK_LIST ({ 1,20000,50000,120000,230000,550000,840000,1500000,2600000,304000, });

