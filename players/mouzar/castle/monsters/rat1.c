/*
Changed the long description from:
           set_long("his eye. He looks like he has seen many horrors in his life.\n");
-Feldegast 9-26-00
*/
 
inherit"/obj/monster";
 
reset(arg) {
::reset(arg);
if(!arg) 
 
            set_name("rat");
            set_short("A furry rat");
              set_long("This is a furry brown rat with vicious teeth.\n");
            set_level(3);
            set_hp(45);
            set_wc(7);
            set_ac(4);
            }
         
 
