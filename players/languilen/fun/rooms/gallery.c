#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPRN this_player()->query_real_name()
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";

int paid, offx, offy;
string shooter;

void set_offset();
int validate_offset(int a,int b);

reset(arg) {
   if(arg) return;
   set_light(1);
   paid = 0;
   short_desc = "Shooting gallery";
   long_desc =
"   This is really two rooms in one separated by a low counter that runs wall\n\
to wall.  A pistol, mounted in the center of the counter, has a slot for coins\n\
right next to it.  On the far wall there is a target made up of the numbers 1\n\
through 9 and a sign for you to read.\n";

   items = ({
      "counter","The top is smooth and has a pistol attached to it by a swivel mount",
      "pistol","The sights look a bit loose but it's functional.  It has a slot next to it",
      "mount","The swiveling mount secures the pistol to the counter so it can't be taken",
      "slot","the slot is marked '25 coins'.  You might be able to insert some",
      "target","   "+BOLD+BLK+"a b c d e\n\
   f "+NORM+HIW+"1 2 3"+NORM+BOLD+BLK+" g\n\
   h "+HIW+"4 "+HIR+"5"+NORM+HIW+" 6"+NORM+BOLD+BLK+" i\n\
   j "+HIW+"7 8 9"+NORM+BOLD+BLK+" k\n\
   l m n o p"+NORM+"",
   });

   dest_dir = ({
	AREA+"gameroom.c","out",
   });
}
init(){
    ::init();
    add_action("insert_coins","insert");
    add_action("shoot_pistol","shoot");
    add_action("read_sign","read");
}
read_sign(str){
     if(!str || str != "sign"){
        notify_fail("Are you trying to 'read' the 'sign'?\n");
        return 0;
     }
     write(HIR+"   *-  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  -*"+NORM+"\n\n");
     write("\
                     Shooting Gallery Rules \n\n\
     First insert some coins to load the gun with ammo.  Take a good\n\
     look at the target, you'll get three tries to hit the center (the 5).\n\
     You will be notified any time you hit any of the targets numbers.\n\
     The letters are there to help you aim and are counted as a miss.\n\
     You may 'shoot at' anything on the target (letters or numbers)\n\
     until your ammo runs out.  Good luck!\n\n");
     write(HIR+"   *-  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --  -*"+NORM+"\n");
     return 1;
}

int insert_coins(string str){
    if( !str || str != "coins" ) {
       notify_fail("Usage: insert coins.\n");
       return 0;
    }
    if(paid){
       if( present(lower_case(shooter)) ){
          write(shooter + " is already playing!  You will have to wait your turn.\n");
          return 1;
       }
    }
    if( TP->query_money() < 25 ) {
       notify_fail("You don't have enough money to play this game!\n");
       return 0;
    }
    TP->add_money(-25);
    set_offset();
    while(validate_offset(offx,offy)){ set_offset(); }
    paid = 3;
    shooter = (string)TPN;
    write("You put the money in the slot and the gun fills with ammo.\n");
    say(shooter + " puts coins in the slot and the pistol fills with ammo.\n");
    return 1;
}

int shoot_pistol(string str){
    int i, z, x, y, xo, yo;
    string tar;
    mixed *target;
    if(!paid) {
       notify_fail("You need to pay if you want to play!\n");
       return 0;
    }
    if( shooter != (string)TPN && present(lower_case(shooter)) ){
       write(shooter + " is already playing!  You'll have to wait your turn.\n");
       return 1;
    }
    if(!str) {
       notify_fail("Usage: shoot at <target>.\n");
       return 0;
    }
    if( sscanf(str,"at %s",tar) != 1 ) {
       notify_fail("Usage: shoot at <target>.\n");
       return 0;
    }
    target = ({ ({ "a", "b", "c", "d", "e" }), ({ "f", "1", "2", "3", "g" }),
             ({ "h", "4", "5", "6", "i" }), ({ "j", "7", "8", "9", "k" }),
             ({ "l", "m", "n", "o", "p" }) });

    z = 0;
    while(z < 5){
          y = member_array(tar,target[z]);
          if( -1 < y ){
             x = z;
             xo = x+offx;
             yo = y+offy;
             write("You aim carefully at the " + target[x][y] + " and...BANG!\n");
             say((string)TPN + " aim's carefully...And shoots!\n");
             --paid;
             if( (x+offx) < 1 || (y+offy) < 1 ){
                write("You missed the target.  Try again.\n");
                say((string)TPN + " missed the target completly.\n");
                return 1;
             }
             if( (x+offx) > 3 || (y+offy) > 3 ){
                write("You missed the target.  Try again.\n");
                say((string)TPN + " missed the target completly.\n");
                return 1;
             }
             if( x+offx == 2 && y+offy == 2 ){
                write("Congratulations!  You hit the bullseye!!\n");
                write("You feel a bit more experienced...\n");
                say((string)TPN + " hit the bullseye!\n");
                i=random(6)+10;
                TP->add_exp(i);
                write_file("/players/languilen/fun/log/gallery_log",ctime()+" ** "+TPRN+" made "+i+" exp.\n");
                return 1;
             }
             write("You hit the "+ target[xo][yo] +" instead...Try again.\n");
             say((string)TPN + "hit the " + target[xo][yo] + ".\n");
             return 1;
          }
          ++z;
    }
    write("You must shoot at one of the numbers or letters on the target!\n");
    return 1;
}

void set_offset(){
    offx = random(4)-2;
    offy = random(4)-2;
}

validate_offset( a, b ){
    if( a == 0 && b == 0 ) return 1;
    if( abs(a) != 2 && abs(b) != 2 ) return 1;
    return 0;
}
int abs(int x){
    if(x>-1) return x;
    else return -x;
}
realm(){ return "NT"; }
