
id(str){ return str == "pumpkin" || str == "jack-o-lantern"; }
string short_desc, long_desc, size;
short(){
   return "A "+size+" "+short_desc+" pumpkin";
}
long(){ write(long_desc+"\n"); }

init(){
   add_action("smash", "smash");
    name();
}

name(){
   int i, j;

   i = random(10);  j= random(10);
   switch(i){
      case 0:
      short_desc = "triangular-eyed";
break;
      case 1:
      short_desc = "square-nosed";
break;
      case 2:
      short_desc = "burning";
break;
      case 3:
      short_desc = "moldy";
break;
      case 4:
      short_desc = "jagged-toothed";
break;
      case 5:
      short_desc = "scowling";
break;
      case 6:
      short_desc = "grinning";
break;
      case 7:
      short_desc = "frightening";
break;
      case 8:
      short_desc = "cute";
break;
      case 9:
      short_desc = "Elvis-resembling";
break;
      case 10:
      short_desc = "jolly";
break;
   }
   switch(j){
      case 0:
      size = "huge";
break;
      case 1:
      size = "gigantic";
break;
      case 2:
      size = "flattened";
break;
      case 3:
      size = "large";
break;
      case 4:
      size = "average-sized";
break;
      case 5:
      size = "small";
break;
      case 6:
      size = "tiny";
break;
   }
   long_desc = "A jack-o-lantern if you will."+
   "Don't even think about smashing it.";
}


smash(){
   write("You smashed a "+short()+" pumpkin!\n");
   say(this_player()->query_name()+" smashes a "+short()+
      " pumkin!\n");
   short_desc = "smashed";
   return 1;
}
