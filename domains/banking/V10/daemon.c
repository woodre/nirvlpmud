/*
 * This is the V10 daemon of the Banking domain.
 * To use it add it with 'daemon add /domains/banking/V10/daemon'.
 * After this you can use the command 'banking' which explains its use.
 */

#include <banking.h>
#include <message.h>
#include <describe.h>
#include <wizlevels.h>
#include <fingerd.h>
#include <libs.h>
#include <closures.h>
#include <prop/player.h>

inherit "basic/time";
inherit "basic/name";
inherit "basic/tools/time";

mapping get_commands() { return ([ "banking":"" ]); }
object find_instance() { return this_object(); }

status dispatch(string verb,string s) {
  string *words;
  if (!s)
    s = "help";
  words = explode(s," ");
  switch(words[0]) {
  default:
    words = ({ "help" });
  case "accounts":
  case "trade":
  case "sells":
  case "buys":
  case "banks":
  case "withdraws":
  case "deposits":
  case "balance":
  case "open":
  case "close":
  case "statistic":
  case "transactions":
  case "lock":
  case "unlock":
  case "help":
  case "bandits":
  case "banditstat":
    return call_other(this_object(),words[0],words[1..]);
  }
}

status bandits(){
  message(ROBCONTROL->print_lurkers());
  return 1;
}

status banditstat()
{
  message(ROBCONTROL->print_statistic());
  return 1;
}

#ifdef BS
#undef BS
#endif
#define BS(x,y) break_string(sprintf("%-23s -- %s",(x),(y)),0,27,-1)

