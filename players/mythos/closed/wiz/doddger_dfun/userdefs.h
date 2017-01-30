#define USER this_player()
#define NAME capitalize(USER->query_name())
#define PRO  USER->query_pronoun()
#define OBJ USER->query_objective()
#define POS USER->query_possessive()
#define HERE environment(USER)
#define PROMPT "->> "
#define DFUNC "/players/dodger/temp/"
