#include "/obj/ansi.h"

#define GUILDNAME "Neo Symbiotes"
#define DIR "players/forbin/closed/neo/"
#define GUILD_FILE DIR+"gob.c"
#define CMDDIR "/"+DIR+"cmds/"
#define HELP "/"+DIR+"help/"
#define LOGS DIR+"logs/"
#define OBJECTS "/"+DIR+"obj/"
#define SAVE_PATH DIR+"/members/"
#define SAVE_BAK SAVE_PATH+"/bak/"
#define NEO environment(this_object())
#define GOB present("neo_symbiote_object", this_player())

#define PGC ((string)gob->query_pgcol())
#define SGC ((string)gob->query_sgcol())
#define TGC NORM+HIW

#define VALIDSKILL ({ "combat", "control", "creation", })
#define VALIDSTORE ({ "hp", "sp", "mp", "coins", })

#define COM ((int)gob->query_skill("combat"))
#define CON ((int)gob->query_skill("control"))
#define CRE ((int)gob->query_skill("creation"))

#define BCOM (skills["combat"])
#define BCON (skills["control"])
#define BCRE (skills["creation"])

#define QN query_name()
#define QRN query_real_name()
#define POS query_possessive()  /*  his her  */
#define PRO query_pronoun()     /*  he she  */
#define OBJ query_objective()   /*  him her  */

#define QL query_level()
#define QEL query_extra_level()

#define CAP capitalize
                               
#define HELPLINE SGC+"<<"+PGC+"==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-=="+SGC+">>"+NORM+"\n"
#define HELPTITLE SGC+"<<"+HIW+colour_pad(colour_pad(title, -((56+strlen(title)) / 2)), 56)+SGC+">>"+NORM+"\n"

#define GHOST this_player()->query_ghost()


#define TOU tell_object(User, 
#define ENV environment
#define TRU tell_room(User,
