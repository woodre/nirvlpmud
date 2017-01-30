#include "/players/softly/closed/ansi.h"
#define player this_player()
inherit "/room/room";
int str;
  reset(arg) {
  if(arg) return;
  ::reset();

short_desc = "test1 ";
long_desc = "test2 ";
  }
init() {
{
    ::init();
add_action("cmd_hook","");
}

call_out("fall1",1);
return 1; }

fall1() {
tell_object(player,
"  Your feet leave the safety of the platform and with\n\
no railing too protect you you find yourself....\n\n");
call_out("fall2",5);
return 1; }

fall2() {
tell_object(player,
"  f\n\
      a\n\
         l\n\
            l\n\
               i\n\
                  n\n\
                     g\n\n"); 
call_out("fall3",5);
return 1; }

fall3() {
tell_object(player,
"  Through the mist that reaches out to caress  your flesh...\n\n");
call_out("fall4",3);
return 1; }

fall4() {
tell_object(player,
"          f\n\
              a\n\
                 l\n\
                    l\n\
                       i\n\
                          n\n\
                             g\n\n"); 
call_out("fall5",7);
return 1; }

fall5() {
tell_object(player,
"  Through the mist that reaches out to caress your flesh...\n\n");
call_out("fall6",3);
return 1; }

fall6() {
tell_object(player,
"               f\n\
                   a\n\
                      l\n\
                         l\n\
                            i\n\
                               n\n\
                                  g\n\n"); 
call_out("fall7",3);
return 1; }

fall7() {
tell_object(player,
" Until in a final THUD, your fragile body smashes on the jagged rocks.n\n"); 
return 1; }
/* no teleport */
  realm() { return "NT"; }

status hurt_em();

  int maxhp, x, y;

  /* take away .8*max hp + a random component between 0 and maxhp ... should die 80% of the time */
   maxhp = (this_player()->query_max_hp())
   x = random(maxhp);
   y = x + ((maxhp/10)*8);
   hit_player(this_player,y);
   /* ACK !!! */
                               
  /* s/he's dead ... or not ... so put 'em on the rocks */
{
    move_object(this_player(), "/players/softly/point/rooms/pt5"));
    return 1;
}
