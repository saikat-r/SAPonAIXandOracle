/* @(#) $Id: //bas/640_REL/src/krn/rfc/rfcpump.h#1 $ SAP*/
#ifndef _RFC_PUMP_H_
#define _RFC_PUMP_H_
#include "saprfc.h"
/*********************************************************

@doc

@module RFC and the Windows Message Pump |

This section describes the precautions which must be taken when
writing RFC programs which runs under Windows<tm>.

The information given here applies to Windows programs 
under Win16 (Windows 3.0, Windows for Workgroup) as well
as under Win32 (Windows 95, Windows NT) which have a Windows.
It does not apply to single threaded console applications
written under Win32.  Authors from multithreaded Win32 
might want to read the classification of the RFC-API-calls.

@head3 1. Problem description |

If a long lasting calls is issued in the main thread of a Windows 
programs, the thread remains blocked in the RFC-API-call and cannot
serves it's Windows message queue.

On Win16, this blocks the entire machine until the RFC-API-call returns
On Win32, the Windows application cannot repaint. If a Windows is moved
above the non pumping applications, the non pumping applications gets 
white patches.  On Win32, a deadlock may also occurs if an other 
application sends a message via SendMessage() to the unserviced Windows

This problems are ignored most of the time since most of the RFC-API-call
return quickly.  A SAP system is expected to respond within 
2 seconds so that the problems are transients and ignored.<nl><nl>
There are however noticeable exception to this:

@flag 1)| Some Function Modules runs significantly longer than 2 seconds.

@flag 2)| Function Modules which uses the SAPGUI (RFC with dialog) returns only
  when the dialog or the transaction is left.  Depending on the 
  user, this can take any amount of time.

@flag 3)| RFC server API calls (RfcDispatch(), RfcGetName(),..) returns only
  when a request is made by a client program.


@head3 2. Solutions |

The RFC-SDK cannot offer a generic solution to all users.  It can only
documents the issue and offer 2 simple implementations of a Windows Pump.
You can build on this sample implementations and modify them to you
needs.

@head3 2.1 Use threads. |

This is the prefered solution for RFC-Server programs.

This is the CPU savy solution.

You can design your Windows Program from the ground up take advantage
of Windows threads capabilities.  Have a thread servicing the UI.
And have other threads performing the work and thus performing the 
RFC calls.  This solution requires threading issues to be considered
from the begining of the project.

@head3 2.2 Use an AbortProc.|

This is the easiest solution to implement.

Because the programs polls on 2 resources (the TCP-IP socket and the
Windows Message Queue) this solutions consumes CPU in the idle mode.

This technique is an time honored solutions known since the Win16 ages
It is described extensively in Petzold's Programming Windows 3.1 in 
Chapter 15: Using the printer. In the Win32 community, the technique
is rarely used. Since each application has it's own Message Queue,
repain problems are less frequent.  But also on Win32 some tasks 
such as printing or RFC calls take to long and the message queue must
be serviced.  One find a sample of the technique in MFC sources in the
CPrintingDialog class.  This solution as the advantage to easily
added to existing projects.

<f RfcPump> is a minimal pump implementation.

<f CRfcPump> is a more sophisticate pump with a progress/cancel dialog.

@head3 2.3 Classification of the RFC-API-Calls.|
<nl>
@group Most RFC-API calls are blocking calls:

@comm
Listed here are the RFC-API calls which read from the network.
They all have the potential to be long lasting calls.  However most
of this call generally returns fast.  While other (RfcCallReceive,
RfcReceive, RfcGetName, RfcDispatch) have really unpredictable 
response time. This is particularly true if you are using RFC with
dialog.  You should consider the techniques described here mainly when
using these 4 API calls. 

@flag <f RfcOpenEx>           | opens an RFC connection including SAP logon
@flag <f RfcCall>             | Calls an ABAP/4 function module.
                                (blocking only on large data volume)
@flag <f RfcReceive>          | Receives the return values from an
                                ABAP/4 function module.
@flag <f RfcCallReceive>      | Calling a function module and receiving the
                                return values in one step.
@flag <f RfcCreateTransID>    | Gets a unique Transaction-ID for calling an ABAP/4
                                function module using the transactional RFC Interface.
@flag <f RfcIndirectCall>     | Calls an ABAP/4 function module using transactional RFC
                                Interface in R/3 (implicit confirmation).
@flag <f RfcIndirectCallEx>   | Calls an ABAP/4 function module using transactional RFC
                                Interface in R/3 ( (explicit confirmation).
@flag <f RfcConfirmTransID>   | Confirms a transaction called by RfcIndirectCallEx.
@flag <f RfcAccept>           | accepting a RFC request or registering at a
                                SAP gateway.
@flag <f RfcDispatch>         | waiting for the next function call.
@flag <f RfcGetData>          | receiving the parameters of a function
                                (blocking only on large data volume)
@flag <f RfcRaise>            | raising an exception.
@flag <f RfcGetName>          | reading the symbolic function name.
@flag <f RfcGetNameEx>        | reading the symbolic function name.
@flag <f RfcCheckRegisterServer>   | check for registered RFC server at a SAP gateway
@flag <f RfcCancelRegisterServer>  | cancel all registered RFC servers at a SAP gateway
@flag <f RfcWaitForRequest>   | wait for incoming RFC requests.
                                Only available after <f RfcAccept> in
                                register mode.
                                (blocking the specified amount of time)


@group Some RFC-API calls are non blocking calls:

@flag <f RfcInstallTransactionControl> | registering functions as callable
                                         function modules for transactional RFC.
@flag <f RfcSncMode>                   | getting the <t RFC_SNC_MODE> (ON or OFF)
@flag <f RfcSncPartnerName>            | getting the SNC name of the RFC client
@flag <f RfcSncPartnerAclKey>          | getting the SNC ACL key of the RFC client

@flag <f RfcListen>            | listen for incoming RFC events.
@flag <f RfcGetAttributes>     | get some information about this RFC connection
@flag <f RfcInstallStructure>  | define a structure for working with inhomogeneous
                                 structure or internal table in an RFC client or
                                 server program.
@flag <f RfcSncNameToAclKey>   | convert an SNC name in an SNC ACL key
@flag <f RfcSncAclKeyToName>   | convert an SNC ACL key in an SNC name

**********************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif
/*---------------------------------------------------------------------
 * @func int | RfcPump | Sample simple Windows pump for RFC calls
 *
 * This is a sample implementation.<nl>  
 * Change it to suite your requirements 
 *
 * Compile and link .../rfcsdk/text/rfcpump.c to your program.
 *
 * @group
 * This is a sample implementation.<nl>  
 * Change it to suite your requirements 
 *
 * Compile and link .../rfcsdk/text/rfcpump.c to your program.
 *
 * @comm
 * Call RfcPump() between <f RfcCall> and <f RfcReceive> 
 * or before <f RfcDispatch> or <f RfcGetName>.
 *
 * If you do only one RFC Function module call
 * in a client program you can pass you main Window handle as 
 * <p hWndMain>.  RfcPump() will disable the Windows durring it's run
 * preventing re-entrancy problems in your application.  If you 
 * are performing several clients call to SAP systems, then you will
 * want to call EnableWindows(hWndMain, FALSE); before the calls
 * and EnableWindows(hWmdMain, TRUE); when all the RFC calls
 * have been carried out.
 *
 * If you are an RFC server program or if you have a modeless dialog box
 * on the screen, the RfcPump will monitor the address passed by <p piAbort>.
 * if it changes to != 0, the pump will stop and return a negative value.
 *
 * The function presented here attempts to cover most simples cases
 * while remaining simple.  Likely enhancements are:<nl>
 * - Timeout parameter<nl>
 * - A Sleep() to reduce CPU drain<nl>
 * - Additional parameters for Accelerator (TranslateAccelerator())
 *   which could be required in some RFC-server implementation.
 *   But those RFC-server are expected to have a multithreaded 
 *   architecture. And thus will not use this simple function.
 *   RFC-Clients should not need accelerators since the Windows should
 *   disabled during the call to RfcPump.
 *
 * Because the programs polls on 2 resources (the TCP-IP socket and the
 * Windows Message Queue) this solutions consumes CPU in the idle mode.
 *
 *
 * @ex Using RfcPump(): |
 *
 * 
 * //assume hRfc is an open handle
 *
 *      RFC_PARAMETER       importing[1],
 *                          exporting[2];
 *      RFC_TABLE           tables[1];
 *      memset(importing,0,sizeof(importing));
 *      memset(tables,   0,sizeof(tables));
 *    
 *      memset(exporting,0,sizeof(exporting));
 *      exporting[0].name = "TCODE";
 *      exporting[0].nlen =  5;
 *      exporting[0].type = RFCTYPE_CHAR;
 *      exporting[0].addr = "SE38";
 *      exporting[0].leng = 4;
 *    
 *      RFC_RC rfc_rc = RfcCall(hRfc,
 *                      "ABAP4_CALL_TRANSACTION",
 *                      exporting,
 *                      tables
 *                      );
 *      if (RFC_OK != rfc_rc)
 *      {
 *          MyRfcError();
 *          RfcClose(hRfc);
 *          return rfc_rc;
 *      }
 *    
 *      int rc = RfcPump(g_hWndMain, hRfc, NULL);
 *      if (rc < 0)
 *      {
 *         //user pressed CANCEL
 *          RfcClose(hRfc);
 *          hRfc = RFC_HANDLE_NULL;
 *          return RFC_SYS_EXCEPTION;
 *
 *      }
 *      else
 *          rfc_rc = (RFC_RC)rc;
 *    
 *     
 *      if (RFC_OK == rfc_rc && RFC_HANDLE_NULL != hRfc)
 *      {
 *          char *exception = NULL,
 *          rfc_rc = RfcReceive(hRfc,importing, tables, &exception);
 *          if (RFC_OK != rfc_rc)
 *          {
 *              MyRfcError();
 *              RfcClose(hRfc);
 *              return rfc_rc;
 *          }
 *      }
 *
 * @rdesc Continue or abort
 * @flag if <gt>= 0 | RFC_RC as returned from <f RfcListen>
 * @flag if <lt> 0  | Abort has been requested
 *--------------------------------------------------------------------
 */
