static status wielded;
static int no_go_time;
static int no_go_over;
static object wielded_by;
static int broke;
static int eff_wc;
static int misses,hits;
static int save_flag,class_of_weapon;
static object hit_func;
static string type;
static string *message_hit;
gen_wc_bonus(){
        int total,str_bonus;
        total = 1;
   if(no_go_time < time()) no_go_over = 0;
   if(no_go_over >= 2) return;
   no_go_time = time();
   no_go_over += 1;
        if(!USER) return 0; /* just a test!  added by verte 6.23.01 */
/*
        str_bonus = USER->query_attrib("str");
*/
        str_bonus = USER->query_attrib("wil");
        
        
        /********  This only happens if no Wep is wielded **********/
        if(USER->query_weapon() == this_object()){
                total += clawstwo();
                total += clawstwo();
        }
        /**********************************************************/
        


/*
        total += str_bonus / 5;
*/
       total += str_bonus / (1 + random(2));
/*
          if(TP->query_guild_rank == 1);
          total += str_bonus / 20;
          if(TP->query_guild_rank == 2);
          total += str_bonus / 10;
          if(TP->query_guild_rank == 3);
          total += str_bonus / 10 +1;
          if(TP->query_guild_rank == 4);
          total += str_bonus / 5;
          if(TP->query_guild_rank == 5);
          total += str_bonus / 4;
          if(TP->query_guild_rank == 6);
          total += str_bonus / 4 + 1;
          if(TP->query_guild_rank == 7);
          total += str_bonus / 3;
          if(TP->query_guild_rank == 8);
          total += str_bonus / 2;
*/

        
        if(!environment(this_object())->query_attack()) return 0;  /* added by verte 6.23.01 */

if(USER->query_real_name() == "pestilence") tell_object(USER, "TOTAL2 IS: "+total+".\n");
        return total;
}
