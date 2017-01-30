#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset()
{
    object reindeer, money, antlers;
    int i;
   string sht, nme;

    i = 0;
    if (!present("reindeer")) {
	while(i<9) {
	    reindeer = clone_object("obj/monster");
	call_other(reindeer, "set_hp", 140);
call_other(reindeer, "set_ac", 3);
	call_other(reindeer, "set_wc", 12);
	call_other(reindeer, "set_al", 500);
  if (i==0)
 {
    sht="Vixen";
   nme = "vixen";
   }
  if(i==1)
 {
    sht="Comet";
   nme = "comet";
 }
  if(i==2)
 {
    sht="Cupid";
   nme = "cupid";
}
  if(i==3)
{
    sht="Donner";
   nme = "donner";
}
  if(i==4)
{
    sht="Blitzen";
   nme = "blitzen";
 }
  if(i==5)
{
    sht="Rudolph the red nosed reindeer";
    nme = "rudolph";
 }
  if(i ==8)
 {
   sht="Dasher";
 nme = "dasher";
 }
  if (i==6) {
   sht="Prancer";
   nme = "prancer";
  }
  if (i==7) {
   sht ="Dancer";
   nme="dancer";
  }
    call_other(reindeer, "set_name", nme);
    call_other(reindeer, "set_short", sht);
    call_other(reindeer, "set_alias", "reindeer");
	call_other(reindeer, "set_long",
  "One of Santa's flying reindeer.\n");
	call_other(reindeer, "set_aggressive", 0);
call_other(reindeer, "set_al", 500);
call_other(reindeer, "set_level", 6);
	    move_object(reindeer, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(400));
        move_object(money, reindeer);
antlers = clone_object("obj/weapon");
call_other(antlers, "set_id", "antlers");
 call_other(antlers, "set_name", "antlers");
call_other(antlers, "set_short", "Magical reindeer antlers");
call_other(antlers, "set_long", "Magical reindeer antlers\n");
call_other(antlers, "set_value", 200);
call_other(antlers, "set_weight", 3);
call_other(antlers, "set_class", 5);
move_object(antlers, reindeer);
 i+=1;
	}
    }
}

ONE_EXIT("players/boltar/santaland/wkshp3.c", "south",
 "The reindeer's place",
 "You are now in the stables outside the workshop. This area appears to be the\n"+
  "housing for many animals. Could this be the place where santa keeps\n"+
 "his reindeer?\n", 1)
