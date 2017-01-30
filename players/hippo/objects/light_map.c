#include "/players/hippo/bs.h"
reset(arg) {
        if(arg) return;
}
int n,m;

id( str ) {
   if(str=="book") return 1;
        return 0;
}

long() {
   write ("The title of this book is: 'The anatomical guideline',"+BS+
      "it looks like an interesting thing to read, especially when "+BS+
      "you enter this area. "+BS+
      "You notice some strange bubbling things under the cover. Maybe"+BS+
      "you could remove it to see what is under it?"+BS);
}

short()
   {return "The anatomical guideline: an interesting book"; }
init()
{
   add_action("do_read","read");
add_action("do_light","remove");
   add_action("do_page","page");
}
do_light(arg) {
   if(arg!="cover") {
      notify_fail("What did you want to remove from the book? I'd try the cover."+BS);
      return 0;
}
   write("You notify little unidentified things, that function like a light source"+BS);
   set_light (1);
   return 1;
}

do_read (str) {
write ("............INTRODUCTION.............."+BS+
      "This book concerns some anatomical lessons. It has been written to"+BS+
      "learn you something about anatomics, and about the creatures you"+BS+
      "find in this enormous body you are in now."+BS+
      "You can read some more about several things, soon enough."+BS+
      "For now, the book's contents are restricted to something about:"+BS+
      ""+BS+"   1. The heart."+BS+
      "   2. The lung."+BS+
      "   3. The intestine."+BS+
      "   4. Blood."+BS+
      "   5. Cancer."+BS+
      "   6. Other stuff."+BS+
      "   7. Abbreviations."+BS+
      ""+BS+".......................just type page <num> to read."+BS);
   return 1;
}
do_page(n) {
   sscanf (n,"%d",m);
   if(m>7) {
      write("There are not that many pages yet. Sorry!"+BS);
      return 0; }
   if(m<1) {
      write("I don't think there is any book with pagenumbers less then 1!"+BS);
      return 0; }
   switch(m) {
      case(1) : write("............... THE HEART ................"+BS+
           "The heart is a big muscle, that consists of 4 different rooms."+BS+
          "These rooms are the left and right atrium and ventricle,"+BS+        
          "the blood stream is as following: "+BS+
          "          <- lung <-"+BS+
          "         |          |"+BS+
          "         LA        RV"+BS+
          "         |          |"+BS+
          "         LV        RA"+BS+
          "         |          |"+BS+
          "          -> body ->"+BS+
          "Valvulae between the four rooms make sure blood goes the "+BS+
          "right way around. They are very strong to do so."+BS+
          "Trabeculae are rough muscles. However, they are friendly,"+BS+
          "as they keep the body alive. They don't look dangerous"+BS);
        return 1;
      case(2) : write("............... THE LUNG ................"+BS+
      "The lung is the area of a human, where the exchange of oxigen"+BS+
      "and other gas takes place. The cellmembrane of the alvoeli has"+BS+
      "a special design to enable this. "+BS+
      "However, substances like tobacco mozaiks can destroy these "+BS+
      "alveoli, which results in difficult breathing. Besides, these "+BS+
      "mozaiks can initiate cancer. They must be very dangerous, bad"+BS+
      "and aggressive for this reason."+BS);
   return 1;
      case (3) : write(".............. THE INTESTINE ..............."+BS+
          "The entire intestine can be devided in several parts."+BS+
          "These are:"+BS+
          "1. Small intestine: consists of the duodenum, jejunum and ileum."+BS+
          "2. Large intestine, consists of an ascending, transvers and "+BS+
          "                    descending part"+BS+
          "3. Rectum (which finally results in the famous ass)."+BS+
          ""+BS+"You will find both recognizable and unrecognizable"+BS+
             "things in here. Sometimes aggressive, but most of it has "+BS+
          "already died a bit, due to the work of mouth and stomach."+BS+
          "For this reason, most of these stuff is not very dangerous,"+BS+
          "although there might be some exceptions, of course"+BS+
          ""+BS);
       return 1;
   case(4) : write("..................BLOOD..................."+BS+
      "Blood is a fluid, that can be entered from nearly"+BS+
      "the entire body. Besides, blood always ends up in the liver"+BS+
      "where it is cleaned from bad substances. Probably in this"+BS+
      "liver, you could find usefull things, because of this reason."+BS+
      ""+BS+
      "In the blood, you will find four different cells:"+BS+
      "  1. erythrocytes (ery's). They are the main cells in blood."+BS+
      "      You could find them all over, but they are not dangerous."+BS+
      "  2. leucocytes (leuco's). They have to do with the immune- "+BS+
      "      system. You don't have to fear them, although they can be tough."+BS+
      "  3. thrombocytes (thrombo's). These are meant to repair the "+BS+
      "      vessels when necessary. They are strong to do so."+BS+
      "  4. virusses etc. like hiv and influenza.. most of the times"+BS+
      "      you meet one of those... make sure it won't hurt you."+BS+
      "      In general, virusses are restricted to the blood."+BS+
      ""+BS);
   return 1;
   case(5) : write(".................CANCER.................\n"+
      "Ok, i'll explain what cancer is. It starts with a cell that\n"+
      "is uncontrollable, and grows in any direction, as much as it\n"+
      "likes. When they are benigne, the carcinogene cells stay \n"+
      "close to each other, like a balloon. Maligne cells grow to\n"+
      "all directions. \n"+
      "I've created some carcinegene processes in my body: in the\n"+
      "liver and in the pancreas. Most of the cancer of the liver\n"+
      "are maligne, the ones in the pancreas are mostly benigne.\n"+
      "However, the pancreatic cancer is a bad one because it's\n"+
      "not easy to operate it and most of the times it has become\n"+
      "a large cancer before you discover it.\n"+
      "Like cancer, i created these area's in my body in a way\n"+
      "You could create as much cells as you like yourself.\n"+
      "I hope you guys enjoy it. Let me know.\n"+
      "\n");
   return 1;
   case(6) : write("..............OTHER STRANGE THINGS..............\n"+
      "This chapter is meant to explain what some creatures"+BS+
      "you see in here are doing in a body. If you got some"+BS+
      "questions about anything you see anywhere, just write"+BS+
      "it down on the board in the liver and i'll tell you "+BS+
      "something about it.  "+BS+
      "The first question was about the endotheel you see "+BS+
      "in the body. I hope (and expect) a lot of questions "+BS+
      "follow soon.. "+BS+
      ""+BS+"   1. Endotheel:"+BS+
      "      This is the name of the inner wall of blood, lymphe"+BS+
      "      and cavities in the body. Sometimes called 'intima'."+BS+
      ""+BS+"   2. Glazour coat:"+BS+
      "      This is the stuff teeth are covered with, to protect"+BS+
      "      themselves against sugar etc. It's quite hard, and"+BS+
      "      thus can be used as armour."+BS);
   return 1;
   case(7) : write("............ABBREVIATIONS.............\n"+
      "Ok, here is the solution to the main problem\n"+
      "in my area: the long (too long) names. Although\n"+
      "I brought in these names because they are the real\n"+
      "names and i liked to create a realistic area, I\n"+
      "have made some creatures an easier alias.\n"+
      "If you want more creatures to have a simple name,\n"+
      "just mail me their names. \n"+
      "\n"+"   contraction_wave : wave\n"+
      "   hepatocyte      : cancer\n"+
      "   influenza       : virus\n"+
      "   langerhans      : cancer\n"+
      "   leucocyte       : leuco\n"+
      "   staphylococ     : coc\n"+
      "   trabeculae      : trab\n"+
      "   thrombocyte     : thrombo\n"+
      "   valvula         : valve\n"+
      "\n"+"I hope this is what you wanted it to be..\n"+"rvd-Hippo\n");
   return 1;
      }
}


get() {
        return 1;
}
drop() {
        return 0;
}
