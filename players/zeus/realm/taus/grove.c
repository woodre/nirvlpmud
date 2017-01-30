inherit "room/room";           /*  Oak tree grove, druid sells heals  */
#include "/players/zeus/closed/all.h"
#define MAX 80000
int teleport, rum_cnt, fruit_cnt, nectar_cnt, COST, profit;
int plum_cnt, mag_s, mag_v, SCOST, COST3, DCOST, delaa_cnt;
object druid;

reset(arg){

    rum_cnt = 40+random(10);     /*  Starting amounts for heals */
    fruit_cnt = 40+random(10);
    nectar_cnt = 40+random(10);
    plum_cnt = 40+random(10);
    mag_s = 40+random(10);
    mag_v = 40+random(10);
    delaa_cnt = 60+random(20);
    COST = 1306;                /*  Base cost of dragons and pamua */
    SCOST = 2400;               /*  Base cost of kalowa and plum */
    COST3 = 2400;               /*  Base cost of balwa */
    DCOST = 1800;               /*  Base cost of delaa plant */
    profit = 0;                 /*  The profits..  'ask druid'   */

 if(arg) return;

    if(!present("druid"))
    {
      druid = CO("/players/zeus/realm/NPC/druid.c");
      MO(druid, TO);
    }

/*   Restocking the heal objects  */
    if(rum_cnt > 40)          rum_cnt += random(5);
    else if(rum_cnt > 30)     rum_cnt += 10;
    else if(rum_cnt > 10)     rum_cnt += 25;
    else                      rum_cnt += 35;

    if(plum_cnt > 40)         plum_cnt += random(5);
    else if(plum_cnt > 30)    plum_cnt += 10;
    else if(plum_cnt > 10)    plum_cnt += 25;
    else                      plum_cnt += 35;

    if(fruit_cnt > 40)        fruit_cnt += random(5);
    else if(fruit_cnt > 30)   fruit_cnt += 10;
    else if(fruit_cnt > 10)   fruit_cnt += 25;
    else                      fruit_cnt += 35;

    if(nectar_cnt > 40)       nectar_cnt += random(5);
    else if(nectar_cnt > 30)  nectar_cnt += 10;
    else if(nectar_cnt > 10)  nectar_cnt += 25;
    else                      nectar_cnt += 35;

    if(mag_s > 40)            mag_s += random(5);
    else if(mag_s > 30)       mag_s += 10;
    else if(mag_s > 10)       mag_s += 25;
    else                      mag_s += 35;

    if(mag_v > 40)            mag_v += random(5);
    else if(mag_v > 30)       mag_v += 10;
    else if(mag_v > 10)       mag_v += 25;
    else                      mag_v += 35;

    if(delaa_cnt > 60)        delaa_cnt += random(5);
    else if(delaa_cnt > 40)   delaa_cnt += 10;
    else if(delaa_cnt > 20)   delaa_cnt += 25;
    else                      delaa_cnt += 50;

    teleport = 0;  if(random(TFL_TLP)) teleport = 1;

 short_desc="The Fallen Lands";
 long_desc=
"This is a beautiful grove hidden amongst the oak trees.  The tall trees\n"+
"are providing a lot of shade, however it is not dark, and everything\n"+
"is warm.  There is a small pond to the northwest.  Green grass and lovely\n"+
"flowers are growing all around.  A small wood table is sitting to the\n"+
"south with some items on it.  This is a very peaceful and relaxing place.\n";
 set_light(1);
 items=({
	"trees",
"The grove is surrounded by tall oak trees, which are providing shade for\n"+
"the entire area.  Their branches are fanning out above you",
	"shade",
"The oak trees are making the grove shady",
	"pond",
"The small pond is filled with crystal clear water.  Some lily pads are\n"+
"floating in it, and numerous cattails are growing around it.  It is\n"+
"perfectly calm",
    "water",
"The water of the pond is perfectly clear and calm",
	"lily pads",
"Some lily pads are floating in the water.  They are of a dark green shade",
	"cattails",
"Some tall, reedlike cattails are growing around the pond.  They are\n"+
"swaying slightly in the breeze",
	"grass",
"Lush green grass is growing all around the grove",
	"flowers",
"Flowers of all colors are growing around here.  Some lovely violent ones\n"+
"are growing in a cluster around one of the many oak trees",
	"table",
"The table is of a very simple design, and it doesn't look very stable.\n"+
"Some drinks can be seen sitting on it.  There is also a piece of paper",
	"paper",
"The paper is white, and is nailed to the table.  It can be 'read'",
	"drinks",
"Some drinks in clear glasses are sitting on the table.  They look tasty",
 });
 dest_dir=({ "/players/zeus/realm/taus/guth9.c", "east",  });
}