int RfcPump( HWND       hWndMain, /* @parm Main Windows, may be NULL */
             RFC_HANDLE handle,   /* @parm the RFC connection performing
                                   *       the long lasting call
                                   */
             int       *piAbort   /* @parm Abort if *piAbort != 0.<nl>
                                   * Pass a NULL pointer if not needed
                                   */
           );
#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
//
// @enum RFCP_PUMPSTATE | cached dialog state,
//
// used to reduce IsVisible and SendMessage trafic
//
// @xref <f CRfcPump>
typedef enum tagRFCP_PUMPSTATE
{
    RFCP_INIT,       //@emem initial, no dialog
    RFCP_CREATED,    //@emem Dialog created, hidden
    RFCP_VISIBLE,    //@emem Dialog Visible
    RFCP_CANCEL,     //@emem Dialog with cancel button
    RFCP_ERROR       //@emem Error, dialog cannot be created
} RFCP_PUMPSTATE;

//
// @enum RFCP_DIALOG_MODE | dialog creation mode
//
// @xref <f CRfcPump>
typedef enum tagRFCP_DIALOG_MODE
{
    RFCPDM_DELAYED,  //@emem create dialog only when needed
    RFCPDM_IMEDIATE  //@emem create dialog immediately
} RFCP_DIALOG_MODE;


