/* #include "/players/mythos/dmon/def.h" */
#include "/players/mythos/droom/desertvr.c"
reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light_switch(2);
    set_short(RED+"Sylan Desert"+NORM,0);
    set_long("It is "+RED+"HOT"+NORM+"\n"+
             "A heat so tortuous and powerful that the senses writhe in agony.\n"+
             "The angry sun beats down upon you and sounds are deadened.\n"+
             "The eye has no place to go for all is too bright and too intense.\n"+
             "Neverending sand stretches out before you.\n",0);
    set_grid(0,0);
} }
