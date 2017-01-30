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
        int total,str_bonus,dex_bonus;
        total = 0;
   if(no_go_time < time()) no_go_over = 0;
   if(no_go_over >= 2) return;
   no_go_time = time();
   no_go_over += 1;
        if(!USER) return 0; /* just a test!  added by verte 6.23.01 */
/*
        str_bonus = USER->query_attrib("str");
*/
            str_bonus = present("dknight_ob",this_player())->query_combat();
/*
             if(present("dknight_ob",TP)->query_offwep()) dex_bonus = 6+random(10);
*/
        
        
        /********  This only happens if no Wep is wielded **********/
        if(USER->query_weapon() == this_object()){
                total += clawstwo();
                total += clawstwo();
        }
        /**********************************************************/
        
/*
        total += (1+random(str_bonus)); 
*/
        total += (str_bonus);
/*
        total += str_bonus + dex_bonus; 
*/
        
        if(!environment(this_object())->query_attack()) return 0;  /* added by verte 6.23.01 */ 

if(USER->query_real_name() == "pestilence") tell_object(USER, "TOTAL2 IS: "+total+".\n");
        return total;
}
