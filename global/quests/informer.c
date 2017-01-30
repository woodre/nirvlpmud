#pragma strong_types

#include <message.h>
#include <quests.h>
#include <server.h>
#include <libs.h>
#include <event.h>
#include <termcol.h>  // Coogan, 25-Nov-2003

inherit "complex/npc";

mixed quests;

private mixed info_chat(string text, string type, object pl, mixed target) {
  int solved;   // 0 = all, 1 = solved, -1 = unsolved
  int level;
  status story;
  int time;
  int players;                 // the amount of players
  status dividable, beginner;  // dividable or beginner-flag.

  int i,tmp,maxi;
  string *wo, *quests_to_list;

  wo = LIB_STRINGS->get_words(text) - ({ "", ".", ",", "!", "-", ";", "?" });
  maxi = sizeof(wo);

  for (i=0; i<maxi; i++) {
    switch(wo[i]) {
      case "level" :
        if (i && wo[i-1] == "my")
          level = pl->query_level();
        else if (i+1 < maxi) {
          level = LIB_PARSE->parse_numeral(wo[i+1]);
        }
        break;

      case "extra" :
      case "very" :
        if (i+1<maxi) {
          wo[i+1] = wo[i] + wo[i+1];
          break;
        }

      case "extralow" :
      case "verylow" :
      case "extrashort" :
      case "veryshort" :
        time = 1;
        break;

      case "low" :
      case "short" :
        time = 2;
        break;

      case "medium" :
      case "average" :
      case "moderate" :
        time = 3;
        break;

      case "high" :
      case "long" :
        time = 4;
        break;

      case "extrahigh" :
      case "veryhigh" :
      case "extralong" :
      case "verylong" :
        time = 5;
        break;

      case "unsolved" :
      case "not" :
      case "didn't" :
      case "haven't" :
        solved = -1;
        break;

      case "solved" :
      case "solve" :
        if (!solved) solved = 1;
        break;

      case "dividable" :
      case "parts" :
        dividable = 1;
        break;

      case "beginner" :
      case "beginners" :
        beginner = 1;
        break;

      case "players" :
      case "player" :
        if (i) players = LIB_PARSE->parse_numeral(wo[i-1]);
        break;

      case "story" :
      case "description" :
        story = 1;
        break;
    }
  }

  quests_to_list = ({ });
  for (i=0; i<sizeof(quests);i++) {
    tmp = pl->query_quests(quests[i][Q_NAME]);

    if (solved) {  // 0: alle, -1:ungeloeste,  1:geloeste
      if (solved == -1 && tmp || solved == 1 && !tmp) continue;
    }

    if (beginner && !quests[i][Q_BEGINNER]) continue;
    if (dividable && !quests[i][Q_DIVIDABLE]) continue;

    if (players) {
       if (intp(quests[i][Q_PLAYERS])) {
          if ( quests[i][Q_PLAYERS] != -1 &&
               players != (quests[i][Q_PLAYERS] || 1)
             ) continue;
       }
       else if ( players > quests[i][Q_PLAYERS][1] ||
                 players < quests[i][Q_PLAYERS][0]
               ) continue;
    }

    if (level) {
      if ( level < (quests[i][Q_LOW_LEVEL] || 1) ||
           level > (quests[i][Q_HIGH_LEVEL] || 1000)
         ) continue;
    }

    if (time && time != quests[i][Q_TIME] &&
                time != quests[i][Q_DIVIDABLE]) continue;

    quests_to_list += ({ quests[i][Q_VERY_SHORT] });
  }

  if (solved != 1 && sizeof(quests_to_list) > 20)
    return ({ ({ M_SAYS, "Oh oh, there are too many quests. Please "
                 "describe more closely which quests you want." }) });

  wo = ({});

  if (level) wo += ({ "suitable for level " + level });
  if (time) wo += ({ "taking " +
        NICE_TIME_GROUPS[time-1] + " time" });

  if (players) wo +=
      ({ "playable for "+players + " player" + (players != 1 ? "s" : "") });

  if (beginner) wo +=
      ({ "which are special beginner-quests" });

  if (dividable) wo +=
      ({ "which are divided into several parts" });

  if (solved == -1) wo +=
      ({ "which you didn't already solve" });

  if (solved == 1) wo +=
      ({ "which you already solved" });

  if (sizeof(quests_to_list)) {
    return ({ ({ M_ME_THE, " looks closely at ", M_PL_THE, ". Then ", 
                 M_ME_PRONOUN, " says: Oh yes, quests " + 
                    make_list(wo) + "..." }),
                 4,
                 ({ M_SAYS, (sizeof(quests_to_list) == 1 ?
                    "There's just the quest " + quests_to_list[0] :
                    "There are " + describe("quest", 0, 0, 
                    sizeof(quests_to_list)) + ", the one " + 
                      make_list(quests_to_list, 0, " and one ", ", one ")) +
                    "." }) });
  }

  return ({ ({ M_ME_THE, " sighs deeply." }),
            4,
            ({ M_SAYS, "Sorry, there are no quests " +
                 make_list(wo) + "." })
         });
}

