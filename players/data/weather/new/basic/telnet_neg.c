// taken from Wunderland mudlib, adapted for Tubmud by Coogan, 24-Oct-2002
//
// based on Morgengrauen Mudlib
//
// the original was provided by Marcus@Tappmud
// adapted for Morgengrauen-Mudlib von Ringor@MG
//

#pragma strict_types

#include <telnet.h>
#include <prop/player.h>

private nosave mapping tn;
private nosave string *terminals;
private nosave string last_received_termtype;

static void set_telnet_neg(mapping stn) {  // Coogan, 05-Oct-2005
  tn = deep_copy(stn);
}

mapping query_telnet_neg() {
  tn = tn || ([ ]);
  return tn;
}

static void set_terminals(string *t) {  // Coogan, 05-Oct-2005
  terminals = copy(t);
}

string* query_terminals() { 
  return terminals;
}

// log sent negotiations
static varargs int send_telnet_neg(int *arr) {
  int res;

  // moved the flag 3 to binary_message() from obj/login, Coogan, 26-Sep-2010
  if (sizeof(arr) < 3)
    return efun::binary_message(arr, 3);
  
  if (!tn)  // Coogan, 29-Sep-2005
    tn = ([ ]);

  if (!tn[TEL_SENT])
    tn[TEL_SENT] = m_allocate(3,3);
    
  if (arr[0] == TEL_DEF_IAC) {
    switch (arr[1]) {
    case TEL_DEF_DO:
    case TEL_DEF_DONT:
      tn[TEL_SENT][arr[2],1] = arr[1];
      break;
    case TEL_DEF_WILL:
    case TEL_DEF_WONT:
      tn[TEL_SENT][arr[2],0] = arr[1];
      break;
    case TEL_DEF_SB:
      tn[TEL_SENT][arr[2],2] = arr[1..];
      break;
    default:
      break;  
    }
  }
  return efun::binary_message(arr, 3);
}

