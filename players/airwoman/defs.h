#define QRN query_real_name()
#define QN query_name()
#define E(x) environment(x)
 
#define M this_player()
#define Mqrn M->QRN
#define Mqn M->QN
#define Me E(M)
 
#define V find_living(str)
#define Vqrn V->QRN
#define Vqn V->QN
#define Ve E(V)
 
#define O this_object()
#define Oe E(O)
 
#define ACT(x,y) add_action(x,y)
#define CAP(x) capitalize(x)
#define CO(x) clone_object(x)
#define CR "\n"
#define D(x) destruct(x)
#define FI(x) first_inventory(x)
#define FL(x) find_living(x)
#define FN(x) file_name(x)
#define FO(x) find_object(x)
#define HOME "/players/airwoman/"
#define MO(x,y) move_object(x,y)
#define MONSTER "/players/airwoman/monster/"
#define NI(x) next_inventory(x)
#define NOSELF Mqrn != "airwoman"
#define P(x) present(x)
#define PP(x,y) present (x,y)
#define R return
#define SELF Mqrn == "airwoman"
#define ME FL("airwoman")
#define TO(x,y) tell_object(x,y)
#define TR(x,y) tell_room(x,y)
#define W(x) write(x)
