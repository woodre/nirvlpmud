#include "defs.h"

#define sk1      "     .xxxxxxx.    "+OFF
#define sk2      "    dXXXXXX"+BOLD+"XX"+OFF+"Xb   "+OFF      
#define sk3      "   dXXXXXXXXX"+BOLD+"X"+OFF+"Xb  "+OFF
#define sk4      "   xXXXXXXXXXXXx  "+OFF
#define sk5      "  `XXP~"+BOLD+"~9"+OFF+"XP~"+BOLD+"~9"+OFF+"XX' "+OFF
#define sk6      "   `Xb..dXb..dX'  "+OFF
#define sk7      "    ,XXX/|\\XXX,   "+OFF
#define sk8      "   `X~XXxXxXX~X'  "+OFF
#define sk9      "      XXXXXXX     "+OFF
#define sk10     "      `XXXXX'     "+OFF
#define sk11 YEL+"       |  d|      "+OFF
#define sk12 YEL+"       | xX|      "+OFF
#define sk13 YEL+"       | XX|      "+OFF
#define sk14     "      dXXXXXb     "+OFF
#define sk15     "     dXXXX"+BOLD+"XX"+OFF+"Xb    "+OFF
#define sk16     "     X`9XXXX"+BOLD+"X"+OFF+"P    "+OFF
#define sk17     "     `b. XXXP'    "+OFF
#define sk18     "       ~~~~~      "+OFF
#define spacer   "                  "
#define SKULL   ({ sk1,sk2,sk3,sk4,sk5,sk6,sk7,sk8,sk9,sk10 })
#define BALL    ({ sk14,sk15,sk16,sk,sk17,sk18 })
#define STAFF   ({ sk11,sk12,sk13 })
revcutstring(string str, int length){
string strb;
int i;
  if(!length || length < 0)
    length = 20;
  str = "                                                                                  "+str;
  i = strlen(str);
  strb = str[i-length..i-1];
  return strb;
}  

cutstring(string str, int length){
string str2;
  if(!length || length < 0)
    length = 20;
  str = str+"                                                                                  ";
  str2 = str[0..length];
  return str2;
}  