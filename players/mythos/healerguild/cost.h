/* this file contains all the changeable variables involved with each spell
   if anything needs to be changed then change using this file  */

/*  nameofspell_var = ({0_level_needed,1_min_sp_cost,2_min_hp_cost,3_min_xp_cost,4_min_coin_cost,
                        5_min_heal_amount, 6_difficulty_chance, 7_type_chance, 8_multiplier_chance,}); 
      note: level = level + extra level so 1 - 40 */

/*
  type_chance can be 1, 2, or 3
   1>  if random(difficulty) > multiplier * (level + piety) then fail
   2>  if random(difficulty) > multiplier * pi              then fail
   3>  if random(difficulty) > multiplier * lvl             then fail
   
   note: failure still expends the costs
*/

static int heal_var, peace_var ,fortify_var, mystic_transfer_var;
static int cure_var, defend_var, shield_var, reduce_var;   
static int resurrect_var, mass_heal_var, simulcrum_var, potion_var;         
static int reinstate_var, regenerate_var, cove_var, full_heal_var;       
static int haven_var, salve_var, healing_spring_var, grant_var;  
static int robe_of_healing_var, holy_blessing_var, bless_var;

reset_m() {
                     /*   lvl,  sp,   hp,     xp,   coin, heal, diff, type, mult  */
                                             
  heal_var            = ({  5,   1,    0,      0,      0,    1,   20,    1,    1});
  peace_var           = ({  5,  35,    0,     50,    100,    0,   20,    2,    1});
  fortify_var         = ({  6,  10,    0,    100,    500,    0,   20,    3,    2});
  mystic_transfer_var = ({  7,  40,    0,    100,    700,    0,   30,    3,    2});
  cure_var            = ({  8,  20,    0,      0,    100,    0,   20,    2,    1});
  defend_var          = ({  9,  40,    0,    100,    300,    0,   40,    1,    1});
  shield_var          = ({ 10,  80,   10,      0,      0,    0,   40,    1,    1});
  reduce_var          = ({ 11,  60,    0,      0,    400,    1,   80,    1,    2});
  resurrect_var       = ({ 12,  80,    0,      0,      0,    0,   60,    2,    3});
  mass_heal_var       = ({ 13,   1,    0,      0,   5000,    1,  120,    1,    2});
  simulcrum_var       = ({ 14,  60,  100,    500,      0,    0,   40,    2,    2});
  potion_var          = ({ 15,  80,    0,    500,   2000,    0,   40,    3,    2});
  reinstate_var       = ({ 16,  90,   50,   3000,      0,    0,   40,    1,    1});
  regenerate_var      = ({ 17, 100,   50,      0,   8000,    0,   40,    1,    1});
  cove_var            = ({ 18, 150,  100,      0,  10000,    0,   50,    1,    1});
  full_heal_var       = ({ 19, 200,    0,      0,   8000, 1000,  100,    1,    2});
  haven_var           = ({ 20, 200,  100,   1000,      0,    0,  160,    1,    3});
  salve_var           = ({ 22, 150,    0,   1000,  10000,    0,  100,    3,    3});
  grant_var           = ({ 25, 200,  100,   1000,  20000,    0,  200,    1,    4});
  healing_spring_var  = ({ 30, 200,  200,  10000,   1000,    0,  240,    1,    4});
  bless_var           = ({ 35, 300,  150,  50000,   2000,    0,  300,    1,    5});
  robe_of_healing_var = ({ 39, 300,  250,  70000,  10000,    0,  320,    1,    5});
  holy_blessing_var   = ({ 40, 300,  300, 150000,  20000,    0,  330,    1,    5});
}                                                        
 

