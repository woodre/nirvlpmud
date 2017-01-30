#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";

string rname;       /* Name of the wep */
string ralt;        /* Alternate name (alias) */
string line1;
string line2;
string line3;
string rtype;       /* Type of wep */
string composition; /* Special composition (jewelled, iron, etc.) */
string acomposition; 
string grade;       /* Skill of creator */
int rvalue,rvalue2,tvalue,comp_val; /* Base value, extra value due to composition */
int rbase;          /* Base wc of wep */
int rbase2;         /* Wc modifier due to skill of creator */
int no_comp;        /* No special composition */
int rwght;          /* Weight of the wep */

reset(arg){
  ::reset(arg);
  if (arg) return;
get_type();
get_grade();
get_comp();
get_value();
get_long();
set_name(rname);
if(ralt) set_alias(ralt);
if(no_comp || !composition){
set_short("a "+capitalize(rname)+"");
}
else{
set_short("a "+composition+" "+capitalize(rname)+"");
}
set_long(format(line1+line2+line3, 35));
set_class(rbase + rbase2);
set_value(tvalue);
set_type(rtype);
set_weight(rwght);
set_save_flag(1);
}

init(){
 ::init();
 add_action("report_it", "rep");
}

report_it(){
write(tvalue+" "+rwght+" "+(rbase + rbase2)+"\n");
return 1;
} 


get_long(){
if(no_comp || !composition){
line1 = "This is a normal "+rname+". It is ";
}
else{
line1 = "This is a "+acomposition+" "+rname+". It is ";
}
if(rwght > 5){
line2 = "incredibly heavy, and it seems to be of ";
}
else if(rwght > 3){
line2 = "very heavy, and it seems to be of ";
}
else if(rwght > 1){
line2 = "somewhat heavy, and it seems to be of ";
}
else{
line2 = "lightweight, and it seems to be of ";
}
line3 = grade+" quality. ";
}



get_comp(){
if(random(100) > 80 && !no_comp){
  switch(random(10) + 1){
   case 9..1000:
   composition = HIY+"Gold"+NORM;
   acomposition = "Gold";
   comp_val = 3;
   break;
   case 6..8:
   composition = WHT+"Silver"+NORM;
   acomposition = "Silver";
   comp_val = 2;
   break; 
   case 5:
   composition = HIG+"J"+HIR+"e"+HIM+"w"+HIB+"e"+NORM+BOLD+"l"+HIY+"l"+HIG+"e"+HIB+"d"+NORM;
   acomposition = "Jewelled";
   comp_val = 5;
   break;
   case 3..4:
   composition = HIY+"Gold "+NORM+"and "+WHT+"Silver"+NORM;
   acomposition = "Gold and Silver";
   comp_val = 2;
   break;
   case 2:
   composition = WHT+"Platinum"+NORM;
   acomposition = "Platinum";
   comp_val = 4;
   break;
   case 1:
   composition = BOLD+"Mithril"+NORM;
   acomposition = "Mithril";
   comp_val = 10;
   break;
   default:
   composition = BOLD+"Mithril"+NORM;
   acomposition = "Mithril";
   comp_val = 10;
   break;
  }
 }
}
get_value(){
tvalue = rvalue / rvalue2;
tvalue += tvalue * comp_val;
}

get_grade(){
switch(random(10) + 1){
case 10..1000:
 grade = "grandmaster";
 rbase2 = 2;
 rwght -= 1;
 rvalue2 = 2;
break;
case 8..9:
 grade = "master";
if(random(100) > 80){
 rbase2 = 2;
 rwght -= 1;
 rvalue2 = 2;
 }
else{
 rbase2 = 1;
 rvalue2 = 1;
}
break;
case 5..7:
 grade = "expert";
if(random(100) > 80){
 rbase2 = 1;
 rwght -= 1;
 rvalue2 = 2;
}
else{
 rbase2 = 0;
 rvalue2 = 1;
}
break;
case 3..4:
 grade = "skilled";
 rbase2 = 0;
 rvalue2 = 1;
break;
case 1..2:
 grade = "poor";
 rbase2 = -1;
 rvalue2 = 1;
 rwght += 1;
break;
default:
 grade = "skilled";
 rbase2 = 0;
 rvalue2 = 1;
break;
 }
}