private string my_get_very_short(int i) {
  return quests[i][Q_VERY_SHORT];
}

private mixed description_chat(string text, string type, object pl,
                               mixed target) {
  mixed msg;
  int i, match, best;
  int best_i, best_length;
  string *quests_to_list, fil;
  string *wo, *wo2;
  object ob;

  wo = LIB_STRINGS->get_words(lower_case(text)) -
       ({ "about", "with", "in", "of", "the",
          "", ".", ",", "!", "-", ";", "?" });
       // added about, Coogan, 05-Apr-01
  quests_to_list = ({});

  best_i = -1;
  best_length = 99;

  for (i=sizeof(quests); i--;) {
    wo2 = LIB_STRINGS->get_words(lower_case(quests[i][Q_VERY_SHORT])) +
          LIB_STRINGS->get_words(lower_case(quests[i][Q_NAME]))       -
                                           // Coogan, 19-Dec-01, added Q_NAME
       ({ "with", "in", "of", "the" });
    match = sizeof(wo2 & wo);
    if (!match) continue;
    if ( match > best ||
         ( match == best && sizeof(wo2) < best_length )
       ) {
      best_i = i;
      best = match;
      best_length = sizeof(wo2);
    }
  }
  if (best_i > -1) {
    if (file_size(fil="/global/quests/" + quests[best_i][Q_NAME] + 
          "_quest.c") < 0)
      return ({ ({ M_SAYS, "Oh, oh, this quest has not yet been "
                   "converted. :)" }) });

    if (catch(ob = load_object(fil)) ||
        !ob ||
        !(msg = ob->query_description())
       ) return ({ ({ M_SAYS, "Something is wrong with this quest." }) });

    wo = ({ "was written by " + quests[best_i][Q_CREATOR],
            "was designed for levels " + quests[best_i][Q_LOW_LEVEL] +
              " to " + quests[best_i][Q_HIGH_LEVEL],
            "takes " + NICE_TIME_GROUPS[quests[best_i][Q_TIME]-1] + 
                " time to solve",
            "is worth " + ((quests[best_i][Q_POINTS] * 1000) /
                          SE_QUESTS->query_quest_points_sum())+
            " level points" });

    if (quests[best_i][Q_DIVIDABLE]) 
      wo += ({ "can be played in several parts" });

    if (quests[best_i][Q_BEGINNER]) 
      wo += ({ "is a special beginner quest" });

    if (quests[best_i][Q_PLAYERS]) {
       if (intp(quests[best_i][Q_PLAYERS])) {
         if (quests[best_i][Q_PLAYERS] == -1) 
           wo += ({ "can be played by any amount of players" });
         else wo += ({ "needs to be played by " +
           describe("player", 0, 0, quests[best_i][Q_PLAYERS]) });
      }
      else wo += ({ "can be played by " +
         quests[best_i][Q_PLAYERS][0] + " to " +
         quests[best_i][Q_PLAYERS][1] + " players" });
    }

    msg = ({ M_PRESENT,
             ({ M_SAYS, "The story of the quest " +
                quests[best_i][Q_VERY_SHORT] + ", yes, of course." }),
             2,
             ({ M_ME_THE, " thinks hard." }),
             2 }) + msg + ({
             4,
             ({ M_SAYS, "That's all. Perhaps some final technical details." }),
             4,
             ({ M_SAYS, "This quest " + make_list(wo) + "." }),
             4,
             ({ M_ME_THE, " smiles at ", M_PL, "." })
          });
    return msg;
  }

  return ({ ({ M_SAYS, "Sorry, I don't know which quest you mean." }) });
}

