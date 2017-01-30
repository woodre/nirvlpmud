/*
 * bankinterface.c
 * This is the interfaces to be used by banks and other objects which want
 * to allow a player to access a bank.
 */

#include <banking.h>
#include <grammar.h>
#include <message.h>
#include <describe.h>
#include <libs.h>
#include <fingerd.h>
#include <money.h>
#include <closures.h>

virtual inherit "basic/parser";
inherit "basic/name";

/* The following functions should be overloaded by the inherting object */
string
bank_name()
{
}

string
vis_bank_name()
{
  return BANKSERVER->query_bank_vis_name(bank_name()) || "this bank";
}

int
possibilities()
{
  return B_PO_ALL;
}

/* The following functions are internal stuff again
 */
#define ACCOUNT "<account>"
#define ACC_MONEY "<acc_money>"
#define PL_MONEY "<pl_money>"
#define BANK "<bank>"
#define PLAYER "<player>"

#define MONEY_EXPLANATION "where <amount of money> can be\n" \
                          "  5 platinum and 5 gold coins\n" \
                          "  all silver coins\n" \
                          "  all\n" \
                          "etc. Try it out!\n"

#define MONEY_NO_ALL_EXPLANATION "where <amount of money> can be\n" \
                          "  5 platinum and 5 gold coins\n" \
                          "  all silver coins\n" \
                          "  all\n" \
                          "etc. Try it out!\n"

#define LOCKED_NOTIFY_FAIL_MESSAGE "Your accounts have been locked.\n" \
                                   "Please contact the admin and/or wizards" \
                                   "  of the Banking domain. You probably"\
                                   "  already have mail.\n"

void
reset(status refresh)
{
  int p;

  if (this_object() == find_object(BANKINTERFACE))
    return;

  if (refresh)
    return;

  p = possibilities();
  add_class(ACCOUNT,"parse_account");
  add_class(BANK,"parse_bank");
  add_class(PLAYER,"parse_player");
  if (p & B_PO_BANKINFO)
    add_rule("info","info");
  if (p & B_PO_ACCOUNTINFO)
  {
    add_rule("show balance","show balance");
    add_rule("balance","show balance");
    add_rule("balance all","show all balance");
    add_error_message("balance",
                      "Please just use 'balance' or 'balance all'.\n");
  }
  if (p & B_PO_OPEN_CLOSE_ACCOUNT)
  {
    add_rule("open "ACCOUNT,"open account");
    add_error_message("open","Do you want to open an account?\n");
    add_rule("close "ACCOUNT,"close account");
    add_error_message("close","Do you want to close an account?\n");
  }
  if (p & B_PO_DEPOSIT)
  {
    add_rule("deposit "G_MONEY, "deposit");
    add_rule("store "G_MONEY, "deposit");
    add_error_message("deposit",
                      "Please use 'deposit <amount of money>' or"
                      " 'store <amount of money>'\n"
                      MONEY_EXPLANATION);
    add_error_message("store",
                      "Please use 'deposit <amount of money>' or"
                      " 'store <amount of money>'\n"
                      MONEY_EXPLANATION);
  }
  if (p & B_PO_WITHDRAW)
  {
    add_rule("withdraw "G_ANY_MONEY,"withdraw");
    add_rule("retrieve "G_ANY_MONEY,"withdraw");
    add_error_message("withdraw",
                      "Please use 'withdraw <amount of money>' or"
                      " 'retrieve <amount of money> '\n"
                      MONEY_EXPLANATION);
    add_error_message("retrieve",
                      "Please use 'withdraw <amount of money>' or"
                      " 'retrieve <amount of money> '\n"
                      MONEY_EXPLANATION);
  }
  if (p & B_PO_TRANSER)
  {
    add_rule("transfer "G_ANY_MONEY" to bank "BANK,
             "transfer_to_bank");
    add_rule("transfer "G_ANY_MONEY" to player "PLAYER,
             "transfer_to_player");
    add_error_message("transfer",
                      "Please use 'transfer <amount of money> to bank"
                      " <bank>'\n"
                      "        or 'transfer <amount of money> to player"
                      " <player>'\n"
                      MONEY_NO_ALL_EXPLANATION);
  }
  if (p & B_PO_CHANGE)
  {
    add_rule("change "G_MONEY" into "G_ANY_MONEY, "change");
    add_rule("change "G_MONEY, "change_simple");
    add_error_message(
     "change",
     "Please use 'change <amount of money> into <amount of money>'\n"
     "        or 'change <amount of money>' (to change into the least\n"
     "                                       possible amount of coins)\n"
     "  Examples:\n"
     "  change all coins into gold coins\n"
     "  change all coins\n"
     "  change all copper coins into silver coins\n"
     "  change mithril coin into silver coins and 1 copper coin\n"
     "etc. Try it out!\n"
    );
  }
}

