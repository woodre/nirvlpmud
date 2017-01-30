inherit "/obj/monster.c";
#include <ansi.h>

#define TO this_object() 
#define ENV environment

reset(arg) {
  ::reset(arg);
  if(arg) return;
   
  set_name("mob");
  set_race("critter");

  set_short("A test mob");
  set_long(
    "  A test mob.\n"+
    "  A test mob.\n");
  set_al(0);

  set_level(27);
  set_hp(1900);
  set_wc(58);
  set_ac(27);
  set_wc_bonus(26);
  set_hp_bonus(600);


  set_gender("male");
  /*set_dead_ob(this_object());*/
  set_aggressive(0);
  set_chat_chance(0);
   load_chat("chat 1.\n");
   load_chat("chat 2.\n");
   load_chat("chat 3.\n");
   
   
  }
  
  
init() {
  ::init();
 
tell_room(ENV(TO),"  \n"); 
tell_room(ENV(TO),HIR+"                                                  ,888b.                \n"+NORM);
tell_room(ENV(TO),HIR+"                                                 88b."+NORM+RED+"*                  \n"+NORM);
tell_room(ENV(TO),HIR+"                                               ,d88'"+NORM+RED+"**                  \n"+NORM);
tell_room(ENV(TO),HIR+"                                             ,d88'"+NORM+RED+"****                  \n"+NORM);
tell_room(ENV(TO),HIR+"                                           ,d88'"+NORM+RED+"******                  \n"+NORM);
tell_room(ENV(TO),HIR+"                                         ,d88'"+NORM+RED+"*********                 \n"+NORM);
tell_room(ENV(TO),HIR+"                                        ,d8'"+NORM+RED+"************                \n"+NORM);
tell_room(ENV(TO),HIR+"                                      ,d8"+NORM+RED+"****************               \n"+NORM);
tell_room(ENV(TO),HIR+"                                    ,d88"+NORM+RED+"**************"+NORM+HIR+"..d**'            \n"+NORM);
tell_room(ENV(TO),HIR+"                                  ,d88'"+NORM+RED+"*********"+NORM+HIR+"..d8*'"+NORM+RED+"****              \n"+NORM);
tell_room(ENV(TO),HIR+"                                ,d888'"+NORM+RED+"****"+NORM+HIR+"..d8P*'"+NORM+RED+"********               \n"+NORM);
tell_room(ENV(TO),HIR+"                        .     ,d8888*8888*'"+NORM+RED+"*************                \n"+NORM);
tell_room(ENV(TO),HIR+"                      ,*     ,88888*8P"+NORM+RED+"*****************                 \n"+NORM);
tell_room(ENV(TO),HIR+"                    ,*      d888888*8b."+NORM+RED+"****************                 \n"+NORM);
tell_room(ENV(TO),HIR+"                  ,P       dP  *888.*888b."+NORM+RED+"**************                \n"+NORM);
tell_room(ENV(TO),HIR+"                ,8*        8    *888*8'"+NORM+RED+"**"+NORM+HIR+"88888b."+NORM+RED+"*********               \n"+NORM);
tell_room(ENV(TO),HIR+"              ,dP                *88 8b."+NORM+RED+"*******"+NORM+HIR+"88b."+NORM+RED+"******               \n"+NORM);
tell_room(ENV(TO),HIR+"             d8'                  *8b 8b."+NORM+RED+"***********"+NORM+HIR+"8b."+NORM+RED+"***              \n"+NORM);
tell_room(ENV(TO),HIR+"           ,d8'                    *8. 8b."+NORM+RED+"**************"+NORM+HIR+"88b.            \n"+NORM);
tell_room(ENV(TO),HIR+"          d8P                       88. 8b."+NORM+RED+"***************              \n"+NORM);
tell_room(ENV(TO),HIR+"        ,88P                        888  8b."+NORM+RED+"************                \n"+NORM);
tell_room(ENV(TO),HIR+"       d888*       .d88P            888   8b."+NORM+RED+"*********                  \n"+NORM);
tell_room(ENV(TO),HIR+"      d8888b..d888888*              888    8b."+NORM+RED+"*******        "+NORM+HIR+"*          \n"+NORM);
tell_room(ENV(TO),HIR+"    ,888888888888888b.              888     8b."+NORM+RED+"*****         "+NORM+HIR+"8          \n"+NORM);
tell_room(ENV(TO),HIR+"   ,8*;88888P*****788888888ba.      888      8b."+NORM+RED+"****         "+NORM+HIR+"8'         \n"+NORM);
tell_room(ENV(TO),HIR+"  ,8;,8888*        '88888*         d88*       8b."+NORM+RED+"***        "+NORM+HIR+"8'          \n"+NORM);
tell_room(ENV(TO),HIR+"  )8e888*          ,88888be.       888         8b."+NORM+RED+"**      "+NORM+HIR+",8'           \n"+NORM);
tell_room(ENV(TO),HIR+" ,d888            ,8888888***     d888          88b."+NORM+RED+"*    "+NORM+HIR+"d8'            \n"+NORM);
tell_room(ENV(TO),HIR+",d88P            ,8888888Pb.     d888'           888b.  d8'             \n"+NORM);
tell_room(ENV(TO),HIR+"888*            ,88888888**   .d8888*                   d8'             \n"+NORM);
tell_room(ENV(TO),HIR+"'88            ,888888888    .d88888b                  d88'             \n"+NORM);
tell_room(ENV(TO),HIR+" 'P           ,8888888888bd888888*                     d88'             \n"+NORM);
tell_room(ENV(TO),HIR+"              d888888888888d888*                       d88'             \n"+NORM);
tell_room(ENV(TO),HIR+"              8888888888888888b.                        d88'            \n"+NORM);
tell_room(ENV(TO),HIR+"              88*. *88888888888b.        .db             d888'          \n"+NORM);
tell_room(ENV(TO),HIR+"              '888b.'8888888888888b. .d8888P               d888'        \n"+NORM);
tell_room(ENV(TO),HIR+"               **88b.'*8888888888888888888888b...            d888'      \n"+NORM);
tell_room(ENV(TO),HIR+"                *888b.'*8888888888P***7888888888888e.          d888'    \n"+NORM);
tell_room(ENV(TO),HIR+"                 88888b.'********.d8888b**  '88888P*            d888'   \n"+NORM);
tell_room(ENV(TO),HIR+"                 '888888b     .d88888888888**  '8888.            d888'  \n"+NORM);
tell_room(ENV(TO),HIR+"                  )888888.   d888888888888P      '8888888b.       d8888'\n"+NORM);
tell_room(ENV(TO),HIR+"                 ,88888*    d88888888888**'        '8888b          d888'\n"+NORM);
tell_room(ENV(TO),HIR+"                ,8888*    .8888888888P'              '888b.        d888'\n"+NORM);
tell_room(ENV(TO),HIR+"               ,888*      888888888b...                '88P88b.  d8888' \n"+NORM);
tell_room(ENV(TO),HIR+"      .db.   ,d88*        88888888888888b                '88888888888   \n"+NORM);
tell_room(ENV(TO),HIR+"  ,d888888b.8888'         '*888888888888888888P'              ******    \n"+NORM);
tell_room(ENV(TO),RED+" /"+NORM+HIR+"*****8888b**'              '***8888P*''8888'                          \n"+NORM);
tell_room(ENV(TO),RED+"  /"+NORM+HIR+"**88'                    ,d888888b.8888'                             \n"+NORM);
tell_room(ENV(TO),RED+"                       /"+NORM+HIR+"*****8888b**'                                   \n"+NORM);
tell_room(ENV(TO),RED+"                         /"+NORM+HIR+"**88'                                         \n"+NORM);
tell_room(ENV(TO),"  \n");
tell_room(ENV(TO),CYAN+" ^   ^   "+NORM+HIR+"____                                 "+NORM+HIC+"_____ _ _            "+NORM+CYAN+" ^   ^ \n"+NORM);
tell_room(ENV(TO),CYAN+"/|\\ /|\\ "+NORM+HIR+"|  _ \\ _ __ __ _  __ _  ___  _ __  "+NORM+HIC+"  |  ___| (_) ___  ___  "+NORM+CYAN+"/|\\ /|\\\n"+NORM);
tell_room(ENV(TO),CYAN+" |   |  "+NORM+HIR+"| | | | '__/ _` |/ _` |/ _ \\| '_ \\  "+NORM+HIC+" | |_  | | |/ _ \\/ __| "+NORM+CYAN+" |   | \n"+NORM);
tell_room(ENV(TO),CYAN+" |   |  "+NORM+HIR+"| |_| | | | (_| | (_| | (_) | | | |  "+NORM+HIC+"|  _| | | |  __/\\__ \\  "+NORM+CYAN+"|   | \n"+NORM);
tell_room(ENV(TO),CYAN+" |   |  "+NORM+HIR+"|____/|_|  \\__,_|\\__, |\\___/|_| |_|"+NORM+HIC+"  |_|   |_|_|\\___||___/"+NORM+CYAN+"  |   | \n"+NORM);
tell_room(ENV(TO),CYAN+" |   |  "+NORM+HIR+"                 |___/                "+NORM+HIC+"                      "+NORM+CYAN+"|   | \n"+NORM);
tell_room(ENV(TO),"  \n");


/*
  ____                                 _____ _ _           
 |  _ \ _ __ __ _  __ _  ___  _ __    |  ___| (_) ___  ___ 
 | | | | '__/ _` |/ _` |/ _ \| '_ \   | |_  | | |/ _ \/ __|
 | |_| | | | (_| | (_| | (_) | | | |  |  _| | | |  __/\__ \
 |____/|_|  \__,_|\__, |\___/|_| |_|  |_|   |_|_|\___||___/
                  |___/                                    
*/




}

/*
heart_beat() {
  ::heart_beat();
  
 tell_room(environment(this_object()), "HEARTBEAT 1\n");
}
*/