void init(){
	::init();
	add_action("read_cmd", "read");
	add_action("buy_cmd", "buy");
	add_action("ask_cmd", "ask");
	add_action("tip_cmd", "tip");
	add_action("list_cmd", "list");
}


realm(){   if(teleport) return "NT";    }
okay_follow() { return 1; }

status read_cmd(string str){
  if(str != "paper") return 0;
  write("\nGreat healing products for sale...\n\n"+
    "Name\t\t\tCount\t\tCost\n\n"+
    "Kalowa nectar\t\t"+nectar_cnt+"\t\t"+SCOST+"\n"+
    "Plum\t\t\t"+plum_cnt+"\t\t"+SCOST+"\n"+
    "Balwa rum\t\t"+rum_cnt+"\t\t"+COST3+"\n"+
    "Pamua fruit\t\t"+fruit_cnt+"\t\t"+COST+"\n"+
    "Dragons breath\t\t"+mag_s+"\t\t"+COST+"\n"+
    "Dragons root\t\t"+mag_v+"\t\t"+COST+"\n"+
    "Delaa plant\t\t"+delaa_cnt+"\t\t"+DCOST+"\n\n"+
    "Just type 'buy <item>' eg:  'buy fruit'\n"+
    "Note: Tips are welcomed and encouraged.\n\n");
  return 1;
}

status list_cmd(){
  write("\nGreat healing products for sale...\n\n"+
    "Name\t\t\tCount\t\tCost\n\n"+
    "Kalowa nectar\t\t"+nectar_cnt+"\t\t"+SCOST+"\n"+
    "Plum\t\t\t"+plum_cnt+"\t\t"+SCOST+"\n"+
    "Balwa rum\t\t"+rum_cnt+"\t\t"+COST3+"\n"+
    "Pamua fruit\t\t"+fruit_cnt+"\t\t"+COST+"\n"+
    "Dragons breath\t\t"+mag_s+"\t\t"+COST+"\n"+
    "Dragons root\t\t"+mag_v+"\t\t"+COST+"\n"+
    "Delaa plant\t\t"+delaa_cnt+"\t\t"+DCOST+"\n\n"+
    "Just type 'buy <item>' eg:  'buy fruit'\n"+
    "Note: Tips are welcomed and encouraged.\n\n");
  return 1;
}

status ask_cmd(string str){
  if(str != "druid") return 0;
  if(!present("druid")) return 0;
  if(TP->query_level() > 19)
  {
    write("\n"+
    "The druid whispers to you:  I've made "+profit+" coins since reboot!\n");
    return 1;
  }
  return 1;
}

