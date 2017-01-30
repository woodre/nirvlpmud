#include "/players/cosmo/closed/esc.h"

/* Colors */
#define BLK ESC+"[30m"          /* Black    */
#define RED ESC+"[31m"          /* Red      */
#define GRN ESC+"[32m"          /* Green    */
#define YEL ESC+"[33m"          /* Yellow   */
#define BLU ESC+"[34m"          /* Blue     */
#define MAG ESC+"[35m"          /* Magenta  */
#define CYN ESC+"[36m"          /* Cyan     */
#define WHT ESC+"[37m"          /* White    */
#define HIR ESC+"[1;31m"        /* Red      */
#define HIG ESC+"[1;32m"        /* Green    */
#define HIY ESC+"[1;33m"        /* Yellow   */
#define HIB ESC+"[1;34m"        /* Blue     */
#define HIM ESC+"[1;35m"        /* Magenta  */
#define HIC ESC+"[1;36m"        /* Cyan     */
#define HIW ESC+"[1;37m"        /* White    */
#define BOLD ESC+"[1m"          /* Turn on bold mode */
#define BLINK ESC+"[5m"         /* Initialize blink mode */
#define NORM ESC+"[2;37;0m"     /* Puts everything back to normal */

/* Common function definitions */
#define TP this_player()
#define TPN TP->query_name()
#define TPL TP->query_level()
#define TPRN TP->query_real_name()
#define TPAL TP->query_alignment()
#define TPAT TP->query_attrib
#define TPMP TP->move_player
#define TO this_object()
#define MO move_object
#define CO clone_object
#define PO previous_object()
#define CAP capitalize

/* Directory definitions */
#define DCDIR "players/cosmo/dc/"
#define DCLOG DCDIR+"log/"
#define DCMON DCDIR+"mon/"
#define DCARM DCDIR+"armor/"
#define DCWEP DCDIR+"weap/"
#define DCOBJ DCDIR+"obj/"
#define DCROOM DCDIR+"rooms/"
#define DCBLDG DCROOM+"bldgs/"
#define DCSTR DCROOM+"street/"
#define DCPATH DCROOM+"path/"
