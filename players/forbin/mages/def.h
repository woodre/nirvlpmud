#include "/players/forbin/ansi.h"

#define GUILDNAME "Mages"
#define GUILD_FILE "players/forbin/mages/spellbook"
#define DIR "/players/forbin/mages/"
#define CMDDIR "/players/forbin/mages/cmds/"
#define SPELLS "/players/forbin/mages/spells/"
#define HELP "/players/forbin/mages/help/"
#define SAVE_PATH "players/forbin/mages/member/"
#define SAVE_BAK SAVE_PATH+"/bak/"
#define MAGE environment(this_object())
#define MAGEGOB present("forbin_mage_object", this_player())

#define SHORTLINE SGC+"["+PGC+"*"+SGC+"]"+PGC+"================================================"+SGC+"["+PGC+"*"+SGC+"]"+QGC
#define LOGO SGC+"["+PGC+"*"+SGC+"]"+PGC
#define SPELL_DAEMON "/players/forbin/mages/daemons/spell_daemon.c"

#define VALIDSCHOOLS ({ "abju", "conj", "ench", "evoc", "divi", "illu", "necr", "tran", "abjuration", "conjuration", "enchantment", "evocation", "divination", "illusion", "necromancy", "transmutation", })
#define VALIDATTRIBS ({ "power", "will power", "intelligence", "wisdom", })

#define TOP tell_object(player,
#define TRP tell_room(environment(player),

#define PGC ((string)gob->query_guild_color())
#define SGC PGC+BOLD
#define TGC NORM+HIW
#define QGC NORM+WHT

#define ABJU ((int)gob->query_school("abju") + (int)gob->query_school_bonus("abju"))
#define CONJ ((int)gob->query_school("conj") + (int)gob->query_school_bonus("conj"))
#define ENCH ((int)gob->query_school("ench") + (int)gob->query_school_bonus("ench"))
#define EVOC ((int)gob->query_school("evoc") + (int)gob->query_school_bonus("evoc"))
#define DIVI ((int)gob->query_school("divi") + (int)gob->query_school_bonus("divi"))
#define ILLU ((int)gob->query_school("illu") + (int)gob->query_school_bonus("illu"))
#define NECR ((int)gob->query_school("necr") + (int)gob->query_school_bonus("necr"))
#define TRAN ((int)gob->query_school("tran") + (int)gob->query_school_bonus("tran"))

#define LABJU (Schools["abju"] + SchoolsBonus["abju"])
#define LCONJ (Schools["conj"] + SchoolsBonus["conj"])
#define LENCH (Schools["ench"] + SchoolsBonus["ench"])
#define LEVOC (Schools["evoc"] + SchoolsBonus["evoc"])
#define LDIVI (Schools["divi"] + SchoolsBonus["divi"])
#define LILLU (Schools["illu"] + SchoolsBonus["illu"])
#define LNECR (Schools["necr"] + SchoolsBonus["necr"])
#define LTRAN (Schools["tran"] + SchoolsBonus["tran"])

#define POW ((int)gob->query_attrib("power") + (int)gob->query_attrib_bonus("power"))
#define WIL ((int)gob->query_attrib("will") + (int)gob->query_attrib_bonus("will"))
#define INT ((int)gob->query_attrib("intelligence") + (int)gob->query_attrib_bonus("intelligence"))
#define WIS ((int)gob->query_attrib("wisdom") + (int)gob->query_attrib_bonus("wisdom"))

#define LPOW (Attribs["power"] + AttribsBonus["power"])
#define LWIL (Attribs["will power"] + AttribsBonus["will power"])
#define LINT (Attribs["intelligence"] + AttribsBonus["intelligence"])
#define LWIS (Attribs["wisdom"] + AttribsBonus["wisdom"])

#define TP this_player()
#define PO previous_object()
#define GOB previous_object()