// the driver calls here with/for all negotiations (hook).
// answer and log them.
void telnet_negotiation(int command, int option, int *optargs) {
  mapping recd, sent;
  int i, l, c, rsw;
  mixed *xx;
  string tmpterminal;
  string text, text2;
  int tmpxx;

  l = 0;
  c = 0;

  // DEBUG_POINT("coogan", ({ ctime(), command, option, optargs }));
  // hmm. WILL/WONT DO/DONT SB_IS 
  tn = tn || ([ ]);
  
  if (!tn[TEL_RECEIVED])
    tn[TEL_RECEIVED] = m_allocate(3,3);
    
  if (!tn[TEL_SENT])
    tn[TEL_SENT] = m_allocate(3,3);

  recd = tn[TEL_RECEIVED];
  sent = tn[TEL_SENT];

  if (command == TEL_DEF_WILL || command == TEL_DEF_WONT) {
    recd[option,0] = command;
        
    if (!sent[option,1] && command == TEL_DEF_WILL) {
      // we support everything - yeah ;)
      efun::binary_message(({ TEL_DEF_IAC, TEL_DEF_DO, option }), 3);
      sent[option,1] = TEL_DEF_DO;
    }
        
    if (command == TEL_DEF_WILL) {
      switch (option) {
      case TEL_OPT_NAWS: 
        break; // no more things needed.
                
      case TEL_OPT_LINEMODE:
        send_telnet_neg(({ TEL_DEF_IAC, TEL_DEF_SB, option,
                           TEL_LM_MODE, TEL_MODE_EDIT,
                           TEL_DEF_IAC, TEL_DEF_SE }));
        // flush on 0d and 0a...
        send_telnet_neg(({ TEL_DEF_IAC, TEL_DEF_SB, option,
                           TEL_DEF_DO, TEL_LM_FORWARDMASK,
                           0, 0x40|0x08, TEL_DEF_IAC, TEL_DEF_SE }));
        sent[TEL_OPT_LINEMODE,2] = TEL_MODE_EDIT;
        break;

      case TEL_OPT_TTYPE:
        send_telnet_neg(({ TEL_DEF_IAC, TEL_DEF_SB, TEL_OPT_TTYPE,
                           TEL_QUAL_SEND, TEL_DEF_IAC, TEL_DEF_SE }));
        sent[TEL_OPT_TTYPE,2] = TEL_QUAL_SEND;
        break;

      case TEL_OPT_TSPEED:
        send_telnet_neg(({ TEL_DEF_IAC, TEL_DEF_SB, TEL_OPT_TSPEED,
                           TEL_QUAL_SEND, TEL_DEF_IAC, TEL_DEF_SE }));
        sent[TEL_OPT_TTYPE,2] = TEL_QUAL_SEND;
        break;
                
      case TEL_OPT_NEWENV:
      case TEL_OPT_ENVIRON:
        efun::binary_message(({ TEL_DEF_IAC, TEL_DEF_SB, option,
                                TEL_QUAL_SEND, TEL_DEF_IAC, TEL_DEF_SE }), 3);
        sent[option,2] = TEL_QUAL_SEND;
        break;
                
      case TEL_OPT_XDISPLOC:
        send_telnet_neg(({ TEL_DEF_IAC, TEL_DEF_SB, TEL_OPT_XDISPLOC,
                           TEL_QUAL_SEND, TEL_DEF_IAC, TEL_DEF_SE }));
        break;
                
      default:
        break;
      }
    }
    return;
  } // endif WILL/WONT

  if (command == TEL_DEF_DONT || command == TEL_DEF_DO) {
    // we don't do anything as telnet client, at least not in the lib
    recd[option,1] = command;
        
    if (!sent[option,0] && command == TEL_DEF_DO) {
      if (option == TEL_OPT_EOR) {
        sent[option,0] = TEL_DEF_WILL;
        efun::binary_message(({ TEL_DEF_IAC, TEL_DEF_WILL, option }), 3);
      } else {
        sent[option,0] = TEL_DEF_WONT;
        efun::binary_message(({ TEL_DEF_IAC, TEL_DEF_WONT, option }), 3);
      }
    }

    if (option == TEL_OPT_EOR && command == TEL_DEF_DO) {
      efun::binary_message(({ TEL_DEF_IAC, TEL_DEF_EOR }), 3);
    }
    return;
  } // endif DO/DONT
    
  if (command == TEL_DEF_SB) {
    switch (option) {
    case TEL_OPT_NAWS:
      recd[option,2] = optargs;
      if (sizeof(optargs) != 4) { 
        message(sprintf("Warning: Your client made an error while negotiating "
                        "the TEL_OPT_NAWS - it has sent IAC SB %O IAC SE!\n",
                        optargs));
        break;
      }
      if (interactive(this_object())) {
        if (!optargs[1])
          c = optargs[0];
        else
          c = optargs[1] + optargs[0] * 256;

        if (!optargs[3])
          l = optargs[2];
        else
          l = 256 * optargs[2] + optargs[3];

        if (!call_resolved(&rsw, this_object(), "query_property",
                                                          P_RESIZE_WINDOW))
          break;

        if (rsw == -1)
          break;
        if (rsw == 0) {
          message("You resized your window to a width of " + c +
                  " columns and a heigth of " + l + " lines. By repeated "
                  "toggling of 'resize' you can let adjust your display size "
                  "automatically or switch it off or get this message.\n");
          break;
        }

        if (c < 20) {
          message("Your window is smaller than 20 columns? You must be joking. "
                  "The standard size of 79 will be used.\n");
          c = 79;
        }

        if (l < 3) {
          message("You want to use less than three lines? The standard value "
                  "of 20 will be used instead.\n");
          l = 20;
        }

        if (this_object()->query_property(P_DISPLAY_WIDTH)  != c ||
            this_object()->query_property(P_DISPLAY_HEIGHT) != l) {
          this_object()->set_property(P_DISPLAY_WIDTH,  c-1);
          this_object()->set_property(P_DISPLAY_HEIGHT, l-1);
          if (this_object()->query_property(P_RESIZE_WINDOW) != -2)
            message("You changed your window size to " + c + " columns and " +
                    l + " lines, display size set to " + (c-1) + " columns "
                    "and " + (l-1) + " lines.\n");
        }
      }
      break;
            
    case TEL_OPT_TTYPE:
      // NOTE: We do not do multiple SB SENDs due to some weird
      // bugs in IBM3270 emulating telnets which crash if we
      // do that.
      if (sizeof(optargs) < 1)
        break;

      if (optargs[0] != TEL_QUAL_IS)
        break;

      tmpterminal = lower_case(to_string(optargs[1..]));
      if (!terminals)
        terminals = ({ tmpterminal });
      else
        terminals += ({ tmpterminal });
      this_object()->set_property(P_TTY_TYPE, terminals[0]);
      recd[option,2] = terminals;
      break;

    case TEL_OPT_TSPEED:
      if (sizeof(optargs) < 2)
        break;

      if (optargs[0] != TEL_QUAL_IS)
        break;

      recd[option,2] = to_string(optargs[1..]);
      break;

    case TEL_OPT_ENVIRON:
    case TEL_OPT_NEWENV:
      if (sizeof(optargs) < 3)
        break;

      if (optargs[0] != TEL_QUAL_IS)
        break;

      optargs = optargs[2..];  // first kill the TEL_QUAL_IS
      recd[option,2] = ([ ]);
      text = "";
      text2 = 0;

      for (i = 0; i < sizeof(optargs) ; i++) {
        tmpxx = optargs[i];

        if (tmpxx < 5) {
          if (text && text2) {
            recd[option,2][text] = text2;
            text2 = 0;
            text = "";
          }
          else
            text2 = "";
        } else {
          if (text2)
            text2 += sprintf("%c", tmpxx);
          else
            text += sprintf("%c", tmpxx);
        }
      }

      if (text && text2)
        recd[option,2][text] = text2;

#ifdef DEBUG
      text = implode(explode(sprintf("%O\n", recd[option,2]), "\n"), "") +"\n";
      // the data are not further used yet ...
#endif
      break;

    case TEL_OPT_XDISPLOC:
      if (optargs[0] != TEL_QUAL_IS)
        recd[TEL_OPT_XDISPLOC,2] = optargs;
      else
        recd[TEL_OPT_XDISPLOC,2] = lower_case(to_string(optargs[1..]));
      break;

    case TEL_OPT_LINEMODE:
      break;

    default:
      break;
    }
    return;
  } // endif SB
}

// return, if the telnet EOR should be sent or not
status query_send_telnet_eor() {
  return tn && mappingp(tn) &&
         mappingp(tn[TEL_RECEIVED]) &&
         tn[TEL_RECEIVED][TEL_OPT_EOR, 1] == TEL_DEF_DO;
}

