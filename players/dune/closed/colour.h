#define esc "
#define WHITE esc+"[1m"
#define BOLD WHITE
#define BLINK esc+"[5m"
#define REVERSE esc+"[7m"
#define RED esc+"[31m"
#define GREEN esc+"[32m"
#define BROWN esc+"[33m"
#define YELLOW BROWN+BOLD
#define BLUE esc+"[34m"
#define MAGENTA esc+"[35m"
#define CYAN esc+"[36m"
#define END esc+"[0m"
#define REV_RED esc+"[41m"
#define REV_GREEN esc+"[42m"
#define REV_BROWN esc+"[43m"
#define REV_BLUE esc+"[44m"
#define REV_MAGENTA esc+"[45m"
#define REV_CYAN esc+"[46m"
#define OFF END

#define BLK "[30m"          /* Black    */
#define GRN "[32m"          /* Green    */
#define YEL "[33m"          /* Yellow   */
#define BLU "[34m"          /* Blue     */
#define MAG "[35m"          /* Magenta  */
#define CYN "[36m"          /* Cyan     */
#define WHT "[37m"          /* White    */

                /*   Hi Intensity Foreground Colors   */

#define HIR "[1;31m"        /* Red      */
#define HIG "[1;32m"        /* Green    */
#define HIY "[1;33m"        /* Yellow   */
#define HIB "[1;34m"        /* Blue     */
#define HIM "[1;35m"        /* Magenta  */
#define HIC "[1;36m"        /* Cyan     */
#define HIW "[1;37m"        /* White    */

                /*  Background Colors  */

#define BBLK "[40m"          /* Black    */
#define BRED "[41m"          /* Red      */
#define BGRN "[42m"          /* Green    */
#define BYEL "[43m"          /* Yellow   */
#define BBLU "[44m"          /* Blue     */
#define BMAG "[45m"          /* Magenta  */
#define BCYN "[46m"          /* Cyan     */
#define BWHT "[47m"          /* White    */

                /* High Intensity Background Colors  */

#define HBRED "[41;1m"       /* Red      */
#define HBGRN "[42;1m"       /* Green    */
#define HBYEL "[43;1m"       /* Yellow   */
#define HBBLU "[44;1m"       /* Blue     */
#define HBMAG "[45;1m"       /* Magenta  */
#define HBCYN "[46;1m"       /* Cyan     */
#define HBWHT "[47;1m"       /* White    */
