
/*
 *      A bag for the kender mini guild
 */

 inherit "obj/container.c";
 reset(arg) {
    ::reset();
    if (arg) return;
    set_name("bag");
    set_short("A kender bag");
    set_long("A kender bag, which can be filled with all sorts of small treasures\n"+
     "and interesting items.  You have the urge to fill it.\n"+
     "To take out a random item, type <???>.\n");
    set_weight(1);
    set_value(0);
    set_max_weight(5);
}

 id(str)  { return str == "bag" || str == "kender_bag";  }

init()  {
  ::init();
   add_action("random_pick","???");
        }

random_pick()  {
string ITEM;
object ob;
int    MONEY, R;

/* Changed from random(75) to random(500) due to excessive cloning/selling
 * 7/7/98  - Snow  */
MONEY = 50 + random(500);
if(this_player()->query_money() < MONEY)  {
  write("You don't have enough coins.\n");
  return 1;
        }

R = random(60);
if(R == 0)  {
  ITEM = "/players/saber/stuff/pillow.c";  }
if(R == 1)  {
  ITEM = "/players/saber/stuff/rose.c";  }
if(R == 2)  {
  ITEM = "/players/saber/stuff/rag.c";  }
if(R == 3)  {
  ITEM = "/players/saber/stuff/bear.c";  }
if(R == 4)  {
  ITEM = "/players/saber/stuff/sack.c";  }
if(R == 5)  {
  ITEM = "/players/saber/stuff/whistle.c";  }
if(R == 6)  {
  ITEM = "/players/saber/stuff/cards.c";  }
if(R == 7)  {
  ITEM = "/players/saber/stuff/corpse2.c";  }
if(R == 8)  {
  ITEM = "/players/saber/stuff/etorch.c";  }
if(R == 9)  {
  ITEM = "/players/saber/stuff/pillow.c";  }
if(R == 10)  {
  ITEM = "/players/saber/stuff/mirror.c";  }
if(R == 11)  {
  ITEM = "/players/saber/stuff/valentine.c";  }
if(R == 12)  {
  ITEM = "/players/saber/stuff/grass.c";  }
if(R == 13)  {
  ITEM = "/players/saber/armor/ljacket.c";  }
if(R == 14)  {
  ITEM = "/players/saber/armor/bluecloak.c";  }
if(R == 15)  {
  ITEM = "/players/saber/closed/bards/ring.c";  }
if(R == 16)  {
  ITEM = "/players/saber/armor/shades.c";  }
if(R == 17)  {
  ITEM = "/players/saber/stuff/flier.c";  }
if(R == 18)  {
  ITEM = "/players/saber/closed/new_mini/scroll.c";  }
if(R == 19)  {
  ITEM = "/players/saber/weapons/whip.c";  }
if(R == 20)  {
  ITEM = "/players/saber/weapons/haxe.c";  }
if(R == 21)  {
  ITEM = "/players/saber/gems/moonstone.c";  }
if(R == 22)  {
  ITEM = "/players/saber/armor/fmask.c";  }
if(R == 23)  {
   ITEM = "/players/saber/weapons/whip.c"; }
if(R == 24)  {
  ITEM = "/players/saber/food/atone.c";  }
if(R == 25)  {
  ITEM = "/players/saber/closed/new_mini/succ.c";  }
if(R == 26)  {
  ITEM = "/players/saber/magic/twiddle.c";  }
if(R == 27)  {
  ITEM = "/players/saber/armor/cbikini.c";  }
if(R == 28)  {
  ITEM = "/players/saber/gems/bloodstone.c";  }
if(R == 29)  {
  ITEM = "/obj/newspaper.c";  }
if(R == 30)  {
  ITEM = "/obj/stethoscope.c";  }
if(R == 31)  {
  ITEM = "/obj/rope.c";  }
if(R == 32)  {
  ITEM = "/players/saber/stuff/brief.c";  }
if(R == 33)  {
  ITEM = "/obj/dice.c";  }
if(R == 34)  {
  ITEM = "/players/saber/food/orange.c";  }
if(R == 35)  {
  ITEM = "/players/saber/stuff/popper.c";  }
if(R == 36)  {
  ITEM = "/players/saber/food/wine.c";  }
if(R == 37)  {
  ITEM = "/players/saber/armor/wshield.c";  }
if(R == 38)  {
  ITEM = "/players/saber/fur/bed.c";  }
if(R == 39)  {
  ITEM = "/players/saber/weapons/hoopak.c";  }
if(R == 40)  {
  ITEM = "/players/saber/weapons/sword.c";  }
if(R == 41)  {
  ITEM = "/players/saber/weapons/2daggers.c";  }
if(R == 42)  {
  ITEM = "/players/saber/gems/garnet.c";  }
if(R == 43)  {
  ITEM = "/players/mizan/etheriel/items/notepad_exe.c";  }
if(R == 44)  {
  ITEM = "/players/mizan/etheriel/items/dirtvial.c";  }
if(R == 45)  {
  ITEM = "/players/mizan/etheriel/items/plyrblinker.c";  }
if(R == 46)  {
  ITEM = "/players/mizan/etheriel/items/poohbear.c";  }
if(R == 47)  {
  ITEM = "/players/mizan/etheriel/items/pencil.c";  }
if(R == 48)  {
  ITEM = "/players/mizan/etheriel/items/uranium-238.c";  }
if(R == 49)  {
  ITEM = "/players/mizan/etheriel/items/kickme.c";  }
if(R == 50)  {
  ITEM = "/players/mizan/etheriel/items/bowling-ball.c";  }
if(R == 51)  {
  ITEM = "/players/mizan/etheriel/items/infernal-mach.c";  }
if(R == 52)  {
  ITEM = "/players/mizan/etheriel/items/beano-fgn.c";  }
if(R == 53)  {
  ITEM = "/players/mizan/etheriel/items/blockbuster.c";  }
if(R == 54)  {
  ITEM = "/players/saber/stuff/tag_gun.c";  }
if(R == 55)  {
  ITEM = "/players/saber/stuff/clip.c";  }
if(R == 56)  {
  ITEM = "/players/saber/stuff/mic.c";  }
if(R == 57)  {
  ITEM = "/players/saber/stuff/streamer.c";  }
if(R == 58)  {
  ITEM = "/players/saber/stuff/fpole.c";  }
if(R == 59) {
  ITEM = "/players/mythos/prac/boy.c"; }

ob = clone_object(ITEM);
if(ob->query_value() > MONEY) ob->set_value(MONEY);
move_object(ob,this_object());
call_other(this_player(), "add_money", - MONEY);
  write("You loose "+MONEY+" golden coins searching through your pouches.\n");
  write("You find "+ITEM->short()+" in the depths of your bag.\n");
  return 1;
        }