static void refuse_objects(mapping e) {
  send_message(({ M_ME_THE, " says, ", M_CNTL_SEQ, TERMCOL_SAY, 
                  "'Sorry, I've got no use for your ", M_NONE,
                  M_DESCRIBE_UNOWNED, e[E_TARGET], ", ", M_PL_DESCRIBE, "'", 
                  M_CNTL_SEQ, TERMCOL_NORMAL,
                  " and refuses to take it from ", M_PL_THE, "." }));
  e[E_TARGET] = ({ });
}

void configure() {
  npc::configure();
  set_name("man");                // to be changed by the loading object
  set_short("just a man");
  set_long("He looks very wise and seems to know many things about quests. "
           "You probably should ask him about quests.\n");
  set_male();
  set_race("human");  // Coogan, 24-Jan-01
  set_level(40);
  set_refuse_function(#'refuse_objects);  // Coogan, 18-Nov-2003

  quests = SE_QUESTS->query_quests();

  set_chat_reactions(({
    ({ ({ "more", "story", "description", "detail", "details" }),
       #'description_chat,
       ({ "say", "ask_for", "ask_about", "whisper" }),
       1
    }),
    
    ({ ({ "solve", "solved", "unsolved", "level", 
          "players", "player", "beginner", "beginners", "dividable", 
          "parts", "very short", "short", "average", "moderate",
          "long", "very long", "veryshort", "verylong",
          "extrashort", "extra short", "extralong", "extra long",
          "very low", "very high" }) + 
          TIME_GROUPS,
       #'info_chat,
       ({ "say", "ask_for", "ask_about", "whisper" }),
       1
    }),

    ({ "recommend",
       ({ ({ M_SAYS, "I could recommend quests which are suitable for "
             "your level or a given level." }),
          4,
          ({ M_SAYS, "I also know quests especially for beginners." }),
          4,
          ({ M_SAYS, "I know which quest takes very short, short, medium, "
             "long or very long. Very short means less than one hour, "
             "short less than 2 hours, medium less than 3 hours, "
             "long less than 6 hours and very long more than 6 hours." }),
          10,
          ({ M_SAYS, "You could also ask me for quests which can be played "
             "in several parts." }),
          4,
          ({ M_SAYS, "Or if you're looking for quests to be played by more "
             "than one player simultaneously, no problem for me." }),
          4,
          ({ M_SAYS, "Finally I also know which quests you already solved. "
             "Of course I know those, too, which you didn't solve yet." }),
          4,
          ({ M_SAYS, "So, just tell me what quest you are interested in." })
       }),
       ({ "say", "ask_for", "ask_about", "whisper" }),
       1
    }),

    ({ ({ "quests" }),
       ({ ({ M_ME_THE, " clears ", M_ME_POSSESSIVE, " throat." }),
          2,
          ({ M_SAYS, "There are many quests in Tubmud which are "
             "just waiting to be solved by you." }),
          4,
          ({ "Pointing to the obelisk ", M_ME_THE, " says: They are "
             "all written down here." }),
          4,
          ({ M_SAYS, "And I can tell you the story of every quest. "
             "You just have to ask." }),
          4,
          ({ M_SAYS, "I even could recommend you some quests." })
       }),
       ({ "say", "ask_about", "whisper" })
    }),

    ({ ({ "hi", "hello", "hiya", "hiho", "greetings" }),
       ({ ({ M_SAYS, "Hello, ", M_PL_DESCRIBE, "." }),
          2,
          ({ M_SAYS, "I know everything about quests." })
       })
    })
  }));
}

int hit_player(mixed dam, mixed from) {
  send_message(({ M_WRITE, "Somehow you fail to focus your aggressive "
                  "energy on ", M_ME_THE, "." }));
  this_player()->stop_fight();
  this_player()->stop_hunter(1);
  this_object()->stop_fight();
  this_object()->stop_hunter(1);
  return 0;
}

