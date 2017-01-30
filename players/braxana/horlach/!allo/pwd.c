string generate(int pass) {
  string mo;
  string moo;  
  string doo;
  int h;
  doo = "";
mo = "a b c d e f g h i j k l m n o p q r s t u v w x "+
     "y z A B C D E F G H I J K L M N O P Q R S T U V W "+
     "X Y Z 1 2 3 4 5 6 7 8 9 0 * - _ > < ] [ ' @ ~ #";
  moo = explode(mo," ");
  for(h=0;h<pass;h++) doo += moo[random(sizeof(moo))];
return doo; }