status buy_cmd(string str){
  int tip, laf;
  object fruit, rum, nectar, s_mag, s_vit, plum, delaa;
  laf = 0;
  if(!str)
  {
    TR(environment(), 
      "The druid asks: What do you want to buy "+TP->QN+"?\n");
    return 1;
  }
  if(!present("druid"))
  {
    write("Nobody is here to help you.\n");
    return 1;
  }
  tip = random(50);
  if(str == "fruit" || str == "pamua")
  {
    if(fruit_cnt < 1)
    {
      TR(TO, "The druid says: Sorry I'm all out of pamua fruits right now.\n");
      return 1;
    }
    if(TP->query_money() < COST + tip)
    {
      TR(TO, "The druid says: You can't afford my goods "+TP->QN+".\n");
      return 1;
    }
    fruit = CO("/players/zeus/heals/pamua.c");
    if(!call_other(TP,"add_weight",call_other(fruit,"query_weight")))
    {
      TR(TO, "The druid says: You can't carry any more "+TP->QN+".\n");
      destruct(fruit);
      return 1;
    }
    write("You pay the druid "+COST+" coins plus tip.\n");
    write("The druid hands you a pamua fruit.\n");
    TP->add_money(-COST-tip);
    if(druid->query_money() < (MAX - (COST+tip))) 
    druid->add_money(COST+tip);
    profit += COST+tip;
    MO(fruit, TP);
    fruit_cnt -= 1;
  }
  else if(str == "nectar" || str == "kalowa")
  {
    if(nectar_cnt < 1)
    {
      TR(TO, "The druid says: Sorry I'm all out of kalowa nectar right now.\n");
      return 1;
    }
    if(TP->query_money() < SCOST + tip)
    {
      TR(TO, "The druid says: You can't afford my goods "+TP->QN+".\n");
      return 1;
    }
    nectar = CO("/players/zeus/heals/kalowa.c");
    if(!call_other(TP,"add_weight",call_other(nectar,"query_weight")))
    {
      TR(TO, "The druid says: You can't carry any more "+TP->QN+".\n");
      destruct(nectar);
      return 1;
    }
    write("You pay the druid "+SCOST+" coins plus tip.\n");
    write("The druid hands you a bottle of kalowa nectar.\n");
    TP->add_money(-SCOST-tip);
    if(druid->query_money() < (MAX - (SCOST+tip)))
    druid->add_money(SCOST+tip);
    profit += SCOST+tip;
    MO(nectar, TP);
    nectar_cnt -= 1;
  }
  else if(str == "plum")
  {
    if(plum_cnt < 1)
    {
      TR(TO, "The druid says: Sorry I'm all out of plums right now.\n");
      return 1;
    }
    if(TP->query_money() < SCOST + tip)
    {
      TR(TO, "The druid says: You can't afford my goods "+TP->QN+".\n");
      return 1;
    }
    plum = CO("/players/zeus/heals/plum.c"); 
    if(!call_other(TP,"add_weight",call_other(plum,"query_weight")))
    {
      TR(TO, "The druid says: You can't carry any more "+TP->QN+".\n");
      destruct(plum);
      return 1;
    }
    write("You pay the druid "+SCOST+" coins plus tip.\n");
    write("The druid hands you a juicy purple plum.\n");
    TP->add_money(-SCOST-tip);
    if(druid->query_money() < (MAX - (SCOST+tip)))
    druid->add_money(SCOST+tip);
    profit += SCOST+tip;
    MO(plum, TP);
    plum_cnt -= 1;
  }
  else if(str == "rum" || str == "balwa")
  {
    if(rum_cnt < 1)
    {
      TR(TO, "The druid says: Sorry I'm all out of balwa rum right now.\n");
      return 1;
    }
    if(TP->query_money() < COST3 + tip)
    {
      TR(TO, "The druid says: You can't afford my goods "+TP->QN+".\n");
      return 1;
    }
    rum = CO("/players/zeus/heals/balwa.c");
    if(!call_other(TP,"add_weight",call_other(rum,"query_weight")))
    {
      TR(TO,"The druid says: You can't carry any more "+TP->QN+".\n");
      destruct(rum);
      return 1;
    }
    write("You pay the druid "+COST3+" coins plus tip.\n");
    write("The druid hands you a bottle of balwa rum.\n");
    TP->add_money(-COST3-tip);
    if(druid->query_money() < (MAX - (COST3+tip)))
    druid->add_money(COST3+tip);
    profit += COST3+tip;
    MO(rum, TP);
    rum_cnt -= 1;
  }
  else if(str == "breath" || str == "dragons breath")
  {
    if(mag_s < 1)
    {
      TR(TO, "The druid says: Sorry I'm all out of that right now.\n");
      return 1;
    }
    if(TP->query_money() < COST + tip)
    {
      TR(TO, "The druid says: You can't afford my goods "+TP->QN+".\n");
      return 1;
    }
    s_mag = CO("/players/zeus/heals/scroll_mag.c");
    if(!call_other(TP,"add_weight",call_other(s_mag,"query_weight")))
    {
      TR(TO, "The druid says: You can't carry any more "+TP->QN+".\n");
      destruct(s_mag);
      return 1;
    }
    write("You pay the druid "+COST+" coins plus tip.\n");
    write("The druid hands you a glass of dragons breath.\n");
    TP->add_money(-COST-tip);
    if(druid->query_money() < (MAX - (COST+tip)))
    druid->add_money(COST+tip);
    profit += COST+tip;
    MO(s_mag, TP);
    mag_s -= 1;
  }
  else if(str == "root" || str == "dragons root")
  {
    if(mag_v < 1)
    {
      TR(TO, "The druid says: Sorry I'm all out of that right now.\n");
      return 1;
    }
    if(TP->query_money() < COST + tip)
    {
      TR(TO,"The druid says: You can't afford my goods "+TP->QN+".\n");
      return 1;
    }
    s_vit = CO("/players/zeus/heals/scroll_vit.c");
    if(!call_other(TP,"add_weight",call_other(s_vit,"query_weight")))
    {
      TR(TO,"The druid says: You can't carry any more "+TP->QN+".\n");
      destruct(s_vit);
      return 1;
    }
    write("You pay the druid "+COST+" coins plus tip.\n");
    write("The druid hands you a dragons root.\n");
    TP->add_money(-COST-tip);
    if(druid->query_money() < (MAX - (COST+tip)))
    druid->add_money(COST+tip);
    profit += COST+tip;
    MO(s_vit, TP);
    mag_v -= 1;
  }
  else if(str == "delaa" || str == "delaa plant" || str == "plant")
  {
    if(delaa_cnt < 1)
    {
      TR(TO, "The druid says: Sorry I'm all out of that right now.\n");
      return 1;
    }
    if(TP->query_money() < DCOST + tip)
    {
      TR(TO,"The druid says: You can't afford my goods "+TP->QN+".\n");
      return 1;
    }
    delaa = CO("/players/zeus/heals/delaa.c");
    if(!call_other(TP,"add_weight",call_other(delaa,"query_weight")))
    {
      TR(TO,"The druid says: You can't carry any more "+TP->QN+".\n");
      destruct(delaa);
      return 1;
    }
    write("You pay the druid "+DCOST+" coins plus tip.\n");
    write("The druid hands you a delaa plant.\n");
    TP->add_money(-DCOST-tip);
    if(druid->query_money() < (MAX - (DCOST+tip)))
    druid->add_money(DCOST+tip);
    profit += DCOST+tip;
    MO(delaa, TP);
    delaa_cnt -= 1;
  }
  else 
  {
    TR(TO, "The druid asks: What do you want to buy "+TP->QN+"?\n");
    laf = 1;
  }
  if(!laf)
  {
    write_file("/players/zeus/log/grove", ctime(time())+
      "  "+TP->QN+" bought "+str+"  ["+TP->query_money()+"]\n");
    laf = 0;
  }
  return 1;
}

status tip_cmd(string str){
  int tip;
  if(str != "druid") return 0;
  if(!present("druid"))
  {
    write("Nobody is here to help you.\n");
    return 1;
  }
  tip = 75 + random(200);
  if(TP->query_money() < tip)
  {
    write("The druid laughs as you can't afford to tip him.\n");
    return 1;
  }
  write("You tip the druid for his excellent service.\n");
  TR(TO, TP->QN+" tips the druid.\n", ({TP}));
  druid->add_money(tip);
  TP->add_money(-tip);
  return 1;
}
