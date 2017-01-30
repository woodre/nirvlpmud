id(str) { return str == "book"; }
 
short() { return "A NEW newbie book"; }
 
long()  { 
write(
"<***********************************************************************>\n");
  write("This is your NEW newbie book! To use, type:\n");
  write("\n");
  write("read index   <for an index>\n");
  write("or\n");
  write("read page #   <the # is the page number you want to read>\n");
  write("Example: read page 1\n");
write(
"<***********************************************************************>\n");
    }

can_put_and_get() { return 1; }

get() { return 1; }
 
query_weight() { return 0; }
 
query_value() { return 0; }
 
init() {
add_action("read","read");
add_action("drop_object","drop");
   }
 
read(arg) {
 
if(!arg) { write("Read what?\n"); return 1; }
 
if (arg == "page #") { 
  write("'#' is the page number you want to read.\n"+
            "Example: read page 1\n");
  return 1;
     }
 
if (arg == "index")  {
write(
"<***********************************************************************>\n");
  write("Index to NEW newbie book!\n");
  write("\n");
  write("Page 1...               Map of town\n");
  write("Page 2...               Useful directions\n");
  write("Page 3...               Large newbie areas\n");
  write("Page 4...               Smaller newbie areas\n");
  write("Page 5...               Fighting tactics\n");
  write("Page 6...               General help\n");
  write("Page 7...               The Guilds of Nirvana\n");
  write("Page 8...               Guilds, continued...\n");
  write("\n");
write(
"<***********************************************************************>\n");
 
return 1;
    }

if (arg == "page 1") {
write(
"<***********************************************************************>\n");
write("Very simple map of town.\n");
write("\n");
write("1. Church\n");
write("2. Village green\n");
write("3. Advance Guild\n");
write("4. Shop\n");
write("5. Post Office\n");
write("                      1     4   \n");
write("                      2 * * *   \n");
write("                          * 3   \n");
write("                          5     \n");
write("\n");
write(
"<***********************************************************************>\n");
return 1;
      }
 
if(arg == "page 2") {
 
write(
"<***********************************************************************>\n");
write("\n"+"Some other useful directions <from church>:\n"+
          "\n"+"Pub: s,2e,n,e \n"+
          "Daycare center: s,4e,3n,w \n"+
          "Hotel: s,4e,2n,e \n"+
          "Motel: s,4e,s,e \n");
write("\n");
write(
"<***********************************************************************>\n");
return 1;
    }

if (arg == "page 3") {

write("Large Newbie Areas...\n"+"\n");
write(
"<**AREA*****************************DIRECTIONS <from church>************>\n"+
"\n"+
"SantaLand                           s,6w,n  \n"+
"Pillars of Peril                    s,6w,3s,5w,s  \n"+
"Bandit Forest                 s,5e,3n,w,step into rift,in,2w,enter,e,u,s \n"+
"M*A*S*H                             s,5e,s,enter portal,w \n"+
"Dopple Killing Grounds              s,9e,s,d,s  \n"+
"\n");
write(
"<***********************************************************************>\n");

return 1;
    }

if (arg == "page 4") {

write("Smaller Newbie Areas...\n"+"\n");
write(
"<**AREA*****************************DIRECTIONS <from church>************>\n"+
"\n"+
"Daydreams                           s,2e,s,d,lay on bed,s,e  \n"+
"Snow Prairie                        s,4w,4n,w,touch sculpture  \n"+
"Hades Rift                  s,5e,3n,w,step into rift,in,2w,enter,e,u,n \n"+
"Orcs of Kor                         s,4w,6n,2u,e,ride,3e  \n"+
"Missionaries                        s,e,n  \n"+
"Zombieland                          s,e,n,tunnel \n"+
"Blueberry Hill                      s,w,enter portal,n  \n"+
"Seagulls                            s,9e,n   \n"+
"Daycare                             n,enter realm,3w,2n,e  \n"+
"Cathedral                           n,enter realm,n,portal  \n"+
"Gangster                            s,4w,4n,enter machine,press 1 \n"+
"Newbie Hunting Grounds          s,4w,2n,w,n,enter grounds,enter,newbie \n"+
"Beren's Newbie                      s,4w,5n,e,enter,w  \n"+
"Blue's Newbie                       s,4w,2n,enter castle,read sign  \n"+
"Detroit                             s,6w,2s,2w,enter city,w  \n"+
"\n");
write(
"<***********************************************************************>\n");

write("More newbie areas to be added soon...\n");

return 1;
    }

if (arg == "page 5") {
 
write(
"<***********************************************************************>\n");
  write("Fighting tactics or\n");
  write("    How to survive and thrive on Nirvana!\n"+"\n");
 
  write("Number 1: SET YOUR WIMPY!\n"+"\n");
 
  write("If you haven't already done this, type:  wimpy   -this will\n"+
"make you run away when your hit points get low from being hit by\n"+
"monsters. It is not fail-safe but it will save your life most of the\n"+
"time.\n"+"\n");
 
  write("Number 2: Party, party, party!\n"+"\n");
 
  write("Partying means forming a group of players that kill monsters\n"+
"and share experience together. A party of 2 players will kill monsters\n"+
"about 3 times as fast as a player fighting alone. Party members can\n"+
"take turns taking hits or 'tanking' for each different monster that the\n"+
"party fights.\n"+"\n");
write(
"<***********************************************************************>\n");
 
return 1;
    }
 
if (arg == "page 6") {
 
write(
"<***********************************************************************>\n");
  write("General stuff...\n"+"\n");
 
write("Better weapons will kill monsters faster <duh>. To find out\n"+
"which weapons are good, ask higher level players <nicely> and\n"+
"someone will probably help you out.\n"+"\n");
write("Eating and drinking things heal you on Nirvana. When you are\n"+
"drunk, you heal faster.\n"+"\n");
 
write("Monsters will remember you if you run away while you are\n"+
"fighting them. The next time you enter the room with the monster,\n"+
"it will continue to attack.\n"+"\n");
 
  write("THE MOST IMPORTANT ADVICE OF ALL!\n"+"\n");
 
  write("Type: help -the documents there are there to help you.\n");
write("\n");
write(
"<***********************************************************************>\n");
 
return 1;
    }
if (arg == "page 7") {
 
write(
"<***********************************************************************>\n");
write("The Guilds of Nirvana\n"+"\n");
 
write("What are guilds?\n"+"\n"+
"Guilds are both playing and role-playing aids on this mud. Being a\n"+
"member of a guild provides a player with multitudes of new abilities\n"+
"and powers, automatic friends and allies on the mud, and a base for\n"+
"role-playing <if such is desired>. There are quite a few guilds on\n"+
"Nirvana. The following is a brief description of each of the current\n"+
"up-and-running guilds.\n"+"\n");
 
write("Bards- A highly selective guild of minstrel-warriors. A very\n"+
"social guild with the most atmosphere of any guild on the mud. Good\n"+
"fighting skills, good offensive spells, great miscellaneous spells. To\n"+
"join, prospective Bards must find a Bard Guild Commander to sponsor\n"+
"them into the guild.\n"+"\n");
 
write("Monks- A powerful guild of martial-artists. Many diverse\n"+
"spells and abilities. Very good offensive spells, natural armor,\n"+
"natural weapon if desired. Must be recruited by a high-ranking monk\n"+
"to join.\n"+"\n");
write(
"<***********************************************************************>\n");
 
return 1;
    }
 
if (arg == "page 8") {
 
write(
"<***********************************************************************>\n");
write("Guilds, continued...\n"+"\n");
 
write("Paladins- The first and only warrior guild of Nirvana. Must be\n"+
"good and willing to adhere to a strict honor code. Incredible fighting\n"+
"skills, great defensive spells, the best healing spells on the mud.\n"+
"Paladins do not use spells in combat.\n"+
"Must be recruited by a high level paladin to join.\n"+"\n");
 
write("Shadows- A guild for those who use the dark and shadows to\n"+
"their advantage. Some powerful miscellaneous spells, ability to\n"+
"create weapons, good natural armor. As of now no recruit\n"+
"requirements.\n"+"\n");
 
write("Undead- A guild of the animated dead. Extremely powerful\n"+
"offensive spells, good miscellaneous spells. Evil and vicious\n"+
"welcome.\n"+
"Must be sponsored by an undead guild commander to become an apprentice.\n"+
"After apprentice period can become undead.\n"+"\n");
 
write("Vampires- An old and selective guild. Vampires are, well,\n"+
"vampires. Many good miscellaneous powers and abilities, powerful\n"+
"pets, strong tradition. To become a vampire, a prospective must be\n"+
"bitten by two high-level vampires.\n");
write("\n");
write(
"<***********************************************************************>\n");

return 1;
    }
}

drop_object(str) {
    if (str == "all") {
        drop_object("book");
        return 0;
    }
    if (!str || !id(str))
        return 0;
    write("The NEW Newbie Book disappears as it touches the ground.\n");
    destruct(this_object());
    return 1;
}