get_type(){
switch(random(10) + 1){
case 8..1000: 
rtype = "sword";
rwght = 3;
  switch(random(10) + 1){
   case 8..1000:
   rname = "longsword";
   ralt = "longsword";
   rbase = 15;
   rvalue = 150;
   break;
   case 6..7:
   rname = "shortsword";
   ralt = "shortsword";
   rvalue = 120;
   rbase = 13;
   rwght = 2;
   break;
   case 5:
   rname = "broadsword";
   ralt = "broadsword";
   rvalue = 165;
   rbase = 15;
   break;
   case 3..4:
   rname = "two-handed sword";
   rbase = 16;
   rvalue = 350;
   rwght = 4;
   break;
   case 2:
   rname = "scimitar";
   ralt = "scimitar";
   rvalue = 150;
   rbase = 15;
   break;
   case 1:
   rname = "falchion sword";
   ralt = "falchion";
   rvalue = 150;
   rbase = 15;
   break;
   default:
   rname = "sword";
   rbase = 15;
   rvalue = 100;
   break;
  } 
break;
case 7:
rtype = "axe";
  switch(random(10) + 1){
   case 9..1000:
   rname = "battleaxe";
   ralt = "battleaxe";
   rvalue = 250;
   rbase = 16;
   rwght = 4;
   break;
   case 7..8:
   rname = "hand axe";
   rvalue = 50;
   rbase = 13;
   rwght = 2;
   break;
   case 1..6:
   rname = "axe";
   rvalue = 100;
   rbase = 15;
   rwght = 3;
   break;
   default:
   rname = "axe";
   rvalue = 100;
   rbase = 14;
   rwght = 3;
   break;
  }
break;
case 6:
rname = "spear";
rvalue = 75;
rbase = 15;
rwght = 3;
break;
case 5:
rtype = "mace";
rwght = 3;
   switch(random(10) + 1){
    case 9..1000:
    rname = "flail";
    ralt = "flail";
    rvalue = 150;
    rbase = 15;
    break;
    case 5..8:
    rname = "footman's mace";
    rbase = 14;
    rvalue = 120;
    break;
    case 4:
    rname = "horseman's mace";
    rbase = 16;
    rvalue = 240;
    break;
    case 1..3:
    rname = "spiked mace";
    rbase = 15;
    rvalue = 165;
    break;
    default:
    rname = "mace";
    rbase = 14;
    rvalue = 120;
    break;
   }
break;
case 4:
rtype = "staff";
rwght = 3;
   switch(random(10) + 1){
    case 7..1000:
    rname = "quarter staff";
    rbase = 13;
    rvalue = 40;
    break;
    case 4..6:
    rname = "staff";
    rbase = 14;
    rvalue = 80;
    break;
    case 1..3:
    rname = "weighted staff";
    rbase = 15;
    rvalue = 120;
    rwght = 3;
    break;
    default:
    rname = "staff";
    rbase = 14;
    rvalue = 80;
    rwght = 3;
    break;
   }
break;
case 3:
rtype = "club";
  if(random(100) > 40){
    no_comp = 1;
    rvalue = 50;
    rname = "spiked club";
    rbase = 14;
    rwght = 2;
    }
  else{
    no_comp = 1;
    rvalue = 20;
    rname = "club";
    rbase = 12;
    rwght = 2;
    }
break;
case 2: 
rtype = "dagger";
   switch(random(10) + 1){
    case 9..1000:
    rname = "knife";
    ralt = "knife";
    rbase = 11;
    rvalue = 40;
    rwght = 2;
    break;
    case 8:
    rname = "longknife";
    ralt = "longknife";
    rvalue = 65;
    rbase = 13;
    rwght = 2;
    break;
    case 6..7:
    rname = "wardagger";
    ralt = "wardagger";
    rvalue = 80;
    rbase = 13;
    rwght = 2;
    break;
    case 3..5:
    rname = "dagger";
    rbase = 11;
    rvalue = 45;
    rwght = 2;
    break;
    case 1..2: 
    rname = "stilleto";
    ralt = "stilleto";
    rvalue = 60;
    rbase = 12;
    rwght = 2;
    break;
    default:
    rname = "dagger";
    rbase = 12;
    rvalue = 40;
    rwght = 2;
    break;
   }
break;
case 1:
rtype = "pike";
   switch(random(10) + 1){
    case 8..1000: 
    rname = "pike";
    rbase = 16;
    rvalue = 200;
    rwght = 4;
    break;
    case 6..7:
    rname = "halberd";
    ralt = "halberd";
    rbase = 16;
    rvalue = 220;
    rwght = 4;
    break;
    case 4..5:
    rname = "lance";
    ralt = "lance";
    rbase = 17;
    rvalue = 150;
    rwght = 4;
    break; 
    case 1..3:
    rname = "footman's lance";
    ralt = "lance";
    rbase = 16;
    rvalue = 200;
    rwght = 3;
    break;
    default:
    rname = "pike";
    rbase = 16;
    rvalue = 150;
    rwght = 4;
    break;
   }
break;
default:
rname = "mace";
rbase = 13;
rvalue = 100;
rwght = 2;
break;
}
}


 

