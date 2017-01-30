#include "/players/eurale/defs.h"
object buyer,pet;
int coins,stats;

id(str) { return str == "vending machine" || str == "vending" || 
          str == "machine"; }

short() { return BOLD+"A Vending Machine"+NORM; }

long() { write(
	"  A functional vending machine to take care of any adventurer.\n"+
	"To look at a list of items available here, just type 'list'. To\n"+
	"get any of the items, simply type 'vend <item>'.\n");
        }
        
get() { return 0; }  /* This makes it so that people can not pick it up*/

init() {
   add_action("llist","list");   /*list action , reason why the function 
                                   is llist is because other things might 
                                   list */
   add_action("Vend","vend");    
}

llist() {
  write("These are the things you may vend at no cost..\n\n"+
	"gear	:	obsidian plate, ring, helm mask\n"+
	"pole	:	kunjukdan\n"+
	"bag	:	a bottomless bag\n"+
	"ticket	:	a ticket to the testroom\n"+
	"coins  :       money (10k increments)\n"+
	"exp    :	experience (1 mil increments)\n"+
	"shirt :	a Vampire Guild T-shirt\n"+
	"gem	:	a sparkling gem\n"+
	"jukebox	a stat jukebox\n"+
	"triangle	a glowing light\n"+
	"\n");
  return 1;}

Vend(str) {
  if(str == "jukebox") {
    write("A jukebox appears before your very eyes.\n");
    move_object(clone_object("players/eurale/OBJ/jukebox.c"),
      environment(TP));
    return 1; }
  if(str == "coins" && TP->query_real_name() == "eurale") {
    write("You feel your money purse get heavier...\n");
    TP->add_money(10000);
    return 1; }
  if(str == "exp" && TP->query_real_name() == "euboy") {
    write("You feel your experience increasing.....\n");
    TP->add_exp(1000000);
    return 1; }
if(str == "sword") {
  move_object(clone_object("/players/eurale/Dis/Hood/OBJ/bsword.c"),TP);
  write("You get a PHBS.\n");
  return 1; }
if(str == "tadji") {
  move_object(clone_object("/players/eurale/Lab/OBJ/tadji.c"),TP);
  write("You get a tadji.\n");
  return 1; }
if(str == "gem") {
  move_object(clone_object("players/eurale/Fiend/OBJ/emerald.c"),
        this_player());
  write("You receive a sparkling gem.\n");
  return 1; }
  if(str == "gear") {
    move_object(clone_object("players/eurale/Arm/obsidian_plate.c"),
		this_player());
    move_object(clone_object("players/eurale/Fiend/OBJ/mask"),
		TP);
  move_object(clone_object("players/eurale/Hotel/OBJ/headdress"),
		this_player());
    move_object(clone_object("players/eurale/Fiend/OBJ/catseye_ring"),
		this_player());
  write("You get:  plate  mask  helm  ring\n");
    return 1; }
if(str == "bag") {
  move_object(clone_object("players/eurale/OBJ/lbag.c"),TP);
  write("You receive a bag.\n"); return 1; }
if(str == "pole") {
  move_object(clone_object("players/eurale/Space/OBJ/kunjukdan"),TP);
  write("You receive a kunjukdan.\n"); return 1; }
if(str == "sham") {
    move_object(clone_object("players/eurale/closed/shamrock.c"),this_player());
    write("You receive a lovely shamrock.\n"); return 1; }
if(str == "button" && TPRN == "euboy") {
  move_object(clone_object("players/eurale/OBJ/button"),TP);
  write("You sew on a shiney brass button.\n");
  return 1; }

if(str == "shirt") {
  move_object(clone_object("/players/eurale/VAMPIRES/OBJ/E_tshirt.c"),TP);
  write("You receive your Vampire T-shirt.\n"); return 1; }
}
