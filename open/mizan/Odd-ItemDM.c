string longs;
string adv;
string id;
string thingoname;
int weight;
int thingos;

return_info() {
  int longs_blah,adv_blah;
  if(!adv) {
   adv=allocate(30);
   adv[0]="wombat flavored";
   adv[1]="fuel injected";
   adv[2]="semi-automatic";
   adv[3]="stainless steel";
   adv[4]="self-propelled";
   adv[5]="somewhat edible";
   adv[6]="mango flavored";
   adv[7]="half-baked";
   adv[8]="purple";
   adv[9]="hot pink";
   adv[10]="ugly looking";
   adv[11]="somewhat abused";
   adv[12]="beat-up";
   adv[13]="nearly destroyed";
   adv[14]="blue";
   adv[15]="terribly rancid";
   adv[16]="somewhat sexy-looking";
   adv[17]="completely smashed";
   adv[18]="broken";
   adv[19]="plain old";
   adv[20]="nasty-smelling";
   adv[21]="lightly toasted";
   adv[22]="carbon scored";
   adv[23]="somewhat burned";
   adv[24]="burned out";
   adv[25]="barely usable";
   adv[26]="somewhat flattened";
   adv[27]="green";
   adv[28]="flourescent red";
   adv[29]="crunchy";

   longs=allocate(29);
   longs[0]="surge supressor";
   longs[1]="tennis ball";
   longs[2]="eggbeater";
   longs[3]="fish fryer";
   longs[4]="baseball mitt";
   longs[5]="tree branch";
   longs[6]="football";
   longs[7]="mechanical pencil";
   longs[8]="boomerang";
   longs[9]="model airplane";
   longs[10]="tree stump remover";
   longs[11]="thermostat";
   longs[12]="bicycle seat";
   longs[13]="egg carton";
   longs[14]="picture frame";
   longs[15]="potato peeler";
   longs[16]="nose hair remover";
   longs[17]="juice machine";
   longs[18]="meat grinder";
   longs[19]="plastic elbow joint";
   longs[20]="fan blade";
   longs[21]="toy action figure";
   longs[22]="bowling pin";
   longs[23]="bowling ball";
   longs[24]="tree stump";
   longs[25]="log";
   longs[26]="lump of tar";
   longs[27]="television set";
   longs[28]="beer mug";

   id=allocate(29);
   id[0]="supressor";
   id[1]="ball";
   id[2]="eggbeater";
   id[3]="fryer";
   id[4]="mitt";
   id[5]="branch";
   id[6]="football";
   id[7]="pencil";
   id[8]="boomerang";
   id[9]="airplane";
   id[10]="remover";
   id[11]="thermostat";
   id[12]="seat";
   id[13]="carton";
   id[14]="frame";
   id[15]="peeler";
   id[16]="remover";
   id[17]="machine";
   id[18]="grinder";
   id[19]="joint";
   id[20]="blade";
   id[21]="figure";
   id[22]="pin";
   id[23]="ball";
   id[24]="stump";
   id[25]="log";
   id[26]="tar";
   id[27]="television";
   id[28]="mug";

   weight=allocate(29);
   weight[0]=1;
   weight[1]=1;
   weight[2]=1;
   weight[3]=2;
   weight[4]=1;
   weight[5]=2;
   weight[6]=1;
   weight[7]=1;
   weight[8]=1;
   weight[9]=2;
   weight[10]=3;
   weight[11]=1;
   weight[12]=1;
   weight[13]=1;
   weight[14]=1;
   weight[15]=1;
   weight[16]=1;
   weight[17]=1;
   weight[18]=1;
   weight[19]=1;
   weight[20]=2;
   weight[21]=1;
   weight[22]=2;
   weight[23]=4;
   weight[24]=4;
   weight[25]=4;
   weight[26]=2;
   weight[27]=3;
   weight[28]=1;
}

  longs_blah=random(27);
  adv_blah=random(19);
  thingos = thingos + 1;
/*
  adv_blah = adv_blah - 1;
  longs_blah = longs_blah - 1;
 */
  thingoname = "a " + adv[adv_blah] + " " + longs[longs_blah] + "#" + 
  id[longs_blah] + "#" + weight[longs_blah];
  return thingoname;
}

id(str) { return str == "box"; }
short() { return "The Anything box (Version 1.0)"; }

long() {
  write("This is a cardboard box filled with all sorts of useless junk.\n");
  if(thingos) {
    write("So far, [" + thingos + "] things have been made from its contents.\n");
    write("The last item made was " + thingoname + ".\n");
  }
}

reset() {
  move_object(this_object(), "players/mizan/workroom.c");
}

