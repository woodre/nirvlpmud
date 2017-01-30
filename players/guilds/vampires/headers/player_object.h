/*  Player Related Defines for easier coding  */
/*  Please use these defines when editing in  */
/*  the vampire guild directories. This will  */
/*  help maintain consistency across all the  */
/*  guild files.                              */

#define ETP environment(this_player())
#define TP this_player()
#define TPN this_player()->query_name()
#define TPRN this_player()->query_real_name()
#define TPPOS this_player()->query_possessive()  /*  his/her  */
#define TPPRO this_player()->query_pronoun()     /*  he/she   */
#define TPOBJ this_player()->query_objective()   /*  him/her  */
#define TPL this_player()->query_level()
#define TPXL  this_player()->query_extra_level()
#define TPTL this_player()->query_total_level()
#define TPAC this_player()->query_ac()
#define TPWC this_player()->query_wc()
#define TPHP this_player()->query_hp()
#define TPSP this_player()->query_spell_point()
#define TPATTRIB(x) this_player()->query_attrib(x)
#define TPDEX this_player()->query_attrib("dex")
#define TPCHA this_player()->query_attrib("cha")
#define TPSTR this_player()->query_attrib("str")
#define TPSTA this_player()->query_attrib("sta")
#define TPWIL this_player()->query_attrib("wil")
#define TPMAG this_player()->query_attrib("mag")
#define TPPIE this_player()->query_attrib("pie")
#define TPSTE this_player()->query_attrib("ste")
#define TPLUC this_player()->query_attrib("luc")
#define TPINT this_player()->query_attrib("int")
#define TPGEXP this_player()->query_guild_exp()

/*  Object Related Defines for easier coding  */
/*  Please use these defines when editing in  */
/*  the vampire guild directories. This will  */
/*  help maintain consistency across all the  */
/*  guild files.                              */

#define ENV environment
#define ETOATTRIB(x) ETO->query_attrib(x)
#define ETODEX ETO->query_attrib("dex")
#define ETOCHA ETO->query_attrib("cha")
#define ETOSTR ETO->query_attrib("str")
#define ETOSTA ETO->query_attrib("sta")
#define ETOWIL ETO->query_attrib("wil")
#define ETOMAG ETO->query_attrib("mag")
#define ETOPIE ETO->query_attrib("pie")
#define ETOSTE ETO->query_attrib("ste")
#define ETOLUC ETO->query_attrib("luc")
#define ETOINT ETO->query_attrib("int")
#define ETO environment(this_object())
#define TO this_object()
#define ROOM ETP
#define PREV       previous_object()
#define TELLOBJ(x,y) tell_object(x,y)
#define TELLROOM(x,y) tell_room(x,y)
#define CLONE(x)   clone_object(x)
#define MOVE(x)    move_object(x)
#define FOREACH(arr, x)   for(x=0;x<sizeof(arr);x++)
#define FORALL(x, y) for(x=first_inventory(y);x;x=next_inventory(x))


