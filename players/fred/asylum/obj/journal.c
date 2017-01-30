inherit "/obj/treasure.c";
#include <ansi.h>
#define tpn this_player()->query_name()
int opened;

reset (arg) {
	set_id("journal");
      set_alias("book");
	set_short("A leather Journal");
	set_long("  A small leather bound journal that has been badly damaged\n"+
               "from time. It has some old worn lettering on the front. The\n"+
               "letters spell out the name Dr. Johanson. He was the head\n"+
               "surgeon at the asylum and it is believed he kept records of\n"+
               "his accounts in this small book. Maybe you could open it and\n"+
               "see for yourself.\n");
      set_weight(1);
      set_value(1200);
      opened = 0;
}
init() {
	::init();
        add_action("openem","open");
        add_action("readem","read");
      }

openem(str) {
  if(!str) { write("Open what?\n"); return 1; }
  if(opened){ write("The journal is already open.\n"); return 1; }
  if(str == "book" || str == "journal"){
   say(tpn+" opens the journal.\n");
   write("You open the journal to the first page.\n");
   write("There are only a few undamaged pages remaining in the\n"+
         "journal. To read one, just 'read page #'. There are 5\n"+
         "pages that are still undamaged.\n");
   opened = 1;
   return 1; }
   }

readem(str){
  if(!str){ write("Read what?\n"); return 1; }
  if(str == "page 1"){
    write("October 9, 1924\n\n"+
          "  I had to perform my first labotamy today on a patient named\n"+
          "Anthony Howden. Things started off as planned but things soon\n"+
          "took a turn for the worse. Shortly after we made an opening in\n"+
          "his skull and I got the metal rod in place to start to scratch\n"+
          "away at his brain. He started to have a seizure and the nurse was\n"+
          "not able to hold his head still. With his head jerking violently\n"+
          "the metal rod caused serious damage to his brain and he started to\n"+
          "bleed profusely. The blood gushing from his head ran over everything.\n"+
          "We did everything we could to help him but it wasn't enough. He died\n"+
          "later that day due to the injuries he sustained.\n");
    return 1; }
  if(str == "page 2"){
    write("April 25, 1928\n\n"+
          "  A horrible fire broke out in the east wing of the institute.\n"+
          "We still are not sure as to what caused the fire but we think it\n"+
          "might have been something with the electroshock treatment room.\n"+
          "They had been having some problems with it as of late. They were\n"+
          "not able to contain the fire when it first broke out. Most stood\n"+
          "helplessly by in a state of horror and shock as 14 people who were\n"+
          "trapped in rooms were burned alive. Five staff members, seven patients,\n"+
          "and two guards didn't make it. Even after the fire was put out there\n"+
          "was nothing we could about the horrible smell of burning flesh that\n"+
          "seemed to follow you where ever you went. The stench was so disgusting\n"+
          "I threw up several times.\n");
    return 1; }
  if(str == "page 3"){
    write("August 14, 1935\n\n"+
          "  One of the male patients tried to escape today. He attacked and\n"+
          "stabbed a guard to death with a fork he must have snuck out of the\n"+
          "dining area. Once he had the guards keys he was able to make his way\n"+
          "to the outside of the main building. Several guards caught him just\n"+
          "as he made it to wall surrounding the main building. The guards who\n"+
          "were ferious about the killing of their friend beat him to within an\n"+
          "inch of his life. He is currently in the infermary undergoing treatment\n"+
          "for his wounds. The doctor said if he actually does pull through and\n"+
          "live he'll probably be in a vegetative state for the rest of his life\n"+
          "due to the brain damage he suffered from repeated blows to the head.\n");
    return 1; }
  if(str == "page 4"){
    write("July 22, 1941\n\n"+
          "  Two of the guards were arrested today for torturing and killing a\n"+
          "female patient named Stacey Ohlbrene. She was, by most standards a\n"+
          "good patient. Most of here therapist say that she was making really\n"+
          "good progress since she started her treatments here and if things kept\n"+
          "going well she might be eligible to be released soon. She was admitted\n"+
          "here after her 3 year old daughter was killed in a car accident that she\n"+
          "blamed herself for. After the death of her daughter she couldn't deal\n"+
          "with the normal stresses of day to day life. It is sad day indeed when\n"+
          "such a tragedy happens to someone like her who has already suffered so\n"+
          "much. She will be missed.\n");
    return 1; }
  if(str == "page 5"){
    write("May 5, 1946\n\n"+
          "  This shall be my last day at the institute. I feel my time has come\n"+
          "to leave this place and move on to different things. In the last 22 years\n"+
          "I have seen and experienced many things that no man should have to endure.\n"+
          "My only wish is that I will be remembered here for the things I have been\n"+
          "able to achieve. Not the things that were beyond what I was capable of with\n"+
          "skills that I did possess. It will be great to leave this horrible place and\n"+
          "all of the pain and anguish that I have grown to associate with it. I don't\n"+
          "think I will ever return here once I leave for it holds too many memories that\n"+
          "I would just as soon forget. Even considering all this I'm sure that in a sad\n"+
          "almost twisted way, I shall still think of this place from time to time with\n"+
          "a few fond memories.\n");
    return 1; }
 }                   

