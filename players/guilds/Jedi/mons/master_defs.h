#include <ansi.h>
#define TIME random(4)+1
#define Name capitalize((string) this_object()->query_name())
#define LOG "/players/dragnar/Jedi/logs/Skills"

status BUSY;        /* Am I training? */
status Training;    /* Mode: 0 - Knowledge; 1 - Training */
string *skills;     /* The skills I can train */
string *Info;       /* Info avail. about guild */
object gob;         /* Jedi guild object on this_object() */
object Trainee;     /* Person being trained */
int counter;        /* Status for HB for being attacked */
status Member;      /* Is the person a guild member? */
object Jedi;        /* Guild object on the Trainee */
status Skills;      /* Does trainee have skill pts? */
int StartPoints;    /* Skill points I started with */
