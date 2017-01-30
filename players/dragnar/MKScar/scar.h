/* Adding these to make his defines work... - Rumplemintz */
#define CYA CYN
#define NOSTYLE NORM

#define SCAROBJ   "/players/dragnar/MKScar/scar"
#define SAVE_PATH "players/dragnar/MKScar/kills/"
#define KILL_LOG "players/dragnar/MKScar/log/Kills"
#define CHANNAME  "Blood"
#define CHANNELD "/bin/channel_daemon"
#define LOGFILE   "/players/dragnar/logs/scar.log"
#define CHAMPLOG  "/players/dragnar/logs/champions.log"
#define KILLS "/players/dragnar/logs/kills.log"
#define CMDDIR "/players/dragnar/MKScar/cmds/"
#define MKDIR "/players/beck/MortalKombat/"
#define HELPDIR "/players/dragnar/MKScar/help/"
#define LOGDIR "/players/dragnar/MKScar/log/"
#define ERROR "/players/dragnar/MKScar/Error.log"
#define TOPLIST "players/dragnar/MKScar/daemons/TopList"

#define CHALLENGE "players/dragnar/MKScar/daemons/Challenge"
#define MAP "players/dragnar/daemons/mapping"
#define RANK "players/dragnar/MKScar/daemons/MKRank"
#define ACTIONS "players/dragnar/MKScar/daemons/actions"
#define user environment(this_object())
#define RN user->query_real_name()
#define capname capitalize(RN)
#define SCAR (present("bloodscar", this_player()))
#define Rank RANK->QRank(capname);
#define WARRIORS ([ "Kano":MKDIR+"Kano", "Liu Kang": MKDIR+"LiuKang", "Johnnie Cage": MKDIR+"JohnnieCage","Rayden":MKDIR+"Rayden", "Sub-Zero":MKDIR+"SubZero","Reptile":MKDIR+"Reptile","Sonya":MKDIR+"Sonya","Scorpion":MKDIR+"Scorpion","Goro":MKDIR+"Goro",])