status help() {
  this_player()->
    tell_more("The following commands are available with the Banking daemon:\n"
              "\n" +
              BS("banking trade <item>",
                 "shows trading information about the item (which must either"
                 " be in your inventory or be given as a key).\n") +
              BS("banking trade [<order>]",
                 "Prints a list of all registered items. <order> can be one"
                 " of: \"buys\", \"sells\", \"new\" and \"old\".\n") +
              BS("banking sells",
                 "shows a list of the levels and the money they got in the"
                 " shops.\n") +
              BS("banking buys",
                 "shows a list of the levels and the money they left in the"
                 " shops.\n") +
              BS("banking banks",
                 "shows all existing banks.\n") +
              BS("banking withdraws",
                 "shows a list of the levels and the money they withdrew as a"
                 " whole.\n") +
              BS("banking deposits",
                 "shows a list of the levels and the money they deposited as a"
                 " whole.\n") +
              BS("banking balance",
                 "shows a list of the levels and the money they have on their"
                 " accounts on the average.\n") +
              BS("banking balance <name>",
                 "shows a list of all accounts the given player has and the"
                 " money on each.\n") +
              BS("banking statistic",
                 "shows some internal variables.\n") +
              BS("banking transactions",
                 "shows a list of the players which deposit or withdraw the"
                 " largest amounts of money. The amount decays with " + 
                 to_int(TRANSACTION_DECAY * 100) + "% per week.\n") +
              BS("banking open <name>",
                 "opens a new bank.\n") +
              BS("banking close <name>",
                 "closes one of your banks.\n") +
              BS("banking lock <name>",
                 "lock the accounts of a player.\n") +
              BS("banking unlock <name>",
                 "unlock the accounts of a player.\n") +
              BS("banking lock all",
                 "lock all banks.\n") +
              BS("banking unlock all",
                 "unlock all banks.\n") +
              BS("banking bandits",
                 "shows where currently bandit-lurkers are.\n") +
              BS("banking banditstat",
                 "shows a robstatistic of the bandits.\n") +
              "\n");
  return 1;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//   These two functions belong together and do nothing more than
//   showing a nice list of the currently registered banks and their
//   owners.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

private string divide_nicely(int divident,int divisor) {
  if (!divisor)
    return divident + "/0";
  return to_string(divident/divisor);
}

status banks(string *words) {
  mixed b,s,h;
  if (!sizeof(b=BANKSERVER->query_banks())) {
    write("There are no banks in Tubmud registered.\n");
    return 1;
  }
  s = BANKINGSTATISTIC->query_banks();
  write(LIB_STRINGS->
        make_tablet(({ "owner","bank","money","acc","mon/acc","vis_name" }),
                    ({ map(m_indices(s),
                                 lambda(({ 'x }),
                                        ({ CL_INDEX,b,'x,1 }))),
                       m_indices(s),
                       map(m_values(s,1),#'to_string),
                       map(m_values(s),#'to_string),
                       map(transpose_array(({ m_values(s,1),
                                                    m_values(s) })),
                                 lambda(({ 'x }),
                                        ({ (#'divide_nicely),
                                           ({ CL_INDEX,'x,0 }),
                                           ({ CL_INDEX,'x,1 }) }))),
                       map(m_indices(s),
                                 lambda(({ 'x }),
                                        ({ CL_INDEX,b,'x,2 }))) }),
                    ({ "|","|","","","","|" })));
  return 1;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//   Clearify is a safety-function and asks the wizard who typed 'open'
//   or 'close' if he/she/it is sure (via input_to).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void clearify(string input,closure c,mixed donemsg) {
  if (!input || lower_case(input[0..0])!="y")
    return write("Aborted.\n");
  else {
    funcall(c);
    message(donemsg);
  }
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//   Open a bank.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

status open(string *words) {
  mixed h;
  string bank;
  bank = implode(words," ");
  if (strlen(bank) < 2 || strlen(bank) > BANKNAMELIMIT)
    return notify_fail("Please give a name which should not be longer than " +
                       BANKNAMELIMIT +
                       " and not shorter than two characters.\n"
                       "The capitalization DOES matter: \"Foo\" and \"foo\""
                       " can be different banks.\n"
                       "Banking strongly suggests that you take your own"
                       " real_name as the name of your bank; the vis_name"
                       " (which will be asked later) may have a nicer"
                       " look.\n"), 0;
  if (h=BANKSERVER->query_owner(bank))
    return notify_fail("I am sorry, but this name is already in use.\n"
                       "The wizard " +
                       (h=FINGERD->load_player(h))->query_vis_name() +
                       " has claimed this name for "+h->query_possessive() +
                       " bank.\n"), 0;
  message("Please give a vis_name for your new bank.\n"
          "The vis_name is the name the players will see when they are shown"
          " a list of all banks; it should look like \"the village bank\".\n"
          "Vis_name? ");
  input_to("ask_vis_name_for_open",0,bank);
  return 1;
}

static status ask_vis_name_for_open(string vis_name,string bank) {
  vis_name = describe(vis_name,ARTICLE_THE);
  message("I will now open a bank called \"" + bank +
          "\" with the vis_name \"" + vis_name + "\" on your name.\n"
          "Sure? ");
  input_to("clearify",0,lambda(0,({ (#'call_other),
                                    BANKSERVER,
                                    "open_bank",
                                    bank,
                                    this_player()->query_real_name(),
                                    vis_name })),
           ({ ({ M_PL,(" just opened a new bank called \"" + bank +
                           "\" with the vis_name \"" + vis_name + "\" on "),
                 M_PL_POSSESSIVE," name." }) }));
  return 1;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//   Close a bank.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

status close(string *words) {
  mixed h;
  string bank;
  bank = implode(words," ");
  if (!(h=BANKSERVER->query_owner(bank)))
    return notify_fail("There is no bank with this name registrated.\n"), 0;
  if (h != this_player()->query_real_name())
    return notify_fail("Sorry, but the owner of this bank is " +
                       (h=FINGERD->load_player(h))->query_vis_name() +
                       " and only " + h->query_pronoun() +
                       " can close this bank.\n"), 0;
  message("I will now close the bank called \"" + bank + "\".\n"
          "Sure? ");
  input_to("clearify",0,lambda(0,({ (#'call_other),
                                    BANKSERVER,
                                    "close_bank",
                                    bank })),
           ({ ({ M_PL," just closed ",M_PL_POSSESSIVE,
                 " bank called \"" + bank + "\"." }) }));
  return 1;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//   Valueserver
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

private string ware_short_view(mixed key,mapping wares) {
  return sprintf("%6s%6.1f%6.1f  %s",short_time(time()-wares[key,2]),
                 wares[key,0],wares[key,1],key);
}

status valueserver(int mode,status backwards) {
  mixed h;
  mapping wares;
  wares = VALUESERVER->query_wares();
  h = m_indices(wares);
  if (mode)
    h = sort_map_array(h,sort_args(CL_MAPPING_INDEX,({ 1,0,2 })),
                       (backwards? (#'>) : (#'<)),({ wares,mode-1 }));
  this_player()->view_text("Number of registered items: " + sizeof(wares) +
                           "\n"
                           "time   buys  sells  key\n" +
                           implode(map(h,(#'ware_short_view),wares),
                                   "\n"),
                           "Valueserver: registered items");
  this_player()->start_view();
  return 1;
}

status trade(string *words) {
  mixed result,h,key,v;
  if (!sizeof(words))
    return valueserver(0,0);
  if (sizeof(words) == 1)
    if (words[0] == "buys")
      return valueserver(1,0);
    else if (words[0] == "sells")
      return valueserver(2,0);
    else if (words[0] == "new")
      return valueserver(3,0);
    else if (words[0] == "old")
      return valueserver(3,1);
  if (call_other_2ref(LIB_GRAMMAR,"parse_object",
                      &result,&h,0,sizeof(words)-1,words,({})) ||
      VALUESERVER->ware_known(key=implode(words," "))) {
    if (!key)  // parse_object() returned true?
      key = VALUESERVER->object2key(result);
    else  // no, but ware_known() returned true.
      result = 0;
    write("key:             " + key + "\n" +
          (result?
           "short():         " + result->short() + "\n"
           "creator():       " + creator(result) + "\n"
           "query_weight():  " + result->query_weight() + "\n"
           "query_value():   " + (v=result->query_value()) + "\n" :
           "") +
          "last trade:      " + ((h=VALUESERVER->time_of_last_trade(key)),
                                 (h? time_short(time()-h) + " ago" :
                                  "not yet")) + "\n"
          "# sells:         " + VALUESERVER->number_of_sells(key) + "\n"
          "# buys:          " + VALUESERVER->number_of_buys(key) + "\n" +
          (result? "resulting value: " + VALUESERVER->value(key,v) + "\n" :
           ""));
    return 1;
  }
  return notify_fail("No such item.\n"), 0;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//   Statisticserver
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

private int compute_div(int x) {
  if (x > 100000000)
    return 10000;
  if (x > 10000000)
    return 1000;
  if (x > 1000000)
    return 100;
  if (x > 100000)
    return 10;
  return 1;
}

private void level_list_line_out(mixed l,int n_a,int v_a,int n_b,int v_b,
                                 int n_d,int v_d) {
  printf("%:3s | %:6d %:6d %:5d | %:6d %:6d %:5d | %:6d %:6s\n",
         to_string(l),
         n_a/n_d,v_a/v_d,v_a/(n_a||1),
         n_b/n_d,v_b/v_d,v_b/(n_b||1),
         (v_a-v_b)/v_d,
         (v_a>v_b?
          (v_b?
           "/" + (to_float(v_a)/v_b) :
           "*0.00000") :
          (v_a?
           "*" + (to_float(v_b)/v_a) :
           "--------")));
}

private void print_level_list(mapping a,mapping b,string name_a,
                              string name_b) {
  mixed h;
  int i,number_sum_a,value_sum_a,number_sum_b,value_sum_b;
  int number_div,value_div;
  status sum_given_out;
  h = sort_array(m_indices(a+b),#'<);
  number_sum_a = value_sum_a = number_sum_b = value_sum_b = 0;
  for (i=sizeof(h); i--; )
    if (h[i]<WL_APPRENTICE) {
      value_sum_a += a[h[i]];
      number_sum_a += a[h[i],1];
      value_sum_b += b[h[i]];
      number_sum_b += b[h[i],1];
    }
    else
      break;
  number_div = compute_div(number_sum_a+number_sum_b >> 1);
  value_div = compute_div(value_sum_a+value_sum_b >> 1);
  printf("%3s | %:6s %:6s %:5s | %:6s %:6s %:5s | %:6s %:6s\n"
         "----|-%:6'-'s-%:6'-'s-%:5'-'s-|-%:6'-'s-%:6'-'s-%:5'-'s-|-%:6'-'s-%:"
         "6'-'s-\n",
         "lvl","#" + name_a,name_a,"avrg","#" + name_b,name_b,"avrg","diff",
         "quot","/" + number_div,"/" + value_div,"/1","/" + number_div,
         "/" + value_div,"/1","/" + value_div,"/1");
  for (i=sizeof(h); i--; ) {
    if (!sum_given_out && h[i] >= WL_APPRENTICE) {
      level_list_line_out("sum",number_sum_a,value_sum_a,number_sum_b,
                          value_sum_b,number_div,value_div);
      sum_given_out = 1;
    }
    level_list_line_out(h[i],a[h[i],1],a[h[i]],b[h[i],1],b[h[i]],number_div,
                        value_div);
  }
  if (!sum_given_out)
    level_list_line_out("sum",number_sum_a,value_sum_a,number_sum_b,
                        value_sum_b,number_div,value_div);
}

status sells() {
  print_level_list(BANKINGSTATISTIC->query_sells(),
                   BANKINGSTATISTIC->query_buys(),"sells","buys");
  return 1;
}

status buys() { return sells(); }

status withdraws() {
  print_level_list(BANKINGSTATISTIC->query_deposits(),
                   BANKINGSTATISTIC->query_withdraws(),"deposits","withdraws");
  return 1;
}

status deposits() { return withdraws(); }

status balance(string *words) {
  mixed g,h;
  int i;
  mapping balance;
  if (!sizeof(words)) {  // show the level table of balances
    balance = BANKINGSTATISTIC->query_balance();
    h = sort_array(m_indices(balance),#'<);
    printf("lvl | %|:12s | %|:8s | %|:10s\n"
           "----|-%12'-'s-|-%8'-'s-|-%10'-'s-\n",
           "money","#players","average","","","");
    for (i=sizeof(h); i--; )
      if (balance[h[i],1])
        printf("%:3d | %12d | %8d | %10d\n",h[i],balance[h[i]],balance[h[i],1],
               balance[h[i]]/balance[h[i],1]);
      else if (balance[h[i]])
        printf("No accounts for level %d but %d coins statistically known.",
               i,balance[h[i]]);
  }
  else {  // show the accounts of players
    words = to_real_name(words);
    for (i=sizeof(words); i--; ) {
      if (h=FINGERD->load_player(words[i]))
        if (sizeof(g=BANKSERVER->query_accounts(h)))
          words[i] = (h->query_vis_name() + ":\n" +
                      implode(map(g,lambda(({ 'bank }),
                                                 ({ (#'sprintf),
                                                    "%8d coins on %s",
                                                    ({ (#'call_other),
                                                       BANKSERVER,"balance",h,
                                                       'bank }),
                                                    ({ (#'call_other),
                                                       BANKSERVER,
                                                       "query_bank_vis_name",
                                                       'bank }) }))),"\n"));
        else
          words[i] = h->query_vis_name() + " has no accounts.";
      else
        words[i] = capitalize(words[i]) + " does not exist.";
    }
    write(implode(words,sprintf("\n%78'-'s\n","")) + "\n");
  }
  return 1;
}

status lock(string *words) {
  int i;
  object pl;
  if (!sizeof(words)) {
    if (BANKSERVER->query_all_banks_locked())
      write("All banks are locked.\n");
    else
      write("The banks are generally open.\n");
    write("The accounts of " +
          make_list(to_vis_name(BANKSERVER->query_locked()),"no player") +
          " are locked.\n");
    return 1;
  }
  if (sizeof(words) != 1)
    return notify_fail("Syntax:\n"
                       "banking lock\n"
                       "banking lock <name>\n"
                       "banking lock all\n"), 0;
  if (!check_previous_privilege("Banking:"))
    return notify_fail("You are no member of the Banking domain.\n"), 0;
  if (words[0] == "all") {
    if (BANKSERVER->query_all_banks_locked())
      return notify_fail("There are already all banks locked.\n"), 0;
    write("You want to lock all banks.\n"
          "But please do this only temporarily.\n"
          "To unlock all banks type 'banking unlock all'.\n"
          "Please give the reason why you want to do this.\n"
          "Why? ");
    input_to("lock_reason",0,
             lambda(({ 'reason }),
                    ({ #'call_other,BANKSERVER,"lock_all_banks",'reason })),
             ({ ({ M_PL,M_PL_VERB,"lock"," all accounts on all banks." }) }));
    return 1;
  }
  pl = FINGERD->load_player(to_real_name(words[0]));
  if (!pl)
    return notify_fail("No such player.\n"), 0;
  if (BANKSERVER->query_locked(pl))
    return notify_fail(({ ({ M_WRITE,M_POSSESSIVE,pl,
                             " accounts are already locked." }) })), 0;
  write("You want to lock the accounts of " + pl->query_vis_name() + ".\n"
        "To unlock the accounts of " + pl->query_objective() + " again type"
        " 'banking unlock " + pl->query_real_name() + "'.\n"
        "Please give the reason why you want to do this.\n"
        "Why? ");
  input_to("lock_reason",0,
           lambda(({ 'reason }),
                  ({ (#'call_other),BANKSERVER,"lock_accounts",
                     ({ (#'call_other),FINGERD,"load_player",
                        pl->query_real_name() }),
                     // the way to just give pl as parameter is not possible
                     // because pl is a FINGERD product which are not stable
                     // but selfdestruct in the heartbeat.
                     'reason })),
           ({ ({ M_PL,M_PL_VERB,"lock",
                 " the accounts of " + pl->query_vis_name(),"." }) }));
  return 1;
}

static void lock_reason(string reason,closure c,mixed m,string old_reason) {
  if (!old_reason && strlen(reason) < 10) {
    message("Please notice that locking a player's accounts is a very serious"
            " thing. So do it not without a good reason. I doubt that a reason"
            " that short is a good one but if it really is, just type enter, I"
            " will accept it then. Otherwise give a longer one.\n"
            "Why? ");
    input_to("lock_reason",0,c,m,reason);
    return;
  }
  if (!strlen(reason))
    reason = old_reason;
  write("Ok. I just want to notify a last time that you are sure about this.\n"
        "Sure? ");
  input_to("clearify",0,lambda(0,({ #'funcall,c,reason })),m);
}

status unlock(string *words) {
  object pl;
  if (!sizeof(words)) {
    if (BANKSERVER->query_all_banks_locked())
      write("All banks are locked.\n");
    else
      write("The banks are generally open.\n");
    write("The accounts of " +
          make_list(to_vis_name(BANKSERVER->query_locked()),"no player") +
          " are locked.\n");
    return 1;
  }
  if (sizeof(words) != 1)
    return notify_fail("Syntax:\n"
                       "banking unlock\n"
                       "banking unlock <name>\n"
                       "banking unlock all\n"), 0;
  if (!check_previous_privilege("Banking:"))
    return notify_fail("You are no member of the Banking domain.\n"), 0;
  if (words[0] == "all") {
    if (!BANKSERVER->query_all_banks_locked())
      return notify_fail("The banks are not locked, nothing to unlock.\n"), 0;
    BANKSERVER->unlock_all_banks();
    send_message(({ M_PL,M_PL_VERB,"unlock"," all banks again." }));
    return 1;
  }
  pl = FINGERD->load_player(words[0]);
  if (!pl)
    return notify_fail("No such player.\n"), 0;
  if (!BANKSERVER->query_locked(pl))
    return notify_fail("The accounts of " + pl->query_vis_name() +
                       " are not locked. Nothing to unlock.\n"), 0;
  BANKSERVER->unlock_accounts(pl);
  send_message(({ M_PL,M_PL_VERB,"unlock",
                  " the accounts of " + pl->query_vis_name() + " again." }));
  return 1;
}

status statistic(string *words) {
  if (!sizeof(words))
    printf("%10d: minimum value to be logged when withdrawn\n"
           "%10d: minimum value to be logged when deposited\n",
           BANKINGSTATISTIC->query_log_min_withdraw(),
           BANKINGSTATISTIC->query_log_min_deposit());
  return 1;
}

status transactions(string *words) {
  mixed h;
  int i,height;
  if (sizeof(words))
    return 0;
  h = BANKINGSTATISTIC->query_transactions();
  height = this_player()->query_property(P_DISPLAY_HEIGHT) - 2;
  printf("%7s %-11s  %7s %-11s\n","","deposit","","withdraw");
  for (i=0; i<sizeof(h[0])/2+1 && i<height; i++)
    printf("%7d %-11s  %7d %-11s\n",
           h[0][<i+1],to_vis_name(h[1][<i+1]),
           h[0][i],to_vis_name(h[1][i]));
  return 1;
}
