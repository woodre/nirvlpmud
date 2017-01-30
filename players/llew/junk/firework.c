#include "/players/llew/closed/ansi.h"
#include "/obj/user/junk_only.c"

string *colors;
int been_lit;
string fire,col1,col2,col3;

reset(arg) {
   if(arg) return;
   colors = ({ RED,WHT,BLU,GRN,YEL,MAG,CYN, });
   col1 = colors[random(7)];
   col2 = colors[random(7)];
   col3 = colors[random(7)];
}

id(str) { return str == "firework" || str == "rocket"; }

short() { return "A large firework"; }
long() { write("A cardboard tube which puts on a dazzling display when lit.\nYou should light the rocket.\nNote: Channel junk must be on to see effect.\n");
}
get() { return 1; }
query_weight() { return 3; }
query_value() { return 500; }
init() {
   add_action("light","light"); }

light(str) {
   if((!str) || !id(str)) {return 0;}
   if(been_lit) { return 0; }
   write("You set off a large firework.\n");
   say(this_player()->query_name()+" lights a large firework...\n");
   command("drop firework",this_player());
   call_out("effect",5);
   been_lit = 1;
   return 1;
}

effect() {
   chan_msg("A firework shoots into the sky...  WHOOSH!\n");
   call_out("effect"+random(5),10);
}

effect0() {
   fire="\n\t\t       "+col1+BOLD+"*\n"+NORM;
   fire+="\n\n\t\t   "+col1+"*       *"+NORM;
   fire+="\n\t\t      "+col2+BOLD+"* "+NORM+col2+"*\n"+NORM;
   fire+="\n\t\t    "+col2+"*  "+BOLD+col3+"*  "+BOLD+col2+"*\n"+NORM;
   fire+="\t\t"+col1+BOLD+"*     "+NORM+col3+"* *     "+BOLD+col1+"*\n"+NORM;
   fire+="\t\t    "+BOLD+col2+"*  "+col3+"*  "+NORM+col2+"*\n"+NORM;
   fire+="\n\t\t      "+col2+"* "+BOLD+"*\n"+NORM;
   fire+="\t\t   "+col1+"*       *\n\n\n\t\t       "+BOLD+col1+"*\n\n"+NORM;
   chan_msg(fire);
   destruct(this_object());
}

effect1() {
   fire="\n\t\t     "+col1+"*\n"+NORM;
   fire+="\t\t "+BOLD+col1+"*  "+col2+"*"+col1+"*"+col2+"*  "+col1+"*\n"+NORM;
   fire+="\t\t  "+col2+"*  "+col1+"*  "+col2+"*\n"+NORM;
   fire+="\t\t     "+BOLD+col1+"*\n"+NORM;
   fire+="\t\t "+BOLD+col2+"*  *"+col1+"*"+col2+"*  *\n"+NORM;
   fire+="\t\t"+col1+"*"+BOLD+"*"+NORM+col1+"*"+BOLD+"*"+NORM+col1+"*"+col2+"*"+col1+"*"+BOLD+"*"+NORM+col1+"*"+BOLD+"*"+NORM+col1+"*\n"+NORM;
   fire+="\t\t "+BOLD+col2+"*  *"+col1+"*"+col2+"*  *\n"+NORM;
   fire+="\t\t     "+BOLD+col1+"*\n"+NORM;
   fire+="\t\t  "+col2+"*  "+col1+"*  "+col2+"*\n"+NORM;
   fire+="\t\t "+BOLD+col1+"*  "+col2+"*"+col1+"*"+col2+"*  "+col1+"*\n"+NORM;
   fire+="\t\t     "+col1+"*\n"+NORM;
   chan_msg(fire);
   destruct(this_object());
}

effect2() {
   fire="\n\t\t    "+BOLD+col1+"*\n"+NORM;
   fire+="\t\t "+BOLD+col2+"*  "+NORM+col1+"*  "+BOLD+col2+"*\n"+NORM;
   fire+="\t\t  "+col2+"* "+BOLD+col1+"* "+NORM+col2+"*\n"+NORM;
   fire+="\t\t   "+BOLD+col2+"* *\n"+NORM;
   fire+="\t\t"+BOLD+col1+"*"+NORM+col1+"*"+BOLD+"* "+WHT+"O "+col1+"*"+NORM+col1+"*"+BOLD+"*\n"+NORM;
   fire+="\t\t   "+BOLD+col2+"* *\n"+NORM;
   fire+="\t\t  "+col2+"* "+BOLD+col1+"* "+NORM+col2+"*\n"+NORM;
   fire+="\t\t "+BOLD+col2+"*  "+NORM+col1+"*  "+BOLD+col2+"*\n"+NORM;
   fire+="\t\t    "+BOLD+col1+"*\n\n"+NORM;
   chan_msg(fire);
   destruct(this_object());
}

