inherit "obj/treasure";

#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

#define ENV environment(this_object())

int first, second;
int health;
int COUNT, WHICH;
string *songs;

reset(arg)  {
  if(arg) return;
    songs= ({
"Jingle Bells",
"Jingle Bells",
"Jingle all the way",
"Oh what fun",
"It is to ride",
"In a one horse open sleigh",
"Jingle Bells",
"Jingle Bells",
/* end song */
"Rudolf the "+HIR+"Red Nosed"+HIG+" Reindeer",
"Had a very shiny nose",
"And if you ever saw him",
"You would even say it glows",
"All of the other reindeer",
"Used to laugh and call him names",
"They never let poor Rudolf",
"Join in the reindeer games",
/* end song */
"Then one foggy Christmas Eve",
"Santa came to say",
"Rudolf with your nose so bright,",
"Won't you guide my sleigh tonight?",
"Then all the reindeer loved him",
"And they shouted out with glee",
"Rudolf the "+HIR+"Red Nosed"+HIG+" Reindeer",
"You'll go down in history!",
/* end song */
"God rest ye merry gentlemen",
"Let nothing you dismay",
"Remember Christ our Saviour",
"Was born on Christmas day",
"To save us all from Satan's power",
"When we had gone astray",
"Oh tidings of comfort and joy, Comfort and joy",
"Oh tidings of comfort and joy",
/* end song */
"Deck the halls with boughs of holly, ",
"Fa la la la la, la la la la. ",
"Tis the season to be jolly, ",
"Fa la la la la, la la la la. ",
"Don we now our gay apparel, ",
"Fa la la, la la la, la la la. ",
"Troll the ancient Yule tide carol, ",
"Fa la la la la, la la la la.",
/* end song */
"It's beginning to look a lot like Christmas",
"Ev'rywhere you go;",
"Take a look in the five-and-ten, glistening once again",
"With candy canes and silver lanes aglow.",
"It's beginning to look a lot like Christmas,",
"Toys in ev'ry store,",
"But the prettiest sight to see is the holly that will be",
"On your own front door. ",
/* end song */
"O little town of Bethlehem",
"How still we see thee lie",
"Above thy deep and dreamless sleep",
"The silent stars go by",
"Yet in thy dark streets shineth",
"The everlasting Light",
"The hopes and fears of all the years",
"Are met in thee tonight",
/* end song */

});
    set_id("xmas_xmas");
    set_weight(0);
    set_value(0);
    COUNT = 0;
    WHICH = random(sizeof(songs)/8);
call_out("sing",6);
        }

sing() {
string SONG;
object att;
  if(!ENV) return 1;
 if(!environment(ENV)) return 1;
 SONG=songs[8*WHICH+COUNT];
 
  tell_room(environment(ENV), "\n"+HIR+""+
     ENV->query_name()+" sings"+HIG+" \""+SONG+"\""+NORM+"\n\n");

  COUNT = COUNT + 1;
  /* Do a little damage to the target when in combat */
  att=ENV->query_attack();
  if(att && present(att,environment(ENV)) && ENV->query_hp()>10)
    ENV->hit_player(2+random(5),"magical");
    if(COUNT > 7)  {
       endgame();
        }


call_out("sing",3+random(10));
   return 1;
}


endgame()  {
if(ENV) if(environment(ENV))
if(living(ENV))
tell_room(environment(ENV),
    ENV->query_name()+" stops singing.\n");
destruct(this_object());
  return 1;
        }

drop()  { return 1; }
get()   { return 1; }
can_put_and_get()  { return 0; }