status
parse_player(mixed result,mixed aux,int first,int last,string *words,
             string *text)
{
  mixed h;
  if (first != last)
    return 0;
  h = to_real_name(words[first]);
  if (h=(find_player(h) || FINGERD->load_player(h)))
  {
    result = h;
    aux = h->query_vis_name() || capitalize(h->query_real_name());
    return 1;
  }
}

status
parse_bank(mixed result,mixed aux,int first,int last,string *words,
           string *text)
{
  mixed g,h;
  g = BANKSSERVER->query_banks();
  h = filter(g, lambda(({ 'name, 'args }),
                       ({ #'>=,
                          ({ #'strstr,
                             ({ #'lower_case, ({ CL_L_INDEX, 'args, 2 }) }),
                             lower_case(implode(words[first..last], " "}) }),
                          0 })));
  result = m_indices(h);
  aux = (sizeof(result)>1?  /* more than one found (ambiguous)? */
         m_values(h,2) :    /* --> vis_names of possibilities   */
         (sizeof(result)?   /* exact one found (unambiguous)?   */
          h[result[0],2] :  /* --> vis_name of solution         */
          m_values(g,2)));  /* no found --> vis_names of all banks */
  return 1;
  /* remove the rest ....... */
  if (sizeof(h)>1)
    message("There are "+sizeof(h)+" banks mathing your description: "+
            make_list(m_values(h,2))+". Please be more precise; you don't want"
            " your money being sent to th wrong address, do you?\n"
            "Any unambiguous substring of a bank's descriptoin suffices.\n");
  else if (!sizeof(h))
    message("Sorry, no bank mathes you description.\n"
            "The following banks exist: "+make_list(m_values(h,2))+".\n"
            "Any unambiguous substring of a bank's description suffices.\n");
  else
  {
    result = m_indices(h)[0];
    aux = h[result,2];
    return 1;
  }
}

status
parse_account(mixed result,mixed aux,int first,int last,string *words,
              string *text)
{
  return describe(implode(words[first..last]," "),ARTICLE_NONE)=="account";
}

status
_all(string str)
{
  if (str == "all")
    return parse_sentence(query_varb() + " all coins");
}

void
init()
{
  add_actions();
  add_action("_all", "retrieve");
  add_action("_all", "withdraw");
  add_action("_all", "store");
  add_action("_all", "deposit");
  add_action("_all", "change");
}

status
info()
{
  mixed h;
  send_message(({ M_PL,M_PL_VERB,"ask",
                  " for information about "+vis_bank_name()+"." }));
  h = m_indices(BANKSERVER->query_banks());
  h = map(h,symbol_function("query_bank_vis_name",BANKSERVER));
  h = make_list(h,"none");
  write("The current interest of "+bank_name()+" is at "+
        BANKSERVER->query_bank_interest(bank_name())*100+"%  p/a.\n"
        "Money in coins stored at "+vis_bank_name()+": "+
        BANKSERVER->query_all_money(bank_name())+".\n"+
        "The following banks exist in Nirvana:\n"+
        break_string(capitalize(h))+".\n");
  return ;
}

string
my_describe_money(int amount)
{
  if (!amount)
    return "no coins";
  if (!(amount % 10))
    return describe("1 silver coin", 0, 0, amount/10);
  if (amount < 10)
    return describe("1 copper coin", 0, 0, amount);
  return (amount / 10) + " silver and " + (amount % 10) + " copper coins";
}

status
show_balance(object p)
{
  int amount;

  if (p!=this_player())
    raise_error("Unimplemented feature in bankinterface\n");
  if (environment(p) == this_object())
    send_message(({ M_PL,M_PL_BERB,"ask"," for ",M_PL_POSSESSIVE,
                  " balance at "+vis_bank_name()+"." }));
  if (BANKSERVER->query_locked(p,bank_name()))
    return notify_fail(LOCKED_NOTIFY_FAIL_MESSAGE,1), 0;
  if (!BANKSERVER->query_accounts(p,bank_name()))
    return write("You don't have an account here.\n"), 1;
  amount = BANKSERVER->balance(p,bank_name());

  write("You currently have "+
        (amount ? my_describe_money(amount) : "nothing")+
        " at "+vis_bank_name()+".\n");
  return 1;
}

status
show_all_balance(object p)
{
  int amount, i;
  string *accs;

  if (p!=this_player())
    raise_error("Unimplemented feature in bankinterface\n");
  send_message(({ M_PL,M_PL_VERB,"ask"," for ",M_PL_POSSESSIVE,
                " balance at all banks." }));
  if (BANKSERVER->query_locked(p,bank_name()))
    return notify_fail(LOCKED_NOTIFY_FAIL_MESSAGE,1), 0;
  if (!sizeof(accs = BANKSERVER->query_accounts(p)))
    return write("You don't have any accounts on Nirvana.\n"), 1;

  write("You currently have");
  for (i = 0; i<sizeof(accs); i++)
  {
    if (amount = BANKSERVER->balance(p, accs[i]))
      accs[i] = " " + my_describe_money(amount) + " at " +
        BANKSERVER->query_bank_vis_name(accs[i]);
    else
      accs[i] = 0;
  }
  accs -= ({ 0 });
  switch(sizeof(accs))
  {
  case 0:
    write(" nothing at all banks.\n");
    return 1;
  case 1:
    write(accs[0] + ".\n");
    return 1;
  default:
    write("\n" + make_list(accs, 0, " and\n", ",\n") + ".\n");
    write("That are " + my_describe_money(BANKSERVER->balance(p)) +
       " altogether.\n");
  }
  return 1;
}

status
open_account(object p)
{
  if (p!=this_player())
    raise_error("Unimplemented feature in bankinterface\n");
  if (p->query_guest())
    return notify_fail("You are just a guest player and cannot open an account"
                       " in this state.\n"
                       "Type 'finalize' to save your character and strip that"
                       " awful state.\n",1), 0;
  if (BANKSERVER->query_locked(p,bank_name()))
    return notify_fail(LOCKED_NOTIFY_FAIL_MESSAGE,1), 0;
  if (BANKSERVER->query_accounts(p,bank_name()))
    return notify_fail("You already have an account at "+vis_bank_name()+".\n",
                       1), 0;
  send_message(({ M_PL,M_PL_VERB,"open",
                  " a new account at "+vis_bank_name()+"." }));
  BANKSERVER->open_account(p,bank_name());
  return 1;
}

status
close_account(object p)
{
  if (p!=this_player())
    raise_error("Unimplemented feature in bankinterface\n");
  if (BANKSERVER->query_locked(p,bank_name()))
    return notify_fail(LOCKED_NOTIFY_FAIL_MESSAGE,1), 0;
  if (!BANKSERVER->query_accounts(p,bank_name()))
    return notify_fail("You have no account you could close at "+
                       vis_bank_name()+".\n",1), 0;
  if (BANKSERVER->balance(p,bank_name()))
    return
      notify_fail("You only can close your account when it is empty.\n",1), 0;
  send_message(({ M_PL,M_PL_VERB,"close",M_PL_POSSESSIVE,
                  " account at "+vis_bank_name()+"." }));
  BANKSERVER->close_account(p,bank_name());
  return 1;
}

varargs status
deposit(object p,int amount,object money_ob,mapping coins)
{
  int i;
  mixed res;

  if (p!=this_player())
    raise_error("Unimplemented feature in bankinterface\n");
  if (BANKSERVER->query_locked(p,bank_name()))
    return notify_fail(LOCKED_NOTIFY_FAIL_MESSAGE,1), 0;
  if (!BANKSERVER->query_accounts(p,bank_name()))
    return notify_fail("Please open an account before you deposit your"
                       " money at "+vis_bank_name()+".\n",1), 0;
  if (!money_ob->query_property(P_COINS))
    return notify_fail("You can only deposit coins here.\n",1), 0;
  if (member_array(p, all_environment(money_ob)) < 0)
    return notify_fail("You can only deposit money that you're"
                       " carrying.\n",1), 0;
  if (amount < 0)
    return notify_fail("Please use 'withdraw'.\n",1), 0;
  if (amount == 0)
    return notify_fail("No. That's too little.\n",1), 0;
  send_message((environment(p) == this_object() ? ({}) : ({ M_WRITE })) +
               ({ M_PL,M_PL_VERB,"deposit"," ",
                  M_PL_ADD, ({ describe(money_ob), "some money" }), " on ",
                  M_PL_POSSESSIVE, " account at " +vis_bank_name()+"." }));
  destruct(money_ob);
  BANKSERVER->add_money(p,bank_name(),amount);
  message("Your balance is now "+
    my_describe_money(BANKSERVER->balance(p, bank_name()))+ ".\n");
  return 1;
}

varargs status
withdraw(object p, int amount, mapping coins)
{
  int val;
  string *types;
  object ob;
  int tmp, rest, i;
  string *accs, *trans;

  if (p!=this_player())
    raise_error("Unimplemented feature in bankinterface\n");

  if (BANKSERVER->query_locked(p,bank_name()))
    return notify_fail(LOCKED_NOTIFY_FAIL_MESSAGE,1), 0;
  if (!BANKSERVER->query_accounts(p,bank_name()))
    return notify_fail("You do not have an account here.\n",1), 0;

  types = m_indices(coins);
  for (i=sizeof(types); i--;)
    if (coins[types[i]] != DUMMY_ALL)
      types[i] = 0;
  types -= ({ 0 });

  switch(sizeof(types))
  {
    /* no all at all */
  case 0:
    break;
    /* 'all silver coins', 'all gold coins' */
  case 1:
    amount = BANKSERVER->balance(p,bank_name());
    if (!amount)
      return notify_fail("There's no money in your account.\n", 1), 0;
    coins = ([ types[0] : amount / (val = COIN_VALUE[types[0]]) ]);
    amount = (amount / val) * val;
    if (!amount)
      return notify_fail("You don't have any " + types[0] +
        " coins in your account.\n", 1), 0;
    break;
    /* 'all coins' */
  case 5:  /* 5 == sizeof(VALID_COINAGES) */
    amount = BANKSERVER->balance(p,bank_name());
    if (!amount)
      return notify_fail("There's no money in your account.\n", 1), 0;
    coins = LIB_MONEY->int2money(amount);
    break;
    /* 'too many alls' */
  default:
    return notify_fail("Sorry, too many 'alls'. Be more concrete.\n", 1), 0;
  }
  if (amount < 0)
    return notify_fail("Please use 'deposit'.\n",1), 0;
  if (amount == 0)
    return notify_fail("No. That's too little.\n",1), 0;
  if (!p->test_encumbrance(LIB_MONEY->query_encumbrance(coins)))
    return notify_fail("You can't carry that much.\n",1), 0);
  if (amount->BANKSERVER->balance(p,bank_name()))
  {
    if (!(possibilities() & B_PO_REMOTE_WITHDRAW))
      return notify_fail(break_string("There is not that much money in your"
                                      "  account at " + vis_bank_name() +
                                      "  and remote withdraws are not " +
                                      "  possible here.\n"),1), 0;
    accs = BANKSERVER->query_accounts(p);
    if (!accs || !sizeof(accs))
      return notify_fail("But you have no accounts on Nirvana.\n", 1), 0;
    if (BANKSERVER->balance(p) < amount)
      return notify_fail("But you haven't got that much money on all your"
                         " accounts on Nirvana.\n", 1), 0;
    accs -= ({ bank_name() });
    accs = ({ bank_name() }) + accs;
    rest = amount;
    trans = ({});
    for (i=0;i<sizeof(accs);i++)
    {
      tmp = BANKSERVER->balance(p,accs[i]);
      if (tmp && tmp >= rest)
      {
        trans += ({ BANKSERVER->query_bank_vis_name(accs[i] });
        BANKSERVER->add_money(p, accs[i], -rest);
        break;
      }
      trans += ({ BANKSERVER->query_bank_vis_name(accs[i]) });
      rest -= tmp;
      BANKSERVER->add_money(p, accs[i], -tmp);
    }
  }
  else
    BANKSERVER->add_money(p,bank_name(),-amount);
  if (trans)
    send_message(({ M_WRITE,
                    ("You withdraw money from your accounts at " +
                    make_list(trans) + " and receive " +
                    LIB_MONEY->describe_money(coins) + ".") }));
  else
    send_message(({ M_WRITE,
                    ("You withdraw " + LIB_MONEY->describe_money(coins) +
                     " from your account at " + vis_bank_name() + ".") }));
  if (environment(p) == this_object())
    send_message(({ M_SAY, M_PL, " withdraws some money from ",
                    M_PL_POSSESSIVE, " account" + (trans ? "s" : " at " +
                                                   vis_bank_name()) + "." }));
  if (!trans)
    message("Your balance is now " +
            my_describe_money(BANKSERVER->balance(p, bank_name())) + ".\n");
  if (!p->add_coins(coins))
    raise_error("Error in withdraw()\n");
  return 1;
}

varargs status
transfer_to_player(object p,int amount,object receiver,mixed vis_name,
                   mapping coins)
{
  if (p!=this_player())
    raise_error("Unimplemented feature in bankinterface\n");
  if (amount < 0)
    return notify_fail("Thank you for looking for a bug, but it's not here.\n",
                       1), 0;
  if (amount == 0)
    return notify_fail("No. That's too little.\n",1), 0;
  if (BANKSERVER->query_locked(p,bank_name()))
    return notify_fail(LOCKED_NOTIFY_FAIL_MESSAGE,1), 0;
  if (!BANKSERVER->query_accounts(p,bank_name()))
    return notify_fail("Please open account here first.\n",1) 0;
  if (!BANKSERVER->query_accounts(receiver,bank_name()))
    return notify_fail("Sorry, but "+vis_name+" does not have an account at "+
                       vis_bank_name()+".\n",1) 0;
  if (BANKSERVER->balance(p,bank_name()) < amount)
    return notify_fail("You do not have that much money in your account at "+
                       vis_bank_name()+".\n",1), 0;
  if (BANKSERVER->query_locked(receiver,bank_name()))
    return notify_fail(({ ({ M_WRITE,
                             (describe(vis_name,0,0,0,1)+" accounts have been"
                              " locked.") }),
                          ({ M_WRITE,LOCKED_NOTIFY_FAIL_MESSAGE }) }),1), 0;
  BANKSERVER->add_money(p,bank_name(),-amount);
  BANKSERVER->add_money(receiver,bank_name(),amount);
  send_message(({ M_PL,M_PL_VERB,"transfer"," ",M_PL_ADD,
                  ({ LIB_MONEY->describe_money(coins || amount)+
                      " to "+describe(vis_name,0,0,0,1)+" account.",
                     " some money to another account." }) }));
  if (interactive(receiver))
    tell_object(receiver,"You feel a little richer.\n");
  return 1;
}

varargs status
transfer_to_bank(object p,int amount,string *banks,mixed vis_names,
                 mapping coins)
{
  if (p!=this_player())
    raise_error("Unimplemented feature in bankinterface\n");
  if (sizeof(banks)>1)
    return notify_fail(({ ({ M_WRITE,
                             ("There are "+sizeof(banks)+
                              " banks matching your description: "+
                              make_list(vis_names)+". Please be more precise;"
                              " you don't won't your money being sent to the"
                              " wrong address, do you?) }),
                           ({ M_WRITE,
                              ("Any unambiguous substring of a bank's"
                               " description suffices.") }) }),1), 0;
  if (!sizeof(banks))
    return notify_fail(({ ({ M_WRITE,
                             ("Sorry, no bank mathces your description.\n"
                              "The following banks exist: "+
                              make_list(vis_names)+".") }),
                          ({ M_WRITE,
                             ("Any unambiguous substring of a bank's"
                              " description suffices.") }) }),1), 0;
  if (amount < 0)
    return notify_fail(({ ({ M_WRITE,
                             ("Sorry, this bank is not capable of accessing"
                              " accounts at another bank, but maybe "+
                              vis_names+
                              " allows you to transfer money here.") }) }),
                           1), 0;
  if (amount == 0)
    return notify_fail("No. That's too little.\n",1), 0;
  if (BANKSERVER->query_locked(p,bank_name()) ||
      BANKSERVER->query_locked(p,banks[0]))
    return notify_fail(LOCKED_NOTIFY_FAIL_MESSAGE,1), 0;
  if (!BANKSERVER->query_accounts(p,bank_name()))
    return notify_fail("You do not have an account at "+vis_bank_name()+".\n"
                       "Please open an account here first.\n",1), 0;
  if (!BANKSERVER->query_accounts(p,banks[0]))
    return notify_fail("You do not have an account at "+vis_names+".\n"
                       "Please open an account there first.\n",1), 0;
  if (BANKSERVER->balance(p,bank_name()) < amount)
    return notify_fail("You do not have that much money in your account at "+
                       vis_bank_name()+".\n",1), 0;
  BANKSERVER->add_money(p,bank_name(),-amount);
  BANKSERVER->add_money(p,banks[0],amount);
  send_message(({ M_PL,M_PL_VERB,"transfer"," ",M_PL_ADD,
                  ({ LIB_MONEY->describe_money(coins || amount) +
                      " to your account at "+vis_names+".",
                      "some money to another bank." }) }));
  return 1;
}

varargs status
change(object p,object money_ob,int old_val,mapping old_coins,int new_val,
       mapping new_coins)
{
  int i, amount, val;
  string *types, oc, nc;
  mapping rest;

  if (p!=this_player())
    raise_error("Unimplemented feature in bankinterface\n"0;

  if (!new_coins || !new_val)
  {
    new_coins = LIB_MONEY->int2money(old_val);
    new_val = old_val;
  }
  if (member_array(p, all_environment(money_ob)) < 0)
    return notify_fail("You can only change money that you're carrying.\n",
                       1), 0;
  if (old_val != new_val)
  {
    types = m_indices(new_coins);
    for (i=sizeof(types);i--;)
      if (new_coins[types[i]] != DUMMY_ALL)
        types[i] = 0;
    types -= ({ 0 });
    switch(sizeof(types))
    {
      /* 'no all at all' */
      case 0:
        return notify_fail("But that would be a different value.\n",1), 0;
      /* 'silver coins', 'gold coins' */
      case 1:
        new_coins -= ([ types[0] ]);
        new_val = LIB_MONEY->query_value(new_coins);
        if (new_val > old_val)
          return notify_fail("But that would be a different value.\n",1), 0;
        amount = (old_val - new_val) / (val = COIN_VALUE[types[0]]);
        if (!amount)
          return notify_fail("That's not enough for " + types[0] +
                             " coins.\n",1), 0;
        new_coins[types[0]] += amount;
        if ((old_val - new_val) % val)
        {
          rest = LIB_MONEY->int2money((old_val - new_val) % val);
          types = m_indices(rest);
          for (i=sizeof(types); i--;)
            new_coins[types[i]] += rest[types[i]];
        }
        break;
      /* 'too many alls' */
      default:
        return notify_fail("Be more precise what coins you want.\n",1), 0;
    }
  }
  if (LIB_MONEY->query_value(new_coins) != old_val)
    raise_error("Internal error: new value differes from old value\n");
  nc = LIB_MONEY->describe_money(new_coins);
  oc = LIB_MONEY->describe_money(old_coins);
  if (nc == oc)
    return notify_fail("You already have those coins. "
                       "No changing required.\n",1), 0;
  move_object(money_ob, load_object("room/void"));
  if (!p->test_encumbrance(LIB_MONEY->query_encumbrance(new_coins)))
  {
    move_object(money_ob, p);
    message("You can't carry that much.\n");
    return 1;
  }
  destruct(money_ob);
  p->add_coins(new_coins);
  send_message(({ M_PL, M_PL_VERB, "change",
                  " " + oc + " into " + nc + "." }));
  return 1;
}

status
do_action(string action,mapping m)
{
  switch(action)
  {
  case "info":
    return info();
  case "show balance":
    return show_balance(this_player());
  case "show all balance":
    return show_all_balance(this_player());
  case "open account":
    return open_account(this_player());
  case "close account":
    return close_account(this_player());
  case "deposit":
    return deposit(this_player(),m[G_MONEY]->query_value(),
                   m[G_MONEY], m[G_MONEY,1]);
  case "withdraw":
    return withdraw(this_player(),m[G_ANY_MONEY],m[G_ANY_MONEY,1]);
  case "transfer_to_player":
    return transfer_to_player(this_player(),m[G_ANY_MONEY],
                              m[PLAYER],m[PLAYER,1],m[G_ANY_MONEY,1]);
  case "transfer_to_bank":
    return transfer_to_bank(this_player(),m[G_ANY_MONEY],
                            m[BANK],m[BANK,1],m[G_ANY_MONEY,1]);
  case "change_simple":
    return change(this_player(), m[G_MONEY],
                  m[G_MONEY]->query_value(),m[G_MONEY,1]);
  case "change":
    return change(this_player(), m[G_MONEY],
                  m[G_MONEY]->query_value(), m[G_MONEY,1],
                  m[G_ANY_MONEY], m[G_ANY_MONEY,1]);
  }
}

status
handle_wizlist_add_money_on_our_own()
{
  return 1;
}
