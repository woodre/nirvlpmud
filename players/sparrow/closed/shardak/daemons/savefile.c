/*
 * Daemon for storing and restoring player profiles
 */
#include "/players/balowski/lib.h"
#include "../def.h"
inherit BASE;

static string	Name;	          /* name of last restore person */
int               guild_class;
int		      pkills;         /* registered player kills */
status            muffled;        /* guild channel muffle */
string            wstmsg;         /* message for waste spell */
string            DragonName;     /* name of dragon (lowercase) */
mapping           Skills;         /* permanent skills */

int               solved;         /* bit field with solved tasks */
			                /* easy for computers to interpret ;-) */
status            frozen;         /* frozen by the law */
mixed		      *Boards;	    /* alist of notes read per bboard */

void
save(string nam, int cla, int sol, status fro, status muf,
     string wst, string dra, mixed *boa, status col)
{
    Name = nam;
    guild_class = cla;
    pkills = 0;
    muffled = muf;
    wstmsg = wst;
    DragonName = dra;
    Skills = 0;
    solved = sol;
    frozen = fro;
    Boards = boa;
    
    save_object(SAVE_PATH + nam);
}

mixed 
restore(string nam)
{
    Name = nam;
    if (!restore_object(SAVE_PATH + Name)) return 0;
    Boards = order_alist(Boards);
    return ({
	guild_class, solved, frozen, muffled, wstmsg,
        DragonName, Boards,
	  });
}


show() {
    write("Name: " + Name + "\n" +
	  "guild_class: " + guild_class + "\n" +
	  "solved: " + solved + "\n" +
	  "frozen: " + frozen + "\n" +
	  "muffled: " + muffled + "\n" +
	  "wstmsg: " + wstmsg + "\n" +
	  "DragonName: " + DragonName + "\n" +
          "Boards: " + typeof(Boards)+"\n");
}
