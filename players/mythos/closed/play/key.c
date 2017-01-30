#include "/players/mythos/closed/guild/def.h"

id(str) { return str == "keys" || str == fear || str == pact ||
                 str == "mageobj" || str == "mage_obj" || 
                 str == "None" || str == "spellbook" || 
                 str == "book" || str == "guild_object" ||
                 str == "Mizan-guild-object" ||
                 str == "lump" || str == "clay" || 
                 str == "robe" || str == "mrobe" || 
                 str == "monk robe" || str == "notarmor"|| 
                 str == "Implants" || str == "implant" || 
                 str == "either implants" || str == "implants" || 
                 str == "CyberNinja Implants" ||
                 str == "medal" || str == "medallion" ||
                 str == "guild_medal" || str == "pro_object" ||
                 str == "guild_death_object" ||
                 str == "instrument" || str=="bard_obj" || 
                 str == "guild_obj" ||
                 str=="nooneelse vampire fangs" ||
                 str=="vampirefangs" || str=="vampire fangs" || 
                 str=="fangs" || str=="guild item" || 
                 str=="guild_item" || str=="guild obj" ||
                 str=="guild item: fangs" ||
                 str == "shardak_mark" || str == "mark"; }

get() { return 0; }
drop() { return 1; }

query_on() { return 1;}
query_original() { return 1;}
query_telepathy() { return 1;}