//dialog proc
extern BOOL CALLBACK RfcPumpDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

//---------------------------------------------------------------------
// @class CRfcPump | a simple Windows Message Pump for RFC Program
//
// @group
// This is a sample implementation.<nl>  
// Change it to suite your requirements 
//
// Compile and link .../rfcsdk/text/rfcpumpd.cpp to your program.
// @comm
//
// This class provides the same basic <f RfcListen> / PeekMessage
// loop as <f RfcPump> and additionally provides a CancelDialog
// with a progress indicator.
//
// The class provide for severall scenario:
//
// The progress dialog is never shown<nl>
// The progress dialog is shown after a timeout<nl>
// The progress dialog is shown immediately with/without cancel button<nl>
// The cancel button is enable after a timeout
//
//
// Likely changes to this code would be:<nl>
// To strip it down to the scenario which you want to implement.<nl>
// Adding a Sleep() to reduce CPU drain.
// 
// @ex Using CRfcPump: |
//
//     RFC_PARAMETER       importing[1],
//                         exporting[2];
//     RFC_TABLE           tables[1];
//     memset(importing,0,sizeof(importing));
//     memset(tables,   0,sizeof(tables));
// 
//     memset(exporting,0,sizeof(exporting));
//     exporting[0].name = "TCODE";
//     exporting[0].nlen =  5;
//     exporting[0].type = RFCTYPE_CHAR;
//     exporting[0].addr = "SE38";
//     exporting[0].leng = 4;
// 
//     RFC_RC rfc_rc = RfcCall(hRfc,
//                         "ABAP4_CALL_TRANSACTION",
//                         exporting,
//                         tables
//                         );
//     if (RFC_OK != rfc_rc)
//     {
//         MyRfcError();
//         RfcClose(hRfc);
//         return rfc_rc;
//     }
// 
//     CRfcPump rfc_pump(RFCPDM_DELAYED,
//                     g_hInst,
//                     IDD_DIALOG1,
//                     g_hWndMain,
//                     IDC_PROGRESS1,
//                     100,
//                     3);
// 
//     
//     int rc = rfc_pump.RfcPump(hRfc, 3000, 6000);
//     if (rc < 0)
//     {
//         //user pressed CANCEL
//         RfcClose(hRfc);
//         hRfc = RFC_HANDLE_NULL;
//         return RFC_SYS_EXCEPTION;
//     }
//     else
//         rfc_rc = (RFC_RC)rc;
// 
//     if (RFC_OK == rfc_rc && RFC_HANDLE_NULL != hRfc)
//     {
//         char *exception = NULL,
//         rfc_rc = RfcReceive(hRfc,importing, tables, &exception);
//         if (RFC_OK != rfc_rc)
//         {
//             MyRfcError();
//             RfcClose(hRfc);
//             return rfc_rc;
//         }
//     }
// 
//
class CRfcPump  
{
public: /* @access Public Members */
        /* @cmember | CRfcPump | (RFCP_DIALOG_MODE dm,<nl>  HINSTANCE hInst,<nl>  UINT DlgID,<nl>  HWND hWndParent,<nl>  UINT idProgress = NULL,<nl>  UINT uiRange = 100,<nl>  UINT uiStep  = 1) |
         * Construct with progress/cancel dialog.<nl>
         * Refer to <mf CRfcPump.CRfcPump> for details
         */
        CRfcPump(RFCP_DIALOG_MODE dm, HINSTANCE hInst,
                 UINT DlgID,
                 HWND hWndParent,
                 UINT idProgress = NULL,
                 UINT uiRange = 100,
                 UINT uiStep  = 1
                ) ;

