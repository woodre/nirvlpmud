#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#define ROOT2 "/players/daranath/closed/market/"
#define big_kill "players/daranath/closed/market/member/"
#include <ansi.h>

int bigkill;
int total;
static int marwho;
static string marlist;
inherit "room/room";

reset(int arg){
if(!present("sign")){
move_object(clone_object(ROOT2+"obj/shop_obj2.c"),this_object());
}
if(!present("dralgos")) {
move_object(clone_object(ROOT2+"mon/dralgos.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Bone Market"+NORM+")");
    long_desc=
"               "+WHT+"Market of Bone"+NORM+"\n"+
"Counters and shelves fill this small room, deep within the bowels of\n"+
"Qual'tor. A variety of exotic items are for sale here, provided you\n"+
"belong to the Bone Marketeers. A doorway leads north, with a large\n"+
"stone archway heads back to the west.\n"+
"A large shop sign shows the items available for sale.\n";

    items=({
"counters","The large wooden counters are filled with items for sale",
"shelves","Items for sale are stack upon the shelves in the room",
"items","A variety of exotic items are for sale to members of the Bone Market here",
"door","A large wooden door sits in the northern wall",
"doorway","The wooden doorway leads to the north and the tunnels beyond",
"tunnels","The tunnels beyond the doorway lead back to the sewer system and the UnderCity",
"archway","The dark grey stone archway heads back to the Bone Market",
    });

    dest_dir=({
ROOT+"undercity5.c","north",
ROOT+"bone_market.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("ask_dral","ask");
add_action("top_list","topmark");
add_action("top_kills","topkill");
    }

search() {
write("Bits of bone and dried blood are all about the area.\n");
  say(tp +" searches the area.\n");
return 1;
}

ask_dral() {
if(!present("dralgos")) {
write("Dralgos is not present to answer your question.\nCheck back later.\n");
return 1; }
write("Dralgos nods and you and slowly begins to speak:\n"+
      "\nI was put here to take care of the shop for Xion, the leader of\n"+
      "the Bone Market. In time, I began to grow weary of a simple shop\n"+
      "keepers life, and now I help to keep track of the individuals who\n"+
      "are the best within the Bone Marketplace.\n"+
      "I can share this info with you through <"+HIR+"tops"+NORM+"> and <"+
      HIR+"topkill"+NORM+">.\n\n");
write("You can also <"+HIR+"sell"+NORM+"> me an item that you want to get rid of.\n");
return 1;
}

top_list() {
  int h;
if(!present("market_ob", this_player())) {
write("You must be a member of the Bone Marketeers to get this information.\n"+
      "Why not check with Xion about how to join?\n");
return 1; }

    creation(1);
write(WHT+"<-------------------------------------->\n"+NORM);
write(HIR+"     Top Marketeers: Career\n"+NORM);
write(WHT+"<-------------------------------------->\n"+NORM);
 for(h=0;h<sizeof(marlist);h++) {
  write(pad("     "+marlist[h],21));
  write(marwho[h]+"\n");
  }
write(WHT+"<-------------------------------------->\n"+NORM);
  restore_object(big_kill+"daranath");
return 1; 
}

creation(int which) {
int k;
int h,start;
string meow, moo, space;
string who;
string nm;

  marlist = allocate(15);
  marwho = allocate(15);
 k = h = start = 0;
  meow = get_dir("/"+big_kill);
  while(start < sizeof(meow)) { 
      if(sscanf(meow[start],"%s.o",who)) {
    if(restore_object(big_kill+who)){
       if(which == 0)
           h = check(bigkill);
       else  h = check(total);
            if(h != -1) { 
                  k = sizeof(marlist)-1;
                 while(k>h) {
                       marlist[k] = marlist[k-1]; 
                           marwho[k] = marwho[k-1]; 
                     k = k -1;
                 }
                     marlist[h] = who;
              if(which == 0)
                  marwho[h] = bigkill;
              else  marwho[h] = total;
                           }
          }
        } 
    start = start + 1;
  }
}

check(int checker) {
int j, i;
  j = 0; i = -1;
  while(j<sizeof(marwho) && i == -1) {
    if(marwho[j] < checker) { i = j; j = 1000; }
        else j = j + 1;
  }
  return i;
}

top_kills() {
  int h, k;
if(!present("market_ob", this_player())) {
write("You must be a member of the Bone Marketeers to get this information.\n"+
      "Why not check with Xion about how to join?\n");
return 1; }
  
    creation(0);
write(WHT+"<-------------------------------------->\n"+NORM);
write(HIR+" Top Individual Kills for Marketeers\n"+NORM);
write(WHT+"<-------------------------------------->\n"+NORM);
 for(h=0;h<sizeof(marlist);h++) {
  write(pad("     "+marlist[h],21));
  write(marwho[h]+"\n");
  }
write(WHT+"<-------------------------------------->\n"+NORM);
  restore_object(big_kill+"daranath");
return 1; }