effect3() {
   fire="\n"; 
   fire+="\t\t        "+col1+"*                   *    \n"+NORM;
   fire+="\t\t       "+BOLD+col1+"* *       "+col2+" * "+col1+"       * *   \n"+NORM;
   fire+="\t\t        "+col1+"*"+col2+"         *"+col1+"         *    \n"+NORM;
   fire+="\t\t               "+BOLD+col2+"*"+NORM+col2+" * *"+BOLD+col2+" *           \n"+NORM;
   fire+="\t\t                  "+BOLD+col2+"*              \n"+NORM;
   fire+="\t\t         "+BOLD+col2+"*"+col1+"   *"+col2+"    *"+col1+"    *"+col2+"   *     \n"+NORM;
   fire+="\t\t        "+col2+" *                 *     \n"+NORM;
   fire+="\t\t      "+BOLD+col2+"*"+NORM+col2+" * *"+BOLD+" * "+NORM+col1+"    *"+BOLD+col2+"     *"+NORM+col2+" * *"+BOLD+" *  \n"+NORM;
   fire+="\t\t        "+col2+" *                 *     \n"+NORM;
   fire+="\t\t         "+BOLD+col2+"*"+col1+"   *"+col2+"    *"+col1+"    *"+col2+"   *     \n"+NORM;
   fire+="\t\t                  "+BOLD+col2+"*              \n"+NORM;
   fire+="\t\t               "+BOLD+col2+"*"+NORM+col2+" * *"+BOLD+col2+" *           \n"+NORM;
   fire+="\t\t        "+col1+"*"+col2+"         *"+col1+"         *    \n"+NORM;
   fire+="\t\t       "+BOLD+col1+"* *       "+col2+" * "+col1+"       * *   \n"+NORM;
   fire+="\t\t        "+col1+"*                   *    \n"+NORM;
   chan_msg(fire);
   destruct(this_object());
}


effect4() {
   while(col2==col1 || col2==col3) col2=colors[random(7)];
   fire="\n";
   fire+="\t\t     "+BOLD+col3+" *                  *\n"+NORM;
   fire+="\t\t     "+BOLD+col3+"*"+NORM+col3+"*"+BOLD+"*                *"+NORM+col3+"*"+BOLD+"*\n"+NORM;
   fire+="\t\t      "+BOLD+col3+"*"+NORM+col3+" *              *"+BOLD+" *\n"+NORM;
   fire+="\t\t      "+BOLD+col3+"    *          *\n"+NORM;
   fire+="\t\t      "+BOLD+col2+" *"+NORM+col3+"    *      * "+BOLD+col2+"   *\n"+NORM;
   fire+="\t\t      "+BOLD+col2+"*"+NORM+col2+"*"+BOLD+"*"+col3+"    *    * "+col2+"   *"+NORM+col2+"*"+BOLD+"*\n"+NORM;
   fire+="\t\t       "+BOLD+col2+"*"+NORM+col2+" *"+col3+"    *  *"+col2+"    *"+BOLD+" *\n"+NORM;
   fire+="\t\t           "+BOLD+col2+"*"+col3+"  *  * "+col2+" *\n"+NORM;
   fire+="\t\t        "+BOLD+col1+"*"+NORM+col2+"   *"+col3+"  ** "+col2+" *"+BOLD+col1+"   *\n"+NORM;
   fire+="\t\t       "+BOLD+col1+"*"+NORM+col1+"*"+BOLD+"*"+NORM+col2+"   *"+col3+" **"+col2+" *"+BOLD+col1+"   *"+NORM+col1+"*"+BOLD+"*\n"+NORM;
   fire+="\t\t        "+BOLD+col1+"*"+NORM+col1+" *"+BOLD+col2+"  *"+NORM+col3+" **"+BOLD+col2+" *"+NORM+col1+"  *"+BOLD+" *\n"+NORM;
   fire+="\t\t           "+BOLD+col1+"*"+NORM+col2+"  *"+col3+"**"+col2+"*"+BOLD+col1+"  *\n"+NORM;
   fire+="\t\t            "+col1+"*"+col2+" *"+col3+"**"+col2+"*"+col1+" *\n"+NORM;
   fire+="\t\t            "+BOLD+col1+"*"+NORM+col2+" *"+col3+"**"+col2+"*"+BOLD+col1+" *\n"+NORM;
   fire+="\t\t             "+col1+"*"+col2+"*"+col3+"**"+col2+"*"+col1+"*\n"+NORM;
   fire+="\t\t             "+col1+"*"+col2+"*"+col3+"**"+col2+"*"+col1+"* \n"+NORM;
   chan_msg(fire);
   destruct(this_object());
}