        /* @cmember Construct without progress/cancel dialog. 
         *
         * If a cancel dialog is needed later on (on a timeout for example)
         * then <mf CrfcPump.CreateCancelDialog> should be called.
         */
      	CRfcPump()
            : m_bUserAbort(FALSE),
              m_hWndParent(0),
              m_hWndDlg(0),
              m_hWndDlgG(0),
              m_hWndProgress(0),
              m_State(RFCP_INIT),
              m_hInst(0),
              m_DlgID(0),
              m_idProgress(0),
              m_uiRange(100),
              m_uiStep(1)
        {
        }

        /* @cmember Distroy dialog.  Enables the parent window.
         */
        virtual ~CRfcPump()
        {
            if (!m_bUserAbort)
            {
                if (0 != m_hWndParent)
                    EnableWindow(m_hWndParent, TRUE);
                if (0 != m_hWndDlg)
                    DestroyWindow(m_hWndDlg);
            }
        }

        /*@cmember HWND | CreateCancelDialog | (HINSTANCE hInst,<nl> UINT DlgID,<nl> HWND hWndParent,<nl> UINT idProgress = NULL,<nl> UINT uiRange = 100,<nl> UINT uiStep  = 1) |
         * Delayed dialog creation.
         */
        HWND CreateCancelDialog(HINSTANCE hInst,
                                UINT DlgID,
                                HWND hWndParent,
                                UINT idProgress = NULL,
                                UINT uiRange = 100,
                                UINT uiStep  = 1
                                );
        
