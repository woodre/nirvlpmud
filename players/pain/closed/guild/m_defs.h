/*----------------------------------------------------------------------*/
/*      Monk Definitions                                                */
/*                                                                      */
/*      Edited and improved by Pain 30 OCT 94                           */
/*      version 1.0                                                     */
/*                                                                      */
/*  version 2.0 Pain 30 SEP 2002                                        */
/*----------------------------------------------------------------------*/

/*      INCLUDES and DEFINITIONS                                        */
#define esc ""
#define WHITE esc+"[1m"
#define BOLD WHITE
#define BLINK esc+"[5m"
#define REVERSE esc+"[7m"
#define RED esc+"[31m"
#define GREEN esc+"[32m"
#define YELLOW esc+"[33m"
#define BLUE esc+"[34m"
#define PURPLE esc+"[35m"
#define LIGHT_BLUE esc+"[36m"
#define END esc+"[0m"
#define REV_RED esc+"[41m"
#define REV_GREEN esc+"[42m"
#define REV_BROWN esc+"[43m"
#define REV_BLUE esc+"[44m"
#define REV_PURPLE esc+"[45m"
#define REV_L_BLUE esc+"[46m"
#define OFF END
#define PUR ESC+"[35m"
#define YEL ESC + "[33m"
#define RED ESC+"[31m"
#define GRE ESC+"[32m"
#define BLU ESC+"[34m"
#define CYA ESC + "[36m"
#define WHI ESC+"[37m"
#define TP this_player()
#define ETP environment(this_player())
#define ETO environment(this_object())
#define PAIN "/players/pain/guild/monk_daemon"
#define ME capitalize(this_player()->query_name())
#define IT capitalize(obj->query_name())
#define LVLAC this_player()->set_ac
#define POBJ "/players/pain/guild/testobj"
#define HIM capitalize(TP->query_attack()->query_name())
#define STR call_other(TP, "query_attrib", "str")
#define PIE call_other(TP, "query_attrib", "pie")
#define STA call_other(TP, "query_attrib", "sta")
#define DIR "players/pain/guild/PLAYERS/"+this_player()->query_real_name()
