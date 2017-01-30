/*----------------------------------------------------------------------*/
/*      Monk Definitions                                                */
/*                                                                      */
/*      Edited and improved by Pain 30 OCT 94                           */
/*      version 1.0                                                     */
/*                                                                      */
/*  version 2.0 Pain 30 SEP 2002                                        */
/*----------------------------------------------------------------------*/

/*      INCLUDES and DEFINITIONS                                        */
#define ESC ""
#define WHITE ESC+"[1m"
#define BOLD WHITE
#define BLINK ESC+"[5m"
#define REVERSE ESC+"[7m"
#define RED ESC+"[31m"
#define GREEN ESC+"[32m"
#define YELLOW ESC+"[33m"
#define BLUE ESC+"[34m"
#define PURPLE ESC+"[35m"
#define LIGHT_BLUE ESC+"[36m"
#define END ESC+"[0m"
#define REV_RED ESC+"[41m"
#define REV_GREEN ESC+"[42m"
#define REV_BROWN ESC+"[43m"
#define REV_BLUE ESC+"[44m"
#define REV_PURPLE ESC+"[45m"
#define REV_L_BLUE ESC+"[46m"
#define OFF END
#define PUR ESC+"[35m"
#define YEL ESC + "[33m"
#define GRE ESC+"[32m"
#define BLU ESC+"[34m"
#define CYA ESC + "[36m"
#define WHI ESC+"[37m"
#define TP this_player()
#define ETP environment(this_player())
#define ETO environment(this_object())
#define PAIN "/players/pain/guild/monk_daemon"
#define ME capitalize(this_player()->query_name())
#define TPN this_player()->query_name()
#define IT capitalize(obj->query_name())
#define LVLAC this_player()->set_ac
#define POBJ "/players/pain/guild/testobj"
#define HIM capitalize(TP->query_attack()->query_name())
#define STR call_other(TP, "query_attrib", "str")
#define PIE call_other(TP, "query_attrib", "pie")
#define STA call_other(TP, "query_attrib", "sta")
#define DIR "players/pain/guild/PLAYERS/"+this_player()->query_real_name()
#define ROBE present("mrobe",this_player())