        /*@cmember The inner Windows message pump
         *
         *Refer to <mf CrfcPump.Pump> for details
         */
        BOOL Pump() ;

        /*@cmember The high level RFC-Windows pump.
         *
         *Refer to <mf CrfcPump.RfcPump> for details
         */
        int RfcPump(RFC_HANDLE hRfc);

        /*@cmember int |RfcPump |(RFC_HANDLE hRfc,<nl> DWORD dwHidden,<nl> DWORD dwCancel)|
         * The high level RFC-Windows pump, with timeout.
         */
        int RfcPump(RFC_HANDLE hRfc,
                    DWORD dwHidden,
                    DWORD dwCancel);

        /*@cmember Show the dialog which is initialy hidden.*/
        void Show(BOOL b = TRUE);

        /*@cmember Enable the cancel button which is initially hidden.*/
        void EnableCancel(void) ;

        /*@cmember Abort the pump.*/
        BOOL SetAbort(BOOL b = TRUE)
        {
            return m_bUserAbort = b; 
        }

        /*@cmember Retrieve abort state.*/
        BOOL GetAbort(void) const
        {
            return m_bUserAbort;
        }

        /*@cmember Retrieve dialog state.*/
        RFCP_PUMPSTATE GetState(void) const
        {
            return m_State;
        }

        /*@cmember Retrieve dialog handle.*/
        HWND GetDialogHandle(void) const
        {
            return m_hWndDlgG;
        }

protected: /* @access Protected Members */
    friend BOOL CALLBACK RfcPumpDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
     /*@cmember Close the pump.*/
    void SetClosed(void) {m_hWndDlgG = NULL; m_State = RFCP_INIT;}

private:
    BOOL m_bUserAbort;
    HWND m_hWndParent;  // parent/owner window
    HWND m_hWndDlg;     // dialog's
    HWND m_hWndDlgG;    // dialog's Petzold's Global
    HWND m_hWndProgress;    // Progress bar
    RFCP_PUMPSTATE m_State; // reduce IsVisible calls in the pump

    //cache for delayed creation
    HINSTANCE m_hInst;  //instance, 
    UINT m_DlgID;       //dialog resource id
    UINT m_idProgress;  //progress indicator id
    UINT m_uiRange;     //progress indicator range
    UINT m_uiStep;      //progress indicator stepping

    //do not copy a dialog => private and not defined
    CRfcPump(const CRfcPump&);
    CRfcPump & operator=(const CRfcPump&);
}; //CRfcPump

#endif /*c++*/

#endif /*!_RFC_PUMP_H_*/
